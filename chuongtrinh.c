#include <mega16.h>
#include <delay.h>
#include <stdlib.h>
#include <i2c.h>
#include <ds1307.h>
#include <alcd.h>

unsigned char gio,phut,giay,mode;
unsigned char week,day,month,year;
unsigned int h1 = 6, m1 = 45, s1=0;
unsigned int h7 = 12, m7 = 30, s7 =0;
unsigned int raChoi = 5;
int dem =0;

int x,y,z;
char t[2];
void hienthigio()
{
rtc_get_time(&gio,&phut,&giay);

            itoa(gio,t);
            if(gio>=10)
            {
                lcd_gotoxy(6,1);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(6,1);
                lcd_putsf("0");
                lcd_gotoxy(7,1);
                lcd_puts(t);
            }
            lcd_gotoxy(8,1);
            lcd_putsf(":");

            itoa(phut,t);
            if(phut>=10)
            {
                lcd_gotoxy(9,1);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(9,1);
                lcd_putsf("0");
                lcd_gotoxy(10,1);
                lcd_puts(t);
            }
            lcd_gotoxy(11,1);
            lcd_putsf(":");
            
            itoa(giay,t);
            if(giay>=10)
            {
                lcd_gotoxy(12,1);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(12,1);
                lcd_putsf("0");
                lcd_gotoxy(13,1);
                lcd_puts(t);
            }
            dem++;
}
void hienthingay()
{
rtc_get_date(&week,&day,&month,&year);

            itoa(week,t);
            lcd_gotoxy(6,0);
            lcd_puts(t);
            lcd_gotoxy(7,0);
            lcd_putsf("/");

            itoa(day,t);
            if(day>=10)
            {
                lcd_gotoxy(8,0);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(8,0);
                lcd_putsf("0");
                lcd_gotoxy(9,0);
                lcd_puts(t);
            }
            lcd_gotoxy(10,0);
            lcd_putsf("/");

            itoa(month,t);
            if(month>=10)
            {
                lcd_gotoxy(11,0);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(11,0);
                lcd_putsf("0");
                lcd_gotoxy(12,0);
                lcd_puts(t);
            }
            lcd_gotoxy(13,0);
            lcd_putsf("/");

            itoa(year,t);
            if(year>=10)
            {
                lcd_gotoxy(14,0);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(14,0);
                lcd_putsf("0");
                lcd_gotoxy(15,0);
                lcd_puts(t);
            }
}
void vaohocsang()
{
            itoa(h1,t);
            if(h1>=10)
            {
                lcd_gotoxy(6,2);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(6,2);
                lcd_putsf("0");
                lcd_gotoxy(7,2);
                lcd_puts(t);
            }
            lcd_gotoxy(8,2);
            lcd_putsf(":");

            itoa(m1,t);
            if(m1>=10)
            {
                lcd_gotoxy(9,2);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(9,2);
                lcd_putsf("10");
                lcd_gotoxy(4,2);
                lcd_puts(t);
            }
            lcd_gotoxy(11,2);
            lcd_putsf(":");

            itoa(s1,t);
            if(s1>=10)
            {
                lcd_gotoxy(12,2);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(12,2);
                lcd_putsf("0");
                lcd_gotoxy(13,2);
                lcd_puts(t);
            }
}
void vaohocchieu()
{
            itoa(h7,t);
            if(h7>=10)
            {
                lcd_gotoxy(6,3);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(6,3);
                lcd_putsf("0");
                lcd_gotoxy(7,3);
                lcd_puts(t);
            }
            lcd_gotoxy(8,3);
            lcd_putsf(":");

            itoa(m7,t);
            if(m7>=10)
            {
                lcd_gotoxy(9,3);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(9,3);
                lcd_putsf("10");
                lcd_gotoxy(4,3);
                lcd_puts(t);
            }
            lcd_gotoxy(11,3);
            lcd_putsf(":");

            itoa(s7,t);
            if(s7>=10)
            {
                lcd_gotoxy(12,3);
                lcd_puts(t);
            }
            else
            {
                lcd_gotoxy(12,3);
                lcd_putsf("0");
                lcd_gotoxy(13,3);
                lcd_puts(t);
            }
}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
    DDRA=(0<<DDA7) | (0<<DDA6) | (0<<DDA5) | (0<<DDA4) | (0<<DDA3) | (0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
    PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
    DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
    PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
    DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=P Bit6=P Bit5=P Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T
    PORTC=(1<<PORTC7) | (1<<PORTC6) | (1<<PORTC5) | (1<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
    DDRD=(1<<DDD7) | (1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0
    PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
    TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
    TCNT0=0x00;
    OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
    TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
    TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
    TCNT1H=0x00;
    TCNT1L=0x00;
    ICR1H=0x00;
    ICR1L=0x00;
    OCR1AH=0x00;
    OCR1AL=0x00;
    OCR1BH=0x00;
    OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
    ASSR=0<<AS2;
    TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
    TCNT2=0x00;
    OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
    TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
    MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
    MCUCSR=(0<<ISC2);

// USART initialization
// USART disabled
    UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
    ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
    SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
    ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI disabled
    SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// SPI initialization
// TWI initialization
// TWI disabled
    TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Bit-Banged I2C Bus initialization
// I2C Port: PORTB
// I2C SDA bit: 1
// I2C SCL bit: 0
// Bit Rate: 100 kHz
// Note: I2C settings are specified in the
// Project|Configure|C Compiler|Libraries|I2C menu.
    i2c_init();

// DS1307 Real Time Clock initialization
// Square wave output on pin SQW/OUT: On
// Square wave frequency: 1Hz
    rtc_init(0,1,0);

// Alphanumeric LCD initialization
// Connections are specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTA Bit 0
// RD - PORTA Bit 1
// EN - PORTA Bit 2
// D4 - PORTA Bit 4
// D5 - PORTA Bit 5
// D6 - PORTA Bit 6
// D7 - PORTA Bit 7
// Characters/line: 20
    lcd_init(20);
//rtc_set_time(0,1,0);
//rtc_set_date(4,23,3,16);

while (1)
{
    {
        hienthigio();
        hienthingay();
        vaohocsang();
        vaohocchieu();



        lcd_gotoxy(0,1);
        lcd_putsf("TIME:");

        lcd_gotoxy(0,0);
        lcd_putsf("DATE:");

        lcd_gotoxy(0,2);
        lcd_putsf("KIP1:");
        lcd_gotoxy(0,3);
        lcd_putsf("KIP7:");

        delay_ms(21);



        if(PINC.7==0)
        {
            mode++;
            //while(PINC.7==0);
            if(mode>13)
            {
                mode=0;
            }
        }
        if(PINC.4==0)
        {
            mode--;
            //while(PINC.4==0);
            if(mode==255)
            {
                mode=13;
            }
        }

        if (mode==1)
        {
            lcd_gotoxy(6,3);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                h7++;
               // while(PINC.6==0);
                if(h7>23)
                {
                    h7=0;
                }

            }
            if(PINC.5==0)
            {
                h7--;
                //while(PINC.5==0);
                if(h7==-1)
                {
                    h7=23;
                }
            }
        }

        if (mode==2)
        {
            lcd_gotoxy(9,3);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                m7++;
                //while(PINC.6==0);
                if(m7>59)
                {
                    m7=0;
                }
            }
            if(PINC.5==0)
            {
                m7--;
                //while(PINC.5==0);
                if(m7==255)
                {
                    m7=59;
                }
            }
        }

        if (mode==3)
        {
            lcd_gotoxy(12,3);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                s7++;
                //while(PINC.6==0);
                if(s7>59)
                {
                    s7=0;
                }
            }
            if(PINC.5==0)
            {
                s7--;
                //while(PINC.5==0);
                if(s7==255)
                {
                    s7=59;
                }
            }
        }


        if (mode==4)
        {
            lcd_gotoxy(6,2);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                h1++;
               // while(PINC.6==0);
                if(h1>23)
                {
                    h1=0;
                }

            }
            if(PINC.5==0)
            {
                h1--;
                //while(PINC.5==0);
                if(h1==-1)
                {
                    h1=23;
                }
            }
        }

        if (mode==5)
        {
            lcd_gotoxy(9,2);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                m1++;
                //while(PINC.6==0);
                if(m1>59)
                {
                    m1=0;
                }
            }
            if(PINC.5==0)
            {
                m1--;
                //while(PINC.5==0);
                if(m1==255)
                {
                    m1=59;
                }
            }
        }

        if (mode==6)
        {
            lcd_gotoxy(12,2);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                s1++;
                //while(PINC.6==0);
                if(s1>59)
                {
                    s1=0;
                }
            }
            if(PINC.5==0)
            {
                s1--;
                //while(PINC.5==0);
                if(s1==255)
                {
                    s1=59;
                }
            }
        }


        if (mode==7)
        {
            lcd_gotoxy(6,1);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                gio++;
                //while(PINC.6==0);
                if(gio>23)
                {
                    gio=0;
                }
            }
            if(PINC.5==0)
            {
                gio--;
                //while(PINC.5==0);
                if(gio==255)
                {
                    gio=23;
                }
            }
            rtc_set_time(gio,phut,giay);
        }

        if (mode==8)
        {
            lcd_gotoxy(9,1);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                phut++;
                //while(PINC.6==0);
                if(phut>59)
                {
                    phut=0;
                }
            }
            if(PINC.5==0)
            {
                phut--;
                //while(PINC.5==0);
                if(phut==255)
                {
                    phut=59;
                }
            }
            rtc_set_time(gio,phut,giay);
        }

        if (mode==9)
        {
            lcd_gotoxy(12,1);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                giay++;
                //while(PINC.6==0);
                if(giay>59)
                {
                    giay=0;
                }
            }
            if(PINC.5==0)
            {
                giay--;
               // while(PINC.5==0);
                if(giay==255)
                {
                    giay=59;
                }
            }
            rtc_set_time(gio,phut,giay);
        }


        if (mode==10)
        {
            lcd_gotoxy(6,0);
            lcd_putsf(" ");
            delay_ms(10);
            if(PINC.6==0)
            {
                week++;
                //while(PINC.6==0);
                if(week>7)
                {
                    week=1;
                }
            }
            if(PINC.5==0)
            {
                week--;
               // while(PINC.5==0);
                if(week==0)
                {
                    week=7;
                }
            }
            rtc_set_date(week,day,month,year);
        }

        if (mode==11)
        {
            lcd_gotoxy(8,0);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                day++;
                //while(PINC.6==0);
                if(day>30)
                {
                    day=1;
                }
            }
            if(PINC.5==0)
            {
                day--;
                //while(PINC.5==0);
                if(day==0)
                {
                    day=30;
                }
            }
            rtc_set_date(week,day,month,year);
        }

        if (mode==12)
        {
            lcd_gotoxy(11,0);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                month++;
                //while(PINC.6==0);
                if(month>12)
                {
                    month=1;
                }
            }
            if(PINC.5==0)
            {
                month--;
                //while(PINC.5==0);
                if(month==0)
                {
                    month=12;
                }
            }

            rtc_set_date(week,day,month,year);
        }

        if (mode==13)
        {
            lcd_gotoxy(14,0);
            lcd_putsf("  ");
            delay_ms(10);
            if(PINC.6==0)
            {
                year++;
                //while(PINC.6==0);
                if(year>99)
                {
                    year=00;
                }
            }
            if(PINC.5==0)
            {
                year--;
                //while(PINC.5==0);
                if(year<=0)
                {
                    year=99;
                }
            }
            rtc_set_date(week,day,month,year);
        }
        x = gio;
        y = phut;
        z = giay;
        //sang
        // KÍP SÁNG:

        // Tiết 1:   6h45 – 7h30
        // Tiết 2:   7h30 – 8h15     
        // Nghỉ 10 phút giữa tiết 2 và tiết 3

        // Tiết 3:   8h25 – 9h10     
        // Nghỉ 10 phút giữa tiết 3 và tiết 4

        // Tiết 4:   9h20 – 10h05   
        // Nghỉ 10 phút giữa tiết 4 và tiết 5

        // Tiết 5:   10h15 – 11h00
        // Tiết 6:   11h00 – 11h45 
        // KÍP CHIỀU:

        // Tiết 7:   12h30 – 13h15
        // Tiết 8:   13h15 – 14h00 
        // Nghỉ 10 phút giữa tiết 8 và tiết 9

        // Tiết 9:   14h10 – 14h55 
        // Nghỉ 10 phút giữa tiết 9 và tiết 10

        // Tiết 10: 15h05 – 15h50 
        // Nghỉ 10 phút giữa tiết 10 và tiết 11

        // Tiết 11: 16h00 – 16h45
        // Tiết 12: 16h45 – 17h30 
        if(((gio==h1)&&(phut==m1)&&(giay==s1)) //6h45
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60)) //kip1 7h30
        //||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+raChoi*60))
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60)) //kip2 8h15
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60+raChoi*60*2)) // ra chơi 8h25
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60+raChoi*60*2+45*60)) // kíp 3 9h10
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2)) //ra chơi 9h20
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60)) // kíp 4 10h05
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60+raChoi*60*2)) //ra chơi 10h15
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60)) // kíp 5  11h
       // ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60+raChoi*60*2+45*60+45*60+raChoi*60*2+45*60+raChoi*60))
        ||((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60+45*60))) // kíp 6 11h45
        {
            PORTD=1;
            delay_ms(400);
        }
        else
        {
            PORTD=0;
        }
        // if((gio*3600+phut*60+giay)==(h1*3600+m1*60+s1+45*60))
        // {
        //     PORTD=1;
        //     delay_ms(400);
        // }
        // else
        // {
        //     PORTD=0;
        // }


        //chieu
        if(((gio==h7)&&(phut==m7)&&(giay==s7)) // 12h30
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60)) //kip7 13h15
        //||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+raChoi*60))
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60)) //kip2 14h00 
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60+raChoi*60*2)) // ra chơi 14h10
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60+raChoi*60*2+45*60)) // kíp 3 14h55 
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2)) //ra chơi 15h05 
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60)) // kíp 4 15h50 
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60+raChoi*60*2)) //ra chơi 16h00 
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60)) // kíp 5  16h45
       // ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60+raChoi*60*2+45*60+45*60+raChoi*60*2+45*60+raChoi*60))
        ||((gio*3600+phut*60+giay)==(h7*3600+m7*60+s7+45*60+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60+raChoi*60*2+45*60+45*60))) // kíp 6 17h30
        {
            PORTD=1;
            delay_ms(400);
        }
        else
        {
            PORTD=0;
        }
    
}
}
}
