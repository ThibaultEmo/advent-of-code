#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool differentValues(vector<char> char_vect) {
    for (int i = 0 ; i < char_vect.size() ; i++) {
        for (int j = 0 ; j < char_vect.size() ; j++) {
            if (i != j) {
                if (char_vect[i] == char_vect[j]) {
                cout << i << " " << j << endl;
                cout << char_vect[i] << " " << char_vect[j] << endl;
                return false;
            }
            }
        }
    }

    return true;
}

int main() {
    ifstream myFile;

    myFile.open("input.txt");

    cout << "START" << endl;
    int packet_start_length = 14;
    vector<char> char_vect;

    if (myFile.is_open())
    {       string line;

            getline(myFile, line);

            for (int i = 0 ; i < packet_start_length ; i++) {
                char_vect.push_back(line[i]);
            }


            //LOOP FROM THE 5TH CHARACTER TO THE END
            for (int i = packet_start_length ; i < line.length() ; i++) {



            if (differentValues(char_vect)) {
                cout << i << endl;
                break;
            }

            cout << endl;

                for (int j = 0 ; j < packet_start_length ; j++) {
                        if (j != (packet_start_length - 1)) {
                            char_vect[j] = char_vect[j+1];
                        }
                        else {
                            char_vect[j] = line[i];
                        }
                }
            }
    }

    return 0;
}
