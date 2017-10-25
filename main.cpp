#include "telefonata.h"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    Telefonata a(Orario(5,34,12), Orario(5,39,00), PhoneNumber("3470101011"));
    cout << a << endl;
    return 0;
}
