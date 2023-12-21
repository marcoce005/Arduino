bool pompa = 0;
#define SENSORE 4
#define POMPA 10
#define REMOTECONTROL 7
void setup()
{
  pinMode(POMPA, OUTPUT);
  pinMode(SENSORE, INPUT_PULLUP);
  pinMode(REMOTECONTROL, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  if (!digitalRead(REMOTECONTROL)) {       // input che arriva dall'utente
    pompa = 1;
    Serial.println("vasca VUOTA           pompa ON");
  }
  if (!digitalRead(SENSORE)) {        // sensore fai da te
    pompa = 0;
    Serial.println("vasca PIENA           pompa OFF");
  }  
  digitalWrite(POMPA, pompa);
}
