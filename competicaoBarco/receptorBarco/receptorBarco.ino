#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE = 7, CSN = 8

void setup() {
  Serial.begin(9600);

  Serial.println("TESTE NRF24L01");

  if (radio.begin()) {
    Serial.println("NRF24L01 DETECTADO!");
  } else {
    Serial.println("NRF24L01 NAO DETECTADO!");
  }
}

void loop() {
  delay(2000);

  if (radio.isChipConnected()) {
    Serial.println("Modulo conectado");
  } else {
    Serial.println("Modulo desconectado");
  }
}