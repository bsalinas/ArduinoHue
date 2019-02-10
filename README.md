ArduinoHue
==========

An Arduino Library for controlling the Philips Hue. This is a work in progress, but the basic functionality is present.

## Important Note ##

Starting in February 2016, Custom whitelist usernames will no longer be allowed and the bridge randomly generated username must be used instead. Please see [this link](http://www.developers.meethue.com/documentation/important-whitelist-changes) for more information.

This library does not currently support this. If you are interested in taking over ownership of this repo, feel free to do so.


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

void setup(){

}
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
hue.setHueSat(1,45000,255);
```

For the Arduino to communicate with the Hue Lights, you will need to run the `SerialBridge.py` python script on your computer. In that file, you will need to update the device id on line 5 to the device id of your Arduino (for instance `COM5` on Windows or `/dev/tty.usbmodemfd131` on a Mac).
To use this script you will need the pySerial module (http://pyserial.sourceforge.net/) and the Requests module (http://docs.python-requests.org/en/latest/user/install.html#install).
