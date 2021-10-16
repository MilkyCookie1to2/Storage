#include "../class .h"

storage::driver::driver():datauser() {
    car = regnum = "N/N";
    position = "Водитель";
}

storage::driver::driver(string m_name, string m_fam, string m_och, int m_num, date m_date, string m_position, string m_car, string m_regnum): datauser(m_name,m_fam,m_och,m_num,m_date,m_position) {
    car = m_car;
    regnum = m_regnum;
}

storage::driver::driver(const driver &driver): datauser(driver){
    car = driver.car;
    regnum = driver.car;
}

void storage::driver::print() {
    cout << "\tФамилия: " << fam<<endl;
    cout << "\tИмя: " << name<<endl;
    cout << "\tОтчество: " << och<<endl;
    cout << "\tНомер телефона: +375" << numphone <<endl;
    cout << "\tДата рождения: " << bith <<endl;
    cout << "\tДолжность: " << position<<endl;
    cout << "\tАвтомобиль: " << car<<endl;
    cout << "\tРегистрационный номер: "<<regnum<<endl;
}

namespace storage {
    istream &operator>>(istream &in, storage::driver &driver) {
        cout << "Введите фамилию: ";
        in >> driver.fam;
        cout << "Введите имя: ";
        in >> driver.name;
        cout << "Введите отчество: ";
        in >> driver.och;
        cout << "Введите номер телефона: +375";
        while((!(in>>driver.numphone))||(driver.numphone <100000000)||(driver.numphone>1000000000))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "ERROR: Неправильный формат\n";
            cout << "Введите номер телефона: +375";
        }
        cout << "Введите дату рождения: ";
        in >> driver.bith;
        cout << "Введите название автомобиля: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getline(in,driver.car);
        cout << "Введите номер автомобиля: ";
        in >> driver.regnum;
        return in;
    }

    ostream &operator <<(ostream&out,const driver &driver)
    {
        out  << driver.fam<<" " << driver.name <<" " << driver.och<<endl;
        return out;
    }
}
