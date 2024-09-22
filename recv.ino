void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  if(Serial3.available() > 0) {
    char in_data = Serial3.read();
    Serial.println(in_data);
    delay(32);
  }
}

