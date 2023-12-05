#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define FINGER 2

RF24 radio(7, 8);
const byte address[10] = "00001";
int flex;
int x;

void setup() {

  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  flex = analogRead(FINGER);
  Serial.println (flex);
  radio.write(&flex, sizeof(flex));
  delay(100);
}
