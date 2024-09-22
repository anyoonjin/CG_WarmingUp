#include <iostream>
//#include <algorithm>
//#include <vector>

using namespace std;

char board[30][30]{};

struct BoxSize {
	int x1;
	int y1;
	int x2;
	int y2;
	bool pr{ false };	//����Ʈ
};

BoxSize Box1{};
BoxSize Box2{};	//���� (���)
BoxSize Box3{};	//������ (���)
BoxSize Box4{};	//���� �ϴ�
BoxSize Box5{};	//������ �ϴ�

BoxSize* Boxes[5]{ &Box1 ,&Box2,&Box3,&Box4,&Box5 };

void print_board(void);
void draw_box(BoxSize Box);	//���� ���忡 �׸���
void make_box(void);	//���� ��ġ ���

void main() {
	fill(&board[0][0], &board[29][30], '*');

	char command{};
	float area{};

	cout << "input coord value: ";
	cin >> Box1.x1 >> Box1.y1 >> Box1.x2 >> Box1.y2;
	while (Box1.x1 > 30 || Box1.x1 < 1 || Box1.x2 > 30 || Box1.x2 < 1 || Box1.y1 > 30 || Box1.y1 < 1 || Box1.y2 < 1 || Box1.y2 > 30) {
		cout << "1�̻�, 30 ������ ���� �ٽ� �Է��ϼ���: " << endl;
		cin >> Box1.x1 >> Box1.y1 >> Box1.x2 >> Box1.y2;
	}
	draw_box(Box1);
	print_board();
	while (true) {
		
		cout << "input order: ";
		cin >> command;
		print_board();
		switch (command)
		{
		case'x':	//�����̵�
			Box1.x1 += 1;
			Box1.x2 += 1;

			if (Box1.x1 > 30) {
				Box1.x1 = 1;
				Box1.x2 = Box1.x2-30;
			}
			system("cls");
			break;
		case'X':	//�����̵�
			Box1.x1 -= 1;
			Box1.x2 -= 1;

			if (Box1.x2 < 1) {
				Box1.x1 = 30 + Box1.x1;
				Box1.x2 = 30;
			}
			system("cls");
			break;
		case'y':	//�Ʒ����̵�
			Box1.y1 += 1;
			Box1.y2 += 1;

			if (Box1.y1 > 30) {
				Box1.y1 = 1;
				Box1.y2 = Box1.y2 - 30;
			}
			system("cls");
			break;
		case'Y':	//�����̵�
			Box1.y1 -= 1;
			Box1.y2 -= 1;

			if (Box1.y2 < 1) {
				Box1.y1 = 30 + Box1.y1;
				Box1.y2 = 30;
			}
			system("cls");
			break;
		case's':	//��ĭ ���
			if (Box1.x2 - Box1.x1 >= 1 && Box1.y2 - Box1.y1 >= 1) {
				Box1.x2 -= 1;
				Box1.y2 -= 1;
			}
			system("cls");
			break;
		case'S':	//��ĭ Ȯ��
			if (Box1.x2 - Box1.x1 <= 30 && Box1.y2 - Box1.y1 <= 30) {
				Box1.x2 += 1;
				Box1.y2 += 1;
			}
			system("cls");
			break;
		case'i':	//x�� �� ĭ Ȯ��
			if (Box1.x2 - Box1.x1 <= 30 ) {
				Box1.x2 += 1;
			}
			system("cls");
			break;
		case'I':	//x�� �� ĭ ���
			if (Box1.x2 - Box1.x1 >= 1) {
				Box1.x2 -= 1;
			}
			system("cls");
			break;
		case'j':	//y�� �� ĭ Ȯ��
			if (Box1.y2 - Box1.y1 <= 30) {
				Box1.y2 += 1;
			}
			system("cls");
			break;
		case'J':	//y�� �� ĭ ���
			if (Box1.y2 - Box1.y1 >= 1) {
				Box1.y2 -= 1;
			}
			system("cls");
			break;
		case'a':	//x�� �� ĭ Ȯ��,y�� �� ĭ ���
			if (Box1.x2 - Box1.x1 <= 30&& Box1.y2 - Box1.y1 >= 1) {
				Box1.x2 += 1;
				Box1.y2 -= 1;
			}
			system("cls");
			break;
		case'A':	//x�� �� ĭ ���,y�� �� ĭ Ȯ��
			if (Box1.x2 - Box1.x1 >= 1&& Box1.y2 - Box1.y1 <= 30) {
				Box1.x2 -= 1;
				Box1.y2 += 1;
			}
			system("cls");
			break;
		case'm':	//�簢���� ���� ���
		case'M':
			system("cls");
			area = (Box1.x2 - Box1.x1 + 1) * (Box1.y2 - Box1.y1 + 1);
			cout << "����: " << Box1.x2 - Box1.x1 + 1 << " x " << Box1.y2 - Box1.y1 + 1 << " = " << area << endl;
			break;
		case'n':	//��ü ������ ���� ������ ���� ���� ���
		case'N':
			system("cls");
			area = (Box1.x2 - Box1.x1 + 1) * (Box1.y2 - Box1.y1 + 1);
			cout << "��ü ����: 30 x 30 = 900		�簢�� ����: " << area << "		���� ����: (" << area << "/900)*100= " << (area / 900.f) * 100.f << "%" << endl;
			break;
		case'r':	//�����ϰ� ��ǥ�� �ٽ� ����
		case'R':
			system("cls");
			cout << "input coord value: ";
			cin >> Box1.x1 >> Box1.y1 >> Box1.x2 >> Box1.y2;
			while (Box1.x1 > 30 || Box1.x1 < 1 || Box1.x2 > 30 || Box1.x2 < 1 || Box1.y1 > 30 || Box1.y1 < 1 || Box1.y2 < 1 || Box1.y2 > 30) {
				cout << "1�̻�, 30 ������ ���� �ٽ� �Է��ϼ���: " << endl;
				cin >> Box1.x1 >> Box1.y1 >> Box1.x2 >> Box1.y2;
			}
			draw_box(Box1);
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
		make_box();
		print_board();
	}
}

void print_board(void) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

void draw_box(BoxSize Box) {
	//fill(&board[0][0], &board[29][30], '*');

	for (int i = 0; i < Box.y2 - Box.y1 + 1; i++) {
		fill(&board[i + Box.y1 - 1][Box.x1 - 1], &board[i + Box.y1 - 1][Box.x2], '@');
	}
}

void make_box(void) {

	Box1.pr = false;
	Box2.pr = false;
	Box3.pr = false;
	Box4.pr = false;
	Box5.pr = false;

	if (Box1.x1 >= 1 && Box1.x2 <= 30 && Box1.y1 >= 1 && Box1.y2 <= 30) {
		Box1.pr = true;
		Box2.pr = false;
		Box3.pr = false;
		Box4.pr = false;
		Box5.pr = false;
	}
	else if (Box1.x1 <= 30 && Box1.x2 > 30) {	//���������� �� ���
		Box2.pr = true;
		Box3.pr = true;

		Box2.x1 = 1;
		Box2.x2 = Box1.x2 - 30;

		Box3.x1 = Box1.x1;
		Box3.x2 = 30;

		if (Box1.y1 >= 1 && Box1.y2 <= 30) {

			Box2.y1 = Box1.y1;
			Box2.y2 = Box1.y2;

			Box3.y1 = Box1.y1;
			Box3.y2 = Box1.y2;

		}
		else {
			Box4.pr = true;
			Box5.pr = true;

			Box4.x1 = 1;
			Box4.x2 = Box1.x2 - 30;

			Box5.x1 = Box1.x1;
			Box5.x2 = 30;

			if (Box1.y1 < 1) {

				Box2.y1 = 1;
				Box2.y2 = Box1.y2;

				Box3.y1 = 1;
				Box3.y2 = Box1.y2;

				Box4.y1 = 30 - Box1.y1;
				Box4.y2 = Box1.y2;

				Box5.y1 = 30 - Box1.y1;
				Box5.y2 = Box1.y2;
			}
			else if (Box1.y2 > 30) {

				Box2.y1 = Box1.y1;
				Box2.y2 = 30;

				Box3.y1 = Box1.y1;
				Box3.y2 = 30;

				Box4.y1 = 1;
				Box4.y2 = Box1.y2 - 30;

				Box5.y1 = 1;
				Box5.y2 = Box1.y2 - 30;
			}
		}
	}
	else if (Box1.x1 < 1 && Box1.x2 >= 1) {	//�������� �� ���
		Box2.pr = true;
		Box3.pr = true;

		Box2.x1 = 1;
		Box2.x2 = Box1.x2;

		Box3.x1 = 30 + Box1.x1;
		Box3.x2 = 30;

		if (Box1.y1 >= 1 && Box1.y2 <= 30) {

			Box2.y1 = Box1.y1;
			Box2.y2 = Box1.y2;

			Box3.y1 = Box1.y1;
			Box3.y2 = Box1.y2;

		}
		else {
			Box4.pr = true;
			Box5.pr = true;

			Box4.x1 = 1;
			Box4.x2 = Box1.x2;

			Box5.x1 = 30 + Box1.x1;
			Box5.x2 = 30;

			if (Box1.y1 < 1) {

				Box2.y1 = 1;
				Box2.y2 = Box1.y2;

				Box3.y1 = 1;
				Box3.y2 = Box1.y2;

				Box4.y1 = 30 - Box1.y1;
				Box4.y2 = Box1.y2;

				Box5.y1 = 30 - Box1.y1;
				Box5.y2 = Box1.y2;
			}
			else if (Box1.y2 > 30) {

				Box2.y1 = Box1.y1;
				Box2.y2 = 30;

				Box3.y1 = Box1.y1;
				Box3.y2 = 30;

				Box4.y1 = 1;
				Box4.y2 = Box1.y2 - 30;

				Box5.y1 = 1;
				Box5.y2 = Box1.y2 - 30;
			}
		}
	}
	else {

		if (Box1.x1 >= 1 && Box1.x2 <= 30) {

			Box2.x1 = Box1.x1;
			Box2.x2 = Box1.x2;

			Box3.x1 = Box1.x1;
			Box3.x2 = Box1.x2;
		}
		if (Box1.y1 < 1 && Box1.y2 >= 1) {	//���� �� ���
			Box2.pr = true;
			Box3.pr = true;

			Box2.y1 = 1;
			Box2.y2 = Box1.y2;

			Box3.y1 = 30 + Box1.y1;
			Box3.y2 = 30;
		}
		else if (Box1.y1 <= 30 && Box1.y2 > 30) {	//�Ʒ��� �� ���
			Box2.pr = true;
			Box3.pr = true;

			Box2.y1 = 1;
			Box2.y2 = Box1.y2 - 30;

			Box3.y1 = Box1.y1;
			Box3.y2 = 30;

		}
	}
	fill(&board[0][0], &board[29][30], '*');

	for (int i = 0; i < 5; i++) {
		if (Boxes[i]->pr) {
			draw_box(*Boxes[i]);
		}
	}
}