#ifndef PHONENUMBER_H
#define PHONENUMBER_H
#include <string>
#include <iostream>

class PhoneNumber {
private:
    static unsigned int size; //fisso per ogni numero di telefono
    std::string number;
public:
    PhoneNumber(std::string = "0444000000");
    std::string getNumber() const;

    bool operator ==(const PhoneNumber&) const;
    bool operator !=(const PhoneNumber&) const;

};

std::ostream& operator <<(std::ostream&, const PhoneNumber&);

#endif // PHONENUMBER_H
