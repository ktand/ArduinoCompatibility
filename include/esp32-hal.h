#ifndef ESP32_HAL_H
#define ESP32_HAL_H

#define log_e(args...) ESP_LOGE("WiFI", args)
#define log_i(args...) ESP_LOGI("WiFI", args)
#define log_w(args...) ESP_LOGW("WiFI", args)
#define log_v(args...) ESP_LOGV("WiFI", args)
#define log_d(args...) ESP_LOGD("WiFI", args)

#include "esp_log.h"
#include "esp_timer.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/queue.h>
#include <freertos/event_groups.h>

#ifdef FREERTOS_UNICORE
#define ARDUINO_EVENT_RUNNING_CORE 0
#else
#define ARDUINO_EVENT_RUNNING_CORE 1
#endif

#ifdef __cplusplus
extern "C" {
#endif
BaseType_t xTaskCreateUniversal( TaskFunction_t pxTaskCode,
                        const char * const pcName,
                        const uint32_t usStackDepth,
                        void * const pvParameters,
                        UBaseType_t uxPriority,
                        TaskHandle_t * const pxCreatedTask,
                        const BaseType_t xCoreID );

extern uint32_t millis();
extern void delay(uint32_t milliseconds);

#ifdef __cplusplus
}
#endif

#endif