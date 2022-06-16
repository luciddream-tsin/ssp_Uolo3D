//
// Created by Administrator on 2022/6/15.
//

#ifndef UOLO3D_ENGINEDEFS_H
#define UOLO3D_ENGINEDEFS_H

#include <cstring>
#include "string"

namespace Uolo3D {
    static const std::string EP_OPENGL = "OpenGL";
    static const std::string EP_FULL_SCREEN = "FullScreen";
    static const std::string EP_LOG_LEVEL = "LogLevel";

    static const std::string EP_WINDOW_POSITION_X = "WindowPositionX";
    static const std::string EP_WINDOW_POSITION_Y = "WindowPositionY";
    static const std::string EP_WINDOW_SIZE_W = "WindowSizeW";
    static const std::string EP_WINDOW_SIZE_H = "WindowSizeH";


    union params_union{
        int int_;
        string str_;
        bool bool_;

        //含有string类型, 他又非平凡的构造和析构, 该 union 类的默认相关的复制/移动构造函数、复制/移动赋值函数、析构函数都会被删除
        //你必须显示声明,不然无法使用,
        //注意, 复制的时候它会调用你实现的拷贝构造函数, 你不可以用如下函数来逃避
        //不然它调用你的函数但实际上社么都没有做, 结果是不确定的, 有可能它指向了临近的内存,
        //出现奇怪的(比如这次你没调用的打印函数, 函数内的字符串竟然被你当前的打印操作打印出来了...)
        //params_union(){}
        //params_union(const params_union &){};
        //params_unionunion(){}

        params_union(){
            int_ = -1;
        }
        params_union(const params_union &t){
            memcpy(this, &t, sizeof(t));
        };
        ~params_union(){}
    };
}
#endif //UOLO3D_ENGINEDEFS_H
