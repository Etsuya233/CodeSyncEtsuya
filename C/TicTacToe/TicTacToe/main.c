#include <stdio.h>

void view(int* game);
int judge(int* game);

void main() {
	printf("Welcome to TicTacToe!\n");
	
	int game[10] = {0};	//To storage the game process
	int status[10] = { 0 };	//1 reprezent the area has used so player cant use it
	int times = 0;	//To record how many round we had played

	int player = 1;
	while (judge(game) == 0) {
		int place;
		int signal1 = 1;
		while (signal1) {
			printf("> Player %d's turn:\n  Please enter the location you want to occupied:", player);
			scanf("%d", &place);
			if (status[place] == 0) {
				status[place] = 1;
				game[place] = player;
				signal1 = 0;
			} else {
				printf("ERROR: This location has occupied or its a wrong location, please try again.");
			}
			view(game);
		}
		times++;
		if (times == 9) break; //If all the location has been occupied
		player++;
		if (player == 3) player = 1;	//To set the player in 1 and 2
	}

	int result = judge(game);	//To get the result
	switch (result) {
	case 0:
		printf("> It's a DRAW!");
		break;
	case 1:
		printf("> Player 1 WIN! Congratulation!");
		break;
	case 2:
		printf("> Player 2 WIN! Congratulation!");
	}
	
	printf("\nPress enter to exit...");
	getchar();
	getchar();
}

void view(int* game) {	//the graphic display of the game process
	printf("\n");
	int cnt = 0;
	int loc = 1;
	for (cnt = 0; cnt < 3; cnt++) {
		printf("      |      |      \n");
		for (int a = 0; a < 3; a++) {	//To printf the result
			printf("  ");
			if (game[loc++] == 0) {
				printf(" ");
			} else {
				printf("%d", game[loc-1]);
			}
			if (a != 2) {
				printf("   |");
			} else {
				printf("    \n");
			}
		}
		printf("______|______|______");
		if (cnt == 2) {	//To fix the layout while using loop print
			printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
			printf("      |      |      ");
		}
		printf("\n");
	}
	printf("\n");
}

int judge(int* g) {	//if the return value is 0 the game is continue or it will return the winner
	int a = 0;
	int loc = 1;
	for (a = 0; a < 3; a++) {	//the order 123 456 789
		if ((g[loc] == g[loc+1]) && (g[loc+1] == g[loc+2]) && g[loc] != 0) {
			return g[loc];
		}
		loc += 3;
	}
	loc = 1;
	for (a = 0; a < 3; a++) {	//the order 147 258 369
		if ((g[loc] == g[loc + 3]) && (g[loc + 3] == g[loc + 6]) && g[loc] != 0) {
			return g[loc];
		}
		loc++;
	}
	if ((g[1] == g[5]) && (g[5] == g[7]) && g[1] != 0) {	//the order 159
		return g[1];
	}
	if ((g[3] == g[5]) && (g[5] == g[7]) && g[3] != 0) {
		return g[3];
	}
	return 0;
}