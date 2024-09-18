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
void Ascending(int counter);	//오름차순으로 정렬
void descending_order(int counter);	//내림차순으로 정렬

three_int list[20];
int ptr_t{};	//여기다 -1해야 리스트 맨 위 자료
//int ptr_nt{};	//20개 넘어갔을 때 리스트 맨 위 자료. new top
int total_l{};	//리스트에 들어간 총 자료 수
int pri_n{ 9 };	//리스트 프린트할 수. total_l 커지면 9에서 19로 변경
void main() {

	char command{};
	three_int num;
	int a_counter{};
	int s_counter{};

	while (1) {
		cout << "명령어를 입력하세요: " << endl;
		cin >> command;
		switch (command) {
		case'+':
			cout << "x,y,z값을 입력하세요: " << endl;
			cin >> num.x >> num.y >> num.z;
			//cout << num.x << num.y << num.z << endl;
			if (total_l >= 20) {	//if (total_l >= 20)
				cout << "더이상 추가할 수 없습니다." << endl;
				break;
			}
			add_top(num);
			total_l++;
			ptr_t++;
			break;
		case'-':	//-: 리스트의 맨 위에서 삭제한다.
			if (total_l > 0) {
				list[ptr_t - 1] = { 312312312,312312312,312312312 };
				total_l--;
				ptr_t--;
			}
			else {
				cout << "삭제할 데이터가 없습니다." << endl;
			}
			print_list();
			break;
		case'e':	//e x y z: 리스트의 맨 아래에 입력 (명령어 +와 반대의 위치, 리스트에 저장된 데이터값이 위로 올라간다.)
		case'E':
			cout << "x,y,z값을 입력하세요: " << endl;
			cin >> num.x >> num.y >> num.z;
			add_bottom(num);
			total_l++;
			ptr_t++;
			break;
		case'd':	//d: 리스트의 맨 아래에서 삭제한다. (리스트에서 삭제된 칸이 비어있다.)
		case'D':
			if (total_l > 0 && (list[0].x != 312312312 || list[0].y != 312312312 || list[0].z != 312312312)) {
				list[0] = { 312312312,312312312,312312312 };
				total_l--;
			}
			else {
				cout << "삭제할 데이터가 없습니다." << endl;
			}
			print_list();
			break;
		case'l':	//l: 리스트에 저장된 점의 개수를 출력한다.
		case'L':
			cout << "저장된 점의 개수: " << total_l << endl;
			break;
		case'c':	//c: 리스트를 비운다. 리스트를 비운 후 다시 입력하면 0번부터 저장된다
		case'C':
			cout << "리스트를 전부 비웠습니다." << endl;
			all_remove();
			break;
		case'm':	//m: 원점에서 가장 먼 거리에 있는 점의 좌표값을 출력한다.
		case'M':
			cout << "가장 먼 거리에 있는 점의 좌표: ";
			find_far_point();
			break;
		case'n':	//n: 원점에서 가장 가까운 거리에 있는 점의 좌표값을 출력한다
		case'N':
			cout << "가장 가까운 거리에 있는 점의 좌표: ";
			find_nearest_point();
			break;
		case'a':	//a: 원점과의 거리를 정렬하여 오름차순으로 정렬하여 출력한다. 인덱스 0번부터 빈 칸없이 저장하여 출력한다
		case'A':
			if (total_l > 0) {
			a_counter++;
			}
			cout << "원점과의 거리를 오름차순으로 정렬합니다." << endl;
			Ascending(a_counter);
			break;
		case's':	//s: 원점과의 거리를 정렬하여 내림차순으로 정렬하여 출력한다. (다시 a 또는 s를 누르면 원래의 인덱스 위치에 출력한다.)
		case'S':
			if (total_l > 0) {
				s_counter++;
			}
			cout << "원점과의 거리를 내림차순으로 정렬합니다." << endl;
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
		cout << "출력할 수 있는 점의 좌표가 없습니다." << endl;
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
		cout << "출력할 수 있는 점의 좌표가 없습니다." << endl;
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
		sort(list_s.begin(), list_s.end(), greater<pair<int, int>>());	//이것만 추가됨

		for (int i = pri_n; i >= 0; i--) {
			cout << i << " | ";
			if (i < total_l) {
				cout << list[list_s[i].second].x << ' ' << list[list_s[i].second].y << ' ' << list[list_s[i].second].z;

			}
			cout << endl;
		}
	}
}