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

        static void Write(int level, const std::string& message);


        void EndFrameHandler(size_t eventType){
            Write(LOG_INFO, "Log's EndFrame Exec be called ...");
        };



    private:
        int level_;
    };


#define UOLO3D_LOG(level, message) Uolo3D::Log::Write(level, message)
#define UOLO3D_DEBUG(message) Uolo3D::Log::Write(Uolo3D::LOG_DEBUG, message)
#define UOLO3D_INFO(message) Uolo3D::Log::Write(Uolo3D::LOG_INFO, message)
#define UOLO3D_WARNING(message) Uolo3D::Log::Write(Uolo3D::LOG_WARNING, message)
#define UOLO3D_ERROE(message) Uolo3D::Log::Write(Uolo3D::LOG_ERROR, message)

}


#endif //UOLO3D_LOG_H
