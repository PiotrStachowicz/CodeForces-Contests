#include <iostream>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <iomanip>

namespace fs = std::filesystem;

int main() {
    // Provide the path to your file
    fs::path filePath = "ścieżka/do/twojego/pliku.txt";

    // Check if the file exists
    if (fs::exists(filePath)) {
        // Get the last write time
        auto ftime = fs::last_write_time(filePath);

        // Extract duration from the file clock time_point
        auto duration = ftime.time_since_epoch();

        // Construct a new system_clock time_point using the extracted duration
        auto sys_time_point = std::chrono::time_point<std::chrono::system_clock>(duration);

        // Convert to local time in a readable format
        auto cftime_t = std::chrono::system_clock::to_time_t(sys_time_point);
        std::tm* localTime = std::localtime(&cftime_t);

        // Print the last modification time
        std::cout << "Ostatnia modyfikacja: "
                  << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") << std::endl;
    } else {
        std::cout << "Plik nie istnieje." << std::endl;
    }

    return 0;
}
