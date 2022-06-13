//
// Created by Administrator on 2022/6/13.
//

#include "Log.h"
#include <iostream>

namespace Uolo3D{


    static Log* instanceLog = nullptr;

    Log::Log(Context *context) : Object(context), level_(LOG_INFO) {
        instanceLog = this;
    }

    void Log::Write(int level, const std::string &message) {

        if (instanceLog->level_ > level) return;

        std::string formattedMessage = levelPrefixes[level];
        formattedMessage += (": " + message);

        std::cout << formattedMessage << std::endl;

    }
}