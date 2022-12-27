#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student {
	int valid;
	int score;
	char name[22];
	char id[12];
} stu;

int AMOUNT = 0;
stu* arr;
int toExit = 0;

int inputNumber(int rangeFrom, int rangeTo, char* tips, char* error, int place);
void inputString(int size, char* tips, char* error, int place, char* location);
int* find_core(int mode, char* id, char* name);
void display(int fromNo, int endNo, int hasTitle, int space);
void find();
void add();
void change();
void del();
void browse();
void sort();
void stats();
void exitfunc();
int cmpID(const void* a, const void* b);
int cmpName(const void* a, const void* b);
int cmpScore1(const void* a, const void* b);
int cmpScore2(const void* a, const void* b);
int save();

int main() {
	//Initialize
	arr = (stu*)malloc(sizeof(stu) * 50000);
	printf("- Loading ...\n");
	FILE* dat = fopen("data.txt", "r");
	if (dat) {
		printf("- Database detected ...\n");
		while (!feof(dat)) {
			arr[AMOUNT].valid = 1;
			fscanf(dat, "%s", arr[AMOUNT].id);
			fscanf(dat, "%s", arr[AMOUNT].name);
			fscanf(dat, "%d", &arr[AMOUNT].score);
			AMOUNT++;
		}
		//system("cls");
		printf("- %d data found\n\n", AMOUNT);
	}
	else {
		printf("! Error: Cannot find the database \"dat.txt\" \n");
		printf("! Program Abort");
		return -1;
	}
	fclose(dat);

	//Menu
	while (1) {
		printf("- Welcome to Student Information Management System\n");
		printf("- Menu:\n");
		printf("      1 Add  2 Change  3 Delete  4 Browse  5 Find  6 Sort  7 Stats  8 Exit\n");
		char* menuTips = "- Please enter a number to continue: ";
		char* menuError = "! Error: Wrong number detected. Please enter again.\n";
		int opera = inputNumber(1, 8, menuTips, menuError, 2);
		switch (opera) {
		case 1:
			add(arr);
			break;
		case 2:
			change();
			break;
		case 3:
			del();
			break;
		case 4:
			browse();
			break;
		case 5:
			find();
			break;
		case 6:
			sort();
			break;
		case 7:
			stats();
			break;
		case 8:
			exitfunc();
			break;
		}
		if (toExit) {
			break;
		}
	}
	save();
	printf("- Changes saved.\n");
	printf("- Press SPACE to exit");
	getchar();
	getchar();
	return 0;
}

int inputNumber(int rangeFrom, int rangeTo, char* tips, char* error, int place) {
	int num;
	while (1) {
		printf("%s", tips);
		printf(" (%d to %d)\n", rangeFrom, rangeTo);
		for (int i = 0; i < place; i++) printf(" ");
		scanf("%d", &num);
		if (num >= rangeFrom && num <= rangeTo) {
			break;
		} else {
			printf("%s", error);
		}
	}
	return num;
}

void inputString(int size, char *tips, char* error, int place, char* location) {
	char temp[500];
	while (1) {
		printf("%s", tips);
		printf(" (length <= %d)\n", size);
		for (int i = 0; i < place; i++) printf(" ");
		scanf("%s", temp);
		if (strlen(temp) <= size) {
			break;
		} else {
			printf("%s", error);
		}
	}
	strcpy(location, temp);
}

void add() {
	//system("cls");
	printf("\n\n- Add:\n");
	printf("  Function Add helps you to create new entries.\n  New entries will be placed in at the end.\n");
	char* add1 = "- Please enter the amount of data you want to add: ";
	char* add2 = "! Error: Wrong number detected. Please enter again.\n";
	int sum = inputNumber(1, 49999 - AMOUNT, add1, add2, 2);
	printf("- Now please enter the data\n");
	for (int i = 1; i <= sum; i++) {
		printf("- Student %d:\n", i);
		inputString(10, "  ID:", "  ! Error: Wrong string detected. Please enter again.\n", 4, &arr[AMOUNT].id);
		inputString(20, "  Name:", "  ! Error: Wrong string detected. Please enter again.\n", 4, &arr[AMOUNT].name);
		arr[AMOUNT].score = inputNumber(0, 150, "  Score:", "  ! Error: Wrong number detected. Please enter again.\n", 4);
		arr[AMOUNT].valid = 1;
		AMOUNT ++;
	}
	save();
	printf("- Changes saved\n\n\n");
}

void change() {
	printf("\n\n- Change:\n");
	printf("  Function Change helps you to modify the data of the exist entries.\n");
	int* ret = NULL;
	while (1) {
		char id[22];
		inputString(10, "- Please enter the ID of the student:", "! Error: Wrong string detected. Please enter again.\n", 2, id);
		ret = find_core(1, id, "");
		if (ret[0] != -1) {
			break;
		}
		else {
			printf("! Error: Cannot find the student. Please try again.\n");
		}
	}
	printf("- The original data:\n");
	display(ret[0], ret[0], 1, 2);
	printf("\n- Enter new data:\n");
	inputString(10, "  ID:", "  ! Error: Wrong string detected. Please enter again.\n", 4, &arr[ret[0]].id);
	inputString(20, "  Name:", "  ! Error: Wrong string detected. Please enter again.\n", 4, &arr[ret[0]].name);
	arr[ret[0]].score = inputNumber(0, 150, "  Score:", "  ! Error: Wrong number detected. Please enter again.\n", 4);
	save();
	free(ret);
	printf("- Changes saved\n\n\n");
}

int save() {
	FILE* sav = fopen("data.txt", "w");
	for (int i = 0; i < AMOUNT; i++) {
		if (arr[i].valid) {
			fprintf(sav, "%s ", arr[i].id);
			fprintf(sav, "%s ", arr[i].name);
			fprintf(sav, "%d", arr[i].score);
			if (i != AMOUNT - 1) fprintf(sav, " ");
		}
	}
	fclose(sav);
	return 1;
}

void del() {
	printf("\n\n- Delete:\n");
	printf("  Function delete helps you to delete an entry.\n");
	char* add1 = "- Please enter the amount of data you want to delete: ";
	char* add2 = "! Error: Wrong number detected. Please enter again.\n";
	int sum = inputNumber(1, AMOUNT, add1, add2, 2);
	printf("- Now please delete the data\n");
	for (int i = 1; i <= sum; i++) {
		printf("- Student %d:\n", i);
		char temp[21];
		int loc;
		while (1) {
			inputString(10, "  ID: ", "  ! Error: Wrong ID detected. Please enter again.\n", 4, temp);
			loc = find_core(1, temp, "");
			if (loc != -1) {
				break;
			} else {
				printf("  ! Error: Cannot find a student match to the ID. Please try again.\n");
			}
		}
		arr[loc].valid = 0;
	}
	save();
	AMOUNT -= sum;
	printf("- Changes saved\n\n\n");
}

void find() {
	printf("\n\n- Find:\n");
	printf("  Function Find helps you to find a student with its ID or name.\n");
	printf("- Search by:\n  1 ID  2 Name\n");
	int mode = inputNumber(1, 2, "- Please enter the mode:", "! Error: Wrong number detected. Please try again.\n", 2);
	char temp[22];
	int* res = NULL;
	if (mode == 1) {
		inputString(20, "- Please enter the ID:", "! Error: Wrong string detected. Please enter again.\n", 2, temp);
		res = find_core(1, temp, "");
	} else {
		inputString(10, "- Please enter the name:", "! Error: Wrong string detected. Please enter again.\n", 2, temp);
		res = find_core(2, "", temp);
	}
	int am;
	for (am = 0; res[am] != -1; am++);
	printf("- %d results found:\n", am);
	for (int i = 0; i < am; i++) {
		if (i == 0) {
			display(res[i], res[i], 1, 2);
		} else {
			display(res[i], res[i], 0, 2);
		}
		if (i != am - 1) printf("\n");
	}
	free(res);
	printf("\n\n");
}

int* find_core(int mode, char* id, char* name) {
	//Mode 1 to 2 repersent the mode in the argument sheet by order
	int res[100] = {0}, am = 0;
	if (mode == 1) {
		for (int i = 0; i < AMOUNT; i++) {
			if (!strcmp(id, arr[i].id)) {
				res[am++] = i;
			}
		}
	} else {
		for (int i = 0; i < AMOUNT; i++) {
			if (!strcmp(name, arr[i].name)) {
				res[am++] = i;
			}
		}
	}
	int* ret = (int*)malloc(sizeof(int) * (am + 1));
	for (int i = 0; i < am; i++) {
		ret[i] = res[i];
	}
	ret[am] = -1;
	return ret;
}

void display(int fromNo, int endNo, int hasTitle, int space) {	//The core of display a sheet
	if (hasTitle) {
		for (int i = 0; i < space; i++) printf(" ");
		printf("    No         ID                 Name     Score\n");
	}
	for (int i = fromNo; i <= endNo; i++) {
		for (int i = 0; i < space; i++) printf(" ");
		printf(" %5d %10s %20s %9d", i + 1, arr[i].id, arr[i].name, arr[i].score);
		if (i != endNo) printf("\n");
	}
}

void browse() {
	printf("\n\n- Browse\n");
	printf("  Function Browse helps you to list all of the entries in a clear way.\n  We recommend you to use Function Sort before using Function Browse.\n");
	printf("- Please select the mode:\n    1 All  2 Range\n");
	int mode = inputNumber(1, 2, "- Please enter a number to continue:", "! Error: Wrong number detected. Please enter again.\n", 2);
	int from, to;
	if (mode == 1) {
		from = 1, to = AMOUNT;
	} else {
		if (mode == 1) {
			from = 0, to = AMOUNT - 1;
		} else {
			from = inputNumber(1, AMOUNT, "- Please enter the starting No:", "! Error: Wrong number detected.\n", 2);
			to = inputNumber(from, AMOUNT, "- Please enter the ending No:", "! Error: Wrong number detected.\n", 2);
		}
	}
	printf("- Now displaying:\n");
	display(from - 1, to - 1, 1, 2);
	printf("\n- End displaying.\n\n\n");
}

void sort() {
	printf("\n\n- Sort:\n");
	printf("  Function Sort helps you to sort all the entries by their ID, name or score.\n");
	printf("- Sorting method:\n    1 ID  2 Dictionary  3 Score(high to low)  4 Score(low to high)\n");
	int mode = inputNumber(1, 4, "- Please enter a number to continue:", "! Error: Wrong number detected. Please try again.", 2);
	switch (mode) {
	case 1:
		qsort(arr, AMOUNT, sizeof(arr[0]), cmpID);
		break;
	case 2:
		qsort(arr, AMOUNT, sizeof(arr[0]), cmpName);
		break;
	case 3:
		qsort(arr, AMOUNT, sizeof(arr[0]), cmpScore1);
		break;
	case 4:
		qsort(arr, AMOUNT, sizeof(arr[0]), cmpScore2);
		break;
	}
	printf("- Success.\n");
	save();
	printf("- Changes saved\n\n\n");
}

void stats() {
	long long sum = 0;
	double aver = 0;
	for (int i = 0; i < AMOUNT; i++) {
		sum += arr[i].score;
	}
	aver = 1.0 * sum / AMOUNT;
	printf("\n\n- Stats\n  Function Stats show you the total score and the average score.\n");
	printf("! Total score of %d students: %lld\n", AMOUNT, sum);
	printf("! Average score of %d students: %f\n\n\n", AMOUNT, aver);
}

void exitfunc() {
	printf("\n\n- Exit\n! Are you sure to exit the program?\n    Y  N\n");
	char opera[2];
	while (1) {
		inputString(1, "- Please enter a alphabet to continue:", "! Error: Wrong string detected.\n", 2, opera);
		if (opera[0] == 'Y') {
			toExit = 1;
			return;
		}
		else if (opera[0] == 'N') {
			printf("\n\n");
			return;
		} else {
			printf("! Error: Wrong alphabet was detected. Please try again.\n");
		}
	}
}

int cmpID(const void* a, const void* b) {
	stu* aa = (stu*)a;
	stu* bb = (stu*)b;
	int aaa = atoi(aa->id);
	int bbb = atoi(bb->id);
	return (aaa - bbb);
}

int cmpName(const void* a, const void* b) {
	stu* aa = (stu*)a;
	stu* bb = (stu*)b;
	int ret = strcmp(bb->name, aa->name);
	return ret;
}

int cmpScore1(const void* a, const void* b) {
	stu* aa = (stu*)a;
	stu* bb = (stu*)b;
	return (bb->score - aa->score);
}

int cmpScore2(const void* a, const void* b) {
	stu* aa = (stu*)a;
	stu* bb = (stu*)b;
	return (aa->score - bb->score);
}
