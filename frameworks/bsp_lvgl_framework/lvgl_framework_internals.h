#pragma once

void s_lvgl_display_panel_set_initial_rotation_config();
void lvgl_display_rotation_update_callback(lv_display_t * disp);
void s_lvgl_input_device_config() ;

bool s_lvgl_port_init_locking_mutex(void);
bool s_lvgl_lock(TickType_t timeout);
void s_lvgl_unlock(void);


#define LVGL_LOCK()   s_lvgl_lock(portMAX_DELAY)
#define LVGL_UNLOCK() s_lvgl_unlock()