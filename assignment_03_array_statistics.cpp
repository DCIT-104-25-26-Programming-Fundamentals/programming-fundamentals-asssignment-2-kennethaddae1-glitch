// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int calculateSum(const vector<int>& numbers) {
    int sum = 0;
    for (int value : numbers) {
        sum += value;
    }
    return sum;
}

double calculateAverage(const vector<int>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }

    return static_cast<double>(calculateSum(numbers)) / numbers.size();
}

int findMaximum(const vector<int>& numbers) {
    int maximum = numbers[0];
    for (int value : numbers) {
        if (value > maximum) {
            maximum = value;
        }
    }
    return maximum;
}

int findMinimum(const vector<int>& numbers) {
    int minimum = numbers[0];
    for (int value : numbers) {
        if (value < minimum) {
            minimum = value;
        }
    }
    return minimum;
}

int main() {
    int count;

    cout << "How many numbers? ";
    cin >> count;

    if (count <= 0) {
        cout << "Error: Number of values must be positive." << endl;
        return 0;
    }

    vector<int> numbers(count);
    for (int i = 0; i < count; ++i) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    cout << endl << "Results:" << endl;
    cout << "Sum:     " << calculateSum(numbers) << endl;
    cout << fixed << setprecision(1) << "Average: " << calculateAverage(numbers) << endl;
    cout << "Maximum: " << findMaximum(numbers) << endl;
    cout << "Minimum: " << findMinimum(numbers) << endl;

    return 0;
}

