
#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);

void setup() {
  Serial.begin(9600);

  Serial.println("Teste NRF24L01");
  Serial.println("----------------");

  if (radio.begin()) {
    Serial.println("NRF24L01 DETECTADO!");
  } else {
    Serial.println("ERRO: NRF24L01 NAO DETECTADO!");
  }
}

void loop() {
  delay(1000);
}

