
#include <TMCStepper.h>


//#define DIAG_PIN_2         19          // STALL motor 2
#define EN_PIN_2           2          // Enable
#define DIR_PIN_2          16          // Direction
#define STEP_PIN_2         17          // Step
#define SERIAL_PORT_2      Serial2    // TMC2208/TMC2224 HardwareSerial port
#define DRIVER_ADDRESS_2   0b00       // TMC2209 Driver address according to MS1 and MS2
#define R_SENSE_2          0.11f      // E_SENSE for current calc.  
#define STALL_VALUE_2      2          // [0..255]
#define RX2                19
#define TX2                21
#define STALL_VALUE        2          // [0..255]
#define gconf              0x00

//hw_timer_t * timer1 = NULL;
TMC2209Stepper driver(&SERIAL_PORT_2, R_SENSE_2 , DRIVER_ADDRESS_2 );

//void IRAM_ATTR onTimer() {
//
//  digitalWrite(STEP_PIN_2, !digitalRead(STEP_PIN_2));
//} 



void setup() {
  Serial.begin(115200);         // Init serial port and set baudrate
  while(!Serial);               // Wait for serial port to connect
  Serial.println("\nStart...");
  SERIAL_PORT_2.begin(115200, SERIAL_8N1, RX2, TX2);
  
  pinMode(EN_PIN_2, OUTPUT);
  pinMode(STEP_PIN_2, OUTPUT);
  pinMode(DIR_PIN_2, OUTPUT);
  digitalWrite(EN_PIN_2, LOW);      // Enable driver in hardware
  
  driver.begin();
  driver.toff(4);
  driver.blank_time(24);
  driver.rms_current(500); 
  driver.microsteps(16);
  driver.TCOOLTHRS(0xFFFFF); // 20bit max
  driver.semin(0);
  driver.semax(2);
  driver.shaft(false);
  driver.sedn(0b01);
  driver.SGTHRS(STALL_VALUE);
  Serial.println(driver.version(), HEX);
  driver.internal_Rsense(true);

  //activate_interrupt();


}

//void loop() {
// static uint32_t last_time=0;
// uint32_t ms = millis();
// if((ms-last_time) > 100) { //run every 0.1s
//    last_time = ms;
//
//    Serial.print("0 ");
//    Serial.print(driver.SG_RESULT(), DEC);
//    Serial.print(" ");
//    Serial.println(driver.cs2rms(driver.cs_actual()), DEC);
//  }
//}

//void activate_interrupt(){
//  {
//    cli();//stop interrupts
//    timer1 = timerBegin(3, 8,true); // Initialize timer 4. Se configura el timer,  ESP(0,1,2,3)
//                                 // prescaler of 8, y true es una bandera que indica si la interrupcion se realiza en borde o en nivel
//    timerAttachInterrupt(timer1, &onTimer, true); //link interrupt with function onTimer
//    timerAlarmWrite(timer1, 8000, true); //En esta funcion se define el valor del contador en el cual se genera la interrupción del timer
//    timerAlarmEnable(timer1);    //Enable timer        
//    sei();//allow interrupts
//  }
//}

//bool shaft = false;
//
void loop() {
  // Run 5000 steps and switch direction in software
  digitalWrite(DIR_PIN_2, LOW);      // Enable driver in hardware
  for (uint16_t i = 5000; i>0; i--) {
    digitalWrite(STEP_PIN_2, HIGH);
    delayMicroseconds(200);
    digitalWrite(STEP_PIN_2, LOW);
    delayMicroseconds(200);
  }
//  shaft = !shaft;
//  driver.shaft(shaft);    
}
