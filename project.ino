#include <Wire.h>
#include <ZumoShield.h>

ZumoBuzzer buzzer;
ZumoReflectanceSensorArray Sensors;
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);

int motorright = 9;
int motorrightdir  = 7;
int motorleft = 10;
int motorleftdir  = 8;

void setup()
{
  Sensors.init();

  button.waitForButton();

  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  delay(1000);
  int i = 0;

  while (i < 80)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70))
      rotate_left(150, 150);
    else
      rotate_right(150, 150);

    Sensors.calibrate();

    delay(20);

    i++;
  }
  straight(0, 0);

  button.waitForButton();
  Serial.begin(9600);
}

void loop()
{
  unsigned int sensors[6];

  int range = Sensors.readLine(sensors);
  Serial.print(range);

  if (range > 4000)
        move_left(0, 200);
//    Serial.println(" left");

  else if (range < 4000 && range > 3000)
        move_left(100, 200);
//    Serial.println(" left thoda");

  else if (range < 2000 and range > 1000)
        move_right(200, 100);
//    Serial.println(" right");

    else if (range < 1000)
        move_right(200, 0);
//    Serial.println(" right thoda");

    else
          straight(200, 200);
//      Serial.println(" seedha");

    }

void rotate_left(int s1, int s2)
{
  digitalWrite(motorrightdir, LOW);
  analogWrite(motorright, s1);
  digitalWrite(motorleftdir, HIGH);
  analogWrite(motorleft, s2);
}

void rotate_right(int s1, int s2)
{
  digitalWrite(motorrightdir, HIGH);
  analogWrite(motorright, s1);
  digitalWrite(motorleftdir, LOW);
  analogWrite(motorleft, s2);
}

void move_left(int s1, int s2)
{
  digitalWrite(motorrightdir, LOW);
  analogWrite(motorright, s1);
  digitalWrite(motorleftdir, LOW);
  analogWrite(motorleft, s2);
}

void move_right(int s1, int s2)
{
  digitalWrite(motorrightdir, LOW);
  analogWrite(motorright, s1);
  digitalWrite(motorleftdir, LOW);
  analogWrite(motorleft, s2);
}

void straight(int s1, int s2)
{
  digitalWrite(motorrightdir, LOW);
  analogWrite(motorright, s1);
  digitalWrite(motorleftdir, LOW);
  analogWrite(motorleft, s2);
}
