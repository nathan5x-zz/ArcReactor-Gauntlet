#include "neopixel/neopixel.h"

#define PILLAR_L_PIXEL_PIN D1
#define PILLAR_R_PIXEL_PIN D2
#define BRIDGE_PIXEL_PIN D3

#define PILLAR_PIXEL_COUNT 8
#define BRIDGE_PIXEL_COUNT 16

#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel leftPillarLedStrip = Adafruit_NeoPixel(PILLAR_PIXEL_COUNT, PILLAR_L_PIXEL_PIN, PIXEL_TYPE);
Adafruit_NeoPixel rightPillarLedStrip = Adafruit_NeoPixel(PILLAR_PIXEL_COUNT, PILLAR_R_PIXEL_PIN, PIXEL_TYPE);
Adafruit_NeoPixel bridgeLedStrip = Adafruit_NeoPixel(BRIDGE_PIXEL_COUNT, BRIDGE_PIXEL_PIN, PIXEL_TYPE);

int leftPillarNumPixels = 0;
int rightPillarNumPixels = 0;
int bridgeNumPixels = 0;

int k=0;
int l=0;

bool canActivateLEDs = false;
bool resetRequired = false;

int bridgeBrightness = 60;

uint32_t redColor = leftPillarLedStrip.Color(255, 0, 0);
uint32_t greenColor = leftPillarLedStrip.Color(0, 255, 0);
uint32_t blueColor = leftPillarLedStrip.Color(0, 0, 255);
uint32_t mediumColor = leftPillarLedStrip.Color(255, 219, 0);

void setup() {

  Serial.begin(9600);
  Serial.println("Setup done");

  /** Initialize all the LED strips with basic configs **/

  leftPillarLedStrip.begin();
  leftPillarLedStrip.setBrightness(5);
  leftPillarLedStrip.show();

  rightPillarLedStrip.begin();
  rightPillarLedStrip.setBrightness(5);
  rightPillarLedStrip.show();

  bridgeLedStrip.begin();
  bridgeLedStrip.setBrightness(5);
  bridgeLedStrip.show();

  /** Get the number of pixels (LEDs) in each strip for pixel manipulations **/

  leftPillarNumPixels = leftPillarLedStrip.numPixels();
  rightPillarNumPixels = rightPillarLedStrip.numPixels();
  bridgeNumPixels = bridgeLedStrip.numPixels();

  Spark.subscribe("LEDsActivated",ledsActivated);
  Spark.subscribe("BrightnessActivated",brightnessActivated);
}

void ledsActivated(const char *name, const char *data) {
    Serial.print("LEDs activated now");
    String str = String(data);
    char strBuffer[125] = "";
    str.toCharArray(strBuffer, 125);
    int ledStatus = atoi(strtok(strBuffer, "\"~"));
    if(ledStatus)
        canActivateLEDs = true;
    else
        canActivateLEDs = false;
}

void brightnessActivated(const char *name, const char *data) {
    Serial.print("Brightness activated now");
    String str = String(data);
    char strBuffer[125] = "";
    str.toCharArray(strBuffer, 125);
    int brightness = atoi(strtok(strBuffer, "\"~"));
    bridgeBrightness = brightness;
}

void loop() {
    if(canActivateLEDs) {
        lightupBridge();
        lightupPillars();
    } else{
        if(resetRequired) {
            resetLEDs();
            resetRequired = false;
        }
    }
}

void lightupBridge() {
    for(l=bridgeNumPixels-1; l>=0;l--) {
        bridgeLedStrip.setPixelColor(l, blueColor);
        bridgeLedStrip.setBrightness(bridgeBrightness);
        bridgeLedStrip.show();
    }
}

void lightupPillars() {
    for(l=leftPillarNumPixels; l>=0;l--) {
        Serial.println(l);
        leftPillarLedStrip.setPixelColor(l, redColor);
        leftPillarLedStrip.setBrightness(20*l);

        rightPillarLedStrip.setPixelColor(l, greenColor);
        rightPillarLedStrip.setBrightness(20*l);

        rightPillarLedStrip.show();
        leftPillarLedStrip.show();
        delay(100);
    }
}

/* Reset LED Strip upon deactivation */
void resetLEDs() {
    for(l=leftPillarNumPixels; l>=0;l--) {
        leftPillarLedStrip.setPixelColor(l, 0);
        rightPillarLedStrip.setPixelColor(l, 0);
    }
    leftPillarLedStrip.show();
    rightPillarLedStrip.show();

    for(l=bridgeNumPixels; l>=0;l--) {
        bridgeLedStrip.setPixelColor(l, 0);
    }
    bridgeLedStrip.show();
}
