//
// Created by david on 2023. 05. 04..
//

#ifndef TELEFONKONYV_CEG_H
#define TELEFONKONYV_CEG_H

#include "Bejegyzes.h"

class Ceg: public Bejegyzes {
    String tipus;
    int adoSzam;

public:
    Ceg(const String& neve, const String& cime, int munkaSzama, const String& tipusa, int adoSzama) : Bejegyzes(neve, cime, munkaSzama), tipus(tipusa), adoSzam(adoSzama) {}
    void kiir(std::ostream& os=std::cout);
    void fkiir(std::ostream &os);

    ~Ceg() {}
};


#endif //TELEFONKONYV_CEG_H
