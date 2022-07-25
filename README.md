# Internet-Radio
Internet Radio with ESP32 and Ethernet connection

## Why another Internet Radio/Web Radio project?
There are many tutorials available on the Internet on this topic, however most of them use Wi-Fi connection as a natural choice, because the build-in Wi-Fi connection is an integral part of the ESP32 chip. However, personally I prefer Ethernet over Wi-Fi because of a better connection stability and avoiding exposure to electromagnetic radiation is allays good choice. Therefore I have build my own version of Internet Radio, which fulfills my personnel need. For all those who would find it useful, I present a detailed instructions.


## Used components
Controller:		      ESP32 development board
I2S D/A converter:	PCM5102A with line output, equipped with 3.5mm stereo audio connector and 2 CINCH connectors.
TFT Display:		    2.0" 176x220 TFT display, ILI9225, SPI
Ethernet module:	  WIZ850io
IR receiver:		    TSOP4838
Power supply:       LM3940


## Schematic diagram
![](/internet_radio.jpg?raw=true "Schematic diagram")


## Arduino software libraries
Software is based on Schreibfaul1 librray for 
https://github.com/schreibfaul1/ESP32-audioI2S which perfectly works with  PCM5102A modules

Wyatt59 Audioeth library, which is a modified ESP32-audioI2S library for use with Arduino Ethernet library.
https://github.com/schreibfaul1/ESP32-audioI2S/files/9173837/Audioeth.zip

Nkawu TFT ILI 9225 display library https://github.com/Nkawu/TFT_22_ILI9225

crankyoldgit library which enables you to send and receive infra-red signals on an ESP8266 or an ESP32
https://github.com/crankyoldgit/IRremoteESP8266

Arduino Ethernet Library
https://github.com/arduino-libraries/Ethernet

