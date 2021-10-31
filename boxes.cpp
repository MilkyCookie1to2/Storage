#include "class .h"

void storage::delbox(vector<tenant>&tenants, vector<product>&products)
{
    if (products.empty()) {
        cout << "Склад пуст";
        cout << "Нажмите ENTER, чтобы продолжить...\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    }
    else {
        cout << "| " << setw(2) << "id" << " | " << setw(22) << "Наименование товара" << " | " << setw(6)
             << "Кол-во" << " | " << setw(15) << "Статус" << " |"<<endl;
        for (int i = 0; i < products.size(); i++)
            cout << products[i];
    }
    cout<<"\nВведите id товара, который хотите удалить: ";
    int vvid = checker();
    vector<product>::iterator u;
    int i;
    for(i=0, u = products.begin(); u<products.end();i++,u++)
    {
        if(products[i].id == vvid)
        {
            int j;
            vector<tenant>::iterator u1;
            for(j=0, u1 = tenants.begin();j<tenants.size();j++,u1++)
            {
                if(tenants[j]==products[i].whos)
                {
                    if(tenants[j].sizeproducts>1)
                    {
                        tenants[j].sizeproducts--;
                        products.erase(u);
                        return;
                    }
                    else
                    {
                        tenants.erase(u1);
                        products.erase(u);
                        return;
                    }
                }
            }
        }
    }
    cout << "Нет товара с таким id\nНажмите ENTER, чтобы продолжить...\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void storage::moreinfo(vector<product>products)
{
    while(1) {
        if (products.empty()) {
            cout << "Склад пуст\n";
            cout << "Нажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        } else {
            cout << "| " << setw(2) << "id" << " | " << setw(22) << "Наименование товара" << " | " << setw(6)
                 << "Кол-во" << " | " << setw(15) << "Статус" << " |" << endl;
            for (int i = 0; i < products.size(); i++)
                cout << products[i];
        }
        cout << "\nВведите id товара или 0, чтобы выйти: ";
        int vvid = checker();
        if (vvid==0)
            break;
        int i;
        for (i = 0; i < products.size(); i++) {
            if (products[i].id == vvid) {
                system("clear");
                products[i].printpro();
                break;
            }
        }
        if (i >= products.size()) {
            system("clear");
            cout << "Товара с таким id нет\n";
            cout << "Нажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            break;
        }
    }
}

void storage::editbox(vector<product>&boxs, vector<driver>&drivers)
{
    if (boxs.empty()) {
        cout << "Склад пуст\n";
        cout << "Нажмите ENTER, чтобы продолжить...\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        return;
    } else {
        cout << "| " << setw(2) << "id" << " | " << setw(22) << "Наименование товара" << " | " << setw(6)
             << "Кол-во" << " | " << setw(15) << "Статус" << " |" << endl;
        for (int i = 0; i < boxs.size(); i++)
            cout << boxs[i];
    }
    cout << "\nВведите id товара: ";
    int vvid = checker();
    for(int i=0;i<boxs.size();i++)
    {
        if (boxs[i].id == vvid)
        {
            while(1) {
                system("clear");
                boxs[i].printpro();
                cout
                        << "Какое поле хотите редактировать:\n\t1. Наименование товара\n\t2. Тип товара\n\t3. Кол-во товара\n\t4. Статус\n\t5. Дополнительная информация\n\t";
                if (boxs[i].status == "На складе")
                    cout << "6. Дата завоза\n\t7. Экспедитор\n";
                cout << "\n0. Назад\n";
                int vvod = checker();
                switch (vvod) {
                    case 1: {
                        cout << "Введите наименование товара: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        getline(cin, boxs[i].name);
                        break;
                    }
                    case 2: {
                        cout << "Введите тип товара: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        getline(cin, boxs[i].type);
                        break;
                    }
                    case 3: {
                        cout << "Введите кол-во товара: ";
                        cin >> boxs[i].area;
                        break;
                    }
                    case 4: {
                        if (boxs[i].status == "На складе")
                            boxs[i].status = "Нет на складе";
                        else {
                            boxs[i].status = "На складе";
                            cout << "Введите дату завоза:";
                            cin >> boxs[i].in;
                            cin.clear();
                            cout
                                    << "Экспедитор:\n\t1. Выбрать из экспедиторов склада\n\t2. Ввести данные экспедитора\n\t";
                            int vvode=0;
                            while ((vvode < 1) || (vvode > 2)) {
                                vvode = checker();
                                switch (vvode) {
                                    case 1: {
                                        if (!drivers.empty()) {
                                            for (int i = 0; i < drivers.size(); i++)
                                                cout << i + 1 << ". " << drivers[i];
                                            cout << "Введите номер экспедитора: ";
                                            int vibor=0;
                                            while ((vibor < 1) || (vibor > drivers.size()))
                                                vibor = checker();
                                            boxs[i].whoin = drivers[vibor - 1];
                                            break;
                                        } else
                                            cout << "Список пуст\nВводим нового\n";
                                    }
                                    case 2: {
                                        cin >> boxs[i].whoin;
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                    case 5: {
                        cout << "Введите дополнительную информацию о товаре:\n";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        getline(cin, boxs[i].extrainfo);
                        break;
                    }
                    case 6: {
                        cout << "Введите дату завоза товара: ";
                        cin >> boxs[i].in;
                        break;
                    }
                    case 7: {
                        cout << "Экспедитор:\n\t1. Выбрать из экспедиторов склада\n\t2. Ввести данные экспедитора\n\t";
                        int vvode=0;
                        while ((vvode < 1) || (vvode > 2)) {
                            vvode = checker();
                            switch (vvode) {
                                case 1: {
                                    if (!drivers.empty()) {
                                        for (int i = 0; i < drivers.size(); i++)
                                            cout << i + 1 << ". " << drivers[i];
                                        cout << "Введите номер экспедитора: ";
                                        int vibor=0;
                                        while ((vibor < 1) || (vibor > drivers.size()))
                                            vibor = checker();
                                        boxs[i].whoin = drivers[vibor - 1];
                                        break;
                                    } else
                                        cout << "Список пуст\nВводим нового\n";
                                }
                                case 2: {
                                    cin >> boxs[i].whoin;
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    case 0: {
                        return;
                    }
                    default:
                    {
                        system("clear");
                    }
                }
            }
        }
    }
}