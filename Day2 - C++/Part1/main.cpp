#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getTurnScore(char player_1_play, char player_2_play) {
    int rock = 1, paper = 2, scissor = 3;
    int lose = 0, draw = 3, win = 6;

    switch(player_1_play)
    {
    case 'A': //P1 ROCK
        if (player_2_play == 'X') { return draw + rock; } //P2 ROCK
        if (player_2_play == 'Y') { return win + paper; } //P2 PAPER
        if (player_2_play == 'Z') { return lose + scissor; } //P2 SCISSORS
        break;
    case 'B': //P1 PAPER
        if (player_2_play == 'X') { return lose + rock; }
        if (player_2_play == 'Y') { return draw + paper; }
        if (player_2_play == 'Z') { return win + scissor; }
        break;
    case 'C': //P1 SCISSORS
        if (player_2_play == 'X') { return win + rock; }
        if (player_2_play == 'Y') { return lose + paper; }
        if (player_2_play == 'Z') { return draw + scissor; }
        break;
    }

    return 0;
}


int main() {
    ifstream myFile;

    myFile.open("input.txt");

    cout << "START" << endl;

    int total_score = 0;

    if (myFile.is_open())
    {       string line;

            while(getline(myFile, line))
            {
                char player_1_play, player_2_play;

                player_1_play = line[0];
                player_2_play = line[2];

                cout << player_1_play << " , " << player_2_play << " : " << getTurnScore(player_1_play, player_2_play) << endl;
                total_score += getTurnScore(player_1_play, player_2_play);
              }
    }

    cout << total_score << endl;
    return 0;
}
