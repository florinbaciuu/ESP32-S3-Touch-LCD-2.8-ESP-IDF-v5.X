#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "misc/lv_types.h"
#include "freertos/FreeRTOS.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************
 *   LVGL FUNCTIONS PROTOTYPES
 ******************************/

/**
 * This function initializes the LVGL kernel and starts the necessary FreeRTOS tasks for LVGL to operate.
 * It ensures that the LVGL main task and, if configured, the tick task are created and pinned to the appropriate core.
 * The function also includes a delay to allow the tasks to start properly before returning.
 * It uses a static variable to ensure that the initialization code is only executed once, preventing multiple initializations 
 * if the function is called multiple times.    
 */
void lvgl_kernel_start(void);

// -------------------------------
void lvgl_display_rotation_update_callback(lv_display_t * disp);

void lvgl_execute_locked(void (*func)(void));
void s_lvgl_input_device_config() ;
bool s_lvgl_port_init_locking_mutex(void);
bool s_lvgl_lock(TickType_t timeout);
void s_lvgl_unlock(void);
void lvgl_framework_init(void);

#define LVGL_LOCK()   s_lvgl_lock(portMAX_DELAY)
#define LVGL_UNLOCK() s_lvgl_unlock()



#ifdef __cplusplus
}
#endif