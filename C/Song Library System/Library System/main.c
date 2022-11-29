#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "listxt.h"

void write(txtPtr songs);
void error();
void status();
void save(txtPtr songs);
void read(txtPtr songs, int amount);
void edit(txtPtr songs);
int rep(int ano, int func);
void delete(txtPtr songs);

void main() {
	//  Part One : Welcome us and initialize the list
	printf("Welcome to Song Library System.\n");
	status();
	printf("Initializing...\n");

	FILE* dat = fopen("dat.txt", "a+");	//open and read the file
	char init[25] = "init"; //init a list and initialize it
	txtPtr songs = TxtCreate(init);
	int amount = 0, cnt = 0;

	if (dat) {
		while (1) {
			char temp[24] = "";
			int ret;
			ret = fscanf(dat, "%s", temp);
			if (ret == EOF) {
				break;
			}
			TxtAddB(songs, cnt + 1, temp);
			cnt++;
		}
		amount = cnt / 3;
		printf("There are %d data in our database.\n", amount);
		fclose(dat);
	}
	else {
		printf("Error: Cannnot access the database file \"dat.txt\"\n");
		printf("Error: Program Abort\n");
	}
	

	// Part 2 : Choose the mode
	int mainsignal = 1;//The loop for the mian function
	while (mainsignal == 1) {
		int choise;
		char signal1 = 1;//To detect the input is correct or not
		while (signal1) {
			printf("\nPlease enter an number to continue:\n");
			printf("\t1 Read    2 Write    3 Edit    4 Delete    5 Exit\n");
			scanf("%d", &choise);
			printf("\n");
			switch (choise) {
			case 1://alphabet to ASCII code cause the argument in switch only can be int 
				read(songs, amount);
				signal1 = 0;
				break;
			case 2:
				write(songs);
				signal1 = 0;
				break;
			case 3:
				edit(songs);
				signal1 = 0;
				break;
			case 4:
				delete(songs);
				signal1 = 0;
				break;
			case 5:
				goto exitsc;
			default:
				error();
			};
		}
		mainsignal = rep(mainsignal,0);
	}

	// Part 3 Exit
	exitsc:
	printf("\nSaving......");
	save(songs);
	printf("\nThank you for using Song Library System.\n");
	printf("Press enter to exit...\n\n");
	getchar();
	getchar();
}	

/*
Need to do:
	The relationship between lf cr crlf
	It used goto which is not recommend to use.
*/

void write(txtPtr songs) {
	int signal = 1;
	int loc;
	while (signal == 1) {
		while (1) {
			printf("Please enter the location where you want to write a data (from 1 to %d):\n", TxtLength(songs)/3+1);
			scanf("%d", &loc);
			if (loc > 0 && loc <= (TxtLength(songs) / 3 + 1)) break;
			else {
				printf("\n");
				error();
			}
		}
		int realocation = (loc - 1) * 3 + 1;
		char temp[25];
		printf("\nNow you are adding a data in location %d in the database.\n", loc);
		printf("\tTitle :");
		scanf("%s", temp);
		TxtAddB(songs, realocation, temp);
		realocation++;
		printf("\n\tArtist:");
		scanf("%s", temp);
		TxtAddB(songs, realocation, temp);
		realocation++;
		printf("\n\tAlbum :");
		scanf("%s", temp);
		TxtAddB(songs, realocation, temp);
		printf("\nWrite successfully\n\n");
		signal = rep(signal,2);
	}
}

void error() {
	printf("Error: Wrong argument was detected! Please try again.\n\n");
}

void status() {
	printf("Date     : %s\n", __DATE__);
	printf("Time     : %s\n", __TIME__);
	printf("Databese : dat.txt\n");
}

void save(txtPtr songs) {
	FILE* dat = fopen("dat.txt", "w");
	char temp[25];
	int cnt = 1;
	while (cnt<TxtLength(songs)-1) {
		fprintf(dat, "%s ", TxtData(songs, cnt));
		cnt++;
	}
	fprintf(dat, "%s", TxtData(songs, cnt));
	fclose(dat);
}

void read(txtPtr songs,int amount) {
	int signal1 = 1;
	while (signal1 == 1) {
		int page = amount / 10 + 1;//To display page
		int input = 0;
		int signal = 1;//To detect whether to continue or give an another chance to enter another number
		while (signal != 0) {
			printf("Please entern the page number (from 1 to %d):\n", page);
			scanf("%d", &input);
			if (input > 0 && input <= page) {
				signal = 0;
			}
			else {
				printf("\n");
				error();
			}
		}
		printf("\n");
		int loc = 30 * (input - 1) + 1;//Locate the position of the list
		printf("---------------------------------------------------------------------------------------------\n");//initialize the sheet
		printf("  No.     Title                           Artist                    Album  \n");
		printf("---------------------------------------------------------------------------------------------\n");
		int cnt = 1;//the counter from 1 to 10
		char temp[25];
		for (cnt = 1; cnt <= 10; cnt++) {
			printf("  %-8d", ((input - 1) * 10 + cnt));//No.
			if (TxtData(songs, loc) == NULL) {//the nul breaker:when it come to the EOF it will stop diaplaying the list
				printf("\b\b\b\b\b\b\b\b\b\b\b");//use the \b to delete the mistaken added thing
				break;
			}
			printf("%-32s", TxtData(songs, loc));
			loc++;
			printf("%-26s", TxtData(songs, loc));//Artist
			loc++;
			printf("%s", TxtData(songs, loc));
			loc++;
			printf("\n");
		}
		printf("---------------------------------------------------------------------------------------------\n\n");
		signal1 = rep(signal1,1);
	}
}

void edit(txtPtr songs) {
	txtPtr p = songs;
	int signal = 1;
	int loc, realoc;
	while (signal == 1) {
		while (1) {
			printf("Please enter the serial number of the data you want to edit (from 1 to %d):\n", TxtLength(songs)/3);
			scanf("%d", &loc);
			if (loc > 0 && loc <= (TxtLength(songs)-1)/3) break;
			else {
				printf("\n");
				error();
			}
		}
		realoc = (loc - 1) * 3 + 1;
		for (int cnt = 0; cnt < 3; cnt++) {
			TxtDelB(songs, realoc);
		}
		printf("\n");
		char temp[25];
		printf("\tTitle :");
		scanf("%s", temp);
		TxtAddB(songs, realoc, temp);
		realoc++;
		printf("\n\tArtist:");
		scanf("%s", temp);
		TxtAddB(songs, realoc, temp);
		realoc++;
		printf("\n\tAlbum :");
		scanf("%s", temp);
		TxtAddB(songs, realoc, temp);
		printf("\nEdit successfully\n\n");
		signal = rep(signal,3);
	}
}

int rep(int ano, int func) {  //ano is another signal that are used in the program, often is the int variable in the first while loop argument in the functuion
	int signal5 = 1;//the func argument is to detect where the rep function are used to display different content
	int ret;
	while (signal5 == 1) {
		if (func == 0) {
			printf("Do you want to go back to the main menu or exit the program?\n");
			printf("\t1 Back   2 Exit\n");
		}
		else {
			printf("Please enter a number to continue the function:\n");
			printf("\t1 Continue   2 Exit\n");
		}
		scanf("%d", &ret);
		switch (ret) {
		case 1:
			signal5 = 0;
			break;
		case 2:
			signal5 = 0;
			ano = 0;
			break;
		default:
			printf("\n");
			error();
			break;
		}
	}
	printf("\n");
	return ano;
}

void delete(txtPtr songs) {
	txtPtr p = songs;
	int signal = 1;
	int loc, realoc;
	while (signal == 1) {
		while (1) {
			printf("Please enter the serial number of the data you want to delete (from 1 to %d):\n", TxtLength(songs)/3);
			scanf("%d", &loc);
			if (loc > 0 && loc <= (TxtLength(songs) / 3 + 1)) break;
			else {
				printf("\n");
				error();
			}
		}
		realoc = (loc - 1) * 3 + 1;
		for (int cnt = 0; cnt < 3; cnt++) {
			TxtDelB(songs, realoc);
		}
		printf("\nDelete succesfully\n\n");
		signal = rep(signal,4);
	}
}