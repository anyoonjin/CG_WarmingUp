#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct three_int {
	int x{ 312312312 };
	int y{ 312312312 };
	int z{ 312312312 };
};

void print_list(void);
void add_top(three_int num);
void add_bottom(three_int num);
void all_remove(void);
void find_far_point(void);
void find_nearest_point(void);
void Ascending(int counter);	//������������ ����
void descending_order(int counter);	//������������ ����

three_int list[20];
int ptr_t{};	//����� -1�ؾ� ����Ʈ �� �� �ڷ�
//int ptr_nt{};	//20�� �Ѿ�� �� ����Ʈ �� �� �ڷ�. new top
int total_l{};	//����Ʈ�� �� �� �ڷ� ��
int pri_n{ 9 };	//����Ʈ ����Ʈ�� ��. total_l Ŀ���� 9���� 19�� ����
void main() {

	char command{};
	three_int num;
	int a_counter{};
	int s_counter{};

	while (1) {
		cout << "��ɾ �Է��ϼ���: " << endl;
		cin >> command;
		switch (command) {
		case'+':
			cout << "x,y,z���� �Է��ϼ���: " << endl;
			cin >> num.x >> num.y >> num.z;
			//cout << num.x << num.y << num.z << endl;
			if (total_l >= 20) {	//if (total_l >= 20)
				cout << "���̻� �߰��� �� �����ϴ�." << endl;
				break;
			}
			add_top(num);
			total_l++;
			ptr_t++;
			break;
		case'-':	//-: ����Ʈ�� �� ������ �����Ѵ�.
			if (total_l > 0) {
				list[ptr_t - 1] = { 312312312,312312312,312312312 };
				total_l--;
				ptr_t--;
			}
			else {
				cout << "������ �����Ͱ� �����ϴ�." << endl;
			}
			print_list();
			break;
		case'e':	//e x y z: ����Ʈ�� �� �Ʒ��� �Է� (��ɾ� +�� �ݴ��� ��ġ, ����Ʈ�� ����� �����Ͱ��� ���� �ö󰣴�.)
		case'E':
			cout << "x,y,z���� �Է��ϼ���: " << endl;
			cin >> num.x >> num.y >> num.z;
			add_bottom(num);
			total_l++;
			ptr_t++;
			break;
		case'd':	//d: ����Ʈ�� �� �Ʒ����� �����Ѵ�. (����Ʈ���� ������ ĭ�� ����ִ�.)
		case'D':
			if (total_l > 0 && (list[0].x != 312312312 || list[0].y != 312312312 || list[0].z != 312312312)) {
				list[0] = { 312312312,312312312,312312312 };
				total_l--;
			}
			else {
				cout << "������ �����Ͱ� �����ϴ�." << endl;
			}
			print_list();
			break;
		case'l':	//l: ����Ʈ�� ����� ���� ������ ����Ѵ�.
		case'L':
			cout << "����� ���� ����: " << total_l << endl;
			break;
		case'c':	//c: ����Ʈ�� ����. ����Ʈ�� ��� �� �ٽ� �Է��ϸ� 0������ ����ȴ�
		case'C':
			cout << "����Ʈ�� ���� ������ϴ�." << endl;
			all_remove();
			break;
		case'm':	//m: �������� ���� �� �Ÿ��� �ִ� ���� ��ǥ���� ����Ѵ�.
		case'M':
			cout << "���� �� �Ÿ��� �ִ� ���� ��ǥ: ";
			find_far_point();
			break;
		case'n':	//n: �������� ���� ����� �Ÿ��� �ִ� ���� ��ǥ���� ����Ѵ�
		case'N':
			cout << "���� ����� �Ÿ��� �ִ� ���� ��ǥ: ";
			find_nearest_point();
			break;
		case'a':	//a: �������� �Ÿ��� �����Ͽ� ������������ �����Ͽ� ����Ѵ�. �ε��� 0������ �� ĭ���� �����Ͽ� ����Ѵ�
		case'A':
			if (total_l > 0) {
			a_counter++;
			}
			cout << "�������� �Ÿ��� ������������ �����մϴ�." << endl;
			Ascending(a_counter);
			break;
		case's':	//s: �������� �Ÿ��� �����Ͽ� ������������ �����Ͽ� ����Ѵ�. (�ٽ� a �Ǵ� s�� ������ ������ �ε��� ��ġ�� ����Ѵ�.)
		case'S':
			if (total_l > 0) {
				s_counter++;
			}
			cout << "�������� �Ÿ��� ������������ �����մϴ�." << endl;
			descending_order(s_counter);
			break;
		case'q':
		case'Q':
			return;
			break;
		}
		if (total_l >= 9) {
			pri_n = 19;
		}
		else{
			pri_n = 9;
		}
	}
}

void print_list(void) {
	for (int i = pri_n; i >= 0; i--) {
		cout << i << " | ";
		if (list[i].x != 312312312 || list[i].y != 312312312 || list[i].z != 312312312) {
			cout << list[i].x << ' ' << list[i].y << ' ' << list[i].z;
		}
		cout << endl;
	}
}
void add_top(three_int num) {
	if (total_l >= 19&& list[0].x == 312312312 && list[0].y == 312312312 && list[0].z == 312312312) {
		list[0] = num;
	}
	else if (list[ptr_t].x == 312312312 && list[ptr_t].y == 312312312 && list[ptr_t].z == 312312312) {
		list[ptr_t] = num;
	}
	print_list();
}

void add_bottom(three_int num) {
	if (list[0].x == 312312312 && list[0].y == 312312312 && list[0].z == 312312312) {
		list[0] = num;
	}
	else {
		for (int i = 18, j = 0; j < total_l || i >= 0; i--) {
			if (list[i].x != 312312312 || list[i].y != 312312312 || list[i].z != 312312312) {
				list[i + 1] = list[i];
				j++;
			}
		}
		list[0] = num;
	}
	print_list();
}
void all_remove(void) {
	if (total_l > 0) {
		for (int i = ptr_t - 1; i >= 0; i--) {

			list[i] = { 312312312,312312312,312312312 };
		}
		total_l = 0;
		ptr_t = 0;
	}
	return;
}

void find_far_point(void) {
	three_int best{ 0,0,0 };
	//three_int
	if (total_l == 0) {
		cout << "����� �� �ִ� ���� ��ǥ�� �����ϴ�." << endl;
		return;
	}
	for (int i = 0; i < ptr_t; i++) {
		if (list[i].x != 312312312 || list[i].y != 312312312 || list[i].z != 312312312) {
			if (list[i].x + list[i].y + list[i].z > best.x + best.y + best.z) {
				best = list[i];
			}
		}
	}
	for (int i = 0; i < ptr_t; i++) {
		if (list[i].x + list[i].y + list[i].z == best.x + best.y + best.z) {
			cout << "(" << list[i].x << "," << list[i].y << "," << list[i].z << ")";
		}
	}
	cout << endl;
}

void find_nearest_point(void) {
	three_int best = list[0];
	//three_int
	if (total_l == 0) {
		cout << "����� �� �ִ� ���� ��ǥ�� �����ϴ�." << endl;
		return;
	}
	for (int i = 0; i < ptr_t; i++) {
		if (list[i].x != 312312312 || list[i].y != 312312312 || list[i].z != 312312312) {
			if (list[i].x + list[i].y + list[i].z < best.x + best.y + best.z) {
				best = list[i];
			}
		}
	}
	for (int i = 0; i < ptr_t; i++) {
		if (list[i].x + list[i].y + list[i].z == best.x + best.y + best.z) {
			cout << "(" << list[i].x << "," << list[i].y << "," << list[i].z << ")";
		}
	}
	cout << endl;
}

void Ascending(int counter) {
	vector<pair<int,int>>list_s;
	if (counter % 2 == 0) {
		print_list();
	}
	else {
		for (int i = 0; i < ptr_t; i++) {
			if (list[i].x != 312312312 || list[i].y != 312312312 || list[i].z != 312312312) {
				list_s.push_back(make_pair(list[i].x + list[i].y + list[i].z,i));
			}
		}
		sort(list_s.begin(), list_s.end());

		for (int i = pri_n; i >= 0; i--) {
			cout << i << " | ";
			if (i<total_l) {
				cout << list[list_s[i].second].x << ' ' << list[list_s[i].second].y << ' ' << list[list_s[i].second].z;

			}
			cout << endl;
		}
	}
}

void descending_order(int counter) {
	vector<pair<int, int>>list_s;
	if (counter % 2 == 0) {
		print_list();
	}
	else {
		for (int i = 0; i < ptr_t; i++) {
			if (list[i].x != 312312312 || list[i].y != 312312312 || list[i].z != 312312312) {
				list_s.push_back(make_pair(list[i].x + list[i].y + list[i].z, i));
			}
		}
		sort(list_s.begin(), list_s.end(), greater<pair<int, int>>());	//�̰͸� �߰���

		for (int i = pri_n; i >= 0; i--) {
			cout << i << " | ";
			if (i < total_l) {
				cout << list[list_s[i].second].x << ' ' << list[list_s[i].second].y << ' ' << list[list_s[i].second].z;

			}
			cout << endl;
		}
	}
}