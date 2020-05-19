// Checks status of push button connected to P2.0  (active low)
// When pushed, LED connected to P1.0 flashes five times
#include "ATSTAMP.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main()
{
	if(!OpenCom(2, 115200))           //open com port
	{
		exit(0);
	}
	   while(1)
	   {
		 SerialOutput(P2, 0xFF);      //let PORT2 HIGH
		 SerialOutput(P1, 0x01);      //let PIN0 of PORT1 HIGH (CLOCK PIN)
		 Sleep(300);                  //delay 300 msec
		 SerialOutput(P1, 0x00);      //let PIN0 of PORT1 LOW (CLOCK PIN)
		 Sleep(300);                  //delay 300 msec
		 SerialOutput(P2, 0x00);      //let PORT2 LOW
		 SerialOutput(P1, 0x03);      //let PIN0 (CLOCK) & PIN1 (PRESET ENBALE for COUNTER 4029) of PORT1 HIGH
		 Sleep(300);                  //delay 300 msec
		 // Testing ICs
		 if(SerialInput(P0) == 0xFE)
		 {
			printf("7453 IC is detected\n");

		 }
		 else if(SerialInput(P0) == 0x00)
		 {
			printf("74377 IC is detected\n");
		 }
		 else if(SerialInput(P0) == 0xC0)
		 {
			printf("74174 IC is detected\n");

		 }
		 else if(SerialInput(P0) == 0xF0 || SerialInput(P0) == 0xF1)
		 {
			printf("4029 IC is detected\n");
		 }
		 else
		 {
			printf("Unknown IC\n");
		 }
		 SerialOutput(P1, 0x00);       //let PIN0 of PORT0 LOW (CLOCK PIN)
		 Sleep(300);                   //delay 300 msec
	   }
	  return 0;
}





