#ifndef PHONENUMBER_H
#define PHONENUMBER_H
#include <string>
#include <iostream>

class PhoneNumber {
private:
    std::string number;
    std::string naz;
public:
    PhoneNumber(std::string = "0444000000", std::string = "it");
    std::string getNumber() const;
    std::string getNationality() const;

    bool operator ==(const PhoneNumber&) const;
    bool operator !=(const PhoneNumber&) const;

};

std::ostream& operator <<(std::ostream&, const PhoneNumber&);

#endif // PHONENUMBER_H
