#include "telefonata.h"

Telefonata::Telefonata(const Orario& o1, const Orario&o2, const PhoneNumber& n)
    : inizio(o1), fine(o2), number(n){} //il check sui parametri attuali viene fatto dai costruttori

//GETTER METHODS
Orario Telefonata::getInizio() const {
    return inizio;
}

Orario Telefonata::getFine() const {
    return fine;
}

PhoneNumber Telefonata::getNumber() const {
    return number;
}

//OPERATORS
bool Telefonata::operator ==(const Telefonata& t) const {
    return (inizio == t.inizio && fine == t.fine && number == t.number);
}

bool Telefonata::operator !=(const Telefonata& t) const {
    return (inizio != t.inizio || fine != t.fine || number != t.number);
}

std::ostream& operator <<(std::ostream& out, const Telefonata& t) {
    return out << "Inizio: " << t.getInizio() << " | Fine: " << t.getFine() << " | "
        << " Numero chiamato: " << t.getNumber();
}
