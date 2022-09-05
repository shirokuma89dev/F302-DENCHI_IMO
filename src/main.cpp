#include <mbed.h>

void interval();

void interval() { HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); }

int main() {
    DigitalOut led(LED1);

    Serial s(SERIAL_TX, SERIAL_RX);
    s.baud(1200);

    Ticker t;
    t.attach(&interval, 1.0);

    while (1) {
        HAL_Delay(1000);
        s.printf("abcde\r\n");
    }
}