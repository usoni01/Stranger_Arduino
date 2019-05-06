void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
 
  //   pinMode(2, OUTPUT);// put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    char data = Serial.read(); // reading the data received from the bluetooth module
    for (int i = 3 ; i <= 13; i++) {
      digitalWrite(i, LOW);
    }
    delay(200);
    switch (data)
    {
      case 'y': digitalWrite(13, HIGH); break;
      case 'z': digitalWrite(12, HIGH); break;

     
      default : break;
    }
    Serial.println(data);
    delay(700);
  }

  delay(50);
  for (int i = 3; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
  //  exit(0);
}
