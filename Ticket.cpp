#define _CRT_SECURE_NO_WARNINGS

#include "Ticket.h"
#include <iostream>
#include <string>
#include<cstring>
#include <vector>
using namespace std;

int Ticket::idcontor = 1000;

const int Ticket:: getticket_id() { return this->ticket_id; }
int Ticket::getidcontor() { return idcontor; }
int Ticket::getseat_nr() { return this->seat_nr; }
double Ticket::getprice() { return this->price; }
char Ticket::getstatus() { return this->status; }

void Ticket::setseat_nr(int seat_nr)
{
    if (seat_nr != NULL)
        this->seat_nr = seat_nr;
}
void Ticket::setprice(double price)
{
    if (price != NULL)
        this->price = price;
}
void Ticket::setstatus(char status)
{
    if (status != '\n')
        this->status = status;
}

bool Ticket:: operator <(const Ticket& t)
{
    return this->price < t.price;
}
bool Ticket:: operator <(int p)
{
    return this->price < p;
}
bool operator <(int p, const Ticket& t)
{
    return p < t.price;
}
bool Ticket:: operator <=(const Ticket& t)
{
    return this->price <= t.price;
}
bool Ticket:: operator <=(int p)
{
    return this->price <= p;
}
bool operator <=(int p, const Ticket& t)
{
    return p <= t.price;
}
bool Ticket:: operator >(const Ticket& t)
{
    return this->price > t.price;
}
bool Ticket:: operator >(int p)
{
    return this->price > p;
}
bool operator >(int p, const Ticket& t)
{
    return p > t.price;
}
bool Ticket:: operator >=(const Ticket& t)
{
    return this->price >= t.price;
}
bool Ticket:: operator >=(int p)
{
    return this->price >= p;
}
bool operator >=(int p, const Ticket& t)
{
    return p > t.price;
}
Ticket& Ticket:: operator ++()
{
    this->price++;
    return *this;
}
Ticket Ticket:: operator ++(int)
{
    Ticket aux(*this);
    this->price++;
    return aux;
}
Ticket& Ticket:: operator --()
{
    this->price--;
    return *this;
}
Ticket Ticket:: operator --(int)
{
    Ticket aux(*this);
    this->price--;
    return aux;
}
Ticket Ticket:: operator +(const Ticket& t)
{
    Ticket aux(*this);
    aux.price = t.price + aux.price;
    return aux;
}
Ticket Ticket:: operator +(double p)
{
    Ticket aux(*this);
    aux.price = aux.price + p;
    return aux;
}
Ticket operator +(double p, const Ticket& t)
{
    Ticket aux(t);
    aux.price = aux.price + p;
    return aux;
}
Ticket Ticket:: operator -(const Ticket& t)
{
    Ticket aux(*this);
    aux.price = aux.price - t.price;
    return aux;
}
Ticket Ticket:: operator -(double p)
{
    Ticket aux(*this);
    aux.price = aux.price - p;
    return aux;
}
Ticket operator -(double p, const Ticket& t)
{
    Ticket aux(t);
    aux.price = p - aux.price;
    return aux;
}
bool Ticket:: operator ==(const Ticket& t)
{
    Ticket aux(*this);
    return aux.seat_nr == t.seat_nr &&
        aux.price == t.price &&
        aux.status == t.status;
}
Ticket Ticket:: operator !()
{
    this->status = 'a';
    return *this;
}
Ticket::operator char()
{
    return this->status;
}
Ticket::operator double()
{
    return this->price;
}
Ticket::~Ticket()
{

}


Ticket::Ticket() : ticket_id(idcontor++)
{
    this->seat_nr = 0;
    this->price = 0;
    this->status = 'u';
}
Ticket::Ticket(int ticket_id, int seat_nr, double price, char status) :ticket_id(idcontor++)
{
    this->seat_nr = seat_nr;
    this->price = price;
    this->status = status;
}
Ticket::Ticket(int seat_nr) : ticket_id(idcontor++)
{
    this->seat_nr = seat_nr;
    this->price = 0;
    this->status = 'u';
}
Ticket::Ticket(int seat_nr, double price) : ticket_id(idcontor++)
{
    this->seat_nr = seat_nr;
    this->price = price;
    this->status = 'u';
}
Ticket::Ticket(const Ticket& t) :ticket_id(idcontor++)
{
    this->seat_nr = t.seat_nr;
    this->price = t.price;
    this->status = t.status;
}
void Ticket::modify(vector <Ticket>& listaTicket)
{
    int nr, ci = 0;
    double p;
    cout << "Which is the seat of the ticket that you want to modify? ";
    cin >> nr;
    cout << endl;
    for (int i = 0; i < listaTicket.size(); i++)
        if (listaTicket[i].getseat_nr() == nr)
        {
            ci = i;
            break;
        }
    cout << "Which is the new price? ";
    cin >> p;
    cout << endl;
    listaTicket[ci].setprice(p);
}
void Ticket::deleting(vector <Ticket>& listaTicket)
{
    int nr, ci;
    bool ok = 0;
    cout << "Which is the seat of the ticket that you want to delete? ";
    cin >> nr;
    cout << endl;
    for (int i = 0; i < listaTicket.size() && ok == 0; i++)
    {
        cout << listaTicket[i].getseat_nr();
        if (listaTicket[i].getseat_nr() == nr)
        {
            ci = i;
            ok = 1;
        }
    }
    listaTicket.erase(listaTicket.begin() + ci);
}
void Ticket::filtru(vector <Ticket>& listaTicket)
{
    cout << "Which is the price of the ticket? ";
    double pret;
    cin >> pret;
    for (int i = 0; i < listaTicket.size(); i++)
        if (listaTicket[i].getprice() == pret)
        {
            cout << listaTicket[i];
            cout << endl;
        }
}
Ticket& Ticket::operator =(const Ticket& t)
{
    if (this != &t)
    {
        this->seat_nr = t.seat_nr;
        this->price = t.price;
        this->status = t.status;
    }
    return *this;
}
ostream& operator << (ostream& out, const Ticket& t)
{
    out << "The seat number is: " << t.seat_nr << endl;
    out << "The price is: " << t.price << endl;
    out << "The status is (s=sold, a=available, r=reserved): " << t.status << endl;
    return out;
}
istream& operator >> (istream& in, Ticket& t)
{
    cout << "The seat number is: ";
    in >> t.seat_nr;
    cout << endl;
    cout << "The price is: ";
    in >> t.price;
    cout << endl;
    cout << "The status is (s=sold, a=available, r=reserved): ";
    in >> t.status;
    cout << endl;
    return in;
}
