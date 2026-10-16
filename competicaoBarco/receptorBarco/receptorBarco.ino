#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte endereco[6] = "BRC01";
char mensagem[33];

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("ERRO: NRF24 nao detectado!");
    while (1);
  }

  radio.setChannel(100);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  radio.setPayloadSize(32);
  radio.setAutoAck(true);

  radio.openReadingPipe(1, endereco);
  radio.startListening();

  Serial.println("RECEPTOR PRONTO");
  Serial.println("Aguardando...");
}

void loop() {
  if (radio.available()) {

    memset(mensagem, 0, sizeof(mensagem));

    radio.read(mensagem, 32);
    mensagem[32] = '\0';

    Serial.print("Recebido: [");
    Serial.print(mensagem);
    Serial.println("]");

    Serial.print("HEX: ");

    for (int i = 0; i < 8; i++) {
      byte valor = (byte) mensagem[i];

      if (valor < 16) Serial.print("0");
      Serial.print(valor, HEX);
      Serial.print(" ");
    }

    Serial.println();
  }
}