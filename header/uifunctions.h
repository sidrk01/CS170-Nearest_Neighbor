//
// Created by sidha on 2/23/2023.
//

#ifndef UNTITLED_UIFUNCTIONS_H
#define UNTITLED_UIFUNCTIONS_H

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

const string welcome = "Welcome to Sid's Feature Selection Algorithm.\n\n";
const string file_name = "Please include the filename you would like to test\n";
const string invalid_file = "Sorry, the following file couldn't be located: ";
const string algo_choice = "Please enter the total number of features:\n";
const string options = "[1] Forward Selection\n[2] Backward Elimination\n";
const string normalize = "Would you like to normalize the continuous features?\nEnter 'Y' to confirm.\n";
const string default_eval = "Using no features and 'random' evaluation, I get an accuracy of ";
const string proceed = "Would you like to try another algorithm?\nEnter 'Y' to continue or 'N' to quit.\n";
const string border = "========================================================================================================================";

//responsible for reading each column value and subsequent row and storing in 2D vector
vector<vector<double>> data_entry(){
    string current_line;
    string user_file;
    string add_line;
    bool flag = false; //flag raised for working .txt file
    vector<vector<double>> data_num;
    vector<double> temp;

    while (!flag){
        cout << file_name;
        cin >> user_file;

        ifstream file(user_file);
        if(!file.is_open()){
            cout << invalid_file << user_file << endl;
        } else {
            flag = true; //causes loop to exit
            getline(file, current_line);
            stringstream string_file(current_line);

            while(string_file >> current_line) { //reads data from column val into string
                temp.push_back(stod(current_line)); //parse the string into double
                data_num.push_back(temp);
                temp.clear();
            }

            while (getline(file, current_line)) {
                stringstream file_i(current_line);
                for (auto & i : data_num) {
                    if (file_i >> add_line)
                        i.push_back(stod(add_line));
                }
            }
        }
    }

    return data_num;
}


#endif //UNTITLED_UIFUNCTIONS_H

