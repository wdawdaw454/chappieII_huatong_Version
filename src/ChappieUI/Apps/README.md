app创建使用App_Generator.py一个名为xxx的app

创建app时：
1.在App_xxx_appIcon()中加入app的图标
2.在App_xxx_onCreate()中加入app功能，该函数：
 void App_xxx_onCreate()
    {
        UI_LOG("[%s] onCreate\n", App_xxx_appName().c_str());

        _xxx_init();//相关硬件使能以及初始化
        while (1) {
            _wifi_tv_update();//循环执行app，app的主要功能函数
            if (device->Button.B.pressed()) //退出判断，退出到Launcher？
                    break;
        }
        lv_obj_t * label = lv_label_create(lv_scr_act());
        lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
        lv_label_set_text(label, "Press B again to quit");
    }