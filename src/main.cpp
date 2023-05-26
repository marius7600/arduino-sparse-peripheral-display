#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 2  // Number of LEDs
#define DATA_PIN 2  // Data pin for the LEDs

CRGB leds[NUM_LEDS];
bool newData = false;

void setup() {
  Serial.begin(250000);  // Start the serial connection (not working)
  // Serial.begin(19200);  // Start the serial connection (working fine)
  // Serial.begin(23000);  // Start the serial connection (working fine)

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // LED setup
  FastLED.setBrightness(10);  // Set the brightness of the LEDs
}

void loop() {
  if (Serial.available() >= NUM_LEDS * 3) {
    byte data[NUM_LEDS * 3];

    Serial.readBytes(data, NUM_LEDS * 3);

    for (int i = 0; i < NUM_LEDS; i++) {
      byte r = data[i * 3];
      byte g = data[i * 3 + 1];
      byte b = data[i * 3 + 2];
      leds[i] = CRGB(r, g, b);
    }
    FastLED.show();
  }
}