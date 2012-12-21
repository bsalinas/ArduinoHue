#ifndef ARDUINOHUE_H
#define ARDUINOHUE_H
#include <Arduino.h>
#include <avr/pgmspace.h>

	const char turn_on_off[] PROGMEM = "{\"on\":%s}";
	const char change_color_string[] PROGMEM = "{\"hue\":%i,\"sat\":%i}";
	const char set_bri_string[] PROGMEM = "{\"bri\":%i}";
	const char set_alert_string[] PROGMEM = "{\"alert\":\"%s\"}";

typedef void (* ActionFunctionPtr) (char*);
#define MAX_LENGTH_STATION_IDENTIFIER 32
#define STATUS_SUCCESS 1
#define STATUS_POST_ERROR -1
#define STATUS_SERVER_KNOWN_ERROR 2
#define STATUS_SERVER_UNKNOWN_ERROR -2
#define STATUS_OUT_OF_BOUNDS_ERROR -3

class ArduinoHue{
public:
	int turnOff(int light);
	int turnOn(int light);
	int setHueSat(int light,int hue, int sat);
	int setBri(int light, int bri);
	int setShortAlert(int light, boolean on);
	int setLongAlert(int light, boolean on);
	int setTransition(int light, int transition);
	// int registerStation(char* name, char* description, boolean override);
	// int addSensor(char* identifier, char* name, char* description, char* units);
	// int sendSensorData(char* sensor_identifier, int value, int multiplier);
	// int registerAction(char* identifier, char* name, char* description, ActionFunctionPtr func);
	// int addState(char* identifier, char* name, char* description);
	// int setStateValue(char* identifier, char* value);
	// int tick();
protected:
	int fillRequestAndProcess(int light,boolean useStatus);
	virtual boolean makePost(char* request, char* data);
	virtual boolean waitForResponse();
	int evaluateResponse();
	char _lastResponse[255];
	char _buffer[100];
	// ActionFunctionPtr _functions[NActions];




};

#endif