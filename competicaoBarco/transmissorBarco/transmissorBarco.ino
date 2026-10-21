#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte endereco[6] = "BRG01";

const int pinoLeme = A0;
const int pinoBotao = 2;

// Estrutura que será enviada
struct Dados {
  int leme;
  byte acelerador;
};

Dados dados;

void setup() {

  //Serial.begin(9600);

  pinMode(pinoBotao, INPUT_PULLUP);

  if (!radio.begin()) {
    //Serial.println("RADIO NAO DETECTADO");
    //while (1);
  }

  radio.setPALevel(RF24_PA_MIN);
  radio.setChannel(108);
  radio.openWritingPipe(endereco);

  radio.stopListening();

  //Serial.println("TRANSMISSOR PRONTO");
}

void loop() {

  // Lê potenciômetro
  dados.leme = analogRead(pinoLeme);

  dados.acelerador = (digitalRead(pinoBotao) == LOW) ? 1 : 0;

  bool enviado = radio.write(&dados, sizeof(dados));

  //Serial.print("LEME: ");
  //Serial.print(dados.leme);

  //Serial.print(" | ACELERADOR: ");
  //Serial.print(dados.acelerador);

  //Serial.println(
  //    enviado ? " | ACK" : " | FALHA"
  //);

  delay(50);
}