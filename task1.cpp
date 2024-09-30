#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
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
            else if(v == "She"){
                a[i] = "She or he" + string(1, last);
            }
            else if(v == "she"){
                a[i] = "she or he" + string(1, last);
            }
            else if(v == "Him"){
                a[i] = "Him or her" + string(1, last);
            }
            else if(v == "him"){
                a[i] = "him or her" + string(1, last);
            }
            else if(v == "Her"){
                a[i] = "Her or him" + string(1, last);
            }
            else if(v == "her"){
                a[i] = "her or him" + string(1, last);
            }
        } else {
            if(v == "He"){
                a[i] = "He or she";
            }
            else if(v == "he"){
                a[i] = "he or she";
            }
            else if(v == "She"){
                a[i] = "She or he";
            }
            else if(v == "she"){
                a[i] = "she or he";
            }
            else if(v == "Him"){
                a[i] = "Him or her";
            }
            else if(v == "him"){
                a[i] = "him or her";
            }
            else if(v == "Her"){
                a[i] = "Her or him";
            }
            else if(v == "her"){
                a[i] = "her or him";
            }
        }
    }
    for(int i = 0 ; i < a.size() ; i++){
        cout << a[i] << " ";
    }
}
