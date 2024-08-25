# SMESerial

SMESerial is a library for serial communication between Arduino and NodeMCU. It supports the transmission and reception of various data types including strings, floats, integers, and long data.

## Features

- Configurable RX and TX pins
- Supports different data types
- Packet-based data transmission

## Installation

Simply download the library from GitHub and add it to your Arduino IDE.

## Usage

Here’s how to use the library in your projects:

```cpp
#include <SMESerial.h>

SMESerial comm(6, 7, 128);  // RX on pin 6, TX on pin 7

void setup() {
    Serial.begin(9600);
    comm.begin(9600);
    // Add your setup code here
}

void loop() {
    // Add your loop code here
}
