#include <iostream>
using namespace std;


void fillArr(int arr[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = -1;
        }
    }
}

int checkWin(int arr[][3]){
    // check all rows one by one
    for(int i = 0; i < 3; i++){
        if(arr[i][0] == -1){
            continue;
        }
        int last = arr[i][0];
        int conseq = 0;
        for(int j = 0; j < 3; j++){
            if(last == arr[i][j]){
                conseq++;
                if(conseq == 3){
                    cout << last << " Wins the game" << endl;
                    return 1;
                }
            }
        }
    }
    // check all columns one by one
    for(int i = 0; i < 3; i++){
        if(arr[0][i] == -1){
            continue;
        }
        int last = arr[0][i];
        int conseq = 0;

        for(int j = 0; j < 3; j++){
            if(last == arr[j][i]){
                conseq++;
                if(conseq == 3){
                    cout << last << " Wins the game." << endl;
                    return 1;

                }
            }
        }
    }
    // diagonal check
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != -1){
        cout << arr[0][0] << " Wins the game." << endl;
        return 1;
    }
    if(arr[0][2] == arr[1][1] && arr[1][1] ==  arr[2][0] && arr[2][0] != -1){
        cout << arr[0][2] << " Wins the game." << endl;
        return 1;
    }
    
    return 0;
}

int takeInput(int arr[][3], int *piece, int *moves){
    int r, c;
    if(*piece) {
        cout << "Player X's turn, enter the row and column of your move: ";
    } else {
        cout << "Player O's turn, enter the row and column of your move: " ;
    }
    cin >> r >> c;
    while(r <= 0 || r > 3 || c <= 0 || c > 3){
        cout << "Please enter a valid input, the rows and columns can range from 1 to 3 only." << endl;
        cin >> r >> c;
    }
    cout << endl;
    // check if position is taken
    if(arr[r-1][c-1] != -1){
        cout << "Invalid input, position already taken." << endl;
    } else {
        arr[r-1][c-1] = *piece;
        if(*piece) *piece = 0;
        else *piece = 1;
        *moves = *moves - 1;
    }
    if(*moves == 0){
        cout << "Game Drawn." << endl << endl;
        return 0;
    }
    if(checkWin(arr)){
        return 0;
    }
    return 1;
}

void printBoard(int arr[][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] == -1){
                cout << "   ";
            } else if(arr[i][j] == 1){
                cout << " X ";
            } else {
                cout << " O ";
            }
            if(j < 2) cout << "|";
        }
        cout << endl;
        if(i < 2) cout << "------------" << endl;
    }
    cout << endl;
}

int main(){
    bool play = true;
    int piece = 1;
    int moves = 9;
    int arr[3][3]; // this stores the piece locations
    fillArr(arr);
    while(play){
        play = takeInput(arr, &piece, &moves);
        printBoard(arr);
    }
}