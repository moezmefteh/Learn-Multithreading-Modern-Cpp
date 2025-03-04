#include <iostream>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

// Define the callback function type
using Callback = std::function<void(double)>;

// Function to simulate reading the sensor and call the callback if temperature is high
void read_sensor(Callback callback, double threshold) {
    std::srand(std::time(nullptr)); // Seed the random number generator

    while (true) {
        // Generate random temperature and humidity values
        double temperature = 20.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX / 10.0)); // Random temperature between 20°C and 30°C
        double humidity = 30.0 + static_cast<double>(std::rand()) / (static_cast<double>(RAND_MAX / 40.0));    // Random humidity between 30% and 70%

        // Print the current temperature and humidity
        std::cout << "Temperature: " << temperature << "°C, Humidity: " << humidity << "%" << std::endl;

        // Call the callback function if the temperature exceeds the threshold
        if (temperature > threshold) {
            callback(temperature);
        }

        std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait for 2 seconds before reading again
    }
}

// Define the high temperature callback function
void high_temperature_callback(double temperature) {
    std::cout << "Warning: High temperature detected! (" << temperature << "°C)" << std::endl;
}

int main() {
    double threshold = 28.0; // Set the high temperature threshold

    // Register the high temperature callback function and start reading the sensor
    read_sensor(high_temperature_callback, threshold);

    return 0;
}