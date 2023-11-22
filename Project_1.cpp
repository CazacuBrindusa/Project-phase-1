#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Event;
class Ticket;
class Customer;
class Payment;
class Location;

class Location
{
protected:
    string venue = "unknown";
    int max_nr_seats = 100000;
    int nr_rows = 100;
    string zones = "unknown";
    int* seats = nullptr;

public:
    string getvenue() { return this->venue; }
    int getmax_nr_seats() { return this->max_nr_seats; }
    int getnr_rows() { return this->nr_rows; }
    string getzones() { return this->zones; }
    int* getseats() { return this->seats; }

    void setvenue(string venue)
    {
        if (venue != "\n")
            this->venue = venue;
    }
    void setmax_nr_seats(int max_nr_seats)
    {
        if (max_nr_seats >= 0 && max_nr_seats <= 100000)
            this->max_nr_seats = max_nr_seats;
    }
    void setnr_rows(int nr_rows)
    {
        if (nr_rows >= 0 && nr_rows <= 100)
            this->nr_rows = nr_rows;
    }
    void setzones(string zones)
    {
        if (zones != "\n")
            this->zones = zones;
    }
    void setseats(int* seat)
    {
        if (seats != nullptr)
            this->seats[this->nr_rows] = seats[this->nr_rows];
    }

    //generic methods (astept sem)
    //pointer -> "rule of 3" ?
    //op [], <=
    Location();
    Location(string, int, int, string, int* seats);
    Location(const Location& l);
    Location& operator =(const Location& l);
    int operator [](int i)
    {
        if (i<0 || i>this->nr_rows)
            throw runtime_error("Out of range");
        else
            return this->seats[i];
    }
    bool operator ==(const Location& l)
    {
        Location aux(*this);
        if (aux.venue == l.venue &&
            aux.max_nr_seats == l.max_nr_seats &&
            aux.nr_rows == l.nr_rows &&
            aux.zones == l.zones)
        {
            for (int i = 0; i < aux.nr_rows; i++)
                if (aux.seats != l.seats)
                    return false;
            return true;
        }
        return false;
    }
    bool operator <(const Location& t)
    {
        return this->max_nr_seats < t.max_nr_seats;
    }
    bool operator <(int p)
    {
        return this->max_nr_seats < p;
    }
    friend bool operator <(int p, const Location& t)
    {
        return p < t.max_nr_seats;
    }
    bool operator <=(const Location& t)
    {
        return this->max_nr_seats <= t.max_nr_seats;
    }
    bool operator <=(int p)
    {
        return this->max_nr_seats <= p;
    }
    friend bool operator <=(int p, const Location& t)
    {
        return p <= t.max_nr_seats;
    }
    bool operator >(const Location& t)
    {
        return this->max_nr_seats > t.max_nr_seats;
    }
    bool operator >(int p)
    {
        return this->max_nr_seats > p;
    }
    friend bool operator >(int p, const Location& t)
    {
        return p > t.max_nr_seats;
    }
    bool operator >=(const Location& t)
    {
        return this->max_nr_seats >= t.max_nr_seats;
    }
    bool operator >=(int p)
    {
        return this->max_nr_seats >= p;
    }
    friend bool operator >=(int p, const Location& t)
    {
        return p >= t.max_nr_seats;
    }
    Location& operator ++()
    {
        this->max_nr_seats++;
        return *this;
    }
    Location operator ++(int)
    {
        Location aux(*this);
        this->max_nr_seats++;
        return aux;
    }
    Location& operator --()
    {
        this->max_nr_seats--;
        return *this;
    }
    Location operator --(int)
    {
        Location aux(*this);
        this->max_nr_seats--;
        return aux;
    }
    Location operator +(const Location& t)
    {
        Location aux(*this);
        aux.max_nr_seats = t.max_nr_seats + aux.max_nr_seats;
        return aux;
    }
    Location operator +(int p)
    {
        Location aux(*this);
        aux.max_nr_seats = aux.max_nr_seats + p;
        return aux;
    }
    friend Location operator +(int p, const Location& t)
    {
        Location aux(t);
        aux.max_nr_seats = aux.max_nr_seats + p;
        return aux;
    }
    Location operator -(const Location& t)
    {
        Location aux(*this);
        aux.max_nr_seats = aux.max_nr_seats - t.max_nr_seats;
        return aux;
    }
    Location operator -(int p)
    {
        Location aux(*this);
        aux.max_nr_seats = aux.max_nr_seats - p;
        return aux;
    }
    friend Location operator -(int p, const Location& t)
    {
        Location aux(t);
        aux.max_nr_seats = p - aux.max_nr_seats;
        return aux;
    }
    friend ostream& operator <<(ostream& out, const Location& p);
    friend istream& operator >>(istream& in, Location& p);
    ~Location() {}
};

Location::Location()
{

}
Location::Location(string venue, int max_nr_seats, int nr_rows, string zones, int* seats)
{
    setvenue(venue);
    setmax_nr_seats(max_nr_seats);
    setnr_rows(nr_rows);
    setzones(zones);
    setseats(seats);
}
Location::Location(const Location& l)
{
    setvenue(l.venue);
    setmax_nr_seats(l.max_nr_seats);
    setnr_rows(l.nr_rows);
    setzones(l.zones);
    setseats(l.seats);
}
Location& Location::operator =(const Location& l)
{
    if (this != &l)
    {
        this->venue = l.venue;
        this->max_nr_seats = l.max_nr_seats;
        this->nr_rows = l.nr_rows;
        this->zones = l.zones;
        this->seats = l.seats;
    }
    return *this;
}
ostream& operator <<(ostream& out, const Location& p)
{
    out << "The location of the venue is: " << p.venue << endl;
    out << "The maximum number of seats is: " << p.max_nr_seats << endl;
    out << "The number of rows is: " << p.nr_rows << endl;
    out << "The zone is: " << p.zones << endl;
    out << "The number of seats per row are: ";
    for (int i = 0; i < p.nr_rows; i++)
        out << p.seats[i] << endl;
    return out;
}
istream& operator >>(istream& in, Location& p)
{
    cout << "The location of the venue is: ";
    in >> p.venue;
    cout << endl;
    cout << "The maximum number of seats is: ";
    in >> p.max_nr_seats;
    cout << endl;
    cout << "The number of rows is: ";
    in >> p.nr_rows;
    cout << endl;
    cout << "The zone is: ";
    in >> p.zones;
    cout << endl;
    cout << "The number of seats per row are: ";
    for (int i = 0; i < p.nr_rows; i++)
    {
        in >> p.seats[i];
        cout << endl;
    }
    return in;
}


class Event : public Location
{
    int event_id;
    string name;
    string data;
    string timp;
    string category;

public:

    int getevent_id() { return this->event_id; }
    string getname() { return this->name; }
    string getdata() { return this->data; }
    string gettimp() { return this->timp; }
    string getcategory() { return this->category; }

    void setevet_id(int event_id)
    {
        if (event_id != NULL)
            this->event_id = event_id;
    }
    void setname(string name)
    {
        if (name != "\n")
            this->name = name;
    }
    void setdata(string data)
    {
        if (data != "\n")
            this->data = data;
    }
    void settimp(string timp)
    {
        if (timp != "\n")
            this->timp = timp;
    }
    void setcategory(string category)
    {
        if (category != "\n")
            this->category = category;
    }

    Event();
    Event(int, string, string, string, string);
    Event(const Event& e);
    Event(int);
    Event(int, string);
    Event& operator = (const Event& e);
    friend ostream& operator << (ostream& out, const Event& e);
    friend istream& operator >> (istream& in, Event& e);
    bool operator ==(const Event& e)
    {
        Event aux(*this);
        return Location:: operator == (e) &&
            aux.event_id == e.event_id &&
            aux.name == e.name &&
            aux.data == e.data &&
            aux.timp == e.timp &&
            aux.category == e.category;
    }

    ~Event()
    {
        Location::~Location();
    };
};
Event::Event() : Location()
{
    this->event_id = 0;
    this->name = "unknown";
    this->data = "unknown";
    this->timp = '0';
    this->category = '0';
}
Event::Event(int event_id, string name, string data, string timp, string category) : Location(venue, max_nr_seats, nr_rows, zones, seats)
{
    this->event_id = event_id;
    this->name = name;
    this->data = data;
    this->timp = timp;
    this->category = category;
}
Event::Event(int event_id) : Location()
{
    this->event_id = event_id;
    this->name = "unknown";
    this->data = "unknown";
    this->timp = '0';
    this->category = '0';
}
Event::Event(int event_id, string name) : Location()
{
    this->event_id = event_id;
    this->name = name;
    this->data = "unknown";
    this->timp = '0';
    this->category = '0';
}
Event::Event(const Event& e) : Location(e)
{
    this->event_id = e.event_id;
    this->name = e.name;
    this->data = e.data;
    this->timp = e.timp;
    this->category = e.category;
}
Event& Event::operator =(const Event& e)
{
    if (this != &e)
    {
        Location::operator =(e);
        this->event_id = e.event_id;
        this->name = e.name;
        this->data = e.data;
        this->timp = e.timp;
        this->category = e.category;
    }
    return *this;
}
ostream& operator << (ostream& out, const Event& e)
{
    out << (Location&)e;
    out << "The event id is: " << e.event_id << endl;
    out << "The name of the event is: " << e.name << endl;
    out << "The date of the event is: " << e.data << endl;
    out << "The time of the event is: " << e.timp << endl;
    out << "The type of the event is: " << e.category << endl;
    return out;
}
istream& operator >> (istream& in, Event& e)
{
    in >> (Location&)e;
    cout << "The event id is: ";
    in >> e.event_id;
    cout << endl;
    cout << "The name of the event is: ";
    in >> e.name;
    cout << endl;
    cout << "The date of the event is: ";
    in >> e.data;
    cout << endl;
    cout << "The time of the event is: ";
    in >> e.timp;
    cout << endl;
    cout << "The type of the event is: ";
    in >> e.category;
    cout << endl;
    return in;
}

class Ticket
{
    const int ticket_id;
    static int idcontor;
    int seat_nr;
    double price;
    char status; //s=sold, a=available, r=reserved

public:

    const int getticket_id() { return this->ticket_id; }
    static int getidcontor() { return idcontor; }
    int getseat_nr() { return this->seat_nr; }
    double getprice() { return this->price; }
    char getstatus() { return this->status; }

    void setseat_nr(int seat_nr)
    {
        if (seat_nr != NULL)
            this->seat_nr = seat_nr;
    }
    void setprice(double price)
    {
        if (price != NULL)
            this->price = price;
    }
    void setstatus(char status)
    {
        if (status != '\n')
            this->status = status;
    }

    Ticket();
    Ticket(int ticket_id, int seat_nr, double price, char status);
    Ticket(const Ticket& t);
    Ticket(int seat_nr);
    Ticket(int seat_nr, double price);
    Ticket& operator =(const Ticket& t);
    friend ostream& operator << (ostream& out, const Ticket& t);
    friend istream& operator >> (istream& in, Ticket& t);
    bool operator <(const Ticket& t)
    {
        return this->price < t.price;
    }
    bool operator <(int p)
    {
        return this->price < p;
    }
    friend bool operator <(int p, const Ticket& t)
    {
        return p < t.price;
    }
    bool operator <=(const Ticket& t)
    {
        return this->price <= t.price;
    }
    bool operator <=(int p)
    {
        return this->price <= p;
    }
    friend bool operator <=(int p, const Ticket& t)
    {
        return p <= t.price;
    }
    bool operator >(const Ticket& t)
    {
        return this->price > t.price;
    }
    bool operator >(int p)
    {
        return this->price > p;
    }
    friend bool operator >(int p, const Ticket& t)
    {
        return p > t.price;
    }
    bool operator >=(const Ticket& t)
    {
        return this->price >= t.price;
    }
    bool operator >=(int p)
    {
        return this->price >= p;
    }
    friend bool operator >=(int p, const Ticket& t)
    {
        return p > t.price;
    }
    Ticket& operator ++()
    {
        this->price++;
        return *this;
    }
    Ticket operator ++(int)
    {
        Ticket aux(*this);
        this->price++;
        return aux;
    }
    Ticket& operator --()
    {
        this->price--;
        return *this;
    }
    Ticket operator --(int)
    {
        Ticket aux(*this);
        this->price--;
        return aux;
    }
    Ticket operator +(const Ticket& t)
    {
        Ticket aux(*this);
        aux.price = t.price + aux.price;
        return aux;
    }
    Ticket operator +(double p)
    {
        Ticket aux(*this);
        aux.price = aux.price + p;
        return aux;
    }
    friend Ticket operator +(double p, const Ticket& t)
    {
        Ticket aux(t);
        aux.price = aux.price + p;
        return aux;
    }
    Ticket operator -(const Ticket& t)
    {
        Ticket aux(*this);
        aux.price = aux.price - t.price;
        return aux;
    }
    Ticket operator -(double p)
    {
        Ticket aux(*this);
        aux.price = aux.price - p;
        return aux;
    }
    friend Ticket operator -(double p, const Ticket& t)
    {
        Ticket aux(t);
        aux.price = p - aux.price;
        return aux;
    }
    bool operator ==(const Ticket& t)
    {
        Ticket aux(*this);
        return aux.seat_nr == t.seat_nr &&
            aux.price == t.price &&
            aux.status == t.status;
    }
    ~Ticket()
    {

    }
};
int Ticket::idcontor = 1000;
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


class Customer
{
    int customer_id;
    string name;
    string phone;
    string email;
    int age;

public:

    int getcustomer_id() { return this->customer_id; }
    string getname() { return this->name; }
    string getphone() { return this->phone; }
    string getemail() { return this->email; }
    int getage() { return this->age; }

    void setcustomer_id(int customer_id)
    {
        if (customer_id != NULL)
            this->customer_id = customer_id;
    }
    void setname(string name)
    {
        if (name != "\n")
            this->name = name;
    }
    void setphone(string phone)
    {
        if (phone != "\n")
            this->phone = phone;
    }
    void setemail(string email)
    {
        if (email != "\n")
            this->email = email;
    }
    void setage(int age)
    {
        if (age != NULL)
            this->age = age;
    }

    Customer();
    Customer(int customer_id, string name, string phone, string email, int age);
    Customer(const Customer& c);
    Customer(int customer_id);
    Customer(int customer_id, string name);
    Customer& operator =(const Customer& c);
    friend ostream& operator << (ostream& out, const Customer& c);
    friend istream& operator >> (istream& in, Customer& c);
    bool operator ==(const Customer& c)
    {
        Customer aux(*this);
        return aux.customer_id == c.customer_id &&
            aux.name == c.name &&
            aux.phone == c.phone &&
            aux.email == c.email &&
            aux.age == c.age;
    }
    bool operator <(const Customer& c)
    {
        return this->age < c.age;
    }
    bool operator <(int a)
    {
        return this->age < a;
    }
    friend bool operator <(int a, const Customer& c)
    {
        return a < c.age;
    }
    bool operator <=(const Customer& c)
    {
        return this->age <= c.age;
    }
    bool operator <=(int a)
    {
        return this->age <= a;
    }
    friend bool operator <=(int a, const Customer& c)
    {
        return a <= c.age;
    }
    bool operator >(const Customer& c)
    {
        return this->age > c.age;
    }
    bool operator >(int a)
    {
        return this->age > a;
    }
    friend bool operator >(int a, const Customer& c)
    {
        return a > c.age;
    }
    bool operator >=(const Customer& c)
    {
        return this->age >= c.age;
    }
    bool operator >=(int a)
    {
        return this->age >= a;
    }
    friend bool operator >=(int a, const Customer& c)
    {
        return a >= c.age;
    }
    Customer& operator ++()
    {
        this->age++;
        return *this;
    }
    Customer operator ++(int)
    {
        Customer aux(*this);
        this->age++;
        return aux;
    }
    Customer& operator --()
    {
        this->age--;
        return *this;
    }
    Customer operator --(int)
    {
        Customer aux(*this);
        this->age--;
        return aux;
    }
    Customer operator +(const Customer& c)
    {
        Customer aux(*this);
        aux.age = aux.age + c.age;
        return aux;
    }
    Customer operator +(int a)
    {
        Customer aux(*this);
        aux.age = aux.age + a;
        return aux;
    }
    friend Customer operator +(int a, const Customer& c)
    {
        Customer aux(c);
        aux.age = aux.age + a;
        return aux;
    }
    Customer operator -(const Customer& c)
    {
        Customer aux(*this);
        aux.age = aux.age - c.age;
        return aux;
    }
    Customer operator -(int a)
    {
        Customer aux(*this);
        aux.age = aux.age - a;
        return aux;
    }
    friend Customer operator -(int a, const Customer& c)
    {
        Customer aux(c);
        aux.age = a - aux.age;
        return aux;
    }
    ~Customer() {}
};
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

class Payment
{
    char* tip_plata; //o=online; f=fizic
    int payment_id;
    float amount;
    bool metoda; //0=card, 1=cash
    vector <Ticket> lista;

public:

    char* gettip_plata() { return this->tip_plata; }
    int getpayment_id() { return this->payment_id; }
    float getamount() const { return this->amount; }
    bool getmetoda() { return this->metoda; }
    vector <Ticket> getlista() { return this->lista; }

    void settip_plata(char* tip_plata)
    {
        if (this->tip_plata != NULL)
            delete[] this->tip_plata;
        this->tip_plata = new char[strlen(tip_plata) + 1];
        strcpy(this->tip_plata, tip_plata);
    }
    void setpayment_id(int payment_id) { this->payment_id = payment_id; }
    void setamount(float amount) { this->amount = amount; }
    void setmetoda(bool metoda) { this->metoda = metoda; }
    void setlista(vector <Ticket> lista) { this->lista = lista; }

    Payment();
    Payment(char* tip_plata, int payment_id, float amount, bool metoda);
    Payment(const Payment& p);
    Payment(int payment_id);
    Payment(int payment_id, float amount);
    Payment& operator =(const Payment& p);
    friend ostream& operator << (ostream& out, const Payment& p);
    friend istream& operator >> (istream& in, Payment& p);
    bool operator <(const Payment& p)
    {
        return this->amount < p.amount;
    }
    bool operator <(float a)
    {
        return this->amount < a;
    }
    friend bool operator <(float a, const Payment& p)
    {
        return a < p.amount;
    }
    bool operator <=(const Payment& p)
    {
        return this->amount <= p.amount;
    }
    bool operator <=(float a)
    {
        return this->amount <= a;
    }
    friend bool operator <=(float a, const Payment& p)
    {
        return a <= p.amount;
    }
    bool operator >(const Payment& p)
    {
        return this->amount > p.amount;
    }
    bool operator >(float a)
    {
        return this->amount > a;
    }
    friend bool operator >(float a, const Payment& p)
    {
        return a > p.amount;
    }
    bool operator >=(const Payment& p)
    {
        return this->amount >= p.amount;
    }
    bool operator >=(float a)
    {
        return this->amount >= a;
    }
    friend bool operator >=(float a, const Payment& p)
    {
        return a >= p.amount;
    }
    Payment& operator ++()
    {
        this->amount++;
        return *this;
    }
    Payment operator ++(int)
    {
        Payment aux(*this);
        this->amount++;
        return aux;
    }
    Payment operator +(const Payment& a)
    {
        Payment aux(*this);
        aux.amount = aux.amount + a.amount;
        return aux;
    }
    Payment operator +(float p)
    {
        Payment aux(*this);
        aux.amount = aux.amount + p;
        return aux;
    }
    friend Payment operator +(float p, const Payment& a)
    {
        Payment aux(a);
        aux.amount = aux.amount + p;
        return aux;
    }
    Payment& operator --()
    {
        this->amount--;
        return *this;
    }
    Payment operator --(int)
    {
        Payment aux(*this);
        this->amount--;
        return aux;
    }
    Payment operator -(const Payment& a)
    {
        Payment aux(*this);
        aux.amount = aux.amount - a.amount;
        return aux;
    }
    Payment operator -(float p)
    {
        Payment aux(*this);
        aux.amount = aux.amount - p;
        return aux;
    }
    friend Payment operator -(float p, const Payment& a)
    {
        Payment aux(a);
        aux.amount = p - aux.amount;
        return aux;
    }
    bool operator ==(const Payment& p)
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
    Payment operator +(const Ticket& t)
    {
        lista.push_back(t);
        return *this;
    }
    friend Payment operator + (const Ticket& t, Payment& p)
    {
        Ticket aux(t);
        p.lista.push_back(aux);
        return p;
    }
    ~Payment()
    {
        if (this->tip_plata != NULL)
        {
            delete[] this->tip_plata;
            this->tip_plata = NULL;
        }
    };
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


int main()
{
    bool stop = false;
    int i;
    vector <Event> listaEvent;
    vector <Ticket> listaTicket;
    vector <Customer> listaCustomer;
    vector <Payment> listaPayment;

    while (stop != true)
    {
        cout << "Apasa 1 if you want to add a data" << endl;
        cout << "Apasa 2 if you want to see the list of values" << endl;
        cout << "Apasa 3 if you want to modify an existing value" << endl;
        cout << "Apasa 4 if you want to delete an existing value" << endl;
        cout << "Apasa 5 if you want to filter after a price" << endl;
        cout << "Apasa 6 if you want to see the events in a day" << endl;
        cout << "Apasa 7 if you want to filter by age" << endl;
        cout << "Apasa 8 pentru stop" << endl;
        cout << "Introdu o comanda: " << endl;
        int comanda1, comanda2, comanda3;
        cin >> comanda1;
        switch (comanda1)
        {
        case 1:
        {
            cout << "Apasa 1 if you want to add a data in the clasa event" << endl;
            cout << "Apasa 2 if you want to add a data in the clasa ticket" << endl;
            cout << "Apasa 3 if you want to add a data in the clasa customer" << endl;
            cout << "Apasa 4 if you want to add a data in the clasa payment" << endl;
            cin >> comanda2;
            switch (comanda2)
            {
            case 1:
            {
                Event a;
                cin >> a;
                listaEvent.push_back(a);
                break;
            }
            case 2:
            {
                Ticket a;
                cin >> a;
                listaTicket.push_back(a);
                break;
            }
            case 3:
            {
                Customer a;
                cin >> a;
                listaCustomer.push_back(a);
                break;
            }
            case 4:
            {
                Payment a;
                cin >> a;
                listaPayment.push_back(a);
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 2:
        {
            cout << "Apasa 1 daca vrei sa vezi lista de valori pentru class event" << endl;
            cout << "Apasa 2 daca vrei sa vezi lista de valori pentru class ticket" << endl;
            cout << "Apasa 3 daca vrei sa vezi lista de valori pentru class customer" << endl;
            cout << "Apasa 4 daca vrei sa vezi lista de valori pentru class payment" << endl;
            cin >> comanda3;
            switch (comanda3)
            {
            case 1:
            {
                for (int i = 0; i < listaEvent.size(); i++)
                {
                    cout << listaEvent[i];
                    cout << endl;
                }
                break;
            }
            case 2:
            {
                for (int i = 0; i < listaTicket.size(); i++)
                {
                    cout << listaTicket[i];
                    cout << endl;
                }
                break;
            }
            case 3:
            {
                for (int i = 0; i < listaCustomer.size(); i++)
                {
                    cout << listaCustomer[i];
                    cout << endl;
                }
                break;
            }
            case 4:
            {
                for (int i = 0; i < listaPayment.size(); i++)
                {
                    cout << listaPayment[i];
                    cout << endl;
                }
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 3:
        {
            cout << "Apasa 1 if you want to modify a value in the class ticket" << endl;
            cout << "Apasa 2 if you want to modify a value in the class customer" << endl;
            cout << "Apasa 3 if you want to modify a value in the class payment" << endl;
            cin >> comanda2;
            switch (comanda2)
            {
            case 1:
            {
                int nr, ci = 0;
                double p;
                cout << "What is the seat of the ticket that you want to modify? ";
                cin >> nr;
                cout << endl;
                for (int i = 0; i < listaTicket.size(); i++)
                    if (listaTicket[i].getseat_nr() == nr)
                    {
                        ci = i;
                        break;
                    }
                cout << "What is the new price? ";
                cin >> p;
                cout << endl;
                listaTicket[ci].setprice(p);
                break;
            }
            case 2:
            {
                int id, ci;
                int age;
                cout << "What is the id of the customer that you want to modify? ";
                cin >> id;
                cout << endl;
                for (int i = 0; i < listaCustomer.size(); i++)
                    if (listaCustomer[i].getcustomer_id() == id)
                    {
                        ci = i;
                        break;
                    }
                cout << "What is the new age? ";
                cin >> age;
                cout << endl;
                listaCustomer[ci].setage(age);
                break;
            }
            case 3:
            {
                int id, ci;
                float p;
                cout << "What is the id of the payment that you want to modify? ";
                cin >> id;
                cout << endl;
                for (int i = 0; i < listaPayment.size(); i++)
                    if (listaPayment[i].getpayment_id() == id)
                    {
                        ci = i;
                        break;
                    }
                cout << "What is the new amount? ";
                cin >> p;
                cout << endl;
                listaPayment[ci].setamount(p);
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 4:
        {
            cout << "Apasa 1 if you want to delete an existing value from the class event" << endl;
            cout << "Apasa 2 if you want to delete an existing value from the class ticket" << endl;
            cout << "Apasa 3 if you want to delete an existing value from the class customer" << endl;
            cout << "Apasa 4 if you want to delete an existing value from the class payment" << endl;
            cin >> comanda2;
            switch (comanda2)
            {
            case 1:
            {
                int id, ci;
                cout << "What is the id of the event that you want to delete? ";
                cin >> id;
                cout << endl;
                for (int i = 0; i < listaEvent.size(); i++)
                    if (listaEvent[i].getevent_id() == id)
                    {
                        ci = i;
                        break;
                    }
                listaEvent.erase(listaEvent.begin() + ci);
                break;
            }
            case 2:
            {
                int nr, ci;
                bool ok = 0;
                cout << "What is the seat of the ticket that you want to delete? ";
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
                cout << ci;
                listaTicket.erase(listaTicket.begin() + ci);
                break;
            }
            case 3:
            {
                int id, ci;
                cout << "What is the id of the customer that you want to delete? ";
                cin >> id;
                cout << endl;
                for (int i = 0; i < listaCustomer.size(); i++)
                    if (listaCustomer[i].getcustomer_id() == id)
                    {
                        ci = i;
                        break;
                    }
                listaCustomer.erase(listaCustomer.begin() + ci);
                break;
            }
            case 4:
            {
                int id, ci;
                cout << "What is the id of the payment that you want to delete? ";
                cin >> id;
                cout << endl;
                for (int i = 0; i < listaPayment.size(); i++)
                    if (listaPayment[i].getpayment_id() == id)
                    {
                        ci = i;
                        break;
                    }
                listaPayment.erase(listaPayment.begin() + ci);
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 5:
        {
            cout << "Apasa 1 if you want to filter by the price of a ticket" << endl;
            cout << "Apasa 2 if you want to filter by the price of a payment" << endl;
            int comanda4;
            cin >> comanda4;
            switch (comanda4)
            {
            case 1:
            {
                cout << "What is the price of the ticket? ";
                double pret;
                cin >> pret;
                for (i = 0; i < listaTicket.size(); i++)
                    if (listaTicket[i].getprice() == pret)
                    {
                        cout << listaTicket[i];
                        cout << endl;
                    }
                break;
            }
            case 2:
            {
                cout << "What is the price of the payment? ";
                float pret;
                cin >> pret;
                for (i = 0; i < listaPayment.size(); i++)
                    if (listaPayment[i].getamount() == pret)
                    {
                        cout << listaPayment[i];
                        cout << endl;
                    }
                break;
            }
            default:
            {
                cout << "Incorect comand" << endl;
                break;
            }
            }
            break;
        }
        case 6:
        {
            cout << "What is the date?";
            string ziua;
            cin >> ziua;
            for (i = 0; i < listaEvent.size(); i++)
                if (listaEvent[i].getdata() == ziua)
                {
                    cout << listaEvent[i];
                    cout << endl;
                }
            break;
        }
        case 7:
        {
            cout << "What is the age?";
            int varsta;
            cin >> varsta;
            for (i = 0; i < listaCustomer.size(); i++)
                if (listaCustomer[i].getage() == varsta)
                {
                    cout << listaCustomer[i];
                    cout << endl;
                }
            break;
        }
        case 8:
        {
            stop = true;
            break;
        }
        default:
        {
            cout << "Incorect comand" << endl;
            break;
        }
        }
    }
}
