#include "../class .h"

storage::tenant::tenant():datauser() {
    company = "N/N";
    numpass = "N/N";
    sizeproducts = 0;
}

storage::tenant::tenant(string m_name, string m_fam, string m_och, int m_num, date m_date,string m_position,  string m_company, string m_numpass, int m_sizeproducts): datauser(m_name, m_fam, m_och, m_num, m_date,m_position) {
    company = m_company;
    numpass = m_numpass;
    sizeproducts = m_sizeproducts;
}

storage::tenant::tenant(const tenant &tenant): datauser(tenant) {
    company = tenant.company;
    numpass = tenant.numpass;
    sizeproducts = tenant.sizeproducts;
}

void storage::tenant::print() {
    cout << "Фамилия: " << fam<<endl;
    cout << "Имя: " << name<<endl;
    cout << "Отчество: " << och<<endl;
    cout << "Номер телефона: +375" << numphone <<endl;
    cout << "Дата рождения: " << bith <<endl;
    cout << "Компания: "<< company<<endl;
    cout << "Номер паспорта: " << numpass<<endl;
}

namespace storage
{
    istream &operator>>(istream&in,storage::tenant&tenant)
    {
        cout << "Введите фамилию: ";
        in >> tenant.fam;
        cout << "Введите имя: ";
        in >> tenant.name;
        cout << "Введите отчество: ";
        in >> tenant.och;
        cout << "Введите номер телефона: +375";
        while((!(in>>tenant.numphone))||(tenant.numphone <100000000)||(tenant.numphone>1000000000))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "ERROR: Неправильный формат\n";
            cout << "Введите номер телефона: +375";
        }
        cout << "Введите дату рождения: ";
        in >> tenant.bith;
        cout <<"Введите название компании: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(in,tenant.company);
        cout <<"Введите номер паспорта: ";
        in >> tenant.numpass;
        tenant.sizeproducts++;
        return in;
    }

    ostream&operator<<(ostream&out,const storage::tenant&tenant)
    {
        out  << tenant.fam<<" " <<  tenant.name <<" " <<  tenant.och <<endl;
        return out;
    }

    bool operator== (const storage::tenant&tenant1,const storage::tenant&tenant2)
    {
        return(tenant1.fam == tenant2.fam && tenant1.name==tenant2.name && tenant1.och==tenant2.och && tenant1.numphone==tenant2.numphone
         && tenant1.numpass==tenant2.numpass );
    }
}