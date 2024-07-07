
#include "Pirate.h"


Pirate::Pirate(const string& name,int bounty): name(name),bounty(bounty) {}

Pirate::Pirate(const Pirate &other){
    this->name=other.name;
    this->bounty=other.bounty;
}

Pirate &Pirate::operator=(const Pirate &other) {
    if(this == &other){
        return *this;
    }
    this->name=other.name;
    this->bounty=other.bounty;
    return *this;
}

void Pirate::setName(const string& name){
    this->name = name;
}

void Pirate::setBounty(int bounty) {
    this->bounty=bounty;
}

std::string Pirate::getName(){
    return name;
}

int Pirate::getBounty() {
    return bounty;
}

std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name;
    os << pirate.bounty;
    return os;
}
