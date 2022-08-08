String getInterpreterName(String info)
{
  String parseString = info;

  String interpreterName;
  int interpreterName2 = 0;

  int index = parseString.indexOf('-');
  interpreterName = parseString.substring(0, index);
  
  Serial.println(interpreterName);

  if (stationID == 10)
  {
    interpreterName = "";
  }

  return interpreterName;
}


String getSongName(String info)
{
  String parseString = info;

  String songNameTemp;
  String songName;
//  int songName2 = 0;

  int index = parseString.indexOf('-'); 
  int stringLength = parseString.length();
  
  
  songNameTemp = parseString.substring(index, stringLength);

  songName = songNameTemp.substring(2, stringLength);
  
  Serial.println(songName);

  if (stationID == 10)
  {
    songName = "";
  }
  
  return songName;
}
