// If max v of 4.5v = 50kPa, then sensorValue of 921 (920.7) = 50kPa

int sensorPin=A0;
int sensorValue=0,sensorMax=1023,sensorOffset=52;
float voltage=0,kpa=0,voltageMax=5.0,kpaRangeTopVoltage=4.5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue=analogRead(sensorPin)-sensorOffset;   // Read sensor & adjust with offset
  Serial.print("sensorValue(offset");
  Serial.print( sensorOffset );
  Serial.print("): ");
  Serial.println(sensorValue, DEC);

  if(sensorValue==0)
  {
    kpa=0;
    voltage=0;
  }
  else
  {
    voltage=sensorValue*(voltageMax/sensorMax);
    kpa=((voltage/kpaRangeTopVoltage)-0.04)/0.018;    //Voltage to KPA calculation
  }

  Serial.print("Voltage: ");
  Serial.println(voltage, 3);
  Serial.print("kpa: ");
  Serial.println(kpa,1);
  Serial.println();
  delay(1000);
}
