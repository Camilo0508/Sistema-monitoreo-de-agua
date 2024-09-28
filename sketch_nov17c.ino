
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>

int TRIG = 10;
int ECHO = 9;
int TimeOn; // Tiempo en estado alto señal ultrasonido
int Nivel;  // Determina la distacia segun la velocidad del sonido y la duracion TimeOn
int DinTira = 7;  //Pin digital de entrada tira led
int LEDs = 7;    // Número de LEDs de la tira led

Adafruit_NeoPixel tira = Adafruit_NeoPixel(LEDs,DinTira, NEO_GRB + NEO_KHZ800);
LiquidCrystal_I2C lcd (0x27,2,1,0,4,5,6,7); //Direccion, E, RW, RS, D4, D5, D6, D7

void setup()
{
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.begin(16,2);
  lcd.clear();
  
  tira.begin();
  tira.show();
  
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);

  Serial.begin(9600);
  
  lcd.setCursor(0,0);
  lcd.setCursor(0,1);
  lcd.print("Bievenido");
  delay(2000);
  lcd.clear();
}

void loop()
{
  tira.setBrightness(100); //0-255  Brillo general de la Tira LED
  
  digitalWrite (TRIG,HIGH);
  delay(1);
  digitalWrite (TRIG,LOW);
  
  TimeOn= pulseIn(ECHO,HIGH);
  Nivel=TimeOn/58.2;    //Nivel en CM
  Serial.println(Nivel);

  lcd.setCursor(0,0);
  lcd.print("Nivel:");
  lcd.setCursor(7,0);
  lcd.print(Nivel);
  lcd.setCursor(11,0);
  lcd.print("CM");
  //delay(1000);
  
  if  (Nivel>=20 ) {
       lcd.setCursor(0,1);
       lcd.print(" NIVEL BAJO!");
     }
  if  (Nivel<20 && Nivel>=10) {
       lcd.setCursor(0,1);
       lcd.print(" NIVEL MEDIO!");
     }
    if  (Nivel<10) {
       lcd.setCursor(0,1);
       lcd.print(" NIVEL ALTO!");
        digitalWrite(LEDs, LOW);
        tone(12,523, 100);
        tone(12,450, 100);
           
     }
}
 /*if  (Nivel>=26 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     }
 if  (Nivel>=25 && Nivel<26 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);   // LED, R , G, B
     }
 if  (Nivel>=24 && Nivel<25 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);   // LED, R , G, B
     }
 if  (Nivel>=23 && Nivel<24 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);   // LED, R , G, B
     tira.setPixelColor(2,255,64,0);   // LED, R , G, B
     }
 if  (Nivel>=22 && Nivel<23 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     }
 if  (Nivel>=20 && Nivel<22 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     } 
 if  (Nivel>=18 && Nivel<20 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     } 
 if  (Nivel>=17 && Nivel<18 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     } 
 if  (Nivel>=15 && Nivel<17 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     } 
 if  (Nivel>=13 && Nivel<15 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     tira.setPixelColor(8,244,255,0); // LED, R , G, B
     } 

 if  (Nivel>=12 && Nivel<13 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     tira.setPixelColor(8,244,255,0); // LED, R , G, B
     tira.setPixelColor(9,212,255,0); // LED, R , G, B
     } 
 if  (Nivel>=10 && Nivel<12 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     tira.setPixelColor(8,244,255,0); // LED, R , G, B
     tira.setPixelColor(9,212,255,0); // LED, R , G, B
     tira.setPixelColor(10,171,255,0);// LED, R , G, B
     } 
 if  (Nivel>=8 && Nivel<10 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     tira.setPixelColor(8,244,255,0); // LED, R , G, B
     tira.setPixelColor(9,212,255,0); // LED, R , G, B
     tira.setPixelColor(10,171,255,0);// LED, R , G, B
     tira.setPixelColor(11,144,255,0);// LED, R , G, B
     } 
 if  (Nivel>=6 && Nivel<8 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     tira.setPixelColor(8,244,255,0); // LED, R , G, B
     tira.setPixelColor(9,212,255,0); // LED, R , G, B
     tira.setPixelColor(10,171,255,0);// LED, R , G, B
     tira.setPixelColor(11,144,255,0);// LED, R , G, B
     tira.setPixelColor(12,111,255,0);// LED, R , G, B
     } 
 if  (Nivel>=5 && Nivel<6 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     tira.setPixelColor(8,244,255,0); // LED, R , G, B
     tira.setPixelColor(9,212,255,0); // LED, R , G, B
     tira.setPixelColor(10,171,255,0);// LED, R , G, B
     tira.setPixelColor(11,144,255,0);// LED, R , G, B
     tira.setPixelColor(12,111,255,0);// LED, R , G, B
     tira.setPixelColor(13,75,255,0); // LED, R , G, B
     } 
 if  (Nivel>3 && Nivel<5 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     tira.setPixelColor(8,244,255,0); // LED, R , G, B
     tira.setPixelColor(9,212,255,0); // LED, R , G, B
     tira.setPixelColor(10,171,255,0);// LED, R , G, B
     tira.setPixelColor(11,144,255,0);// LED, R , G, B
     tira.setPixelColor(12,111,255,0);// LED, R , G, B
     tira.setPixelColor(13,75,255,0); // LED, R , G, B
     tira.setPixelColor(14,47,255,0); // LED, R , G, B
     } 
 if  (Nivel<=3 ) {
     tira.setPixelColor(0,255,0,0);   // LED, R , G, B
     tira.setPixelColor(1,255,32,0);  // LED, R , G, B
     tira.setPixelColor(2,255,64,0);  // LED, R , G, B
     tira.setPixelColor(3,255,96,0);  // LED, R , G, B
     tira.setPixelColor(4,255,124,0); // LED, R , G, B
     tira.setPixelColor(5,255,160,0); // LED, R , G, B
     tira.setPixelColor(6,255,197,0); // LED, R , G, B
     tira.setPixelColor(7,255,234,0); // LED, R , G, B
     tira.setPixelColor(8,244,255,0); // LED, R , G, B
     tira.setPixelColor(9,212,255,0); // LED, R , G, B
     tira.setPixelColor(10,171,255,0);// LED, R , G, B
     tira.setPixelColor(11,144,255,0);// LED, R , G, B
     tira.setPixelColor(12,111,255,0);// LED, R , G, B
     tira.setPixelColor(13,75,255,0); // LED, R , G, B
     tira.setPixelColor(14,47,255,0); // LED, R , G, B
     tira.setPixelColor(15,0,255,0);  // LED, R , G, B
     }




     tira.show();
     delay(500);
     tira.clear();
     
     lcd.setCursor(7,0);
     lcd.print("    "); // Para borrar los datos que se actualizan y evitar el parpadeo de la pantalla.
     lcd.setCursor(12,1); 
     lcd.print(" ");
     //lcd.clear();
     //tira.show();
     //delay(200);
     
}*/