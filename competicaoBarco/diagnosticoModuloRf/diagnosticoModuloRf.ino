
#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);

void setup() {
  Serial.begin(9600);

  // Mantem o Arduino Uno como mestre SPI
  pinMode(10, OUTPUT);
  digitalWrite(10, HIGH);

  Serial.println("=== DIAGNOSTICO NRF24L01 ===");

  bool iniciado = radio.begin();

  Serial.print("radio.begin(): ");
  Serial.println(iniciado ? "OK" : "FALHOU");

  Serial.print("Chip conectado: ");
  Serial.println(
    radio.isChipConnected() ? "SIM" : "NAO"
  );

  if (iniciado) {
    radio.printDetails();
  }
}

void loop() {
}

