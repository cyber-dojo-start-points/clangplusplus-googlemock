#include "fizz_buzz.hpp"
#include "disk_logger.hpp"

FizzBuzz::FizzBuzz()
    : logger(DiskLogger::getInstance())
{
}


FizzBuzz::FizzBuzz(Logger & logger_)
    : logger(logger_)
{
}

int FizzBuzz::answer()
{
    logger.log("FizzBuzz::answer()");
    return 6 * 7;
}
