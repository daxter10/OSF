#include <iostream>
#include <fstream>

int main() {
    std::string sourceFile, destinationFile;
    std::cout << "Enter source file path: ";
    std::cin >> sourceFile;
    std::cout << "Enter destination file path: ";
    std::cin >> destinationFile;

    std::ifstream src(sourceFile, std::ios::binary);
    std::ofstream dst(destinationFile, std::ios::binary);

    if(!src) {
        std::cout << "Error opening source file!\n";
        return 1;
    }

    if(!dst) {
        std::cout << "Error opening destination file!\n";
        return 1;
    }

    dst << src.rdbuf();

    std::cout << "File copied successfully.\n";

    return 0;
}
