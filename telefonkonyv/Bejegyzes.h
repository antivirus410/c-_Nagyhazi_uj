//
// Created by david on 2023. 05. 04..
//

#ifndef TELEFONKONYV_BEJEGYZES_H
#define TELEFONKONYV_BEJEGYZES_H

#include "string5.h"

class Bejegyzes {
    String nev;
    String cim;
    int munkaSzam;

public:
    Bejegyzes(): nev(""), cim(""), munkaSzam(0) {}
    Bejegyzes(const String neve, const String cime, int munkaSzama) : nev(neve), cim(cime), munkaSzam(munkaSzama) {}
    int osszehasonlit (const String& rhs);
    int osszehasonlit (const Bejegyzes* rhs);
    virtual void kiir(std::ostream& os=std::cout) {}
    virtual void fkiir(std::ostream& os) {}



    String getNev() {return nev;}
    String getCim() {return cim;}
    int getMunkaSzam() const {return munkaSzam;}

    virtual ~Bejegyzes(){}
};


#endif //TELEFONKONYV_BEJEGYZES_H