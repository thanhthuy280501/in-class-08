#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>  // For sorting

// Function to calculate statistics
void calculate_stats(int arr[], int size, int& min, int& max, double& average) {
    min = arr[0];
    max = arr[0];
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        sum += arr[i];
    }
    average = static_cast<double>(sum) / size;
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments are provided
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <array_size> <input_file> <output_file>" << std::endl;
        return 1;
    }

    // Extract command-line arguments
    int array_size = std::atoi(argv[1]);
    const char* input_file = argv[2];
    const char* output_file = argv[3];

    // Dynamically allocate an array of integers
    int* arr = new int[array_size];

    // Open the input file
    std::ifstream infile(input_file);
    if (!infile) {
        std::cerr << "Error: Could not open file " << input_file << " for reading." << std::endl;
        delete[] arr;
        return 1;
    }

    // Read data from the file
    int count = 0;
    while (infile >> arr[count] && count < array_size) {
        ++count;
    }
    infile.close();

    // Sort the array
    std::sort(arr, arr + count);

    // Write the sorted data to the output file
    std::ofstream outfile(output_file);
    if (!outfile) {
        std::cerr << "Error: Could not open file " << output_file << " for writing." << std::endl;
        delete[] arr;
        return 1;
    }
    for (int i = 0; i < count; ++i) {
        outfile << arr[i] << std::endl;
    }
    outfile.close();

    // Calculate and print statistics
    int min, max;
    double average;
    calculate_stats(arr, count, min, max, average);

    std::cout << "Min: " << min << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Average: " << average << std::endl;

    // Clean up dynamic memory
    delete[] arr;
    return 0;
}
