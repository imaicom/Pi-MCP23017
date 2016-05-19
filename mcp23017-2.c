#include <stdio.h>
#include <wiringPi.h>
#include <mcp23017.h>

#define BASE 100

int main (void) {
  int i, bit ;

  wiringPiSetup () ;
  mcp23017Setup (BASE, 0x20) ;

  printf ("Raspberry Pi - MCP23017-2 Test\n") ;

  for (i = 0 ; i < 10 ; ++i)
    pinMode (BASE + i, OUTPUT);

//  pinMode         (BASE + 15, INPUT) ;
//  pullUpDnControl (BASE + 15, PUD_UP) ;

  while (1) {
    for (i = 0; i < 1024; i++) {
      for (bit = 0 ; bit < 10 ; bit++)
        digitalWrite (BASE + bit, i & (1 << bit)) ;
      delay (5) ;
 //     while (digitalRead (BASE + 15) == 0)
 //       delay (1) ;
 
    }
  }
  return 0 ;
}
