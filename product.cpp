#include "../class .h"

storage::product::product() {
    id = idgen++;
    name = type = status = extrainfo = "N/N";
    area = 0;
}

storage::product::product(string m_name, string m_type, int m_area, string m_status, date m_in, driver m_whoin,
                          tenant m_whos, string m_extrainfo){
    name = m_name;
    type = m_type;
    area = m_area;
    status = m_status;
    in = m_in;
    whoin = m_whoin;
    whos = m_whos;
    extrainfo = m_extrainfo;
}

storage::product::product(const product &product) {
    id = product.id;
    name = product.name;
    type = product.type;
    area = product.area;
    status = product.status;
    in = product.in;
    whoin = product.whoin;
    whos = product.whos;
    extrainfo = product.extrainfo;
}

namespace storage {
    ostream &operator<<(ostream &out, const product &products) {
        out << "| " << setw(2) << products.id << " | " << setw(20) << products.name << " | " << setw(6) << products.area
            << " | " << setw(15) << products.status << " |"<<endl;
        return out;
    }
}
void storage::product::printpro() {
    cout << "ID: " << id<<endl;
    cout << "Наименование товара: " << name << endl;
    cout << "Тип: " << type << endl;
    cout << "Кол-во: " << area<<endl;
    cout << "Статус: " << status << endl;
    if (status == "На складе") {
        cout << "Дата завоза: " << in << endl;
        cout << "Экспедитор: " << endl;
        whoin.print();
    }
    cout << "Владелец товара: " << whos;
    cout << "Дополнительная информация:\n\t"<<extrainfo<<"\n"<<endl;
}

void storage::product::vvodpro(vector<tenant>&arend,vector<driver>&drivers,vector<product>&products) {
    cout << "Введите наименование товара: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, name);
    cout << "Введите тип товара: ";
    cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, type);
    cout << ("Введите кол-во: ");
    area = checker();
    cout << ("Выберите статус товара:\n\t1. На складе\n\t2. Нет на складе\n\t");
    int vvod;
    while((vvod <1)||(vvod>2))
    {
        vvod = checker();
        switch(vvod)
        {
            case 1:
            {
                status = "На складе";
                cout << "Введите дату завоза:\n";
                cin >> in;
                cout <<"Экспедитор:\n\t1. Выбрать из экспедиторов склада\n\t2. Ввести данные экспедитора\n\t";
                int vvode=0;
                while((vvode <1)||(vvode>2))
                {
                    vvode = checker();
                    switch(vvode)
                    {
                        case 1: {
                            if (!drivers.empty()) {
                                for (int i = 0; i < drivers.size(); i++)
                                    cout << i + 1 << ". "<< drivers[i];
                                cout << "Введите номер экспедитора: ";
                                int vibor=0;
                                while ((vibor < 1) || (vibor > drivers.size()))
                                    vibor = checker();
                                whoin = drivers[vibor - 1];
                                break;
                            }
                            else
                                cout << "Список пуст\nВводим нового\n";
                        }
                        case 2:
                        {
                            cin >> whoin;
                            break;
                        }
                    }
                }
                break;
            }
            case 2:
            {
                status = "Нет на складе";
                break;
            }
        }
    }
    cout << "Владелец товара:\n\t1. Выбрать уже сушествующего\n\t2. Ввести данные нового\n\t";
    int vvod1=0;
    while((vvod1<1)||(vvod1>2))
    {
        vvod1 = checker();
        switch(vvod1)
        {
            case 1:
            {
                if (!arend.empty()) {
                    for (int i = 0; i < arend.size(); i++)
                        cout << i+1 << ". "<< arend[i];
                    cout << "Введите номер владельца: ";
                    int vibor=0;
                    while ((vibor < 1) || (vibor > arend.size()))
                        vibor = checker();
                    whos = arend[vibor - 1];
                    arend[vibor-1].sizeproducts++;
                    break;
                }
                else
                {
                    cout << "Список пуст\nВводим нового\n";
                }
            }
            case 2:
            {
                cin >> whos;
                arend.push_back(whos);
                break;
            }
        }
    }
    cout << "Введите дополнительную информацию: ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin,extrainfo);
}

