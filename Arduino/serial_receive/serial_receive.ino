void setup() {
  Serial.begin(9600);
  Serial.println("Ready to receive float array...");
}

void loop() {
  if (Serial.available() >= 1) {
    // スタートバイトの確認
    if (Serial.read() == 0xFF) {
      // 配列の長さを受け取る
      while (Serial.available() < 1);
      uint8_t array_size = Serial.read(); // 受信するfloatの数

      // float配列のデータを受信
      float received_array[array_size];
      uint8_t float_bytes[4];  // floatは4バイト

      for (int i = 0; i < array_size; i++) {
        // floatの4バイトを読み取る
        while (Serial.available() < 4); // 各floatが4バイト
        for (int j = 0; j < 4; j++) {
          float_bytes[j] = Serial.read();
        }
        // 4バイトをfloatに変換して配列に格納
        received_array[i] = *((float*)float_bytes);
      }

      // 受信したfloat配列を表示
      Serial.println("Received float array:");
      for (int i = 0; i < array_size; i++) {
        Serial.println(received_array[i]);
      }
      Serial.write("get!");
    }
  }
}
