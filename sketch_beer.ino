


// Librerias para sensor DS18B20 
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SoftwareSerial.h>

SoftwareSerial canal_bluetooth(2,3); //Pin 2 Rx, pin 3 Tx
// DS18B20 en PIN 6 Digital
#define ONE_WIRE_BUS 6

//Relé de Estado Sólido en PIN 3 Digital (PWM)
#define RELAY_PIN 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


unsigned long time;
unsigned long timer_1 = 0;
unsigned long timer_2 = 0;
unsigned long timer_3 = 0;
unsigned long timer_4 = 0;
unsigned long timer_5 = 0;
unsigned long timer_6 = 0;
unsigned long timer_7 = 0;
unsigned long timer_8 = 0;
unsigned long timer_9 = 0;
unsigned long timer_10 = 0;

unsigned long tiempo_1 = 0;
unsigned long tiempo_2 = 0;
unsigned long tiempo_3 = 0;
unsigned long tiempo_4 = 0;
unsigned long tiempo_5 = 0;
double tiempo_restante;
double ref_tiempo;
double m;
int bandera = 1;
int bandera1 = 0;
int bandera2 = 0;
int comando;
int sp1, sp2, sp3, sp4, sp5;
int array_1[10]={1,1,1,1,1,1,1,1,1,1};
float lectura_sensor = 0;
int contador = 0;
int contador2 = 0;
int contador3 = 0;
int contador4 = 0;
int contador5 = 0;
int contador6 = 0;
//Ciclo de tiempo 1
int C1=1;
int C2=0;
int C3=0;
int C4=0;
int C5=0;
int C6=0;
//Ciclo de tiempo 2
int C7 = 1;
int C8 = 0;
int C9 = 0;
int C10 = 0;
int C11 = 0;
int C12 = 0;
//Ciclo de tiempo 3
int C13 = 1;
int C14= 0;
int C15 = 0;
int C16 = 0;
int C17 = 0;
int C18 = 0;
//Ciclo de tiempo 4
int C19 = 1;
int C20 = 0;
int C21 = 0;
int C22 = 0;
int C23 = 0;
int C24 = 0;
//Ciclo de tiempo 5
int C25 = 1;
int C26 = 0;
int C27 = 0;
int C28 = 0;
int C29 = 0;
int C30 = 0;



//Dirección para cada sensor (Se deben sacar)
DeviceAddress sensor1 = {0x28, 0xFF, 0x31, 0x26, 0xA2, 0x17, 0x05, 0x7C};
DeviceAddress sensor2 = {0x28, 0xFF, 0x5F, 0x26, 0xA2, 0x17, 0x05, 0xCF};

void setup() {
  Serial.begin(9600);
  canal_bluetooth.begin(9600); 
  pinMode(RELAY_PIN, OUTPUT);
  //digitalWrite(RELAY_PIN, LOW);
  tiempo_restante = timer_2 - timer_1;
  //Establecemos resolución de sensores

  /************************************************
   * Resolution     Increment            Time
   * 9  bit         0.5    degrees C     93.75 mSec
   * 10 bit         0.25   degrees C     187.5 mSec
   * 11 bit         0.125  degrees C     375 mSec
   * 12 bit         0.0625 degrees C     750 mSec  
  *************************************************/

  sensors.setResolution(sensor1, 12);
  sensors.setResolution(sensor2, 12);
  //digitalWrite(RELAY_PIN, HIGH);
}

void loop() {
// Sincronizando transmisión serial con interfaz Matlab
  if(bandera) {
    do{
      if(canal_bluetooth.available()>0) {
        comando = canal_bluetooth.read();
        if(comando == 95){
          bandera = 0;
          canal_bluetooth.print(135.0000,4);
          canal_bluetooth.print(" ");
          canal_bluetooth.println(135.0000,4);
          break;
        }
          delay(300);
       }
      }while(1);
       delay(300);

       // Recibir vector de valores de setpoint y tiempos configurados en la interfaz
       do{
      if(canal_bluetooth.available()>=8) {
        for(int i = 0; i<10; i++) {
          array_1[i] = canal_bluetooth.read();
          }
           
          Serial.print("Setpoint_1: ");
          Serial.println(array_1[0]);
          Serial.print("Tiempo_1: ");
          Serial.println(array_1[1]*60000);
          Serial.print("Setpoint_2: ");
          Serial.println(array_1[2]);
          Serial.print("Tiempo_2: ");
          Serial.println(array_1[3]);
          Serial.print("Setpoint_3: ");
          Serial.println(array_1[4]);
          Serial.print("Tiempo_3: ");
          Serial.println(array_1[5]);
          Serial.print("Setpoint_4: ");
          Serial.println(array_1[6]);
          Serial.print("Tiempo_4: ");
          Serial.println(array_1[7]);
          Serial.print("Setpoint_5");
          Serial.println(array_1[8]);
          Serial.print("Tiempo_5");
          Serial.println(array_1[9]); 

          Serial.println("****INICIO DE TRANSMISIÓN DE DATOS****");
          delay(300);
          break;
      }
    }while(1);

    
   } // Fin if(bandera)

 // Setpoints seteados desde la interfaz
 sp1 = array_1[0];
 sp2 = array_1[2];
 sp3 = array_1[4];
 sp4 = array_1[6];
 sp5 = array_1[8];
 
 // Tiempos seteados desde la interfaz en millisegundos 

 tiempo_1 = array_1[1]*60000; 
 tiempo_2 = array_1[3]*60000;
 tiempo_3 = array_1[5]*60000;
 tiempo_4 = array_1[7]*60000;
 tiempo_5 = array_1[9]*60000;

 Serial.print("Tiempo 1 = ");
 Serial.println(tiempo_1);
 Serial.print("Tiempo_2 = ");
 Serial.println(tiempo_2);
 Serial.print("Tiempo 3 = ");
 Serial.println(tiempo_3);
 Serial.print("Tiempo 4 = ");
 Serial.println(tiempo_4);
 Serial.print("Tiempo 5 = ");
 Serial.println(tiempo_5);
 Serial.print("sp1 : ");
 Serial.println(sp1);
 Serial.print("sp2 : ");
 Serial.println(sp2);
 Serial.print("sp3 : ");
 Serial.println(sp3);
 Serial.print("sp4 : ");
 Serial.println(sp4);
 Serial.print("sp5: ");
 Serial.println(sp5);
 delay(1000);

 // ***********************************************INICIO PRIMER CICLO DE TIEMPO*************************************************************************************************************************


do{
  sensors.requestTemperatures();
  m = sensors.getTempC(sensor1);
  ref_tiempo = tiempo_1;                               // Variable para guardar el valor del tiempo seteado en la interfaz y sirve para calcular e imprimir el tiempo restante en el bloque final del programa  
     
      if( m < sp1-4 && C1==1) {                        // C1 compara si el ultimo registro de tiempo es menor a sp1-2 
        Serial.print("Temperatura: ");
        Serial.println(m,4);                             // Ultimo registro de temperatura leido 'm'
        digitalWrite(RELAY_PIN, HIGH);
        Serial.println("Ejecuto C1");
  C2=1;
  C3=0;
  C4=0;
  C5=0;
  C6=0;
        //delay(1000);
      }
      else if( m >= sp1-4 && m < sp1 && C2 ==1) {     // C2 compara si el ultimo registro de tiempo es mayor igual a sp1-2 y menor a sp1 y si existe flanco de subida
        Serial.print("Temperatura: ");
        Serial.println(m,4);                             // Ultimo registro de temperatura leido 'm'
        digitalWrite(RELAY_PIN, LOW);
        //timer_2 = millis();                           //Referencia de tiempo
        Serial.println("Ejecuto C2");
  C1=0;
  C3=1;
  C4=0;
  C5=0;
  C6=0;
        //delay(1000);
      }
      else if( m >= sp1 && C3==1 && contador ==0) {  // C3 Si el ultimo registro de temperatura m es mayor o igual al setpoint_1, si existe flanco de subida y guarda el valor de  timer_1 para temporizar
        digitalWrite(RELAY_PIN, LOW);               
        timer_1 = millis();                            // Referencia tiempo inicial para temporizar
        contador++;                                    // Contador para que solo cumpla la condicion la primer vez que alcance el setpoint
        Serial.print("ALCANZO SET_POINT1_Temperatura: ");
        Serial.println(m,4);                                   
        Serial.println("Ejecuto C3");
  C1=0;
  C2=0;
  C4=1;
  C5=0;
  C6=0;
        //delay(1000);
      }
      else if( m >= sp1 && contador != 0 && C4==1){            // C4 compara Si el ultimo registro de temperatura m es mayor o igual al setpoint_1 y si contador es diferente de cero
        Serial.print("Temperatura: ");
        Serial.println(m,4);
        digitalWrite(RELAY_PIN, LOW);
        //timer_2 = millis();                           //Referencia de tiempo 
        Serial.println("Ejecuto C4");
  C1=0;
  C2=0;
  C3=0;
  C5=1;
  C6=0;
        //delay(1000);
      }
      else if( m < sp1 && m < sp1-2 && C5==1){      // C5 compara si el ultimo registro de tiempo es menor igual a sp1 y mayor que sp1-1 y si existe flanco bajada
        Serial.print("Temperatura: ");
        Serial.println(m);
        digitalWrite(RELAY_PIN, HIGH);
        Serial.println("Ejecuto C5");
  C1=0;
  C2=0;
  C3=0;
  C4=0;
  C6=1;
       // delay(1000);
      }
      else if( m <= sp1 && m > sp1-1 && C6==1){  // C6 compara si el ultimo registro de tiempo es menor igual a sp1-1, mayor igual a sp1-2 y si existe flanco bajada
        Serial.print("Temperatura: ");
        Serial.println(m);
        digitalWrite(RELAY_PIN, LOW);
        //timer_2 = millis();                           //Referencia de tiempo 
        Serial.println("Ejecuto C6");
  C1=0;
  C2=0;
  C3=0;
  C4=0;
  C5=1;
        //delay(1000);
      }

      // Bloque final
      timer_2 = millis();                                // Actualiza tiempo de ciclo 1, desde que el programa se encuentra ejecutandose en milisegundos
      float diferencia_tiempo = timer_2 - timer_1;       //Actualiza la diferencia de tiempo en la variable de tiempo local
      tiempo_restante = ref_tiempo - diferencia_tiempo; // Tiempo restante en milisegundos
     
      // Imprimir tiempo restante de ciclo
      Serial.print("Tiempo restante: ");
      Serial.print((tiempo_restante/60000));            
      Serial.println("minutos ");
      // enviar datos por bluetooth a interfaz de Matlab
      canal_bluetooth.print(m,4);
      canal_bluetooth.print(" ");
      canal_bluetooth.println(((tiempo_restante)/60000),4);
      delay(500);
      
}while(timer_2-timer_1 <= tiempo_1);


// ***********************************************FIN PRIMERA CICLO DE TIEMPO*************************************************************************************************************************


do{

  sensors.requestTemperatures();
  m = sensors.getTempC(sensor1);  
  ref_tiempo = tiempo_2;
  
  Serial.println("CICLO DE TIEMPO 2");
  if(m < sp2-4 && C7==1) {
    timer_4 = millis();
    timer_3 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);                             // Ultimo registro de temperatura leido 'm'
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Ejecuto C1");
  C8=1;
  C9=0;
  C10=0;
  C11=0;
  C12=0;
  //delay(1000);
   }
  else if( m >= sp2-4 && m < sp2 && C8 ==1) {     // C2 compara si el ultimo registro de tiempo es mayor igual a sp1-2 y menor a sp1 y si existe flanco de subida
     Serial.print("Temperatura: ");
     Serial.println(m);                             // Ultimo registro de temperatura leido 'm'
     digitalWrite(RELAY_PIN, LOW);
     Serial.println("Ejecuto C2");
  C7=0;
  C9=1;
  C10=0;
  C11=0;
  C12=0;
  //delay(1000);
  }
  else if( m >= sp2 && C9==1 && contador2 ==0) {  // C3 Si el ultimo registro de temperatura m es mayor o igual al setpoint_1, si existe flanco de subida y guarda el valor de  timer_1 para temporizar
    timer_4 = millis();
    timer_3 = millis();                        //   Seteo timer4 igual que timer_3 para comenzar a temporizar desde cero hasta el tiempo_2                            
    digitalWrite(RELAY_PIN, LOW);               
    contador2++;                                    // Contador para que solo cumpla la condicion la primer vez que alcance el setpoint
    Serial.print("ALCANZO SET_POINT1_Temperatura: ");
    Serial.println(m);                                   
    Serial.println("Ejecuto C3");
  C7=0;
  C8=0;
  C10=1;
  C11=0;
  C12=0;
  //delay(1000);
  }
  else if( m >= sp2 && contador2 != 0 && C10==1){            // C4 compara Si el ultimo registro de temperatura m es mayor o igual al setpoint_1 y si contador es diferente de cero
    timer_3 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Ejecuto C4");
  C7=0;
  C8=0;
  C9=0;
  C11=1;
  C12=0;
   //delay(1000);
  }
  else if( m < sp2 && m < sp2 -2 && C11==1){      // C5 compara si el ultimo registro de tiempo es menor igual a sp1 y mayor que sp1-1 y si existe flanco bajada
    timer_3 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Ejecuto C5");
  C7=0;
  C8=0;
  C9=0;
  C10=0;
  C12=1;
   //delay(1000);
  }
  else if( m <= sp2 && m > sp2-1 && C12==1){  // C6 compara si el ultimo registro de tiempo es menor igual a sp1-1, mayor igual a sp1-2 y si existe flanco bajada
    timer_3 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Ejecuto C6");
  C7=0;
  C8=0;
  C9=0;
  C10=0;
  C11=1;
   //delay(1000);
  }
  timer_3 = millis(); //Actualizo tiempo de ciclo 2
 float diferencia_tiempo = timer_3 - timer_4;
  tiempo_restante = ref_tiempo - diferencia_tiempo; // Tiempo restante en milisegundos
  // Imprimir tiempo restante de ciclo
  Serial.print("Tiempo restante: ");
  Serial.print((tiempo_restante/60000)); // Hay que cambiar el tiempo restante para que aplique para cualquier ciclo
  Serial.println("minutos ");
  // enviar datos por bluetooth a interfaz de Matlab
      canal_bluetooth.print(m,4);
      canal_bluetooth.print(" ");
      canal_bluetooth.println(((tiempo_restante)/60000),4);
      delay(500);
}while(timer_2-timer_1 > tiempo_1 && timer_3 - timer_4 <= tiempo_2);

// ***********************************************FIN SEGUNDA CONDICION DE TIEMPO*************************************************************************************************************************

do{

  sensors.requestTemperatures();
  m = sensors.getTempC(sensor1);  
  ref_tiempo = tiempo_3;
  
  Serial.println("CICLO DE TIEMPO 3");
  if(m < sp3-4 && C13==1) {
    timer_6 = millis();
    timer_5 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);                             // Ultimo registro de temperatura leido 'm'
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Ejecuto C1");
  C14=1;
  C15=0;
  C16=0;
  C17=0;
  C18=0;
  //delay(1000);
   }
  else if( m >= sp3-4 && m < sp3 && C14 ==1) {     // C2 compara si el ultimo registro de tiempo es mayor igual a sp1-2 y menor a sp1 y si existe flanco de subida
     Serial.print("Temperatura: ");
     Serial.println(m);                             // Ultimo registro de temperatura leido 'm'
     digitalWrite(RELAY_PIN, LOW);
     Serial.println("Ejecuto C2");
  C13=0;
  C15=1;
  C16=0;
  C17=0;
  C18=0;
  //delay(1000);
  }
  else if( m >= sp3 && C15==1 && contador3 ==0) {  // C3 Si el ultimo registro de temperatura m es mayor o igual al setpoint_1, si existe flanco de subida y guarda el valor de  timer_1 para temporizar
    timer_6 = millis();
    timer_5 = millis();                        //   Seteo timer4 igual que timer_3 para comenzar a temporizar desde cero hasta el tiempo_2                            
    digitalWrite(RELAY_PIN, LOW);               
    contador3++;                                    // Contador para que solo cumpla la condicion la primer vez que alcance el setpoint
    Serial.print("ALCANZO SET_POINT3_Temperatura: ");
    Serial.println(m);                                   
    Serial.println("Ejecuto C3");
  C13=0;
  C14=0;
  C16=1;
  C17=0;
  C18=0;
  //delay(1000);
  }
  else if( m >= sp3 && contador3 != 0 && C16==1){            // C4 compara Si el ultimo registro de temperatura m es mayor o igual al setpoint_1 y si contador es diferente de cero
    //timer_4 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Ejecuto C4");
  C13=0;
  C14=0;
  C15=0;
  C17=1;
  C18=0;
   //delay(1000);
  }
  else if( m < sp3 && m < sp3 -2 && C17==1){      // C5 compara si el ultimo registro de tiempo es menor igual a sp1 y mayor que sp1-1 y si existe flanco bajada
    //timer_3 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Ejecuto C5");
  C13=0;
  C14=0;
  C15=0;
  C16=0;
  C18=1;
   //delay(1000);
  }
  else if( m <= sp3 && m > sp3-1 && C18==1){  // C6 compara si el ultimo registro de tiempo es menor igual a sp1-1, mayor igual a sp1-2 y si existe flanco bajada
   // timer_3 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Ejecuto C6");
  C13=0;
  C14=0;
  C15=0;
  C16=0;
  C17=1;
   //delay(1000);
  }
  timer_5 = millis(); //Actualizo tiempo de ciclo 2
 float diferencia_tiempo = timer_5 - timer_6;
  tiempo_restante = ref_tiempo - diferencia_tiempo; // Tiempo restante en milisegundos
  // Imprimir tiempo restante de ciclo
  Serial.print("Tiempo restante: ");
  Serial.print((tiempo_restante/60000)); // Hay que cambiar el tiempo restante para que aplique para cualquier ciclo
  Serial.println("minutos ");
  // enviar datos por bluetooth a interfaz de Matlab
      canal_bluetooth.print(m,4);
      canal_bluetooth.print(" ");
      canal_bluetooth.println(((tiempo_restante)/60000),4);
      delay(500);
}while(timer_3-timer_4 > tiempo_2 && timer_5 - timer_6 <= tiempo_3);

// ***********************************************FIN TERCERA CONDICION DE TIEMPO*************************************************************************************************************************

do{

  sensors.requestTemperatures();
  m = sensors.getTempC(sensor1);
  ref_tiempo = tiempo_4;
  
  Serial.println("CICLO DE TIEMPO 4");
  if(m < sp4-4 && C19==1) {
    timer_8 = millis();
    timer_7 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);                             // Ultimo registro de temperatura leido 'm'
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Ejecuto C1");
  C20=1;
  C21=0;
  C22=0;
  C23=0;
  C24=0;
  //delay(1000);
   }
  else if( m >= sp4-4 && m < sp4 && C20 ==1) {     // C2 compara si el ultimo registro de tiempo es mayor igual a sp1-2 y menor a sp1 y si existe flanco de subida
     Serial.print("Temperatura: ");
     Serial.println(m);                             // Ultimo registro de temperatura leido 'm'
     digitalWrite(RELAY_PIN, LOW);
     Serial.println("Ejecuto C2");
  C19=0;
  C21=1;
  C22=0;
  C23=0;
  C24=0;
  //delay(1000);
  }
  else if( m >= sp4 && C21==1 && contador4 ==0) {  // C3 Si el ultimo registro de temperatura m es mayor o igual al setpoint_1, si existe flanco de subida y guarda el valor de  timer_1 para temporizar
    timer_8 = millis();
    timer_7 = millis();                        //   Seteo timer4 igual que timer_3 para comenzar a temporizar desde cero hasta el tiempo_2                            
    digitalWrite(RELAY_PIN, LOW);               
    contador4++;                                    // Contador para que solo cumpla la condicion la primer vez que alcance el setpoint
    Serial.print("ALCANZO SET_POINT1_Temperatura: ");
    Serial.println(m);                                   
    Serial.println("Ejecuto C3");
  C19=0;
  C20=0;
  C22=1;
  C23=0;
  C24=0;
  //delay(1000);
  }
  else if( m >= sp4 && contador4 != 0 && C22==1){            // C4 compara Si el ultimo registro de temperatura m es mayor o igual al setpoint_1 y si contador es diferente de cero
    
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Ejecuto C4");
  C19=0;
  C20=0;
  C21=0;
  C23=1;
  C24=0;
   //delay(1000);
  }
  else if( m < sp4 && m < sp4 -2 && C23==1){      // C5 compara si el ultimo registro de tiempo es menor igual a sp1 y mayor que sp1-1 y si existe flanco bajada
    
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Ejecuto C5");
  C19=0;
  C20=0;
  C21=0;
  C22=0;
  C24=1;
   //delay(1000);
  }
  else if( m <= sp4 && m > sp4-1 && C24==1){  // C6 compara si el ultimo registro de tiempo es menor igual a sp1-1, mayor igual a sp1-2 y si existe flanco bajada
    
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Ejecuto C6");
  C19=0;
  C20=0;
  C21=0;
  C22=0;
  C23=1;
   //delay(1000);
  }
  timer_7 = millis(); //Actualizo tiempo de ciclo 2
 float diferencia_tiempo = timer_7 - timer_8;
  tiempo_restante = ref_tiempo - diferencia_tiempo; // Tiempo restante en milisegundos
  // Imprimir tiempo restante de ciclo
  Serial.print("Tiempo restante: ");
  Serial.print((tiempo_restante/60000)); // Hay que cambiar el tiempo restante para que aplique para cualquier ciclo
  Serial.println("minutos ");
  // enviar datos por bluetooth a interfaz de Matlab
      canal_bluetooth.print(m,4);
      canal_bluetooth.print(" ");
      canal_bluetooth.println(((tiempo_restante)/60000),4);
      delay(500);
}while(timer_5-timer_6 > tiempo_3 && timer_7 - timer_8 <= tiempo_4);

// ***********************************************FIN CUARTA CONDICION DE TIEMPO*************************************************************************************************************************


do{

  sensors.requestTemperatures();
  m = sensors.getTempC(sensor1);
  ref_tiempo = tiempo_5;
  
  Serial.println("CICLO DE TIEMPO 5");
  if(m < sp5-4 && C25==1) {
    timer_10 = millis();
    timer_9 = millis();
    Serial.print("Temperatura: ");
    Serial.println(m);                             // Ultimo registro de temperatura leido 'm'
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Ejecuto C1");
  C26=1;
  C27=0;
  C28=0;
  C29=0;
  C30=0;
  //delay(1000);
   }
  else if( m >= sp5-4 && m < sp5 && C26 ==1) {     // C2 compara si el ultimo registro de tiempo es mayor igual a sp1-2 y menor a sp1 y si existe flanco de subida
     Serial.print("Temperatura: ");
     Serial.println(m);                             // Ultimo registro de temperatura leido 'm'
     digitalWrite(RELAY_PIN, LOW);
     Serial.println("Ejecuto C2");
  C25=0;
  C27=1;
  C28=0;
  C29=0;
  C30=0;
  //delay(1000);
  }
  else if( m >= sp5 && C27==1 && contador5 ==0) {  // C3 Si el ultimo registro de temperatura m es mayor o igual al setpoint_1, si existe flanco de subida y guarda el valor de  timer_1 para temporizar
    timer_10 = millis();
    timer_9 = millis();                        //   Seteo timer4 igual que timer_3 para comenzar a temporizar desde cero hasta el tiempo_2                            
    digitalWrite(RELAY_PIN, LOW);               
    contador5++;                                    // Contador para que solo cumpla la condicion la primer vez que alcance el setpoint
    Serial.print("ALCANZO SET_POINT1_Temperatura: ");
    Serial.println(m);                                   
    Serial.println("Ejecuto C3");
  C25=0;
  C26=0;
  C28=1;
  C29=0;
  C30=0;
  //delay(1000);
  }
  else if( m >= sp5 && contador5 != 0 && C28==1){            // C4 compara Si el ultimo registro de temperatura m es mayor o igual al setpoint_1 y si contador es diferente de cero
    
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Ejecuto C4");
  C25=0;
  C26=0;
  C27=0;
  C29=1;
  C30=0;
   //delay(1000);
  }
  else if( m < sp5 && m < sp5 -2 && C29==1){      // C5 compara si el ultimo registro de tiempo es menor igual a sp1 y mayor que sp1-1 y si existe flanco bajada
    
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, HIGH);
    Serial.println("Ejecuto C5");
  C25=0;
  C26=0;
  C27=0;
  C28=0;
  C30=1;
   //delay(1000);
  }
  else if( m <= sp5 && m > sp5-1 && C30==1){  // C6 compara si el ultimo registro de tiempo es menor igual a sp1-1, mayor igual a sp1-2 y si existe flanco bajada
   
    Serial.print("Temperatura: ");
    Serial.println(m);
    digitalWrite(RELAY_PIN, LOW);
    Serial.println("Ejecuto C6");
  C25=0;
  C26=0;
  C27=0;
  C28=0;
  C29=1;
   //delay(1000);
  }
  timer_9 = millis(); //Actualizo tiempo de ciclo 2
 float diferencia_tiempo = timer_9 - timer_10;
  tiempo_restante = ref_tiempo - diferencia_tiempo; // Tiempo restante en milisegundos
  // Imprimir tiempo restante de ciclo
  Serial.print("Tiempo restante: ");
  Serial.print((tiempo_restante/60000)); // Hay que cambiar el tiempo restante para que aplique para cualquier ciclo
  Serial.println("minutos ");
  // enviar datos por bluetooth a interfaz de Matlab
      canal_bluetooth.print(m,4);
      canal_bluetooth.print(" ");
      canal_bluetooth.println(((tiempo_restante)/60000),4);
      delay(500);
}while(timer_7-timer_8 > tiempo_4 && timer_9 - timer_10 <= tiempo_5);

//************************* FIN DEL PROCESO DE COCCIÓN MALTA*****************************************************************************************************************************

do{
  for (int i=0; i!=20; i++){
    Serial.println("**********FIN DE PRODUCCION, FILTRAR Y AGRAGAR LÚPULO*****************");
    delay(300);
  }
  bandera1 = true;
  if (bandera1) {
    break;
  }

}while(timer_9-timer_10 > tiempo_5);


// Sincronizando transmisión serial con interfaz Matlab para iniciar ciclo lupulado lUPULADO
  if(bandera1) {
    do{
      Serial.println("Esperando sincronización con Interfaz para iniciar ciclo de lupulado...");
      if(canal_bluetooth.available()>0) {
        comando = canal_bluetooth.read();
        if(comando == 96){
          bandera1 = 0;
          //bandera2 = true;
          canal_bluetooth.print(136.0000,4);
          canal_bluetooth.print(" ");
          canal_bluetooth.println(136.0000,4);
          Serial.println("*********************Sincronizado, iniciando ciclo lupulado***********************");
          timer_1 = millis();
          timer_2 = millis();
          break;
        }
          delay(300);
       }
      }while(1);
       delay(400);
  
  }//Fin if(bandera1)

 // ***********************************************INICIO CICLO DE LUPULADO*************************************************************************************************************************


do{
  Serial.println("************************************INICIO CICLO DE LUPULADO*****************************************************");
  sensors.requestTemperatures();
  m = sensors.getTempC(sensor1);
  sp1 = 95;                           // Setpoint ciclo de lupulado
  
  ref_tiempo = 3600000;               // Variable para guardar el valor del tiempo en milisegundos 3600000ms = 60min
      if( m <= sp1 && contador6 ==0) { 
        Serial.print("Temperatura: ");
        Serial.println(m,4);                             // Ultimo registro de temperatura leido 'm'
        digitalWrite(RELAY_PIN, HIGH);
        Serial.println("Relay ON");
        timer_1 = millis();                //Seteo el timer_1 
        contador6++;                       // Contador para evitar que vuelva a entrar a esta condicion y cometer el error de setear nuevamente a timer_1
        
        //delay(1000);
      }
      
      else {     
        if ( m<= sp1 && contador6 !=0) {
          Serial.println("Temperatura: ");
          Serial.println(m,4);
          digitalWrite(RELAY_PIN,HIGH);
          Serial.print("Relay ON");
        }
        else if (m>sp1) {
           Serial.print("Temperatura excedió 95 grados, Relay OFF ");
           Serial.println(m,4);                             // Ultimo registro de temperatura leido 'm'
           digitalWrite(RELAY_PIN, LOW);
           Serial.println("Relay OFF");
 
        //delay(1000);
      }
      }
      

      // Bloque final
      timer_2 = millis();                                // Actualiza tiempo de ciclo 1, desde que el programa se encuentra ejecutandose en milisegundos
      float diferencia_tiempo = timer_2 - timer_1;       //Actualiza la diferencia de tiempo en la variable de tiempo local
      tiempo_restante = ref_tiempo - diferencia_tiempo; // Tiempo restante en milisegundos
     
      // Imprimir tiempo restante de ciclo
      Serial.print("Tiempo restante: ");
      Serial.print((tiempo_restante/60000));            
      Serial.println("minutos ");
      // enviar datos por bluetooth a interfaz de Matlab
      canal_bluetooth.print(m,4);
      canal_bluetooth.print(" ");
      canal_bluetooth.println(((tiempo_restante)/60000),4);
      delay(500);
      
}while(timer_2-timer_1 <= ref_tiempo);

}
// ***********************************************FINAL DE PRODUCCIÓN*************************************************************************************************************************

