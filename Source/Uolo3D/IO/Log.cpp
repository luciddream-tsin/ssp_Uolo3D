//
// Created by Administrator on 2022/6/13.
//

#include "Log.h"
#include <iostream>

namespace Uolo3D{

    static Log* instanceLog = nullptr;

    int Log::level_ = LOG_INFO;
    Log::Log(Context *context) : Object(context) {
        instanceLog = this;

        SubscribeToEvent(E_ENDFRAME, new EventHandler(std::bind(&Log::EndFrameHandler, this, std::placeholders::_1)));
    }

    void Log::Write(int level, const std::string &message) {

        //if (instanceLog->level_ > level) return;

        std::string formattedMessage = levelPrefixes[level];
        formattedMessage += (": " + message);

        std::cout << formattedMessage << std::endl << std::flush;

    }

    void Log::Write(const std::string &message) {



        std::string formattedMessage = levelPrefixes[level_];
        formattedMessage += (": " + message);

        std::cout <<flush<< formattedMessage << std::endl;    }

    void Log::EndFrameHandler(size_t eventType) {
        Write("Log's EndFrame Exec be called ...");
    }
}