//#include <io/peripherals/uart.h>
#include <stdint.h>
#include <io/peripherals/mini_uart.h>
#include <io/led.h>

void kernel_main(void)
{	
	uint8_t a;
	mini_uart_init(14);
	mini_uart_init(15);
	//led_init();
	//led_set(LOW);

	mini_uart_send_string("Hello, world!\r\n");
	while (1) {
		mini_uart_send('>');
		a = mini_uart_recv();
		mini_uart_send_string("Your character is: ");
		mini_uart_send(a);

		if(a == 'o'){
			mini_uart_send_string(", and it should turn on the led\r\n");
			//led_set(HIGH);
		}
		else if (a == 'f'){
			mini_uart_send_string(", and it should turn off the led\r\n");
			//led_set(LOW);
		}
		else if (a == 'q'){
			mini_uart_send_string("\r\nShutting down");
			break;
		}
		else{
			mini_uart_send_string("\r\n");
		}
		
	}
}
