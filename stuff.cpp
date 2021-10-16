#include "class .h"

using namespace storage;

void stuff(vector<driver>&drivers, vector<loader>&loaders, vector<security>&securities)
{
    if(drivers.empty())
    {
        cout << "Экспедиторов нет\n";
    }
    else
    {
        cout << "\nЭкспедиторы:\n";
        for(int i=0;i<drivers.size();i++)
            cout << i+1<< ". " << drivers[i];
    }
    cout << "\n\t1. Редактирование списка экспедиторов\n\t2. Подробная информация\n";
    if(loaders.empty())
    {
        cout << "\nГрузчиков нет\n";
    }
    else
    {
        cout << "\nГрузчики:\n";
        for(int i=0;i<loaders.size();i++)
            cout << i+1<< ". " << loaders[i];
    }
    cout << "\n\t3. Редактирование списка грузчиков\n\t4. Подробная информация\n";
    if(securities.empty())
    {
        cout << "\nОхранников нет\n";
    }
    else
    {
        cout << "\nОхранники:\n";
        for(int i=0;i<securities.size();i++)
            cout << i+1<< ". " << securities[i];
    }
    cout << "\n\t5. Редактирование списка охранников\n\t6. Подробная информация\n\n7.Назад\n";
    int vvod = checker();
    switch(vvod)
    {
        case 1:
        {
            system("clear");
            editdriver(drivers);
            system("clear");
            break;
        }
        case 2:
        {
            system("clear");
            moreinfodriver(drivers);
            system("clear");
            break;
        }
        case 3:
        {
            system("clear");
            editloader(loaders);
            system("clear");
            break;
        }
        case 4:
        {
            system("clear");
            moreinfoloader(loaders);
            system("clear");
            break;
        }
        case 5:
        {
            system("clear");
            editsecurity(securities);
            system("clear");
            break;
        }
        case 6:
        {
            system("clear");
            moreinfosecurity(securities);
            system("clear");
            break;
        }
        case 7:
        {
            return;
        }
        default:
        {
            system("clear");
        }
    }
}

void moreinfosecurity(vector<security>securities)
{
    while(1) {
        if (securities.empty()) {
            cout << "Охранников нет\n";
            cout << "Нажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        } else {
            cout << "\nОхранники:\n";
            for (int i = 0; i < securities.size(); i++)
                cout << i + 1 << ". " << securities[i];
        }
        int uk;
        cout << "\nВведите номер экспедитора или 0 для выхода: ";
        uk = checker();
        if ((uk < 1) || (uk > securities.size())) {
            if (uk==0)
                return;
            cout << "Такого охранника нет";
            cout << "\nНажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("clear");
        } else {
            system("clear");
            securities[uk - 1].print();
        }
    }
}

void moreinfoloader(vector<loader>loaders)
{
    while(1) {
        if (loaders.empty()) {
            cout << "Грузчиков нет\n";
            cout << "Нажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        } else {
            cout << "\nГрузчики:\n";
            for (int i = 0; i < loaders.size(); i++)
                cout << i + 1 << ". " << loaders[i];
        }
        int uk;
        cout << "\nВведите номер экспедитора или 0 для выхода: ";
        uk = checker();
        if ((uk < 1) || (uk > loaders.size())) {
            if (uk==0)
                return;
            cout << "Такого Грузчика нет";
            cout << "\nНажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("clear");
        } else {
            system("clear");
            loaders[uk - 1].print();
        }
    }
}

void moreinfodriver(vector<driver>drivers)
{
    while(1) {
        if (drivers.empty()) {
            cout << "Экспедиторов нет\n";
            cout << "Нажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            return;
        } else {
            cout << "\nЭкспедиторы:\n";
            for (int i = 0; i < drivers.size(); i++)
                cout << i + 1 << ". " << drivers[i];
        }
        int uk;
        cout << "\nВведите номер экспедитора или 0 для выхода: ";
        uk = checker();
        if ((uk < 1) || (uk > drivers.size())) {
            if (uk==0)
                return;
            cout << "Такого экспедитора нет";
            cout << "\nНажмите ENTER, чтобы продолжить...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("clear");
        } else {
            system("clear");
            drivers[uk - 1].print();
        }
    }
}

void editsecurity(vector<security>&securities)
{
    if(securities.empty())
    {
        cout << "\nОхранников нет\n";
    }
    else
    {
        cout << "\nОхранники:\n";
        for(int i=0;i<securities.size();i++)
            cout << i+1<< ". " << securities[i];
    }
    cout << "\n1. Добавить охранника\n2. Удалить охранника\n3. Редактировать данные охранника\n4. Назад\n";
    int vvod = checker();
    switch(vvod)
    {
        case 1:
        {
            system("clear");
            securities.push_back(security());
            cin >> securities[securities.size()-1];
            system("clear");
            break;
        }
        case 2:
        {
            system("clear");
            delsecurity(securities);
            system("clear");
            break;
        }
        case 3:
        {
            system("clear");
            editpolesecurities(securities);
            system("clear");
            break;
        }
        case 4:
        {
            return;
        }
        default:
        {
            system("clear");
        }
    }
}

void delsecurity(vector<security>&securities)
{
    vector<security> ::iterator u;
    for(int i=0;i<securities.size();i++)
        cout << i+1<< ". " << securities[i];
    int uk;
    cout << "\nВведите номер грузчика, которого хотите удалить: ";
    uk = checker();
    int i;
    for (i=1, u = securities.begin();u<securities.end();u++,i++)
    {
        if(i==uk) {
            securities.erase(u);
            return;
        }
    }
    cout << "Такого грузчика нет";
    cout << "\nНажмите ENTER, чтобы продолжить...\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void storage::editpolesecurities(vector<security>&securities)
{
    vector<security>::iterator u;
    for (int i = 0; i < securities.size(); i++)
        cout << i + 1 << ". " << securities[i];
    int uk;
    cout << "\nВведите номер грузчика данные, которого хотите редактировать: ";
    uk = checker();
    int i;
    for (i = 1, u = securities.begin(); u < securities.end(); u++, i++) {
        if (i == uk) {
            system("clear");
            while (1) {
                securities[i - 1].print();
                cout
                        << "\nКакое поле хотите редактировать:\n\t1. Фамилия\n\t2. Имя\n\t3. Отчество\n\t4. Номер телефона\n\t5. Дата рождения\n\t6. Смена\n\t0. Назад\n";
                int vvod = checker();
                switch (vvod) {
                    case 1: {
                        cout << "Введите фамилию: ";
                        cin >> securities[i - 1].fam;
                        system("clear");
                        break;
                    }
                    case 2: {
                        cout << "Введите имя: ";
                        cin >> securities[i - 1].name;
                        system("clear");
                        break;
                    }
                    case 3: {
                        cout << "Введите отчество: ";
                        cin >> securities[i - 1].och;
                        system("clear");
                        break;
                    }
                    case 4: {
                        cout << "Введите номер телефона: +375";
                        cin >> securities[i - 1].numphone;
                        system("clear");
                        break;
                    }
                    case 5: {
                        cout << "Введите дату рождения: ";
                        cin >> securities[i - 1].bith;
                        system("clear");
                        break;
                    }
                    case 6: {
                        cout << "Выберите рабочую смену:\n\t1. Дневная\n\t2. Ночная\n\t";
                        int vvod1 = 0;
                        while ((vvod1 < 1) || (vvod1 > 2)) {
                            vvod1 = checker();
                            switch (vvod1) {
                                case 1: {
                                    securities[i - 1].smena = "Дневная";
                                    break;
                                }
                                case 2: {
                                    securities[i - 1].smena = "Ночная";
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    case 0: {
                        return;
                    }
                    default: {
                        system("clear");
                    }
                }
            }

        }
    }
}

void editloader(vector<loader>&loaders)
{
    if(loaders.empty())
    {
        cout << "\nГрузчиков нет\n";
    }
    else
    {
        cout << "\nГрузчики:\n";
        for(int i=0;i<loaders.size();i++)
            cout << i+1<< ". " << loaders[i];
    }
    cout << "\n1. Добавить грузчика\n2. Удалить грузчика\n3. Редактировать данные грузчика\n4. Назад\n";
    int vvod = checker();
    switch(vvod)
    {
        case 1:
        {
            system("clear");
            loaders.push_back(loader());
            cin >> loaders[loaders.size()-1];
            system("clear");
            break;
        }
        case 2:
        {
            system("clear");
            delloader(loaders);
            system("clear");
            break;
        }
        case 3:
        {
            system("clear");
            editpoleloaders(loaders);
            system("clear");
            break;
        }
        case 4:
        {
            return;
        }
        default:
        {
            system("clear");
        }
    }
}

void delloader(vector<loader>&loaders)
{
    vector<loader> ::iterator u;
    for(int i=0;i<loaders.size();i++)
        cout << i+1<< ". " << loaders[i];
    int uk;
    cout << "\nВведите номер грузчика, которого хотите удалить: ";
    uk = checker();
    int i;
    for (i=1, u = loaders.begin();u<loaders.end();u++,i++)
    {
        if(i==uk) {
            loaders.erase(u);
            return;
        }
    }
    cout << "Такого грузчика нет";
    cout << "\nНажмите ENTER, чтобы продолжить...\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void storage::editpoleloaders(vector<loader>&loaders)
{
    vector<loader>::iterator u;
    for (int i = 0; i < loaders.size(); i++)
        cout << i + 1 << ". " << loaders[i];
    int uk;
    cout << "\nВведите номер грузчика данные, которого хотите редактировать: ";
    uk = checker();
    int i;
    for (i = 1, u = loaders.begin(); u < loaders.end(); u++, i++) {
        if (i == uk) {
            system("clear");
            while(1) {
                loaders[i - 1].print();
                cout
                        << "\nКакое поле хотите редактировать:\n\t1. Фамилия\n\t2. Имя\n\t3. Отчество\n\t4. Номер телефона\n\t5. Дата рождения\n\t6. Разряд\n\t0. Назад\n";
                int vvod = checker();
                switch (vvod) {
                    case 1: {
                        cout << "Введите фамилию: ";
                        cin >> loaders[i - 1].fam;
                        system("clear");
                        break;
                    }
                    case 2: {
                        cout << "Введите имя: ";
                        cin >> loaders[i - 1].name;
                        system("clear");
                        break;
                    }
                    case 3: {
                        cout << "Введите отчество: ";
                        cin >> loaders[i - 1].och;
                        system("clear");
                        break;
                    }
                    case 4: {
                        cout << "Введите номер телефона: +375";
                        cin >> loaders[i - 1].numphone;
                        system("clear");
                        break;
                    }
                    case 5: {
                        cout << "Введите дату рождения: ";
                        cin >> loaders[i - 1].bith;
                        system("clear");
                        break;
                    }
                    case 6: {
                        cout << "Введите номер разряда: ";
                        while((!(cin >> loaders[i-1].category))||(loaders[i-1].numphone <1)||(loaders[i-1].numphone>2))
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                            cout << "ERROR: Такого разряда не существет\n";
                            cout << "Введите разряд: ";
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
    cout << "Такого экспедитора нет";
    cout << "\nНажмите ENTER, чтобы продолжить...\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void editdriver(vector<driver>&drivers)
{
    if(drivers.empty())
    {
        cout << "Экспедиторов нет\n";
    }
    else
    {
        cout << "\nЭкспедиторы:\n";
        for(int i=0;i<drivers.size();i++)
            cout << i+1<< ". " << drivers[i];
    }
    cout << "\n1. Добавить экспедитора\n2. Удалить экспедитора\n3. Редактировать данные экспедитора\n4. Назад\n";
    int vvod = checker();
    switch(vvod)
    {
        case 1:
        {
            system("clear");
            drivers.push_back(driver());
            cin >> drivers[drivers.size()-1];
            system("clear");
            break;
        }
        case 2:
        {
            system("clear");
            deldriver(drivers);
            system("clear");
            break;
        }
        case 3:
        {
            system("clear");
            editpoledrivers(drivers);
            system("clear");
            break;
        }
        case 4:
        {
            return;
        }
        default:
        {
            system("clear");
        }
    }
}

void deldriver(vector<driver> &drivers)
{
    vector<driver> ::iterator u;
    for(int i=0;i<drivers.size();i++)
        cout << i+1<< ". " << drivers[i];
    int uk;
    cout << "\nВведите номер экспедитора, которого хотите удалить: ";
    uk = checker();
    int i;
    for (i=1, u = drivers.begin();u<drivers.end();u++,i++)
    {
        if(i==uk) {
            drivers.erase(u);
            return;
        }
    }
    cout << "Такого экспедитора нет";
    cout << "\nНажмите ENTER, чтобы продолжить...\n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void storage::editpoledrivers(vector<driver> &drivers) {
        vector<driver>::iterator u;
        for (int i = 0; i < drivers.size(); i++)
            cout << i + 1 << ". " << drivers[i];
        int uk;
        cout << "\nВведите номер экспедитора данные, которого хотите редактировать: ";
        uk = checker();
        int i;
        for (i = 1, u = drivers.begin(); u < drivers.end(); u++, i++) {
            if (i == uk) {
                system("clear");
                while(1) {
                    drivers[i - 1].print();
                    cout
                            << "\nКакое поле хотите редактировать:\n\t1. Фамилия\n\t2. Имя\n\t3. Отчество\n\t4. Номер телефона\n\t5. Дата рождения\n\t6. Название атомобиля\n\t7. Номер\n\t0. Назад\n";
                    int vvod = checker();
                    switch (vvod) {
                        case 1: {
                            cout << "Введите фамилию: ";
                            cin >> drivers[i - 1].fam;
                            system("clear");
                            break;
                        }
                        case 2: {
                            cout << "Введите имя: ";
                            cin >> drivers[i - 1].name;
                            system("clear");
                            break;
                        }
                        case 3: {
                            cout << "Введите отчество: ";
                            cin >> drivers[i - 1].och;
                            system("clear");
                            break;
                        }
                        case 4: {
                            cout << "Введите номер телефона: +375";
                            cin >> drivers[i - 1].numphone;
                            system("clear");
                            break;
                        }
                        case 5: {
                            cout << "Введите дату рождения: ";
                            cin >> drivers[i - 1].bith;
                            system("clear");
                            break;
                        }
                        case 6: {
                            cout << "Введите название автомобиля: ";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            getline(cin, drivers[i - 1].car);
                            system("clear");
                            break;
                        }
                        case 7: {
                            cout << "Введите номер автомобиля: ";
                            cin >> drivers[i - 1].regnum;
                            system("clear");
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
        cout << "Такого экспедитора нет";
        cout << "\nНажмите ENTER, чтобы продолжить...\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }