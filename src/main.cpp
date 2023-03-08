#include <iostream>
#include "../header/uifunctions.h"
#include "../header/SearchAlgos.h"
#include "../header/Normalize.h"

vector<vector<double>> user_vct; //global variable to store data entries

int main() {
    char user_opt = 'Y'; //used to continue running program
    char user_opt_2 = 'Y'; //used to allow normalization of features
    int features_num = 0;
    int user_choice = 0;

//// TEST: Helper functions for mean and standard deviation
//    double c = 0;
//    vector<double> temp;
//    for (unsigned i = 0; i < 3; i++){
//        temp.push_back(c);
//        c += 0.18;
//    }
//
//    for (unsigned i = 0; i < 5; i++){
//        user_vct.push_back(temp);
//    }
//
//    for (auto & i : user_vct) {
//        for (double j: i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//        Normalize test(user_vct);
//
//   user_vct =  test.normalize_data();
//cout << endl;
//    for (auto & i : user_vct){
//            for (double j : i){
//                cout << j << " ";
//            }
//            cout << endl;
//        }

    while (user_opt == 'Y' || user_opt == 'y') {
        cout << welcome << border; //Welcome prompt

        user_vct = data_entry();

////        TEST: Make sure column and row of 2D vector are swapped correctly
//        for (auto & i : user_vct){
//            for (double j : i){
//                cout << j << " ";
//            }
//            cout << endl;
//        }

//        cout << algo_choice; //choices for algorithm
//        cin >> features_num;

        cout << border;

        cout << normalize;
        cin >> user_opt_2;
        if (user_opt_2 == 'Y' || user_opt_2 == 'y'){
            Normalize user_normalize(user_vct);
            user_vct = user_normalize.normalize_data();
////        TEST: Make sure standardized values  are calculated correctly
//        for (auto & i : user_vct){
//            for (double j : i){
//                cout << j << " ";
//            }
//            cout << endl;
//        }
        }

        cout << options;
        cin >> user_choice;
        //create searchalgos object
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
