#pragma once

class Log
{
public:
    enum Type
    {
        LOG = 37, // WHITE
        NOTICE = 34, // BLUE 
        WARNING = 33, // YELLOW 
        SUCCESS = 32, // GREEN 
        ERROR = 31, // RED
    };

    static Log* GetInstance();

    const static void Print(Type log_type, const char* log_format, ...);

private:
    static Log* m_Instance;
};