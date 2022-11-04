#include <iostream>
#include <map>
#include <cctype>
#include <sstream>
using namespace std;

//function to display menu
void display_menu (){
    cout << "a. Balance" << endl;
    cout << "b. Withdraw" << endl;
    cout << "c. Deposit" << endl;
    cout << "d. Exit the program" << endl;
}

int main(){
    map <string, map<string, string>> list = {
                                             {"001",{{"Name","James"},{"Balance","3000"},{"Password","1234"}}},
                                             {"002",{{"Name","Harry"},{"Balance","2000"},{"Password","xyzk"}}},
                                             {"003",{{"Name","Marry"},{"Balance","2500"},{"Password","1236"}}},
                                             {"004",{{"Name","Jake"},{"Balance","3500"},{"Password","abcd"}}},
                                             {"005",{{"Name","Jane"},{"Balance","2000"},{"Password","1239"}}},
                                             };
    string account_no, password;
    char menu_select;
    int loop_count = 0;

    //ask user for account_no and password
    cout << "Accont_no: ";
    getline(cin, account_no);
    cout << "Password: ";
    getline(cin, password);

    for (auto m: list){

        //vertify the account_no and password
        if((account_no==m.first)and(password==m.second.at("Password"))){

            //display the menu and let the user select the menu
            display_menu();
            cout << "Select menu: ";
            cin >> menu_select;
            menu_select = tolower(menu_select);

            //check balance
            if(menu_select=='a'){
                cout << "Balance: " << m.second.at("Balance");
            }

            //balance withdrawal
            else if(menu_select=='b'){
                float balance_to_withdraw;
                stringstream new_balance;

                cout << "Balance to withdraw: ";
                cin >> balance_to_withdraw;
                new_balance << stof(m.second.at("Balance")) - balance_to_withdraw;
                m.second.at("Balance") = new_balance.str();
                cout << "Balance after the withdrawal: "<<m.second.at("Balance");
            }

            //balance deposit
            else if(menu_select=='c'){
                float balance_to_deposit;
                stringstream new_balance;
                
                cout << "Balance to deposite: ";
                cin >> balance_to_deposit;
                new_balance << stof(m.second.at("Balance")) + balance_to_deposit;
                m.second.at("Balance") = new_balance.str();
                cout << "Balance after the deposite: "<<m.second.at("Balance");
            }

            //exit program
            else if(menu_select=='d'){
                cout << "Program exited";
                exit(0);
            }

            else{
                cout << "Please enter a letter between a and d";
            }
            loop_count--;
        }
        loop_count++;
    }
    if (loop_count==list.size()){
        cout << "Wrong account_no or password";
    }

    return 0;
}