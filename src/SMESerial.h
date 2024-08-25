#ifndef SMESerial_h
#define SMESerial_h

#include <Arduino.h>
#include <SoftwareSerial.h>

class SMESerial {
public:
    SMESerial(uint8_t rxPin, uint8_t txPin, unsigned int bufferSize = 64);

    void begin(long baudRate);
    void sendData(int numData, float *dataArray);
    void sendData(int numData, int *dataArray);
    void sendData(int numData, long *dataArray);
    void sendData(int numData, String *dataArray);

    bool receiveData(int &numData, float *dataArray);
    bool receiveData(int &numData, int *dataArray);
    bool receiveData(int &numData, long *dataArray);
    bool receiveData(int &numData, String *dataArray);

private:
    SoftwareSerial _serial;
    unsigned int _bufferSize;
    String readData();
    bool sendPacket(const String &packet);
    String receivePacket();
};

#endif
