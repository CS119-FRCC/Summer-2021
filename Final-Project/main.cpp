#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void splashScreen() {

   cout <<  "    ___                       _            __   __    _     _                         ___                                   \n"
            "   / __|    ___     ___    __| |     o O O \\ \\ / /   (_)   | |__     ___      o O O  / __|   __ _    _ __     ___     ___   \n"
            "  | (_ |   / _ \\   / _ \\  / _` |    o       \\ V /    | |   | '_ \\   / -_)    o      | (_ |  / _` |  | '  \\   / -_)   (_-<   \n"
            "   \\___|   \\___/   \\___/  \\__,_|   TS__[O]  _\\_/_   _|_|_  |_.__/   \\___|   TS__[O]  \\___|  \\__,_|  |_|_|_|  \\___|   /__/_  \n"
            " _|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| {======|_| \"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| {======|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| \n"                                     
            " \"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'./o--000'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-'\"`-0-0-' \n\n\n"<< flush;


    cout << "              ★░░░░░░░░░░░████░░░░░░░░░░░░░░░░░░░░★\n"
            "              ★░░░░░░░░░███░██░░░░░░░░░░░░░░░░░░░░★\n" 
            "              ★░░░░░░░░░██░░░█░░░░░░░░░░░░░░░░░░░░★\n" 
            "              ★░░░░░░░░░██░░░██░░░░░░░░░░░░░░░░░░░★\n" 
            "              ★░░░░░░░░░░██░░░███░░░░░░░░░░░░░░░░░★\n" 
            "              ★░░░░░░░░░░░██░░░░██░░░░░░░░░░░░░░░░★\n" 
            "              ★░░░░░░░░░░░██░░░░░███░░░░░░░░░░░░░░★\n" 
            "              ★░░░░░░░░░░░░██░░░░░░██░░░░░░░░░░░░░★\n" 
            "              ★░░░░░░░███████░░░░░░░██░░░░░░░░░░░░★\n" 
            "              ★░░░░█████░░░░░░░░░░░░░░███░██░░░░░░★\n" 
            "              ★░░░██░░░░░████░░░░░░░░░░██████░░░░░★\n" 
            "              ★░░░██░░████░░███░░░░░░░░░░░░░██░░░░★\n" 
            "              ★░░░██░░░░░░░░███░░░░░░░░░░░░░██░░░░★\n" 
            "              ★░░░░██████████░███░░░░░░░░░░░██░░░░★\n" 
            "              ★░░░░██░░░░░░░░████░░░░░░░░░░░██░░░░★\n"
            "              ★░░░░███████████░░██░░░░░░░░░░██░░░░★\n" 
            "              ★░░░░░░██░░░░░░░████░░░░░██████░░░░░★\n" 
            "              ★░░░░░░██████████░██░░░░███░██░░░░░░★\n"
            "              ★░░░░░░░░░██░░░░░████░███░░░░░░░░░░░★\n"
            "              ★░░░░░░░░░█████████████░░░░░░░░░░░░░★\n" 
            "              ★░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░★\n\n\n" << flush;

    
    cout << "                _    ___   _   ___ ___ _  _  ___ \n"
 "               | |  / _ \\ /_\\ |   \\_ _| \\| |/ __|\n"
 "               | |_| (_) / _ \\| |) | || .` | (_ |\n"
 "               |____\\___/_/ \\_\\___/___|_|\\_|\\___|        "<< flush;
                                   
        cout << "░░░░░░░░░░░░░░░░░░░░░░" << flush;
        sleep(2);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b███░░░░░░░░░░░░░░░░░░░" << flush;
        sleep(2);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b█████████████░░░░░░░░░" << flush;
        sleep(2);
        cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b█████████████████████░" << flush;
        sleep(1);
        system("clear");






    cout << "\n\n\n    ████████╗██╗ ██████╗████████╗ █████╗  ██████╗████████╗ ██████╗ ███████╗\n"
        "    ╚══██╔══╝██║██╔════╝╚══██╔══╝██╔══██╗██╔════╝╚══██╔══╝██╔═══██╗██╔════╝\n"
        "       ██║   ██║██║        ██║   ███████║██║        ██║   ██║   ██║█████╗  \n"
        "       ██║   ██║██║        ██║   ██╔══██║██║        ██║   ██║   ██║██╔══╝  \n"
        "       ██║   ██║╚██████╗   ██║   ██║  ██║╚██████╗   ██║   ╚██████╔╝███████╗\n"
        "       ╚═╝   ╚═╝ ╚═════╝   ╚═╝   ╚═╝  ╚═╝ ╚═════╝   ╚═╝    ╚═════╝ ╚══════╝\n"
        "\n\n       © 2021 Front Range Community College\n\n"<< flush;
                                                                       


}


//tictactoe game
struct TicTacToeGame {
    char board[10] = {'?', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char turn;
    char player_1;
    char player_2;
    char winner = -1;
};

void printBoard(const TicTacToeGame &game) {
    
}

void printWinner(const TicTacToeGame &game) {
                                             
}

void printTie(const TicTacToeGame &game) {
                   
}

bool isValidMove(const TicTacToeGame &game, const int position) {

}

void makeMove(TicTacToeGame &game) {
  
}

bool checkForEndOfGame(TicTacToeGame &game) {

}

void playGame(TicTacToeGame &game) {

}


int main(int argc, char **argv) {
    TicTacToeGame test;
    playGame(test);
    return 0;
}



