//Rayen Lahmar
const int moteur_left = 2;
const int moteur_right = 3;


const int enA= 4;
const int enB= 9;

const int capteur_leftleft = A1;
const int capteur_left= A2;
const int capteur_center= A3;
const int capteur_right= A4;
const int capteur_rightright= A5;

const int ult_trig =A1;
const int ult_echo = A2;

bool etatcapteur_leftleft ;
bool etatcapteur_left;
bool etatcapteur_center;
bool etatcapteur_right;
bool etatcapteur_rightright;


void setup() {

  Serial.begin(9600);
  pinMode(capteur_leftleft,INPUT);
  pinMode(capteur_left,INPUT);
  pinMode(capteur_center,INPUT);
  pinMode(capteur_right,INPUT);
  pinMode(capteur_rightright,INPUT);

  pinMode(moteur_left,OUTPUT);
  pinMode(moteur_right,OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  
  pinMode(ult_trig,INPUT);
  pinMode(ult_echo,INPUT);
 }



void loop() {
 int i,j,k,l,m,n;
 
 etatcapteur_leftleft= digitalRead(capteur_leftleft);
 etatcapteur_left= digitalRead(capteur_left);
 etatcapteur_center= digitalRead(capteur_center);
 etatcapteur_right= digitalRead(capteur_right);
 etatcapteur_rightright= digitalRead(capteur_rightright);
//center is black ray
 if (capteur_rightright){
   
   if(((!etatcapteur_leftleft) && (!etatcapteur_left)) && ((!etatcapteur_right )&& (!etatcapteur_rightright ))){  
        forword();}
   
   else if (((!etatcapteur_leftleft)&&(!etatcapteur_left))&&((etatcapteur_right)&&(!etatcapteur_rightright))) {
      turn_right();}

    else if (((!etatcapteur_leftleft)&&(etatcapteur_left))&&((!etatcapteur_right)&&(!etatcapteur_rightright))) {turn_left(); 
    }

    else if (((!etatcapteur_leftleft)&&(!etatcapteur_left))&&((etatcapteur_right)&&(etatcapteur_rightright))) { 
      turn_rightright();}

    else if (((etatcapteur_leftleft)&&(etatcapteur_left))&&((!etatcapteur_right)&&(!etatcapteur_rightright))) { }
      else { move_back();}
 }
//capteur is white ray
 if (!capteur_rightright){
   if(((etatcapteur_leftleft)&&(etatcapteur_left))&&((etatcapteur_right)&&(etatcapteur_rightright))){  
       forword();}
   
   else if (((etatcapteur_leftleft)&&(etatcapteur_left))&&((!etatcapteur_right)&&(etatcapteur_rightright))) {
      turn_right();}

    else if (((etatcapteur_leftleft)&&(!etatcapteur_left))&&((etatcapteur_right)&&(etatcapteur_rightright))) {turn_left(); 
    }

    else if (((etatcapteur_leftleft)&&(etatcapteur_left))&&((!etatcapteur_right)&&(!etatcapteur_rightright))) { 
      turn_rightright();}

    else if (((!etatcapteur_leftleft)&&(!etatcapteur_left))&&((etatcapteur_right)&&(etatcapteur_rightright))) {  turn_leftleft();}
      else { move_back();}}

// if found obstacle stop



    

    
 
}
void forword(){
   analogWrite(enA,0); analogWrite(enB,0);
       delay(100);
       Serial.print("move forword");
       digitalWrite(in1,HIGH);digitalWrite(in4,HIGH);
       digitalWrite(in2,LOW); digitalWrite(in3,LOW);
       }
void  turn_right(){
  analogWrite(enA,0); analogWrite(enB,250);
       delay(100);
      Serial.print("turn silghtly to the right");
      digitalWrite(in1,HIGH);digitalWrite(in4,HIGH);
       digitalWrite(in2,LOW); digitalWrite(in3,LOW);
}
void turn_left(){
  analogWrite(enA,250); analogWrite(enB,0);
       delay(100);
     Serial.print("turn silghtly to the left");
      digitalWrite(in1,LOW);digitalWrite(in4,LOW);
       digitalWrite(in2,HIGH); digitalWrite(in3,HIGH);
}
void turn_rightright(){
analogWrite(enA,250); analogWrite(enB,0);
       delay(100);
     Serial.print("make a right turn");
      digitalWrite(in1,LOW);digitalWrite(in4,LOW);
       digitalWrite(in2,HIGH); digitalWrite(in3,HIGH);}

void turn_leftleft(){
  analogWrite(enA,250); analogWrite(enB,0);
  delay(100);
     Serial.print("turn silghtly to the left");
      digitalWrite(in1,LOW);digitalWrite(in4,LOW);
       digitalWrite(in2,HIGH); digitalWrite(in3,HIGH);   }

 void move_back(){
  analogWrite(enA,250); analogWrite(enB,250);
  delay(100);
     Serial.print("turn silghtly to the left");
      digitalWrite(in1,LOW);digitalWrite(in4,LOW);
       digitalWrite(in2,HIGH); digitalWrite(in3,HIGH);
     
 }
 void STOP(){
  digitalWrite(in1,LOW);digitalWrite(in4,LOW);
       digitalWrite(in2,LOW); digitalWrite(in3,LOW);
       delay(5000);
}
