#include <SPI.h>
#include <LoRa.h>
#include<KRrtc.h>
#include<Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_ADS1X15.h>
#include <GravityTDS.h>
#include <Servo.h> //library servo
#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Galaxy A32";
const char* password = "11111111";

// Konfigurasi MQTT
const char* mqttServer = "192.168.237.166";
const int mqttPort = 1883;
const char* mqttTopic1 = "mqtt/pompa";
const char* mqttTopic2 = "mqtt/aerator";

WiFiClient espClient;
PubSubClient client(espClient);
//define the pins used by the LoRa transceiver module
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
#define RST 14
#define DIO0 26

//433E6 for Asia
//866E6 for Europe
//915E6 for North America
#define BAND 915E6
int counter = 0;
String LoRaMessage = "";
int readingID = 0;


#define ONE_WIRE_BUS 23
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

Servo myservo;

int pos = 20; 
int pos1 = 67; 

#define TdsSensorPin 35
#define VREF 5      
#define SCOUNT 30           
int analogBuffer[SCOUNT];    
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0,copyIndex = 0;
float averageVoltage = 0,tdsValue = 0,temperature = 25;

Adafruit_ADS1115 ads;  
long lastMsg = 0;
char msg[50];


const int pompa_akuarium = 17; 
const int aerator = 16;
int pompa_pupuk_output = 13;
int pompa_pupuk = 15;
int fishfeeder = 4;


int Aa = 8, Bb = 18;  
int Cc = 7;          
int Dd = 0, Ee = 2;   
int Ff = 6, Gg = 19;
int Hh = 0, Ii = 1;   
float ph = 0;
float ph_step;

double teganganph;


float ph4= 2.080;
float ph7 =1.905;

int getMedianNum(int bArray[], int iFilterLen) 
{
      int bTab[iFilterLen];
      for (byte i = 0; i<iFilterLen; i++)
      bTab[i] = bArray[i];
      int i, j, bTemp;
      for (j = 0; j < iFilterLen - 1; j++) 
      {
      for (i = 0; i < iFilterLen - j - 1; i++) 
          {
        if (bTab[i] > bTab[i + 1]) 
            {
        bTemp = bTab[i];
            bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
         }
      }
      }
      if ((iFilterLen & 1) > 0)
    bTemp = bTab[(iFilterLen - 1) / 2];
      else
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
    return bTemp;
}

void startLoRA(){
  //SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);

  while (!LoRa.begin(BAND) && counter < 10) {
    Serial.print(".");
    counter++;
    delay(500);
  }
  if (counter == 10) {
    // Increment readingID on every new reading
    readingID++;
    Serial.println("Starting LoRa failed!"); 
  }
  Serial.println("LoRa Initialization OK!");
  delay(2000);
}

void setup () {
  Serial.begin(115200);
 
   ads.begin();
   rtcBegin();
   setManual(2023, 5, 24, 5, 00, 57); // set manual rtc 
     sensors.begin();
     myservo.attach(fishfeeder);

   pinMode(TdsSensorPin,INPUT);
   pinMode(pompa_akuarium, OUTPUT);
   pinMode(pompa_pupuk, OUTPUT);
   pinMode(pompa_pupuk_output, OUTPUT);   
   pinMode(fishfeeder, OUTPUT); 
   pinMode(aerator, OUTPUT);    
      digitalWrite(pompa_pupuk, HIGH); 
      digitalWrite(pompa_akuarium, HIGH);
      digitalWrite(pompa_pupuk_output, HIGH) ;
      digitalWrite(fishfeeder, HIGH) ;
      digitalWrite(aerator, HIGH) ;
    
   startLoRA();
}

void loop () {
 if (LoRa.parsePacket()){
      LoRaMessage1 += (char)LoRa.read();
  
    int separatorIndex = LoRaMessage1.indexOf(",");
    if (separatorIndex !=-1){
      pompa_akuarium_status = LoRaMessage1.substring(0, separatorIndex).toInt();
      aerator_status = LoRaMessage1.substring(separatorIndex + 1).toInt();
    }
    if (pompa_akuarium_status == 0){
      digitalWrite(pompa_akuarium, HIGH);
      Serial.print(" Power pompa akuarium OFF ");
     Serial.println(pompa_akuarium_status);
    } else if (pompa_akuarium_status == 1){
      digitalWrite(pompa_akuarium, LOW);
     Serial.print(" Power pompa akuarium ON ");
     Serial.println(pompa_akuarium_status);
    }
        if (aerator_status == 0){
      digitalWrite(aerator, HIGH);
            Serial.print(" aerator OFF ");
     Serial.println(aerator_status);
    } else if (aerator_status == 1){
      digitalWrite(aerator, LOW);
                  Serial.print(" aerator ON ");
     Serial.println(aerator_status);
    }
  }
realtimeclock();
aktuator();
const int16_t nilai_analog_ph = ads.readADC_SingleEnded(0)/14.88;
Serial.print("Nilai ADC ph =");
Serial.println(nilai_analog_ph);
double teganganph = 5/4095.0*nilai_analog_ph;
Serial.print("Tegangan Ph =");
Serial.print(teganganph,3);


ph_step=(ph4-ph7)/3;
ph = 7.00+((ph7-teganganph)/ph_step);
    Serial.print("  pH Value: ");
    Serial.println(ph, 2);
sensor();
 delay(1000);
  }
  
