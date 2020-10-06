#include <SoftwareSerial.h>
SoftwareSerial gsm(2, 3);
String smsMetni = "";
char gelen;
//---------------------------------------------------------------------
int toprak = 0;
int referans = 0;
//int isi = 0;
int sicaklik = 0;

int nem = 0;
double bas = 0;
//---------------------------------------------------------------------

#define LED_PIN 12
#define ISIK_PIN 11
#define BEKLE 3

void SMSgonder(String mesaj) {
  gsm.print("AT+CMGF=1\r");
  delay(100);
  gsm.println("AT+CMGS=\"+905426051123\"");// telefon numarasi degistir
  delay(100);
  gsm.println(mesaj);
  delay(100);
  gsm.println((char)26);
  delay(100);
  gsm.println();
  delay(100);
  gsm.println("AT+CMGD=1,4");
  delay(100);
  gsm.println("AT+CMGF=1");
  delay(100);
  gsm.println("AT+CNMI=1,2,0,0,0");
  delay(200);
  smsMetni = "";
}

/*
void smscoz() {
  while (gsm.available()) {
    delay(BEKLE);
    gelen = gsm.read();
      //-----------------------------------
    if (gelen == '#') {
      if (gsm.available()) {
        delay(BEKLE);
        gelen = gsm.read();
        if (gelen == 'L') {
          if (gsm.available()) {
            delay(BEKLE);
            gelen = gsm.read();
            if (gelen == 'E') {
              if (gsm.available()) {
                delay(BEKLE);
                gelen = gsm.read();
                if (gelen == 'D') {
                  if (gsm.available()) {
                    delay(BEKLE);
                    gelen = gsm.read();
                    if (gelen == 'a') {
                      digitalWrite(LED_PIN, HIGH);
                      SMSgonder("LED acildi");
                    }
                    else if (gelen == 'k') {
                      digitalWrite(LED_PIN, LOW);
                      SMSgonder("LED kapatildi");
                    }
                  }
                }
              }
            }
          }
        }
        else if (gelen == 'I') {
          if (gsm.available()) {
            delay(BEKLE);
            gelen = gsm.read();
            if (gelen == 'S') {
              if (gsm.available()) {
                delay(BEKLE);
                gelen = gsm.read();
                if (gelen == 'I') {
                  if (gsm.available()) {
                    delay(BEKLE);
                    gelen = gsm.read();
                    if (gelen == 'K') {
                      if (gsm.available()) {
                        delay(BEKLE);
                        gelen = gsm.read();
                        if (gelen == 'a') {
                          digitalWrite(ISIK_PIN, LOW);
                          smsMetni = "Isik acildi";
                          SMSgonder(smsMetni);
                        }
                        else if (gelen == 'k') {
                          digitalWrite(ISIK_PIN, HIGH);
                          smsMetni = "Isik kapatildi";
                          SMSgonder(smsMetni);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}*/
void smscoz() {

      while (gsm.available()) {
        delay(BEKLE);
        gelen = gsm.read();
      //-----------------------------------
    
        if (gelen == '#') {
          if (gsm.available()) {
            delay(BEKLE);
            gelen = gsm.read();
            if (gelen == 'F') {

              if (gsm.available()) {
                delay(BEKLE);
    
                gelen = gsm.read();
                if (gelen == 'A') {
  
                  if (gsm.available()) {
                    delay(BEKLE);
                    gelen = gsm.read();
                    if (gelen == 'R') {
 
                      if (gsm.available()) {
                        delay(BEKLE);
    
                        gelen = gsm.read();
                        if (gelen == 'U') {

                          if (gsm.available()) {
                            delay(BEKLE);
                            gelen = gsm.read();
                            if (gelen == 'K') {
 

                              if (gsm.available()) {
                                delay(BEKLE);
    
   
   // lcd.println("Faruk >>> Rapor ");
    
                                gsm.print("AT+CMGF=1\r");
                                delay(100);
                                gsm.println("AT+CMGS=\"+905076258682\"");// telefon numarasi degistir
                                
                                delay(100);
                                gsm.println("Merhaba Faruk Sizin icin Sistem Sonuclari");
                                delay(100);
                                gsm.print("RUZGAR......"); /*gsm.print(ruz);*/ gsm.println(" m/s");
                                delay(100);
                                gsm.print("Toprak......"); gsm.print(toprak); gsm.println(" %");
                                delay(100);
                                gsm.print("BASINC......");/* gsm.print(bas);*/ gsm.println(" hPa");
                                delay(100);
                                gsm.print("ISI........."); /*gsm.print(sicaklik);*/ gsm.println(" C");
                                delay(100);
                                gsm.print("Nem........."); gsm.print(nem); gsm.println(" %");
                                gsm.println((char)26);
                                delay(100);
                                gsm.println();
                                delay(100);
                                gsm.println("AT+CMGD=1,4");
                                delay(100);
                                gsm.println("AT+CMGF=1");
                                delay(100);
                                gsm.println("AT+CNMI=1,2,0,0,0");
                                delay(200);
                                smsMetni = "";
                              }  }}}}}}}}}}}
                              
     else if (gelen == '*') {
      if (gsm.available()) {
        delay(BEKLE);
        gelen = gsm.read();
        if (gelen == 'L') {
          if (gsm.available()) {
            delay(BEKLE);
            gelen = gsm.read();
            if (gelen == 'E') {
              if (gsm.available()) {
                delay(BEKLE);
                gelen = gsm.read();
                if (gelen == 'D') {
                  if (gsm.available()) {
                    delay(BEKLE);
                    gelen = gsm.read();
                    if (gelen == 'a') {
                      digitalWrite(LED_PIN, HIGH);
                      SMSgonder("LED acildi");
                    }
                    else if (gelen == 'k') {
                      digitalWrite(LED_PIN, LOW);
                      SMSgonder("LED kapatildi");
                    }
                  }
                }
              }
            }
          }
        }
             else if (gelen == 'M') {
          if (gsm.available()) {
            delay(BEKLE);
            gelen = gsm.read();
            if (gelen == 'O') {
              if (gsm.available()) {
                delay(BEKLE);
                gelen = gsm.read();
                if (gelen == 'T') {
                  if (gsm.available()) {
                    delay(BEKLE);
                    gelen = gsm.read();
                    if (gelen == 'O') {
                      if (gsm.available()) {
                        delay(BEKLE);
                        gelen = gsm.read(); 
                        if (gelen == 'R') {
                      if (gsm.available()) {
                        delay(BEKLE);
                        if (gelen == 'a') {
                          digitalWrite(ISIK_PIN, LOW);
                          smsMetni = "Motor acildi";
                          SMSgonder(smsMetni);
                        }
                        else if (gelen == 'k') {
                          digitalWrite(ISIK_PIN, HIGH);
                          smsMetni = "Motor kapatildi";
                          SMSgonder(smsMetni);
                        }
                      }
                     }
                   }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  //--------------------------------------------------------------------------------------------------------------------------
 else if (gelen == '+') {
          if (gsm.available()) {
            delay(BEKLE);
            gelen = gsm.read();
            if (gelen == 'B') {
              if (gsm.available()) {
                delay(BEKLE);
    
                gelen = gsm.read();
                if (gelen == 'A') {
   
                  if (gsm.available()) {
                    delay(BEKLE);
                    gelen = gsm.read();
                    if (gelen == 'B') {
  
                      if (gsm.available()) {
                        delay(BEKLE);
    
                        gelen = gsm.read();
                        if (gelen == 'A') {
   
                          if (gsm.available()) {
                            delay(BEKLE);
                            gelen = gsm.read();
                            if (gelen == 'M') {
 
          if (gsm.available()) {
                                delay(BEKLE);
    
   // lcd.println("Hocam >>>> Rapor");

                                       
    
             gsm.print("AT+CMGF=1\r");
             delay(100);
             gsm.println("AT+CMGS=\"+905426051123\"");// telefon numarasi degistir
                delay(100);
                                gsm.print("RUZGAR......"); /*gsm.print(ruz);*/ gsm.println(" m/s");
                                delay(100);
                                gsm.print("Toprak......"); gsm.print(toprak); gsm.println(" %");
                                delay(100);
                                gsm.print("BASINC......");/* gsm.print(bas);*/ gsm.println(" hPa");
                                delay(100);
                                gsm.print("ISI........."); /*gsm.print(sicaklik);*/ gsm.println(" C");
                                delay(100);
                                gsm.print("Nem........."); gsm.print(nem); gsm.println(" %");
                                gsm.println((char)26);
            delay(100);
            gsm.println();
            delay(100);
            gsm.println("AT+CMGD=1,4");
            delay(100);
            gsm.println("AT+CMGF=1");
            delay(100);
            gsm.println("AT+CNMI=1,2,0,0,0");
            delay(200);
            smsMetni = "";
                              } } } }}}}}}}}}
                              }}
void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(ISIK_PIN, OUTPUT);
  digitalWrite(ISIK_PIN, HIGH);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  delay(3000);
  digitalWrite(7, LOW);
  gsm.begin(9600);
  delay(2000);
  gsm.println("AT+CMGF=1");
  delay(100);
  gsm.println("AT+CNMI=1,2,0,0,0");
  delay(100);
  gsm.println("AT+CMGD=1,4");
  delay(1000);
  SMSgonder("Sistem ile baglanti kuruldu");
  gsm.flush();
  delay(100);
}

void loop() {
   int topraksensoru = analogRead(A1);
    toprak = map(abs(topraksensoru), 0, 1024, 99, 0);
      for (int sayim = 0; sayim < 40; sayim++)
    {
      smscoz();
      //    Serial.println(sayim);
      //    Serial.print("Temperature = ");
      //    Serial.print(bmp.readTemperature());
      //    Serial.println(" Celsius");
      //
      //    Serial.print("Pressure = ");
      //    Serial.print(bmp.readPressure());
      //    Serial.println(" Pascal");
      
      int topraksensoru = analogRead(A1);
      toprak = map(abs(topraksensoru), 0, 1024, 99, 0);
   


      delay(100);
    }
  smscoz();
  delay(1);
}
