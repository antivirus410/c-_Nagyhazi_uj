//
// Created by david on 2023. 05. 04..
//

#ifndef TELEFONKONYV_EMBER_H
#define TELEFONKONYV_EMBER_H

#include "Bejegyzes.h"

class Ember: public Bejegyzes {
    String becenev;
    int privatSzam;

public:
    Ember(const String& neve, const String& cime, int munkaSzama, const String& beceneve, int privatSzama) : Bejegyzes(neve, cime, munkaSzama), becenev(beceneve), privatSzam(privatSzama) {}
    void kiir(std::ostream& os=std::cout);
    void fkiir(std::ostream& os);


    ~Ember() {}
};


#endif //TELEFONKONYV_EMBER_H
