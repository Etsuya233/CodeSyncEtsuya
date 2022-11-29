#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> //For the random seed

void welcome();
struct map** mapGenerator();
void travelTheMap(struct map**);
void mapDisplayer(struct map** map);
void showAnswer(struct map** map);
int mineAmountCounter(struct map** map, int x, int y);
int click(struct map** map, int x, int y, char mode);
void fail();

struct map {
	int isMine;
	int isFlaged;
	int beenClicked;
	int mineAmount;
} ;

void main() {
	int flagTimes = 0;
	int correctFlags = 0;
	int clickResult = 0;

	//welcome();
	srand((unsigned)time(NULL)); //To get the random seed
	struct map** myMap = mapGenerator();
	printf("Answer:\n");	//Test use
	showAnswer(myMap);
	travelTheMap(myMap);
	printf("\n");
	do {
		int x, y;
		char mode;
		while (1) {
			printf("Please enter the mode and the block you want to manipulate: \n");
			printf("Mode: f to flag and c to click \n");
			scanf("%c %d %d", &mode, &y, &x);
			clickResult = click(myMap, x, y, mode);
			if (clickResult == 1) {
				printf("This block has been clicked, please try again!\n");
			} else if (clickResult == 2) {
				fail();
				break;
			} else if (clickResult == 3) {
				break;
			} else if (clickResult == 4) {
				if (myMap[x][y].isMine == 1) {
					correctFlags += 1;
				}
				break;
			} else if (clickResult == 5) {
				printf("This block has been flaged, please try again.\n");
			}
		}
		//printf("The block: %d", myMap[x][y].isFlaged); test use
		if (clickResult == 2) break;
		if (correctFlags == 8) {
			break;
		}
		
		mapDisplayer(myMap);
		printf("\n");
	} while (clickResult != 2);

	if (clickResult != 2) {
		printf("U win!");
	}
}

/*
Need to do:
	In func main:
		The malloc will destroyed when leaving the func?
	In func mapInit :
		Initialize every value of the structure map into 0 (maybe don't do it is OK cus its default value is 0);
	In func click:
		Optimize the situation when click a block which has been flaged and on the opposite situation
*/

void welcome() {
	printf("Please adjust the screen to a suitable size:\n");
	for (int cnt = 0; cnt < 25; cnt++) {
		printf("--------------------------------------------------------------------------------\n");
	}
}

void mapDisplayer(struct map** map) {
	printf("  0 1 2 3 4 5 6 7\n");	//To display x
	for (int i = 0; i < 8; i++) {
		printf("%d", i);	//To display the y
		for (int j = 0; j < 8; j++) {
			if (map[j][i].isFlaged == 1) {
				printf(" f");
			} else if (map[j][i].beenClicked && map[i][j].isMine == 0) {
				printf(" %d", mineAmountCounter(map, i, j));
			} else if (map[j][i].beenClicked && map[i][j].isMine == 1) {
				printf(" x");
			}else {
				printf(" *");
			}
		}
		printf("\n");
	}


}

struct map** mapGenerator() {	//To generate a map by using struct** and return a pointer
	struct map** mapInit = (struct map**)malloc(sizeof(struct map*) * 8);	//To understand it!!!
	for (int cnt = 0; cnt < 8; cnt++) {
		mapInit[cnt] = (struct map*)malloc(sizeof(struct map) * 8);
		for (int i = 0; i < 8; i++) {	//Initialize the value in the struct
			mapInit[cnt][i].isFlaged = 0;
			mapInit[cnt][i].isMine = 0;
			mapInit[cnt][i].mineAmount = 0;
			mapInit[cnt][i].beenClicked = 0;
		}
	}

	for (int cnt = 0; cnt < 8;) {	//To generate 10 mines
		int x = rand();	//To generate the location of the mines and frame the location bwtween 0 to 9;
		x %= 8;
		int y = rand();
		y %= 8;
		//printf("\t%d\n", mapInit[x][y].isMine);
		//For test use: to display the loc whether an mine
		if (mapInit[x][y].isMine == 0) {
			mapInit[x][y].isMine = 1;
			cnt++;
		}//To detect the location whether a mine. If the loc isnt a mine then mark it is a mine 
	}

	return mapInit;
}

void travelTheMap(struct map** map) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (map[i][j].isMine == 1) printf("%d, %d is a mine.\n", j, i);
		}
	}
}

void showAnswer(struct map** map) {
	printf("  0 1 2 3 4 5 6 7\n");	//To display x
	for (int i = 0; i < 8; i++) {
		printf("%d", i);	//To display the y
		for (int j = 0; j < 8; j++) {
			if (map[i][j].isMine == 1) {
				printf(" x");
			}
			else if (map[i][j].isMine == 0) {
				printf(" %d", mineAmountCounter(map, i, j));
			}
		}
		printf("\n");
	}


}

int mineAmountCounter(struct map** map, int x, int y) {
	int amount = 0;
	if (map[x][y].isMine == 0) {
		if (x - 1 >= 0 && y - 1 >= 0 && map[x - 1][y - 1].isMine == 1) amount += 1;
		if (x - 1 >= 0 && y >= 0 && map[x - 1][y].isMine == 1) amount += 1;
		if (x - 1 >= 0 && y + 1 <= 7 && map[x - 1][y + 1].isMine == 1) amount += 1;
		if (x >= 0 && y - 1 >= 0 && map[x][y - 1].isMine == 1) amount += 1;
		if (x >= 0 && y + 1 <= 7 && map[x][y + 1].isMine == 1) amount += 1;
		if (x + 1 <= 7 && y - 1 >= 0 && map[x + 1][y - 1].isMine == 1) amount += 1;
		if (x + 1 <= 7 && y >= 0 && map[x + 1][y].isMine == 1) amount += 1;
		if (x + 1 <= 7 && y + 1 <= 7 && map[x + 1][y + 1].isMine == 1) amount += 1;
	} else {
		return 9;
	}
	return amount;
}

int click(struct map** map, int x, int y, char mode) {
	int ret = 0;
	if (mode == 'c') {
		if (map[x][y].beenClicked == 1) {
			ret = 1;	//This represent the block had been clicked
		} else if (map[x][y].isMine == 1) {
			ret = 2;
		} else if (map[x][y].isMine == 0) {
			map[x][y].beenClicked = 1;
			ret = 3;
		}
	} else if (mode == 'f') {
		if (map[x][y].isFlaged == 0) {
			map[x][y].isFlaged = 1;
			ret = 4;
		} else if (map[x][y].isFlaged == 1) {
			ret = 5;
		}
	} else {
		ret = 6;
	}

	return ret;
}

int flag(struct map** map, int x, int y) {
	int ret;
	if (map[x][y].isFlaged == 0) {
		map[x][y].isFlaged = 1;
		ret = 1;
	}
	else if (map[x][y].isFlaged == 1) {
		ret = 2;
	}
	return ret;
}//Abandoned!!!

void fail() {
	printf("U R Failed");
}