#include "class .h"

int storage::product::idgen=1;

int main(){
    //sh();
    vector <product> boxs;
    vector <driver> vodils;
    vector <loader> grys;
    vector <security> ohrana;
    vector <tenant> arend;
    while(1) {
        icon();
        if (boxs.empty())
            cout << "Склад пуст\n";
        else {
            cout << "| " << setw(2) << "id" << " | " << setw(25) << " Наименование товара" << " | " << setw(6)
                 << "Кол-во" << " | " << setw(15) << "   Статус" << " |"<<endl;
            for (int i = 0; i < boxs.size(); i++)
                cout << boxs[i];
        }
        menuiconbox();
        menuiconother();
        //cout <<"\n1. Добавить товар\n2. Удалить товар\n3. Редактировать данные товара\n4. Подробная информация о товарах\n5. Сотрудники\n6. Арендатели\n7. Выход\n";
        int vvod=checker();
        switch(vvod)
        {
            case 1:
            {
                system("clear");
                boxs.push_back(product());
                boxs[boxs.size()-1].vvodpro(arend,vodils,boxs);
                system("clear");
                break;
            }
            case 2:
            {
                system("clear");
                delbox(arend,boxs);
                system("clear");
                break;
            }
            case 3:
            {
                system("clear");
                editbox(boxs,vodils);
                system("clear");
                break;
            }
            case 4:
            {
                system("clear");
                moreinfo(boxs);
                system("clear");
                break;
            }
            case 5:
            {
                system("clear");
                stuff(vodils,grys,ohrana);
                system("clear");
                break;
            }
            case 6:
            {
                system("clear");
                viewtenant(arend,boxs);
                system("clear");
                break;
            }
            case 7:
            {
                return 0;
            }
            default:
            {
                system("clear");
            }
        }
    }
    this_thread::sleep_for(chrono::seconds(5));
}

void storage::viewtenant(vector<tenant>tenants, vector<product>products)
{
    while(1) {
        if (tenants.empty()) {
            cout << "Арендаторов нет\n";
            cout << "Нажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        } else {
            cout << "\nАрендаторы:\n";
            for (int i = 0; i < tenants.size(); i++)
                cout << i + 1 << ". " << tenants[i];
        }
        int uk;
        cout << "\nВведите номер арендатора или 0 для выхода: ";
        uk = checker();
        if ((uk < 1) || (uk > tenants.size())) {
            if (uk==0)
                return;
            cout << "Такого арендатора нет";
            cout << "\nНажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("clear");
        } else {
            system("clear");
            tenants[uk - 1].print();
            cout << "\nТовары:\n";
            cout << "| " << setw(2) << "id" << " | " << setw(22) << "Наименование товара" << " | " << setw(6)
                 << "Кол-во" << " | " << setw(15) << "Статус" << " |"<<endl;
            for(int i=0;i<products.size();i++)
            {
                if (products[i].whos==tenants[uk-1])
                    cout << products[i];
            }
        }
    }
}

int checker()
{
    int i;
    while(!(cin >> i))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Unknow ERROR: наверно не int\n";
    }
    return i;
}
