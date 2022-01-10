# HS-Fastled-Brightness
HomeSpan and FastLED powered blinken lights - selectable using brightness dimmer.


Rough experiment to try and build homekit powered blinken lights.

With thanks to HomeSpan for the great library and the examples.
Thanks also to FastLED for a wildly powerful LED library.


As implimented, the device appears as a dimmable light in the home.app. The brightness slider has a 6 positions which select six different patterns.


0. Off
1. Solid Blue
2. Solid Green
3. Solid Yellow
4. Pacifica - from the FastLED examples
5. Cylon - also from the FastLED exmples

Different animations might need varying update speeds so the main() loop includes a non-blocking loop that can impliment different update speeds.
