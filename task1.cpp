#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
/*
*
* *
  *
* * * *
    *
    * *
      *
* * * * * * * *
        *
        * *
          *
        * * * *
            *
            * *
              *
 */
void problem2(){
    string m;
    cout << "Enter the string : " << endl;
    getline(cin ,m );
    vector<string> a;
    string temp = "";
    for(char c : m){
        if(!isspace(c)){
            temp += c;
        }
        else if (isspace(c) && temp != ""){
            a.push_back(temp);
            temp ="";
        }
    }
    if(!temp.empty()){
        a.push_back(temp);
    }
    for(int i = 0 ; i < a.size() ; i++){
        string word = a[i];
        char last = word.back();
        string v = word;
        if(ispunct(last) && (last == '.' || last == '?' || last == '!' || last == ',')){
            v.pop_back();
            if(v == "He"){
                a[i] = "He or she" + string(1, last);
            }
            else if(v == "he"){
                a[i] = "he or she" + string(1, last);
            }
            else if(v == "his"){
                a[i] = "his or her" + string(1, last);
            }
            else if(v == "His"){
                a[i] = "His or her" + string(1, last);
            }
            else if(v == "Him"){
                a[i] = "Him or her" + string(1, last);
            }
            else if(v == "him"){
                a[i] = "him or her" + string(1, last);
            }
        } else {
            if(v == "He"){
                a[i] = "He or she";
            }
            else if(v == "he"){
                a[i] = "he or she";
            }
            else if(v == "his"){
                a[i] = "his or her";
            }
            else if(v == "His"){
                a[i] = "His or her";
            }
            else if(v == "Him"){
                a[i] = "Him or her";
            }
            else if(v == "him"){
                a[i] = "him or her";
            }
        }
    }
    for(int i = 0 ; i < a.size() ; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void problem5(){
    char choice;
    vector<pair<int, string>> a ;
    int n;
    cout << "Enter the number of players :"<< endl;
    cin >> n;
    cout << "Enter the name and score of players : "<< endl;
    for(int i = 0; i < n ; i++){
        string name;
        int score;
        cin >> name >> score;
       a.push_back({score,name});
       sort(a.rbegin(), a.rend());
       cout << "List of players : "<< endl;
       for(int j = 0 ; j <= i ; j++){
           cout << a[j].second << " " << a[j].first;
           if (j < i) {
               cout << ", ";
           }
       }
       cout << endl;
    }
    while (true) {
        try {
            cout << "Enter a character (a, b, c): " << endl;
            cin >> choice;
            choice = tolower(choice);
            if (choice == 'y') {
                break;
            }
            if (choice != 'a' && choice != 'b' && choice !=
            'c') {
                throw invalid_argument("Invalid input! Please enter 'a', 'b' or 'c'.");
            }
            switch (choice) {
                case 'a': {
                    string name;
                    int score;
                    cout << "Enter the new player name and score: "<< endl;
                    cin >> name >> score;
                    pair<int,string> t(score, name);
                    for (int i = 0; i < 10; i++) {
                        if (score > a[i].first) {
                            a.erase(a.end() - 1);
                            a.insert(a.begin() + i, t);
                            break;
                        }
                    }
                    sort(a.rbegin(), a.rend());

                }
                    break;
                case 'b' : {

                    for (int i = 0; i < 10; i++) {
                        cout << a[i].second << " " << a[i].first;
                        if (i < 9) {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                }
                break;
                case 'c': {
                    cout << "Enter name of player to get maximum score : "<< endl;
                    string name;
                    cin >> name;
                    bool found = false;
                    bool found_list = false;
                    for (int i = 0; i < 10; i++) {
                        if (name == a[i].second) {
                            cout << a[i].first<< endl;
                            found = true;
                            break;
                        }
                    }
                    for (int i = 0; i < a.size(); i++) {
                        if (name == a[i].second) {
                            found_list = true;
                            break;
                        }
                    }
                    if (!found && found_list) {
                        cout << "Player is not in Top 10." << endl;
                    } else if (!found_list) {
                        cout << "This player is not in this list." << endl;
                    }
                }
                    break;
            }
            cout << "if you want to stop, Enter 'y' to stop" << endl;
        }
        catch (invalid_argument &e) {
            cout << e.what();
        }
    }
}

void problem8(int n , int i){
  if(n == 1){
      for(int j = 0 ; j < i ; j++){
          cout << " ";
      }
      cout << "*";
      cout << endl;
      return;
  }
  problem8(n/2,i);
  for(int j = 0 ; j < i ; j++){
        cout << " ";
    }
  for(int k = 0 ; k < n ; k++){
      cout << "* ";
  }
  cout << endl;
  problem8( n / 2,i+ n / 2 );
}
int main() {
    int choice;
    while (true) {
        try {
            cout << "Enter the problem number: " << endl;
            cin >> choice;
            if(cin.fail()){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input! Please enter '2', '5' ,'8' or '11'");
            }
            cin.ignore();
            if (choice == -1) {
                break;
            }
            if (choice != 2 && choice != 5 && choice !=
                                                  8 && choice != 11) {
                throw invalid_argument("Invalid input! Please enter '2', '5' ,'8' or '11'");
            }
            switch(choice){
                case 2:{
                    problem2();
                }
                break;
                case 5:{
                    problem5();
                }
                break;
                case 8: {
                    int n;
                    cin >> n;
                   problem8(n,0);
                }
                break;
                case 11:{
                  //problem11();
                }
            }
        }
        catch(invalid_argument & e){
            cout << e.what()<< endl;
        }
    }
}