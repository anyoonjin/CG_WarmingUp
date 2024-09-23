#include <iostream>
#include <windows.h>

using namespace std;

struct BOARD {
	char ch;
	int crash{};	//2�� �Ǹ� �浹�� ����
};
BOARD board[30][30]{};

struct BoxSize {
	int x1;
	int y1;
	int x2;
	int y2;
	bool pr{ false };	//����Ʈ
	char sym{};
};

BoxSize Box1[5]{};
BoxSize Box2[5]{};


void input_value(int num, BoxSize* Box);	//�׸� ��ǥ �ޱ�
void print_board(void);
//void draw_box(BoxSize Box[]);	//���� ���忡 �׸���
void make_box(BoxSize Box[]);	//���� ��ġ ���
void fill_int();

void main() {
	fill(&Box1[0].sym, &Box1[5].sym, '@');
	fill(&Box2[0].sym, &Box2[5].sym, '&');


	char command{};
	float area{};

	fill(&board[0][0].ch, &board[29][30].ch, '*');
	fill_int();
	input_value(1, &Box1[0]);
	input_value(2, &Box2[0]);
	make_box(Box1);
	make_box(Box2);
	print_board();

	while (true) {

		cout << "input order: ";
		cin >> command;
		print_board();
		switch (command)
		{
		case'x':	//�����̵�
			Box1[0].x1 += 1;
			Box1[0].x2 += 1;

			if (Box1[0].x1 > 30) {
				Box1[0].x1 = 1;
				Box1[0].x2 = Box1[0].x2 - 30;
			}
			system("cls");
			break;
		case'X':	//�����̵�
			Box1[0].x1 -= 1;
			Box1[0].x2 -= 1;

			if (Box1[0].x2 < 1) {
				Box1[0].x1 = 30 + Box1[0].x1;
				Box1[0].x2 = 30;
			}
			system("cls");
			break;
		case'y':	//�Ʒ����̵�
			Box1[0].y1 += 1;
			Box1[0].y2 += 1;

			if (Box1[0].y1 > 30) {
				Box1[0].y1 = 1;
				Box1[0].y2 = Box1[0].y2 - 30;
			}
			system("cls");
			break;
		case'Y':	//�����̵�
			Box1[0].y1 -= 1;
			Box1[0].y2 -= 1;

			if (Box1[0].y2 < 1) {
				Box1[0].y1 = 30 + Box1[0].y1;
				Box1[0].y2 = 30;
			}
			system("cls");
			break;
		case's':	//��ĭ ���
			if (Box1[0].x2 - Box1[0].x1 >= 1 && Box1[0].y2 - Box1[0].y1 >= 1) {
				Box1[0].x2 -= 1;
				Box1[0].y2 -= 1;
			}
			system("cls");
			break;
		case'S':	//��ĭ Ȯ��
			if (Box1[0].x2 - Box1[0].x1+1 < 30 && Box1[0].y2 - Box1[0].y1+1 < 30) {
				Box1[0].x2 += 1;
				Box1[0].y2 += 1;
			}
			system("cls");
			break;

		case'w':	// �� ��° ������ x�� ���� �� ĭ �̵�
			Box2[0].x1 += 1;
			Box2[0].x2 += 1;

			if (Box2[0].x1 > 30) {
				Box2[0].x1 = 1;
				Box2[0].x2 = Box2[0].x2 - 30;
			}
			system("cls");
			break;
		case'W':	// �� ��° ������ x�� ���� �� ĭ �̵�
			Box2[0].x1 -= 1;
			Box2[0].x2 -= 1;

			if (Box2[0].x2 < 1) {
				Box2[0].x1 = 30 + Box2[0].x1;
				Box2[0].x2 = 30;
			}
			system("cls");
			break;
		case'a':	//�� ��° ������ y�� �Ʒ��� �� ĭ �̵�
			Box2[0].y1 += 1;
			Box2[0].y2 += 1;

			if (Box2[0].y1 > 30) {
				Box2[0].y1 = 1;
				Box2[0].y2 = Box2[0].y2 - 30;
			}
			system("cls");
			break;
		case'A':	//�� ��° ������ y�� ���� �� ĭ �̵�
			//���ĳ��� �ø��� �ݴ����� �ȳ�Ÿ��..
			Box2[0].y1 -= 1;
			Box2[0].y2 -= 1;

			if (Box2[0].y2 < 1) {
				Box2[0].y1 = 30 + Box2[0].y1;
				Box2[0].y2 = 30;
			}
			system("cls");
			break;
		case'd':	// �� ��° ������ x�� y ��� �� ĭ ���
			if (Box2[0].x2 - Box2[0].x1 > 1 && Box2[0].y2 - Box2[0].y1 > 1) {
				Box2[0].x2 -= 1;
				Box2[0].y2 -= 1;
			}
			system("cls");
			break;
		case'D':	//: �� ��° ������ x�� y ��� �� ĭ Ȯ��
			if (Box2[0].x2 - Box2[0].x1+1 < 30 && Box2[0].y2 - Box2[0].y1+1 < 30) {
				Box2[0].x2 += 1;
				Box2[0].y2 += 1;
			}
			system("cls");
			break;
			break;
		case'r':	//�����ϰ� ��ǥ�� �ٽ� ����
		case'R':
			system("cls");
			fill(&board[0][0].ch, &board[29][30].ch, '*');
			fill_int();
			input_value(1, &Box1[0]);
			input_value(2, &Box2[0]);
			make_box(Box1);
			make_box(Box2);
			print_board();
			break;
		case'q':	//����
		case'Q':
			return;
			break;
		default:
			cout << "�ùٸ��� ���� ��ɾ� �Դϴ�." << endl;
			break;
		}
		fill(&board[0][0].ch, &board[29][30].ch, '*');
		fill_int();
		make_box(Box1);
		make_box(Box2);
		print_board();
	}
}
void fill_int() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			board[i][j].crash = 0;
		}
	}
}
void input_value(int num, BoxSize* Box) {
	cout << "input coord value " << num << ": ";
	cin >> Box->x1 >> Box->y1 >> Box->x2 >> Box->y2;
	while (Box->x1 > 30 || Box->x1 < 1 || Box->x2 > 30 || Box->x2 < 1 || Box->y1 > 30 || Box->y1 < 1 || Box->y2 < 1 || Box->y2 > 30) {
		cout << "1�̻�, 30 ������ ���� �ٽ� �Է��ϼ���: " << endl;
		cin >> Box->x1 >> Box->y1 >> Box->x2 >> Box->y2;
	}
}

void print_board(void) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			if (board[i][j].crash == 2) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << "# ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			else {
				cout << board[i][j].ch << " ";
			}
		}
		cout << endl;
	}
}

void draw_box(BoxSize Box) {

	for (int i = Box.x1 - 1; i < Box.x2; i++) {
		for (int j = Box.y1 - 1; j < Box.y2; j++) {
			board[j][i].ch = Box.sym;
			board[j][i].crash++;
		}
	}
}


void make_box(BoxSize Box[]) {

	Box[0].pr = false;
	Box[1].pr = false;
	Box[2].pr = false;
	Box[3].pr = false;
	Box[4].pr = false;

	if (Box[0].x1 >= 1 && Box[0].x2 <= 30 && Box[0].y1 >= 1 && Box[0].y2 <= 30) {
		Box[0].pr = true;
		Box[1].pr = false;
		Box[2].pr = false;
		Box[3].pr = false;
		Box[4].pr = false;
	}
	else if (Box[0].x1 <= 30 && Box[0].x2 > 30) {	//���������� �� ���
		Box[1].pr = true;
		Box[2].pr = true;

		Box[1].x1 = 1;
		Box[1].x2 = Box[0].x2 - 30;

		Box[2].x1 = Box[0].x1;
		Box[2].x2 = 30;

		if (Box[0].y1 >= 1 && Box[0].y2 <= 30) {

			Box[1].y1 = Box[0].y1;
			Box[1].y2 = Box[0].y2;

			Box[2].y1 = Box[0].y1;
			Box[2].y2 = Box[0].y2;

		}
		else {
			Box[3].pr = true;
			Box[4].pr = true;

			Box[3].x1 = 1;
			Box[3].x2 = Box[0].x2 - 30;

			Box[4].x1 = Box[0].x1;
			Box[4].x2 = 30;

			if (Box[0].y1 < 1) {

				Box[1].y1 = 1;
				Box[1].y2 = Box[0].y2;

				Box[2].y1 = 1;
				Box[2].y2 = Box[0].y2;

				Box[3].y1 = 30 - Box[0].y1;
				Box[3].y2 = Box[0].y2;

				Box[4].y1 = 30 - Box[0].y1;
				Box[4].y2 = Box[0].y2;
			}
			else if (Box[0].y2 > 30) {

				Box[1].y1 = Box[0].y1;
				Box[1].y2 = 30;

				Box[2].y1 = Box[0].y1;
				Box[2].y2 = 30;

				Box[3].y1 = 1;
				Box[3].y2 = Box[0].y2 - 30;

				Box[4].y1 = 1;
				Box[4].y2 = Box[0].y2 - 30;
			}
		}
	}
	else if (Box[0].x1 < 1 && Box[0].x2 >= 1) {	//�������� �� ���
		Box[1].pr = true;
		Box[2].pr = true;

		Box[1].x1 = 1;
		Box[1].x2 = Box[0].x2;

		Box[2].x1 = 30 + Box[0].x1;
		Box[2].x2 = 30;

		if (Box[0].y1 >= 1 && Box[0].y2 <= 30) {

			Box[1].y1 = Box[0].y1;
			Box[1].y2 = Box[0].y2;

			Box[2].y1 = Box[0].y1;
			Box[2].y2 = Box[0].y2;

		}
		else {
			Box[3].pr = true;
			Box[4].pr = true;

			Box[3].x1 = 1;
			Box[3].x2 = Box[0].x2;

			Box[4].x1 = 30 + Box[0].x1;
			Box[4].x2 = 30;

			if (Box[0].y1 < 1) {

				Box[1].y1 = 1;
				Box[1].y2 = Box[0].y2;

				Box[2].y1 = 1;
				Box[2].y2 = Box[0].y2;

				Box[3].y1 = 30 - Box[0].y1;
				Box[3].y2 = Box[0].y2;

				Box[4].y1 = 30 - Box[0].y1;
				Box[4].y2 = Box[0].y2;
			}
			else if (Box[0].y2 > 30) {

				Box[1].y1 = Box[0].y1;
				Box[1].y2 = 30;

				Box[2].y1 = Box[0].y1;
				Box[2].y2 = 30;

				Box[3].y1 = 1;
				Box[3].y2 = Box[0].y2 - 30;

				Box[4].y1 = 1;
				Box[4].y2 = Box[0].y2 - 30;
			}
		}
	}
	else {

		if (Box[0].x1 >= 1 && Box[0].x2 <= 30) {

			Box[1].x1 = Box[0].x1;
			Box[1].x2 = Box[0].x2;

			Box[2].x1 = Box[0].x1;
			Box[2].x2 = Box[0].x2;
		}
		if (Box[0].y1 < 1 && Box[0].y2 >= 1) {	//���� �� ���
			Box[1].pr = true;
			Box[2].pr = true;

			Box[1].y1 = 1;
			Box[1].y2 = Box[0].y2;

			Box[2].y1 = 30 + Box[0].y1;
			Box[2].y2 = 30;
		}
		else if (Box[0].y1 <= 30 && Box[0].y2 > 30) {	//�Ʒ��� �� ���
			Box[1].pr = true;
			Box[2].pr = true;

			Box[1].y1 = 1;
			Box[1].y2 = Box[0].y2 - 30;

			Box[2].y1 = Box[0].y1;
			Box[2].y2 = 30;

		}
	}
	for (int i = 0; i < 5; i++) {
		if (Box[i].pr) {
			draw_box(Box[i]);
		}
	}
}