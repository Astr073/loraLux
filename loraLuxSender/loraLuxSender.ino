#include <SPI.h>
#include <LoRa.h>
#include <string.h>
#include "../lib/SSD1306Wire.h"
#include "../lib/OLEDDisplay.h"



SSD1306Wire display(0x3c, SDA, SCL);

// -----  Hier anpassen  ------------------------------
#define CODE_Buchstabe "B"
// ----------------------------------------------------

#define breite display.getWidth()
#define CS_PIN  18
#define RST_PIN 23
#define DIO_PIN 26
#define ADC_PIN 34
#define Messintervall 1000

float rawValue = 0;
int counter = 1;

void setup() {
  Serial.begin(115200);

  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.displayOn();
  display.clear();
  display.println("LoRa Sender");
  display.display();

  LoRa.setPins(CS_PIN, RST_PIN, DIO_PIN);
  if (!LoRa.begin(868000000)) {
    display.println("Starting LoRa failed!");
    display.display();
    while (1);
  }

  display.println("LoRa ok");
  display.display();
  delay(1000);
}

void loop() {
  rawValue = analogRead(ADC_PIN);

// Payload wird nicht als direkter Zahlenwert versendet, sondern ein Array an Bytes. 
// Im Receiver kann diese Payload korrekt in einen Zahlenwert umgewandelt werden.
// Im Gegensatz zur Alternative mit den Strings. 

  uint8_t payload[5];
  payload[0] = CODE_Buchstabe[0];
  memcpy(&payload[1], &rawValue, sizeof(rawValue));

  LoRa.beginPacket();
  LoRa.write(payload, sizeof(payload));
  LoRa.endPacket();

  Serial.print("Gesendet: ");
  Serial.println(rawValue);

  display.clear();
  display.println("LoRa Sender");
  display.println("");
  display.println("Sending packet:");
  display.println(String(counter));
  display.println("ADC:");
  display.println(String(rawValue, 2));
  display.display();

  counter++;
  delay(1000);
}