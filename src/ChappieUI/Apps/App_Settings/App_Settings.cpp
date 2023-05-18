#if 1
#include "App_Settings.h"
#include "../../../ChappieBsp/Chappie.h"

static std::string app_name = "Settings";
static CHAPPIE* device;

LV_IMG_DECLARE(ui_img_icon_setting_png);


namespace App {

    /**
     * @brief Return the App name laucnher, which will be show on launcher App list
     * 
     * @return std::string 
     */
    std::string App_Settings_appName()
    {
        return app_name;
    }


    /**
     * @brief Return the App Icon laucnher, NULL for default
     * 
     * @return void* 
     */
    void* App_Settings_appIcon()
    {
        // return NULL;
        return (void*)&ui_img_icon_setting_png;
    }


    /**
     * @brief Called when App is on create
     * 
     */
    void App_Settings_onCreate()
    {
        UI_LOG("[%s] onCreate\n", App_Settings_appName().c_str());

       //static uint8_t frame_id=0;
       //lv_obj_t * img1;
       //int len = sprintf(buf, "S:/hold/%04d.bin", frame_id++);
       //buf[len] = 0;
       //lv_img_set_src(img1,buf);
       //if (frame_id == 311) frame_id = 0;

       
	// lv_obj_t* obj = lv_img_create(lv_scr_act());
    // lv_img_set_src(obj,"S:1.bmp");    
    // lv_obj_center(obj);

    lv_obj_t* gif1 = lv_gif_create(lv_scr_act());
    lv_gif_set_src(gif1,"S:1.gif");
    lv_obj_center(gif1);

    }


    /**
     * @brief Called repeatedly, end this function ASAP! or the App management will be affected
     * If the thing you want to do takes time, try create a taak or lvgl timer to handle them.
     * Try use millis() instead of delay() here
     * 
     */
    void App_Settings_onLoop()
    {
    }


    /**
     * @brief Called when App is about to be destroy
     * Please remember to release the resourse like lvgl timers in this function
     * 
     */
    void App_Settings_onDestroy()
    {
        UI_LOG("[%s] onDestroy\n", App_Settings_appName().c_str());
    }


    /**
     * @brief Launcher will pass the BSP pointer through this function before onCreate
     * 
     */
    void App_Settings_getBsp(void* bsp)
    {
        device = (CHAPPIE*)bsp;
    }
    
}

#endif
