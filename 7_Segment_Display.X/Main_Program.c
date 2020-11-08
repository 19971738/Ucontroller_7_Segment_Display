/*
 * File:   Main_Program.c
 * Author: Juan De Dios De Luna Ponce
 *
 * Created on October 31, 2020, 2:08 PM
 */

#include <xc.h>
#include "Configuracion.h"
int i;
int display[14]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67,0x76,0x3F,0x38,0x77,0x00};
void initPort(void){
    ADCON1bits.PCFG = 0xFF; // Puertos en Digital
    LATA = 0;
    LATD = 0;
    TRISA = 0; //Puerto -> Salida
    TRISD = 0; //Puerto -> Salida
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    TRISBbits.RB4 = 1;
    INTCON2bits.RBPU = 0; 
}

void main(void) {
    initPort();
    while(1){
            for(i=10;i<14;i++){
                PORTD = display[i];
                __delay_ms(500);
            }
            PORTD = display[15]; //From 0 to 9
            __delay_ms(500);
            for(i=0;i<10;i++){
                PORTD = display[i]; //From 0 to 9
                __delay_ms(500);
            }
            PORTD = display[15];
            __delay_ms(500);
            for(i=0;i<10;i++){
                PORTD = display[9]; //From 0 to 9
                __delay_ms(500);
                PORTD = display[15]; //From 0 to 9
                __delay_ms(500);
            }
             __delay_ms(500);
            for(i=9;i>=0;i--){
                PORTD = display[i];
                __delay_ms(500);
            }
            PORTD = display[15]; //From 0 to 9
            __delay_ms(500);
            PORTD = 0;
            LATAbits.LA0 = 0;
            LATAbits.LA1 = 0;
        }
    }
