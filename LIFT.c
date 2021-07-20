#include<mega16.h>
#include<delay.h>

int c=0;

int z[]={0x3f, 0x30, 0x5B, 0x4F, 0x66,  0X6d, 0x7D, 0x07,  0x7F, 0x67};

int floor=0;
int dfloor=1;
int cfloor=0;


void main()
{




PORTA=0b00000000;
DDRA=0b01111111;    //current floor(7 segment)

PORTC=0b00000000;
DDRC=0b10010101;        //dc motor

PORTD=0b00000000;
DDRD=0b01111111;        //desired floor(7 segment)

PORTB=0b00011111;
DDRB=0b01100000;        //switch and led


PORTB.5=1;
PORTD=z[0];
PORTA=z[0];
while(1)
{
    if(PINB.0==0)   //ground floor
    {
        delay_ms(400);
        PORTD=z[0];
        floor=0;
    }
    if(PINB.1==0)   //first floor
    {
        delay_ms(400);
        PORTD=z[1];
        floor=1;
    }
    if(PINB.2==0)       //second floor
    {
        delay_ms(400);
        PORTD=z[2];
        floor=2;
    }
    if(PINB.3==0)      //third floor
    {
        delay_ms(400);
        PORTD=z[3];
        floor=3;
    }
    if(PINB.4==0)         //start
    {
        //start=clock();
        delay_ms(400);
        while(cfloor>floor)
        {
            PORTC.0=0;
            PORTC.2=1;
            delay_ms(3300);
            PORTB.6=1;
            delay_ms(700);
            cfloor=cfloor-1;
            PORTA=z[cfloor];
            PORTB.6=0;

            if(cfloor==floor)      //door operation
            {
                PORTC.0=0;
                PORTC.2=0;                 //floor operated motor close

                PORTC.4=0;
                PORTC.7=1;
                delay_ms(1000);
                PORTC.4=0;
                PORTC.7=0;
                delay_ms(5000);
                PORTC.4=1;
                PORTC.7=0;
                delay_ms(1000);
                PORTC.4=0;
                PORTC.7=0;
            }
        }


        while(cfloor<floor)
        {
            PORTC.0=1;
            PORTC.2=0;;
            //time=floor-cfloor;
            //delay_ms(2*time*1000);
            delay_ms(3300);
            PORTB.6=1;
            delay_ms(700);
            cfloor=cfloor+1;
            PORTA=z[cfloor];
            PORTB.6=0;
            if(cfloor==floor)      //door operation
            {

                PORTC.0=0;
                PORTC.2=0;                 //floor operated motor close

                PORTC.4=0;
                PORTC.7=1;
                delay_ms(1000);
                PORTC.4=0;
                PORTC.7=0;
                delay_ms(5000);
                PORTC.4=1;
                PORTC.7=0;
                delay_ms(1000);
                PORTC.4=0;
                PORTC.7=0;

            }
        }

    }


}

}



           


