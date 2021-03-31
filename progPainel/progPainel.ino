#include "Nextion.h"

const float pi = 3.14159;

NexPicture picSpd = NexPicture(1,2,"p1");
NexPicture picRpm = NexPicture(1,3,"p2");
NexPicture picFuel = NexPicture(1,4,"p3");
NexPicture picAlarm1 = NexPicture(1,9,"p7");
NexPicture picAlarm2 = NexPicture(1,10,"p8");
NexPicture picAlarm3 = NexPicture(1,11,"p9");

NexText txtSpd = NexText(1, 6, "t0");
NexText txtRpm = NexText(1, 8, "t1");

int vel;
int id_PicVel;
int divi;
unsigned int pot;

char txt[10];
char txt1[10];

//DATESCAR
unsigned int R_roda = 10; //EM METROS

//FOR SPEEDCAR METHOD
unsigned int auxSpeed = 0;        //VARIÁVEL PARA AUXILIAR NA MEDIÇÃO DA VELOCIDADE
unsigned int pinSensor_speed = 1; //PINO DO SENSOR DE VELOCIDADE
unsigned int spCar;             //VELOCIDADE DO VEÍCULO
unsigned long timerSp;
unsigned int pulsosSp;

//FOR RPMCAR METHOD
unsigned int pinSensor_rpm = 2;
unsigned int rpCar;
unsigned int pulsosRpm;
unsigned long timerRpm;

//FOR FUEL METHOD
unsigned int pinSensor_fuel = 3,
             fuelCar;

//RENDER DISPLAY IMAGES ID
int imgMinSpd = 1,
    imgMaxSpd = 19,
    imgMinRpm = 20,
    imgMaxRpm = 25,
    imgMinFuel = 27,
    imgMaxFuel = 29,
    imgAlarmFull_1 = 30,
    imgAlarm1Null_1 = 31,
    imgAlarmFull_2 = 32,
    imgAlarmNull_2 = 33,
    imgAlarmFull_3 = 34,
    imgAlarmNull_3 = 35;

int imgSpd,
    imgRpm;


void setup() {
  Serial.begin(9600);
  nexInit();

  pinMode(pinSensor_speed, INPUT);
  pinMode(pinSensor_rpm, INPUT);
  pinMode(pinSensor_fuel, INPUT);
  
  attachInterrupt(digitalPinToInterrupt(pinSensor_speed), setPulsosSp, FALLING);
  attachInterrupt(digitalPinToInterrupt(pinSensor_rpm), setPulsosRpm, FALLING);
}

void loop() {
  renderSpeedCar();
  renderRpmCar();
  renderFuelCar();
  renderAlarmCar();
}

void setPulsosSp(){
  pulsosSp++;
}
void setPulsosRpm(){
  pulsosRpm++;
}

unsigned int getSpeedCar(){
  if(millis() - timerSp >= 500){
   detachInterrupt(digitalPinToInterrupt(pinSensor_speed)); //Desliga a interrupção externa para não somar os pulsos várias vezes enquanto faz o cálculo.
   pulsosSp = 0;
   timerSp = millis();
   spCar = (2*pi*R_roda/4)*pulsosSp*(3.6)*2;   //...(converte para km/h)*1-(tempo em segundos)
   //attachInterrupt(digitalPinToInterrupt(pinSensor_speed), pulsosSp, FALLING); //Ativa novamente
  }
  return (unsigned int)spCar;
}

unsigned int getRpmCar(){
  if(millis() - timerRpm >= 500){
   detachInterrupt(digitalPinToInterrupt(pinSensor_rpm)); //Desliga a interrupção externa para não somar os pulsos várias vezes enquanto faz o cálculo.
   pulsosRpm = 0;
   timerRpm = millis();
   rpCar = pulsosRpm*60*2; //*60 - converte para RPM; * 2 - é 1/tempo em segundos
   //attachInterrupt(digitalPinToInterrupt(pinSensor_rpm), pulsosRpm, FALLING); //Ativa novamente
  }
  return rpCar;
}

unsigned int getFuelCar(){
  if(digitalRead(pinSensor_fuel)) fuelCar = 1; //Tanque cheio 
  else fuelCar = 0; //Tanque vazio

  return fuelCar;
}

//PARTE DE RENDERIZAÇÃO DO DISPLAY
void renderSpeedCar(){
  imgSpd = map(getSpeedCar(), imgMinSpd, imgMaxSpd, 0, 50); //A imagen renderizada é proporcional a velocidade
  memset(txt, 0, sizeof(txt));
  itoa(getSpeedCar(), txt, 10);
  picSpd.setPic(imgSpd);
  txtSpd.setText(txt);
}

void renderRpmCar(){
  imgRpm = map(getRpmCar(), imgMinRpm, imgMaxRpm, 0, 180); //A imagen renderizada é proporcional ao rpm do motor
  memset(txt1, 0, sizeof(txt1));
  itoa(getSpeedCar(), txt1, 10);
  picRpm.setPic(imgSpd);
  txtRpm.setText(txt1);
}

void renderFuelCar(){
  if(getFuelCar() == 1) picFuel.setPic(imgMaxFuel);
  else picFuel.setPic(imgMinFuel);
}

void renderAlarmCar(){
  
}
