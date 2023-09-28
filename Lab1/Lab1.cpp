
#include <iostream>

using namespace std;
struct FullName {
    string name, surname;
};
struct Address {
    string city, street;
};
struct Data {

    FullName fullName;
    Address address;
    string phoneNumber;

    Data() {
        this->fullName.name = "Name";
        this->fullName.surname = "Surname";
        this->address.city = "City";
        this->address.street = "Street";
        this->phoneNumber = "Phone";
    }
    Data(string name, string surname, string city, string street, string phoneNumber) {
        this->fullName.name = name;
        this->fullName.surname = surname;
        this->address.city = city;
        this->address.street = street;
        this->phoneNumber = phoneNumber;
    }
    void ShowAllData() {
        if (fullName.name != "Name") {
            cout << this->fullName.name << " " << this->fullName.surname << " " << this->address.city << " " << this->address.street << " " << this->phoneNumber << " " << endl;
        }      
    }
};
int main()
{
    int capacity = 4;
    string inputName, inputCity;
    int inputCase;
    bool isFound = false;
    Data* data = new Data[capacity];

    data[0] = Data("Ivan", "Petrov", "Dnipro", "Gagarina", "20-44-55");
    data[1] = Data("Ruslan", "Tereshenko", "Lviv", "Mayorivka", "15 - 49 - 89");
    data[2] = Data("Alina", "Gorova", "Dnipro", "Soborna", "99 - 07 - 12");
    data[3] = Data("Anna", "Gonchar", "Kyiv", "Khreshchatyk", "80 - 40 - 01");
    cout << "1. Show all the data." << endl;
    cout << "2. Find the data by a name and a city." << endl;
    cout << "3. Add a person." << endl;
    cout << "4. End the program." << endl;
    while (true) {
        cout << "Enter the number of operation: ";
        cin >> inputCase;
        switch (inputCase) {
        case 1:
            for (int i = 0; i < capacity; i++) {
                data[i].ShowAllData();
            }
            break;
        case 2:
            cout << "Enter a name of the person and a name of the city: " << endl;
            cin >> inputName; cin >> inputCity;
            for (int i = 0; i < capacity; i++) {
                if (inputName == data[i].fullName.name && inputCity == data[i].address.city) {
                    data[i].ShowAllData();
                    isFound = true;
                }
            }
            if (!isFound) {
                cout << "The person wasn't found." << endl;
            }
            break;
        case 3:
        {
            cout << "Enter name, surname, city, street, and phone number: " << endl;
            string newName, newSurname, newCity, newStreet, newPhoneNumber;
            cin >> newName >> newSurname >> newCity >> newStreet >> newPhoneNumber;
            Data newData(newName, newSurname, newCity, newStreet, newPhoneNumber);
            int size = capacity * capacity;
            Data* newArray = new Data[size*size];
            for (int i = 0; i < capacity; i++) {
                newArray[i] = data[i];
            }
            delete[] data;
            data = newArray;
            data[capacity] = newData;
            capacity++;
            break;
        }
        case 4:
            return 0;
        default:
            cout << "Wrong operation." << endl;       
        }   
    }
    delete[] data;
}
