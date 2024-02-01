#include <iostream>
#include <cmath>
#include <vector>
#include <limits>

#include "point.h"
using namespace std;

class City {
public:
    City(const string& name, double x, double y) : name(name), x(x), y(y) {}

    const string& getName() const {
        return name;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

private:
    string name;
    double x, y;
};

class CityMap {
public:
    void enterCityInformation();
    void calculateDistance();
    void printAllCities();
    void menu();

private:
    vector<City> cities;
    static const int maxCities = 6; 
};

void CityMap::enterCityInformation() {
    if (cities.size() >= maxCities) {
        char choice;
        cout << "City list is full. Do you want to overwrite a city? (y/n): ";
        cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            std::cout << "Overwriting a city.\n";
            return;
        }

        cout << "Choose a city to overwrite:\n";
        printAllCities();

        int cityIndex;
        cout << "Enter the number of the city to overwrite: ";
        cin >> cityIndex;

        if (cityIndex < 1 || cityIndex > cities.size()) {
            cout << "Invalid city number.\n";
            return;
        }

        cities.erase(cities.begin() + cityIndex - 1);
    }

    string name;
    double x, y;

    cout << "Enter city name: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, name);

    cout << "Enter city coordinates (x y): ";
    cin >> x >> y;

    cities.emplace_back(name, x, y);

    cout << "New city information has been entered.\n";
}

void CityMap::calculateDistance() {
    if (cities.size() < 2) {
        cout << "You need at least two cities to calculate distance.\n";
        return;
    }

    printAllCities();

    int cityIndex1, cityIndex2;

    do {
        cout << "Enter the numbers of the two cities to calculate distance (separated by space): ";
        std::cin >> cityIndex1 >> cityIndex2;

        if (cityIndex1 < 1 || cityIndex1 > cities.size() || cityIndex2 < 1 || cityIndex2 > cities.size() || cityIndex1 == cityIndex2) {
            cout << "Invalid city numbers. Please choose two different cities.\n";
        }
    } while (cityIndex1 < 1 || cityIndex1 > cities.size() || cityIndex2 < 1 || cityIndex2 > cities.size() || cityIndex1 == cityIndex2);

    const City& city1 = cities[cityIndex1 - 1];
    const City& city2 = cities[cityIndex2 - 1];

    double distance1 = sqrt(pow(city2.getX() - city1.getX(), 2));
    double distance2 = sqrt(pow(city2.getY() - city1.getY(), 2));

    cout << "Distance between " << city1.getName() << " and " << city2.getName() << " is: " << "["  << distance1 << "," << distance2 << "]" << "\n";
}

void CityMap::printAllCities() {
    if (cities.empty()) {
        cout << "No cities entered yet.\n";
        return;
    }

    cout << "List of cities:\n";
    for (int i = 0; i < cities.size(); ++i) {
        cout << i + 1 << ") " << cities[i].getName() << " (" << cities[i].getX() << ", " << cities[i].getY() << ")\n";
    }
}

void CityMap::menu() {
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "1) Enter city information\n";
        cout << "2) Calculate distance between two cities\n";
        cout << "3) Print all cities\n";
        cout << "4) Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case '1':
                enterCityInformation();
                break;
            case '2':
                calculateDistance();
                break;
            case '3':
                printAllCities();
                break;
            case '4':
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != '4');
}

int main() {
    CityMap cityMap;
    cityMap.menu();

    return 0;
}