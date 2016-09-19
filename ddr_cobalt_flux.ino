#include <Joystick.h>

#define PIN_OFFSET 2
#define NUM_PINS 10

boolean lastButtonState[NUM_PINS];

void setup() {

  for (int index = 0; index <= NUM_PINS; index++)  {
    pinMode(index + PIN_OFFSET, INPUT_PULLUP);
    lastButtonState[NUM_PINS] = 0;
  }
  Joystick.setZAxis(0);
  Joystick.setXAxis(0);
  Joystick.setYAxis(0);
  Joystick.setThrottle(127);
  Joystick.setRudder(127);
    Joystick.setXAxisRotation(180);
  Joystick.setYAxisRotation(180);
  Joystick.begin();
}

void loop() {

  // Read pin values
  for (int index = 0; index <= NUM_PINS; index++)
  {
    int currentButtonState = !digitalRead(index + PIN_OFFSET);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(50);
}

