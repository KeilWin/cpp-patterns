#include <iostream>
#include <string>

class Logger {
   public:
    Logger() = default;
    ~Logger() = default;

    virtual void Debug(std::string&& message) = 0;
    virtual void Info(std::string&& message) = 0;
    virtual void Error(std::string&& message) = 0;
};

class NightLogger : public Logger {
   public:
    NightLogger(std::string&& debug_prefix, std::string&& info_prefix,
                std::string&& error_prefix)
        : debug_prefix_{debug_prefix},
          info_prefix_{info_prefix},
          error_prefix_{error_prefix} {}
    ~NightLogger() = default;

    void Debug(std::string&& message) override {
        std::cout << debug_prefix_ << message << std::endl;
    }
    void Info(std::string&& message) override {
        std::cout << info_prefix_ << message << std::endl;
    }
    void Error(std::string&& message) override {
        std::cout << error_prefix_ << message << std::endl;
    }

   private:
    std::string debug_prefix_;
    std::string info_prefix_;
    std::string error_prefix_;
};

class LoggerFactory {
   public:
    LoggerFactory() = default;
    ~LoggerFactory() = default;

    virtual Logger* NewLogger() = 0;
};

class NigthLoggerFactory : public LoggerFactory {
   public:
    NigthLoggerFactory() = default;
    ~NigthLoggerFactory() = default;

    Logger* NewLogger() {
        return new NightLogger("night_debug:\t", "night_info:\t",
                               "night_error:\t");
    };
};

class DayLoggerFactory : public LoggerFactory {
   public:
    DayLoggerFactory() = default;
    ~DayLoggerFactory() = default;

    Logger* NewLogger() {
        return new NightLogger("day_debug:\t", "day_info:\t", "day_error:\t");
    };
};

Logger* NewLogger(LoggerFactory& factory) {
    return factory.NewLogger();
}

int main(int argc, char* argv[]) {
    std::cout << "Abstract factory\n";

    NigthLoggerFactory night_logger_factory;
    Logger* night_logger = NewLogger(night_logger_factory);
    night_logger->Debug("hello");

    DayLoggerFactory day_logger_factory;
    Logger* day_logger = NewLogger(day_logger_factory);
    day_logger->Debug("hello");

    delete night_logger;
    delete day_logger;
    return 0;
}