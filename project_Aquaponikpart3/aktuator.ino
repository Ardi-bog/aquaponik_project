void aktuator(){


//   if(hari == "Minggu" && jam >= Aa && jam < Bb){
//     digitalWrite(pompa_akuarium, LOW); // pompa akuarium hidup saat jam menunjukkan variabel Aa  hingga Variabel Bb
//     Serial.println("Power pompa_pupuk_output OFF  ");
//     Serial.print("Fish feeder OFF  ");
//     Serial.print("Power pompa pupuk OFF  ");
//     Serial.println("Power Pompa Akuarium ON  ");
//    }
//   else if(hari == "Senin" && jam >= Aa && jam < Bb){ 
//     digitalWrite(pompa_akuarium, LOW); // pompa akuarium hidup saat jam menunjukkan variabel Aa  hingga Variabel Bb
//     Serial.println("Power pompa_pupuk_output OFF  ");
//     Serial.print("Fish feeder OFF  ");
//     Serial.print("Power pompa pupuk OFF  ");
//     Serial.println("Power Pompa Akuarium ON  ");
//    }
//   else if(hari == "Selasa" && jam >= Aa && jam < Bb){
//     digitalWrite(pompa_akuarium, LOW); // pompa akuarium hidup saat jam menunjukkan variabel Aa  hingga Variabel Bb
//     Serial.println("Power pompa_pupuk_output OFF  ");
//     Serial.print("Fish feeder OFF  ");
//     Serial.print("Power pompa pupuk OFF  ");
//     Serial.println("Power Pompa Akuarium ON  ");
//    }
//   else if(hari == "Rabu" && jam >= Aa && jam < Bb){
//     digitalWrite(pompa_akuarium, LOW); // pompa akuarium hidup saat jam menunjukkan variabel Aa  hingga Variabel Bb
//     Serial.println("Power pompa_pupuk_output OFF  ");
//     Serial.print("Fish feeder OFF  ");
//     Serial.print("Power pompa pupuk OFF  ");
//     Serial.println("Power Pompa Akuarium ON  ");
//    }
//   else if(hari == "Kamis" && jam >= Aa && jam < Bb){
//     digitalWrite(pompa_akuarium, LOW); // pompa akuarium hidup saat jam menunjukkan variabel Aa  hingga Variabel Bb
//     Serial.println("Power pompa_pupuk_output OFF  ");
//     Serial.print("Fish feeder OFF  ");
//     Serial.print("Power pompa pupuk OFF  ");
//     Serial.println("Power Pompa Akuarium ON  ");
//    }
//   else if(hari == "Jumat" && jam >= Aa && jam < Bb){
//     digitalWrite(pompa_akuarium, LOW); // pompa akuarium hidup saat jam menunjukkan variabel Aa  hingga Variabel Bb
//     Serial.println("Power pompa_pupuk_output OFF  ");
//     Serial.print("Fish feeder OFF  ");
//     Serial.print("Power pompa pupuk OFF  ");
//     Serial.println("Power Pompa Akuarium ON  ");
//    }
//   else if(hari == "Sabtu" && jam >= Aa && jam < Bb){
//     digitalWrite(pompa_akuarium, LOW); // pompa akuarium hidup saat jam menunjukkan variabel Aa  hingga Variabel Bb
//     Serial.println("Power pompa_pupuk_output OFF  ");
//     Serial.print("Fish feeder OFF  ");
//     Serial.print("Power pompa pupuk OFF  ");
//     Serial.println("Power Pompa Akuarium ON  ");
//    }
  if ( hari == "Senin" && jam == Cc && menit >= Dd && menit <= Ee) {
     digitalWrite(pompa_pupuk, LOW); // pompa pupuk hidup saat jam menunjukkan Variabel Cc pada menit Variabel Dd sampai Ee
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder OFF  ");
     Serial.print("Power pompa pupuk ON  ");
     Serial.println("Power Pompa Akuarium OFF  ");
  } else if (hari == "Rabu" && jam == Cc && menit >= Dd && menit <= Ee){
     digitalWrite(pompa_pupuk_output, LOW); // pompa_pupuk_output hidup saat jam menunjukkan Variabel Cc pada menit Variabel Dd sampai Ee
     Serial.println("Power pompa_pupuk_output ON  ");
     Serial.print("Fish feeder OFF  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
    }else if (hari == "Sabtu" && jam == Cc && menit >= Dd && menit <= Ee){
     digitalWrite(pompa_pupuk_output, LOW); // pompa_pupuk_output hidup saat jam menunjukkan Variabel Cc pada menit Variabel Dd sampai Ee
     Serial.println("Power pompa_pupuk_output ON  ");
     Serial.print("Fish feeder OFF  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Senin" && jam == Ff && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Senin" && jam == Gg && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Selasa" && jam == Ff && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Selasa" && jam == Gg && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Rabu" && jam == Ff && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Rabu" && jam == Ff && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Kamis" && jam == Ff && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Kamis" && jam == Gg && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Jumat" && jam == Ff && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Jumat" && jam == Gg && menit >= Hh && menit <= Ii){
         myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Sabtu" && jam == Ff && menit >= Hh && menit <= Ii){
        myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Sabtu" && jam == Gg && menit >= Hh && menit <= Ii){
        myservo.write(pos); // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Minggu" && jam == Ff && menit >= Hh && menit <= Ii){
        myservo.write(pos);  // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
   else if (hari == "Minggu" && jam == Gg && menit >= Hh && menit <= Ii){
          myservo.write(pos);  // fish feeder hidup saat jam menunjukkan Variabel Ff pada menit Variabel Hh sampai Ii
     Serial.println("Power pompa_pupuk_output OFF  ");
     Serial.print("Fish feeder ON  ");
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power Pompa Akuarium OFF  ");
   }
      else{                                      //semua aktuator dalam keadaan mati
        myservo.write(pos1);
     Serial.println("Fish feeder OFF  ");
     digitalWrite(pompa_pupuk, HIGH);   
     digitalWrite(pompa_pupuk_output, HIGH); 
     Serial.print("Power pompa pupuk OFF  ");
     Serial.println("Power pompa_pupuk_output OFF  ");
     
  }
}
