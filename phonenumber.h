#ifndef PHONENUMBER_H
#define PHONENUMBER_H
#include <string>
#include <iostream>

class PhoneNumber {
private:
    std::string prefix;
    std::string number;
public:
    PhoneNumber(std::string, std::string); //2 parametri: prefisso e resto del numero
    PhoneNumber(std::string = "0444-000000"); //0 e 1 parametro: numero per intero
    std::string getFullNumber() const;  //restituisce prefisso + numero
    std::string getPrefix() const;
    std::string getNumber() const;

    bool operator ==(const PhoneNumber&) const;
    bool operator !=(const PhoneNumber&) const;

};

std::ostream& operator <<(std::ostream&, const PhoneNumber&);

#endif // PHONENUMBER_H
