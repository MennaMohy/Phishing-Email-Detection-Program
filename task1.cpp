#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
/*void problem2(){
    string m;
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
}
*/
int main() {
    // problem2();
    char choice;
    vector<pair<string, int>> a = {
            {"salma",  85},
            {"menna",  90},
            {"habiba", 95},
            {"ahmed",  80},
            {"Eve",    100},
            {"Frank",  70},
            {"Grace",  60},
            {"yasser", 75},
            {"fatma",  65},
            {"Jack",   85}
    };
    sort(a.rbegin(), a.rend());
    while (true) {
        try {
            cout << "Enter a character (a, b, c): " << endl;
            cin >> choice;
            choice = tolower(choice);
            if (choice == 'y') {
                break;
            }
            if (choice != 'a' && choice != 'b' && choice !=
                                                  'c' ) {
                throw invalid_argument("Invalid input! Please enter 'a', 'b' or 'c'.") ;
                cout << endl;
            }
            switch (choice) {
                case 'a': {
                    string name;
                    int score;
                    cin >> name >> score;
                    pair<string, int> t(name, score);
                    for (int i = 0; i < 10; i++) {
                        if (score > a[i].second) {
                            a.erase(a.end() - 1);
                            a.insert(a.begin() + i,t);
                            break;
                        }else{
                            a.push_back(t);                   }
                    }
                    sort(a.begin(), a.end(), [](const pair<string, int>& p1, const pair<string, int>& p2) {
                        return p1.second > p2.second;  // Compare scores
                    });

                }
                 break;
                case 'b' : {

                    for (int i = 0; i < 10; i++) {
                        cout << a[i].first << " " << a[i].second;
                        if (i < 9) {
                            cout << ", ";
                        }
                    }
                    cout << endl;
                }
                break;
                case 'c': {
                    string name;
                    cin >> name;
                    bool found = false;
                    bool found_list = false;
                    for (int i = 0; i < 10 ; i++) {
                        if (name == a[i].first) {
                            cout << a[i].second << endl;
                            found = true;
                            break;
                        }
                    }
                    for(int i = 0; i < a.size(); i++) {
                        if (name == a[i].first){
                            found_list = true;
                            break;
                        }
                    }
                    if(!found && found_list){
                        cout << "Player is not in Top 10." << endl;
                    }
                    else if(!found_list){
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