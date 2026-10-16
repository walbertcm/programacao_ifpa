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