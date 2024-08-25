#include <SMESerial.h>

SMESerial comm(6, 7, 128);  // Define RX as pin 6, TX as pin 7, and set buffer size to 128 bytes

void setup() {
    Serial.begin(9600);
    comm.begin(9600);  // Initialize SoftwareSerial with the defined pins and baud rate

    float sensorData[] = {25.70, 65.90, 40.0, 12.34, 56.78, 90.12};  // Example sensor data
    comm.sendData(6, sensorData);  // Sending 6 data points
}

void loop() {
    // Send or receive data periodically
}
