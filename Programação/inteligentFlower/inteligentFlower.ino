#include <Servo.h>

#define M1_PWM		5
#define M1_IN1		3
#define M1_IN2		4

#define M2_PWM		6
#define M2_IN1		7
#define M2_IN2		8

#define OPEN 		2000
#define CLOSED		1310

#define pSERVO		9
Servo caixaDagua;

const int[4] LDR_PIN = {A0, A1, A2, A3}; 

void setup() 
{
	// put your setup code here, to run once:

	Serial.begin(9600);

	pinMode(M1_PWM, OUTPUT);
	pinMode(M1_IN1, OUTPUT);
	pinMode(M1_IN2, OUTPUT);

	pinMode(M2_PWM, OUTPUT);
	pinMode(M2_IN1, OUTPUT);
	pinMode(M2_IN2, OUTPUT);

	caixaDagua.attach(pSERVO);
	caixaDagua.writeMicroseconds(CLOSED);
}

void dropWatter(int time){
	caixaDagua.writeMicroseconds(OPEN);
	delay(time);
	caixaDagua.writeMicroseconds(CLOSED);
}

void setSpeed(int speed1, int speed2){
	speed1 = constrain(speed1, -255, 255);
	speed2 = constrain(speed2, -255, 255);

	int dir1 = speed1 >= 0;
	digitalWrite(M1_IN1, dir1);
	digitalWrite(M1_IN2, !dir1);//(speed1 != 0 ? !dir1 : 0)); // For brake porpouses
	analogWrite(M1_PWM, abs(speed1));

	int dir2 = speed2 >= 0;
	digitalWrite(M2_IN1, dir2);
	digitalWrite(M2_IN2, !dir2);//(speed2 != 0 ? !dir2 : 0)); // For brake porpouses
	analogWrite(M2_PWM, abs(speed2));

}

void loop() {
	// setSpeed(0, 0);
	// delay(1000);
	// dropWatter(500);
	setSpeed(0, 0);
	// delay(1000);
	// setSpeed(-255, -255);
	// delay(1000);

	// for(int i = -255; i < 255; i++){
	// 	setSpeed(i, i);
	// 	delay(5);
	// }
  // put your main code here, to run repeatedly: 
  

 	int values[4];
  
 	int i;
	for(i=0; i<4; i++)
	{
		values[i] = analogRead(LDR_PIN[i]);              
	}

	for(i=0; i<4; i++)
	{
		Serial.print(values[i]);

		if(i==3)
			Serial.print("\n");
		else
	  		Serial.print(", ");    
	}

}
