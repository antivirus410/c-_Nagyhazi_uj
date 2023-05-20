#include <iostream>
#include "fstream"
#include "string5.h"
#include "Bejegyzes.h"
#include "Ceg.h"
#include "Ember.h"
#include "Telefonkonyv.h"

int main() {

    int option;
    bool running = true;
    String filename;

    std::cout << "              TELEFONKONYV\n";
    std::cout << "Kerem adja meg a telefonkonyvet tartalmazo file nevet, kiterjesztessel(pl:telefonkonyv.txt): ";
    std::cin >> filename;

    Telefonkonyv file;
    try {
        file.fileBeolvas(filename.c_str());
    }catch (const char*) {
        running=false;
        std::cout << "Nem sikerult megnyitni a file-t!\n";
    }


    while (running) {
menu:
        std::cout << "\nA menupont valasztasahoz nyomaj meg a megfelelo gomobt!\n";
        std::cout << "1. A telefonkonyv kilistazasa\n2. Uj nevjegy felvetele\n3. Kereses a telefonkonyvben\n4. Meglevo bejegyzes szerkesztese\n5. Meglevo bejegyzes torlese\n6. Kilepes\n";
        std::cin >> option;
        switch (option) {
            case 1: {
                file.listaz();
                break;
            }
            
            case 2: {
                int createOption;
                std::cout << "1. Ember beszurasa\n2. Ceg beszurasa\n3. Visszalepes\n";
                std::cin >> createOption;
                switch (createOption) {
                    case 1: {
                        String nev, cim, becenev, kozTer, hazszam, space = " ";
                        int privSzam, munkaSzam;
                        std::cout << "Adja meg az Ember adatait(nev lakcim becenev privatszam munkahelyiszam): ";
                        std::cin >> nev >> cim >> kozTer >> hazszam >> becenev >> privSzam >> munkaSzam;
                        cim += space + kozTer + space + hazszam;
                        Ember* uj = new Ember(nev,cim,munkaSzam,becenev,privSzam);
                        file.beszur(uj);
                    }
                    case 2: {
                        String nev, cim, tipus, kozTer, hazszam, space = " ";
                        int adoSzam, munkaSzam;
                        std::cout << "Adja meg a Ceg adatait(nev cim tipus adoszam munkhelyiaszam): ";
                        std::cin >> nev >> cim >> kozTer >>  hazszam >> tipus >> adoSzam >> munkaSzam;
                        cim += space + kozTer + space + hazszam;
                        Ceg *uj= new Ceg(nev, cim, munkaSzam, tipus, adoSzam);
                        file.beszur(uj);
                    }
                    case 3: {goto menu;}
                }
                break;
            }
            
            case 3: {
                int keresOption;
                String nev;
                std::cout << "1. Kereses\n2. Visszalepes\n";
                std::cin >> keresOption;
                switch (keresOption) {
                    case 1: {
                        size_t idx;
                        std::cout << "Adja meg a keresett nevet: ";
                        std::cin >> nev;
                        idx = file.keres(nev); /// TODO: valamit kell baszni a void/size_t returnnak
                    }
                    case 2: {goto menu;}
                }
                break;
            }
            
            case 4: {
                int szerkeszOption;
                std::cout << "1. Szerkesztes\n2. Visszalepes\n";
                std::cin >> szerkeszOption;
                switch (szerkeszOption) {
                    case 1: {
                        size_t idx;
                        std::cout << "Adja meg a szerkeszteni kivant bejegyzes indexet:";
                        std::cin >> idx;
                        file.szerkeszt(idx);
                    }
                    case 2: {goto menu;}
                }
                break;
            }
            
            case 5: {
                int torolOption;
                std::cout << "1. Torles\n2. Visszalepes\n";
                std::cin >> torolOption;
                switch (torolOption) {
                    case 1: {
                        size_t idx;
                        std::cout << "Adja meg a torlni kivant bejegyzes indexet: ";
                        std::cin >> idx;
                        file.torol(idx);
                    }
                    case 2: {goto menu;}
                }
                break;
            }

            case 6: {running = false;}
        }
    }

    return 0;
}
