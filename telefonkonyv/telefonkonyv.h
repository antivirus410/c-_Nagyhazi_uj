//
// Created by david on 2023. 05. 05..
//

#ifndef TELEFONKONYV_TELEFONKONYV_H
#define TELEFONKONYV_TELEFONKONYV_H

#include "Bejegyzes.h"
#include "Ember.h"
#include "Ceg.h"
#include "fstream"

class Telefonkonyv {
    static size_t emberek;
    static size_t cegek;
    size_t len;
    Bejegyzes **tabla;
public:
    Telefonkonyv()  {
        fileBeolvas();
    }

    static  void setEmber(size_t ember) {emberek = ember;}
    static  void setCeg(size_t ceg) {cegek = ceg;}

    size_t getLen() {return len;}

    void beszur();

    void listaz ();

    size_t keres(const String& nev);

    void szerkeszt();

    void torol();

    void fileBeolvas();

    void fileKiir();

    void clear();

    ~Telefonkonyv() {
        clear();
        emberek=0;
        cegek=0;
        len=0;
    }
};


#endif //TELEFONKONYV_TELEFONKONYV_H
