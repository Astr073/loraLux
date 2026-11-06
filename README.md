# loraLux

<img src="images/darc-logo_hu_72068f3e06ddeb02.jpg" alt="DARC E13" width="180" align="left">

Dieses Projekt wurde innerhalb der Lora-AG mit dem DARC E-13 erstellt.

Internetseite vom DARC E-13: https://www.amateurfunk-im-alstertal.de/

<br clear="left">

## Funktionsweise
Der loraLuxSender liest die Helligkeit aus und sendet diese and den loraReceiver. Der loraLuxReceiver stellt die
gemessene Helligkeit an einer Mehrfarbigen LED dar. Blau ist der dunkelste Wert und rot der Hellste.
Alle Werte dazwischen werden als Mischwerte von blau und rot abgebildet.
## Material

- Zwei LilyGo T3 1.6.1
- Helligkeitssensor
- Mehrfarbige LED
- 220 Ohm Wiederstand
- Breadboards und Jumperkabel

## Voraussetzungen und Bibliotheken (Installation)
Für die Kompilierung des Quellcodes wird die Arduino IDE benutzt.

### Manuell zu installierende Bibliotheken
| Bibliothek / Header | Name im Bibliotheksverwalter | Autor | Zweck |
| :--- | :--- | :--- | :--- |
| `"SSD1306Wire.h"` | **ESP8266 and ESP32 OLED driver for SSD1306 displays** | ThingPulse | Steuerung des OLED-Displays |
| `<LoRa.h>` | **LoRa** | Sandeep Mistry | Funkkommunikation über das LoRa-Modul |


### Standard-Bibliotheken
Die folgenden Bibliotheken sind bereits fest in der Arduino IDE integriert und müssen **nicht** extra installiert werden:
* `<SPI.h>` – Ermöglicht die SPI-Kommunikation mit dem LoRa-Modul.
* `<string.h>` – Standard-C++-Bibliothek für Textoperationen.


## Aufbau

### loraLuxReceiver

![Schaltplan](images/lora_lux_receiver_bb.png)


### loraLuxSender

![Schaltplan](images/lora_lux_sender_bb.png)
