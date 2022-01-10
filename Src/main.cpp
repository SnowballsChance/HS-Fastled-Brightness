#include <Arduino.h>
#include "FastLED.h"
#include "HomeSpan.h"

#include "SYS_Config.h"
#include "DEV_LED.h"
#include "LED_Patterns.h"


void setup()
{
  Serial.begin(115200);

  FastLED.addLeds<WS2812B, LEDStringPin, GRB>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip); // GRB ordering is typical
  FastLED.setMaxPowerInVoltsAndMilliamps( 5, LED_MAX_POWER_MILLIAMPS);
 
  FastLED.setBrightness(LED_EFFECT_BRIGHTNESS);

  homeSpan.setApSSID(deviceName);
  homeSpan.enableAutoStartAP();
  homeSpan.setSketchVersion(ver);
  homeSpan.setControlPin(homeSpanControlPin);
  homeSpan.setStatusPin(homeSpanStatusPin);
  homeSpan.enableOTA(false);
  homeSpan.setPairingCode("11223344");
  homeSpan.begin(Category::Lighting, "HomeSpan LEDs");

  new SpanAccessory();

  new Service::AccessoryInformation();
  new Characteristic::Name("On/Off LED");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("123-ABC");
  new Characteristic::Model("20mA LED");
  new Characteristic::FirmwareRevision("0.9");
  new Characteristic::Identify();

  new Service::HAPProtocolInformation();
  new Characteristic::Version("1.1.0");

  new DEV_LED(4); // create an on/off LED attached to pin 16 (same as in Example 5)

  new SpanAccessory();

  new Service::AccessoryInformation();
  new Characteristic::Name("Dimmable LED");
  new Characteristic::Manufacturer("HomeSpan");
  new Characteristic::SerialNumber("123-ABC");
  new Characteristic::Model("20mA LED");
  new Characteristic::FirmwareRevision("0.9");
  new Characteristic::Identify();

  new Service::HAPProtocolInformation();
  new Characteristic::Version("1.1.0");

  new DEV_DimmableLED(5); // NEW! create a dimmable (PWM-driven) LED attached to pin 17.  See new code at end of DEV_LED.h

} // end of setup()

//////////////////////////////////////

void loop()
{

  do
  { // infinite loop

    homeSpan.poll();


    if (millis() - time_1 >= INTERVAL1)
    {

      // Serial.println("Interval 1");

      // Insert code here

      time_1 = millis();
    } // end interval 1 interface (buttons)

    if (millis() - time_2 >= INTERVAL2)
    {

      // Serial.println("Interval 2");

      // Insert code here

      switch (current_LED_Effect)
      {
      case 0:
        fill_solid(leds, NUM_LEDS, CRGB::Black);
            FastLED.show();
        break;
      case 1:
        fill_solid(leds, NUM_LEDS, CRGB::BlueViolet);
            FastLED.show();
        break;
      case 2:
        fill_solid(leds, NUM_LEDS, CRGB::Green);
            FastLED.show();
        break;
      case 3:
        fill_solid(leds, NUM_LEDS, CRGB::Yellow);
            FastLED.show();
        break;
      case 4:


        pacifica_loop();
        FastLED.show();

        break;
      case 5:

        // nothing here
        break;

      default:
        break;
      }

      time_2 = millis();
    } // end interval 2

    if (millis() - time_3 >= INTERVAL3)
    {

      // Serial.println("Interval 3");

      // Insert code here



switch (current_LED_Effect)
      {
      case 5:

        cylon();
        break;

      default:
        break;
      }

      time_3 = millis();
    } // end interval 3

    if (millis() - time_4 >= INTERVAL4)
    {

      // Serial.println("Interval 4");

      // Insert code here

      time_4 = millis();
    } // end interval 4

  } while (1); // infinite loop

} // end of loop()
