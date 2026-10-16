
#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte endereco[6] = "BARCO";

char mensagem[32];

void setup() {
  Serial.begin(9600);
  
  if (!radio.begin()) {
    Serial.println("Erro no NRF24L01!");
    while (true) {}
  }

  radio.setChannel(76);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);

  radio.openWritingPipe(endereco);
  radio.stopListening();

  Serial.println("TRANSMISSOR PRONTO");
  Serial.println("Digite uma mensagem:");
}

void loop() {
  if (Serial.available() > 0) {

    size_t tamanho = Serial.readBytesUntil(
      '\n', mensagem, sizeof(mensagem) - 1
    );

    // Remove eventual retorno de carro
    if (tamanho > 0 && mensagem[tamanho - 1] == '\r') {
      tamanho--;
    }

    mensagem[tamanho] = '\0';

    if (tamanho == 0) return;

    bool sucesso = radio.write(
      mensagem, tamanho + 1
    );

    if (sucesso) {
      Serial.print("Enviado: ");
      Serial.println(mensagem);
    } else {
      Serial.println("Falha na transmissao!");
    }

    Serial.println("Digite outra mensagem:");
  }
}

