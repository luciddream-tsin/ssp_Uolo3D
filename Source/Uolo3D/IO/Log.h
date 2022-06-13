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
    public:
        Log(Context *context);

        void Write(int level, const std::string& message);



    private:
        int level_;
    };
}


#endif //UOLO3D_LOG_H
