//
// Created by david on 2023. 05. 05..
//

#ifndef TELEFONKONYV_TELEFONKONYV_H
#define TELEFONKONYV_TELEFONKONYV_H

#include "fstream"
#include "Bejegyzes.h"
#include "Ember.h"
#include "Ceg.h"

class Telefonkonyv {
    static size_t emberek;
    static size_t cegek;
    size_t len;
    Bejegyzes **tabla;
public:
    Telefonkonyv()  {}

    static  void setEmber(size_t ember) {emberek = ember;}
    static  void setCeg(size_t ceg) {cegek = ceg;}

    size_t getLen() {return len;}

    void beszur(Ember* uj);
    void beszur(Ceg* uj);

    void listaz ();

    size_t keres(const String& nev);

    void szerkeszt(size_t idx);

    void torol(size_t idx);

    void fileBeolvas(const char* fileNev);

    void fileKiir(char* fileNev);

    void clear();

    ~Telefonkonyv() {
        if (len != 0) clear();
        emberek=0;
        cegek=0;
        len=0;
    }
};


#endif //TELEFONKONYV_TELEFONKONYV_H
