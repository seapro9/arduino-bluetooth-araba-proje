char komut;
int in1=6;
int in2=7;
int in3=8;
int in4=9;
int ENA=5;
int ENB=11;
int HIZ=140;
int onfar=12;
int arkafar=13;
int korna=2;

void _Ileri() { 
  analogWrite(ENA,HIZ);     analogWrite(ENB,HIZ);    digitalWrite(in1,HIGH);   
  digitalWrite(in2,LOW);    digitalWrite(in3,HIGH);  digitalWrite(in4,LOW);
  Serial.println("go Ileri!");
}
void _Geri() {
  analogWrite(ENA,HIZ);     analogWrite(ENB,HIZ);    digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);   digitalWrite(in3,LOW);   digitalWrite(in4,HIGH);
  Serial.println("go Geri!");
}
void _Sol()  {
  analogWrite(ENA,HIZ);     analogWrite(ENB,HIZ);    digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);    digitalWrite(in3,LOW);   digitalWrite(in4,HIGH);
  Serial.println("go Sol!");
}
void _Sag()  {
  analogWrite(ENA,HIZ);     analogWrite(ENB,HIZ);    digitalWrite(in1,LOW); 
  digitalWrite(in2,HIGH);   digitalWrite(in3,HIGH);  digitalWrite(in4,LOW);
  Serial.println("go Sag!");
}
void _Dur()  {
  digitalWrite(ENA,LOW);   digitalWrite(ENB,LOW); Serial.println("Dur!");
}


void setup()
{ 
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(onfar,OUTPUT);
  pinMode(arkafar,OUTPUT);
  pinMode(korna,OUTPUT);
  _Dur();
}

void loop()
  { 
  komut=Serial.read();

       /// Yönlere göre hareketler ///
  
  if(komut=='f'|| komut=='F')      {  //ileri
        _Ileri();  
       }              
  else if(komut=='b'|| komut=='B') {  //geri
        _Geri(); delay(200);  
       }
  else if(komut=='l'|| komut=='L') {  // sol
        _Sol();  delay(200);   
       }
  else if(komut=='r'|| komut=='R') {  //sağ
        _Sag(); delay(200);   
       }
 else if(komut=='s'|| komut=='S')  {  //dur
        _Dur();              
       }

  
  else if(komut=='i'|| komut=='I') { 
        _Sag();  delay(100);  _Ileri();  // ileri sağ  
       }
  else if(komut=='g'|| komut=='G') {
        _Sol();  delay(100);  _Ileri();  // ileri sol
       }
  else if(komut=='j'|| komut=='J') {
        _Sol();  delay(200);  _Geri();   // geri sol
       }
  else if(komut=='h'|| komut=='H') {
        _Sag();   delay(200);  _Ileri();  // geri sağ
       }
 
        /// Farlar  & korna ////
  else if(komut=='W')   digitalWrite(onfar,HIGH);   // on far yak
                      
  else if(komut=='w')   digitalWrite(onfar,LOW);    // on far söndür
                      
  else if(komut=='U')   digitalWrite(arkafar,HIGH); // arka far yak
                      
  else if(komut=='u')  digitalWrite(arkafar,LOW);  // arka far söndür
                      
  else if(komut=='V')  digitalWrite(korna,HIGH);  // korna çal
  
  else if(komut=='v')  digitalWrite(korna,LOW);   // korna sustur
     
     /// Hız Ayarları ////
  else if(komut=='1')  HIZ=100;
  else if(komut=='2')  HIZ=120;
  else if(komut=='3')  HIZ=140;
  else if(komut=='4')  HIZ=160;
  else if(komut=='5')  HIZ=180;
  else if(komut=='6')  HIZ=200;
  else if(komut=='7')  HIZ=220;
  else if(komut=='8')  HIZ=230;
  else if(komut=='9')  HIZ=240;
  else if(komut=='q')  HIZ=250;
  
  }

