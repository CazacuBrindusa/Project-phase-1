#define _CRT_SECURE_NO_WARNINGS

#include "Ticket.h"
#include <iostream>
#include <string>
#include<cstring>
#include <vector>
using namespace std;

class Payment
{
    char* tip_plata; //o=online; f=fizic
    int payment_id;
    float amount;
    bool metoda; //0=card, 1=cash
    vector <Ticket> lista;

public:

    char* gettip_plata();
    int getpayment_id();
    float getamount() const;
    bool getmetoda();
    vector <Ticket> getlista();

    void settip_plata(char* tip_plata);
    void setpayment_id(int payment_id);
    void setamount(float amount);
    void setmetoda(bool metoda);
    void setlista(vector <Ticket> lista);

    Payment();
    Payment(char* tip_plata, int payment_id, float amount, bool metoda);
    Payment(const Payment& p);
    Payment(int payment_id);
    Payment(int payment_id, float amount);
    Payment& operator =(const Payment& p);

    void modify(vector <Payment>& listaPayment);
    void deleting(vector <Payment>& listaPayment);
    void filtru(vector <Payment>& listaPayment);

    friend ostream& operator << (ostream& out, const Payment& p);
    friend istream& operator >> (istream& in, Payment& p);
    bool operator <(const Payment& p);
    bool operator <(float a);
    friend bool operator <(float a, const Payment& p);
    bool operator <=(const Payment& p);
    bool operator <=(float a);
    friend bool operator <=(float a, const Payment& p);
    bool operator >(const Payment& p);
    bool operator >(float a);
    friend bool operator >(float a, const Payment& p);
    bool operator >=(const Payment& p);
    bool operator >=(float a);
    friend bool operator >=(float a, const Payment& p);
    Payment& operator ++();
    Payment operator ++(int);
    Payment operator +(const Payment& a);
    Payment operator +(float p);
    friend Payment operator +(float p, const Payment& a);
    Payment& operator --();
    Payment operator --(int);
    Payment operator -(const Payment& a);
    Payment operator -(float p);
    friend Payment operator -(float p, const Payment& a);
    bool operator ==(const Payment& p);
    Payment operator +(const Ticket& t);
    friend Payment operator + (const Ticket& t, Payment& p);
    bool operator ! ();
    explicit operator float();
    ~Payment();
};
