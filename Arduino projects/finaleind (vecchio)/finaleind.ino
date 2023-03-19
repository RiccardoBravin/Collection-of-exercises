#include <Servo.h>

Servo Myservo;

const int piezo   = 0;
const int redled  = 2;
const int led1    = 3;
const int led2    = 4;
const int led3    = 5;
const int led4    = 6;
const int led5    = 7;
const int led6    = 8;
const int led7    = 9;
const int ledgiallo= 10;
const int pulsante=12;
const int lng    = 6;
const int lngr   = 5;
const int minp   = 30;
const int maxint = 1500;
const float tl   = 0.50;

unsigned int c;
unsigned int k;
unsigned int valpiezo = 0;
unsigned int t1       = 0;
unsigned int t2       = 0;
unsigned int At       = 0;
unsigned int cc       = 0;

int diff;
boolean valpul;
boolean codicevalido;

float codice[lng]     = {  0,  0,  0,   0,   0,   0};
float origincod[lng]  = {100, 50, 50, 100, 200, 100};
float originrap[lngr] = {0, 0, 0, 0, 0};
float codrap[lngr]    = {0, 0, 0, 0, 0};


void setup(){
  Myservo.attach(11) ;
  pinMode(redled, OUTPUT);
  pinMode(led1,   OUTPUT);
  pinMode(led2,   OUTPUT);
  pinMode(led3,   OUTPUT);
  pinMode(led4,   OUTPUT);
  pinMode(led5,   OUTPUT);
  pinMode(led6,   OUTPUT);
  pinMode(led7,   OUTPUT);
  pinMode(ledgiallo, OUTPUT);
  pinMode(pulsante, INPUT_PULLUP);
  Serial.begin(9600);
  Myservo.write(150);
  
  //andirivieni dei led iniziale
  /*for(k=2; k<10; k++)
    digitalWrite(k, LOW);*/
  for(k=3; k<11; k++)
  {
    digitalWrite(k, HIGH);
    delay(100);
    digitalWrite(k, LOW);
  }
    for(k=8; k>2; k--)
  {
    digitalWrite(k, HIGH);
    delay(100);
    digitalWrite(k, LOW);
  }
  //delay(500);
}

void loop(){
  Myservo.write(150);
  delay(100);
  valpul = false;
  ascolto();
  
  if (valpul ==false)
    confronto();
  
}
  
  
void ascolto()
{
  for(k=3; k<10; k++)
    digitalWrite(k, LOW);
  digitalWrite(ledgiallo, LOW);
  delay(1500);                        //controlla funzioni il led giallo
  digitalWrite(ledgiallo, HIGH);
  
  c = 0;
  while(c < lng){
    if(digitalRead(pulsante) == LOW){
      valpul = true;
      digitalWrite(redled, HIGH);
    }
      else
      valpul = false;
      
    t1 = t2;
    do{
      valpiezo = analogRead(piezo);
      t2 = millis();
    } while (valpiezo < minp);
    digitalWrite(led1, HIGH); //lampeggia perchè è fuori dall'if. dove metterlo?
    delay (50);
    At = t2 - t1;
    
    if(At < maxint){
      if(valpul == false){
        codice[c] = At;
        digitalWrite(c+4, HIGH);
        Serial.println(codice[c]);
      } else if(valpul == true){
        origincod[c] = At;
        digitalWrite(c+4, HIGH);
        Serial.println(origincod[c]);
      }
      c++;
    } else{
      c = 0;
       for(k=3; k<10; k++)
       digitalWrite(k, LOW);
    }
      
  }
}


void confronto(){
  for (c=0; c<lngr; c++){
    originrap[c] = (origincod[c]/origincod[c+1]);
    Serial.println(originrap[c]);
  }
  
  for (c=0; c<lngr; c++){
   codrap[c] = (codice[c]/codice[c+1]);
  Serial.println(codrap[c]);
  }
 
  cc = 0;

  for (c=0; c<lngr; c++){
    if((codrap[c] <= originrap[c] + tl) && (codrap[c] >= originrap[c] - tl)){
      cc++;
      Serial.println("OK");
    } else Serial.println("KO");
  }
  
  if (cc == 5){
    codicevalido = true;
    for(k=3; k<10; k++){
      digitalWrite(k, HIGH);
      delay(100);
      digitalWrite(k, LOW);
    }
    for(k=8; k>2; k--){
      digitalWrite(k, HIGH);
      delay(100);
      digitalWrite(k, LOW);
    }
    Serial.println("porta in apertura");
    delay(15);
    Myservo.write(60);
    delay(1000);
  } else {
    codicevalido = false;
    delay(500);
    for(k=3; k<10; k++)
      digitalWrite(k, LOW);
    for(k=0; k<3; k++){
      digitalWrite(redled, HIGH);
      delay(300);
      digitalWrite(redled, LOW);
      delay(300);
    }    
    Serial.println("codice errato"); 
  }
}
  


    



  
    

  
  
  

  
  
  
  
    
    
          



