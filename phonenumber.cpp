#include "phonenumber.h"

PhoneNumber::PhoneNumber(std::string n, std::string nat) : number(n), naz(nat) {}

std::string PhoneNumber::getNumber() const {
    return number;
}

std::string PhoneNumber::getNationality() const {
    return naz;
}

//OPERATORS

bool PhoneNumber::operator ==(const PhoneNumber& p) const {
    return number == p.number;
}

bool PhoneNumber::operator !=(const PhoneNumber& p) const {
    return number != p.number;
}

std::ostream& operator <<(std::ostream& out, const PhoneNumber& p) {
    if (p.getNationality() == "it") { //output preciso per it
        out << "+39 ";
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

    return out << p.getNumber();
}
