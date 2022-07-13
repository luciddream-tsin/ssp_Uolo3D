//
// Created by Administrator on 2022/6/13.
//

#ifndef UOLO3D_LOG_H
#define UOLO3D_LOG_H

#include "Core/Object.h"
#include "string"

namespace Uolo3D {

    static const int LOG_DEBUG = 1;
    static const int LOG_INFO = 2;
    static const int LOG_WARNING = 3;
    static const int LOG_ERROR = 4;

    static const std::string levelPrefixes[] =
            {"", "DEBUG", "INFO", "WARNING", "ERROR"};

    class Log :public Object{
        UOLO3D_CLASS_INFO(Log, Object)
    public:
        Log(Context *context);

        //TODO: 添加打印时Log的文件具体位置
        static void Write(int level, const std::string& message);
        static void Write(const std::string& message);


        void SetLogLevel(int level){
            level_ = level;
        };


        void EndFrameHandler(size_t eventType);



    private:
        static int level_;
    };

#define UOLO3D_LOG_(message) Uolo3D::Log::Write(message)
#define UOLO3D_LOG(level, message) Uolo3D::Log::Write(level, message)
#define UOLO3D_DEBUG(message) Uolo3D::Log::Write(Uolo3D::LOG_DEBUG, message)
#define UOLO3D_INFO(message) Uolo3D::Log::Write(Uolo3D::LOG_INFO, message)
#define UOLO3D_WARNING(message) Uolo3D::Log::Write(Uolo3D::LOG_WARNING, message)
#define UOLO3D_ERROE(message) Uolo3D::Log::Write(Uolo3D::LOG_ERROR, message)

}


#endif //UOLO3D_LOG_H
