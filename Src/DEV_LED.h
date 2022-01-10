
////////////////////////////////////
//   DEVICE-SPECIFIC LED SERVICES //
////////////////////////////////////

#include "extras/PwmPin.h"

struct DEV_LED : Service::LightBulb
{ // ON/OFF LED

  int ledPin;                // pin number defined for this LED
  SpanCharacteristic *power; // reference to the On Characteristic

  DEV_LED(int ledPin) : Service::LightBulb()
  { // constructor() method

    power = new Characteristic::On(false, true);
    this->ledPin = ledPin;
    pinMode(ledPin, OUTPUT);

  } // end constructor

  boolean update()
  { // update() method

    digitalWrite(ledPin, power->getNewVal());

    return (true); // return true

  } // update
};

//////////////////////////////////


struct DEV_DimmableLED : Service::LightBulb
{ // Dimmable LED

  LedPin *ledPin;
  SpanCharacteristic *power;
  SpanCharacteristic *level; 

  DEV_DimmableLED(int pin) : Service::LightBulb()
  { // constructor() method

    power = new Characteristic::On(false, true);

    level = new Characteristic::Brightness(0, true); // NEW! Instantiate the Brightness Characteristic with an initial value of 60% and save setting
    level->setRange(20, 100, 20);                     // This sets the range of the Brightness to be from a min of 20%, to a max of 100%, in steps of 20% 

    // this->ledPin = new LedPin(pin); // NEW! Configures a PWM LED for output to the specified pin.  Note pinMode() does NOT need to be called in advance

  } // end constructor

  boolean update()
  {

    // ledPin->set(power->getNewVal() * level->getNewVal());

    // Here we set the global effect flag to match the one  selected in the home app
    if (level->getNewVal() == 20)
    {
      current_LED_Effect = 1;
    }
    if (level->getNewVal() == 40)
    {
      current_LED_Effect = 2;
    }
    if (level->getNewVal() == 60)
    {
      current_LED_Effect = 3;
    }

    if (level->getNewVal() == 80)
    {
      current_LED_Effect = 4;
    }

    if (level->getNewVal() == 100)
    {
      current_LED_Effect = 5;
    }

    if (power->getNewVal() == 0)
    {
      current_LED_Effect = 0;
    }

    return (true); // return true

  } // update
};

//////////////////////////////////
