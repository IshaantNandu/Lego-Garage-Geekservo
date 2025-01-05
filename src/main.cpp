#include <Arduino.h>

//Hardware specific libraries
#if defined(__AVR__)
#include <Servo.h>  // Include Servo.h for AVR boards
#elif defined(ESP32)
#include <ESP32Servo.h> // Include ESP32Servo.h for ESP32
#endif

//The servo object
Servo door;  

//the pins we're gonna use

uint8_t doorpin = 13;
uint8_t openpin = 12;

void setup()
{
    door.attach(doorpin, 600, 1500);//Nessescary for GeekServo
    pinMode(openpin, INPUT_PULLUP);
}

void loop()
{
}