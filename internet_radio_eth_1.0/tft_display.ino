void displaySplashScreen()
{
  tft.clear();
  
  String s1 = "Internet Radio";
  tft.setGFXFont(&FreeSansBold12pt7b);                                         // set current font
  tft.getGFXTextExtent(s1, x, y, &w, &h);                                      // get string extents
  y = h;                                                                       // set y position to string height
  tft.drawGFXText(20, y, s1, COLOR_TURQUOISE);                                 // print string

  tft.drawLine(0, 40, 219, 40, COLOR_WHITE);

  String s2 = "with PCM5102 I2S";
  tft.setGFXFont(&FreeSans9pt7b);                                              // set current font
  tft.getGFXTextExtent(s2, x, y, &w, &h);                                      // get string extents
  y = h+50;                                                                    // set y position to string height
  tft.drawGFXText(x, y, s2, COLOR_WHITE);                                      // Print string

  String s3 = "audio module and";
  tft.setGFXFont(&FreeSans9pt7b);                                              // set current font
  tft.getGFXTextExtent(s3, x, y, &w, &h);                                      // get string extents
  y = h+80;                                                                    // set y position to string height
  tft.drawGFXText(x, y, s3, COLOR_WHITE);                                      // print string

  String s4 = "Ethernet connectivity";
  tft.setGFXFont(&FreeSans9pt7b);                                              // set current font
  tft.getGFXTextExtent(s4, x, y, &w, &h);                                      // get string extents
  y = h+110;                                                                   // set y position to string height
  tft.drawGFXText(x, y, s4, COLOR_WHITE);                                      // print string

  tft.drawLine(0, 135, 219, 135, COLOR_WHITE);
  
  String s5 = producedBy;
  tft.setGFXFont(&FreeSans9pt7b);                                              // set current font
  tft.getGFXTextExtent(s5, x, y, &w, &h);                                      // set string extents
  y = h+150;                                                                   // set y position to string height
  tft.drawGFXText(x, y, s5, COLOR_GREEN);                                      // print string
  
}



void displaySystemInfo()
{
  tft.clear();
  
  String s1 = "Internet Radio";
  tft.setGFXFont(&FreeSansBold12pt7b);                                          // set current font
  tft.getGFXTextExtent(s1, x, y, &w, &h);                                       // get string extents
  y = h;                                                                        // set y position to string height
  tft.drawGFXText(20, y, s1, COLOR_TURQUOISE);                                  // print string

  tft.drawLine(0, 40, 219, 40, COLOR_WHITE);

  String s2 = "HW revision: " + hwRevision;
  tft.setGFXFont(&FreeSans9pt7b);                                               // Set current font
  tft.getGFXTextExtent(s2, x, y, &w, &h);                                       // Get string extents
  y = h+50;                                                                     // set y position to string height
  tft.drawGFXText(x, y, s2, COLOR_WHITE);                                       // print string

  String s3 = "SW version: " + swVersion;
  tft.setGFXFont(&FreeSans9pt7b);                                               // set current font
  tft.getGFXTextExtent(s3, x, y, &w, &h);                                       // get string extents
  y = h+80;                                                                     // set y position to string height
  tft.drawGFXText(x, y, s3, COLOR_WHITE);                                       // print string

  String s4 = "SW date: " + swReleaseDate;
  tft.setGFXFont(&FreeSans9pt7b);                                               // set current font
  tft.getGFXTextExtent(s4, x, y, &w, &h);                                       // get string extents
  y = h+110;                                                                    // set y position to string height
  tft.drawGFXText(x, y, s4, COLOR_WHITE);                                       // print string

  tft.drawLine(0, 135, 219, 135, COLOR_WHITE);
  
  String s5 = producedBy;
  tft.setGFXFont(&FreeSans9pt7b);                                               // set current font
  tft.getGFXTextExtent(s5, x, y, &w, &h);                                       // get string extents
  y = h+150;                                                                    // set y position to string height
  tft.drawGFXText(x, y, s5, COLOR_GREEN);                                       // print string
}



void displayConnecting()
{
  tft.clear();
  
  String s1 = "Internet Radio";
  tft.setGFXFont(&FreeSansBold12pt7b);                                           // set current font
  tft.getGFXTextExtent(s1, x, y, &w, &h);                                        // get string extents
  y = h;                                                                         // set y position to string height
  tft.drawGFXText(20, y, s1, COLOR_TURQUOISE);                                   // print string

  tft.drawLine(0, 40, 219, 40, COLOR_WHITE);

  String s2 = "Connecting to Internet...";
  tft.setGFXFont(&FreeSans9pt7b);                                                // set current font
  tft.getGFXTextExtent(s2, x, y, &w, &h);                                        // get string extents
  y = h+80;                                                                      // set y position to string height
  tft.drawGFXText(x, y, s2, COLOR_WHITE);                                        // print string

  tft.drawLine(0, 135, 219, 135, COLOR_WHITE);
  
  String s5 = producedBy;
  tft.setGFXFont(&FreeSans9pt7b);                                                // set current font
  tft.getGFXTextExtent(s5, x, y, &w, &h);                                        // get string extents
  y = h+150;                                                                     // set y position to string height
  tft.drawGFXText(x, y, s5, COLOR_GREEN);                                        // print string
}



void displayConnected(String localIpAddress)
{
  tft.clear();
  
  String s1 = "Internet Radio";
  tft.setGFXFont(&FreeSansBold12pt7b);                                           // set current font
  tft.getGFXTextExtent(s1, x, y, &w, &h);                                        // get string extents
  y = h;                                                                         // set y position to string height
  tft.drawGFXText(20, y, s1, COLOR_TURQUOISE);                                   // print string

  tft.drawLine(0, 40, 219, 40, COLOR_WHITE);

  String s2 = "Connected to Internet";
  tft.setGFXFont(&FreeSans9pt7b);                                                // set current font
  tft.getGFXTextExtent(s2, x, y, &w, &h);                                        // get string extents
  y = h+50;                                                                      // set y position to string height
  tft.drawGFXText(x, y, s2, COLOR_WHITE);                                        // print string

  String s3 = "Assigned IP Address";
  tft.setGFXFont(&FreeSans9pt7b);                                                // set current font
  tft.getGFXTextExtent(s3, x, y, &w, &h);                                        // get string extents
  y = h+80;                                                                      // set y position to string height
  tft.drawGFXText(x, y, s3, COLOR_WHITE);                                        // print string

  String s4 = localIpAddress;
  tft.setGFXFont(&FreeSans9pt7b);                                                // set current font
  tft.getGFXTextExtent(s4, x, y, &w, &h);                                        // get string extents
  y = h+110;                                                                     // set y position to string height
  tft.drawGFXText(x, y, s4, COLOR_WHITE);                                        // print string

  tft.drawLine(0, 135, 219, 135, COLOR_WHITE);
  
  String s5 = producedBy;
  tft.setGFXFont(&FreeSans9pt7b);                                                // set current font
  tft.getGFXTextExtent(s5, x, y, &w, &h);                                        // get string extents
  y = h+150;                                                                     // set y position to string height
  tft.drawGFXText(x, y, s5, COLOR_GREEN);                                        // print string
}


void displayStreamInfo(String stationNumber, String stationName, String interpreterName, String songName)
{   
  if (interpreterName.length() > 21)
  {
    interpreterName1 = interpreterName.substring(0, 21);
    interpreterName2 = interpreterName.substring(21, interpreterName.length());
  }

  else if (interpreterName.length() <= 21)
  {
    interpreterName1 = interpreterName;
    interpreterName2 = "";
  }
  
  if (songName.length() > 21)
  {
    songName1 = songName.substring(0, 21);
    songName2 = songName.substring(21, songName.length());
  }

  else if (songName.length() <= 21)
  {
    songName1 = songName;
    songName2 = "";
  }


  tft.clear();  
  tft.setGFXFont(&FreeSans12pt7b);                                                // set current font
  tft.getGFXTextExtent("Station " + stationNumber, x, y, &w, &h);                 // get string extents  
  y = h;                                                                          // set y position to string height
  tft.drawGFXText(x, y, "Station " + stationNumber, COLOR_WHITE);                 // print string


  tft.setGFXFont(&FreeSansBold12pt7b);                                            // set current font
  tft.getGFXTextExtent(stationName, x, y, &w, &h);                                // set string extents
  y = h+30;                                                                       // set y position to string height
  tft.drawGFXText(x, y, stationName, COLOR_TURQUOISE);                            // print string
  tft.drawLine(0, 65, 219, 65, COLOR_WHITE);


  tft.setGFXFont(&FreeSans9pt7b);                                                 // set current font
  tft.getGFXTextExtent(interpreterName1, x, y, &w, &h);                           // get string extents
  y = h+80;                                                                       // set y position to string height
  tft.drawGFXText(x, y, interpreterName1, COLOR_GOLD);                            // print string


  tft.setGFXFont(&FreeSans9pt7b);                                                 // set current font
  tft.getGFXTextExtent(interpreterName2, x, y, &w, &h);                           // get string extents
  y = h+100;                                                                      // set y position to string height
  tft.drawGFXText(x, y, interpreterName2, COLOR_GOLD);                            // print string


  tft.setGFXFont(&FreeSans9pt7b);                                                 // set current font
  tft.getGFXTextExtent(songName1, x, y, &w, &h);                                  // get string extents
  y = h+130;                                                                      // set y position to string height
  tft.drawGFXText(x, y, songName1, COLOR_GREEN);                                  // print string


  tft.setGFXFont(&FreeSans9pt7b);                                                 // set current font
  tft.getGFXTextExtent(songName2, x, y, &w, &h);                                  // get string extents
  y = h+150;                                                                      // set y position to string height
  tft.drawGFXText(x, y, songName2, COLOR_GREEN);                                  // print string 
}
