const int piezo    = 0;
const int redled   = 2;
const int greenled = 4;
const int pulsante = 7;
const int lng      = 6; 
const int lngr     = 5;
const int minp     = 10;
const int maxint   = 1500;
const float  tl    = 0.30;
unsigned int c; 
int diff;
unsigned int valpiezo = 0;
unsigned int t1       = 0;
unsigned int t2       = 0;
unsigned int At       = 0;
unsigned int cc       = 0;
boolean valpul;

float codice[lng]     = {  0,  0,  0,   0,   0,   0};
float origincod[lng]  = {100, 50, 50, 100, 200, 100};
float originrap[lngr] = {0, 0, 0, 0, 0};
float codrap[lngr]    = {0, 0, 0, 0, 0};



void setup()
{
  pinMode(redled, OUTPUT);  
  pinMode(greenled, OUTPUT);
  pinMode(pulsante, INPUT_PULLUP);
  digitalWrite(redled, LOW);
  digitalWrite(greenled, LOW);
  
 //delay (500);
  Serial.begin(9600);
}  
   
   
void loop() 
{
 valpul = false;
 ascolto();
 if (valpul == false)
  confronto();
}

void ascolto()
{
  delay(1500);
  
  c=0;
  while(c<6)
  {
    valpul = (digitalRead(pulsante) == LOW);
   
    t1=t2;
    
    do
    {
      valpiezo = analogRead(piezo);
      t2 = millis();
    } while (valpiezo < minp);
    delay (50);
    At = t2-t1;    
    
    
    if (At < maxint)                 //esclude il valore primo e sballato
    {
      if(valpul == false)
      {
        codice[c] = At;
        Serial.println(codice[c]);
      }else if(valpul == true)
      {
        origincod[c] =At;
        Serial.println(origincod[c]);
      }
      
      c++;
     
    } else 
       c = 0;
   
  }
  /*for(c=0; c<6; c++)
   Serial.println(codice[c]);*/
}


void confronto()
{
  
   for (c = 0; c < 5; c++ )                              //genera l'array con i rapporti tra i  valori di origincod
  {
    originrap[c] = (origincod[c] / origincod[c + 1]);
    Serial.println(originrap[c]);
  }
  for (c = 0; c < 5; c++)            //WTF?!?!?  genera l'array con i rapporti fra i valori registrati
  {
    codrap[c] = (codice[c] / codice[c+1]);
    Serial.println(codrap[c]);    
  } 
  
  cc = 0;
  
  for(c = 0; c <= 4; c++)                   //confronto
  {
    if((codrap[c] <= originrap[c] + tl) && (codrap[c] >= originrap[c] - tl))
    {
      Serial.println("OK");
      cc++;
    } else
    Serial.println("KO"); 
  }
  
  Serial.println(cc);
  
  if(cc == 5)
  {
    Serial.println("hai vinto");
  }
}
  
 
