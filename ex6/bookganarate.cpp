#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <vector>

// Vector of famous names
std::vector<std::string> names = {
    "Micky Mouse", "Donald Duck", "Minnie Mouse", "Goofy Goof",
    "Daisy Duck", "Scrooge McDuck", "Pluto Pup", "Chip Monk",
    "Luigi Mario", "Peach Princess", "Bowser King", "Donkey Kong",
    "Peter Parker", "Bruce Banner", "Natasha Romanoff", "Loki Laufeyson",
    "James Bond", "Indiana Jones", "Jack Sparrow", "Luke Skywalker",
    "SpongeBob SquarePants", "Patrick Star", "Squidward Tentacles", "Sandy Cheeks",
    "Timmy Turner", "Cosmo Cosma", "Wanda Fairywinkle",
    "Sherlock Holmes", "John Watson", "Bruce Wayne", "Clark Kent"
};

// Function to generate a random phone number
std::string generatePhone() {
    int num = rand() % 9000000 + 1000000; // Generate a number between 1000000 and 9999999
    return "054-" + std::to_string(num);
}

int main() {
    std::ofstream outFile("phone_book.txt");
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for writing.\n";
        return EXIT_FAILURE;
    }

    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 eng(rd()); // Seed the generator

    // Shuffle names using Fisher-Yates shuffle algorithm
    std::shuffle(names.begin(), names.end(), eng);

    srand(time(nullptr)); // Seed the random number generator

    // Assuming there are at least 100 names in the `names` vector
    for (int i = 0; i < 100; ++i) {
        std::string name = names[i]; // Take name sequentially from shuffled vector
        std::string phone = generatePhone(); // Generate a random phone number
        outFile << name << "," << phone << std::endl; // Write to file
    }

    outFile.close(); // Close the file stream
    std::cout << "Generated phone book with 100 unique entries." << std::endl;

    return 0;
}
