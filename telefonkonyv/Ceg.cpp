//
// Created by david on 2023. 05. 04..
//

#include "Ceg.h"


void Ceg::kiir(std::ostream& os) {
    os << "Ceg neve: "  << getNev() << ", Telephely cime: " << getCim() << ", Tipusa: " << tipus << ", Adoszama: " << adoSzam << ", Hivatalos telefonszam: " << getMunkaSzam() << std::endl;
}

void Ceg::fkiir(std::ostream &os) {
    os << getNev() << " " << getCim() << " " << tipus << " "<< adoSzam << " " << getMunkaSzam() << std::endl;
}