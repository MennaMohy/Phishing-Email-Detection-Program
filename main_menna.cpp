#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <unordered_map>
#include <fstream>
#include <algorithm>

using namespace std;


vector<string> split(string target, string delimiter) {
    vector<string> output;
    int delimiter_position;
    string element;

    // While the delimiter is found, cut the text from the beginning till the delimiter position
    while ((delimiter_position = target.find(delimiter)) != string::npos) {
        element = target.substr(0, delimiter_position);
        // Add the elements to the output vector
        output.push_back(element);
        // Delete the element added and delimiter from the string
        target.erase(0, delimiter_position + delimiter.length());
    }
    // Add the last element after the last delimiter
    output.push_back(target);
    return output;
}


void binaryPrint(int n) {
    // If number = 0, then the binary number will be = 0
    if (n == 0) {
        cout << "0";
    } else if (n > 0) {
        // Divide the number by 2 till it reaches 1
        if (n > 1) {
            binaryPrint(n / 2);
        }
        // Display the remainder (0/1) from the LSB till the MSB
        cout << n % 2;
    }
}


void Numbers(string prefix, int k) {
    // Base case: if k is 0 (no more combinations), print the current prefix
    if (k == 0) {
        cout << prefix << endl;
    } else {
        k--;
        // Recursive calls to add zero and one to the prefix, till k = 0
        Numbers(prefix + "0", k);
        Numbers(prefix + "1", k);
    }
}


bool bears(int n){
    // Base case: number of bears is 42, goal achieved
    if(n == 42){
        return true;
    }
    // If n is less than 42, goal cannot be achieved
    if(n < 42){
        return false;
    }
    // If n is divisible by 5, check if (n - 42) can achieve the goal
    if (n % 5 == 0 && bears(n - 42)) {
        return true;
    }
    // If n is divisible by 2, check if (n / 2) can achieve the goal
    if (n % 2 == 0 && bears(n / 2)) {
        return true;
    }
    // If n is divisible by 3 or 4, multiply the last two digits
    if(n % 3 == 0 || n % 4 == 0) {
        int result = (n % 10) * ((n % 100) / 10);

        // If the result is greater than 0, check if (n - result) can achieve the goal
        if (result > 0 && bears(n - result)) {
            return true;
        }
    }
    // if no condition is matched, return false
    return false;
}

// List of phrases commonly found in phishing messages and their points.
unordered_map<string,int> Phrashes_and_Points{

         {"click here", 1},{"action required", 2},{"urgent", 2},{"password reset", 3},
         {"congratulations!", 2},{"you have won", 3},{"security alert", 3},{"visa", 3},
         {"facebook", 1}, {"download now", 3},{"secure your account", 2},{"verify", 3},
         {"password", 2},{"your username", 2},{"confirm your email", 2},{"win a gift card", 3}
        ,{"you have won an iphone", 3}, {"unusual activity", 2}, {"bank account", 2},
         {"download now", 3},{"claim your prize", 3},{"free trial", 2},{"account setup", 1},
         {"we’ve noticed a problem", 3},{"dear user", 1},{"win a cash prize", 3},
         {"click here to unlock", 3}, {"free", 2},{"google", 2},{"netflix",2},{"fake",3}


};
// List of the phrases and their occurrences.
unordered_map<string,int> Occurrences{
};

int main() {
    cout << "         WELCOME !\n____________________________ \n";

    char choice1, choice2;

    while (true){
        cout << "Choose the program you want :\n1) Split input \n2) Binary functions\n3) Teddy Bear Picnic\n"
                "4) Phishing Scanner\n5) Exit\n";
        cin >> choice1;
        cin.ignore();

        switch (choice1) {
            case '1':{

                string target, delimiter;

                cout << "Please enter the string to be split: " << endl;
                getline(cin, target);

                cout << "Please Enter the delimiter: " << endl;
                getline(cin, delimiter);

                // Split the string and store it in the result vector
                vector<string> result = split(target, delimiter);

                cout << "The string split is: " << endl;

                // Display the split result in double quotes, separated by commas
                for(int i = 0; i < result.size(); i++) {
                    cout << "\"" << result[i] << "\"";
                    if (i != result.size() - 1) {
                        cout << ", ";
                    }
                }

                cout << "\n____________________________ \n";
                break;

            }

            case '2':{
                cout << "Choose the program you want : \nA) Binary conversion \nB) Printing many numbers \n";
                cin >> choice2;
                choice2 = tolower(choice2);

                switch (choice2) {

                    case 'a':{

                        int n;
                        cout << "Please enter a non-negative integer: \n";
                        cin >> n;

                        // Keep looping until the input is Non-negative Integer
                        while (cin.fail() || n < 0) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Please enter a non-negative integer: \n";
                            cin >> n;
                        }

                        binaryPrint(n);
                        cout << endl;

                        break;
                    }
                    case 'b': {
                        while (true) {
                            string prefix;
                            cout << "Please enter a binary number: \n";
                            cin >> prefix;

                            // Remove the leading zeros
                            while (prefix[0] == '0') {
                                prefix.erase(0, 1);
                            }

                            bool binary = true;
                            // Make sure the entered number is binary one
                            for (int i = 0; i < prefix.size(); i++) {
                                if (prefix[i] != '0' && prefix[i] != '1') {
                                    binary = false;
                                    cout << "Invalid binary number, ";
                                    break;
                                }
                            }

                            if (binary) {
                                int k;
                                cout << "Please enter a k-digit suffix: \n";
                                cin >> k;
                                // If no input and one combination
                                if (prefix.empty() && k == 1) {
                                    Numbers("", k);
                                }
                                    // If no input and zero combination
                                else if(prefix.empty() && k == 0){
                                    cout << "0"<< endl;
                                }else{
                                    Numbers(prefix, k);
                                }
                                break;
                            }
                        }
                        break;
                    }

                    default: {
                        cout << "Invalid choice, please enter a valid choice: " << endl;
                        break;
                    }
                }

                break;
            }
            case '3':{

                int num_bears;
                cout << "Please enter the number of bears: \n";
                cin >> num_bears;

                if(bears(num_bears)){
                    cout << "You have reached the goal!\n";
                }else{
                    cout << "Failed, please try again\n";
                }
            }
                break;

            case '4':{
                string fileName;
                cout << "Please enter the name of the file (without spaces) : \n";
                cin >> fileName;

                ifstream file(fileName);
                string line;

                // Loop until the file open normally
                while (file.fail()) {
                    cout << "Error in opening the file!\n";
                    cout << "Please enter the name of the file (without spaces) : \n";
                    cin >> fileName;
                    file.clear();
                    file.open(fileName);
                }
                int Total_points = 0;

                // While not the end of the file get the line from the file
                while(!file.fail() && !file.eof()){

                    getline(file,line);
                    // Change the words in the file, so they become lower case
                    transform(line.begin(), line.end(), line.begin(), ::tolower);

                    // For loop about all the list, to find if the phrases are found
                    for (const auto& [phrase, points] : Phrashes_and_Points) {

                        if(line.find(phrase) != string::npos){
                            // If found increase the occurrence of the phrase by one
                            Occurrences[phrase]++;
                            // Increase the total points by the points of this phrase
                            Total_points += points;
                        }
                    }
                }
                for (const auto& [phrase, occurrences] : Occurrences) {

                    // If the phrase is occurred, display the phrase and how many times it occurred and its points
                    if(occurrences > 0){
                        cout << "Phrase: \" " << phrase << " \", have been occurred " << occurrences << " time/s.\nHaving "
                             << occurrences*Phrashes_and_Points[phrase] << " total points.\n";
                    }
                }
                cout << "\nWe got " << Total_points << " total points! \n";

                // If the total points of the file is equal to 10 or more, considered as phishing file
                if(Total_points > 9 ){
                    cout << "This e-mail seems to be a phishing e-mail, Be Careful !\n";
                } else{
                    cout << "This e-mail seems to be legitimate e-mail\n";
                }
                cout << "____________________________\n";
                break;
            }

            case '5':{

                cout << "Thank you for using the program! \n____________________________";
                return 0;

            }

            default: {
                cout << "Invalid choice, please enter a valid choice: " << endl;
                break;
            }

        }
    }

}
