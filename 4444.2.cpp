#include <iostream>
#include <string>
using namespace std;

class prods {
protected:
    string name;
public:
    prods() :name(">_empty") { cout << ">_construct000;\n"; }
    prods(string _name) :name(_name) { cout << ">_construct001;\n"; }
    ~prods();

    virtual void prods_out() {
        cout << "Product: " << this->name << endl;
    }
};

class country :virtual public prods {
protected:
    string cname;
public:
    country() :cname(">_empty"), prods() { cout << ">_construct010;\n"; }
    country(string _name, string _cname) :cname(_cname), prods(_name) { cout << ">_construct011;\n"; }
    ~country();

    void country_out() {
        cout << "Country: " << cname << endl;
    }
};

class consist :virtual public prods {
protected:
    string consistency;
public:
    consist() :consistency(">_empty"), prods() { cout << ">_construct020;\n"; }
    consist(string _name, string _consistency) :consistency(_consistency), prods(_name) { cout << ">_construct021;\n"; }
    ~consist();

    void consist_out() {
        cout << "Consistency: " << consistency << endl;
    }
};

class date :public country {
protected:
    int days;
public:
    date() : days(0), country(), prods() { cout << ">_construct110;\n"; }
    date(string _name, string _cname, int _days) : days(_days), country(_cname,_name), prods(_name) { cout << ">_construct111;\n"; }
    ~date();

    void date_out() {
        cout << "Expiry date: " << cname <<" days"<< endl;
    }
};

class strg :public consist {
protected:
    string conds;
public:
    strg() : conds(">_empty"), consist(), prods() { cout << ">_construct220;\n"; }
    strg(string _name, string _consistency, string _conds) : conds(_conds), consist(_name, _consistency), prods(_name) { cout << ">_construct221;\n"; }
    ~strg();

    void strg_out() {
        cout << "Conds: " << conds << endl;
    }
};

class price :public strg, public date {
protected:
    int mon;
    string mon_unit;
public:
    //price() : mon(0), mon_unit("none"),date(), strg(), prods() { cout << ">_construct_OwO;\n"; }
    price(string _name, string _cname, string _consistency, string _conds, string _mon_unit, int _days, int _mon) : 
        mon(_mon), mon_unit(_mon_unit), strg(_name, _consistency, _conds), date( _name, _cname, _days), prods(_name) { cout << ">_construct_UwU;\n"; }
    ~price();

    void out() {
        prods_out();
        country_out();
        consist_out();
        strg_out();
        date_out();
        cout << "Price: " << mon <<" "<<mon_unit <<endl;
    }
};

void input(string& str) {
    while (true) {
        rewind(stdin);
        cout << "Input string" << endl;
        getline(cin, str);
        if (str.length() < 2) {
            cout << "\nPlease, describe this topic in more details" << endl;
            continue;
        }
        else break;
    }
}

void input(string& str, int i) {
    while (true) {
        rewind(stdin);
        cout << "Input string" << endl;
        getline(cin, str);
        if (str.length() != 3) {
            cout << "\nPlease, use 3 symbols" << endl;
            continue;
        }
        else break;
    }
}

int input() {
    int i;
    bool fail = true;
    cout << "\nInput:";
    do
    {
        cin >> i;
        if (cin.fail() || cin.rdbuf()->in_avail() > 1)
            cout << "\nError" << endl;
        else
            if(i>0)
                fail = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (fail);
    return i;
}

int main()
{
    string _name, _cname, _consistency, _conds, _mon_unit;
    int _days, _mon;

    /*price c();
    c.out();*/

    cout << "\nInput name:";
    input(_name);
    input(_cname);
    input(_consistency);
    input(_conds);
    input(_mon_unit, 0);
    _days = input();
    _mon = input();

    price a1(_name, _cname, _consistency, _conds, _mon_unit, _days, _mon);
    a1.out();
}