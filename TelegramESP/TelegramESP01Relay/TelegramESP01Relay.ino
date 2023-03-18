#include <ESP8266WiFi.h>
#include "FastBot.h"

#define WIFI_SSID "TME edu"
#define WIFI_PASS "begin9600"
#define BOT_TOKEN "IntroduzaSeuTokenAqui"
#define CHAT_ID "SeuID aqui"

#define LED 0

FastBot bot;

void setup() {
  connectWiFi();
  pinMode(LED, OUTPUT);
  bot.setToken(BOT_TOKEN);
  bot.attach(newMsg);
}

void newMsg(FB_msg& msg) {
  if (msg.text.equals("on"))
  {
    digitalWrite(LED, HIGH);
    bot.sendMessage("Lampada ligada", msg.chatID);
  }
  else if (msg.text.equals("off"))
  {
    digitalWrite(LED, LOW);
    bot.sendMessage("Lampada desligada", msg.chatID);
  }
}
void loop() {
  bot.tick();
}

void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    if (millis() > 15000) ESP.restart();
  }
}
