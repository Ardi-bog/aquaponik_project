void realtimeclock(){ 
  rtcGet();
  Serial.println(" ----------------------------------------------------------------- ");  
  Serial.print(String() + hari + ", " + tanggal + "-" + bulan + "-" + tahun);
  Serial.print("  ");
  Serial.println(String() + jam + ":" + menit + ":" + detik);
}
