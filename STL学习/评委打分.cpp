#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
//5名选手，10个人打分，去最高最低，取平均
class Person {
public:

	Person(string name, int sorce) {
		this->m_name = name;
		this->m_sorce = sorce;
	}

	string m_name;
	int m_sorce;
};

void creatperson(vector<Person>& v) {
	
	string nameseed = "abcde";
	
	for (int i = 0; i < 5; i++) {
		string name = "选手";
		name += nameseed[i];

		int sorce = 0;
		Person p(name, sorce);
		v.push_back(p);
	}
}

void setscore(vector<Person>&v) {

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//将评委的分数放入deque容器
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;//60到100
			d.push_back(score);
		}
		cout << "选手:" << it->m_name << "打分为:" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			cout << *dit << " ";
		}
		cout << endl;
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end();dit++) {
			sum += *dit;
		}
		int avg = sum / d.size();
		it->m_sorce = avg;

		cout << "选手:" << it->m_name << "平均分为:" << it->m_sorce<<endl;
		
	}

}

int main() {

	//1创建5名选手
	vector<Person>v;//存放选手的容器
	creatperson(v);
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名" << it->m_name << "分数:" << it->m_sorce << endl;
	}


	setscore(v);



	system("pause");
	return 0;
}