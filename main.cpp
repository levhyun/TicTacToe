#include <iostream>
#include <random>

using namespace std;

char randomTurn();
void header();
void gameGui(char array[][3]);
int insertIcon(char array[][3], int x, int y, char icon);
char turnChange(char turn);
int cheak(char array[][3], int cnt);
void win(char winner);
void tie();

int main() {
    char array[][3] = { 
        { ' ',' ',' ' },
        { ' ',' ',' ' },
        { ' ',' ',' ' }
    };
    int x, y;
    int cnt = 0;
    char turn = { randomTurn() };
    header();
    while (1) {
        gameGui(array);
        cout << turn << "가 할 차례입니다." << endl;
        while (1) {
            cout << "좌표를 입력하세요." << endl;
            cout << "x : ";
            cin >> x;
            cout << "y : ";
            cin >> y;
            int err = insertIcon(array, x, y, turn);
            if (err == 0) {
                break;
            }
        }
        cnt++;
        if (cheak(array, cnt)) {
            break;
        }
        turn = turnChange(turn);
    }   
    return 0;
}

char randomTurn() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 1);
    int num = dis(gen);
    if (num == 0) {
        return 'O';
    }
    else if (num == 1) {
        return 'X';
    }
}

void header() {
    cout << "[Tic Tac Toe]\n";
}

void gameGui(char array[][3]) {
    cout << "┏━━━┳━━━┳━━━┓" << endl;
    cout << "┃ "<< array[0][0] << " ┃ " << array[0][1] << " ┃ " << array[0][2] << " ┃" << endl;
    cout << "┣━━━╋━━━╋━━━┫" << endl;
    cout << "┃ " << array[1][0] << " ┃ " << array[1][1] << " ┃ " << array[1][2] << " ┃" << endl;
    cout << "┣━━━╋━━━╋━━━┫" << endl;
    cout << "┃ " << array[2][0] << " ┃ " << array[2][1] << " ┃ " << array[2][2] << " ┃" << endl;
    cout << "┗━━━┻━━━┻━━━┛" << endl;
}

int insertIcon(char array[][3], int x, int y, char icon) {
    if (array[x][y] != ' ') {
        gameGui(array);
        cout << "이미 채워져 있는 칸입니다!" << endl;
        cout << "다시 ";
        return -1;
    }
    array[x][y] = icon;
    return 0;
}

char turnChange(char turn) {
    if (turn == 'O') {
        return 'X';
    }
    else {
        return 'O';
    }
}

int cheak(char array[][3], int cnt) {
    if ((array[0][0] == array[1][1] && array[0][0] == array[2][2]) || (array[2][2] == array[1][1] && array[2][2] == array[2][0])) {
        if (array[1][1] != ' ') {
            win(array[1][1]);
        }
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (array[i][0] == array[i][1] && array[i][0] == array[i][2] && array[i][0] != ' ') {
            win(array[i][0]);
            return 1;
        } 
    }
    for (int i = 0; i < 3; i++) {
        if (array[0][i] == array[1][i] && array[0][i] == array[2][i] && array[0][i] != ' ') {
            win(array[0][i]);
            return 1;
        }
    }
    if (cnt == 9) {
        tie();
        return 1;
    }
    return 0;
}

void win(char winner) {
    cout << "------------------" << endl;
    cout << winner << "가 이겼습니다!" << endl;
    cout << "------------------" << endl << endl;
}

void tie() {
    cout << "------------------" << endl;
    cout << "무승부입니다..." << endl;
    cout << "------------------" << endl << endl;
}