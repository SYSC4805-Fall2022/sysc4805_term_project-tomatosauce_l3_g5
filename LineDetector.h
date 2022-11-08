int Left = 8;
int Middle = 9;
int Right = 10;

void setupLineDetector() {
pinMode(Left, INPUT);
pinMode(Middle, INPUT);
pinMode(Right, INPUT);
Serial.begin(9600);
}

void checkLine(){
  String l;
  String r;
  String m;
  int count = 0;
  int Line_flag =0;
  int L_VAL= digitalRead(Left);  
  int M_VAL= digitalRead(Middle);
  int R_VAL= digitalRead(Right);
  

  if(L_VAL == 0){
    l="W";
  }else{
    l="B";
    count++;
  }
  
    if(R_VAL == 0){
    r="W";
  }else{
    r="B";
    count++;
  }

    if(M_VAL == 0){
    m="W";
  }else{
    m="B";
    count++;
  }

  if(count>1){
    Line_flag = 1;
    Serial.println("On Black line");
  }

  return (int) Line_flag;
  
}