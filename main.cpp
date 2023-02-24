#include <iostream>
#include "header/uifunctions.h"
#include "header/SearchAlgos.h"

int main() {
    char user_opt = 'Y';
    int features_num = 0;
    int user_choice = 0;

    Node n;
    for (unsigned i = 0; i < 5; i++) {
        printf("%.3g", n.accuracy(&n));
        cout << " ";
    }
    /*
    while (user_opt == 'Y' || user_opt == 'y') {
        cout << welcome; //Welcome prompt
        cout << algo_choice; //choices for algorithm
        cin >> features_num;
        cout << border;

        cout << options;
        cin >> user_choice;

        if (user_choice == 1) {
            //Forward Selection
        } else if (user_choice == 2) {
            //Backward Selection
        } else {
            //Sid's Special Algorithm
        }

        cout << border;

        cout << proceed;
        cin >> user_opt;
    }
*/
        return 0;
    return 0;
}
