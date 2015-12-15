# ArcReactor-Gauntlet
Controlling a lighting system in Ironman (Jarvis) style.

### Introduction
We have implemented a gesture controlled lighting system. We have made a gauntlet and a laser repulsor. Our design is inspired by the one that Iron Man uses, and we have tried to replicate the design. We are calling this gauntlet-repulsor combination as the “Iron Man’s glove”. This glove is our gesture recognition device.The lights themselves are comprised of strips of programmable NeoPixel RGB LED Strips.We have made a replica design of the Golden Gate Bridge. We have arranged the strips along the design to create a nice visual effect. We are controlling these LED strips with the help of gestures. There’s quite a bit of 3D printing and laser-cutting involved.

![Network Strength Simulation](/Images/GauntletDisplayBanner.jpg)

#### Proposal
[Proposal Document](https://github.com/nathan5x/ArcReactor-Gauntlet/blob/master/Docs/ArcReactor_Proposal.pdf)

#### Final Report
[Final Paper](https://github.com/nathan5x/ArcReactor-Gauntlet/blob/master/Docs/FinalPaper.pdf)

#### Instructable Article
[For detailed instructions on how to build](http://www.instructables.com/id/Ironmans-ArcReactor-Gauntlet-Light-Controlling-Sys/)

#### Youtube Video for Demonstration
[Ironman's Gauntlet and Laser Repulsor](https://youtu.be/D1eNAbzzMB0)

### How to control lights using the Iron Man’s Gauntlet:
We have made a gauntlet and a laser repulsor. Our design is inspired by the one that Iron Man uses, and we have tried to replicate the design. We are calling this gauntlet-repulsor combination as the “Iron Man’s glove”.
Apart from having a nice visual effect, this glove can be used to control the lights.
In this instructable article, we have explained how to make this gauntlet, laser repulsor, and also the lights which can be controlled. There’s quite a bit of 3D printing and laser-cutting involved. Basic knowledge of electronics and circuits is enough understand this article easily. We have also provided the code for programming the circuits and the lights.

#### Components Required
1. Breadboards - 2
2. Sparkfun Triple-Axis Accelerometer
3. RGB LED Strip: https://www.adafruit.com/products/1460
4. RGB LED NeoPixel Ring : https://www.adafruit.com/products/1463
5. Clear Cast Acrylic - 1 Sheets
6. Particle Photon - 2
7. 5V Adapter
8. 3.7V Li-Ion Poly rechargeable battery
9. Soft Ply Wood - 2 Sheets
10. Connecting Wires.

#### APIs Used
1. [Neopixel APIs from Adafruit](https://github.com/adafruit/Adafruit_NeoPixel)

2. [Particle Cloud APIs](https://docs.particle.io/reference/api/)

#### Motivation
Ironman's JARVIS :)

#### General thoughts and how it can be improved.
Add music! Add a speaker which will give out an addition “Whoosh” sound every time the laser repulsor fires up.

Consider using an accelerometer with IMU like this: https://www.sparkfun.com/products/11028 . It’ll provide us with precise position data and will not rely entirely on acceleration alone to register an input.
Use a thinner breadboard with thinner wires. Design a sleeker gauntlet. Thinner the better!
