#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte endereco[6] = "BRC01";
char mensagem[9];

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("NRF24 NAO DETECTADO");
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

    memset(mensagem, 0xAA, sizeof(mensagem));

    radio.read(mensagem, 8);
    mensagem[8] = '\0';

    Serial.print("HEX: ");

    for (int i = 0; i < 8; i++) {
      if ((uint8_t)mensagem[i] < 16) {
        Serial.print("0");
      }

      Serial.print((uint8_t)mensagem[i], HEX);
      Serial.print(" ");
    }

    Serial.println();

    Serial.print("TEXTO: [");
    Serial.print(mensagem);
    Serial.println("]");
  }
}