# ArcReactor-Gauntlet
Controlling a lighting system in Ironman (Jarvis) style.

### Introduction
We are planning to implement a gesture controlled lighting
mechanism. We are envisioning this system for indoor lighting purposes
only. The gesture vocabulary would consist of waves and motions made
with the palm. These gestures would be read with the help of the Iron
Man’s Gauntlet. The “Laser Repulsor” in the palms would read the
gestures and convey it to the system to trigger the appropriate,
consequent change. The lighting mechanism on itself would consist of a
length strip of RGB LED lights. With the help of the gestures, we would
be able to turn the lights on and off, control the brightness, increase
or decrease the length of the strip that gets illuminated.

[Proposal Document](https://github.com/nathan5x/ArcReactor-Gauntlet/blob/master/Docs/ArcReactor_Proposal.pdf)

How to control lights using the Iron Man’s Gauntlet:

We have made a gauntlet and a laser repulsor. Our design is inspired by the one that Iron Man uses, and we have tried to replicate the design. We are calling this gauntlet-repulsor combination as the “Iron Man’s glove”.
Apart from having a nice visual effect, this glove can be used to control the lights.
In this instructable article, we have explained how to make this gauntlet, laser repulsor, and also the lights which can be controlled. There’s quite a bit of 3D printing and laser-cutting involved. Basic knowledge of electronics and circuits is enough understand this article easily. We have also provided the code for programming the circuits and the lights.



**Step 1:** Components Required
Breadboards - 2
Sparkfun Triple-Axis Accelerometer
RGB LED Strip: https://www.adafruit.com/products/1460
RGB LED NeoPixel Ring : https://www.adafruit.com/products/1463
Clear Cast Acrylic - 1 Sheets
Particle Photon - 2
5V Adapter
3.7V Li-Ion Poly rechargeable battery
Soft Ply Wood - 2 Sheets
Connecting Wires.


**Step 2:** Making the Laser Repulsor:
Solder 3 wires to the back of the NeoPixel ring: 1 for each Power, Data, and Ground
3D print the holder for the NeoPixel ring
Design a pattern for the repulsor and laser-cut it on a clear acrylic sheet. Stick this pattern on top of the holder with the NeoPixel ring inside it. Your apparatus must look like (Fig: CircuitLayout_6.JPG) now


**Step 3:** Making the Gauntlet
Connect the accelerometer. Flash the code and check if you are able to get any data via serial. <Insert Code>
Once you can read data from the accelerometer, try to publish the data via particle cloud. Your apparatus must look like (Fig.CircuitLayout_1.JPG)
Connect the 3.7V battery to the breadboard so that it can function as an independent unit
Make a 3D model of a gauntlet for this accelerometer circuitry to sit inside. Design it in such a way that it sits snuggly on the back of your palm. We have made a small box with ridges on top. This is how our design looked (Fig. CircuitLayout_7.JPG). The box cover was ridged like Fig:PhysicalComponent_24. We wanted it to look like a mini-missile blaster that comes out of Iron Man’s Gauntlet!
Once you have this gauntlet ready with all the circuits, plug in the laser repulsor to the front so that it drops to the center of the palm. Tie the laser repulsor to the box using strings so that it doesn’t fall off.
Program the NeoPixel to work according to the changes made to the accelerometer <Insert Code>

**Step 4:** Making the display lights
Laser cut and etch out a beautiful pattern.We chose to design the Golden Gate Bridge (Fig: PhysicalComponent_1.JPG)
Cut out strips of NeoPixel RGB LED. Place it along the design. (Fig:PhysicalComponent_10.JPG)
Plug in all the wires. (Fig: CircuitLayout_5.JPG). Ensure that you have provisioned for a +5V DC input to be provided to this circuit.
Program this photon to act according to events received via the particle cloud <insert code>
Test to see if the LED lights work
Make nice frames for the display (Fig:PhysicalComponent_14.JPG) . Stick the frames so that the display can rest on a wall.



**Step 5:** Final thoughts
General thoughts and how it can be improved.
Add music! Add a speaker which will give out an addition “Whoosh” sound every time the laser repulsor fires up.
Consider using an accelerometer with IMU like this: https://www.sparkfun.com/products/11028 . It’ll provide us with precise position data and will not rely entirely on acceleration alone to register an input
Use a thinner breadboard with thinner wires. Design a sleeker gauntlet. Thinner the better!

Youtube Video:
https://www.youtube.com/watch?v=yWfIvwNryL4
