#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// CE = 7, CSN = 8, SPI = 4 MHz
RF24 radio(7, 8, 4000000);

const byte endereco[6] = "BRC01";

byte dados[8];

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("MODULO NAO DETECTADO");
    while (1);
  }

  radio.setChannel(100);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.setAutoAck(true);
  radio.disableDynamicPayloads();
  radio.setPayloadSize(8);

  radio.openReadingPipe(1, endereco);
  radio.startListening();

  Serial.println("RECEPTOR PRONTO");
}

void loop() {
  if (radio.available()) {
    memset(dados, 0xAA, sizeof(dados));

    radio.read(dados, sizeof(dados));

    Serial.print("DADOS: ");

    for (int i = 0; i < 8; i++) {
      Serial.print(dados[i]);
      Serial.print(" ");
    }

    Serial.println();
  }
}