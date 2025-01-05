#include <Arduino.h>

// Hardware specific libraries
#if defined(__AVR__)
#include <Servo.h> // Include Servo.h for AVR boards
#elif defined(ESP32)
#include <ESP32Servo.h> // Include ESP32Servo.h for ESP32
#endif

// The servo object
Servo door;

// the pins we're gonna use

uint8_t doorpin = 13;
uint8_t openpin = 12;

void setup()
{
    //Comment the line below if you're using a SG90
    door.attach(doorpin, 600, 1500); // Nessescary for GeekServo
    pinMode(openpin, INPUT_PULLUP);  // The pin in the IR sensor
    door.write(0);
}

/*****************\
 Functions for ease of use
 \*****************/


//Opens the door
void open()
{
    door.write(90);
    delay(2000);
}

//Closes the door
void close(){
   door.write(0);
   delay(100);
}

//The actual stuff......
void loop()
{
    bool prevstate = false;
    bool state = not(digitalRead(openpin));
    //If the sensor detected a car
    if (state == true)
    {open();}
    //CPU optimization (optional)
    else if (state == false and prevstate == false)
    {
        delay(100);
    }
    //If the sensor didn't detect a car
    else
    {close();}
    prevstate=state;
}