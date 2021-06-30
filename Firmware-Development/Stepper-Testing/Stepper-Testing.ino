#define EN_PIN    2 //enable (CFG6)
#define DIR_PIN   16 //direction
#define STEP_PIN  17 //step
#define STDBY     4


void setup()
{
  //set pin modes
  Serial.begin(115200);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, HIGH); //deactivate driver (LOW active)
  pinMode(STDBY, OUTPUT);
  digitalWrite(STDBY, LOW);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, LOW); //LOW or HIGH
  pinMode(STEP_PIN, OUTPUT);
  digitalWrite(STEP_PIN, LOW);

  digitalWrite(EN_PIN, LOW); //activate driver
}

void loop()
{
  //make steps
  for (int i=0; i < 3200; i++) {
  digitalWrite(STEP_PIN, HIGH);
  delayMicroseconds(3000);
  digitalWrite(STEP_PIN, LOW);
  delayMicroseconds(3000);
  }

  //delay(1000);
  
}
