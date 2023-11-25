#define _CRT_SECURE_NO_WARNINGS

#include "Payment.h"
#include "Ticket.h"
#include <iostream>
#include <string>
#include<cstring>
#include <vector>
using namespace std;

char* Payment:: gettip_plata() { return this->tip_plata; }
int Payment::getpayment_id() { return this->payment_id; }
float Payment::getamount() const { return this->amount; }
bool Payment::getmetoda() { return this->metoda; }
vector <Ticket> Payment::getlista() { return this->lista; }

void Payment::settip_plata(char* tip_plata)
{
    if (tip_plata != NULL)
    {
        if (this->tip_plata != NULL)
            delete[] this->tip_plata;
        this->tip_plata = new char[strlen(tip_plata) + 1];
        strcpy(this->tip_plata, tip_plata);
    }
    else
        throw runtime_error("Invalid imput");
}
void Payment::setpayment_id(int payment_id) 
{
    if (payment_id != NULL)
        this->payment_id = payment_id;
    else
        throw runtime_error("Invalid imput");
}
void Payment::setamount(float amount) 
{
    if (amount != NULL)
        this->amount = amount;
    else
        throw runtime_error("Invalid imput");
}
void Payment::setmetoda(bool metoda) 
{
    if (metoda != NULL && (metoda == 0 || metoda == 1))
        this->metoda = metoda;
    else
        throw runtime_error("Invalid imput");
}
void Payment::setlista(vector <Ticket> lista) 
{
    this->lista = lista;
}

bool Payment::operator <(const Payment& p)
{
    return this->amount < p.amount;
}
bool Payment::operator <(float a)
{
    return this->amount < a;
}
bool operator <(float a, const Payment& p)
{
    return a < p.amount;
}
bool Payment::operator <=(const Payment& p)
{
    return this->amount <= p.amount;
}
bool Payment::operator <=(float a)
{
    return this->amount <= a;
}
bool operator <=(float a, const Payment& p)
{
    return a <= p.amount;
}
bool Payment::operator >(const Payment& p)
{
    return this->amount > p.amount;
}
bool Payment::operator >(float a)
{
    return this->amount > a;
}
bool operator >(float a, const Payment& p)
{
    return a > p.amount;
}
bool Payment::operator >=(const Payment& p)
{
    return this->amount >= p.amount;
}
bool Payment::operator >=(float a)
{
    return this->amount >= a;
}
bool operator >=(float a, const Payment& p)
{
    return a >= p.amount;
}
Payment& Payment::operator ++()
{
    this->amount++;
    return *this;
}
Payment Payment:: operator ++(int)
{
    Payment aux(*this);
    this->amount++;
    return aux;
}
Payment Payment::operator +(const Payment& a)
{
    Payment aux(*this);
    aux.amount = aux.amount + a.amount;
    return aux;
}
Payment Payment::operator +(float p)
{
    Payment aux(*this);
    aux.amount = aux.amount + p;
    return aux;
}
Payment operator +(float p, const Payment& a)
{
    Payment aux(a);
    aux.amount = aux.amount + p;
    return aux;
}
Payment& Payment::operator --()
{
    this->amount--;
    return *this;
}
Payment Payment::operator --(int)
{
    Payment aux(*this);
    this->amount--;
    return aux;
}
Payment Payment::operator -(const Payment& a)
{
    Payment aux(*this);
    aux.amount = aux.amount - a.amount;
    return aux;
}
Payment Payment::operator -(float p)
{
    Payment aux(*this);
    aux.amount = aux.amount - p;
    return aux;
}
Payment operator -(float p, const Payment& a)
{
    Payment aux(a);
    aux.amount = p - aux.amount;
    return aux;
}
bool Payment::operator ==(const Payment& p)
{
    bool ok = false;
    Payment aux(*this);
    if (aux.tip_plata == p.tip_plata)
        if (aux.payment_id == p.payment_id)
            if (aux.amount == p.amount)
                if (aux.metoda == p.metoda)
                    ok = true;
    return ok;
}
Payment Payment::operator +(const Ticket& t)
{
    lista.push_back(t);
    return *this;
}
Payment operator + (const Ticket& t, Payment& p)
{
    Ticket aux(t);
    p.lista.push_back(aux);
    return p;
}
bool Payment::operator ! ()
{
    return !(this->metoda);
}
Payment::operator float()
{
    return this->amount;
}
Payment::~Payment()
{
    if (this->tip_plata != NULL)
    {
        delete[] this->tip_plata;
        this->tip_plata = NULL;
    }
};


Payment::Payment()
{
    this->tip_plata = new char[2];
    strcpy(this->tip_plata, "u");
    this->payment_id = 0;
    this->amount = 0;
    this->metoda = 0;
}
Payment::Payment(char* tip_plata, int payment_id, float amount, bool metoda)
{
    this->tip_plata = new char[strlen(tip_plata) + 1];
    strcpy(this->tip_plata, tip_plata);
    this->payment_id = payment_id;
    this->amount = amount;
    this->metoda = metoda;
}
Payment::Payment(int payment_id)
{
    this->tip_plata = new char[2];
    strcpy(this->tip_plata, "u");
    this->payment_id = payment_id;
    this->amount = 0;
    this->metoda = 0;
}
Payment::Payment(int payment_id, float amount)
{
    this->tip_plata = new char[2];
    strcpy(this->tip_plata, "u");
    this->payment_id = payment_id;
    this->amount = amount;
    this->metoda = 0;
}
Payment::Payment(const Payment& p)
{
    this->payment_id = p.payment_id;
    this->tip_plata = new char[strlen(p.tip_plata) + 1];
    strcpy(this->tip_plata, p.tip_plata);
    this->payment_id = p.payment_id;
    this->amount = p.amount;
    this->metoda = p.metoda;
}
void Payment::modify(vector <Payment>& listaPayment)
{
    int id, ci;
    float p;
    cout << "Which is the id of the payment that you want to modify? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaPayment.size(); i++)
        if (listaPayment[i].getpayment_id() == id)
        {
            ci = i;
            break;
        }
    cout << "Which is the new amount? ";
    cin >> p;
    cout << endl;
    listaPayment[ci].setamount(p);
}
void Payment::deleting(vector <Payment>& listaPayment)
{
    int id, ci;
    cout << "Which is the id of the payment that you want to delete? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaPayment.size(); i++)
        if (listaPayment[i].getpayment_id() == id)
        {
            ci = i;
            break;
        }
    listaPayment.erase(listaPayment.begin() + ci);
}
void Payment::filtru(vector <Payment>& listaPayment)
{
    cout << "Which is the price of the payment? ";
    float pret;
    cin >> pret;
    for (int i = 0; i < listaPayment.size(); i++)
        if (listaPayment[i].getamount() == pret)
        {
            cout << listaPayment[i];
            cout << endl;
        }
}
Payment& Payment::operator =(const Payment& p)
{
    if (this != &p)
    {
        if (this->tip_plata != NULL)
        {
            delete[] this->tip_plata;
            this->tip_plata = NULL;
        }
        this->tip_plata = new char[strlen(p.tip_plata) + 1];
        strcpy(this->tip_plata, p.tip_plata);
        this->payment_id = p.payment_id;
        this->amount = p.amount;
        this->metoda = p.metoda;
    }
    return *this;
}
ostream& operator << (ostream& out, const Payment& p)
{
    out << "The type of payment is (o pentru online, f pentru fizic): " << p.tip_plata << endl;
    out << "The payment's id is: " << p.payment_id << endl;
    out << "The payment's value is: " << p.amount << endl;
    out << "The method of payment is (0 pentru card, 1 pentru numerar): " << p.metoda << endl;
    return out;
}
istream& operator >> (istream& in, Payment& p)
{
    char aux[100];
    int m;
    cout << "The type of payment is (o pentru online, f pentru fizic): ";
    in >> aux;
    if (p.tip_plata != NULL)
        delete[] p.tip_plata;
    p.tip_plata = new char[strlen(aux) + 1];
    strcpy(p.tip_plata, aux);
    cout << endl;
    cout << "The payment's id is: ";
    in >> p.payment_id;
    cout << endl;
    cout << "The payment's value is: ";
    in >> p.amount;
    cout << endl;
    cout << "The method of payment is (0 pentru card, 1 pentru numerar): ";
    in >> m;
    if (m == 1)
        p.metoda = true;
    else
        p.metoda = false;
    cout << endl;
    return in;
}
