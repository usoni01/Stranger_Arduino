void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);// put your setup code here, to run once:
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
     // case 'c': digitalWrite(12, HIGH); break;
    //  case 'd': digitalWrite(11, HIGH); break;

      // when a is pressed on the app on your smart phone
              case 'm': digitalWrite(13, HIGH);break; // when d is pressed on the app on your smart phone
              case 'n': digitalWrite(12, HIGH);break;
              case 'o': digitalWrite(11, HIGH);break;
              case 'p': digitalWrite(10, HIGH);break;
              case 'q': digitalWrite(9, HIGH);break;
              case 'r': digitalWrite(8, HIGH);break;
              case 's': digitalWrite(7, HIGH);break;
              case 't': digitalWrite(6, HIGH);break;
              case 'u': digitalWrite(5, HIGH);break;
              case 'v': digitalWrite(4, HIGH);break;
              case 'w': digitalWrite(3,HIGH);break;
              case 'x': digitalWrite(2,HIGH);break;
      // case 'l': digitalWrite(2, HIGH);break;

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
