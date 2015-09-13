#define trigPin 12
#define echoPin 11
#define ledPin 10

void setup() {
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  //start console communication
  Serial.begin(9600);
}

void loop() {
  long time, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time =pulseIn(echoPin, HIGH);
  //.034029 cm/10^-6 s
  //divide by 2 because the signal comes back to the HC-SR04  
  distance = (.034029*time)/2;
  
  if(distance > 100 || distance <= 0){
    Serial.println("Too large or too small.");
  }
  else{
    Serial.println(distance);
    Serial.print(" cm\n");
    //turn red led on    
    if (distance < 19){
      digitalWrite(ledPin, HIGH);
    }
    else{
      digitalWrite(ledPin, LOW);
    }
  }
  delay(300);
}
