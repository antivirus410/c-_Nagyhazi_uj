#include <iostream>
#include "Bejegyzes.h"
#include "Ceg.h"
#include "Ember.h"
#include "Telefonkonyv.h"
#include "fstream"
#include "string5.h"

int main() {

    Telefonkonyv test;

    test.beszur();

    test.listaz();

    test.fileKiir();

    //std::cout << "Fasz";
    //std::getline(be,test);
    ///telefonkonyvben lesz egy init, ott lesz a file beolvasasa+tombfeltotes és lesz egy insert op ami berakja a megfelelő pointerre

    return 0;
}
