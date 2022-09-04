#include "main.h"
#include "defs.h"

UART_HandleTypeDef huart1;

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    Gpio_Init();
    Uart_Init();
    myprintf("Hi I am Cristobal.\r\n");
    // myprintf("Welcome to the UART DEMO example.\r\n");
    while (1)
    {
    }
}
/************************************* GPIO *************************************/

void Gpio_Init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_USART1_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct;

    GPIO_InitStruct.Pin = TX_Local_Pin;          // Pin 9
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;      // Alternative function push pull mode
    GPIO_InitStruct.Pull = GPIO_NOPULL;          // No pull up or pull down
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Baja velocidad
    HAL_GPIO_Init(TX_Local_Port, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = RX_Local_Pin;          // Pin 10
    GPIO_InitStruct.Mode = GPIO_MODE_AF_INPUT;   // Alternative function input mode
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW; // Baja velocidad
    HAL_GPIO_Init(RX_Local_Port, &GPIO_InitStruct);
}
/*********************** CONFIGURACION  DE RELOJ DE SISTEMA ***********************/
bool SystemClock_Config(void)
{

    RCC_OscInitTypeDef RCC_OscInitStruct = {0}; // Estructura para oscilador
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0}; // Estructura para reloj

    /* Inicializa el oscilador RCC de acuerdo a los siguientes paramentros.*/
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSI; // HSE reloj externo y LSI RTC interno
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;                                            // Habilita HSE
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;                                            // Habilita LSI
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;                             // Se divide por 2 HSE
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;                                // Configura PLL como fuente  de HSE
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;                                        // Se habilita PLL
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;                                        // Configura multiplicador de PLL x9
    HAL_RCC_OscConfig(&RCC_OscInitStruct);
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        return false;
    }

    /* Initializes the CPU, AHB and APB buses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // Se utiliza como fuente PLL
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;        // AHB dividido por 1
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;         // APB1 dividido por 1
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;         // APB2 dividido por 1
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
    {
        return false;
    }
    return true;
}
/************************************* UART *************************************/
bool Uart_Init(void)
{

    __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);

    huart1.Instance = USART1;                        //
    huart1.Init.BaudRate = 115200;                   // Baudios
    huart1.Init.WordLength = UART_WORDLENGTH_8B;     // Tamaño de palabra de 8 bits
    huart1.Init.Parity = UART_PARITY_NONE;           // Sin paridad
    huart1.Init.StopBits = UART_STOPBITS_1;          // 1 bit de parada
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;     //
    huart1.Init.Mode = UART_MODE_TX_RX;              // Modo transmisor receptor
    huart1.Init.OverSampling = UART_OVERSAMPLING_16; //

    if (HAL_UART_Init(&huart1) != HAL_OK)
    {
        return false;
    }
    return true;
}

void myprintf(const char *format, ...)
{
    static char buffer[256];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    int len = strlen(buffer);
    HAL_UART_Transmit(&huart1, (uint8_t *)buffer, len, -1);
}