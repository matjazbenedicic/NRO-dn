#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// Funkcija za izračun odvoda prvega reda s centralno diferenčno shemo
double calculateCentralDifference(vector<pair<double, double>>& data, int index, double dx) {
    double x = data[index].first;
    double centralDiff = (data[index + 1].second - data[index - 1].second) / (2 * dx);
    return centralDiff;
}

// Funkcija za izračun odvoda prvega reda z diferenčno shemo naprej
double calculateForwardDifference(vector<pair<double, double>>& data, int index, double dx) {
    double forwardDiff = (-3 * data[index].second + 4 * data[index + 1].second - data[index + 2].second) / (2 * dx);
    return forwardDiff;
}

// Funkcija za izračun odvoda prvega reda z diferenčno shemo nazaj
double calculateBackwardDifference(vector<pair<double, double>>& data, int index, double dx) {
    double backwardDiff = (3 * data[index].second - 4 * data[index - 1].second + data[index - 2].second) / (2 * dx);
    return backwardDiff;
}

int main() {
    ifstream inputFile("C:\\Users\\HP\\Documents\\Faks\\3. letnik\\5. semester\\Napredna računalniška orodja\\DN4\\poly.txt");

    if (!inputFile) {
        cerr << "Unable to open input file!" << endl;
        return 1;
    }

    int numValues;
    inputFile >> numValues;

    if (numValues < 3) {
        cerr << "Error: Insufficient data points for differentiation!" << endl;
        return 1;
    }

    vector<pair<double, double>> data(numValues);

    for (int i = 0; i < numValues; ++i) {
        char discard; // za odstranitev dvopičja in presledka
        int id;
        inputFile >> id >> discard >> data[i].first >> discard >> discard >> data[i].second;

        if (!inputFile) {
            cerr << "Error reading data at line " << i + 2 << "!" << endl;
            return 1;
        }
    }

    inputFile.close();

    double dx = 0.01;  // Lahko prilagodite glede na potrebe

    ofstream outputFile("diff_poly.txt");

    if (!outputFile) {
        cerr << "Unable to open output file!" << endl;
        return 1;
    }

    // Izračunajte odvode in shranite v novo datoteko
    for (int i = 1; i < numValues - 1; ++i) {
        double centralDiff = calculateCentralDifference(data, i, dx);
        double forwardDiff = calculateForwardDifference(data, i, dx);
        double backwardDiff = calculateBackwardDifference(data, i, dx);

        // Shranite vrednosti odvodov v datoteko
        outputFile << centralDiff << " " << forwardDiff << " " << backwardDiff << endl;

        if (!outputFile) {
            cerr << "Error writing data at line " << i + 2 << " to diff_poly.txt!" << endl;
            return 1;
        }
    }

    outputFile.close();

    cout << "Differences calculated and saved to diff_poly.txt." << endl;

    return 0;
}
