#include <iostream>
#include <fstream>
#include <mutex>

class EventLogger {
private:
    static EventLogger* instance;

    EventLogger() {}
    std::ofstream logFile;

   
    static std::mutex mutex;

public:
    static EventLogger* getInstance() {
        std::lock_guard<std::mutex> lock(mutex);
        if (instance == nullptr) {
            instance = new EventLogger();
            instance->openLogFile("logfile.txt");
        }
        return instance;
    }

    
    void logEvent(const std::string& event) {
        std::lock_guard<std::mutex> lock(mutex);
        logFile << event << std::endl;
    }

 
    EventLogger(const EventLogger&) = delete;
    EventLogger& operator=(const EventLogger&) = delete;

    ~EventLogger() {
        logFile.close();
    }

private:
    // Відкриття файлу для запису
    void openLogFile(const std::string& filename) {
        logFile.open(filename, std::ios::out | std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "Error opening log file: " << filename << std::endl;
        }
    }
};


EventLogger* EventLogger::instance = nullptr;
std::mutex EventLogger::mutex;

int main() {
    EventLogger* logger = EventLogger::getInstance();
    logger->logEvent("Application started.");
    logger->logEvent("Some event occurred.");



    return 0;
}