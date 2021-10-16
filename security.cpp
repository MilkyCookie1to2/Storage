#include "../class .h"

storage::security::security():datauser() {
    smena = "N/N";
    position = "Охранник";
}

storage::security::security(string m_name, string m_fam, string m_och, int m_num, date m_date, string m_position, string m_smena): datauser(m_name, m_fam,m_och,m_num,m_date,m_position)
{
    smena = m_smena;
}

storage::security::security(const security &security): datauser(security) {
    smena = security.smena;
}

void storage::security::print() {
    cout << "Фамилия: " << fam<<endl;
    cout << "Имя: " << name<<endl;
    cout << "Отчество: " << och<<endl;
    cout << "Номер телефона: +375" << numphone <<endl;
    cout << "Дата рождения: " << bith <<endl;
    cout << "Должность: " << position<<endl;
    cout << "Рабочая смена: " << smena << endl;
}

namespace storage
{
    istream&operator>>(istream&in,storage::security &security)
    {
        cout << "Введите фамилию: ";
        in >> security.fam;
        cout << "Введите имя: ";
        in >> security.name;
        cout << "Введите отчество: ";
        in >> security.och;
        cout << "Введите номер телефона: +375";
        while((!(in>>security.numphone))||(security.numphone <100000000)||(security.numphone>1000000000))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "ERROR: Неправильный формат\n";
            cout << "Введите номер телефона: +375";
        }
        cout << "Введите дату рождения: ";
        in >> security.bith;
        cout << "Выберите рабочую смену:\n\t1. Дневная\n\t2. Ночная\n\t";
        int vvod = 0;
        while((vvod<1)||(vvod>2)) {
            vvod =checker();
            switch (vvod) {
                case 1: {
                    security.smena = "Дневная";
                    break;
                }
                case 2: {
                    security.smena = "Ночная";
                    break;
                }
            }
        }
        return in;
    }

    ostream&operator<<(ostream&out,const storage::security&security)
    {
        out  << security.fam<<" "  << security.name <<" " << security.och <<endl;
        return out;
    }

}