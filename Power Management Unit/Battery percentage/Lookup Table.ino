int readPin=A3;
int blueLight=10;
int GreenLight=12;
int RedLight=14;
int readVal;
float V2=0;
int delayTime=1000;
int percentage;
void setup() {
  // put your setup code here, to run once:
pinMode(readPin,INPUT); 
pinMode(blueLight,OUTPUT)
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
readVal=analogRead(readPin);
V2=(5./1023.)*readval;
delay(delayTime);
if(5>v2>4.92){
  percentage=90%;
  Serial.println(percentage);
  digitalWrite(blueLight,HIGH);
}
if(4,92>v2>4.88){
  percentage=80%;
  Serial.println(percentage);
  digitalWrite(blueLight,HIGH);
}
if(4,88>v2>4.85){
  percentage=70%;
  Serial.println(percentage);
  digitalWrite(GlueLight,HIGH);
}
if(4,85>v2>4.8){
  percentage=60%;
  Serial.println(percentage);
  digitalWrite(GreenLight,HIGH);
}
if(4,8>v2>4.74){
  percentage=50%;
  Serial.println(percentage);
  digitalWrite(GreenLight,HIGH);
}
if(4,74>v2>4.68){
  percentage=40%;
  Serial.println(percentage);
  digitalWrite(GreenLight,HIGH);
}
if(4,68>v2>4.64){
  percentage=30%;
  Serial.println(percentage);
  digitalWrite(GreenLight,HIGH);
}
if(4,64>v2>4.55){
  percentage=20%;
  Serial.println(percentage);
  digitalWrite(RedLight,HIGH);
}
if(4,55>v2>4.45){
  percentage=10%;
  Serial.println(percentage);
  digitalWrite(RedLight,HIGH);
}
if(4,45>v2>4.13){
  percentage=00%;
  Serial.println(percentage);
  digitalWrite(RedLight,HIGH);
}
}
