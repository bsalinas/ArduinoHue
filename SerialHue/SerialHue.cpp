#include "SerialHue.h"

SerialHue::SerialHue(char* ipAddress, Stream* serial){
	_ipAddress = ipAddress;
	_serial = serial;
}

boolean SerialHue::connect(char* deviceId, char* username){
	_username = username;
	_deviceId = _deviceId;
}

boolean SerialHue::makePost(char* request, char* data){
	_serial -> flush();
	_serial->write(0x04);
	_serial->print("http://");
	_serial->print(_ipAddress);
	_serial->write(0x05);
	_serial->write(0x06);
	_serial->print("/api/22a828f1898a4257c3f181e753241337/");
	_serial->print(request);
	_serial->write(0x07);
	_serial->write(0x08);
	_serial->print(data);
	_serial->write(0x03);
	return waitForResponse();
}
boolean SerialHue::waitForResponse(){
	while(_serial->available() <=0 ){
		delay(10);
	}
	int i=0;
	_lastResponse[0]='\0';
	while(_serial->available() > 0){
		_lastResponse[i] = _serial->read();
		i++;
		delay(10);
	}
	_lastResponse[i]='\0';
	return true;
}