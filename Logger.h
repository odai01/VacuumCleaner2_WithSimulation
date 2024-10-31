#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <memory>
#include <mutex>

class Logger {
public:
    enum Level {
        INFO,
        WARNING,
        ERROR
    };

    Logger(const std::string& filename);
    ~Logger();

    void log(Level level, const std::string& message);
     void clearLog();

private:
    std::ofstream logFile;
    std::string getTimestamp();
    std::string levelToString(Level level);
      std::mutex logMutex;
};

#endif // LOGGER_H
