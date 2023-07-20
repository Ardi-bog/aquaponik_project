void sensor (){

 // Minta sensor untuk membaca suhu
  sensors.requestTemperatures();

  // Baca suhu dalam derajat Celcius
  float suhu = sensors.getTempCByIndex(0);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

    Serial.print("  Suhu saat ini: ");
    Serial.print(suhu);
    Serial.println("°C");
    
  static unsigned long analogSampleTimepoint = millis();
//   if(millis()-analogSampleTimepoint > 40U)     //every 40 milliseconds,read the analog value from the ADC
//   {
     analogSampleTimepoint = millis();
     analogBuffer[analogBufferIndex] = analogRead(TdsSensorPin);    //read the analog value and store into the buffer
     analogBufferIndex++;
     if(analogBufferIndex == SCOUNT) 
     analogBufferIndex = 0;
//   }   
   static unsigned long printTimepoint = millis();
//   if(millis()-printTimepoint > 800U)
//   {
      printTimepoint = millis();
      for(copyIndex=0;copyIndex<SCOUNT;copyIndex++)
      analogBufferTemp[copyIndex]= analogBuffer[copyIndex];
      averageVoltage = getMedianNum(analogBufferTemp,SCOUNT) * (float)VREF / 4095.0; // read the analog value more stable by the median filtering algorithm, and convert to voltage value
      float compensationCoefficient=1.0+0.02*(temperature-25.0);    //temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
      float compensationVolatge=averageVoltage/compensationCoefficient;  //temperature compensation
      tdsValue=(133.42*compensationVolatge*compensationVolatge*compensationVolatge - 255.86*compensationVolatge*compensationVolatge + 857.39*compensationVolatge)*0.5; //convert voltage value to tds value

        Serial.print("voltage:");
    Serial.print(averageVoltage,2);
      Serial.print("V   ");
      Serial.print("TDS Value:");
      Serial.print(tdsValue,0);
      Serial.println("ppm");  
 //  }
long now= millis();
if (now - lastMsg > 1000){
  lastMsg = now;
  StaticJsonDocument<512>jsonDocument;

 char tempString[8];
 dtostrf(suhu, 1, 2, tempString);

 char phString[8];
 dtostrf(ph, 1, 2, phString);

 char tdsString[8];
 dtostrf(tdsValue, 1, 2, tdsString);

jsonDocument["suhu"] = suhu;
jsonDocument["ph"] = ph;
jsonDocument["tds"] = tdsValue;

  LoRaMessage = String(readingID) + "/" + String(suhu) + "&" + String(ph) + "#" + String(tdsValue)+ "!";
  //Send LoRa packet to receiver
  LoRa.beginPacket();
  LoRa.print(LoRaMessage);
  LoRa.endPacket();
  readingID++;
  }  
}
