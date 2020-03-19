#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ThingSpeak.h>

unsigned long ChannelID = 1022929;
const char * WriteAPI = "2UGX3K4Q02325PHE";
const char * ReadAPI = "89T31L9N28QJ6I92";
const char* ssid = "Crystal Rock 11";
const char* pass = "Ambrish11";

WiFiClient client;

int led1 = 16;
int led2 = 5;
int led3 = 4;
int led4 = 12;
int ldr = A0;

void setup() 
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(ldr,INPUT);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  Serial.begin(115200);
  WiFi.begin(ssid,pass);
  Serial.print("Connecting to WiFi: ");
  Serial.print(ssid);
  ThingSpeak.begin(client);
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi Connected");
}

void loop() 
{
  int ldr_value = analogRead(ldr);
  float voltage = (ldr_value*5.0)/1024.0; 
  Serial.print("LDR Value = ");
  Serial.println(ldr_value);
  Serial.print("Voltage = ");
  Serial.println(voltage);
  if(ldr_value<500)
  {
    Serial.println("Low Light detected... Turning Lights ON");
    digitalWrite(led1,HIGH);
    Serial.println("LED 1 ON");
    digitalWrite(led2,HIGH);
    Serial.println("LED 2 ON");
    digitalWrite(led3,HIGH);
    Serial.println("LED 3 ON");
    digitalWrite(led4,HIGH);
    Serial.println("LED 4 ON"); 
  }
  else
  {
    digitalWrite(led1,LOW);
    Serial.println("LED 1 OFF");
    digitalWrite(led2,LOW);
    Serial.println("LED 2 OFF");
    digitalWrite(led3,LOW);
    Serial.println("LED 3 OFF");
    digitalWrite(led4,LOW);
    Serial.println("LED 4 OFF");
  }
  ThingSpeak.writeField(ChannelID, 1,ldr_value, WriteAPI);
  ThingSpeak.writeField(ChannelID, 2,voltage, WriteAPI);
  ThingSpeak.writeField(ChannelID, 3,led1, WriteAPI);
  ThingSpeak.writeField(ChannelID, 4,led2, WriteAPI);
  ThingSpeak.writeField(ChannelID, 5,led3, WriteAPI);
  ThingSpeak.writeField(ChannelID, 6,led4, WriteAPI);
}
