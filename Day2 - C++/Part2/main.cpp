#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getTurnScore(char player_1_play, char player_2_end) {
    int rock = 1, paper = 2, scissor = 3;
    int lose = 0, draw = 3, win = 6;

    switch(player_1_play)
    {
    case 'A': //P1 ROCK
        if (player_2_end == 'X') { return lose + scissor; } //P2 NEEDS A LOSE
        if (player_2_end == 'Y') { return draw + rock; } //P2 NEEDS A DRAW
        if (player_2_end == 'Z') { return win + paper; } //P2 NEEDS A WIN
        break;
    case 'B': //P1 PAPER
        if (player_2_end == 'X') { return lose + rock; }
        if (player_2_end == 'Y') { return draw + paper; }
        if (player_2_end == 'Z') { return win + scissor; }
        break;
    case 'C': //P1 SCISSORS
        if (player_2_end == 'X') { return lose + paper; }
        if (player_2_end == 'Y') { return draw + scissor; }
        if (player_2_end == 'Z') { return win + rock; }
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
                char player_1_play, player_2_end;

                player_1_play = line[0];
                player_2_end = line[2];

                cout << player_1_play << " , " << player_1_play << " : " << getTurnScore(player_1_play,player_2_end) << endl;
                total_score += getTurnScore(player_1_play,player_2_end);
              }
    }

    cout << total_score << endl;
    return 0;
}
