#include <Servo.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define FINGER 2
  
RF24 radio(7, 8);
Servo myservo;
int flex;
const byte address[10] = "00001";

void setup() {
  Serial.begin(115200);

  myservo.attach(FINGER);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    radio.read(&flex, sizeof(flex));
    flex = map(flex, 570, 770, 1, 180);
    if (flex < 30) flex = 0;
    Serial.println(flex);
    myservo.write(flex);
  }
  delay (100);
}
