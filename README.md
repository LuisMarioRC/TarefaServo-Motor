# Controle de Servomotor por PWM - RP2040  

## Tarefa: Simulação do Controle de um Servomotor  

### Descrição  
Este repositório contém o código-fonte de um projeto desenvolvido em Linguagem C, utilizando o Pico SDK, para implementar o controle do ângulo de um servomotor através de PWM no microcontrolador Raspberry Pi Pico W. O projeto será executado no simulador de eletrônica online Wokwi, sem necessidade de um circuito físico.

A solução implementa estratégias para:  
1. Configuração da GPIO 22 para gerar sinais PWM.  
2. Ajuste do ciclo ativo para movimentar o servomotor para 0°, 90° e 180°.  
3. Movimentação periódica suave do servomotor entre 0° e 180°.  
4. Testes adicionais com o LED RGB utilizando a Ferramenta Educacional BitDogLab.  

## Funcionalidades  
1. **Geração de Sinal PWM**:  
   - Configura a GPIO 22 para gerar PWM com frequência de aproximadamente 50Hz.  
   - Ajuste do ciclo ativo para 2.400µs (180°), 1.470µs (90°) e 500µs (0°).  
   - Tempo de espera de 5 segundos em cada posição.  

2. **Movimentação Periódica Suave**:  
   - Alterna o ângulo do servomotor entre 0° e 180°.  
   - Incrementa o ciclo ativo em ±5µs a cada 10ms para suavizar o movimento.  

3. **Experimento com LED RGB**:  
   - Uso da Ferramenta BitDogLab para analisar o comportamento do LED RGB na GPIO 12.  
   - Observação dos efeitos do sinal PWM sobre a iluminação do LED.  

## Pré-requisitos  
1. **Hardware Necessário**:  
   - Simulação utilizando Wokwi.  
   - Raspberry Pi Pico W.  
   - Servomotor micro servo padrão.  
   - LED RGB na GPIO 12 para testes adicionais.  

2. **Ambiente de Desenvolvimento**:  
   - Visual Studio Code com Pico SDK configurado.  
   - Compilador GCC para C.  
   - Simulador Wokwi integrado ao VS Code.  

## Como Usar  
1. **Clone o repositório**:  
    ```bash  
    git clone https://github.com/LuisMarioRC/TarefaServo-Motor.git 
    ```  

2. **Navegue até o diretório do projeto**:  
    ```bash  
    cd TarefaServo-Motor
    ```  

3. **Compile o código com o Pico SDK**:  
   - Certifique-se de que o Pico SDK está configurado corretamente.  
   - No terminal, execute:  
     ```bash  
     mkdir build  
     cd build  
     cmake ..  
     make  
     ```  

4. **Execute a simulação no Wokwi**:  
   - Abra o Wokwi e carregue o projeto.  
   - Observe a movimentação do servomotor conforme a lógica implementada.  

5. **Experimento com BitDogLab**:  
   - Utilize a Ferramenta BitDogLab para analisar o LED RGB.  
   - Registre as observações sobre o comportamento do LED.  

## Requisitos Implementados  
1. Configuração da GPIO 22 para PWM com 50Hz.  
2. Ajuste do ciclo ativo para posições de 0°, 90° e 180°.  
3. Movimentação periódica suave entre 0° e 180°.  
4. Testes com LED RGB na Ferramenta BitDogLab.  
5. Simulação no Wokwi integrada ao VS Code.  

## Testes e Demonstração  
1. **Simulação no Wokwi**:  
   - Configure o Wokwi conforme as especificações do hardware.  
   - Execute o código e analise a movimentação do servomotor.  

2. **Demonstração Física**:  
   - Grave um vídeo demonstrando o funcionamento.  
   - Explique as funcionalidades implementadas.  

## Vídeo  

Confira a demonstração prática no link: [Link do vídeo](https://youtu.be/okv76mCHUzs).  

### Líder do Projeto  
- <b><a href="https://github.com/LuisMarioRC">Luis Mario</a></b> 