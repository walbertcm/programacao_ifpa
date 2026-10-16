
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

  radio.openReadingPipe(1, endereco);
  radio.startListening();

  Serial.println("RECEPTOR PRONTO");
  Serial.println("Aguardando mensagens...");
}

void loop() {
  if (radio.available()) {

    uint8_t tamanho = radio.getDynamicPayloadSize();

    // Aqui usamos tamanho fixo por padrao
    // Portanto lemos o payload configurado
    // pelo transmissor.
    (void)tamanho;

    radio.read(mensagem, sizeof(mensagem));
    mensagem[31] = '\0';

    Serial.print("Recebido: ");
    Serial.println(mensagem);
  }
}
