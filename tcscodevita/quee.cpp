#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

// Function to calculate the surface at a point x based on the equation
double calculateSurface(double x, const vector<int>& A, const vector<int>& B, int n) {
    double y = 0;
    for (int i = 0; i < n; ++i) {
        y += sin(x + A[i]) + sin(2 * x + B[i]);
    }
    return y;
}

// Function to find local maxima (peaks) by analyzing the surface values
vector<double> findPeaks(int n, const vector<int>& A, const vector<int>& B) {
    vector<double> peaks;
    double step = 0.01; // small step for precision
    double prev = calculateSurface(0, A, B, n); // Initial surface value
    bool increasing = true;

    for (double x = step; x <= 6.2831; x += step) {
        double current = calculateSurface(x, A, B, n);
        if (increasing && current < prev) {
            peaks.push_back(x - step); // Found a peak
            increasing = false;
        } else if (!increasing && current > prev) {
            increasing = true;
        }
        prev = current;
    }

    return peaks;
}

// Function to find the widest valley
int findWidestValley(const vector<double>& peaks) {
    double maxWidth = 0;
    int widestValleyIndex = 0;
    
    // Use size_t to match the type of peaks.size()
    for (size_t i = 1; i < peaks.size(); ++i) {
        double width = peaks[i] - peaks[i - 1];
        if (width > maxWidth) {
            maxWidth = width;
            widestValleyIndex = i; // valleys are between peaks, so we track this way
        }
    }

    return widestValleyIndex + 1; // Since we count valleys from 1
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n), B(n);

    // Input values for arrays A and B
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }

    // Find all the peaks in the surface
    vector<double> peaks = findPeaks(n, A, B);

    // Determine the widest valley
    int widestValley = findWidestValley(peaks);

    // Output the result
    cout << widestValley;

    return 0;
}
