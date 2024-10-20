#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <seed> <count> <output_file>" << std::endl;
        return 1;
    }

    // Extract command-line arguments
    int seed = std::atoi(argv[1]);
    int count = std::atoi(argv[2]);
    const char* output_file = argv[3];

    // Seed the random number generator
    srand(seed);

    // Open the output file
    std::ofstream outfile(output_file);
    if (!outfile) {
        std::cerr << "Error: Could not open file " << output_file << " for writing." << std::endl;
        return 1;
    }

    // Generate random numbers and write them to the file
    for (int i = 0; i < count; ++i) {
        int rnum = 1 + (int)(1000.0 * (rand() / (RAND_MAX + 1.0)));
        outfile << rnum << std::endl;
    }

    // Close the file
    outfile.close();

    std::cout << "Successfully wrote " << count << " random numbers to " << output_file << std::endl;
    return 0;
}
