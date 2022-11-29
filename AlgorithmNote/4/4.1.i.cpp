#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct Student{
	int score;
	char name[8];
} Student;

bool cmpStudent(Student a, Student b);

int main(){
	while(true){
		int amount_of_student;
		int amount_of_question;
		int score_line;
		cin >> amount_of_student;
		if(amount_of_student == 0) break;
		cin >> amount_of_question >> score_line;
		
		int score_list[amount_of_question];
		for(int i = 0; i < amount_of_question; i++) cin >> score_list[i];

		Student stu[amount_of_student];
		Student stu_certified[amount_of_student];
		int certified = 0;
		for(int i = 0; i < amount_of_student; i++){
			cin >> stu[i].name;
			int amount_of_completed;
			cin >> amount_of_completed;
			for(int j = 0; j < amount_of_completed; j++){
				int id_of_ques;
				cin >> id_of_ques;
				stu[i].score += score_list[id_of_ques - 1];
			}
//			cout << "\n---" << stu[i].score << "---\n";
			if(stu[i].score >= score_line) stu_certified[certified++] = stu[i];
		}
		
		sort(stu_certified, stu_certified + certified, cmpStudent);
		for(int i = 0; i < certified; i++){
			cout << stu_certified[i].name << " " << stu_certified[i].score << "\n";
		}
	}
}

bool cmpStudent(Student a, Student b){
	if(a.score != b.score) return (a.score > b.score);
	else return strcmp(b.name, a.name);
}
