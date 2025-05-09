#include <RF24.h>
#include <SPI.h>
#include <RF24Audio.h>

RF24 radio(7, 8);  // CE, CSN
RF24Audio rfAudio(radio, 1);

const int statusLED = 6;

void setup() {
  Serial.begin(115200);

  Serial.println("[INFO] Starting the radio...");

  pinMode(statusLED, OUTPUT);

  const bool radioStarted = radio.begin();

  if (radioStarted) {
    Serial.println("[INFO] Successfully started the radio.");

    digitalWrite(statusLED, HIGH);

  } else {
    Serial.println("[ERROR] Radio hardware is not responding!");

    while (true) {
      digitalWrite(statusLED, HIGH);
      delay(500);
      digitalWrite(statusLED, LOW);
      delay(500);
    };
  }

  rfAudio.begin();
}

void loop() {
  rfAudio.handleButtons();
}
