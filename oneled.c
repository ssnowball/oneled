#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/binary_info.h"

const uint REDLED_PIN = 15;

int main() {
	bi_decl(bi_program_description("This is a program to blink 1 LED."));
	bi_decl(bi_1pin_with_name(REDLED_PIN, "External LED"));
	
	stdio_init_all();
	
	gpio_init(REDLED_PIN);
	gpio_set_dir(REDLED_PIN, GPIO_OUT);
	while(1) {
		gpio_put(REDLED_PIN,1);
		sleep_ms(250);
		gpio_put(REDLED_PIN,0);
		puts("made it here\n");
		sleep_ms(250);
	}
}
