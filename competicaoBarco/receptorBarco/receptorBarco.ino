
#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);

const byte endereco[6] = "BARCO";

char mensagem[33];

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("ERRO: NRF24L01!");
    while (true) {}
  }

  radio.setChannel(76);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);

  // Receber mensagens de tamanho variavel
  radio.enableDynamicPayloads();

  radio.openReadingPipe(1, endereco);
  radio.startListening();

  Serial.println("RECEPTOR PRONTO!");
}

void loop() {
  if (radio.available()) {

    uint8_t tamanho = radio.getDynamicPayloadSize();

    if (tamanho > 0 && tamanho <= 32) {

      radio.read(mensagem, tamanho);
      mensagem[tamanho] = '\0';

      Serial.print("Recebido: ");
      Serial.println(mensagem);

    } else {
      radio.flush_rx();
    }
  }
}
