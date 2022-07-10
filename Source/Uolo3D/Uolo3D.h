//
// Created by Administrator on 2022/6/16.
//

#ifndef UOLO3D_UOLO3D_H
#define UOLO3D_UOLO3D_H

#define UOLO3D_GL
#define UOLO3D_VK
#include "cstring"

typedef size_t strHash;

union params_union{
    int int_;
    std::string str_;
    bool bool_;

    //含有string类型, 他又非平凡的构造和析构, 该 union 类的默认相关的复制/移动构造函数、复制/移动赋值函数、析构函数都会被删除
    //你必须显示声明,不然无法使用,
    //注意, 复制的时候它会调用你实现的拷贝构造函数, 你不可以用如下函数来逃避
    //不然它调用你的函数但实际上社么都没有做, 结果是不确定的, 有可能它指向了临近的内存,
    //出现奇怪的(比如这次你没调用的打印函数, 函数内的字符串竟然被你当前的打印操作打印出来了...)
    //params_union(){...}
    //params_union(const params_union &){...};
    //params_unionunion(){...}

    params_union(){
    }
    params_union(const params_union &t){
        memcpy(this, &t, sizeof(t));
    };
    ~params_union(){}
};


#endif //UOLO3D_UOLO3D_H
