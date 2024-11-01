//
// Created by h on 2024/10/28.
//

#include <string.h>

#include "main.h"
#include "stm32f4xx_hal_uart.h"
#include "usart.h"

extern uint8_t rcvBuff[BUF_SIZE];

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
    if (huart->Instance == UART8) {
        HAL_UART_Transmit_DMA(&huart8, rcvBuff, BUF_SIZE);
        HAL_UARTEx_ReceiveToIdle_DMA(&huart8, &rcvBuff[0], BUF_SIZE);
    }
}
