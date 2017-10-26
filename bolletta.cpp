#include "bolletta.h"

//class Nodo

Bolletta::Nodo::Nodo() : next(0) {} //costruttore di default per Telefonata

Bolletta::Nodo::Nodo(const Telefonata& t, Nodo* _next) : info(t), next(_next) {}    //costruttore a 2 parametri

Bolletta::Nodo::~Nodo() {
    if (next)   //chiamata ricorsiva sulla distruzione dei nodi
        delete next;
}

//class Bolletta

Bolletta::Bolletta() : head(0) {}

bool Bolletta::isEmpty() const {
    if (head)
        return true;
    return false;
}

void Bolletta::aggiungiTelefonata(const Telefonata& t) {
    head = new Nodo(t, head);
}

void Bolletta::togliTelefonata(const Telefonata& t) {
    Nodo* p = head, *prec = 0;
    while (p && p->info != t) {
        prec = p;
        p = p->next;
    }

    if (p) { //telefonata da eliminare trovata
        if (prec)  //non è nel nodo iniziale
            prec->next = p->next;

        else  //è nel nodo iniziale
            head = head->next;
        p->next = 0; //per evitare la distruzione a cascata
        delete p;
    }
}

//PRE: *this è Bolletta NON vuota
Telefonata Bolletta::pop_begin() {
    Telefonata res = head->info;
    Nodo* del = head;
    head = head->next;
    del->next = 0; //per evitare la distruzione a cascata
    delete del;
    return res;
}

Bolletta::Nodo* Bolletta::copy(Nodo* n) { //copia profonda
    if (!n)
        return 0;
    Nodo* newList = new Nodo(n->info, 0), *p = newList;
    while (n->next) {
        n = n->next;
        p->next = new Nodo(n->info, 0);
        p = p->next;
    }
    return newList;
}

Bolletta::Bolletta(const Bolletta& b) : head(copy(b.head)) {} //deep copy constructor

Bolletta& Bolletta::operator =(const Bolletta& b) {
    if (this != &b) {
        if (head)
            delete head; //distruttore ridefinito di nodo
        head = copy(b.head);
    }
    return *this;
}

Bolletta::~Bolletta() {
    if (head)
        delete head;
}

//OPERATORS

std::ostream& operator <<(std::ostream& out, const Bolletta& b) {
    out << "TELEFONATE IN BOLLETTA: \n";

    for (Bolletta::Iterator it = b.begin(); it != b.end(); it++) {
        out << *it << std::endl;
    }

    return out;
}

//class Iterator

bool Bolletta::Iterator::operator ==(const Iterator& it) const {
    return ptr == it.ptr;
}

bool Bolletta::Iterator::operator !=(const Iterator& it) const {
    return ptr != it.ptr;
}
//++prefix
Bolletta::Iterator& Bolletta::Iterator::operator ++() {
    if (ptr)
        ptr = ptr->next;
    return *this;
}
//++postfix
Bolletta::Iterator Bolletta::Iterator::operator ++(int) {
    Iterator aux = *this;
    if (ptr)
        ptr = ptr->next;
    return aux;
}

//Metodi di accesso a membro

Telefonata& Bolletta::Iterator::operator *() const {
    return ptr->info;
}

Telefonata* Bolletta::Iterator::operator ->() const {
    return &(ptr->info);
}

Bolletta::Iterator Bolletta::begin() const {
    Iterator aux;
    aux.ptr = head;
    return aux;
}

Bolletta::Iterator Bolletta::end() const {
    Iterator aux;
    aux.ptr = 0;
    return aux;
}

Telefonata& Bolletta::operator [](const Iterator& it) const {
    return it.ptr->info;
}
