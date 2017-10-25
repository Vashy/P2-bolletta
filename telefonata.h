#ifndef TELEFONATA_H
#define TELEFONATA_H
#include "orario.h"
#include "phonenumber.h"
#include <iostream>

class Telefonata {
private:
    Orario inizio;
    Orario fine;
    PhoneNumber number;

public:
    Telefonata(const Orario& = Orario(), const Orario& = Orario(), const PhoneNumber& = PhoneNumber());

    Orario getInizio() const;
    Orario getFine() const;
    PhoneNumber getNumber() const;

    bool operator ==(const Telefonata&) const;
    bool operator !=(const Telefonata&) const;
};

std::ostream& operator <<(std::ostream&, const Telefonata&);
#endif // TELEFONATA_H
