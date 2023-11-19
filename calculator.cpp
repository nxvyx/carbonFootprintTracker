#include "common.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;


const double CARBON_PER_SOFT_COVER_BOOK = 0.7;
const double CARBON_PER_HARD_COVER_BOOK = 1.2;
const double CARBON_PER_ARTICLE_OF_CLOTHING = 10.75;
const double CARBON_PER_CELL_PHONE_YEAR = 0.50;
const double CARBON_PER_EREADER_YEAR = 0.70;
const double CARBON_PER_MILE_DRIVEN = 0.12;
const double CARBON_PER_BUS_MILE = 0.1;
const double CARBON_PER_AIRPLANE_MILE = 0.115;
const double CARBON_PER_FOOD = 0.2;
const double CARBON_WATER = 0.3;

void calculateFootprints(UserData& userData) {
    userData.wasteScore = 0;
    userData.energyScore = 0;
    userData.waterScore = 0;
    userData.foodScore = 0;

    // Calculate waste footprint
    userData.wasteScore += userData.softCoverBooksPerQuarter * CARBON_PER_SOFT_COVER_BOOK;
    userData.wasteScore += userData.hardCoverBooksPerQuarter * CARBON_PER_HARD_COVER_BOOK;
    userData.wasteScore += userData.articlesOfClothingPerMonth * CARBON_PER_ARTICLE_OF_CLOTHING;
    userData.wasteScore += userData.wasteGen;

    // Calculate energy footprint
    userData.energyScore += userData.cellPhoneYears/12 * CARBON_PER_CELL_PHONE_YEAR;
    userData.energyScore += userData.eReaderYears/12 * CARBON_PER_EREADER_YEAR;
    userData.energyScore += userData.milesDrivenPerMonth * CARBON_PER_MILE_DRIVEN;
    userData.energyScore += userData.milesOnBusPerMonth * CARBON_PER_BUS_MILE;
    userData.energyScore += userData.airplaneMilesThisYear/12 * CARBON_PER_AIRPLANE_MILE;
    userData.energyScore += userData.energyScore/userData.nMem;

    // Calculate food footprint
    userData.foodScore += userData.foodConsumption * CARBON_PER_FOOD;

    // Calculate water footprint
    userData.waterScore += userData.waterConsumption * CARBON_WATER;
}

void printCarbonFootprints(const UserData& userData) {
    std::cout << "\nCarbon Footprints (in kilograms):" << std::endl;
    double totalFootprint = userData.wasteScore + userData.energyScore + userData.waterScore + userData.foodScore;
    
    std::cout << "Waste Score: " << userData.wasteScore << std::endl;
    std::cout << "Energy Score: " << userData.energyScore << std::endl;
    std::cout << "Water Score: " << userData.waterScore << std::endl;
    std::cout << "Food Score: " << userData.foodScore << std::endl;
    std::cout << "Total Footprint: " << totalFootprint << std::endl;
    if (totalFootprint <=199)
    {
        cout<<"\n\nYou are doing fine. You can take small steps to reduce carbon emissions."<<endl;
        cout<<"Here are some recommendations for you to reduce carbon emission: "<<endl;
        cout<<"-> Avoid single-use plastics and opt for reusable alternatives. Always Reuse,Reduce & Recycle!"<<endl;
        cout<<"-> Participate in local reforestation efforts."<<endl;
        cout<<"-> Conserve water at home and in daily activities."<<endl;
        cout<<"-> Encourage community-wide efforts to reduce energy consumption and waste."<<endl;
        cout<<"-> Buy products with long lifespans and consider second-hand items."<<endl;
        cout<<"-> Bike or walk for short distances when possible."<<endl;
    }
    
    else if (totalFootprint >= 200 and totalFootprint <= 350){
        cout<<"\n\nYou can improve!";
        cout<<"Here are some recommendations for you to reduce carbon emission: "<<endl;
        cout<<"-> Participate in tree planting initiatives in your community."<<endl;
        cout<<"-> Support organizations involved in afforestation and conservation efforts."<<endl;
        cout<<"-> Choose products with minimal environmental impact and consider second-hand options."<<endl;
        cout<<"-> Collect rainwater for outdoor use."<<endl;
        cout<<"-> Minimize waste by choosing products with minimal packaging."<<endl;
        cout<<"-> Recycle paper, plastic, glass, and other materials as much as possible."<<endl;
    }
    else if (totalFootprint >= 351)
    {
        cout<<"\n\nYou are emiiting too much carbon! You need to take strict measures to reduce the emissions."<<endl;
        cout<<"Here are some recommendations for you to reduce carbon emission: "<<endl;
        cout<<"-> Switch to energy-efficient appliances and light bulbs."<<endl;
        cout<<"-> Support and advocate for policies promoting renewable energy adoption."<<endl;
        cout<<"-> Opt for public transportation, carpooling, or ridesharing to reduce individual vehicle emissions."<<endl;
        cout<<"-> Choose fuel-efficient or electric vehicles when purchasing a new car."<<endl;
        cout<<"-> Recycle paper, plastic, glass, and other materials as much as possible"<<endl;
        cout<<"-> Buy locally-produced and seasonal goods to reduce the carbon footprint of transportation."<<endl;
        cout<<"-> Participate in tree planting initiatives in your community."<<endl;
        cout<<"-> Invest in carbon offset programs to compensate for unavoidable emissions."<<endl;
        cout<<"-> Adopt a plant-based diet or reduce meat consumption."<<endl;
    }
    
}

void printQuestion(const std::string& question) {
    std::cout << question << std::endl;
}

int getUserInputInt() {
    int input;
    std::cin >> input;
    return input;
}

double getUserInputDouble() {
    double input;
    std::cin >> input;
    return input;
}

bool getUserInputYesNo() {
    char response;
    std::cin >> response;
    return (response == 'y' || response == 'Y');
}

std::string getUserInputString() {
    std::string input;
    std::getline(std::cin, input);  // Use getline to get the entire line
    return input;
}

void saveUserDataToCSV(const UserData& userData) {
    std::ofstream file("user_cf_data.csv", std::ios::app);
    file << userData.softCoverBooksPerQuarter << ","
         << userData.hardCoverBooksPerQuarter << ","
         << userData.articlesOfClothingPerMonth << ","
         << userData.cellPhoneYears << ","
         << userData.eReaderYears << ","
         << userData.usesAlternativeTransport << ","
         << userData.carType << ","
         << userData.milesDrivenPerMonth << ","
         << userData.usesBus << ","
         << userData.milesOnBusPerMonth << ","
         << userData.hasTraveledByAirplane << ","
         << userData.airplaneMilesThisYear << ","
         << userData.wasteScore << ","
         << userData.energyScore << ","
         << userData.waterScore << ","
         << userData.foodScore << "\n";
    file.close();
}

int main() {
    std::list<UserData> users;  // Using std::list as a linked list

    printQuestion("Enter the number of users: ");
    int numberOfUsers = getUserInputInt();

    for (int i = 0; i < numberOfUsers; ++i) {
        UserData userData;

        printQuestion("Approximately how many soft cover books do you buy/month?");
        userData.softCoverBooksPerQuarter = getUserInputInt();

        printQuestion("Approximately how many hard cover books do you buy/month?");
        userData.hardCoverBooksPerQuarter = getUserInputInt();

        printQuestion("How often buy a new article of clothing in a given month?");
        userData.articlesOfClothingPerMonth = getUserInputInt();

        printQuestion("How long have you had your current cell phone. Please approximate in years.");
        userData.cellPhoneYears = getUserInputDouble();

        printQuestion("Do you own an iPad or a Kindle?");
        if (getUserInputYesNo()){
            printQuestion("How long have you had your current eReader. Please approximate in years.");
            userData.eReaderYears = getUserInputDouble();
        }

        printQuestion("Do you own a car? (y/n)");
        if (getUserInputYesNo()) {
            std::cout << "Please select your car type (small/average/SUV/truck/hybrid): ";
            std::cin >> userData.carType;
        }

        printQuestion("Do you use alternative transportation?");
        userData.usesAlternativeTransport = getUserInputYesNo();

        printQuestion("Approximately how many miles do you drive/month?");
        userData.milesDrivenPerMonth = getUserInputDouble();

        printQuestion("Do you use the bus? (y/n)");
        userData.usesBus = getUserInputYesNo();
        if (userData.usesBus) {
            printQuestion("Approximately how many miles/month do you travel on the bus?");
            userData.milesOnBusPerMonth = getUserInputDouble();
        }

        printQuestion("Have you travelled or plan to travel on airplane this year?");
        if (getUserInputYesNo()){
            std::cout<<"How many mile have you travelled or plan to travel this year?"<<std::endl;
            userData.airplaneMilesThisYear = getUserInputDouble();
        }

        printQuestion("Approximately what is your weekly consumption of food (in kilograms) per month?");
        userData.foodConsumption = getUserInputDouble();

        printQuestion("Approximately how many liters of water do you use per month?");
        userData.waterConsumption = getUserInputDouble();

        printQuestion("How many members live with you?");
        userData.nMem = getUserInputInt();

        printQuestion("Approximately how many kilowatt-hours of electricity do you use per month?");
        userData.energyScore = getUserInputDouble();

        printQuestion("How much household waste do you generate on a monthly basis?");
        userData.wasteGen = getUserInputDouble();

        // Calculate carbon footprints
        calculateFootprints(userData);

        // Save user data to linked list
        users.push_back(userData);

        printCarbonFootprints(userData);

        saveUserDataToCSV(userData);
    }

    // Save user data to CSV file
    std::ofstream file("user_cf_data.csv", std::ios::app);  // Open file in append mode
    file << "SoftCoverBooks,HardCoverBooks,ArticlesOfClothing,CellPhoneYears,"
        "EReaderYears,UsesAlternativeTransport,CarType,MilesDrivenPerMonth,"
        "UsesBus,MilesOnBusPerMonth,HasTraveledByAirplane,AirplaneMilesThisYear,"
        "WasteScore,EnergyScore,WaterScore,FoodScore\n";

    for (const auto& userData : users) {
        file << userData.softCoverBooksPerQuarter << ","
             << userData.hardCoverBooksPerQuarter << ","
             << userData.articlesOfClothingPerMonth << ","
             << userData.cellPhoneYears << ","
             << userData.eReaderYears << ","
             << userData.usesAlternativeTransport << ","
             << userData.carType << ","
             << userData.milesDrivenPerMonth << ","
             << userData.usesBus << ","
             << userData.milesOnBusPerMonth << ","
             << userData.hasTraveledByAirplane << ","
             << userData.airplaneMilesThisYear << ","
             << userData.wasteScore << ","
             << userData.energyScore << ","
             << userData.waterScore << ","
             << userData.foodScore <<"\n";
    }

    std::cout << "\nUser data and carbon footprints saved successfully." << std::endl;

    return 0;
}