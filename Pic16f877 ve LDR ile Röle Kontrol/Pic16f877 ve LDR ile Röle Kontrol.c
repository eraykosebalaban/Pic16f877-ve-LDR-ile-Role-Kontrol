#include<16f877.h>

#device ADC = 10;

#use delay(clock = 4000000)

#use fast_io(a)
#use fast_io(b)
#use fast_io(c)

#define use_portb_lcd TRUE
#include<lcd.c>

unsigned int deger;

void main(){
setup_psp(PSP_DISABLED);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_ccp1(CCP_OFF);
setup_ccp2(CCP_OFF);

setup_adc(adc_clock_div_32); 
setup_adc_ports(ALL_ANALOG);

set_tris_a(0x20);
set_tris_b(0x00);
set_tris_c(0x00);

output_b(0x00);
output_c(0x00);

lcd_init();

set_adc_channel(4);

while(true){
deger = read_adc();
delay_us(20);

printf(lcd_putc,"\fLDR Deger= %u",deger);
delay_ms(100);

switch(deger){
case 245:
output_high(pin_c5);
break;

case 206:
output_high(pin_c5);
break;

case 162:
output_high(pin_c5);
break;

case 84:
output_low(pin_c5);
break;

case 170:
output_high(pin_c5);
break;

case 255:
output_high(pin_c5);
break;

case 85:
output_low(pin_c5);
break;

case 93:
output_low(pin_c5);

default:
output_low(pin_c5);

}

}




}


