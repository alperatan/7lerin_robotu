
#define IN1 5  // Sol motor yön 1 ucu
#define IN2 6  // Sol motor yön 2 ucu
#define IN3 9  // Sağ motor yön 1 ucu
#define IN4 10   // Sağ motor yön 2 ucu

int hiz=200;
// ***********************************************
void setup() {
  // ******Pinlerin giriş mi çıkış mı olacağı ayarlanıyor.  ***********
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
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
   ileri(); delay(500);
   dur();   delay(500);
   geri();  delay(500);
   dur();   delay(500);
   saga();  delay(500);
   dur();  delay(500);
   sola(); delay(500);
   dur();  delay(2000);
}
