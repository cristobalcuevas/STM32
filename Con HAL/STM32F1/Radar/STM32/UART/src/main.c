/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "defs.h"
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart1;
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void USART1_UART_Init(void);
void GPIO_Init(void);

/**
 * @brief  The application entry point.
 * @retval int
 */

int main(void)
{
    /* Configure the system clock */
    SystemClock_Config();
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();
        /* Initialize all configured peripherals */
    GPIO_Init();
    USART1_UART_Init();
    myprintf("Hi I am Cristobal.\r\n");
    /* Infinite loop */
    while (1)
    {
    }
}

/**
 * @brief System Clock Configuration
 * @retval None
 */

void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0}; // Estructura para oscilador
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0}; // Estructura para reloj

    /* Initializes the RCC Oscillators according to the specified parameters in the RCC_OscInitTypeDef structure */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSI; // HSE reloj externo y LSI RTC interno
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;                                            // Habilita HSE
    RCC_OscInitStruct.LSIState = RCC_LSI_ON;                                            // rtc clock source enable
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;                             // Se divide por 2 HSE
    // RCC_OscInitStruct.HSIState = RCC_HSI_ON;                 //
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;         // Se habilita PLL
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE; // Configura PLL como fuente  de HSE
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;         // Configura multiplicador de PLL x9
    HAL_RCC_OscConfig(&RCC_OscInitStruct);
    /* Initializes the CPU, AHB and APB buses clocks */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK; // Se utiliza como fuente PLL
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;        // AHB dividido por 1
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;         // APB1 dividido por 1
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;         // APB2 dividido por 1
    HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
}

/**
 * @brief USART1 Initialization Function
 * @param None
 * @retval None
 */

void USART1_UART_Init(void)
{
    huart1.Instance = USART1;                        //
    huart1.Init.BaudRate = 115200;                   // Baudios
    huart1.Init.WordLength = UART_WORDLENGTH_8B;     // Tamaño de palabra de 8 bits
    huart1.Init.StopBits = UART_STOPBITS_1;          // 1 bit de parada
    huart1.Init.Parity = UART_PARITY_NONE;           // Sin paridad
    huart1.Init.Mode = UART_MODE_TX_RX;              // Modo transmisor receptor
    huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;     //
    huart1.Init.OverSampling = UART_OVERSAMPLING_16; //
    HAL_UART_Init(&huart1);
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */

void GPIO_Init(void)
{
    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
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