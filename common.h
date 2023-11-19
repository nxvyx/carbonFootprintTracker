// common.h

#pragma once

#include <string>
#include <vector>
#include <unordered_map> // Include the unordered_map header

struct UserData {
    int softCoverBooksPerQuarter;
    int hardCoverBooksPerQuarter;
    int articlesOfClothingPerMonth;
    double cellPhoneYears;
    double eReaderYears;
    bool usesAlternativeTransport;
    std::string carType;
    double milesDrivenPerMonth;
    bool usesBus;
    double milesOnBusPerMonth;
    bool hasTraveledByAirplane;
    double airplaneMilesThisYear;
    double wasteScore;   // Placeholder for a more detailed waste calculation
    double energyScore;  // Placeholder for a more detailed energy consumption calculation
    double waterScore;   // Placeholder for a more detailed water consumption calculation
    double foodScore;
    double foodConsumption;
    double waterConsumption;
    double wasteGen;
    int nMem;
};

void calculateFootprints(UserData& userData);
void printCarbonFootprints(const UserData& userData);
void printQuestion(const std::string& question);
int getUserInputInt();
double getUserInputDouble();
bool getUserInputYesNo();
std::string getUserInputString();
void saveDataToCSV(const UserData& userData, const std::string& filename);

// Define an alias for the hash map
using UserHashMap = std::unordered_map<std::string, UserData>;
