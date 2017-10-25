#include "phonenumber.h"

PhoneNumber::PhoneNumber(std::string n) {
    if (n.length() != PhoneNumber::size)
        number = "0444000000";
    else
        number = n;
}

unsigned int PhoneNumber::size = 10;

std::string PhoneNumber::getNumber() const {
    return number;
}

//OPERATORS

bool PhoneNumber::operator ==(const PhoneNumber& p) const {
    return number == p.number;
}

bool PhoneNumber::operator !=(const PhoneNumber& p) const {
    return number != p.number;
}

std::ostream& operator <<(std::ostream& out, const PhoneNumber& p) {
    if (p.getNumber().front() == '0') { //numero fisso
        for (unsigned int i = 0; i < p.getNumber().length(); i++) {
            if (i == 4)
                out << "-";
            out << p.getNumber()[i];
        }
        return out;
    }

    //numero di cellulare
    for (unsigned int i = 0; i < p.getNumber().length(); i++) {
        if (i == 3)
            out << "-";
        out << p.getNumber()[i];
    }
    return out;
}
