//
// Created by david on 2023. 05. 05..
//

#include "telefonkonyv.h"
#include "Bejegyzes.h"
#include "fstream"

size_t Telefonkonyv::emberek = 0;
size_t Telefonkonyv::cegek = 0;

void Telefonkonyv::listaz() {
    for (size_t i = 0; i < len; ++i) {
        tabla[i]->kiir();
        //tabla[i]->osszehasonlit("Ceg");
    }
}

void Telefonkonyv::fileBeolvas() {
    std::ifstream fileIn;
    String nameFile;
    std::cout << "Irja be a file nevet! ";
    std::cin >> nameFile;
    fileIn.open(nameFile.c_str(), std::fstream::in);

    if (!fileIn.is_open()) {
        std::cout << "Nem talalhato a file!\n";
    }

    fileIn >> emberek;
    fileIn >> cegek;
    len = emberek+cegek;
    if (len == 0) len = 1;
    tabla = new Bejegyzes*[len];

    for (int i = 0; i < emberek; ++i) {
        String nev, cim, becenev, kozTer, hazszam, space = " ";
        int privSzam, munkaSzam;
        fileIn >> nev >> cim >> kozTer >>  hazszam >> becenev >> privSzam >> munkaSzam;
        cim += space + kozTer + space + hazszam;
        tabla[i] = new Ember(nev, cim, munkaSzam, becenev , privSzam);
    }
    for (size_t i = emberek; i < emberek+cegek; ++i) {
        String nev, cim, tipus, kozTer, hazszam, space = " ";
        int adoSzam, munkaSzam;
        fileIn >> nev >> cim >> kozTer >>  hazszam >> tipus >> adoSzam >> munkaSzam;
        cim += space + kozTer + space + hazszam;
        tabla[i] = new Ceg(nev, cim, munkaSzam, tipus, adoSzam);
    }
    fileIn.close();
}

void Telefonkonyv::fileKiir() {
    std::ofstream fileOut;
    String nameFile;
    std::cout << "Irja be a file nevet! ";
    std::cin >> nameFile;
    fileOut.open(nameFile.c_str());

    fileOut << emberek << " " << cegek << std::endl;
    for (size_t i = 0; i < emberek; ++i) {
        tabla[i]->fkiir(fileOut);
    }
    for (size_t i = emberek; i < emberek+cegek; ++i) {
        tabla[i]->fkiir(fileOut);
    }
    fileOut.close();
}

void Telefonkonyv::clear() {
    for (size_t i = 0; i < len-1; ++i) {
        delete tabla[i];
    }
    delete[] tabla;
    tabla = nullptr;
}

size_t Telefonkonyv::keres(const String& nev) {
    for (size_t i=0; i<len; i++) {
        if (tabla[i]->osszehasonlit(nev)) {
            return i; ///TODO: Szar! Rossz memoriacimet vesz át
        }
    }
    return -1;
}

void Telefonkonyv::szerkeszt() {
    //torol();
//    beszur();

}

void Telefonkonyv::torol() {

}


void Telefonkonyv::beszur() {
    std::cout << "Ember beszurasahoz nyomjon 1-est!\nCeg beszurasahoz nyomjon 2-est!\nVisszalepeshez nyomjon 3-ast!\n";
    int option;
    std::cin >> option;
    switch (option) {
        case 1: {
            String nev, cim, becenev, kozTer, hazszam, space = " ";
            int privSzam, munkaSzam;
            std::cout << "Adja meg az Ember adatait(nev lakcim becenev privatszam munkaszam): ";
            std::cin >> nev >> cim >> kozTer >>  hazszam >> becenev >> privSzam >> munkaSzam;
            cim += space + kozTer + space + hazszam;
            Bejegyzes* uj = new Ember(nev,cim,munkaSzam,becenev,privSzam);
            len++;
            Bejegyzes** tempa;
            tempa = new Bejegyzes*[len];
            size_t j=0, i;
            for(i=0; i<emberek; i++) {
                if(tabla[i]->osszehasonlit(uj) < 0) {
                    tempa[j] = tabla[i];
                }
                else {
                    tempa[j] = uj;
                    j++;
                    tempa[j] = tabla[i];
                }
                j++;
            }
            if (i==j) {
                tempa[j] = uj;
                j++;
            }
            for (i = emberek; i<emberek+cegek; ++i) {
                tempa[j] = tabla[i];
                j++;
            }
            clear();
            emberek++;
            tabla = tempa;
            break;
        }
        case 2:{
            String nev, cim, tipus, kozTer, hazszam, space = " ";
            int adoSzam, munkaSzam;
            std::cin >> nev >> cim >> kozTer >>  hazszam >> tipus >> adoSzam >> munkaSzam;
            cim += space + kozTer + space + hazszam;
            Bejegyzes *uj= new Ceg(nev, cim, munkaSzam, tipus, adoSzam);
            len++;
            Bejegyzes** tempa = new Bejegyzes*[len];

            size_t j=0;
            for(size_t i=0; i<emberek; i++) {
                tempa[j] = tabla[i];
            }
            for (size_t i = emberek; i<emberek+cegek; ++i) {
                if(tabla[i]->osszehasonlit(uj) == 1) {
                    tempa[j] = tabla[i];
                }
                else {
                    tempa[j] = uj;
                    j++;
                    tempa[j] = tabla[i];
                }
                j++;
            }
            cegek++;
            //clear();
            delete[] tabla;
            tabla = tempa;
            break;
        }
        case 3:{
            ///TODO: Meg kell csinalni a visszatero cumot
            break;
        }
    }
}