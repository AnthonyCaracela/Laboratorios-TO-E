// ejercicio_resuelto_c.cpp
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex vectLock;
std::vector<unsigned int> primeVect;

void FindPrimesWithoutThreads(unsigned int start, unsigned int end, std::vector<unsigned int>& vect) {
    for (unsigned int x = start; x <= end; x += 2) {
        for (unsigned int y = 2; y < x; y++) {
            if (x % y == 0) {
                break;
            } else if ((y + 1) == x) {
                vect.push_back(x);
            }
        }
    }
}

void FindPrimes(unsigned int start, unsigned int end) {
    for (unsigned int x = start; x <= end; x += 2) {
        bool isPrime = true;
        for (unsigned int y = 2; y < x; y++) {
            if (x % y == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime && x > 1) {
            vectLock.lock();
            primeVect.push_back(x);
            vectLock.unlock();
        }
    }
}

void FindPrimesWithThreads(unsigned int start, unsigned int end, unsigned int numThreads) {
    std::vector<std::thread> threadVect;
    unsigned int threadSpread = (end - start + 1) / numThreads;
    unsigned int currentStart = start;
    unsigned int currentEnd = start + threadSpread - 1;

    for (unsigned int x = 0; x < numThreads; x++) {
        threadVect.emplace_back(FindPrimes, currentStart, currentEnd);
        currentStart += threadSpread;
        currentEnd += threadSpread;
    }

    for (auto& t : threadVect) {
        t.join();
    }
}

int main() {
    unsigned int limite = 100000;

    auto startClockSeq = std::chrono::high_resolution_clock::now();
    std::vector<unsigned int> seqPrimes;
    FindPrimesWithoutThreads(1, limite, seqPrimes);
    auto endClockSeq = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedSeq = endClockSeq - startClockSeq;
    std::cout << "[SIN HILOS] Execution Time: " << elapsedSeq.count() << " segundos\n";

    auto startClockThread = std::chrono::high_resolution_clock::now();
    FindPrimesWithThreads(1, limite, 8);
    auto endClockThread = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedThread = endClockThread - startClockThread;
    std::cout << "[CON HILOS] Execution Time: " << elapsedThread.count() << " segundos\n";

    return 0;
}