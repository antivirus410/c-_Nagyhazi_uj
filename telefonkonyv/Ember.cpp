//
// Created by david on 2023. 05. 04..
//

#include "string5.h"
#include "Ember.h"

void Ember::kiir(std::ostream& os) {
    os << getNev() << " " << getCim() << " " << getMunkaSzam() << " " << privatSzam << " " << becenev << std::endl;
}

void Ember::fkiir(std::ostream &os) {
    os << getNev() << " " << getCim() << " " << becenev << " "  << privatSzam << " " << getMunkaSzam() << std::endl;
}
/*
void Ember::kiir(std::ofstream& of) {
    of << " " << getCim() << " " << getMunkaSzam() << " " << privatSzam << " " << becenev << std::endl;
}*/