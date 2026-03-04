#include "wrapper.hpp"


void wrapper::runGame()
{
    retrievwUserInfo();
    currentUser->printUserInfo();
}

void wrapper::retrievwUserInfo()
{
    fstream file("userData.csv");
    string line, token;
    line = "hello";
    user* newUser = new user();
    getline(file, line);
    stringstream ss(line);
    getline(ss, token, ',');
    newUser->setUserName(token);
    getline(ss, token, ',');
    newUser->setPassword(token);
    getline(ss, token, ',');
    newUser->setDisplayName(token);
    getline(ss, token, ',');
    newUser->setID(stoi(token));
    getline(ss, token, ',');
    newUser->setLevel(stoi(token));
    setCurrentUser(newUser);
}