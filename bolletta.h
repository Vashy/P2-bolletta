#ifndef BOLLETTA_H
#define BOLLETTA_H
#include "telefonata.h"

class Bolletta {
    friend class Iterator;
private:
    class Nodo {
    public:
        Telefonata info;
        Nodo* next;

        Nodo();
        Nodo(const Telefonata&, Nodo* = 0);
        ~Nodo();
    };
    Nodo* head; //testa della coda

    //aux private methods
    static Nodo* copy(Nodo*);

public:
    Bolletta();

    //rule of three
    Bolletta(const Bolletta&);
    ~Bolletta();
    Bolletta& operator =(const Bolletta&);

    bool isEmpty() const;   //true solo se la bolletta è vuota
    void aggiungiTelefonata(const Telefonata&); //aggiunge una Telefonata in testa
    void togliTelefonata(const Telefonata&);    //toglie la Telefonata passata come argomento
    Telefonata pop_begin(); //toglie la Telefonata in testa dalla Bolletta di invocazione, e la restituisce

    friend std::ostream& operator <<(std::ostream&, const Bolletta&);   //operatore di ostream

    class Iterator {
        friend class Bolletta;
    private:
        Bolletta::Nodo* ptr; //SERVE L'AMICIZIA!
    public:
        bool operator ==(const Iterator&) const;    //confronto ==
        bool operator !=(const Iterator&) const;    //confronto !=
        Iterator& operator ++();            //incremento prefisso
        Iterator operator ++(int);          //incremento postfisso
        Telefonata& operator *() const;     //dereferenziazione
        Telefonata* operator ->() const;    //accesso a membro Telefonata
    };

    //metodi che usano Iterator
    Iterator begin() const; //restituisce la prima Telefonata
    Iterator end() const;   //fine della lista: ptr == 0
    Telefonata& operator [](const Iterator&) const; //accesso a membro. Es (Bolletta b, Iterator it): b[it]
};

#endif // BOLLETTA_H
