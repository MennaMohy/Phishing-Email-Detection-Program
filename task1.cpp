#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<fstream>
#include<filesystem>
using namespace std;

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
            else if(v == "Himself"){
                a[i] = "Himself or herself" + string(1, last);
            }
            else if(v == "himself"){
                a[i] = "himself or herself" + string(1, last);
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
            else if(v == "Himself"){
                a[i] = "Himself or herself" ;
            }
            else if(v == "himself"){
                a[i] = "himself or herself";
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
    vector<pair<int, string>> players;
    while (true) {
        try {
            cout << "Menu:\n";
            cout << "a - Add a player\n";
            cout << "b - Display the list of players\n";
            cout << "c - Find a player's score\n";
            cout << "y - Exit\n";
            cout << "Enter your choice: " << endl;
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
                     if(players.size() < 10){
                         players.push_back(t);
                         sort(players.rbegin(), players.rend());
                     }
                     else{
                         for(int i = 0 ; i < players.size() ; i++){
                             if(score > players[i].first ){
                                 players.erase(players.begin()+1);
                                 players.insert(players.begin()+i,t);
                                 break;
                             }
                         }
                     }
                    sort(players.rbegin(), players.rend());

                }
                break;
                case 'b' : {
                    cout << "List of players : " << endl;
                    if (players.empty()) {
                        cout << "No players to display." << endl;
                    } else {
                        for (int i = 0; i < players.size(); i++) {
                            cout << players[i].second << " " << players[i].first;
                            if (i < players.size() - 1) {
                                cout << ", ";
                            }
                        }
                        cout << endl;
                    }
                }
                break;
                case 'c': {
                    cout << "Enter name of player to get maximum score : "<< endl;
                    string name;
                    cin >> name;
                    bool found = false;
                    bool found_list = false;
                    for (int i = 0; i < players.size(); i++) {
                        if (name == players[i].second) {
                            found_list = true;
                            if(i < 10) {
                                cout << players[i].first << endl;
                                found = true;
                            }
                            break;
                        }
                    }
                    if (!found_list) {
                        cout << "This player is not in this list." << endl;

                    }
                    else if (!found){
                        cout << "Player is not in Top 10." << endl;
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
void print(int n ){
    static int i = 0 ;
    if(n == 1 ){
        for(int j = 0 ; j < i ; j++){
            cout << " ";
        }
        cout << "*" << endl;
    }
    else if (i > n ){
        for(int j = 0 ; j < i - n + 1 ; j++ ){
                 cout << " ";
        }
        for(int j = 0 ; j < n ; j++){
            cout << "* ";
        }
        cout << endl;
    }
    else{
        for(int j = 0; j < n ; j++){
            cout << "* ";
        }
        cout << endl;
    }
    i++;
}
void problem8(int n){
      if(n <= 1 ){
          print(1);
          return;
      }
    problem8(n/2);
    print(n);
    problem8(n/2);
}


void problem11() {
    fstream file1;
    string filename1;
    while(true) {
        cout << "Enter the name of the first file: " << endl;
        cin >> filename1;
        file1.open(filename1.c_str(), ios::in);
        if (!file1) {
            cout << "The file is not found! please enter valid file name:" << endl;
            file1.clear();
            file1.open(filename1.c_str(), ios::in);
        }
        else{
            break;
        }
    }
    fstream file2;
    string filename2;
    while (true) {
        cout << "Enter the name of the second file: " << endl;
        cin >> filename2;
        file2.open(filename2.c_str(), ios::in);
        if (!file2) {
            cout << "The file is not found! please enter valid file name:" << endl;
            file2.clear();
            file2.open(filename2.c_str(), ios::in);
        }
        else{
            break;
        }
    }
    char choice;
    while (true) {
        try {
            cout << "Menu:\n";
            cout << "a - Compare character by character\n";
            cout << "b - Compare word by word\n";
            cout << "y - Exit\n";
            cout << "Enter your choice: " << endl;
            cin >> choice;
            choice = tolower(choice);
            if (choice == 'y') {
                break;
            }
            if (choice != 'a' && choice != 'b') {
                throw invalid_argument("Invalid input! Please enter 'a' or 'b'");
            }
            switch(choice){
                case 'a':{
                  char ch1,ch2;
                  int position = 1;
                  bool identical = true;
                  while(file1.get(ch1) && file2.get(ch2)){
                      if(ch1 != ch2){
                          cout << "Files are not identical." << endl;
                          cout << "Difference at character " << position << endl;
                          cout << "File 1: " ;
                          if(ch1 ==' ') cout << "space"<< endl;
                          else if(ch1 =='\n') cout << "newline"<< endl;
                          else if(ch1 == '\t')cout << "tab"<< endl;
                          else cout << ch1 << endl;
                          cout << "File 2: ";
                          if(ch2 ==' ') cout << "space"<< endl;
                          else if(ch2 =='\n') cout << "newline"<< endl;
                          else if(ch2 == '\t')cout << "tab"<< endl;
                          else cout << ch2 << endl;
                          identical = false;
                          break;
                      }
                      position++;
                  }
                  if(file1.eof() != file2.eof()){
                      cout << "The Files are not identical." << endl;
                      identical = false;
                  }
                  if(identical){
                      cout << "The Files are identical."<< endl;
                  }
                    file1.clear(); file1.seekg(0);
                    file2.clear(); file2.seekg(0);
                }
                break;
                case 'b':{
                    bool identical = true;
                    string word1,word2;
                    vector<string>a , b;
                   while(file1 >> word1){
                       a.push_back(word1);
                   }
                   while(file2 >> word2 ){
                       b.push_back(word2);
                   }
                    file1.close();
                    file2.close();
                   for(int i = 0 ;  i < min(a.size(),b.size()) ; i++){
                       if(a[i] != b[i]){
                           cout << "The files are not identical "<< endl;
                           cout << "file 1 :" << " at word " << i + 1 << " " << a[i] << endl;
                           cout << "file 2 :" << " at word " << i + 1 << " " << b[i] << endl;
                           break;
                       }
                   }
                   if(a.size() != b.size()){
                       identical = false;
                       break;
                   }
                   if(identical){
                       cout << "The files are identical."<< endl;
                   }
                    file1.clear(); file1.seekg(0);  // Reset file stream
                    file2.clear(); file2.seekg(0);
                }

            }
        }
        catch (invalid_argument &e) {
            cout << e.what();
        }
    }

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
                    cout << "Enter the size of your pattern : " << endl;
                    cin >> n;
                    problem8(n);
                }
                break;
                case 11:{
                  problem11();
                }
            }
        }
        catch(invalid_argument & e){
            cout << e.what()<< endl;
        }
    }
}