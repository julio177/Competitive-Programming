#include <iostream>
#include <algorithm>

using namespace std;

struct Team {
    int points;
    int average;
    string name;
};

bool compareTeam(Team a, Team b) {
    if(a.points > b.points) {
        return true;
    }
    if(a.points == b.points) {
        return a.average > b.average;
    }
    return false;
}

int main() {
    int teamsQty, games;
    Team teams[20];
    cin >> teamsQty >> games;

    for(int i = 0; i < teamsQty; i++) {
        cin >> teams[i].name;
        teams[i].points = 0;
        teams[i].average = 0;
    }

    string teamName, type;
    int goalsScored, goalsReceived;
    for(int i = 0; i < teamsQty * games; i++) {
        cin >> teamName >> type >> goalsScored >> goalsReceived;
        for(int j = 0; j < teamsQty; j++) {
            if(teams[j].name == teamName) {
                //win
                if(goalsScored > goalsReceived) {
                    teams[j].points += 3;
                    if(type == "V") {
                        teams[j].points += 1;
                    }
                }
                //draw
                else if(goalsScored == goalsReceived) {
                    teams[j].points += 1;
                    if(type == "V") {
                        teams[j].points += 1;
                    }
                }
                teams[j].average = goalsScored - goalsReceived;
            }
        }
    }
    sort(teams, teams + teamsQty, compareTeam);
    for(int i = 0; i < teamsQty; i++) {
        cout << teams[i].name << " " << teams[i].points << " " << teams[i].average << endl;
    }
}