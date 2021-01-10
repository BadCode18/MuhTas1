//sağ sensör
int trigPin = 11;
int echoPin = 10;
//sol sensör
int trigPin2 = 12;
int echoPin2 = 13;


// motor 1
int enA = 6;//ok
int in1 = 2;
int in2 = 7;
// motor 2
int enB = 5;//ok
int in3 = 4;
int in4 = 3;

void setup()
{
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

pinMode(2,OUTPUT);
pinMode(7,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);

pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
}

void loop()

{
//yarım saniye delay
do {delay(500);}
while(0);


//sağ——————————————————————-

int duration, distance;
digitalWrite (trigPin, HIGH);
delayMicroseconds (10);
digitalWrite (trigPin, LOW);
duration = pulseIn (echoPin, HIGH);
distance = (duration/2) / 29.1;

//sol——————————————————————

int duration2, distance2;
digitalWrite (trigPin2, HIGH);
delayMicroseconds (10);
digitalWrite (trigPin2, LOW);
duration2 = pulseIn (echoPin2, HIGH);
distance2 = (duration2/2) / 29.1;

//——————————————————————

// Motorlar sabit hızda aynı yöne dönüyorlar.
// 1. motor ileri
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
analogWrite(enA, 100);
// 2.motor ileri
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enB, 100);
delay(200);

if(distance<=50 && distance2<=50)//iki sensörün önünde de engel varsa
{
//motorlar durduruluyor
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

delay(200);//bir üst fonksiyonun çalışma süresi

// motorlar geriye dönüyor
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enA,250);
analogWrite(enB,250);

delay(3000);//bir üst fonksiyonun çalışma süresi

digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
//motorlar normal çalışıyor
analogWrite(enA, 255);
analogWrite(enB, 0);
//motor aynı yere çarpmasın diye döndürüldü
delay(3000);
analogWrite(enB, 255);
//motor normal hızına geri döndü



delay(550);//bir üst fonksiyonun çalışma süresi

}
//—————————————————-
if(distance<=50 && distance2>=50)//sağ sensör
{
//sol motor
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
analogWrite(enA, 0);

//sağ motor
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enB, 255); // sağ motorun hızı arttırıldı

delay(2000);
}

//——————————————————
if(distance2<=50 && distance>=50)//sol sensör
{

//sol motor
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
analogWrite(enA, 255);// sol motorun hızı arttırıldı

//sağ motor
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enB, 0);

delay(2000);
}}
