#include <LiquidCrystal.h>   //includi la libreria Liquid Crystal per lo schermo lcd

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   //coordina la libreria con i pin usati nei tuoi collegamenti

const int numRows = 2;
const int numCols = 16;

#define INDIETROpin  6     // Dichiara i pin a cui hai collegato i pulsanti (3 pulsanti = 3 pin)
#define PLAYpin  7
#define AVANTIpin  8


int INDIETROstate = 0; // Dichiara come leggere gli stati delle variabili
int PLAYstate = 0;
int AVANTIstate = 0;


int numRow = 0;

void statocursore() {
  lcd.setCursor(0, numRow);
  lcd.print(">");
  delay(1000);
  lcd.setCursor(0, numRow);
  lcd.print(" ");
  
}

void setup() {
  //configura i pin dei pulsanti come INPUT (3 pulsanti = 3 INPUT)
  pinMode(INDIETROpin, INPUT);   //PIN 6 = Tasto INDIETRO <<
  pinMode(PLAYpin, INPUT);   //PIN 7 = Tasto PLAY 
  pinMode(AVANTIpin, INPUT);   //PIN 8 = Tasto AVANTI >>
  
  lcd.begin(numCols, numRows);
}


void loop() {
  //leggi lo stato del pulsante
  // buttonState = digitalRead(buttonPin);

  PLAYstate = digitalRead(PLAYpin);
  INDIETROstate = digitalRead(INDIETROpin);
  AVANTIstate = digitalRead(AVANTIpin);

  /*switch(AVANTIstate == HIGH){
    case 0:
    delay(100);
    statocursore();
    while(AVANTIstate == HIGH) {}
    break;

    case 1:
    delay(100);
    statocursore();
    while(AVANTIstate == HIGH) {}
    break;

    default: break;
  }*/

  if (AVANTIstate == HIGH) {                  
    delay(100);
    statocursore();
    numRow++;
    while(digitalRead(AVANTIpin) == HIGH) {}
  }
}
  /*if ((AVANTIstate == HIGH)&&(numRow == 1)) {
    delay(100);
    statocursore();
    while(digitalRead(AVANTIpin) == HIGH) {}
  }else{numRow=0;}

}*/
