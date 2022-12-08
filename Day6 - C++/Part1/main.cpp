#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    ifstream myFile;

    myFile.open("input.txt");

    cout << "START" << endl;


    if (myFile.is_open())
    {       string line;
            char c1,c2,c3,c4;

            cout << line.length() << endl;

            getline(myFile, line);

            //GET THE FIRST 4 CHARACTERS
            c1 = line[0];
            c2 = line[1];
            c3 = line[2];
            c4 = line[3];

            //LOOP FROM THE 5TH CHARACTER TO THE END
            for (int i = 4 ; i < line.length() ; i++) {

                cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
                //CHECK C1 WITH OTHER C
                if (c1 != c2 && c1 != c3 && c1 != c4) {
                        //C2 WITH OTHER C
                        if (c2 != c3 && c2 != c4) {
                            //C3 WITH OTHER C
                            if (c3 != c4) {
                                cout << i << endl; //PRINT THE POSITION
                                break;
                        }
                    }
                }

                //MOVE IN THE STRING
                c1 = c2;
                c2 = c3;
                c3 = c4;
                c4 = line[i];
            }
    }

    return 0;
}
