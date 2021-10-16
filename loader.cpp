#include "../class .h"

storage::loader::loader():datauser()
{
    category =0;
    position = "Грузчик";
}

storage::loader::loader(string m_name, string m_fam, string m_och, int m_num, date m_date,string m_position,  int m_category): datauser(m_name, m_fam, m_och, m_num, m_date,m_position) {
    category = m_category;
}

storage::loader::loader(const loader &loader): datauser(loader) {
    category = loader.category;
}

void storage::loader::print() {
    cout << "Фамилия: " << fam<<endl;
    cout << "Имя: " << name<<endl;
    cout << "Отчество: " << och<<endl;
    cout << "Номер телефона: +375" << numphone <<endl;
    cout << "Дата рождения: " << bith <<endl;
    cout << "Должность: " << position<<endl;
    cout << "Разряд: " << category<<endl;
}

namespace storage
{
    istream &operator >>(istream&in,storage::loader &loader)
    {
        cout << "Введите фамилию: ";
        in >> loader.fam;
        cout << "Введите имя: ";
        in >> loader.name;
        cout << "Введите отчество: ";
        in >> loader.och;
        cout << "Введите номер телефона: +375";
        while((!(in>>loader.numphone))||(loader.numphone <100000000)||(loader.numphone>1000000000))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "ERROR: Неправильный формат\n";
            cout << "Введите номер телефона: +375";
        }
        cout << "Введите дату рождения: ";
        in >> loader.bith;
        cout << "Введите разряд: ";
        while(!(in>>loader.category))
        {
            if ((loader.numphone <1)||(loader.numphone>2)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "ERROR: Такого разряда не существет\n";
                cout << "Введите разряд: ";
            }
            else
                break;
        }
        return in;
    }

    ostream &operator<<(ostream&out,const storage::loader&loader)
    {
        out << loader.fam<<" " << loader.name <<" " << loader.och<<endl;
        return out;
    }
}