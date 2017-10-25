#ifndef ORARIO_H
#define ORARIO_H
#include <iostream>

class Orario {
private:
    int sec;
    static Orario intToOrario(int);
public:
    Orario(int = 0, int = 0, int = 0);
    int ore() const;
    int minuti() const;
    int secondi() const;

    bool operator==(const Orario&) const;
    bool operator!=(const Orario&) const;
    bool operator>(const Orario&) const;
    bool operator<(const Orario&) const;
    bool operator>=(const Orario&) const;
    bool operator<=(const Orario&) const;
    friend Orario operator+(const Orario&, const Orario&);
    friend Orario operator-(const Orario&, const Orario&);

};

std::ostream& operator<<(std::ostream&, const Orario&); //output operator

#endif // ORARIO_H
