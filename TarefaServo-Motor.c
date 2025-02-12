#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definições de pinos e parâmetros do PWM
#define SERVO_PIN 22  // Pino GPIO para o controle do servomotor
#define LED_PIN 12    // Pino GPIO para controle do LED RGB
#define PWM_FREQ 50   // Frequência do PWM em Hz
#define PWM_WRAP 20000  // Período do PWM em microssegundos (20ms)

/**
 * @brief Define o ciclo de trabalho do PWM para um determinado pino
 * @param gpio Pino GPIO onde o PWM está configurado
 * @param duty_us Tempo de ciclo ativo em microssegundos
 */
void set_pwm_duty_cycle(uint gpio, uint16_t duty_us) {
    uint slice_num = pwm_gpio_to_slice_num(gpio);
    pwm_set_gpio_level(gpio, duty_us);
}

/**
 * @brief Programa principal que configura e controla o servomotor e o LED
 */
int main() {
    stdio_init_all();
    
    // Configuração dos pinos para função PWM
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);

    // Configuração do PWM para o servomotor
    uint slice_num = pwm_gpio_to_slice_num(SERVO_PIN);
    pwm_set_wrap(slice_num, PWM_WRAP);
    pwm_set_clkdiv(slice_num, 125.0f);
    pwm_set_enabled(slice_num, true);

    // Configuração do PWM para o LED
    uint led_slice = pwm_gpio_to_slice_num(LED_PIN);
    pwm_set_wrap(led_slice, PWM_WRAP);
    pwm_set_clkdiv(led_slice, 125.0f);
    pwm_set_enabled(led_slice, true);

    while (1) {
        // Define o servomotor em 180 graus e ajusta o LED
        set_pwm_duty_cycle(SERVO_PIN, 2400);
        set_pwm_duty_cycle(LED_PIN, 1000);
        sleep_ms(5000);
        
        // Define o servomotor em 90 graus e ajusta o LED
        set_pwm_duty_cycle(SERVO_PIN, 1470);
        set_pwm_duty_cycle(LED_PIN, 500);
        sleep_ms(5000);
        
        // Define o servomotor em 0 graus e ajusta o LED
        set_pwm_duty_cycle(SERVO_PIN, 500);
        set_pwm_duty_cycle(LED_PIN, 250);
        sleep_ms(5000);
        
        // Movimentação suave do servomotor de 0 a 180 graus
        for (uint16_t duty = 500; duty <= 2400; duty += 5) {
            set_pwm_duty_cycle(SERVO_PIN, duty);
            sleep_ms(10);
        }
        
        // Movimentação suave do servomotor de 180 a 0 graus
        for (uint16_t duty = 2400; duty >= 500; duty -= 5) {
            set_pwm_duty_cycle(SERVO_PIN, duty);
            sleep_ms(10);
        }
    }
}
