#include <iostream>
#include <string>
#include <list>
#include <map>
using namespace std;

struct TreeNode {
	string name; //이름
	TreeNode *p; //노드를 가리키는 포인터 p
	list<TreeNode *> lp; //list를 가리키는 포인터 lp
	TreeNode() { p = NULL; };
};

map<string, TreeNode*> arr; //string이 key, list를 가리키는 포인터가 value 

void print(long depth, TreeNode *p) {
	if (p == NULL) //노드가 존재하지 않을 경우
	{
		return;
	}

	for (int i = 1; i <= depth; ++i)
	{
		cout << '+';
	}

	cout << p->name << "\n";

	for (auto it = p->lp.begin(); it != p->lp.end(); it++) { //depth 끝까지 출력
		print(depth + 1, *it);
	}
}

void fire(string s1) {
	TreeNode *lp = arr[s1]; //해당하는 s1 저장

	if (lp == nullptr) { //해당하는 string이 arr에 없을 경우

	}
	else //있으면
	{
		TreeNode *p = lp->p; //임시로 s1 저장
		arr.erase(s1); //arr에서 해당하면 삭제

		while (lp->lp.size() != 0) { //나머지 노드들을 이어줌
			lp->name = lp->lp.front()->name;
			arr[lp->name] = lp;
			lp = lp->lp.front();
		}

		lp->p->lp.remove(lp); //기존의 s1이 있는 노드 삭제
		delete lp;
	}
}

void hires(string n1, string n2) {
	TreeNode *p = arr[n1];
	if (p == nullptr) { //해당하는 string이 arr에 없을 경우

	}
	else //있으면
	{
		TreeNode *lp = new TreeNode(); //새로운 노드 생성
		lp->name = n2;
		lp->p = p;
		p->lp.push_back(lp);
		arr[n2] = lp;
	}
}

int main() {
	string s1, s2; //첫번째, 두번째 이후의 문자열
	TreeNode *root; 
	cin >> s1;

	root = new TreeNode(); //가장 첫번째 노드에 문자열 저장
	arr[s1] = root; 
	root->name = s1;

	while (cin >> s1)
	{
		if (s1 == "Print") { //Print 문자열 입력시
			cout << "--------------------------------------------------\n";
			print(0, root);
			cout << "--------------------------------------------------\n";
		}
		else if (s1 == "Fire") { //Fire 문자열 입력시
			cin >> s2;
			fire(s2);
		}
		else { //s1이 둘다 아닐 경우
			cin >> s2 >> s2;
			hires(s1, s2);
		}
	}

	return 0;
}