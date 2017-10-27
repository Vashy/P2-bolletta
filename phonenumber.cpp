#include "phonenumber.h"

PhoneNumber::PhoneNumber(std::string pre, std::string n) : prefix(pre), number(n) {}

PhoneNumber::PhoneNumber(std::string n) : prefix(""), number(n) {}

std::string PhoneNumber::getFullNumber() const {
    std::string res = prefix;
    res += number; //append
    return res;
}

std::string PhoneNumber::getPrefix() const {
    return prefix;
}

std::string PhoneNumber::getNumber() const {
    return number;
}

//OPERATORS

bool PhoneNumber::operator ==(const PhoneNumber& p) const {
    std::string n1 = prefix, n2 = p.prefix;
    n1 += number;
    n2 += p.number;
    return n1 == n2;
}

bool PhoneNumber::operator !=(const PhoneNumber& p) const {
    std::string n1 = prefix, n2 = p.prefix;
    n1 += number;
    n2 += p.number;
    return n1 != n2;
}

std::ostream& operator <<(std::ostream& out, const PhoneNumber& p) {
    if (p.getPrefix() != "")
        out << p.getPrefix() << "-" << p.getNumber();
    else
        out << p.getFullNumber();
    return out;
}
