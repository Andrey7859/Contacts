#include <iostream>

using namespace std;

typedef struct ContactStruct {

    char *name;
    char *phone;
    char *email;
    char *address;
    struct ContactStruct *next;
}contact;

contact *initList(){

    contact *tmp = new contact;
    tmp->name = "Максим";
    tmp->phone = "89613695454";
    tmp->email = "qwe@mail.ru";
    tmp->address = "Г.новосибирск";
    tmp->next = NULL;

    return tmp;
}

void output(contact *list){
    contact *tmp = list;
    int i = 1;
    while(tmp != NULL){
        cout << i << endl;
        i++;
        cout <<"Name: " << tmp->name << endl;
        cout <<"Phone: " << tmp->phone << endl;
        cout <<"Email: " << tmp->email << endl;
        cout <<"Address: " << tmp->address << endl;
        cout << endl;
        tmp = tmp->next; // Происходит переход к следующему элементу 
    }
}

void addElem(contact *list, char *name,  char *phone, char *email, char *address){
    contact *tmp;
    contact *tmp2 = new contact;

    tmp = list->next; // Сохранения указателя на следующий узел
    list->next = tmp2; // Предыдущий узел указывает на текущий (Текущий это создаваемый)
    tmp2->next = tmp;

    tmp2->name = name;
    tmp2->phone = phone;
    tmp2->email = email;
    tmp2->address = address;
}

void deleteElem(contact *list, int elem){
    contact *tmp = list;
    contact *t = list;

    for (int i = 0; i < elem - 1; i++)
    {
        if(i > 0){
            t = t->next;
        }
        tmp = tmp->next; // Происходит переход к следующему элементу
    }
    
    t->next = tmp->next;  //следующий у пердыдущего = следущему текущего
    free(tmp);
}

void seatch (contact *list, int elem){
    contact *tmp = list;
    for (int i = 0; i < elem - 1; i++){
        tmp = tmp->next;
    }
        cout <<"Name: " << tmp->name << endl;
        cout <<"Phone: " << tmp->phone << endl;
        cout <<"Email: " << tmp->email << endl;
        cout <<"Address: " << tmp->address << endl;
        cout << endl;
}

int main(){

    setlocale (LC_ALL, "rus");
    int choice = 1;
    bool run = true;
    contact *tmp = initList();

    cout << "\t\t Книга контактов\n\n";
    while(run){
        cout << "1. Поиск\n";
        cout << "2. Добавить\n";
        cout << "3. Удалить\n";
        cout << "4. Вывести список\n";
        cout << "0. Выход\n\n";
        
        cout << "Введите число: ";
        cin >> choice;
        cout << endl;
        
        switch (choice){
            case 1:{
                seatch(tmp, 3);
            break;
            }
            case 2:{
                addElem(tmp, "Василий",  "89536968787", "zxc@mail.ru", "г Москва");
                addElem(tmp, "Маша",  "89536968787", "zxc@mail.ru", "г Москва");
                addElem(tmp, "Олег",  "89536968787", "zxc@mail.ru", "г Москва");
                break;
            }
            case 3:{
                deleteElem(tmp, 2);
                break;
            }
            case 4:{
                output(tmp);
                break;
            }
            case 0:{
                run = false;
                break;
            }
            default: // если count равно любому другому значению
                cout << "Ошибка! Неправильный выбор" << endl;
        }
    }
    return 0;
}
/*Разработать приложение контакты, подобрать структуру данных реализовать функционал: Поиск, Добавление, Удаление. Разработать интерфейс.

План

Данные
    +Структура:
    1.Имя ФИО
    2.Номер телефона
    3.Email
    4.Адрес

Логика
    +Разработать интерактивный интерфейс: 
    Функция: ОДНОСВЯЗНЫЙ ЛИНЕЙНЫЙ СПИСОК
    1.поиска 
    2.удаления
    +3.добавления
    +4.функция вывода
Интерфейс
    +Варфрейм:
            Книга контактов
    
    1.Поиск 
    2.Добавить (Связаные списки)
    3.Удалить
    4.Вывести список
    0.Выход

    Введите число:
*/