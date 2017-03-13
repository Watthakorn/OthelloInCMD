#include <stdio.h>
#include <windows.h>

void othello();// Othello label
void menu();// menu 1 2 3 4
void gotoxy();// fix axis x & y
void credit();// credit
void htp(); //how to play
void black_win(); // black win label
void white_win(); // white win label
void draw(); // draw label
void table_8x8(); // print table
void flip(int col, int row, int bow); // flip opponent stone
void play(); // play game
void page(); // page hoe to play
void htp_table(); // table how to play
int checka(int col, int row, int bow); // check around of selected position can land a stone
int checks(int col, int row, int bow, int x, int y);// check straight of selected position can land a stone
int can_land(int bow); // check that turn can land a stone
int check_score_black(); // check score of black
int check_score_white(); // check score of white
int game_end(); // check game is end?

int table[8][8], p=1; // array of table 8*8

 /* main function */

int main()
{
	system("MODE 120,30");

	othello();
	menu();
	
	return 0;
}

void othello()
{
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
	printf("\n");
	printf(" ###################################################################################################################### ");
	printf(" #   _____________     _____________    ____     ______   _____________   ____          ____          _____________   # ");
	printf(" #  /    ____     |   /             /  /   |    /     |  /            |  /   |         /   |         /    ____     |  # ");
	printf(" #  |   |    |    |  /____     ____/   |   |    |     |  |    ________|  |   |         |   |         |   |    |    |  # ");
	printf(" #  |   |    |    |       |   |        |   |____|     |  |   |________   |   |         |   |         |   |    |    |  # ");
	printf(" #  |   |    |    |       |   |        |    ____      |  |    ________|  |   |         |   |         |   |    |    |  # ");
	printf(" #  |   |    |    |       |   |        |   |    |     |  |   |________   |   |         |   |         |   |    |    |  # ");
	printf(" #  |   |____|    |       |   |        |   |    |     |  |            |  |   |_______  |   |_______  |   |____|    |  # ");
	printf(" #  |_____________/       |___/        |___/    |_____/  |____________/  |__________/  |__________/  |_____________/  # ");
	printf(" #                                                                                                                    # ");
	printf(" ###################################################################################################################### ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

void menu()
{
	int number;
	printf("\n\n\n");
	printf("\t\t\t\t\t\t1 - Play\n");
	printf("\t\t\t\t\t\t2 - How to Play\n");
	printf("\t\t\t\t\t\t3 - Credit\n");
	printf("\t\t\t\t\t\t4 - Exit\n");
	printf("\n\n\n");
	printf("\t\t\t\t\t    Please You Choose : ");
	scanf("%d",&number);
	system("cls");
	system("MODE 75,50");
	if(number==1)
		play();
	else 
		if(number==2)
		{
			htp();
			page();
			main();
		}
		else 
			if(number==3)
			{
				credit();
				getch();
				main();
			}
			else 
				if(number!=4)
					main();	
}

COORD coord = {0,0};
void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void credit()
{
	system("MODE 120,30");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
	printf("\n");
	printf(" ###################################################################################################################### ");
	printf(" #             _____________    ____   ___   _____________              ____   _____    _____________                 # ");
	printf(" #            /             |  /    | /  /  /            |             /   |  /____/   /             /                # ");
	printf(" #            |   __________|  |    |/  /   |    ________|             |   |   ____   /____     ____/                 # ");
	printf(" #            |   |            |       /    |   |________     _________|   |  |    |       |   |                      # ");
	printf(" #            |   |            |      /     |    ________|   |   ___       |  |    |       |   |                      # ");
	printf(" #            |   |_________   |     /      |   |________    |  |___|      |  |    |       |   |                      # ");
	printf(" #            |             |  |    |       |            |   |        /|   |  |    |       |   |                      # ");
	printf(" #            |_____________/  |____|       |____________/   |_______/ |___|  |____|       |___/                      # ");
	printf(" #                                                                                                                    # ");
	printf(" ###################################################################################################################### ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	gotoxy(55,13);
	printf("The Teams\n");
	gotoxy(43,15);
	printf("Ramet       Yangdum       57070098\n");
	gotoxy(43,16);
	printf("Worravej    Siraputpong   57070104\n");
	gotoxy(43,17);
	printf("Watthakorn  Malikow       57070106\n");
	gotoxy(43,18);
	printf("Sattra      Tansuphasiri  57070111\n");
	gotoxy(43,19);
	printf("Safwan      Paeroh        57070125\n");
}

void htp()
{
	system("cls");
	system("MODE 120,35");
	p=1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x09);
	printf("\n");
    printf(" ###################################################################################################################### ");	
	printf(" #  ____     ______   _____________    ____              ____     _____________    _____________     _______________  # ");
	printf(" # /   |    /     |  /    ____     |  /    |    ___     /    |   /             /  /    ____     |   /   _________   | # ");
	printf(" # |   |    |     |  |   |    |    |  |    |   /   |    |    |  /____     ____/   |   |    |    |   |  | |___  | |  | # ");
	printf(" # |   |____|     |  |   |    |    |  |    |   |   |    |    |       |   |        |   |    |    |   |  |____|  | |  | # ");
	printf(" # |    ____      |  |   |    |    |  |    |   |   |    |    |       |   |        |   |    |    |   |__________| |  | # ");
	printf(" # |   |    |     |  |   |    |    |  |    |___|   |____|    |       |   |        |   |    |    |        ________|  | # ");
	printf(" # |   |    |     |  |   |____|    |  |                      |       |   |        |   |____|    |       |    _______| # ");
	printf(" # |___/    |_____/  |_____________/  |______________________/       |___/        |_____________/       |___|         # ");
	printf(" #                                                                                                                    # ");
	printf(" ###################################################################################################################### ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
	gotoxy(45,15);
	printf("[ Press q : back to main menu ]");
	gotoxy(57,17);
	printf("[ 1/4 ]\t\t\t\t\t\tNext >>>\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

void page()
{
	int n;
	do
	{	do
		{
			do
			{
				n = getch(); // left=75   right=77
			}while(n!=75 && n!=77 && n!='q');
		}while((n==75&&p==1) || (n==77&&p==4));
			if (n==77&&p!=4)
			{
				p++;
				system("cls");
				htp_table();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
				printf("\n\n\t\t    [ Press q : back to main menu ]\n");
				if (p==4)
				{
					printf("\n<<< Back\t\t\t[ %d/4 ]\n", p);
				}
				else
				{
					printf("\n<<< Back\t\t\t[ %d/4 ]\t\t\t\tNext >>>\n", p);
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			}
			if(n==75&&p!=1)
			{
				p--;
				system("cls");
				htp_table();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
				printf("\n\n\t\t    [ Press q : back to main menu ]\n");
				printf("\n<<< Back\t\t\t[ %d/4 ]\t\t\t\tNext >>>\n", p);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			}
			if(n==75&&p<2)
			{
				htp();
			}
	}while(n!='q');
}

void htp_table()
{
	int i,j;
	for(i=0;i<=7;i++)// set first table
		for(j=0;j<=7;j++)
			table[i][j] = 0;
	table[3][4] = 1;// set black
	table[4][3] = 1;// set black

	table[3][3] = 2;// set white
	table[4][4] = 2;// set white
	if(p==2)
	{
		system("MODE 75,35");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf("\n\t\t\t\t\t\t (Score Black and White)\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		table_8x8();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf("\t\t\t(The Black player moves first)\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		printf("Enter \"t1\" to call table \"q1\" to End Game.");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf(" (Can leave the game at anytime.)\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		printf("\n\t\tEnter black move (column row): ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf("-> Ex. c4, d3, e6, f5, etc.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	}
	else if(p==3)
	{
		system("MODE 75,35");
		table[2][3] = 1;
		table[3][3] = 1;
		table_8x8();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf("\t\t\t    ^ (If Black move(c4)\", \n\t   White chip(d4) between Black chip(c4, e4) will change to Black)");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		printf("\n\nEnter \"t1\" to call table \"q1\" to End Game\n.");
		printf("\n\t\tEnter white move (column row): ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf("-> Turn Change to White.\n");
		printf("\nIf one player can't make a valid move, play passes back to the other player\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	}
	else if (p==4)
	{
		system("MODE 75,35");
		int i,j;
		for (i=0;i<8;i++)
		{
			for (j=0;j<8;j++)
				table[i][j]=1;
		}
		for (i=1; i<7; i++)
			table[i][3]=2;
		table[2][2]=2;table[2][6]=2;
		table[3][4]=2;table[3][5]=2;
		table[4][5]=2;
		table[5][4]=2;
		table[6][4]=2;table[6][5]=2;table[6][6]=2;
		table_8x8();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf("\n    (If on one have turn or in bord have only one color, game will end)\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		printf("\n\nEnter \"t1\" to call table \"q1\" to End Game\n.");
		printf("\n\t\t Black Wins!!");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0C);
		printf("-> chips Black(49) more than chips white(15)\n");
		printf("\n\t\t\tIf Score Black = White --> DRAW");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
	}
}

void black_win()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0D);
	printf("\t#####################################################\n");
	printf("\t#                                                   #\n");
	printf("\t#  ######    #          #####     #####    #     #  #\n");
	printf("\t#  #     #   #         #     #   #     #   #     #  #\n");
	printf("\t#  #     #   #         #     #   #         #    #   #\n");
	printf("\t#  ######    #         #     #   #         #####    #\n");
	printf("\t#  #     #   #         #######   #         #    #   #\n");
	printf("\t#  #     #   #         #     #   #     #   #     #  #\n");
	printf("\t#  ######    #######   #     #    #####    #     #  #\n");
	printf("\t#                                                   #\n");
	printf("\t#####################################################\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
	printf("\t\t\t\t\t###############################\n");
	printf("\t\t\t\t\t#                             #\n");	
	printf("\t\t\t\t\t# #     #   #######   #     # #\n");
	printf("\t\t\t\t\t# #     #      #      ##    # #\n");
	printf("\t\t\t\t\t# #     #      #      # #   # #\n");
	printf("\t\t\t\t\t# #  #  #      #      #  #  # #\n");
	printf("\t\t\t\t\t# #  #  #      #      #   # # #\n");
	printf("\t\t\t\t\t# #  #  #      #      #    ## #\n");
	printf("\t\t\t\t\t#  ## ##    #######   #     # #\n");
	printf("\t\t\t\t\t#                             #\n");	
	printf("\t\t\t\t\t###############################\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

void white_win()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);
	printf("\t#####################################################\n");
	printf("\t#                                                   #\n");
	printf("\t#  #     #   #     #   #######   #######   #######  #\n");
	printf("\t#  #     #   #     #      #      #  #  #   #        #\n");
	printf("\t#  #     #   #     #      #         #      #        #\n");
	printf("\t#  #  #  #   #######      #         #      #######  #\n");
	printf("\t#  #  #  #   #     #      #         #      #        #\n");
	printf("\t#  #  #  #   #     #      #         #      #        #\n");
	printf("\t#   ## ##    #     #   #######     ###     #######  #\n");
	printf("\t#                                                   #\n");
	printf("\t#####################################################\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0E);
	printf("\t\t\t\t\t###############################\n");
	printf("\t\t\t\t\t#                             #\n");	
	printf("\t\t\t\t\t# #     #   #######   #     # #\n");
	printf("\t\t\t\t\t# #     #      #      ##    # #\n");
	printf("\t\t\t\t\t# #     #      #      # #   # #\n");
	printf("\t\t\t\t\t# #  #  #      #      #  #  # #\n");
	printf("\t\t\t\t\t# #  #  #      #      #   # # #\n");
	printf("\t\t\t\t\t# #  #  #      #      #    ## #\n");
	printf("\t\t\t\t\t#  ## ##    #######   #     # #\n");
	printf("\t\t\t\t\t#                             #\n");	
	printf("\t\t\t\t\t###############################\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

void draw()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03);
	printf("\t\t#########################################\n");	
	printf("\t\t#                                       #\n");
	printf("\t\t# ######    ######     #####    #     # #\n");
	printf("\t\t# #     #   #     #   #     #   #     # #\n");
	printf("\t\t# #     #   #     #   #     #   #     # #\n");
	printf("\t\t# #     #   ######    #     #   #  #  # #\n");
	printf("\t\t# #     #   #     #   #######   #  #  # #\n");
	printf("\t\t# #     #   #     #   #     #   #  #  # #\n");
	printf("\t\t# ######    #     #   #     #    ## ##  #\n");	
	printf("\t\t#                                       #\n");
	printf("\t\t#########################################\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

 /* function print table */
void table_8x8()
{
	printf("\n\t\t");
	char abc[9]={"abcdefgh"};
	int i,j;
	printf(" ");
	for (i=0; i<8; i++)
	{
		printf("   %c", abc[i]);
	}
	printf("    Black %d : %d white", check_score_black(), check_score_white());
	printf("\n  ");
	for (i=0;i<8;i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		printf("\t\t  ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x20);
		printf("---------------------------------\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		printf("\t\t  ");
		for(j=0;j<8;j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x20);
			printf("|");
			if (table[j][i]==1)
			{
				printf(" @ ");
			}
			else if (table[j][i]==2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x27);
				printf(" @ ", table[j][i]);
			}
			else
				printf("   ");
		}
		printf("|");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
		printf(" %d \n", i+1);
		
	}
	printf("  \t\t  ");SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x20);
	printf("---------------------------------\n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
}

/* flip opponent stone */
void flip(int col, int row, int bow)
{
	int i,j,a,b;
	for(i=-1;i<=1;i++)
	{
		for(j=-1;j<=1;j++)
		{
			if((i!=0||j!=0) && checks(col, row, bow, i, j))
			{
				a=col;
				b=row;
				while(table[a+i][b+j]!=bow) // flip opponent target stone
				{
					table[a+i][b+j]=bow;
					a+=i;
					b+=j;
				}
			}
		}
	}

}

/* play */
void play()
{
	int check=1,col,row,turn=1,again=0,bow,a,b,i,j; // bow is black or white stone that turn, a and b is observer of col and row
	char cols[2]; // string of column
	for(i=0;i<=7;i++)// set first table
		for(j=0;j<=7;j++)
			table[i][j] = 0;

	table[3][4] = 1;// set black
	table[4][3] = 1;// set black

	table[3][3] = 2;// set white
	table[4][4] = 2;// set white

	printf("\n\n");
	table_8x8();// first table

	do{

		if((cols[0]==113&&row==0)||game_end())// check game is end or exit input
		{
			system("cls");
			printf("\n\t\t\t      Game is end. \n\n");	
			table_8x8();
			printf("\n\n Press any key to continue.\n");
			getch();
			system("cls");
			printf("\n\t\t\t      Game is end. \n\n");	
			printf(" Total score is Black %d : %d White\n\n", check_score_black(), check_score_white());
			if(check_score_black() == check_score_white())
				draw();
			else
				if (check_score_black() > check_score_white())
					black_win();
				else
					white_win();
			printf("\n\n Press any key to continue.\n");
			getch();
			main();
			check=0;
		}
		else
		{
			if(turn==1||can_land(bow))
			{
				if(again==0)
				{
					printf(" Enter \"t1\" to call table \"q1\" to End Game.\n\n\t\t   Enter %s move (column row): ", turn%2==0?"white":"black"); // print presenter of input
				}
				else
				{
					printf("\t\t   Enter %s again (column row): ", turn%2==0?"white":"black"); // if input is wrong it will be work
				}

				scanf("%1s%1d", cols,&row); // input column in string form and row in integer form

				col = cols[0]-96; //change char to integer 
				again++; // set again more than 0 for check this turn have to input again or not?
				col--; // change integer to index
				row--; // change integer to index
				bow=turn%2==0?2:1;// turn of black or white
			}
		}

		if(can_land(bow)) // check this turn can play?
		{
			if(table[col][row]==0 && 0<=col&&col<=7 && 0<=row&&row<=7 && checka(col, row, bow)) // check selected position can land a stone
			{
				// land and flip //
				table[col][row] = bow; // land a stone
				flip(col, row, bow); // flip opponent stone
				again=0; // set again to 0
			}

			if(again==0) // if this turn worked true will go next turn
			{
				system("cls");
				printf("\n\t\t\t    %s move: %s%d\n", turn%2==0?"white":"black", cols, row+1); // print position of this turn
				table_8x8();
				turn++; // set turn to next turn
			}
		}
		
		else
		{
			turn++; // set turn to next turn
		}

		if(cols[0]==116&&row==0)
		{
			system("cls");
			printf("\n\n");
			table_8x8();
			printf(" Enter \"t1\" to call table \"q1\" to End Game.\n\n");
		}
		bow=turn%2==0?2:1;
	}while(check==1);
}

/* check around of selected position can land a stone */
int checka(int col, int row, int bow)
{ // check around
	int flag=0,i,j;
	for(i=-1;i<=1;i++)
	{
		for(j=-1;j<=1;j++)
		{
			if((i!=0||j!=0) && checks(col, row, bow, i, j))
			{
				if(checks(col, row, bow, i, j))
					flag=1;
			}
		}
	}
	return flag;
}

/* check straight of selected position can land a stone */
int checks(int col, int row, int bow, int x, int y)
{
	int flag=0,fst=0;

	while(flag==0 && col<=7&&row<=7 && col>=0&&row>=0)
	{
		if(fst++==0)
		{
			if(table[col+x][row+y]==bow || table[col+x][row+y]==0)// if next step is same or space will break while loob and return flag = 0
			{
				break;
			}
		}
		else
		{
			if(table[col+x][row+y]==0)// while function is working if next step is space will break while loob and return flag = 0
			{
				break;
			}
			else
			{
				if(table[col+x][row+y]==bow&&col+x<=7&&row+y<=7&&col+x>=0&&row+y>=0) // check next step untill find same stone and return flag = 1
				{
					flag=1;
				}
			}
		}
		col+=x;
		row+=y;
	}
	return flag;// flag=1 is can land stone in that space
}

/* check this turn can land a stone */
int can_land(int bow)
{
	int flag=0,i,j;
	for(i=0;i<=7;i++)
	{
		for(j=0;j<=7;j++)
		{
			if(table[i][j]==0&&checka(i, j, bow))
				flag=1;
		}
	}
	return flag;

}

/* check score of black*/
int check_score_black()
{
	int black=0,q,p;
	for(q=0;q<=7;q++)
	{
		for(p=0;p<=7;p++)
		{
			if(table[q][p] == 1)
				black++;
		}
	}
	return black;
}

/* check score of white */
int check_score_white()
{
	int white=0,q,p;
	for(q=0;q<=7;q++)
	{
		for(p=0;p<=7;p++)
		{
			if(table[q][p] == 2)
				white++;
		}
	}
	return white;
}

/* check game is end? */
int game_end()
{
	int flag=1;
	if(can_land(1) || can_land(2)) // if both stone can't land return flag = 0
		flag=0;
	return flag;
}