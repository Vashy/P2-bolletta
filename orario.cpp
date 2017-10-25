#include "orario.h"

Orario::Orario(int o, int m, int s) {
    if (o < 0 || o > 23 || m < 0 || m > 59 || s < 0 || s > 59)
        sec = 0;
    else
        sec = s + m * 60 + o * 60 * 60;
}

//GETTER METHODS
int Orario::ore() const {
    return sec / 3600;
}

int Orario::minuti() const {
    return (sec % 3600) / 60;
}

int Orario::secondi() const {
    return sec % 60;
}

//RIDEFINIZIONE OPERATORI
bool Orario::operator==(const Orario& o) const {
    return sec == o.sec;
}

bool Orario::operator !=(const Orario& o) const {
    return sec != o.sec;
}

bool Orario::operator <(const Orario& o) const{
    return sec < o.sec;
}

bool Orario::operator >(const Orario& o) const{
    return sec > o.sec;
}

bool Orario::operator <=(const Orario& o) const{
    return sec <= o.sec;
}

bool Orario::operator >=(const Orario& o) const{
    return sec > o.sec;
}

Orario operator +(const Orario& o1, const Orario& o2) {
    int result = o1.sec + o2.sec;
    return result % 86400; //sec in un giorno
}

Orario operator -(const Orario& o1, const Orario& o2) {
    if (o1.sec < o2.sec)
        return Orario();

    int tmp = o1.sec - o2.sec;
    return Orario::intToOrario(tmp);
}

std::ostream& operator <<(std::ostream& out, const Orario& o) {
    if (o.ore() < 10)
        out << "0" << o.ore();
    else
        out << o.ore();

    if (o.minuti() < 10)
        out << ":0" << o.minuti();
    else
        out << ":" << o.minuti();

    if (o.secondi() < 10)
        out << ":0" << o.secondi();
    else
        out << ":" << o.secondi();

    return out;
}

//aux private static functions
Orario Orario::intToOrario(int _sec) {
    _sec %= 86400;
    int o = _sec / 3600;
    int m = _sec % 3600 / 60;
    int s = _sec % 60;
    return Orario(o, m, s);
}

