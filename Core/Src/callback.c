//
// Created by h on 2024/10/28.
//

#include <string.h>

#include "main.h"
#include "stm32f4xx_hal_uart.h"
#include "usart.h"

extern uint8_t rcvBuff[BUF_SIZE];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == UART8) {
        HAL_UART_Transmit_DMA(&huart8, rcvBuff, BUF_SIZE);
        HAL_UART_Receive_DMA(&huart8, rcvBuff, BUF_SIZE);
    }
}
