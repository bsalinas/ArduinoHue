ArduinoHue
==========

An Arduino Library for controlling the Philips Hue. This is a work in progress, but the basic functionality is present.

## Different Versions ##
Eventually, there will be multiple flavors of the library which will connec to the network in different manners. The first version, which is available now, communicates with a computer over Serial and uses a Python script to post the data to the internet.

## Usage ##
Make sure you have the following at the top of your sketch.
```
import <ArduinoHue.h>
import <SerialHue.h>
```

To create the SerialHue object, 

```
SerialHue hue("192.168.1.10", &Serial);

void loop(){
  Serial.begin(9600);
  hue.connect("YOUR_DEVICE_ID", "YOUR_USERNAME");
  //Everything else.
}
```

Then, you can change colors and turn lights on or off using the following commands:

```
hue.turnOn(1);//1 is the Light ID.
hue.turnOff(2); //2 is the Light ID.
//1 is the light, 45000 is the hue, and 255 is the saturation;
//Hue is on the scale of 0 - 65,000 and saturation is on the scale of 0-255
hue.seHueSat(1,45000,255);
```
