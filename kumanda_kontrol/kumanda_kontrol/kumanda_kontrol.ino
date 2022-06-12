#include <IRremote.h>
#define eksi A3
#define arti A4
//#define data A5

int RECV_PIN = A5;
IRrecv irrecv(RECV_PIN);
decode_results results;

#define IN1 5  // Sol motor yön 1 ucu
#define IN2 6  // Sol motor yön 2 ucu
#define IN3 9  // Sağ motor yön 1 ucu
#define IN4 10   // Sağ motor yön 2 ucu
 
#define IR 8 // IR göz

// ******* kumanda kodları  *******************
#define ileri_tus 0x3D9AE3F7  //0xFF18E7
#define OK_tus    0xDBC8CB72   // 0xFF38C7
#define geri_tus  0x1BC0157B  //0xFF4AB5
#define sag_tus   0x449E79F  //0xFF5AA5
#define sol_tus   0x8C22657B  //0xFF10EF

#define yildiz_tus 0xFF6897
#define kare_tus 0xFFB04F


int hiz=200;
// ***********************************************
void setup() {
  // ******Pinlerin giriş mi çıkış mı olacağı ayarlanıyor.  ***********
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(arti,OUTPUT);
  pinMode(eksi,OUTPUT);
 // pinMode(data,INPUT);
  Serial.begin(9600);

  irrecv.enableIRIn();
  digitalWrite(arti,1);
  digitalWrite(eksi,0);
}

 //-----------------------------------
void ileri(){
  analogWrite (IN1,hiz);  
  analogWrite (IN2,0);    
  analogWrite (IN3,hiz);  
  analogWrite (IN4,0); 
}
void geri(){
  analogWrite (IN1,0);  
  analogWrite (IN2,hiz);    
  analogWrite (IN3,0);  
  analogWrite (IN4,hiz);  
}

void sola(){
  analogWrite (IN1,0);  
  analogWrite (IN2,hiz);    
  analogWrite (IN3,hiz);  
  analogWrite (IN4,0);
}

void saga(){
  analogWrite (IN1,hiz);  
  analogWrite (IN2,0);    
  analogWrite (IN3,0);  
  analogWrite (IN4,hiz);
}

void dur() {  
  analogWrite (IN1,0);  
  analogWrite (IN2,0);    
  analogWrite (IN3,0);  
  analogWrite (IN4,0);
}
//***************************************
void loop() {
   if (irrecv.decode(&results))
  {    
    //Serial.println(results.value, HEX); // bu satır ile bilgisayarımızda gelen kodları görüyoruz
//-------------------------------------    
    if (results.value == ileri_tus)
    {
      ileri();     
    } 
//-------------------------------------    
if (results.value == geri_tus)
    {
      geri();     
    } 
//-------------------------------------
if (results.value == sol_tus)
    {
      sola();     
    } 
//------------------------------------- 
if (results.value == sag_tus)
    {
      saga();     
    } 
//-------------------------------------    
if (results.value == OK_tus)
    {
      dur(); 
    }
//-------------------------------------          
    if (results.value == yildiz_tus) // yıldız tuşuna her basışta motor hızı 5 artacak
    {
      hiz=hiz+5;
      if(hiz>255) hiz=255;    
    } 
    if (results.value == kare_tus)  // kare tuşuna her basışta motor hızı 5 azalacak
    {
      hiz=hiz-5;
      if(hiz<10) hiz=10;    
    } 
    irrecv.resume();
  }
}
