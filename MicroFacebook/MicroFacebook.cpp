//2013112136 컴퓨터공학과 원동주
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

void displayMenu()
{
	cout << "P: Create a person record of the specified name" << '\n'; 
	cout << "F: Record that the two specified people are friends" << '\n'; //ok
	cout << "U: Record that the two specified people are no longer friends" << '\n'; 
	cout << "L: Print out the friends of the specified person" << '\n'; //ok
	cout << "Q: Check whether the two people are friends" << '\n'; //ok
	cout << "X: terminate the program" << '\n'; //ok
}

int main() {
	vector <string> v; //person을 저장할 vector v
	vector<pair<string, string>> p; //person끼리 친구 관계를 저장할 vector p
	vector <string>::iterator iter_v; //v의 반복자
	vector<pair<string, string>>::iterator iter_p; //p의 반복자
	string testData, testData2; //person 입력값 
	char cmd;
	bool flag = false; //친구인지 아닌지 판별한 flag

	do
	{
		flag = false;

		displayMenu();                     // Output list

		cout << endl << "Command: ";                  // Read command
		cin >> cmd;
		if (cmd == 'P' || cmd == 'L')
			cin >> testData;
		else if (cmd == 'F' || cmd == 'U' || cmd == 'Q')
			cin >> testData >> testData2;

		switch (cmd)
		{
			case 'P':
				v.push_back(testData); //v 벡터에 person 저장
				break;

			case 'F':             
				iter_v = find(v.begin(), v.end(), testData); //v 벡터에 person1이 있는지 검색
				if(iter_v == v.end()){ 
					cout << "Person is missed" << '\n';
					break;
				}

				iter_v = find(v.begin(), v.end(), testData2); //v 벡터에 person2이 있는지 검색
				if (iter_v == v.end()) {
					cout << "Person is missed" << '\n';
					break;
				}

				p.push_back(pair<string, string>(testData, testData2)); //둘 다 있을 경우 p 벡터에 pair로 저장
				break;

			case 'U':                               
				for (iter_p = p.begin(); iter_p != p.end(); iter_p++) { 
					if (iter_p->first == testData && iter_p->second == testData2) { //p 벡터에 두 person이 pair로 존재할시, p 벡터에서 삭제
						iter_p = p.erase(iter_p);									//p1,p2로 입력시 삭제
						break;
					}

					if (iter_p->second == testData && iter_p->first == testData2) { //p2,p1으로 입력시 삭제
						iter_p = p.erase(iter_p);
						break;
					}
				}
				break;

			case 'L':                                
				for (iter_p = p.begin(); iter_p != p.end(); iter_p++) { //p 벡터에서 p1이랑 pair인 값들 모두 출력
					if (iter_p->first == testData) {
						cout << iter_p->second << " ";
					}
					if (iter_p->second == testData) {
						cout << iter_p->first << " ";
					}
				}
				cout << '\n';
				break;
	
			case 'Q':
				for (iter_p = p.begin(); iter_p != p.end(); iter_p++) { 
					if (iter_p->first == testData && iter_p->second == testData2) {  //p 벡터에서 p1,p2가 친구로 존재시 yes 출력
						cout << "Yes" << '\n';
						flag = true; //flag 값 true로 저장
						break;
					}

					if (iter_p->first == testData2 && iter_p->second == testData) { //p 벡터에서 p2,p1이 친구로 존재시 yes 출력
						cout << "Yes" << '\n';
						flag = true;
						break;
					}
				}
			
				if (flag == false) { //아무것도 발견 못했을 시
					cout << "No" << '\n';
				}
				break;

			case 'X':                   // Quit test program
				break;

			default:                               // Invalid command
				cout << "Inactive or invalid command" << endl;
				break;
		}
	} while (cmd != 'X');
}
