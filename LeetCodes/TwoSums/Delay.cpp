#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

int main() {
    cout << "Start of program\n";

    this_thread::sleep_for(chrono::seconds(2));

    // Correct the type of bitPath to const char*
    const char* bitPath = "\"C:/Program Files/qBittorrent/qBittorent.exe\"";

    int result = system(bitPath);

    if (result == 0) {
        return 0;
    } else {
        return 1;  // Return 1 in case of an error
    }

    // The code after the system call and the second sleep will not be executed
    // as the function would have already returned in the previous if-else block.

    // Sleep for 2 seconds
    this_thread::sleep_for(chrono::seconds(2));

    cout << "After delay\n";

    return 0;
}
