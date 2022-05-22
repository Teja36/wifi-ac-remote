#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#import "index.h"

const uint16_t kIrLed = 14;

/*Put your SSID & Password*/
const char* ssid = "Hi5Wi5";  // Enter SSID here
const char* password = "babuji000";  //Enter Password here

IRsend irsend(kIrLed);

ESP8266WebServer server(80);

// On
uint16_t rawOn[59] = {8552, 4138,  636, 1472,  638, 416,  638, 416,  612, 444,  638, 1472,  612, 442,  586, 468,  612, 442,  612, 444,  586, 468,  612, 442,  612, 442,  610, 444,  614, 442,  612, 442,  612, 444,  610, 1498,  612, 1498,  612, 444,  612, 1498,  612, 442,  610, 1500,  636, 418,  612, 444,  638, 416,  612, 442,  638, 416,  612, 1498,  612};

// Off
uint16_t rawOff[59] = {8552, 4118,  630, 1498,  612, 442,  612, 444,  610, 444,  612, 1498,  612, 442,  612, 442,  612, 444,  612, 1498,  612, 1498,  612, 442,  612, 444,  612, 442,  612, 444,  612, 442,  612, 444,  610, 444,  612, 444,  612, 442,  612, 444,  610, 444,  610, 1498,  612, 442,  612, 1500,  612, 442,  612, 442,  612, 444,  610, 1498,  612};

// Swing
uint16_t rawSwing[59] = {8500, 4190,  558, 1550,  560, 494,  560, 494,  560, 494,  560, 1550,  560, 494,  560, 494,  560, 494,  566, 480,  578, 486,  560, 494,  562, 1548,  560, 494,  562, 492,  560, 494,  560, 494,  560, 494,  560, 494,  562, 494,  560, 494,  562, 494,  560, 494,  560, 494,  560, 494,  560, 494,  560, 494,  562, 492,  560, 1550,  560};

// JetCool
uint16_t rawJetCool[59] = {8500, 4168,  608, 1524,  560, 494,  560, 494,  586, 470,  560, 1550,  560, 494,  584, 470,  586, 470,  584, 470,  586, 468,  586, 468,  586, 1538,  546, 494,  586, 468,  586, 468,  586, 468,  586, 468,  588, 468,  586, 468,  586, 468,  586, 1524,  586, 468,  586, 468,  586, 468,  586, 1524,  588, 468,  586, 468,  586, 1524,  586};

//Timer off 1hr
uint16_t rawTimer1[59] = {8548, 4142,  582, 1524,  610, 444,  610, 446,  610, 444,  610, 1502,  608, 444,  610, 446,  610, 444,  610, 1502,  608, 444,  610, 446,  610, 1500,  608, 446,  610, 444,  610, 446,  610, 444,  610, 444,  610, 446,  610, 1500,  584, 1526,  608, 1502,  608, 1502,  610, 446,  608, 446,  610, 1500,  610, 444,  610, 444,  610, 446,  610};

uint16_t rawTimer2[59] = {8550, 4138,  586, 1522,  612, 442,  612, 442,  614, 440,  612, 1498,  586, 468,  612, 442,  610, 444,  612, 1496,  612, 442,  640, 416,  662, 1448,  586, 468,  612, 442,  612, 444,  612, 442,  640, 416,  612, 1498,  610, 1500,  610, 1498,  586, 1524,  612, 442,  586, 468,  612, 442,  636, 1472,  586, 468,  612, 444,  586, 468,  610};

uint16_t rawTimer3[59] = {8548, 4140,  582, 1526,  610, 442,  612, 442,  612, 442,  610, 1498,  612, 444,  612, 442,  612, 442,  616, 1494,  612, 444,  610, 444,  612, 1498,  612, 442,  612, 444,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 1498,  612, 1498,  612, 442,  612, 442,  612, 1498,  612, 1498,  612, 442,  612, 1498,  612, 1498,  612, 1498,  612};

uint16_t rawTimer4[59] = {8550, 4138,  612, 1496,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 1498,  612, 1498,  612, 442,  612, 1498,  612, 1498,  612, 1498,  612, 1498,  612, 442,  612, 1496,  614, 1496,  612, 442,  612};

uint16_t rawTimer45[59] = {8548, 4120,  628, 1498,  612, 442,  612, 444,  610, 444,  610, 1498,  610, 444,  612, 444,  610, 444,  612, 1498,  610, 444,  612, 444,  610, 1500,  612, 442,  612, 442,  612, 444,  610, 1500,  610, 444,  612, 442,  612, 442,  612, 444,  612, 1498,  610, 1500,  610, 444,  612, 442,  612, 444,  612, 1498,  612, 1498,  612, 444,  610};

uint16_t rawTimer5[59] = {8550, 4138,  610, 1498,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 442,  614, 442,  612, 1510,  600, 442,  612, 442,  614, 1496,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 1498,  612, 442,  612, 1498,  614, 442,  612, 442,  612, 1498,  612, 1498,  612, 442,  612};

uint16_t rawTimer55[59] = {8552, 4114,  632, 1512,  616, 426,  612, 442,  612, 442,  618, 1492,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  614, 442,  612, 1498,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 1498,  612, 442,  612, 442,  612, 1498,  614, 442,  612, 1498,  612, 442,  612, 1498,  612, 442,  612, 442,  614, 442,  612};

uint16_t rawTimer6[59] = {8550, 4138,  586, 1524,  612, 442,  612, 442,  624, 444,  606, 1492,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 1498,  612, 1498,  612, 442,  612, 442,  612, 1498,  612, 1498,  612, 1498,  612, 442,  612, 1498,  612, 1498,  612, 1498,  614};

uint16_t rawTimerCancel[59] = {8552, 4116,  606, 1504,  632, 442,  612, 442,  614, 442,  612, 1498,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  612, 1498,  612, 1496,  612, 442,  612, 442,  612, 442,  614, 442,  612, 442,  614, 442,  612, 442,  612, 442,  612, 444,  612, 442,  612, 442,  612, 442,  612, 1498,  612, 442,  614, 1498,  612, 1498,  612};

boolean ACstatus = false, jetCoolStatus = false;


void setup() {
  irsend.begin();
#if ESP8266
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
#else  // ESP8266
  Serial.begin(115200, SERIAL_8N1);
#endif  // ESP8266

  Serial.println("Connecting to ");
  Serial.println(ssid);

  //connect to your local wi-fi network
  WiFi.begin(ssid, password);

  //check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected..!");
  Serial.print("Got IP: ");  Serial.println(WiFi.localIP());

//  server.on("/", handle_OnConnect);/
  server.on("/OnOff", handle_OnOff);
  server.on("/Swing", handle_Swing);
  server.on("/JetCool", handle_JetCool);
  server.on("/OffTimer", handle_Timer);
  server.on("/TimerCancel", handle_TimerCancel);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
  handle_OnConnect();
}

void loop() {
  server.handleClient();
}

void handle_OnConnect() {
  Serial.println("Ready");
  if (ACstatus == false) {
    ACstatus = true;
    irsend.sendRaw(rawOn, 59, 38);  // Send a raw data capture at 38kHz.
    Serial.println("AC turend On.");}
  server.send(200, "text/html", MAIN_page);
}

void handle_OnOff() {
  if (ACstatus == false) {
    ACstatus = true;
    irsend.sendRaw(rawOn, 59, 38);  // Send a raw data capture at 38kHz.
    Serial.println("AC turend On.");
  }
  else {
    ACstatus = false;
    irsend.sendRaw(rawOff, 59, 38);  // Send a raw data capture at 38kHz.
    Serial.println("AC turend Off.");
  }
  server.send(200, "text/html", MAIN_page);
}

void handle_Swing() {
  irsend.sendRaw(rawSwing, 59, 38);
  Serial.println("Swing.");
  server.send(200, "text/html", MAIN_page);
}

void handle_JetCool() {
  if (jetCoolStatus == false) {
    jetCoolStatus = true;
    irsend.sendRaw(rawJetCool, 59, 38);
    Serial.println("Jetcool : ON");
  }
  else {
    jetCoolStatus = false;
    irsend.sendRaw(rawOn, 59, 38);
    Serial.println("Jetcool : OFF");
  }


  server.send(200, "text/html", MAIN_page);
}

void handle_Timer() {

  int timervalue = server.arg("timer").toInt();

//  Serial.println(timervalue);

  switch (timervalue) {

    case 1 : irsend.sendRaw(rawTimer1, 59, 38);
      Serial.println("Off timer set to 1 hr.");
      break;

    case 2 : irsend.sendRaw(rawTimer2, 59, 38);
      Serial.println("Off timer set to 2 hrs.");
      break;

    case 3 : irsend.sendRaw(rawTimer3, 59, 38);
      Serial.println("Off timer set to 3 hrs.");
      break;

    case 4 : irsend.sendRaw(rawTimer4, 59, 38);
      Serial.println("Off timer set to 4 hrs.");
      break;

    case 45 : irsend.sendRaw(rawTimer45, 59, 38);
      Serial.println("Off timer set to 4 1/2 hrs.");
      break;

    case 5 : irsend.sendRaw(rawTimer5, 59, 38);
      Serial.println("Off timer set to 5 hrs.");
      break;

    case 55 : irsend.sendRaw(rawTimer55, 59, 38);
      Serial.println("Off timer set to 5 1/2 hrs.");
      break;

    case 6 : irsend.sendRaw(rawTimer6, 59, 38);
      Serial.println("Off timer set to 6 hrs.");
      break;

    default : Serial.println("Invalid timer Value.");
              break;
  }

  server.send(200, "text/html", MAIN_page);
  
}

void handle_TimerCancel() {
  irsend.sendRaw(rawTimerCancel, 59, 38);
  Serial.println("Timer cancelled.");
  server.send(200, "text/html", MAIN_page);
  
}
void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}
