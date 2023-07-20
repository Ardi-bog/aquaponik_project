// Import Wi-Fi library
#include <WiFi.h>
#include <SPIFFS.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
//Libraries for LoRa
#include <SPI.h>
#include <LoRa.h>

// Variables to save date and time
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
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

// Replace with your network credentials
// Konfigurasi jaringan Wi-Fi
const char* ssid = "Galaxy A32";
const char* password = "11111111";
//const char* ssid     = "ASUS_X00TD";
//const char* password = "najiboel";
const char* mqtt_server = "192.168.237.166";
// Variables to save date and time
String formattedDate;
String day;
String hour;
String timestamp;


// Initialize variables to get and save LoRa data
int rssi;
String loRaMessage;
String suhu;
String tdsValue;
String ph;
String readingID;
String pompa_pupuk_status;
String aerator_status;


// Replaces placeholder with DHT values
String processor(const String& var){
  //Serial.println(var);
  if(var == "SUHU"){
    return suhu;
  }
  else if(var == "PH"){
    return ph;
  }
  else if(var == "TDS"){
    return tdsValue;
  }
  else if(var == "TIMESTAMP"){
    return timestamp;
  }
  else if (var == "RRSI"){
    return String(rssi);
  }
  return String();
}

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect("ttgoClient")) {
      Serial.println("connected");
      // ... and resubscribe
      client.subscribe("mqtt/pompa");
      client.subscribe("mqtt/aerator");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(1000);
    }
  }
}

//Initialize LoRa module
void startLoRA(){
  int counter;
  //SPI LoRa pins
  SPI.begin(SCK, MISO, MOSI, SS);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DIO0);

  while (!LoRa.begin(BAND) && counter < 10) {
    Serial.print(".");
    counter++;
    delay(500);
  }
}

void connectWiFi(){
  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// Read LoRa packet and get the sensor readings
void getLoRaData() {
  Serial.print("Lora packet received: ");
  // Read packet
  while (LoRa.available()) {
    String LoRaData = LoRa.readString();
    // LoRaData format: readingID/temperature&soilMoisture#batterylevel
    // String example: 1/27.43&654#95.34
    Serial.print(LoRaData); 
    
    // Get readingID, temperature and soil moisture
    int pos1 = LoRaData.indexOf("/");
    int pos2 = LoRaData.indexOf("&");
    int pos3 = LoRaData.indexOf("#");
    int pos4 = LoRaData.indexOf("!");
    readingID = LoRaData.substring(0, pos1);
    suhu = LoRaData.substring(pos1 +1, pos2);
    ph = LoRaData.substring(pos2+1, pos3);
    tdsValue = LoRaData.substring(pos3+1,LoRaData.length());    

  }
  // Get RSSI
  rssi = LoRa.packetRssi();
  Serial.print(" with RSSI ");    
  Serial.println(rssi);
}
void callback (  String& topic,  byte* payload,  unsigned int length){
 payload[length] = '\0';
 Serial.print(" Pesan diterima = ");
 Serial.println(topic);
 Serial.print("Payload = ");
 Serial.println((String&)payload);  
  if((topic, "mqqt/pompa") == 0){
    (pompa_akuarium_status, (String&) payload);
  }
   else if((topic, "mqqt/aerator") == 0){
    ( aerator_status, (String&) payload);
    }
  }

void setup() { 
  // Initialize Serial Monitor
  Serial.begin(115200);
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  startLoRA();
  connectWiFi();
}

void loop() {
//coding menirim data control relay
     Serial.println(pompa_akuarium_status);
    Serial.println(" : ");
    Serial.println(aerator_status);
 String LoRaMessage1 = String(pompa_akuarium_status) +  ","  + String(aerator_status);
   LoRa.beginPacket();
  LoRa.print(LoRaMessage1);
  LoRa.endPacket();
  // Coding menerima data sensor
  int packetSize = LoRa.parsePacket();
    if (packetSize) {
    getLoRaData();
    String data = "";
    while (LoRa.available()) {
      data += (char)LoRa.read();
    }
    Serial.print("Data diterima: ");
    Serial.println(data);  
  }
  if (!client.connected()) 
  {
    reconnect();
  }
  client.loop();
  long now = millis();
  if (now - lastMsg > 1000) {
    lastMsg = now;
    StaticJsonDocument<512> jsonDocument;
jsonDocument["suhu"] = suhu;
jsonDocument["ph"] = ph;
jsonDocument["tds"] = tdsValue;

    String jsonString;
    serializeJson(jsonDocument, jsonString);
    char jsonCharArray[jsonString.length() + 1];
    jsonString.toCharArray(jsonCharArray, sizeof(jsonCharArray));
  // Publish the JSON data to the MQTT topic
    client.publish("mqtt/data", jsonCharArray);
  // Check if there are LoRa packets available
}
}
