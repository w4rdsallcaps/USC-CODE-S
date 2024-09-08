#include <iostream>
#include <iomanip>
#include <limits>   

int main() {
    float aspeed = 9.1618, bspeed = 10.1618; 
    float distance;
    float atime_min, atime_max, btime_min, btime_max, Xavetime, Yavetime;
    char result;

    while (1) {
        
        std::cout << "Enter the distance from the jeep to your destination (in kilometers): ";
        std::cin >> distance;
        while (distance <= 0 && distance >= 0){
            std::cout << "\nInvalid option. Please enter a proper distance\nEnter the distance from the jeep to your destination (in kilometers): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> distance;
        }
        btime_min = (distance / bspeed) * 60;
        btime_max = (distance / aspeed) * 60;
        Yavetime = (btime_min + btime_max) / 2;
        std::cout << "\nThe estimated time it will take to reach your destination: " << std::fixed << std::setprecision(2) << btime_min << " minutes to " << btime_max << " minutes\n";
        std::cout << "The estimated average time to reach your destination is " << std::fixed << std::setprecision(2) << Yavetime << " minutes\n";

        std::cout << "\nDo you want to use the program again? (y/n): ";
        std::cin >> result;

        while (result != 'y' && result != 'n') {
            std::cout << "Invalid option. Please enter 'y' to continue or 'n' to exit: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> result;
        }
        
        if (result == 'n') {
            break;
        }
    }
    return 0;
}
