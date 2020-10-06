#include <SoftwareSerial.h>                                   //SoftwareSerial kütüphanimizi ekliyoruz.
//#include <dht11.h>                                                            //DHT11 sensör kütüphanemizi ekliyoruz.
//#include <dht.h>
//#include <SimpleDHT.h>

//Ağ Bağlantımız
//String agAdi = "mi";                 //Ağımızın adını buraya yazıyoruz.    
//String agSifresi = "silifkeli";           //Ağımızın şifresini buraya yazıyoruz.


//Pinlerimiz
//int rxPin = 10;                                               //ESP8266 RX pini
//int txPin = 11;                                               //ESP8266 RX pini
int moto3 = 12;                                  //IN3                                            
int moto4 = 13;                                  //IN4
//int dht11Pin = 2;

int topraksensor = A0;                                               
int ldrsensor=A1;                                       

//dht11 DHT11;
//dht DHT11;
//SimpleDHT DHT11;


//String ip = "184.106.153.149";                                //Thingspeak ip adresi
//float sicaklik, nem;
float toprakdeger,ldrdeger;

//SoftwareSerial esp(rxPin, txPin);                             //Seri haberleşme pin ayarlarını yapıyoruz.




void setup() {  
  
  Serial.begin(9600);/*  Seri port ile haberleşmemizi başlatıyoruz.
  Serial.println("Started");
  esp.begin(115200);                                          //ESP8266 ile seri haberleşmeyi başlatıyoruz.
  esp.println("AT");                                          //AT komutu ile modül kontrolünü yapıyoruz.
  Serial.println("AT Yollandı");
  while(!esp.find("OK")){                                     //Modül hazır olana kadar bekliyoruz.
    esp.println("AT");
    Serial.println("ESP8266 Bulunamadı.");
  }
  Serial.println("OK Komutu Alındı");
 esp.println("AT+CWMODE=1");  
 while(!esp.find("OK")){                                     //Ayar yapılana kadar bekliyoruz.
    esp.println("AT+CWMODE=1");
    Serial.println("Ayar Yapılıyor....");
  }
   Serial.println("Client olarak ayarlandı");
   Serial.println("Aga Baglaniliyor...");
  esp.println("AT+CWJAP=\""+agAdi+"\",\""+agSifresi+"\"");    //Ağımıza bağlanıyoruz.
  while(!esp.find("OK"));                                     //Ağa bağlanana kadar bekliyoruz.
Serial.println("Aga Baglandi.");
delay(1000);
*/
  pinMode (topraksensor, INPUT);
  pinMode (ldrsensor, INPUT); 
  
  pinMode (moto3, OUTPUT);
  pinMode (moto4, OUTPUT); 
}


void loop() {
  /*
   esp.println("AT+CIPSTART=\"TCP\",\""+ip+"\",80");           //Thingspeak'e bağlanıyoruz.
  if(esp.find("Error")){                                      //Bağlantı hatası kontrolü yapıyoruz.
    Serial.println("AT+CIPSTART Error");
  }
  DHT11.read(dht11Pin);
   */toprakdeger = analogRead(topraksensor);
  
  ldrdeger = analogRead(ldrsensor);
/*  sicaklik = (float)DHT11.temperature;
  nem = (float)DHT11.humidity;  
  String veri = "GET https://api.thingspeak.com/update?api_key=IJ7F2JJY25PNF6PJ";   //Thingspeak komutu. Key kısmına kendi api keyimizi yazıyoruz.                                   //Göndereceğimiz sıcaklık değişkeni
  veri += "&field1=";
  veri += String(sicaklik);
  
  veri += "&field2=";
  veri += String(nem);                                        //Göndereceğimiz nem değişkeni
  
veri += "&field3=";
  veri += String(toprakdeger); 
  veri += "&field4=";
  veri += String(ldrdeger);
veri += "\r\n\r\n"; 
  esp.print("AT+CIPSEND=");                                   //ESP'ye göndereceğimiz veri uzunluğunu veriyoruz.
  esp.println(veri.length()+2);
  delay(2000);
  
 
   
*/ 
/*
  digitalWrite(moto3,HIGH );       // 12. pine HIGH değeri yazılı             
  digitalWrite(moto4,LOW );        // 13. pine Low değeri yazıldı
  Serial.println("hl");
  delay(8000);
  digitalWrite(moto3,LOW );       // 12. pine HIGH değeri yazılı             
  digitalWrite(moto4,HIGH );        // 13. pine Low değeri yazıldı
  Serial.println("lh");
  delay(8000);
    digitalWrite(moto3,HIGH );       // 12. pine HIGH değeri yazılı             
  digitalWrite(moto4,HIGH );        // 13. pine Low değeri yazıldı
  Serial.println("hh");
  delay(8000);
    digitalWrite(moto3,LOW );       // 12. pine HIGH değeri yazılı             
  digitalWrite(moto4,LOW );        // 13. pine Low değeri yazıldı
  Serial.println("ll");
  delay(8000);
*/
  
if ( toprakdeger<800 )     
   { 
      Serial.println("toprak ıslak");
      Serial.println(toprakdeger);    
    delay(2000);
      
     }
       else     
    { 
      Serial.println("toprak kuru");
      Serial.println(toprakdeger);    
       delay(2000);
   
     
 }
 if(toprakdeger<800){
   durdur();
    Serial.println("motor durdu");
  }
  else{
   ileri(); 
     Serial.println("motor çalıştı");
  }
  if ( ldrdeger>20 )     
    { 
      Serial.println("ısık var");
      Serial.println(ldrdeger);
      delay(2000);
   
      }
    else   
    { 
      Serial.println("ısık yok");
      Serial.println(ldrdeger);
    delay(2000);
      }
   /*
  if(esp.find(">")){                                          //ESP8266 hazır olduğunda içindeki komutlar çalışıyor.
    esp.print(veri);                                          //Veriyi gönderiyoruz.
    Serial.println(veri);
    Serial.println("Veri gonderildi.");
    delay(1000);
  }
  */
 

}
void ileri(){

  digitalWrite(moto3,HIGH );       // 12. pine HIGH değeri yazılı             
  digitalWrite(moto4,LOW );        // 13. pine Low değeri yazıldı
                 

}
void durdur(){
  
  
  digitalWrite(moto3, LOW);       // 13. pine HIGH değeri yazılı             
  digitalWrite(moto4, LOW);        // 14. pine Low değeri yazıldı
  
  
  }
