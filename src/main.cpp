#include <iostream>
#include "../header/uifunctions.h"
#include "../header/SearchAlgos.h"

vector<vector<double>> user_vct; //global variable to store data entries

int main() {
    char user_opt = 'Y';
    int features_num = 0;
    int user_choice = 0;


    while (user_opt == 'Y' || user_opt == 'y') {
        cout << welcome << endl; //Welcome prompt

        data_entry();

        cout << algo_choice; //choices for algorithm
        cin >> features_num;
        cout << border;

        cout << options;
        cin >> user_choice;

        //create searchalgos object

        vector<double> v =  {30.0};
        for (unsigned i = 0; i < features_num + 1; i++){
            user_vct.push_back(v);
        }

        SearchAlgos searchAlgos(user_vct);

        if (user_choice == 1) {
            //Forward Selection
            searchAlgos.forward_selection();
        } else if (user_choice == 2) {
            //Backward Selection
            searchAlgos.backward_selection();
        } else {
            //Sid's Special Algorithm
        }

        cout << border;

        cout << proceed;
        cin >> user_opt;
    }

    return 0;
}
