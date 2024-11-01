void setup() {
  Serial.begin(9600);
}

void loop() {
  float array[5] = {1.23, 4.56, 7.89, 12.34, 56.78};  // float型の配列を宣言
  
  // スタートバイトを送信
  Serial.write(0xFF);

  // 各float値をバイナリ形式で送信
  for (int i = 0; i < 5; i++) {
    Serial.write((uint8_t*)&array[i], sizeof(float));
  }

  delay(1000);  // 1秒待機
}
