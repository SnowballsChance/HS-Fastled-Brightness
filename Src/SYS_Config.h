#pragma once

/*
    *
    *   Global Variables
    *   # Defines etc
    *   
*/

#define ver "0.01a"  // Sketch version number

// name assignments
#define deviceName "FastLED"
#define bridgeName "FL-Bridge"
#define manufacturer "Snowball's Chance"
#define serialNumber "Experiment"

// Pin assignments
    // LED indicators
#define homeSpanStatusPin 2  // LED status indicator

    // Buttons
#define homeSpanControlPin 0        // configuration button

// Peripherals             
    // LEDString
    #define LEDStringPin 13

    #define NUM_LEDS 16                    // the number of RGB LED's in your string.

// Globals
CRGB leds[NUM_LEDS];                    // creates a structure holding the settings for each individual RGB LED
byte current_LED_Effect = 0;

// Main loop non-blocking timers
#define INTERVAL1 5
#define INTERVAL2 50
#define INTERVAL3 100
#define INTERVAL4 1000

unsigned long time_1 = 0;
unsigned long time_2 = 0;
unsigned long time_3 = 0;
unsigned long time_4 = 0;

// LED Effects
#define LED_EFFECT_BRIGHTNESS  70
bool LED_EFFECT_gReverseDirection = false;
#define LED_MAX_POWER_MILLIAMPS 500

CRGBPalette16 pacifica_palette_1 = 
    { 0x000507, 0x000409, 0x00030B, 0x00030D, 0x000210, 0x000212, 0x000114, 0x000117, 
      0x000019, 0x00001C, 0x000026, 0x000031, 0x00003B, 0x000046, 0x14554B, 0x28AA50 };
CRGBPalette16 pacifica_palette_2 = 
    { 0x000507, 0x000409, 0x00030B, 0x00030D, 0x000210, 0x000212, 0x000114, 0x000117, 
      0x000019, 0x00001C, 0x000026, 0x000031, 0x00003B, 0x000046, 0x0C5F52, 0x19BE5F };
CRGBPalette16 pacifica_palette_3 = 
    { 0x000208, 0x00030E, 0x000514, 0x00061A, 0x000820, 0x000927, 0x000B2D, 0x000C33, 
      0x000E39, 0x001040, 0x001450, 0x001860, 0x001C70, 0x002080, 0x1040BF, 0x2060FF };
