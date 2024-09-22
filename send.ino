int rand_num = 0;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);

  randomSeed(analogRead(0));
}

void loop() {
  rand_num = random(65, 90);
  char in_data = rand_num + '\0';

  Serial.println(in_data);
  Serial3.write(in_data);

  delay(64);
}

