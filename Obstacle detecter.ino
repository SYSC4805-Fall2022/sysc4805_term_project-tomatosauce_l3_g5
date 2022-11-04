//The max distance is 8cm
int ledPin = 13;
int inPin = 8;
int obs = 0;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  Serial.begin(9600);

}

void loop(){

  obs = digitalRead(inPin);

  if (obs == HIGH){
    Serial.println("NO obstacle");

  }else{
    Serial.println(" Obstacle");
  }

  delay(2000);

}