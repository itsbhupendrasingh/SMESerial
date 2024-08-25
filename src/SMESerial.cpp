\#include "SMESerial.h"

SMESerial::SMESerial(uint8_t rxPin, uint8_t txPin, unsigned int bufferSize) 
    : _serial(rxPin, txPin), _bufferSize(bufferSize) {}

void SMESerial::begin(long baudRate) {
    _serial.begin(baudRate);
}

void SMESerial::sendData(int numData, float *dataArray) {
    String packet = String(numData);
    for (int i = 0; i < numData; i++) {
        packet += "|" + String(dataArray[i], 6); // 6 decimal places for float
        if (packet.length() > _bufferSize - 10) { // -10 for some safety margin
            sendPacket(packet);
            packet = ""; // Start a new packet
        }
    }
    if (packet.length() > 0) {
        sendPacket(packet);
    }
}

void SMESerial::sendData(int numData, int *dataArray) {
    String packet = String(numData);
    for (int i = 0; i < numData; i++) {
        packet += "|" + String(dataArray[i]);
        if (packet.length() > _bufferSize - 10) {
            sendPacket(packet);
            packet = "";
        }
    }
    if (packet.length() > 0) {
        sendPacket(packet);
    }
}

void SMESerial::sendData(int numData, long *dataArray) {
    String packet = String(numData);
    for (int i = 0; i < numData; i++) {
        packet += "|" + String(dataArray[i]);
        if (packet.length() > _bufferSize - 10) {
            sendPacket(packet);
            packet = "";
        }
    }
    if (packet.length() > 0) {
        sendPacket(packet);
    }
}

void SMESerial::sendData(int numData, String *dataArray) {
    String packet = String(numData);
    for (int i = 0; i < numData; i++) {
        packet += "|" + dataArray[i];
        if (packet.length() > _bufferSize - 10) {
            sendPacket(packet);
            packet = "";
        }
    }
    if (packet.length() > 0) {
        sendPacket(packet);
    }
}

bool SMESerial::receiveData(int &numData, float *dataArray) {
    String packet = receivePacket();
    if (packet.length() > 0) {
        int index = 0;
        numData = packet.substring(0, packet.indexOf('|')).toInt();
        packet = packet.substring(packet.indexOf('|') + 1);

        while (packet.length() > 0 && index < numData) {
            int delimiterIndex = packet.indexOf('|');
            if (delimiterIndex == -1) {
                dataArray[index++] = packet.toFloat();
                break;
            } else {
                dataArray[index++] = packet.substring(0, delimiterIndex).toFloat();
                packet = packet.substring(delimiterIndex + 1);
            }
        }
        return true;
    }
    return false;
}

bool SMESerial::receiveData(int &numData, int *dataArray) {
    String packet = receivePacket();
    if (packet.length() > 0) {
        int index = 0;
        numData = packet.substring(0, packet.indexOf('|')).toInt();
        packet = packet.substring(packet.indexOf('|') + 1);

        while (packet.length() > 0 && index < numData) {
            int delimiterIndex = packet.indexOf('|');
            if (delimiterIndex == -1) {
                dataArray[index++] = packet.toInt();
                break;
            } else {
                dataArray[index++] = packet.substring(0, delimiterIndex).toInt();
                packet = packet.substring(delimiterIndex + 1);
            }
        }
        return true;
    }
    return false;
}

bool SMESerial::receiveData(int &numData, long *dataArray) {
    String packet = receivePacket();
    if (packet.length() > 0) {
        int index = 0;
        numData = packet.substring(0, packet.indexOf('|')).toInt();
        packet = packet.substring(packet.indexOf('|') + 1);

        while (packet.length() > 0 && index < numData) {
            int delimiterIndex = packet.indexOf('|');
            if (delimiterIndex == -1) {
                dataArray[index++] = packet.toInt();
                break;
            } else {
                dataArray[index++] = packet.substring(0, delimiterIndex).toInt();
                packet = packet.substring(delimiterIndex + 1);
            }
        }
        return true;
    }
    return false;
}

bool SMESerial::receiveData(int &numData, String *dataArray) {
    String packet = receivePacket();
    if (packet.length() > 0) {
        int index = 0;
        numData = packet.substring(0, packet.indexOf('|')).toInt();
        packet = packet.substring(packet.indexOf('|') + 1);

        while (packet.length() > 0 && index < numData) {
            int delimiterIndex = packet.indexOf('|');
            if (delimiterIndex == -1) {
                dataArray[index++] = packet;
                break;
            } else {
                dataArray[index++] = packet.substring(0, delimiterIndex);
                packet = packet.substring(delimiterIndex + 1);
            }
        }
        return true;
    }
    return false;
}

bool SMESerial::sendPacket(const String &packet) {
    _serial.println(packet);
    delay(10); // Give the receiver some time to process
    return true;
}

String SMESerial::receivePacket() {
    return readData();
}

String SMESerial::readData() {
    if (_serial.available()) {
        return _serial.readStringUntil('\n');
    }
    return "";
}
