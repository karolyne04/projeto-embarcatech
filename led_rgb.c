#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definição de pinos
#define RED_PIN 13
#define GREEN_PIN 11

#define BLUE_PIN 12

// Função para configurar PWM nos pinos dos LEDs
void init_pwm(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM); // Define o pino como saída PWM
    uint slice = pwm_gpio_to_slice_num(pin); // Obtém o número do "slice" do PWM
    pwm_set_wrap(slice, 255); // Define o valor máximo do PWM (0-255)
    pwm_set_chan_level(slice, pwm_gpio_to_channel(pin), 0); // Começa com LED apagado
    pwm_set_enabled(slice, true); // Habilita PWM
}

// Função para definir uma cor no LED RGB
void set_led_color(uint red, uint green, uint blue) {
    pwm_set_gpio_level(RED_PIN, red);
    pwm_set_gpio_level(GREEN_PIN, green);
    pwm_set_gpio_level(BLUE_PIN, blue);
}

int main() {
    stdio_init_all(); // Inicializa UART para depuração

    // Inicializa PWM para cada cor
    init_pwm(RED_PIN);
    init_pwm(GREEN_PIN);
    init_pwm(BLUE_PIN);

    while (true) {
        // Definição de cores personalizadas (valores de 0 a 255)
        set_led_color(255, 0, 255);  // Rosa (Mistura de vermelho e azul)
        printf("Cor: Rosa\n");
        sleep_ms(1000);

        set_led_color(0, 255, 100);  // Verde diferente (Mistura de verde e azul)
        printf("Cor: Verde claro\n");
        sleep_ms(1000);

        set_led_color(255, 165, 0);  // Laranja
        printf("Cor: Laranja\n");
        sleep_ms(1000);

        set_led_color(0, 0, 0);  // Apaga LED
        printf("LED Off\n");
        sleep_ms(1000);
    }

    return 0;
}
