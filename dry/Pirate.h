
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int bounty;

public:
    Pirate(const string& name,int bounty);
    Pirate()=default;
    Pirate(const Pirate& other);
    Pirate& operator=(const Pirate& other);
    ~Pirate() = default;

    void setName(const string& name);
    void setBounty(int bounty);
    int getBounty();
    string getName();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
