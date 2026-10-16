
#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte endereco[6] = "BARCO";

char mensagem[33];

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("NRF24 NAO DETECTADO");
    while (1);
  }

  radio.setChannel(76);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);

  radio.setPayloadSize(32);

  radio.openReadingPipe(1, endereco);
  radio.startListening();

  Serial.println("RECEPTOR PRONTO");
}

void loop() {

  if (radio.available()) {

    memset(mensagem, 0, sizeof(mensagem));

    radio.read(mensagem, 32);

    mensagem[32] = '\0';

    if (mensagem[0] != '\0') {

      Serial.print("RECEBIDO: ");
      Serial.println(mensagem);
    }
  }
}