#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<deque>
#include<algorithm>
//5��ѡ�֣�10���˴�֣�ȥ�����ͣ�ȡƽ��
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
		string name = "ѡ��";
		name += nameseed[i];

		int sorce = 0;
		Person p(name, sorce);
		v.push_back(p);
	}
}

void setscore(vector<Person>&v) {

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		//����ί�ķ�������deque����
		deque<int>d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;//60��100
			d.push_back(score);
		}
		cout << "ѡ��:" << it->m_name << "���Ϊ:" << endl;
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

		cout << "ѡ��:" << it->m_name << "ƽ����Ϊ:" << it->m_sorce<<endl;
		
	}

}

int main() {

	//1����5��ѡ��
	vector<Person>v;//���ѡ�ֵ�����
	creatperson(v);
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "����" << it->m_name << "����:" << it->m_sorce << endl;
	}


	setscore(v);



	system("pause");
	return 0;
}