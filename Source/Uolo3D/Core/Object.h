//
// Created by Administrator on 2022/6/13.
//

#ifndef SSP_UOLO3D_OBJECT_H
#define SSP_UOLO3D_OBJECT_H
#include "string"

using namespace std;

namespace Uolo3D {

    class ClassInfo{
    public:
        ClassInfo(const string name, const ClassInfo *baseClassInfo);

        bool IsClassOf(size_t typeHash)const;

        size_t GetType() const{return typeHash_;}
        const string& GetTypeName() const{return typeName_;}
        const ClassInfo *GetBaseClassInfo() const{return baseClassInfo_;}

    private:
        size_t typeHash_;
        string typeName_;

        const ClassInfo *baseClassInfo_;
    };


//这个宏的作用是, 为每个在Uolo3D系统中运作的类, 插入获得它类型信息的函数
//注意这个函数是静态的, 这样可以实现通过父类的类名, 获得父类的ClassInfo
//当一个类调用了该函数, 会按照继承顺序逆向递归的, 为每个父类生成ClassInfo
//这个ClassInfo也是类的静态函数里的静态的变量, 在该类生命周期内只有一份

//#define UOLO3D_CLASS_INFO(className, baseClassName)                             \
//public:                                                                         \
//static const Uolo3D::ClassInfo *GetClassInfoStatic(){                           \
//    static ClassInfo classInfo(className, baseClassName::GetClassInfoStatic()); \
//    return &classInfo;                                                          \
//}

//其实上面的功能已经足够了, 但是有两个小问题：
//1. 我们可以进一步的为继承自Object的类提供提供GetType, GetTypeName, IsClassOf 而不是每次都通过GetClassInfoStatic再获得.
//2. 我们希望如果一个类继承至Object及其子类而没有实现UOLO3D_CLASS_INFO, 编译不通过.
//这两个问题可以放在一起解决, 在Object 类中将GetType, GetTypeName, IsClassOf设置为纯虚函数
//在宏中加入它们的实现, 实现改宏的用户类, 同时具有快捷方便的类型获取判断接口, 反之编译不通过.
//所以宏变为如下, note: classInfo 对象的定义会被认为是函数声明, 请用初始化列表声明它, 编译器原则: 如果有可能将他解释为函数声明编译器就会这样做

#define UOLO3D_CLASS_INFO(className, baseClassName)                                                            \
public:                                                                                                        \
static const Uolo3D::ClassInfo *GetClassInfoStatic(){                                                          \
    static const ClassInfo classInfo{#className, baseClassName::GetClassInfoStatic()};                         \
    return &classInfo;                                                                                         \
}                                                                                                              \
virtual size_t GetType() const override {return GetClassInfoStatic()->GetType();}                              \
virtual const string &GetTypeName() const override {return GetClassInfoStatic()->GetTypeName();}               \
virtual bool IsClassOf(size_t typeHash) const override {return GetClassInfoStatic()->IsClassOf(typeHash);}     \




    class Context;
    class Object {
    public:
        Object(Context *context);

        //Object类为最顶层的类, 而且绝大多数类都继承于它, 将它的类型信息设为空是合理的
        //即是, 没有必要单独使用信息来标识它.
        //同时, 结合ClassInfo::IsClassOf实现, 可以表示回溯继承结构的终点.
        static const ClassInfo *GetClassInfoStatic(){return nullptr;}

        virtual size_t GetType() const = 0;
        virtual const string& GetTypeName() const = 0;
        virtual bool IsClassOf(size_t typeHash) const = 0;


    protected:
        Context *context_;

    };
}


#endif //SSP_UOLO3D_OBJECT_H
