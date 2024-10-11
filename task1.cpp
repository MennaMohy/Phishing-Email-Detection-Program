#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<fstream>
#include<sstream>
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
void print(int n , int i ){

    for(int k = 0 ; k < i ; k++) {
        cout << " ";
    }
    for(int j = 0 ; j < n ; j++){
        cout << "* ";
    }
    cout << endl;
}
void problem8(int n, int i){
    if(n == 1 ){
        print(1,i);
        return;
    }
    problem8(n/2, i);
    print(n,i);
    problem8(n/2, i + n);
}
/*
string trim(const string& str) {
    int first = 0;
    int last = str.length() - 1;
    while (first <= last && (str[first] == ' ' || str[first] == '\t' || str[first] == '\n' || str[first] == '\r')) {
        first++;
    }
    while (last >= first && (str[last] == ' ' || str[last] == '\t' || str[last] == '\n' || str[last] == '\r')) {
        last--;
    }
    return str.substr(first, last - first + 1);
}*/
/*
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \n\r\t");
    size_t last = str.find_last_not_of(" \n\r\t");
    return (first == string::npos) ? "" : str.substr(first, (last - first + 1));
}*/

string removeSpaces(const string& str) {
    string result;
    for (char ch : str) {
        if (!isspace(ch) && ch != '\n' && ch != '\t' && ch != '\r' ){ // Skip spaces, tabs, newlines
            result += ch;
        }
    }
    return result;
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
            switch(choice) {
                case 'a': {
                    vector<char> chars1,chars2;
                    char ch;
                    int position = 1;
                    while(file1.get(ch)){
                        chars1.push_back(ch);
                    }
                    file1.clear();
                    file1.seekg(0);
                    while (file2.get(ch)) {
                        chars2.push_back(ch);
                    }
                    file2.clear();
                    file2.seekg(0);
                    bool identical = true;
                    int line = 1;
                    int smaller_size = min(chars1.size(), chars2.size());
                    for (int i = 0; i < smaller_size; i++) {
                        if (chars1[i] != chars2[i]) {
                            identical = false;
                            if (chars1[i] == '\n' || chars2[i] == '\n') {
                                line++;
                            }
                            cout << "Difference at line : " << line << endl;
                            cout << "File 1: ";
                            if (chars1[i] == ' ') cout << "space" << endl;
                            else if (chars1[i] == '\n') cout << "newline" << endl;
                            else if (chars1[i] == '\t') cout << "tab" << endl;
                            else cout << chars1[i] << endl;

                            cout << "File 2: ";
                            if (chars2[i] == ' ') cout << "space" << endl;
                            else if (chars2[i] == '\n') cout << "newline" << endl;
                            else if (chars2[i] == '\t') cout << "tab" << endl;
                            else cout << chars2[i] << endl;
                            return;
                        }
                        if (chars1[i] == '\n' || chars2[i] == '\n') {
                            line++;
                        }
                    }
                    if (chars1.size() > chars2.size()) {
                        int i;
                        for (i = smaller_size; i < chars1.size(); i++) {
                            if (chars1[i] == '\n') {
                                line++;
                            }
                            cout << "Difference at line: " << line << endl;
                            cout << "File 1: " << chars1[i] << endl;
                            cout << "File 2: none" << endl;
                            break;
                        }

                    } else if (chars2.size() > chars1.size()) {
                        int i;
                        for ( i = smaller_size; i < chars2.size(); i++) {
                            if (chars2[i] == '\n') {
                                line++;
                            }
                            cout << "Difference at line: " << line << endl;
                            cout << "File 1: none" << endl;
                            cout << "File 2: " << chars2[i] << endl;
                            break;
                        }
                    }

                    if (identical && (chars1.size() == chars2.size())) {
                        cout << "The Files are identical." << endl;
                    }
                    file1.clear();
                    file1.seekg(0);
                    file2.clear();
                    file2.seekg(0);
                }
                break;
                case 'b': {
                    vector<string> words1, words2;
                    string word;
                    file1 >> std::ws;
                    while (file1 >> word) {
                        words1.push_back(word);
                    }
                    file1.close();
                    file2 >> std::ws;
                    while (file2 >> word) {
                        words2.push_back(word);
                    }

                    file2.close();
                    bool identical = true;
                     int line = 0;
                    for (int i = 0; i < min(words1.size(), words2.size()); i++) {
                         line++;
                        if (words1[i] != words2[i]) {
                            cout << "The files are not identical at line : " << line<< endl;
                            cout << "Difference at word position: " << (i + 1) << endl;
                            cout << "File 1: " << words1[i] << endl;
                            cout << "File 2: " << words2[i] << endl;
                            identical = false;
                            break;
                        }
                    }

                    if (identical && (words1.size() != words2.size())) {
                        identical = false;
                        cout << "The files have different number of words." << endl;
                        int smaller_size = min(words1.size(), words2.size());
                        if (words1.size() > words2.size()) {
                            for (size_t i = smaller_size; i < words1.size(); i++) {
                                cout << "Difference at word position: " << (i + 1) << endl;
                                cout << "File 1: " << words1[i] << endl;
                                cout << "File 2: none" << endl;
                            }
                        } else {
                            for (int i = smaller_size; i < words2.size(); i++) {
                                cout << "Difference at word position: " << (i + 1) << endl;
                                cout << "File 1: none" << endl;
                                cout << "File 2: " << words2[i] << endl;
                            }
                        }
                    }

                    if (identical) {
                        cout << "The files are identical." << endl;
                    }
                    file1.clear();
                    file1.seekg(0);
                    file2.clear();
                    file2.seekg(0);
                }
                break;
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
                    int n,i;
                    cout << "Enter the size of your pattern : " << endl;
                    cin >> n ;
                    cout << "Enter the index : "<< endl;
                    cin >> i;
                    while(n <= 0 || (n & (n-1)) != 0 ){
                        cout << "The size must be power of 2 : "<< endl;
                        cin >> n;
                    }
                    problem8(n,i);
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