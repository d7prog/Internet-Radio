/* File name:         internet_radio_eth_1.0
 * Version:           1.0
 * Date:              25-07-2022
 * 
 * Description:       ESP32 Internet Radio with I2S audio modul PCM5102
 * 
 * Changes ver1.0:    Initial version
 *            
 * Author:            d7prog
 * 
 * Credits:           Schreibfaul1 https://github.com/schreibfaul1/ESP32-audioI2S
 *                    Wyatt59 https://github.com/schreibfaul1/ESP32-audioI2S/files/9173837/Audioeth.zip
 *                    Nkawu https://github.com/Nkawu/TFT_22_ILI9225
 *                    crankyoldgit https://github.com/crankyoldgit/IRremoteESP8266
 *                    Arduino https://github.com/arduino-libraries/Ethernet                  
 */


#include "variables.h"
#include "defines.h"

#include <SPI.h>
#include "Ethernet.h"
#include "Audioeth.h"

#include "TFT_22_ILI9225.h"

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

// include font definition files
#include <../fonts/FreeSans9pt7b.h>
#include <../fonts/FreeSans12pt7b.h>
#include <../fonts/FreeSans18pt7b.h>
#include <../fonts/FreeSans24pt7b.h>

#include <../fonts/FreeSansBold12pt7b.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xAD };                                                  // MAC address setup


IRrecv irrecv(RECV_PIN);
decode_results results;

Audioeth audioeth;                                                                                    // create audio object

SPIClass hspi(HSPI);                                                                                  // create hspi class  

                                                            
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);                // create tft class



void setup()
{
  Serial.begin(115200);                                                                               // initialize serial communication at 115200 bits per second

  irrecv.enableIRIn();
  
  hspi.begin();
  tft.begin(hspi);
  tft.clear();
  tft.setOrientation(1);
  
  Ethernet.init(5);                                                                                   // define SCS pin for Ethernet
  Ethernet.begin(mac);
  
  Serial.print(F("Connected! IP address: "));                                                         // display IP address used by ESP32
  Serial.println(Ethernet.localIP());

  localIpAddress = Ethernet.localIP().toString();
  

  displaySplashScreen();
  delay(2000);
  displaySystemInfo();
  delay(2000);
  displayConnecting();
  delay(1000);
  displayConnected(localIpAddress);
  delay(2000);

  audioeth.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);                                                    // connect MAX98357 I2S Amplifier Module

  audioeth.setVolume(10);                                                                             // set thevolume (0-100)
}



void loop()
{
  if (irrecv.decode(&results))                                                            
  {         
    switch(results.value)
    {           
      case 0xFF6897:                                                                                  // select station - button CH-
      if (stationID > 1)
      {         
        stationID = stationID - 1;
        Serial.println(stationID);
      }
      break;
  
      case 0xFF609F:                                                                                  // select station - button CH+           
      if (stationID <= 10) 
      {       
        stationID = stationID + 1;
        Serial.println(stationID);
      }
      break;

      case 0xFF4AB5:                                                                                  // select station - button 1             
      if (stationID != 1)
      {
        stationID = 1;
        Serial.println(stationID);
      }
      break;

      case 0xFF0AF5:                                                                                  // select station - button 2             
      if (stationID != 2)
      {
        stationID = 2;
        Serial.println(stationID);
      }
      break;

      case 0xFF08F7:                                                                                  // select station - button 3             
      if (stationID != 3)
      {
        stationID = 3;
        Serial.println(stationID);
      }
      break;

      case 0xFF6A95:                                                                                  // select station - button 4             
      if (stationID != 4)
      {
        stationID = 4;
        Serial.println(stationID);
      }
      break;

      case 0xFF2AD5:                                                                                  // select station - button 5            
      if (stationID != 5)
      {
        stationID = 5;
        Serial.println(stationID);
      }
      break;

      case 0xFF28D7:                                                                                  // select station - button 6            
      if (stationID != 6)
      {
        stationID = 6;
        Serial.println(stationID);
      }
      break;

      case 0xFF728D:                                                                                  // select station - button 7           
      if (stationID != 7)
      {
        stationID = 7;
        Serial.println(stationID);
      }
      break;

      case 0xFF32CD:                                                                                  // select station - button 8           
      if (stationID != 8)
      {
        stationID = 8;
        Serial.println(stationID);
      }
      break;

      case 0xFF30CF:                                                                                  // select station - button 9           
      if (stationID != 9)
      {
        stationID = 9;
        Serial.println(stationID);
      }
      break;

      case 0xFFF00F:                                                                                  // select station - button 0            
      if (stationID != 10)
      {
        stationID = 10;
        Serial.println(stationID);
      }
      break;

      case 0xFFD827:                                                                                  // increase volume - button VOL+
      if (volume < 95)
      {             
        volume = volume + 2;  
        audioeth.setVolume(volume); 
        Serial.println(volume);        
      }
      break;
  
      case 0xFF5AA5:                                                                                  // increase volume - button VOL+
      if (volume > 5)
      {
        volume = volume - 2;          
        audioeth.setVolume(volume); 
        Serial.println(volume); 
      }
      break;

      case 0xFF9867:                                                                                  // mute sound
      if (volume != 0)
      {
        lastVolume = volume;
        volume = 0;
        audioeth.setVolume(volume); 
      }

      else if(volume == 0)                                                                             // resume sound to previous volume
      {
        volume = lastVolume;
        audioeth.setVolume(volume); 
      }
    }

    delay(200);                                                                                       // wait 200ms
    irrecv.resume();                                                                                  // read next data from IR
  }


if (stationID == 1 && stationID != currentStationID)
  {
    audioeth.connecttohost("orf-live.ors-shoutcast.at/wie-q1a");                                      // ORF Radio Wien
    currentStationID = stationID;
  }

  else if (stationID == 2 && stationID != currentStationID)
  {
    audioeth.connecttohost("orf-live.ors-shoutcast.at/oe3-q1a");                                      // OE3
    currentStationID = stationID;
  }

  else if (stationID == 3 && stationID != currentStationID)
  {
    audioeth.connecttohost("live.u1-radio.at/;stream.mp3");                                           // U1 Tirol
    currentStationID = stationID;
  }

  else if (stationID == 4 && stationID != currentStationID)
  {
    audioeth.connecttohost("dispatcher.rndfnk.com/br/br3/live/aac/low?aggregator=radio-de");          // Bayern 3
    currentStationID = stationID;
  }

  else if (stationID == 5 && stationID != currentStationID)
  {
    audioeth.connecttohost("liveradio.swr.de/rddez3a/swraktuell/");                                   // SWR Aktuells
    currentStationID = stationID;
  }

  else if (stationID == 6 && stationID != currentStationID)
  {
    audioeth.connecttohost("fm1melody.ice.infomaniak.ch/fm1melody-128.mp3");                          // Radio Melody
    currentStationID = stationID;
  }

  else if (stationID == 7 && stationID != currentStationID)
  {
    audioeth.connecttohost("strmreg.1.fm/ccountry_mobile_mp3");                                       // 1.FM - Classic Country
    currentStationID = stationID;
  }

  else if (stationID == 8 && stationID != currentStationID)
  {
    audioeth.connecttohost("0n-70s.radionetz.de/0n-70s.mp3");                                         // ON 70s
    currentStationID = stationID;
  }

  else if (stationID == 9 && stationID != currentStationID)
  {
    audioeth.connecttohost("icecast7.play.cz/cro1-128.mp3");                                          // ČR Radiožurnál
    currentStationID = stationID;
  }

  else if (stationID == 10 && stationID != currentStationID)
  {
    audioeth.connecttohost("20423.live.streamtheworld.com/RADIO_HUMOR.aac");                          // Rádio humor
    currentStationID = stationID;
  }

  audioeth.loop();                                                                                    // run audio player
}


// audio status functions
void audio_icyurl(const char *info)
{
  Serial.print("icyurl      "); Serial.println(info);

  stationUrl = info;
}


void audio_showstation(const char *info) 
{
  Serial.print("station     "); Serial.println(info);
  stationNumber = String(stationID, DEC);
  stationName = info;


  switch(stationID)
  {
    case 1:
    stationName = "ORF Radio Wien";
    break;

    case 2:
    stationName = "Hitradio OE3";
    break;

    case 3:
    stationName = "Radio U1 Tirol";
    break;

    case 4:
    stationName = "Bayern 3";
    break;

    case 5:
    stationName = "SWR Aktuell";
    break;

    case 6:
    stationName = "Radio Melody";
    break;

    case 7:
    stationName = "Clasic Country";
    break;

    case 8:
    stationName = "ON 70s";
    break;

    case 9:
    stationName = "CRo Radiozurnal";
    break;

    case 10:
    stationName = "Radio Humor";
    break;
  }

  displayStreamInfo(stationNumber, stationName, "", "");   
}


void audio_showstreamtitle(const char *info)
{
  Serial.print("streamtitle "); Serial.println(info);

  interpreterName = getInterpreterName(info);
  songName = getSongName(info);

  displayStreamInfo(stationNumber, stationName, interpreterName, songName);
}
