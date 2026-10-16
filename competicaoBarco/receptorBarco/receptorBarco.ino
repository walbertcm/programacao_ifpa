
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE = 7, CSN = 8

const byte endereco[6] = "00001";

char mensagem[32];

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("NRF24L01 nao detectado!");
    while (1);
  }

  radio.openReadingPipe(0, endereco);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

  Serial.println("Receptor pronto!");
  Serial.println("Aguardando mensagens...");
}

void loop() {

  if (radio.available()) {

    memset(mensagem, 0, sizeof(mensagem));

    radio.read(mensagem, sizeof(mensagem));

    mensagem[31] = '\0';

    Serial.print("Mensagem recebida: ");
    Serial.println(mensagem);
  }
}