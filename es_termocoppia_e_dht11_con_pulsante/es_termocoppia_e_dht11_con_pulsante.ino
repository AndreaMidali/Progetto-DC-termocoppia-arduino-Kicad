// this example is public domain. enjoy!
// www.ladyada.net/learn/sensors/thermocouple
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11
#include "max6675.h"
DHT dht(DHTPIN, DHTTYPE);

int ledPin = 7;
int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;
int buttonPin= 9;
int ledState= 0;
int lastState= 0;
//double Temp=0;


MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
//int vccPin = 3;
//int gndPin = 2;

//unsigned long old_millis = 0;
//unsigned long delta = 1000;
//int minuti = 1;
float temp_dht = 0;
float temp_therm = 0;



void setup() {
  Serial.begin(9600);
  Serial.println(F("MILLIS, DHT11, MAX6675"));
  dht.begin();

  //pinMode(vccPin, OUTPUT); digitalWrite(vccPin, HIGH);
 // pinMode(gndPin, OUTPUT); digitalWrite(gndPin, LOW);

  pinMode(ledPin, OUTPUT);
pinMode (buttonPin, INPUT);
  // wait for MAX chip to stabilize
  delay(1000);
  
}

void loop() {
unsigned long now = millis();
int state = digitalRead(buttonPin);

  if(state == HIGH && state != lastState){
  //if (now >= old_millis + delta)

    digitalWrite(ledPin, HIGH);
    temp_dht = dht.readTemperature();
    temp_therm = thermocouple.readCelsius();
   // Serial.print(minuti);
   Serial.print(now/1000);
   Serial.print (", ");
    Serial.print(temp_therm);
    Serial.print (", ");
    Serial.println(temp_dht);
  digitalWrite (ledPin, LOW);
  //  Serial.println(F("°C "));

  //  old_millis = now;
   // minuti = minuti + 1;  
  
  }
    lastState=state;
    if (state== LOW){
    digitalWrite(ledPin, LOW);
    delay(1);
    }
  
  //delay(1);


  //Serial.print(millis());
  //Serial.print(", ");
  //Serial.print("C = ");
  //Serial.println(thermocouple.readCelsius());
  //Serial.print("F = ");
  //Serial.println(thermocouple.readFahrenheit());

  //delay(1000);
}
