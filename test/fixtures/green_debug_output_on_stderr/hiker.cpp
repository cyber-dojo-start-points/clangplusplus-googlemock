#include "hiker.hpp"
#include "disk_logger.hpp"
#include <iostream>

Hiker::Hiker()
    : logger(DiskLogger::getInstance())
{
}


Hiker::Hiker(Logger & logger_)
    : logger(logger_)
{
}

int Hiker::answer()
{
    std::cerr << "answer was called" << std::endl;
    logger.log("Hiker::answer()");
    return 6 * 7;
}
