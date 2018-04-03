//smart_shepshed_software_node1_V1.1 25/01/2018
#include <Wire.h>
#include <SPI.h>
#include <RH_RF95.h>
#include <Sensirion.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>
//Initiate radio 
RH_RF95 rf95(8, 7);//Data pins for Lora32u4 Bs france board
Adafruit_BMP280 bmp;   
int nodeAddress = 1;//node adress can be any integer value, for this example its 1
const uint8_t dataPin  =  6; //sht 75 data pin
const uint8_t clockPin =  5; //sht 75 clock pin 
Sensirion tempSensor = Sensirion(dataPin, clockPin);
//Create variables to store sensor data 
float temp;
float hum;
float dew;
float bTemp;
float bPressure;
float pressure;
int rain;
int piezo;


void setup() 
{
  Serial.begin(9600); 
  
  if (!rf95.init()){
    Serial.println("init failed");
  }
  rf95.setTxPower(23, false);// Set rfm95 to maximum power
  rf95.setFrequency(868.1);// Set frequency to 868.0
  rf95.setModemConfig(RH_RF95::Bw125Cr48Sf4096);// modem config set to slow and long range
  bmp.begin(); init bmp 280
  pinMode(12,OUTPUT); pin for power to wetness sensing grid used to detect rain/moisture
}

void loop()
{ 
  uint8_t command [RH_RF95_MAX_MESSAGE_LEN];//Variable to store incoming command
  uint8_t len = sizeof(command);// length of incomming command
    if (rf95.recv(command,len)){
      int a = atoi(command);//converts uint8_t string to integer to compare with following if statment 
     if (a == nodeAddress) {//If the statement runs true the following is executed, otherwise do nothing
        tempSensor.measure(&temp, &hum, &dew);// take measurements from SHT75 sensor
        bTemp = bmp.readTemperature();//read bmp280 temp
        bPressure = bmp.readPressure();//read BMP280 pressure
        pressure = (((bPressure*100)/pow((1-(YOUR ALTITUDE HERE)/44330), 5.255))/100) *0.01;//calculation for sea leavel pressure
        digitalWrite(12,HIGH);//turn on wetness grid
        delay(100);
        rain = analogRead(A1);// read wetness grid
        digitalWrite(12,LOW) turn off wetness grid
          for (int i = 0; i < 5; i++){        // this for loop takes readings of a 20cm piezo transducer to acoustically listen out for 
             piezo = piezo + analogRead(A0);  // vibration caused by falling rain and after the for loop is finished it is divided by the 
             delay(100);                      //number of readings taken, this is currently for research purposes at the moment
          }                                   // and may be subject to change
        piezo / 5;
        String data( String(temp)+","+String(hum)+","+ String(dew)+","+String(pressure)+","+String(rain)+","+String(piezo));// put all the data into a string variable reading for us to send back to the gateway 
        int str_length=data.length()+1;
        char data_array[str_length];
        Serial.println(data);// for debugging purposes
        data.toCharArray(data_array,str_length);// convert to char array        
        rf95.send((uint8_t *)data_array, sizeof(data_array));// send data back to the gateway 
        rf95.waitPacketSent();
        piezo = 0;//reset variable back to zero
        }
      }
    }

