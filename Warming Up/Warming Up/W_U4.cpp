#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>

using namespace std;

struct OpenCard {
	char card{};
	int color{ 7 };
};

struct Point {
	char x;	//열
	int y;	//행
};

OpenCard board[5][5]{};
char card[5][5]{};
int score{};
int game_round{};
int color{ 2 };

void print_board(Point point1, Point point2);
void setting_card(void);
void matching_in_pairs(Point point1, Point point2);
void show_card(void);


void main() {
	fill(&board[0][0].card, &board[4][5].card, '*');

	Point point1{};
	Point point2{};

	print_board(point1, point2);

	setting_card();
	while (game_round <= 10) {
		show_card();
		cout << endl << "행과 열을 입력하세요 : " << endl;
		cin >> point1.x;
		if (point1.x == 'r' || point1.x == 'R') {
			fill(&board[0][0].card, &board[4][5].card, '*');
			setting_card();
			game_round = 0;
			score = 0;
			color = 2;
			system("cls");
			print_board(point1, point2);
			continue;
		}
		cin >> point1.y >> point2.x >> point2.y;
		game_round++;
		matching_in_pairs(point1, point2);
	}
	cout << endl << "게임이 종료되었습니다.";
}

void print_board(Point point1, Point point2) {
	cout << "	round(" << game_round << "/10)" << endl << "  ";
	for (char i = 'a'; i < 'f'; i++) {
		cout << i << ' ';
	}
	cout << "		 score: " << score;
	for (int i = 1; i < 6; i++) {
		cout << endl;
		cout << i << ' ';
		for (int j = 0; j < 5; j++) {
			if (board[i - 1][j].color != 7) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), board[i - 1][j].color);
				cout << board[i - 1][j].card << ' ';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else {
				cout << board[i - 1][j].card << ' ';
			}
		}
	}
}

//카드 어디있는 지 보고 싶으면 주석 풀기
void show_card(void) {
	cout << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << card[i][j] << " ";
		}
		cout << endl;
	}
}

void setting_card() {
	cout << endl;
	vector<char>card_v;

	for (int j = 0; j < 2; j++) {
		for (int i = 'A'; i <= 'L'; i++) {
			card_v.push_back(i);
		}
	}
	card_v.push_back('#');
	random_shuffle(card_v.begin(), card_v.end());

	for (int i = 0, k = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++, k++) {
			card[i][j] = card_v[k];
		}
	}
}

void matching_in_pairs(Point point1, Point point2) {
	//a=97 A=65
	system("cls");
	int p1_x{}, p2_x{};
	if (point1.x < 90) {
		p1_x = point1.x - 65;
	}
	else {
		p1_x = point1.x - 97;
	}

	if (point2.x < 90) {
		p2_x = point2.x - 65;
	}
	else {
		p2_x = point2.x - 97;
	}

	if (card[point1.y - 1][p1_x] == card[point2.y - 1][p2_x]) {
		board[point1.y - 1][p1_x].color = color;
		board[point2.y - 1][p2_x].color = color++;
		board[point1.y - 1][p1_x].card = card[point1.y - 1][p1_x];
		board[point2.y - 1][p2_x].card = card[point2.y - 1][p2_x];
		score += 10;
		print_board(point1, point2);
	}
	else {
		//조커인 경우
		if (card[point1.y - 1][p1_x] == '#') {
			board[point1.y - 1][p1_x].card = card[point1.y - 1][p1_x];
			board[point2.y - 1][p2_x].card = card[point2.y - 1][p2_x];

			board[point2.y - 1][p2_x].color = color;
			score += 5;	//조커 발견해서 +5
			print_board(point1, point2);
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (card[point2.y - 1][p2_x] == card[i][j] && (point2.y - 1 != i || p2_x != j)) {
						board[i][j].card = card[i][j];
						board[i][j].color = color++;
					}
				}
			}
			Sleep(1000);
			score += 10;	//한 패 맞춰지니 +10
			print_board(point1, point2);
		}
		else if (card[point2.y - 1][p2_x] == '#') {
			board[point1.y - 1][p1_x].card = card[point1.y - 1][p1_x];
			board[point2.y - 1][p2_x].card = card[point2.y - 1][p2_x];

			board[point1.y - 1][p1_x].color = color;
			score += 5;	//조커 발견해서 +5
			print_board(point1, point2);
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (card[point1.y - 1][p1_x] == card[i][j] && (point1.y - 1 != i || p1_x != j)) {
						board[i][j].card = card[i][j];
						board[i][j].color = color++;
					}
				}
			}
			Sleep(1000);
			system("cls");
			score += 10;	//한 패 맞춰지니 +10
			print_board(point1, point2);
		}
		else {		//짝 실패
			board[point1.y - 1][p1_x].card = card[point1.y - 1][p1_x];
			board[point2.y - 1][p2_x].card = card[point2.y - 1][p2_x];
			board[point1.y - 1][p1_x].color = color++;
			board[point2.y - 1][p2_x].color = color;
			print_board(point1, point2);
			Sleep(1000);
			system("cls");
			score -= 5;
			board[point1.y - 1][p1_x].card = '*';
			board[point2.y - 1][p2_x].card = '*';
			board[point1.y - 1][p1_x].color = 7;
			board[point2.y - 1][p2_x].color = 7;
			color--;
			print_board(point1, point2);
		}
	}

}

// 중복으로 받는거 처리 안함(열려있는 카드 다른 턴에 다시 열어서 틀리면 열려있던 거 닫힘)
// 범위 벗어나는 값 받는거 처리 안함