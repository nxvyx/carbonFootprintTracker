
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

std::string getPassword() {
    std::string password;
    std::cout << "Enter your password: ";
    std::cin >> password;
    return password;
}

bool login(const std::vector<std::string>& userList, const std::vector<std::string>& passwordList) {
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    for (int i = 0; i < userList.size(); i++) {
        if (userList[i] == username && passwordList[i] == password) {
            std::cout << "Login successful." << std::endl;
            return true;
        }
    }
    std::cout << "Incorrect username or password. Please try again." << std::endl;
    return false;
}


void loadUserData(std::vector<std::string>& userList, std::vector<std::string>& passwordList) {
    userList.clear();
    passwordList.clear();

    std::ifstream infile;
    infile.open("login_info.txt");

    if (infile.is_open()) {
        std::string line;
        while (std::getline(infile, line)) {
            userList.push_back(line);
            std::getline(infile, line);
            passwordList.push_back(line);
        }
    }

    infile.close();
}

void signup(std::vector<std::string>& userList, std::vector<std::string>& passwordList) {
    std::string username, password;
    std::cout << "Enter a username: ";
    std::cin >> username;
    std::cout << "Enter a password: ";
    std::cin >> password;

    std::ofstream outfile;
    outfile.open("login_info.txt", std::ios::app);
    outfile << username << "\n" << password << "\n";
    outfile.close();

    loadUserData(userList, passwordList);
}

int main() {
    std::vector<std::string> userList;
    std::vector<std::string> passwordList;

    loadUserData(userList, passwordList);

    while (true) {
        std::cout << "Choose an option:\n1. Login\n2. Sign up\n3. Exit\n";
        int option;
        std::cin >> option;
        

        switch (option) {
            case 1:
                if (login(userList, passwordList)) {
                    return 0;
                }
                break;
            case 2:
                signup(userList, passwordList);
                break;
            case 3:
                std::cout << "Exiting the program..." << std::endl;
                return 0;

            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}