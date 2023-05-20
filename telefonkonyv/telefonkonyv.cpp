//
// Created by david on 2023. 05. 05..
//

#include "fstream"
#include "Telefonkonyv.h"
#include "Bejegyzes.h"

size_t Telefonkonyv::emberek = 0;
size_t Telefonkonyv::cegek = 0;

void Telefonkonyv::listaz() {
    for (size_t i = 0; i < len; ++i) {
        std::cout << i << ". ";
        tabla[i]->kiir();
    }
}

void Telefonkonyv::fileBeolvas(const char* fileNev) {
    std::ifstream fileIn;
    fileIn.open(fileNev, std::fstream::in);

    if (fileIn.fail()) {
        len=0;
        throw "Nem talalhato a file!\n";
    }

    fileIn >> emberek;
    fileIn >> cegek;
    len = emberek+cegek;
    if (len == 0) len = 1;
    tabla = new Bejegyzes*[len];

    for (size_t i = 0; i < emberek; ++i) {
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

void Telefonkonyv::fileKiir(char* fileNev) {
    std::ofstream fileOut;
    fileOut.open(fileNev);

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
        if (tabla[i]->osszehasonlit(nev) == 0) {
            std::cout << i << ". ";
            tabla[i]->kiir();
            return i;
        }
    }
    return -1;
}

void Telefonkonyv::szerkeszt(size_t idx) { ///TODO: Le kell tesztelni
    torol(idx);
    switch (idx<emberek) {
        case true: {
            String nev, cim, becenev, kozTer, hazszam, space = " ";
            int privSzam, munkaSzam;
            std::cout << "Adja meg az Ember adatait(nev lakcim becenev privatszam munkahelyiszam): ";
            std::cin >> nev >> cim >> kozTer >> hazszam >> becenev >> privSzam >> munkaSzam;
            cim += space + kozTer + space + hazszam;
            Ember* uj = new Ember(nev,cim,munkaSzam,becenev,privSzam);
            beszur(uj);
            break;
        }
        case false: {
            String nev, cim, tipus, kozTer, hazszam, space = " ";
            int adoSzam, munkaSzam;
            std::cout << "Adja meg a Ceg adatait(nev cim tipus adoszam munkhelyiaszam): ";
            std::cin >> nev >> cim >> kozTer >>  hazszam >> tipus >> adoSzam >> munkaSzam;
            cim += space + kozTer + space + hazszam;
            Ceg *uj= new Ceg(nev, cim, munkaSzam, tipus, adoSzam);
            beszur(uj);
            break;
        }
    }
   // beszur();

}

void Telefonkonyv::torol(size_t idx) {
    if (idx > len ) {throw "Hiba: nagyobb az index mint amennyi adat van!\n";}
    delete tabla[idx];
    tabla[idx] = nullptr;
    if (idx+1 <= emberek) {
        emberek--;
    }
    else {
        cegek--;
    }
    len--;
}


void Telefonkonyv::beszur(Ember *uj) {
            len++;
            Bejegyzes** tmp = new Bejegyzes*[len];
            if (tmp == nullptr) {throw "Nem sikerült a foglalas beszurasnal!\n";}
            size_t j=0, i;

            for(i=0; i<emberek; i++) {
                if (tabla[i] == nullptr) {}
                else if(tabla[i]->osszehasonlit(uj) < 0) {
                    tmp[j] = tabla[i];
                }
                else {
                    tmp[j] = uj;
                    j++;
                    tmp[j] = tabla[i];
                }
                j++;
            }
            if (i==j) {
                tmp[j] = uj;
                j++;
            }
            for (i = emberek; i<emberek+cegek; i++) {
                if (tabla[i] == nullptr) {}
                else {tmp[j] = tabla[i];}
                j++;
            }
            emberek++;
            delete[] tabla;
            tabla = tmp;

    }

void Telefonkonyv::beszur(Ceg *uj) {
    len++;
    Bejegyzes** tmp = new Bejegyzes*[len];
    if (tmp == nullptr) {throw "Nem sikerült a foglalas beszurasnal!\n";}
    size_t j=0, i;

    for(i=0; i<emberek; i++) {
        if (tabla[i] == nullptr) {}
        else tmp[j] = tabla[i];
        j++;
    }
    for(i=emberek; i<emberek+cegek; i++) {
        if (tabla[i] == nullptr) {}
        else if(tabla[i]->osszehasonlit(uj) < 0) {
            tmp[j] = tabla[i];
        }
        else {
            tmp[j] = uj;
            j++;
            tmp[j] = tabla[i];
        }
        j++;
    }
    cegek++;
    delete[] tabla;
    tabla = tmp;
}