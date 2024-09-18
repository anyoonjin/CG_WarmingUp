#include <iostream>
//#include <Windows.h>
#include <algorithm>
#include <vector>

using namespace std;
//random_device rd;
//mt19937 mt(rd());
//uniform_int_distribution<int> alpha(0, 4);

char board[5][5]{};
char card[5][5]{};

struct Point {
	char x;	//열
	int y;	//행
};

void print_board(void);
void setting_card(void);
void matching_in_pairs(Point point1,Point point2);
void open_card(void);


void main() {
	fill(&board[0][0], &board[4][5], '*');
	fill(&card[0][0], &card[4][5], '*');

	print_board();
	//system("cls");

	Point point1{};
	Point point2{};

	setting_card();
	while (1) {
		cout << endl << "행과 열을 입력하세요 : " << endl;
		cin >> point1.y >> point1.x >> point2.y >> point2.x;
	}
}

void print_board() {
	cout << "  ";
	for (char i = 'a'; i < 'f'; i++) {
		cout << i << ' ';
	}
	for (int i = 1; i < 6; i++) {
		cout << endl;
		cout << i << ' ';
		for (int j = 0; j < 5; j++) {
			cout << board[i - 1][j] << ' ';
		}
	}
}

void setting_card() {
	cout << endl;
	vector<char>card;

	for (int j = 0; j < 2; j++) {
		for (int i = 'A'; i <= 'L'; i++) {
			card.push_back(i);
		}
	}
	card.push_back('#');
	random_shuffle(card.begin(), card.end());
	
	//카드 어디있는 지 보고 싶으면 주석 풀기
	//for (int i = 0; i < 25;) {
	//	for (int j = 0; j < 5; i++,j++) {
	//	cout << card[i] << " ";
	//	}
	//	cout<<endl;
	//}
}

void matching_in_pairs(Point point1, Point point2) {
	//a=97 A=65
	//if(point1.x)
}