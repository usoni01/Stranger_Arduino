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
     

               case 'a': digitalWrite(12, HIGH); break;
               case 'b': digitalWrite(11, HIGH); break;    
              case 'c': digitalWrite(11, HIGH);break;
              case 'd': digitalWrite(10, HIGH);break;
              case 'e': digitalWrite(9, HIGH);break;
              case 'f': digitalWrite(8, HIGH);break;
              case 'g': digitalWrite(7, HIGH);break;
              case 'h': digitalWrite(6, HIGH);break;
              case 'i': digitalWrite(5, HIGH);break;
              case 'j': digitalWrite(4, HIGH);break;
              case 'k': digitalWrite(3, HIGH);break;
             case 'l': digitalWrite(13,HIGH);break;
      //   case 'm': digitalWrite(13,HIGH);break;
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
