#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

void sh();
void icon();
int checker();

namespace storage {
    class product;
    class driver;
    class date {
    private:
        int month;
        int year;
        int day;
    public:
        friend istream &operator>>(istream &in, storage::date &date);
        friend ostream &operator<<(ostream &out, const storage::date &date);
        date();
        date(int m_day, int m_month, int m_year);
        date(const date&date);
        ~date(){}
    };

    class datauser {
    protected:
        string name;
        string fam;
        string och;
        string position;
        date bith;
        int numphone;
    public:
        datauser();
        datauser(string m_name, string m_fam, string m_och, int m_num, date m_date,string m_position);
        datauser(const datauser&datauser);
        virtual void print() = 0;
    };

    class driver : datauser {
    private:
        string car;
        string regnum;
    public:
        friend istream &operator>>(istream &in, storage::driver &driver);
        friend ostream &operator<<(ostream &out, const storage::driver &driver);
        friend void editpoledrivers(vector<driver>&drivers);
        driver();
        driver(string m_name, string m_fam, string m_och, int m_num, date m_date,string m_position,  string m_car, string m_regnum);
        driver(const driver&driver);
        void print();
    };

    class tenant:datauser
    {
    private:
        string company;
        string numpass;
        int sizeproducts;
    public:
        friend istream &operator>>(istream &in, storage::tenant &tenant);
        friend ostream &operator<<(ostream &out, const storage::tenant &tenant);
        friend bool operator== (const storage::tenant&tenant1,const storage::tenant&tenant2);
        friend void delbox(vector<tenant>&tenants, vector<product>&products);
        friend void viewtenant(vector<tenant>tenants, vector<product>products);
        friend class product;
        tenant();
        tenant(string m_name, string m_fam, string m_och, int m_num, date m_date,string m_position,  string m_company, string m_numpass, int m_sizeproducts);
        tenant(const tenant &tenant);
        void print();
    };

    class security:datauser
    {
    private:
        string smena;
    public:
        friend istream &operator>>(istream &in, storage::security &security);
        friend ostream &operator<<(ostream &out, const storage::security &security);
        friend void editpolesecurities(vector<security>&securities);
        security();
        security(string m_name, string m_fam, string m_och, int m_num, date m_date, string m_position, string m_smena);
        security(const security&security);
        void print();
    };

    class loader:datauser
    {
    private:
        int category;
    public:
        friend istream &operator>>(istream &in, storage::loader &loader);
        friend ostream &operator<<(ostream &out, const storage::loader &loader);
        friend void editpoleloaders(vector<loader>&loaders);
        loader();
        loader(string m_name, string m_fam, string m_och, int m_num, date m_date,string m_position,  int m_category);
        loader(const loader&loader);
        void print();
    };

    class product {
    private:
        static int idgen;
        int id;
        string name;
        string type;
        int area;
        string status;
        date in;
        driver whoin;
        tenant whos;
        string extrainfo;
    public:
        friend ostream &operator<<(ostream &out, const storage::product &product);
        friend void delbox(vector<tenant>&tenants, vector<product>&products);
        friend void moreinfo(vector<product>products);
        friend void viewtenant(vector<tenant>tenants, vector<product>products);
        friend void editbox(vector<product>&boxs, vector<driver>&vodil);
        product();
        product(string m_name, string m_type, int m_area, string m_status, date m_in,driver m_whoin,tenant m_whos,string m_extrainfo);
        product(const product&product);
        void printpro();
        void vvodpro(vector<tenant>&arend,vector<driver>&drivers,vector<product>&products);
    };
}

using namespace storage;

void stuff(vector<driver>&, vector<loader>&, vector<security>&);
void editdriver(vector<driver>&);
void deldriver(vector<driver> &);
void editloader(vector<loader>&);
void delloader(vector<loader>&);
void delsecurity(vector<security>&);
void editsecurity(vector<security>&);
void moreinfodriver(vector<driver>);
void moreinfoloader(vector<loader>);
void moreinfosecurity(vector<security>);
void menuiconbox();
void menuiconother();
//#ifndef LB_MG_3S_4_CLASS_H
//#define LB_MG_3S_4_CLASS_H

//#endif //LB_MG_3S_4_CLASS_H