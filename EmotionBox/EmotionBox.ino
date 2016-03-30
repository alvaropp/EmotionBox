/*
EmotionBox
Copyright (c) 2016 Alvaro Perez

This code is under a GNU GENERAL PUBLIC LICENSE
                     Version 3, 29 June 2007


Arduino software for the EmotionBox to accompany the following how-to
in Instructables website.
*/

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(2, 3); // RX, TX
#define BLYNK_PRINT SwSerial
#include <BlynkSimpleSerial.h>
#include <SimpleTimer.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "EnterYourPrivateAuthCodeHere";

SimpleTimer timer;

// Define the digital pins your buttons are using
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;
const int buttonPin5 = 6;
// Define the digital pins your LEDs are using
const int led1 = 7;
const int led2 = 8;
const int led3 = 9;
const int led4 = 10;
const int led5 = 11;
// All LEDs start off
int state_1 = LOW;
int state_2 = LOW;
int state_3 = LOW;
int state_4 = LOW;
int state_5 = LOW;
// All readings start off as well
int reading_1;
int previous_1 = LOW;
int reading_2;
int previous_2 = LOW;
int reading_3;
int previous_3 = LOW;
int reading_4;
int previous_4 = LOW;
int reading_5;
int previous_5 = LOW;
// Debounce time for reliable buttons
long time = 0;         // the last time the output pin was toggled
long debounce = 300;   // the debounce time, increase if the output flickers

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void checkButton1()
{
  reading_1 = digitalRead(buttonPin1);
  if (reading_1 == HIGH && previous_1 == LOW && millis() - time > debounce) {
    if (state_1 == HIGH) {
      state_1 = LOW;
    } else {
      state_1 = HIGH;
    }
    time = millis();
  }

  if (state_1 == HIGH) {
    digitalWrite(led1, state_1);
    Blynk.virtualWrite(V1, state_1);
  } else {
    digitalWrite(led1, state_1);
    Blynk.virtualWrite(V1, state_1);
  }
}

void checkButton2()
{
  reading_2 = digitalRead(buttonPin2);
  if (reading_2 == HIGH && previous_2 == LOW && millis() - time > debounce) {
    if (state_2 == HIGH) {
      state_2 = LOW;
    } else {
      state_2 = HIGH;
    }
    time = millis();
  }

  if (state_2 == HIGH) {
    digitalWrite(led2, state_2);
    Blynk.virtualWrite(V2, state_2);
  } else {
    digitalWrite(led2, state_2);
    Blynk.virtualWrite(V2, state_2);
  }
}

void checkButton3()
{
  reading_3 = digitalRead(buttonPin3);
  if (reading_3 == HIGH && previous_3 == LOW && millis() - time > debounce) {
    if (state_3 == HIGH) {
      state_3 = LOW;
    } else {
      state_3 = HIGH;
    }
    time = millis();
  }

  if (state_3 == HIGH) {
    digitalWrite(led3, state_3);
    Blynk.virtualWrite(V3, state_3);
  } else {
    digitalWrite(led3, state_3);
    Blynk.virtualWrite(V3, state_3);
  }
}

void checkButton4()
{
  reading_4 = digitalRead(buttonPin4);
  if (reading_4 == HIGH && previous_4 == LOW && millis() - time > debounce) {
    if (state_4 == HIGH) {
      state_4 = LOW;
    } else {
      state_4 = HIGH;
    }
    time = millis();
  }

  if (state_4 == HIGH) {
    digitalWrite(led4, state_4);
    Blynk.virtualWrite(V4, state_4);
  } else {
    digitalWrite(led4, state_4);
    Blynk.virtualWrite(V4, state_4);
  }
}

void checkButton5()
{
  reading_5 = digitalRead(buttonPin5);
  if (reading_5 == HIGH && previous_5 == LOW && millis() - time > debounce) {
    if (state_5 == HIGH) {
      state_5 = LOW;
    } else {
      state_5 = HIGH;
    }
    time = millis();
  }

  if (state_5 == HIGH) {
    digitalWrite(led5, state_5);
    Blynk.virtualWrite(V5, state_5);
  } else {
    digitalWrite(led5, state_5);
    Blynk.virtualWrite(V5, state_5);
  }
}

// Functions to read the state of each buttons from
// the phone app
BLYNK_WRITE(V1) //Button Widget is writing to pin V1
{
  int v_reading = param.asInt();
  if (v_reading == HIGH) {
    state_1 = HIGH;
  } else {
    state_1 = LOW;
  }
}

BLYNK_WRITE(V2) //Button Widget is writing to pin V2
{
  int v_reading = param.asInt();
  if (v_reading == HIGH) {
    state_2 = HIGH;
  } else {
    state_2 = LOW;
  }
}

BLYNK_WRITE(V3) //Button Widget is writing to pin V3
{
  int v_reading = param.asInt();
  if (v_reading == HIGH) {
    state_3 = HIGH;
  } else {
    state_3 = LOW;
  }
}

BLYNK_WRITE(V4) //Button Widget is writing to pin V4
{
  int v_reading = param.asInt();
  if (v_reading == HIGH) {
    state_4 = HIGH;
  } else {
    state_4 = LOW;
  }
}

BLYNK_WRITE(V5) //Button Widget is writing to pin V5
{
  int v_reading = param.asInt();
  if (v_reading == HIGH) {
    state_5 = HIGH;
  } else {
    state_5 = LOW;
  }
}

void setup()
{
  Serial.begin(9600); // See the connection status in Serial Monitor
  Blynk.begin(auth);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  // Setup a function to be called every second
  timer.setInterval(1000L, checkButton1);
  timer.setInterval(1000L, checkButton2);
  timer.setInterval(1000L, checkButton3);
  timer.setInterval(1000L, checkButton4);
  timer.setInterval(1000L, checkButton5);
}

void loop()
{
  Blynk.run(); // Initiates Blynk
  timer.run(); // Initiates SimpleTimer
}

