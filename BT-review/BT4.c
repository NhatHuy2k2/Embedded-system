#include <wiringPi.h>
#include <stdio.h>
#include <stdint.h>
#include <softPwm.h>
#include <unistd.h>
#include <stdlib.h>

uint8_t led[3] = {3,2,0};  //khai bao chan GPIO cho led
uint8_t but[3] = {24,23,22};

static unsigned long led_on,tm;
int a=0, variable=0;

void ngaunhien()
{

	variable = rand()%3;
	//printf("so random la: %d \r", variable);
	a=0;
	softPwmWrite(led[0],100);
	led_on= millis();
	
		
}

void thang()
{
	softPwmWrite(led[variable],0);
	delay(200);
	
	
	for(int k=0;k<20;k++)     //sang dan  0.5s
	{
	softPwmWrite(led[0],k*5);
	softPwmWrite(led[1],k*5);
	softPwmWrite(led[2],k*5);
	delay(25);
	}
	
	for(int k=19;k>=0;k--)     //toi dan  0.5s
	{
	softPwmWrite(led[0],k*5);
	softPwmWrite(led[1],k*5);
	softPwmWrite(led[2],k*5);
	delay(25);
	}

}

void thua()
{
	softPwmWrite(led[0],0);
    softPwmWrite(led[1],0);
	softPwmWrite(led[2],0);

}

void ngat()
{   
	if (digitalRead(but[variable])==1)
	a=1;

}



int main(void)
{

	wiringPiSetup(); //setup
	for (int i=0; i<3; i++)
	{

	pinMode(led[i],OUTPUT);
	softPwmCreate(led[i],0,100);
	pinMode(but[i],INPUT);
	wiringPiISR(but[i], INT_EDGE_BOTH, &ngat);

    }



while(1) //chuong trinh chinh
{
	delay(500);
	ngaunhien();
		while(1)
		 {
			 tm=millis()-led_on;
			 if(a==1&&tm<=5000)
			 {
				 thang();
				 break;
			 }
			 
			else if(a==1&&tm>=5000);
			{
				thang();
				break;
			}
			printf("   thoi gian nhan nut cua ban la: %ld \r", tm);
		 }
	printf("   thoi gian nhan nut cua ban la: %ld \r", tm);
	fflush(stdout);
}
return 0;
}
