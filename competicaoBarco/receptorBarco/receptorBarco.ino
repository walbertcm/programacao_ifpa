#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// CE = 7, CSN = 8, SPI = 4 MHz
RF24 radio(7, 8);

const byte endereco[6] = "BRC01";

int sensorValue;
float voltagem;

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("MODULO NAO DETECTADO");
    while (1);
  }

  //radio.setChannel(100);
  //radio.setDataRate(RF24_250KBPS);
  //radio.setPALevel(RF24_PA_LOW);

  //radio.disableDynamicPayloads();
  //radio.setPayloadSize(8);

  radio.openReadingPipe(0,endereco);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();

  Serial.println("RECEPTOR PRONTO");
}

void loop() {
if(radio.available()){
//char text[32] = "";
radio.read(&voltagem, sizeof(voltagem));
Serial.println(voltagem);

}
}