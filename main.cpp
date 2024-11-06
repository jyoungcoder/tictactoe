#include <iostream>
#include <vector>

void initBoard(std::vector<std::vector<char>> board) {    
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2)
                std::cout << "|";
                
        }
        std::cout << std::endl;
        if (i < 2)
            std::cout << "---|---|---\n";
    }
}

void getInput(std::vector<std::vector<char>> &board, bool &playerTurn) {
    int position;
    char player = 'o';
    char computer = 'x';
    int counter = 0;

    //getting input
    if (playerTurn == true) {
        std::cout << "Player's turn: ";
    } else {
        std::cout << "Computer's turn: ";
    }

    // updating square
    std::cin >> position;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            counter++;
            if (counter == position) {
                if (playerTurn == true) {
                    board[i][j] = player;
                    playerTurn = false;
                } else {
                    board[i][j] = computer;
                    playerTurn = true;
                }
            }
        }
    }

}

void checkWin(std::vector<std::vector<char>> board, bool &gameRunning) {
    std::vector<char> winConditionO = {'o', 'o', 'o'};
    std::vector<char> winConditionX = {'x', 'x', 'x'};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i] == winConditionO || board[i] == winConditionX) {
                gameRunning = false;
            }
        }
    }


    // brute force cus i don't know how to do it
    if (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') {
        gameRunning = false;
    } else if (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') {
        gameRunning = false;
    } else if (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x') {
        gameRunning = false;
    }

    if (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') {
        gameRunning = false;
    } else if (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') {
        gameRunning = false;
    } else if (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') {
        gameRunning = false;
    }
}

int main() {
    // initialise the board
    std::vector<std::vector<char>> board = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    /*
        {'[0][0]', '[0][1]', '[0][2]'},
        {'[1][0]', '[1][1]', '[1][2]'},
        {'[2][0]', '[2][1]', '[2][2]'}
    */

    bool gameRunning = true;
    bool playerTurn = false;

    initBoard(board);

    // switching turns every move
    
    while (gameRunning) {
        getInput(board, playerTurn);
        initBoard(board);
        checkWin(board, gameRunning);
    }


}   