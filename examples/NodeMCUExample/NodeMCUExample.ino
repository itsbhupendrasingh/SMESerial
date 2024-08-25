#include <SMESerial.h>

SMESerial comm(D6, D7, 128);  // Define RX as D6, TX as D7, and set buffer size to 128 bytes

void setup() {
    Serial.begin(9600);
    comm.begin(9600);  // Initialize SoftwareSerial with the defined pins and baud rate
}

void loop() {
    int numData;
    float sensorData[10];  // Array to hold received data

    if (comm.receiveData(numData, sensorData)) {
        Serial.print("Received ");
        Serial.print(numData);
        Serial.println(" data points:");

        for (int i = 0; i < numData; i++) {
            Serial.print("Data ");
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.println(sensorData[i]);
        }
    }

    delay(1000);  // Adjust delay as needed
}
