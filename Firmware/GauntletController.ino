#include "MMA8452Q.h"
#include "neopixel/neopixel.h"

#define RING_PIN D4
#define PIXEL_COUNT 24

#define PILLAR_LED_STRIP D5
#define PILLAR_PIXEL_COUNT 8
#define PILLAR_PIXEL_TYPE WS2812B

MMA8452Q accMeter;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, RING_PIN);

char publishString[180];
char statusString[180];
char brightnessString[180];

int onThresold = 650;
int offThresold = -650;
int initalRingBrightness = 60;

uint8_t  mode   = 0, // Current animation effect
         offset = 0; // Position of spinny eyes

uint32_t color  = 0xffae00; // Start red
uint32_t prevTime;

bool isActivated = false;
bool canPillarReady = false;
bool resetDone = false;

uint32_t blueColor = pixels.Color(0, 0, 255);

void setup() {
  /* Initial Settings */
  Serial.begin(9600);

  pixels.begin();
  pixels.setBrightness(initalRingBrightness);

  prevTime = millis();
  accMeter.init(SCALE_2G, ODR_1);
}

void loop() {

  if (accMeter.available())
    {
        accMeter.read();
        int x = accMeter.x;
        float cx = accMeter.cx;
        int y = accMeter.y;
        float cy = accMeter.cy;
        int z = accMeter.z;
        float cz = accMeter.cz;
        int tap= accMeter.readTap();
        //sprintf(publishString,"{\"x\":%d,\"y\":%d,\"z\":%d}",x,y,z);
        Serial.println(publishString);

        /* Activate the Gauntlet for Interactions */
        if(tap >= 16) {
            if(isActivated) {
                isActivated = false;
            } else {
                isActivated = true;
            }
        }

        if(isActivated) {
            powerUpRing();
            resetDone = false;
        } else{
            if(!resetDone) {
                resetRing();
            }
        }

        /* Pillar Light Controlling Events */

        if(y>=onThresold) {
            if(!canPillarReady && isActivated) {
                canPillarReady = true;
                sprintf(statusString, "1");
                Spark.publish("LEDsActivated",statusString);
            }
        } else if (y<=offThresold) {
            if(canPillarReady && isActivated) {
                canPillarReady = false;// if turn on
                sprintf(statusString, "0");
                Spark.publish("LEDsActivated",statusString);
            }
        }


        /* Bridge Light Controlling Events */
        int brightnessLevel = 0;
        if( x < 0) {
            brightnessLevel = (x*-1) % 8;
            Serial.println(brightnessLevel);
        } else {
            brightnessLevel = (x % 8) + 100;
        }

        if(isActivated) {
            sprintf(brightnessString, "%d~", brightnessLevel);
            Serial.println(brightnessString);
            Spark.publish("BrightnessActivated",brightnessString);
        }
    }

}

void powerUpRing() {
    uint8_t  i;
    uint32_t t;

    for(i=0; i<PIXEL_COUNT/2; i++) {
        uint32_t c = 0;
        if(((offset + i) & 6) < 2)
            c = color; // 4 pixels on...

        pixels.setPixelColor(   i, blueColor);
        pixels.setPixelColor(PIXEL_COUNT-1-i, blueColor);

        pixels.setBrightness(100);
    }

    pixels.show();
    offset++;
    delay(10);
}

 void resetRing() {
    uint8_t  i;
    for(i=0; i<PIXEL_COUNT; i++) {
        pixels.setPixelColor(i, 0);
    }
    pixels.show();
    resetDone = true;
 }
