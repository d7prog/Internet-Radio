# Internet-Radio
Internet Radio with ESP32 and Ethernet connection

## Why another Internet Radio/Web Radio project?
There are many tutorials available on the Internet on this topic, however most of them use Wi-Fi connection as a natural choice, because the build-in Wi-Fi connection is an integral part of the ESP32 chip. However, personally I prefer Ethernet over Wi-Fi because of a better connection stability and avoiding exposure to electromagnetic radiation is allays good choice. Therefore I have build my own version of Internet Radio, which fulfills my personnel need. For all those who would find it useful, I present a detailed instructions.

## Used components
Controller:		ESP32 development board
I2S D/A converter:	PCM5102A with line output, equipped with 3.5mm stereo audio connector and 2 CINCH connectors.

TFT Display:		2.0" 176x220 TFT display, ILI9225, SPI

Ethernet module:	WIZ850io

IR receiver:		TSOP4838

Power supply converter: LM3940

## The complete schematic diagram with all components
