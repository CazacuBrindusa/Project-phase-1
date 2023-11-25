#define _CRT_SECURE_NO_WARNINGS

#include "Customer.h"
#include <iostream>
#include <string>
#include<cstring>
#include <vector>
using namespace std;

int Customer:: getcustomer_id() { return this->customer_id; }
string Customer::getname() { return this->name; }
string Customer::getphone() { return this->phone; }
string Customer::getemail() { return this->email; }
int Customer::getage() { return this->age; }

void Customer::setcustomer_id(int customer_id)
{
    if (customer_id != NULL)
        this->customer_id = customer_id;
}
void Customer::setname(string name)
{
    if (name != "\n")
        this->name = name;
}
void Customer::setphone(string phone)
{
    if (phone != "\n")
        this->phone = phone;
}
void Customer::setemail(string email)
{
    if (email != "\n")
        this->email = email;
}
void Customer::setage(int age)
{
    if (age != NULL && age>=0 && age <= 100)
        this->age = age;
}

bool Customer:: operator ==(const Customer& c)
{
    Customer aux(*this);
    return aux.customer_id == c.customer_id &&
        aux.name == c.name &&
        aux.phone == c.phone &&
        aux.email == c.email &&
        aux.age == c.age;
}
bool Customer:: operator <(const Customer& c)
{
    return this->age < c.age;
}
bool Customer:: operator <(int a)
{
    return this->age < a;
}
bool operator <(int a, const Customer& c)
{
    return a < c.age;
}
bool Customer:: operator <=(const Customer& c)
{
    return this->age <= c.age;
}
bool Customer:: operator <=(int a)
{
    return this->age <= a;
}
bool operator <=(int a, const Customer& c)
{
    return a <= c.age;
}
bool Customer:: operator >(const Customer& c)
{
    return this->age > c.age;
}
bool Customer:: operator >(int a)
{
    return this->age > a;
}
bool operator >(int a, const Customer& c)
{
    return a > c.age;
}
bool Customer:: operator >=(const Customer& c)
{
    return this->age >= c.age;
}
bool Customer:: operator >=(int a)
{
    return this->age >= a;
}
bool operator >=(int a, const Customer& c)
{
    return a >= c.age;
}
Customer& Customer:: operator ++()
{
    this->age++;
    return *this;
}
Customer Customer:: operator ++(int)
{
    Customer aux(*this);
    this->age++;
    return aux;
}
Customer& Customer:: operator --()
{
    this->age--;
    return *this;
}
Customer Customer:: operator --(int)
{
    Customer aux(*this);
    this->age--;
    return aux;
}
Customer Customer:: operator +(const Customer& c)
{
    Customer aux(*this);
    aux.age = aux.age + c.age;
    return aux;
}
Customer Customer:: operator +(int a)
{
    Customer aux(*this);
    aux.age = aux.age + a;
    return aux;
}
Customer operator +(int a, const Customer& c)
{
    Customer aux(c);
    aux.age = aux.age + a;
    return aux;
}
Customer Customer:: operator -(const Customer& c)
{
    Customer aux(*this);
    aux.age = aux.age - c.age;
    return aux;
}
Customer Customer:: operator -(int a)
{
    Customer aux(*this);
    aux.age = aux.age - a;
    return aux;
}
Customer operator -(int a, const Customer& c)
{
    Customer aux(c);
    aux.age = a - aux.age;
    return aux;
}
Customer Customer:: operator !()
{
    this->age = 100 - this->age;
    return *this;
}
Customer::operator int()
{
    return this->age;
}
Customer::~Customer() {}


Customer::Customer()
{
    this->customer_id = 0;
    this->name = "unknown";
    this->phone = "0000000000";
    this->email = "unknown";
    this->age = 0;
}
Customer::Customer(int customer_id, string name, string phone, string email, int age)
{
    this->customer_id = customer_id;
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->age = age;
}
Customer::Customer(int customer_id)
{
    this->customer_id = customer_id;
    this->name = "unknown";
    this->phone = "0000000000";
    this->email = "unknown";
    this->age = 0;
}
Customer::Customer(int customer_id, string name)
{
    this->customer_id = customer_id;
    this->name = name;
    this->phone = "0000000000";
    this->email = "unknown";
    this->age = 0;
}
Customer::Customer(const Customer& c)
{
    this->customer_id = c.customer_id;
    this->name = c.name;
    this->phone = c.phone;
    this->email = c.email;
    this->age = c.age;
}
void Customer::modify(vector <Customer>& listaCustomer)
{
    int id, ci=-1;
    double age;
    cout << "Which is the id of the customer that you want to modify? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaCustomer.size(); i++)
        if (listaCustomer[i].getcustomer_id() == id)
        {
            ci = i;
            break;
        }
    cout << "Which is the new age? ";
    cin >> age;
    cout << endl;
    listaCustomer[ci].setage(age);
}
void Customer::deleting(vector <Customer>& listaCustomer)
{
    int id, ci;
    cout << "Which is the id of the customer that you want to delete? ";
    cin >> id;
    cout << endl;
    for (int i = 0; i < listaCustomer.size(); i++)
        if (listaCustomer[i].getcustomer_id() == id)
        {
            ci = i;
            break;
        }
    listaCustomer.erase(listaCustomer.begin() + ci);
}
void Customer::filtru(vector <Customer>& listaCustomer)
{
    cout << "Which is the age?";
    int varsta;
    cin >> varsta;
    for (int i = 0; i < listaCustomer.size(); i++)
        if (listaCustomer[i].getage() == varsta)
        {
            cout << listaCustomer[i];
            cout << endl;
        }
}
Customer& Customer::operator =(const Customer& c)
{
    if (this != &c)
    {
        this->customer_id = c.customer_id;
        this->name = c.name;
        this->phone = c.phone;
        this->email = c.email;
        this->age = c.age;
    }
    return *this;
}
ostream& operator << (ostream& out, const Customer& c)
{
    out << "The client's id is: " << c.customer_id << endl;
    out << "The client's name is: " << c.name << endl;
    out << "The client's phone is: " << c.phone << endl;
    out << "The client's email is: " << c.email << endl;
    out << "The client's age is: " << c.age << endl;
    return out;
}
istream& operator >> (istream& in, Customer& c)
{
    cout << "The client's id is: ";
    in >> c.customer_id;
    cout << endl;
    cout << "The client's name is: ";
    in >> c.name;
    cout << endl;
    cout << "The client's phone is: ";
    in >> c.phone;
    cout << endl;
    cout << "The client's email is: ";
    in >> c.email;
    cout << endl;
    cout << "The client's age is: ";
    in >> c.age;
    cout << endl;
    return in;
}
