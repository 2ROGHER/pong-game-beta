#include <iostream>

#include <chrono> // incluir la biblioteca de temporización
#include "Timer.h"

using namespace std;
/**
 * @implementation 
 * @brief
 *
 *
 * @file Timer.cpp
 * @version 1.0
 * @date 2025-06-21
 * @copyright Copyright (c) 2025
 */


Timer::Timer() : isRunning_(false) {}

void Timer::start() {
    isRunning_ = true;
    startTime_ = std::chrono::steady_clock::now();
}

void Timer::stop() {
    isRunning_ = false;
}

void Timer::reset() {
    isRunning_ = false;
    startTime_ = std::chrono::steady_clock::now();
}

void Timer::update() {
    if (isRunning_) {
        currentTime_ = std::chrono::steady_clock::now();
    }
}

float Timer::getElapsedTime() const {
    if (!isRunning_) return 0.0f;
    auto elapsed = std::chrono::duration<float>(currentTime_ - startTime_).count();
    return elapsed;
}

bool Timer::isRunning() const {
    return isRunning_;
}