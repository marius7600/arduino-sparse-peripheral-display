#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 48  // Number of LEDs
#define DATA_PIN 2  // Data pin for the LEDs
#define BAUD_RATE 256000  // Baud rate for the serial connection

CRGB leds[NUM_LEDS];  // LED array

int currentLED = 0;
bool initialized = false;

void setup() {
  // Start the serial connection
  Serial.begin(BAUD_RATE);

  // Setup the LEDs
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
}

/// @brief Receives data from the serial connection and pushes it to the LEDs
void unity() {
  if (Serial.available() >= NUM_LEDS * 3) {
    // data is 3 bytes per LED
    byte data[NUM_LEDS * 3];

    // Read the data from the serial connection
    Serial.readBytes(data, NUM_LEDS * 3);

    // Decode the data
    for (int i = 0; i < NUM_LEDS; i++) {
      byte r = data[i * 3];
      byte g = data[i * 3 + 1];
      byte b = data[i * 3 + 2];
      leds[i] = CRGB(r, g, b);
    }

    // Push the data to the LEDs
    FastLED.show();
  }
}

/// @brief Turns on one LED at a time
void singleLedTest () {
  // turn current LED on
  leds[currentLED] = CRGB::White;
  FastLED.show();
  
  delay(100);
  leds[currentLED] = CRGB::Black;
  FastLED.show();
  currentLED = (currentLED + 1) % NUM_LEDS;
}

/// @brief Turns on all LEDs
void testAllLeds() {
  if (!initialized) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::White;
    }
    FastLED.show();
    initialized = true;
  }
}

void loop () {
  unity();
  // singleLedTest();
  // testAllLeds();
}
