#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 2  // Anzahl der LEDs
#define DATA_PIN 2  // Daten-Pin für die LEDs

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(250000);  // Starte die serielle Verbindung

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // Setup der LEDs
  // FastLED.setBrightness();  // Setze die Helligkeit der LEDs
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
    delay(3);
  }
}


// void example() {
//   // Print a heartbeat
//   if (millis() > last_time + 2000)
//   {
//     Serial.println("Arduino is alive!!");
//     last_time = millis();
//   }

//   switch (Serial.read())
//   {
//     case 'A':
//       leds[0] = CRGB::Green;
//       leds[1] = CRGB::Green;
//       FastLED.show();
//       delay(500);
//       break;
//     case 'Z':
//       leds[0] = CRGB::Blue;
//       leds[1] = CRGB::Blue;
//       FastLED.show();
//       delay(500);
//       break;
//     default:
//       leds[0] = CRGB::Red;
//       leds[1] = CRGB::Red;
//       FastLED.show();
//       break;
//   }
// }