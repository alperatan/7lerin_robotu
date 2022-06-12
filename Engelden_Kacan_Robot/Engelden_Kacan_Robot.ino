#define echoPin 12 //Ultrasonik sensörün echo pini Arduino'nun 12.pinine
#define trigPin 13 //Ultrasonik sensörün trig pini Arduino'nun 13.pinine tanımlandı.
#define R2 9
#define R1 10 // Motor pinlerini tanımlıyoruz.
#define L2 5
#define L1 6

int rndm;

void setup() {
 
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);

  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  int olcum = mesafe();
  if(olcum < 27){
    dur();
    delay(500);
    while(olcum < 21)
    {
      geri();
      olcum = mesafe();
    }
    rndm = random(2);
    if(rndm == 0)
    {
      sag();
    }
    if(rndm == 1)
    {
      sol();
    }
    delay(500);
  }
  else {
    ileri();
  }
}



void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.
  analogWrite(L1, 230);
  analogWrite(L2, 0);
  analogWrite(R1, 230);
  analogWrite(R2, 0);
}


void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
  analogWrite(L1, 255);
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 255);
  delay(200);
  analogWrite(L1, 0);
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 0);
}


void geri(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.
  analogWrite(L1, 0);
  analogWrite(L2, 255);
  analogWrite(R1, 0);
  analogWrite(R2, 255);
}

void dur(){
  analogWrite(L1, 0);
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 0);
}
void sol(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.
  analogWrite(L1, 0);
  analogWrite(L2, 255);
  analogWrite(R1, 255);
  analogWrite(R2, 0);
  delay(150);
  analogWrite(L1, 0);
  analogWrite(L2, 0);
  analogWrite(R1, 0);
  analogWrite(R2, 0);
}

int mesafe()
{
  long duration, distance;
  
  digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);

  duration = pulseIn(echoPin, 1);
  distance = duration / 58.2;
  delay(50);
  
  return distance;

}
