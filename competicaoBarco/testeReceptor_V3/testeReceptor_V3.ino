#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);  // CE = 7, CSN = 8

const byte endereco[6] = "BARCO";

char mensagem[33];

void setup() {
  Serial.begin(9600);
  delay(1000);

  Serial.println("INICIANDO RECEPTOR");

  if (!radio.begin()) {
    Serial.println("ERRO: NRF24L01 nao detectado!");
    while (1);
  }

  Serial.println("NRF24L01 detectado!");

  radio.setChannel(76);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);

  radio.enableDynamicPayloads();
  radio.openReadingPipe(1, endereco);
  radio.startListening();

  Serial.println("RECEPTOR PRONTO");
}

void loop() {

  static unsigned long ultimoTeste = 0;

  // Verifica o SPI a cada 2 segundos
  if (millis() - ultimoTeste >= 2000) {

    ultimoTeste = millis();

    if (radio.isChipConnected()) {
      Serial.println("[SPI] OK");
    } else {
      Serial.println("[SPI] FALHA");
    }
  }

  // Recebe mensagens
  if (radio.available()) {

    uint8_t tamanho = radio.getDynamicPayloadSize();

    if (tamanho > 0 && tamanho <= 32) {

      char mensagem[33];

      radio.read(mensagem, tamanho);

      mensagem[tamanho] = '\0';

      Serial.print("[RX] ");
      Serial.println(mensagem);

    } else {
      radio.flush_rx();
      Serial.println("[RX] Pacote invalido");
    }
  }
}