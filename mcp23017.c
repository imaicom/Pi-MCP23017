// cc -o mcp23017 mcp23017.c -lwiringPi
#include <stdio.h>
#include <wiringPi.h>
#include <mcp23017.h>

int main(void) {
	int i;

	wiringPiSetup();
	mcp23017Setup(100 , 0x20); // base pin no 100~

	printf("Raspberry Pi - MCP23017 Test \n");

	for(i = 0; i < 8; i++) {
		pinMode(100 + i , OUTPUT);
		pinMode(108 + i , INPUT );
	}

	while(1) {
		for(i = 0; i < 8; i++) {
			digitalWrite(100 + i , digitalRead(108 + i));
		}

		delay(50); // 50ms
	}
	return 0;
}
