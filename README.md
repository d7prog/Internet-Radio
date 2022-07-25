# Internet-Radio
Internet Radio with ESP32 and Ethernet connection

## Why another Internet Radio/Web Radio project?
There are many tutorials available on the Internet on this topic, however most of them use Wi-Fi connection as a natural choice, because the build-in Wi-Fi connection is an integral part of the ESP32 chip. However, personally I prefer Ethernet over Wi-Fi because of a better connection stability and avoiding exposure to electromagnetic radiation is allays a good choice. Therefore I have build my own version of Internet Radio, which fulfills my personnel needs. For all those who would find it useful, I decided to make my project public. 

## Used components
Controller:         ESP32 development board<br/>
I2S D/A converter:  PCM5102A with line output, equipped with 3.5mm stereo audio connector and 2 CINCH connectors<br/>
TFT Display:        2.0" 176x220 TFT display, ILI9225, SPI<br/>
Ethernet module:    WIZ850io<br/>
IR receiver:        TSOP4838<br/>
Power supply:       LM3940<br/>


## Schematic diagram
![](/internet_radio.jpg?raw=true "Schematic diagram")


## Arduino software libraries
Software is based on Schreibfaul1 librray for 
https://github.com/schreibfaul1/ESP32-audioI2S which perfectly works with  PCM5102A modules

Wyatt59 Audioeth library, which is a modified ESP32-audioI2S library for use with Arduino Ethernet library.
https://github.com/schreibfaul1/ESP32-audioI2S/files/8943164/Audioeth.zip

Nkawu TFT ILI 9225 display library https://github.com/Nkawu/TFT_22_ILI9225

crankyoldgit library which enables you to send and receive infra-red signals on an ESP8266 or an ESP32
https://github.com/crankyoldgit/IRremoteESP8266

Arduino Ethernet Library
https://github.com/arduino-libraries/Ethernet


## Software installation
1. Install all above mentioned Arduino software libraries via Arduino IDE Library Manager.

2. To install Wyatt59 Audioeth ethernet support just do the following:<br/>
Open Arduino/libraries/ESP32-audioI2S/src folder and copy Audioeth.cpp and Audioeth.h files to this folder. So the folder will consist of the following files:<br/>
Audio.cpp<br/> 
Audio.h<br/>
Audioeth.cpp<br/>
Audioeth.h<br/>

2. Create new Arduino sketch called internet_radio_eth_1.0.
3. Copy all files from the GitHub internet_radio_eth_1.0 folder to newly created Arduino sketch folder (the original  internet_radio_eth_1.0.ino will be rewrited).
4. Compile and download to ESP32 as usually.

## Notes
Internet radio has 10 preset stations which can be selected using IR remote controller. You can use any old IR remote controller however you need to use correct IR codes.<br>
For this reason use [ir_decoder](https://github.com/d7prog/Internet-Radio/blob/main/util/ir_decoder.ino) to record codes from the IR controller.<br>
Than modify the switch → case statements accordingly in the void loop{} function in the internet_radio_eth_1.0.ino file. Codes needs to be in hex format.

You can use the following commands:<br>
Select station number 1 – 9 (station 10 is 0)<br>
Increase/decrease volume using Vol+/Vol-<br>
Mute sound (use mute button or any button you select)



## Final mechanical assembly
![](/images/internet-radio1.jpg?raw=true "Front view")

![](/images/internet-radio2.jpg?raw=true "Inside view")

![](/images/internet-radio3.jpg?raw=true "Back view")



