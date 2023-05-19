#include <iostream>
#include "fstream"
#include "string5.h"
#include "Bejegyzes.h"
#include "Ceg.h"
#include "Ember.h"
#include "Telefonkonyv.h"

int main() {

    Telefonkonyv test;
    char *uj = "test.txt";
    test.fileBeolvas(uj);

    test.listaz();
    size_t x = 1;
    test.torol(x);
   // test.fileKiir();

    //std::cout << "Fasz";
    //std::getline(be,test);
    ///telefonkonyvben lesz egy init, ott lesz a file beolvasasa+tombfeltotes és lesz egy insert op ami berakja a megfelelő pointerre

    return 0;
}
