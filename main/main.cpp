

//---------

/*********************
 *      INCLUDES
 *********************/
extern "C" {

//#include "freertos/FreeRTOS.h"
//#include "freertos/task.h"
#include "esp_log.h"
#include "lcd_backlight.h"
#include "lcd_bsp_interface.h"
#include "touch_bsp_interface.h"
#include "lvgl_framework.h"
#include "ui.h"
//#include "filesystem.h"
}
/**********************
 *   GLOBAL VARIABLES
 **********************/

//---------
//---------
//--------------------------------------

/*
███████ ██████  ███████ ███████ ██████ ████████  ██████  ███████ 
██      ██   ██ ██      ██      ██   ██   ██    ██    ██ ██      
█████   ██████  █████   █████   ██████    ██    ██    ██ ███████ 
██      ██   ██ ██      ██      ██   ██   ██    ██    ██      ██ 
██      ██   ██ ███████ ███████ ██   ██   ██     ██████  ███████ 
*/
/*********************
 *  RTOS variables
 *********************/

// -------------------------------
/********************************************** */
/*                   TASK                       */
/********************************************** */
// -------------------------------

/************************************************** */

//--------------------------------------

/*
███    ███  █████  ██ ███    ██ 
████  ████ ██   ██ ██ ████   ██ 
██ ████ ██ ███████ ██ ██ ██  ██ 
██  ██  ██ ██   ██ ██ ██  ██ ██ 
██      ██ ██   ██ ██ ██   ████ 
  * This is the main entry point of the application.
  * It initializes the hardware, sets up the display, and starts the LVGL tasks.
  * The application will run indefinitely until the device is powered off or reset.
*/
extern "C" void app_main(void) {
    esp_log_level_set("*", ESP_LOG_INFO);  //
    printf("Starting application!\n");
    ESP_LOGI("APP_MAIN", "Hello world!\n");
    printf("Hello world!\n");

    Backlight_Driver_Init();   // Initialize the LCD backlight with default brightness 80%
    Backlight_Set(100);  // Set backlight brightness to 80%
    lvgl_framework_init(); // Initialize the LVGL framework and display
    bsp_lcd_init();  // Initialize the LCD display
    bsp_touchscreen_init();  // Initialize the touch controller
    lvgl_kernel_start(); // Start the LVGL kernel and tasks
    lvgl_execute_locked([]() {
        create_tabs_ui();
    });

    // init_filesystem_sys();

    vTaskDelay(pdMS_TO_TICKS(150));
    //fflush(stdout);
    printf("Closing application!\n");
}
