#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte endereco[6] = "00001";

char mensagem[33];

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("NRF24 nao detectado!");
    while (1);
  }

  radio.openReadingPipe(0, endereco);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(76);
  radio.startListening();

  Serial.println("Receptor pronto!");
}

void loop() {

  if (radio.available()) {

    memset(mensagem, 0, sizeof(mensagem));

    // Lê o payload de 32 bytes
    radio.read(mensagem, 32);

    mensagem[32] = '\0';

    Serial.print("Mensagem recebida: [");
    Serial.print(mensagem);
    Serial.println("]");

    Serial.print("Bytes HEX: ");

    for (int i = 0; i < 32; i++) {
      if ((byte)mensagem[i] < 16) {
        Serial.print("0");
      }
      Serial.print((byte)mensagem[i], HEX);
      Serial.print(" ");
    }

    Serial.println();
  }
}