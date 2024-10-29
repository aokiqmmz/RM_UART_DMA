//
// Created by h on 2024/10/28.
//

#include <string.h>

#include "main.h"
#include "stm32f4xx_hal_uart.h"

extern char message[1];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == UART8) {
        HAL_Delay(1000);
        HAL_UART_Transmit(huart, (uint8_t *)message, strlen((char *)message), HAL_MAX_DELAY);
    }
}
