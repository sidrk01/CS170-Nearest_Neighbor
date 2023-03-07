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
const string options = "[1] Feature Selection\n[2] Backward Elimination\n[3] Sid's Special Algorithm.\n";
const string default_eval = "Using no features and 'random' evaluation, I get an accuracy of ";
const string proceed = "Would you like to try another algorithm?\nEnter 'Y' to continue or 'N' to quit.\n";
const string border = "========================================================================================================================";

void data_entry(){
    string current_line;
    string user_file;
    bool flag = false; //flag raised for working .txt file
    int current_itr = 0;
    vector<vector<double>> data_num;
    vector<double> temp;

    while (!flag){
        cout << file_name;
        cin >> user_file;

        ifstream file("small.txt");
        if(!file.is_open()){
            cout << invalid_file << user_file << endl;
        } else {
            flag = true; //causes loop to exit
        }
    }
//        while(file >> current_line){ //reads data from column val into string
//            temp.push_back(stod(current_line)); //parse the string into double
//            data_num.push_back(temp);
//            for (unsigned i = 0; i < temp.size(); i++){
//                cout << "Double value " << i << ":" << data_num.at(current_itr).at(i);
//            }
//        }

}

#endif //UNTITLED_UIFUNCTIONS_H

