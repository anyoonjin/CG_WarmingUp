#include <iostream>
#include <fstream>		//파일 입출력
#include <vector>		//vector
#include <string>		//string
#include <sstream>		//stringstream<공백에 따라 쪼개기
#include <algorithm>	//sort쓰려고
#include <windows.h>	//
#include <cctype>		//toupper쓰려고


using namespace std;

void print_sentences(void);
void Alignment_of_sentences(int r_counter);		//문장정렬
void search_big(int c_counter);
void word_reverse_print(int f_counter);			//공백기준 단어들 거꾸로 출력하기
void line_reverse_print(int d_counter);			//문장 한 줄 거꾸로 출력하기
void insert_Symbol(int e_counter);				//3문자 후 @@ 삽입
void change_char(int g_counter, char ch_str, char new_str);
void find_word(string f_str);
string to_uppercase(string str);	//문자열 대문자로 바꿔주는 함수

vector<string> file_line[10];

int main() {
	string file_name;
	ifstream readFile;

	char command{};
	int r_counter{};	//이거 나중에 뭐 어케 잘 하면 좋을듯...^^
	int c_counter{};
	int f_counter{};
	int d_counter{};
	int e_counter{};
	int g_counter{};

	cout << "파일 이름을 입력하세요." << endl;
	cin >> file_name;

	readFile.open(file_name);
	if (readFile.is_open())
	{
		int line_counter{};
		// << "성공";
		while (!readFile.eof()) {
			string str_line;
			string str_word;
			getline(readFile, str_line);	//한 줄 받기
			cout << str_line << endl;
			stringstream ss(str_line);	//공백에 따라 쪼개기
			while (ss >> str_word) {
				file_line[line_counter].push_back(str_word);//vector쓸 땐 =이렇게 대입이 아니라 ()이렇게 함수에 넣어줘야함
			}
			line_counter++;
		}
		//cout << file_line[0].size() << endl;


		while (true) {	//숫자 될 수 있으면 적지 말기.. 매직넘버,,
			cout << endl << "명령어를 입력하세요: " << endl;
			cin >> command;
			switch (command) {
			case 'c':	// c: 대문자로 시작되는 단어 다른 색으로 출력하고, 몇 개 있는지 출력. 다시 누르면 원래대로 출력
			case 'C':
				c_counter++;
				search_big(c_counter);
				break;
			case 'd':	// d: 문장 한 줄 전체를 거꾸로 출력. 다시 누르면 원래대로 출력.
			case 'D':
				d_counter++;
				line_reverse_print(d_counter);
				break;
			case 'e':
			case 'E':	// e: 3문자 후 2개의 @ 문자 삽입. 다시 누르면 원래대로 출력
				e_counter++;
				insert_Symbol(e_counter);
				break;
			case 'f':	// f: 공백을 기준으로 모든 단어들을 거꾸로 출력. 다시 누르면 원래대로 출력
			case 'F':
				f_counter++;
				word_reverse_print(f_counter);
				break;
			case 'g':	// g: 문자 내부의 특정 문자를 다른 문자로 바꾸기 (바꿀 문자와 새롭게 입력할 문자 입력 받음) 다시 누르면 원래대로 출력
			case 'G': {
				g_counter++;
				char change_str, new_str;
				if (g_counter % 2 == 1) {
					cout << "바꿀 문자를 입력하세요: " << endl;
					cin >> change_str;
					cout << "새로 입력할 문자를 입력하세요: " << endl;
					cin >> new_str;

					change_char(g_counter, change_str, new_str);
				}
				else {
					print_sentences();
				}
			}
					break;
			case 'h':	// h: 각 줄의 단어의 개수를 출력
			case 'H':
				for (int i = 0; i < 10; i++) {
					cout << i + 1 << "번째 줄 단어 개수: " << file_line[i].size() << endl;
				}
				break;
			case 'r':	// r: 한 문장의 단어의 개수에 따라 오름차순 → 내림차순 → 원래대로 → 오름차순...
			case 'R':
				r_counter++;
				Alignment_of_sentences(r_counter);
				break;
			case 's':	// s: 명령어와 단어를 입력하면, 입력받은 문장들을 모두 출력하면서 그 단어를 찾아 다른 색으로 출력하고, 몇 개 있는지를 계산하여 출력(대소문자 구분하지 않는다)
			case 'S':
			{
				string f_str;
				cout << "찾을 단어를 입력하세요: " << endl;
				cin >> f_str;
				find_word(f_str);
			}
				break;
			case 'q':
			case 'Q':
				readFile.close();
				return 0;
				break;
			default:
				break;
			}
		}
	}
	else {
		cout << "파일 읽기 실패!";
	}
	readFile.close();
}

/*
			//string str_line;
			string str_word;
			//getline(readFile, str_line);	//,
			getline(readFile, str_word, ' ');	//,
			//readFile >> str_word;		//이렇게 하면 전부 단어별로 저장됨.
			//file_line[line_counter].push_back(str_word) ;
			cout << str_word << endl;

			if (str_word.back() == '\n') {		//back() 문자열의 마지막 문자를 반환함
				str_word.pop_back();//마지막 문자 제거. \n제거 용도
				file_line[line_counter].push_back(str_word);//vector쓸 땐 =이렇게 대입이 아니라 ()이렇게 함수에 넣어줘야함
				line_counter++;
			}
			else if (str_word.front() == '\n') {
				str_word = str_word.substr(1);  //pop같은 함수가 없어서 수동으로. substr(1) 첫 번째 문자 제외한 부분 반환
				line_counter++;
				file_line[line_counter].push_back(str_word);//vector쓸 땐 =이렇게 대입이 아니라 ()이렇게 함수에 넣어줘야함
			}
			else {
				file_line[line_counter].push_back(str_word);
			}

*/

string to_uppercase(string str) {
	string result = str;
	for (int i = 0; i < str.size(); i++) {
		result[i] = toupper(str[i]);
	}
	return result;
}

void print_sentences(void) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < file_line[i].size(); j++) {
			cout << file_line[i][j] << ' ';
		}
		cout << endl;
	}
}

void Alignment_of_sentences(int r_counter) {
	//int word_c[10][2]{};
	vector<pair<int, int>> word_c;
	vector<string> f_asc[10];	//오름차순
	vector<string> f_des[10];	//내림차순

	if (r_counter % 3 == 0) {	//원래대로 출력
		cout << "문장을 원래대로 출력합니다." << endl;
		print_sentences();
		return;
	}
	for (int i = 0; i < 10; i++) {
		//word_c[i][0] = file_line[i].size();		//단어 수
		//word_c[i][1] = i;		//라인 넘버			//이중배열은sort못 써서 vector씀
		word_c.push_back(make_pair(file_line[i].size(), i));
	}
	if (r_counter % 3 == 1) {	//오름차순으로 정렬
		int num{};
		sort(word_c.begin(), word_c.end());
		for (int j = 0; j < 10; j++) {
			num = word_c[j].second;		//오름차순으로 정렬된 행 번호	 /바로 넣어도 ㄱㅊ지만 내가 보기 편하라고,,
			for (int k = 0; k < file_line[num].size(); k++) {
				f_asc[j].push_back(file_line[num][k]);
			}
		}
		cout << "문장을 단어의 개수에 따라 오름차순으로 출력합니다." << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < f_asc[i].size(); j++) {
				cout << f_asc[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else {		//내림차순으로 정렬
		int num{};
		sort(word_c.begin(), word_c.end(), greater<pair<int, int>>());
		/*	for (int i = 0; i < 10; i++) {
				cout << word_c[i].first << ' ' << word_c[i].second << endl;
			}*/
		cout << "문장을 단어의 개수에 따라 내림차순으로 출력합니다." << endl;
		for (int j = 0; j < 10; j++) {
			num = word_c[j].second;		//오름차순으로 정렬된 행 번호	 /바로 넣어도 ㄱㅊ지만 내가 보기 편하라고,,
			for (int k = 0; k < file_line[num].size(); k++) {
				f_des[j].push_back(file_line[num][k]);
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < f_des[i].size(); j++) {
				cout << f_des[i][j] << ' ';
			}
			cout << endl;
		}
	}
}
//성공하긴 했지만 하나만 만들고 역순으로 출력하는 게 낫겠단 생각...

void search_big(int c_counter) {
	int num{};

	if (c_counter % 2 == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < file_line[i].size(); j++) {
				if (isupper(file_line[i][j][0])) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					cout << file_line[i][j] << " ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					num++;
				}
				else {
					cout << file_line[i][j] << " ";
				}
			}
			cout << endl;
		}
		cout << "대문자로 시작되는 단어의 개수: " << num << endl;
	}
	else {
		cout << "원래대로 출력합니다." << endl;
		print_sentences();
	}
}

void word_reverse_print(int f_counter) {
	if (f_counter % 2 == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < file_line[i].size(); j++) {
				for (int k = file_line[i][j].size() - 1; k >= 0; k--) {
					cout << file_line[i][j][k];
				}
				cout << " ";
			}
			cout << endl;
		}
	}
	else {
		print_sentences();
	}
}

void line_reverse_print(int d_counter) {
	if (d_counter % 2 == 1) {
		for (int i = 0; i < 10; i++) {
			for (int j = file_line[i].size() - 1; j >= 0; j--) {
				for (int k = file_line[i][j].size() - 1; k >= 0; k--) {
					cout << file_line[i][j][k];
				}
				cout << " ";
			}
			cout << endl;
		}
	}
	else {
		print_sentences();
	}
}

void insert_Symbol(int e_counter) {
	int num{};
	if (e_counter % 2 == 1) {
		for (int i = 0; i < 10; i++) {
		num = 0;
			for (int j = 0; j < file_line[i].size(); j++) {
				for (int k = 0; k < file_line[i][j].size(); k++) {
					cout << file_line[i][j][k];
					num++;
					if (num == 3) {
						num = 0;
						cout << "@@";
					}
				}
				cout << " ";
				num++;
				if (num == 3) {
					num = 0;
					cout << "@@";
				}
			}
			cout << endl;
		}
	}
	else {
		print_sentences();
	}
}

void change_char(int g_counter, char ch_str, char new_str) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < file_line[i].size(); j++) {
			for (int k = 0; k < file_line[i][j].size(); k++) {
				if (ch_str == file_line[i][j][k]) {
					cout << new_str;
				}
				else {
					cout << file_line[i][j][k];
				}
			}
			cout << " ";
		}
		cout << endl;
	}
}

void find_word(string f_str) {
	int num{};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < file_line[i].size(); j++) {
			if (to_uppercase(f_str) == to_uppercase(file_line[i][j])) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << file_line[i][j] << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
				num++;
			}
			else {
				cout << file_line[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << "단어의 총 개수: " << num << endl;
}