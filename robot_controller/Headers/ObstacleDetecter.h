//The max distance is 8cm
int ledPin = 13;
int inPin = 8;
int obs = 0;

void setupObstacleDetecter(){
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  Serial.begin(9600);

}

int checkObstacle(){

  obs = digitalRead(inPin);

  if (obs == HIGH){
    Serial.println("NO obstacle");
    return 0;

  }else{
    Serial.println(" Obstacle");
    return 1
  }

  
}