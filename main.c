#include "stm32l476xx.h"
#include "SysClock.h"
#include "LED.h"
#include "UART.h"

#include <string.h>
#include <stdio.h>

// why is this here?
char RxComByte = 0;
uint8_t buffer[BufferSize];
char str[] = "POST routine starting...\r\n";
char postOk[] = "POST routine successful\r\n";
char postFail[] = "POST routine failed. Would you like to continue(y,n)?: \r\n";

// function prototypes
static int PostTest(void);

int main(void){
	char rxByte = 'y';
	int		pass = 0;
	
	System_Clock_Init(); // Switch System Clock = 80 MHz
	LED_Init();
	UART2_Init();
		
	USART_Write(USART2, (uint8_t *)str, strlen(str));
	
	while(!pass && rxByte == 'y')
	{
			
			if(PostTest()) {
				pass = 1;
				USART_Write(USART2, (uint8_t *)postOk, strlen(postOk));
			} else {
				USART_Write(USART2, (uint8_t *)postFail, strlen(postFail));
				rxByte = USART_Read(USART2);
				if (rxByte == 'Y' || rxByte == 'y'){
					rxByte = 'y';
				}
			}
	}
	
}

static int PostTest(void)
{
		int res = 0;
		// if sucessful return 1, else 0
		//res = 1;
		return res;
}

