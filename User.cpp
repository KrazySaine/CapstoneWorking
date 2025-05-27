#include "User.h"
#include <fstream>
#include <vector>

std::vector<User> users;
const std::string dataFile = "users.txt";


void initUsers() {
    users.clear();
    std::ifstream file(dataFile);
    std::string userName, password;
    double bal;
    while (file >> userName >> password >> bal) {
        users.push_back({userName, password, bal});
    }
    file.close();
}

void saveUsers() {
    std::ofstream file(dataFile);
    for (const auto& user : users) {
        file << user.username << " " << user.password << " " << user.balance << std::endl;
    }
    file.close();
}

