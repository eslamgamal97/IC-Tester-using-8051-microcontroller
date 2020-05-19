#include <reg52.h>
void delay(int count);
void main(void)
{ 
	P3 = 0xFF;   //make PORT3 as input
	P2 = 0x00;   //make PORT2 as output
	P1 = 0x00;   //make PORT1 as output
	while(1)
	{
		P2 = 0xFF; 		//let PORT2 HIGH 
		P0 = 0x01; 		//let PIN0 of PORT0 HIGH (CLOCK PIN)
		delay(300); 	//delay 300 msec
		P0 = 0x00; 		//let PIN0 of PORT0 LOW (CLOCK PIN)
		delay(300);   //delay 300 msec
		P2 = 0x00; 		//let PORT2 LOW
		P0 = 0x03; 		//let PIN0 (CLOCK) & PIN1 (PRESET ENBALE for COUNTER 4029) of PORT0 HIGH
		delay(300);   //delay 300 msec
		// Testing ICs
		if(P3 == 0xFE)
		{
			P1 = 0x01; //7453 IC
		}
		else if(P3 == 0x00)
		{
			P1 = 0x02;  //74377 IC
		}
		else if(P3 == 0xC0)
		{
			P1 = 0x04; //74174 IC
		}
		else if(P3 == 0xF1 || P3 == 0xF0)
		{
			P1 = 0x08; //4029 IC
		}
		else
		{
			P1 = 0x00; //Unknown
		}
		P0 = 0x00;   //let PIN0 of PORT0 LOW (CLOCK PIN)
		delay(300);  //delay 300 msec
	}
}

void delay(int count)
{
	while(count != 0)
	{
		//delay 1 msec
		TMOD = 0x10;  //set Timer 1
		TL1 = 0xCD;   
		TH1 = 0xF8;
		TR1 = 1;
		while(TF1 == 0);
		TR1 = 0;
		TF1 = 0;
		count--;
	}
}
