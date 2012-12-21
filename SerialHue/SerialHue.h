#ifndef SERIALHUE_H
#define SERIALHUE_H
#include <Arduino.h>
#include <Stream.h>
#include <ArduinoHue.h>



class SerialHue: public ArduinoHue{
public:
	SerialHue(char* ipAddress, Stream* serial);
	boolean connect(char* deviceId, char* username);
protected:
	char* _ipAddress; 
	char* _deviceId;
	char* _username;
	boolean makePost(char* request, char* data);
	boolean waitForResponse();
	Stream* _serial;
};

#endif