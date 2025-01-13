#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
const char* ssid = "Jakob - iPhone";
const char* pass = "kodekodeadad";
WiFiClient client;
unsigned long channelID = 2808277; //your TS channal
const char * APIKey = "PKX3A19J2G4V5U2Q"; //your TS API
const char* server = "api.thingspeak.com";
const int postDelay = 20 * 1000; //post data every 5 seconds

const char* readAPIKey = "MT49SDOA5WVE5PKW"; //Read API Key

const int led = D2;

bool LEDon = 1;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  pinMode(led, OUTPUT);
  digitalWrite(led,LEDon);
}

float data; //measured data
int RSSI;
int readRSSI = 0;
void loop() {
  RSSI = WiFi.RSSI();
  digitalWrite(led,LEDon);

  ThingSpeak.begin(client);
  client.connect(server, 80); //connect(URL, Port)
  ThingSpeak.setField(1, RSSI); //set data on the X graph
  ThingSpeak.setField(2, LEDon);

  readRSSI = ThingSpeak.readIntField(channelID, 1, readAPIKey);

  Serial.print("Read previous RSSI: ");
  Serial.println(readRSSI);

  Serial.print("WiFi RSSI: ");
  Serial.println(RSSI);
  Serial.println("");

  ThingSpeak.writeFields(channelID, APIKey);//post everything to TS
  client.stop();
  LEDon = !LEDon;
  delay(postDelay); //wait and then post  again
}
