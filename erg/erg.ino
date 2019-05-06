const int dial = A1;               // potentiometer
const int buzzer = A2;             // passive buzzer 
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;
int dialValue = 0;   
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
 
  //   pinMode(2, OUTPUT);// put your setup code here, to run once:
}

void loop() {
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  dialValue = analogRead(dial);
  Serial.print("Distance: ");
  Serial.println(distance);
  // put your main code here, to run repeatedly:
   if (distance < 50){
    if (dialValue){               // while the dial exists and is giving out some value
      tone(buzzer, dialValue);    // have the buzzer emit sound based on the output the dial gives
      delay(2000);
    }
     else{
      noTone(buzzer);             // when dial value is 0, emit no sound; also if it's outside the analog range 0-1023
    }
   }
   else{
    noTone(buzzer);
   }
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
