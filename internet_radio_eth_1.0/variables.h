String hwRevision = "1";                                                            // define HW revision
String swVersion = "1.0";                                                           // define SW version
String swReleaseDate = "25.07.2022";                                                // define SW release date
String producedBy = "www.github.com/d7prog";                                        // define producer name

// create tft diplay variables
int16_t x = 0;
int16_t y = 0;
int16_t w;
int16_t h;


String localIpAddress;

String stationUrl;
String stationNumber;
String stationName;
String interpreterName;
String songName;

String songName1;
String songName2;

String interpreterName1;
String interpreterName2;

const int RECV_PIN = 21;
int stationID = 1;
int currentStationID;

int volume = 10;                                                                    // defalult volume after switch on
int lastVolume = 10;                                                                // last volume before mute
