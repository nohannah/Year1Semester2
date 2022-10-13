#include <iostream>
#include <string>

using namespace std;

int main(){
    struct Person{
        int id;
        string name;
        struct Birthday{
            int day = 0;
            int month = 0;
            int year = 0;
            int s = 0; //score for compare between two people's age (older, younger, or same age)
        } birthday;
    } *person_ptr, person[2];

    person_ptr = &person[0];

    // ask user to input some info
    //id
    for(int i = 0; i < 2; i++){
    cout << "Person" << i + 1 << " : " << "Enter your ID: ";
    cin >> (*(person_ptr + i)).id;

    cout << "Person" << i + 1 << " : " << "Enter your name: ";
    fflush(stdin);
    getline(cin, (*(person_ptr + i)).name);
    do{
        if((*(person_ptr + i)).birthday.day > 31){
            cout << "Enter the day of birth again!" << endl;
        }
        cout << "Person" << i + 1 << " : " << "Enter your day of birth: ";
        cin >> (*(person_ptr + i)).birthday.day;

    } while ((*(person_ptr + i)).birthday.day > 31);
    
    do{
        if((*(person_ptr)).birthday.month > 12){
            cout << "Enter the month of birth again!" << endl;
        }
        cout << "Person" << i + 1 << " : " << "Enter your month of birth: ";
        cin >> (*(person_ptr + i)).birthday.month;
    } while((*(person_ptr)).birthday.month > 12);


    cout << "Person" << i + 1 << " : " << "Enter your year of birth: ";
    cin >> (*(person_ptr + i)).birthday.year;

    cout << endl;
    }

    // condition for age scoring 
    if((*(person_ptr)).birthday.day < (*(person_ptr + 1)).birthday.day){
        (*(person_ptr)).birthday.s++;
    }
    if((*(person_ptr)).birthday.day > (*(person_ptr + 1)).birthday.day){
        (*(person_ptr + 1)).birthday.s++;
    }

    if((*(person_ptr)).birthday.month < (*(person_ptr + 1)).birthday.month){
        (*(person_ptr)).birthday.s++;
    }
    if((*(person_ptr)).birthday.month > (*(person_ptr + 1)).birthday.month){
        (*(person_ptr + 1)).birthday.s++;
    }

    if((*(person_ptr)).birthday.year < (*(person_ptr + 1)).birthday.year){
        (*(person_ptr)).birthday.s++;
    }
    if((*(person_ptr)).birthday.year > (*(person_ptr + 1)).birthday.year){
        (*(person_ptr + 1)).birthday.s++;
    }

    //display the result
    if((*(person_ptr)).birthday.s > (*(person_ptr + 1)).birthday.s){
        cout << (*(person_ptr)).name << " is older than " << (*(person_ptr + 1)).name << ".";
    }
    else if((*(person_ptr)).birthday.s == (*(person_ptr + 1)).birthday.s){
        cout << "Birthdates are equal.";
    }
    else{
        cout << (*(person_ptr)).name << " is younger than " << (*(person_ptr + 1)).name << ".";
    }
    return 0;
}
