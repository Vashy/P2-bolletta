#include "bolletta.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    Telefonata t1(Orario(14,15), Orario(14,19), PhoneNumber("0444838383"));
    Telefonata t2(Orario(15,15), Orario(15,24), PhoneNumber("0444838383"));
    Telefonata t3(Orario(16,2), Orario(17), PhoneNumber());
    Bolletta b1, b2;
    b1.aggiungiTelefonata(t1);
    b1.aggiungiTelefonata(t2);
    b1.aggiungiTelefonata(t3);

    b2 = b1;
    b1.togliTelefonata(t2);

    cout << b1 << endl << b2;
    return 0;
}
