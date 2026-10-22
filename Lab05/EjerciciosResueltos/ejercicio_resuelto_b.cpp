// ejercicio_resuelto_b.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <cstdlib>

int GetRandom(int maxSec) {
    return (rand() % maxSec) + 1;
}

void ExecuteThread(int id) {
    auto nowTime = std::chrono::system_clock::now();
    std::time_t sleepTime = std::chrono::system_clock::to_time_t(nowTime);

    tm myLocalTime = *std::localtime(&sleepTime);

    std::cout << "Thread: " << id << " sleep Time: " << std::ctime(&sleepTime);
    std::cout << "Month: " << (myLocalTime.tm_mon) + 1 << "\n";
    std::cout << "Day: " << myLocalTime.tm_mday << "\n";
    std::cout << "Year: " << myLocalTime.tm_year + 1900 << "\n";
    std::cout << "Hours: " << myLocalTime.tm_hour << "\n";
    std::cout << "Minutes: " << myLocalTime.tm_min << "\n";
    std::cout << "Seconds: " << myLocalTime.tm_sec << "\n";

    std::this_thread::sleep_for(std::chrono::seconds(GetRandom(3)));

    nowTime = std::chrono::system_clock::now();
    sleepTime = std::chrono::system_clock::to_time_t(nowTime);
    std::cout << "Thread " << id << " Awake Time: " << std::ctime(&sleepTime) << "\n";
}

int main() {
    srand(time(NULL));

    std::thread th1(ExecuteThread, 1);
    th1.join();

    std::thread th2(ExecuteThread, 2);
    th2.join();

    return 0;
}