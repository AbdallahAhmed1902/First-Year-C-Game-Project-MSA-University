#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
/*Kareem*/
//Structure to maintaines enemy's data//
struct Enemies
{
	int Er;
	int Ec;
	int Type;
	float Health;
	int minEc;
	int maxEc;
	int dir;
	int JumpTime;
};
void logic(char map[][360], int& jumpstate, int& Heror, int& herohealth, int& Heroc, int& state, int& jumpcounter, int& ballr, int& ballc, int& jumpstateball, int& stateladder, int& displayr, int& pos, Enemies* Enemy, int NumE, int& dispalyc, int& bulletA, int shop, int& ENH, int& ct)
{
	if (shop == 0)
	{
		/*Abdallah*/
		//Made The Final Boss Notice Hero When he is Within the Enemy's borders//
		if (Heroc <= Enemy[2].maxEc && Heror == 15 || (Heroc + 6) >= Enemy[2].minEc && Heror == 15)
		{
			ENH = 1;
		}
		else
		{
			ENH = 0;
		}

		/*Abdallah*/
		//Gave The Player 2 chances//
		if (herohealth <= 0 && ct <= 2)
		{
			herohealth = 10;
			Heror = 35;
			ballc = 320;
			ballr = 36;
			displayr = 20;
			Heroc = 320;
			dispalyc = 275;
			ct++;
		}

		/*Abdallah*/
		//Active The bullet When The hero catch The Ability from The Parkour//
		if (bulletA == 0 && (Heror - 1 <= 27 && Heror + 4 >= 27 && Heroc <= 138 && Heroc + 7 >= 136) || (ballr - 1 <= 27 && ballr + 3 >= 27 && ballc - 1 <= 138 && ballc + 9 >= 136))
		{
			bulletA = 1;
		}





		/*Kareem*/
		//To Active The ladder state while the player using it//
		stateladder = 0;
		for (int i = 0; i < 7; i++)
		{
			if (Heror + 4 >= 19 && Heror <= 37 && Heroc >= 340 && Heroc <= 348)
			{
				stateladder = 1;
				break;
			}
		}
		
		/*Moaz and edited by Kareem*/
		//When Hero "ONElevator" The Hero will goes down with it//
		int onElevator = 0;
		if (Heroc >= 0 && Heroc <= 11)
		{
			if (jumpstate == 0)
			{
				if (Heror + 4 >= (39 + pos) - 1 && Heror + 4 <= (39 + pos) + 2)
				{
					Heror = 35 + pos;
					onElevator = 1;
				}
			}
		}

		/*Abdallah*/
		//To Check Before hits The Hero if bahind him is a wall or not to do not bush him out of the map//
		for (int e = 0; e < NumE; e++)
		{
			if (Enemy[e].Health > 0)
			{
				if (Heroc >= Enemy[e].Ec - 8 && Heroc <= Enemy[e].Ec + 8 &&
					Heror >= Enemy[e].Er - 4 && Heror <= Enemy[e].Er + 4)
				{
					herohealth--;

					if (Heroc < Enemy[e].Ec)
					{
						if (map[Heror][Heroc - 5] == ' ' && map[Heror + 3][Heroc - 5] == ' ' && Heroc - 5 > 12)
						{
							Heroc -= 5;
							ballc -= 5;
							dispalyc -= 5;
						}
						else
						{
							if (map[Heror][Heroc - 4] == ' ' && map[Heror + 3][Heroc - 4] == ' ' && Heroc - 4 > 12)
							{
								Heroc -= 4;
								ballc -= 4;
								dispalyc -= 4;
							}
							else
							{
								if (map[Heror][Heroc - 3] == ' ' && map[Heror + 3][Heroc - 3] == ' ' && Heroc - 3 > 12)
								{
									Heroc -= 3;
									ballc -= 3;
									dispalyc -= 3;
								}
								else
								{
									if (map[Heror][Heroc - 2] == ' ' && map[Heror + 3][Heroc - 2] == ' ' && Heroc - 2 > 12)
									{
										Heroc -= 2;
										ballc -= 2;
										dispalyc -= 2;
									}
									else
									{
										if (map[Heror][Heroc - 1] == ' ' && map[Heror + 3][Heroc - 1] == ' ' && Heroc - 1 > 12)
										{
											Heroc -= 1;
											ballc -= 1;
											dispalyc -= 1;
										}
									}
								}
							}
						}


					}
					else
					{
						Heroc += 5;
						ballc += 5;
						dispalyc += 5;
					}
					if (Heroc < 0)
					{
						Heroc = 0;
					}
				}
			}
		}

		/*Abdallah*/
		//Make sure the camera did not fall while hero fall down//
		if (jumpstate == 0 && jumpstateball == 0 && Heror == 35)
		{
			displayr = 20;
		}
		else
		{
			if (jumpstate == 0 && jumpstateball == 0 && Heror == 15)
			{
				displayr = 0;
			}
			else
			{
				if (jumpstate == 0 && jumpstateball == 0 && Heror == 56)
				{
					displayr = 20;
				}
			}
		}
		/*Abdallah*/
		//Gravity for ball//
		if (jumpstateball != 0)
		{
			jumpstateball--;

			if (map[ballr + 3][ballc] == ' ' && map[ballr + 3][ballc + 1] == ' ' && map[ballr + 3][ballc + 2] == ' ' && map[ballr + 3][ballc + 3] == ' ' && map[ballr + 3][ballc + 4] == ' ' && map[ballr + 3][ballc + 5] == ' ' && map[ballr + 3][ballc + 6] == ' ' && map[ballr + 3][ballc + 7] == ' ' && map[ballr + 3][ballc + 8] == ' ')
			{
				ballr++;
				displayr++;
			}
		}
		else
		{
			if (jumpstateball == 0 && map[ballr + 3][ballc] == ' ' && map[ballr + 3][ballc + 1] == ' ' && map[ballr + 3][ballc + 2] == ' ' && map[ballr + 3][ballc + 3] == ' ' && map[ballr + 3][ballc + 4] == ' ' && map[ballr + 3][ballc + 5] == ' ' && map[ballr + 3][ballc + 6] == ' ' && map[ballr + 3][ballc + 7] == ' ' && map[ballr + 3][ballc + 8] == ' ')
			{
				ballr++;
				displayr++;
			}
		}

		/*Abdallah*/
		//Gravity for Hero//
		if (map[Heror + 4][Heroc] != ' ' && map[Heror + 4][Heroc + 1] != ' ' && map[Heror + 4][Heroc + 2] != ' ' && map[Heror + 4][Heroc + 3] != ' ')
		{
			jumpstate = 0;
		}
		if (map[ballr + 3][ballc] != ' ' && map[ballr + 3][ballc + 1] != ' ' && map[ballr + 3][ballc + 2] != ' ' && map[ballr + 3][ballc + 3] != ' ' && map[ballr + 3][ballc + 4] != ' ' && map[ballr + 3][ballc + 5] != ' ' && map[ballr + 3][ballc + 6] != ' ' && map[ballr + 3][ballc + 7] != ' ' && map[ballr + 3][ballc + 8] != ' ')
		{
			jumpstateball = 0;
		}
		if (Heror > displayr + 12 && displayr < 40)
		{
			displayr++;
		}
		else
		{
			if (Heror < displayr + 8 && displayr > 0)
			{
				displayr--;
			}
		}

		/*Kareem abd edited by Abdallah*/
		//Push The hero When The "first floor Enemy" hits him//
		int push = 0;
		if (Enemy[1].Health > 0)
		{
			if (Enemy[1].Health > 120)
			{
				if ((Heroc + 5) >= (Enemy[1].Ec) && (Heroc + 5) <= (Enemy[1].Ec + 5) && (Enemy[1].Er == 9 && Heror == 15 || Enemy[1].Er == 4 && Heror == 10))
				{
					herohealth -= 0.5;

					if (Heroc - Enemy[1].Ec + 20 > 190)
					{
						push = Heroc - Enemy[1].Ec + 10;
						Heroc -= push;
						ballc -= push;
						dispalyc -= push;
					}
					else
					{
						push = (Enemy[1].Ec + 43) - Heroc + 10;
						Heroc += push;
						ballc += push;
						dispalyc += push;
					}

				}
				else
				{
					if ((Heroc + 5) >= (Enemy[1].Ec + 5) && (Heroc + 5) <= (Enemy[1].Ec + 21) && (Enemy[1].Er == 9 && Heror == 15 || Enemy[1].Er == 4 && Heror == 10))
					{
						herohealth -= 1;

						if (Heroc - Enemy[1].Ec + 20 > 190)
						{
							push = Heroc - Enemy[1].Ec + 5;
							Heroc -= push;
							ballc -= push;
							dispalyc -= push;
						}
						else
						{
							push = (Enemy[1].Ec + 43) - Heroc + 5;
							Heroc += push;
							ballc += push;
							dispalyc += push;
						}
					}
					else
					{
						if ((Heroc) <= (Enemy[1].Ec + 43) && (Heroc) >= (Enemy[1].Ec + 38) && (Enemy[1].Er == 9 && Heror == 15 || Enemy[1].Er == 4 && Heror == 10))
						{
							herohealth -= 0.5;

							if ((Enemy[1].Ec + 43) - (Heroc + 10) + 20 < 360)
							{
								push = (Enemy[1].Ec + 43) - Heroc + 20;
								Heroc += push;
								ballc += push;
								dispalyc += push;
							}
							else
							{
								push = Heroc - Enemy[1].Ec + 20;
								Heroc -= push;
								ballc -= push;
								dispalyc -= push;
							}
						}
						else
						{
							if ((Heroc) >= (Enemy[1].Ec + 22) && (Heroc) <= (Enemy[1].Ec + 43) && (Enemy[1].Er == 9 && Heror == 15 || Enemy[1].Er == 4 && Heror == 10))
							{
								herohealth -= 1;

								if ((Enemy[1].Ec + 43) - (Heroc + 10) + 20 < 360)
								{
									push = (Enemy[1].Ec + 43) - Heroc + 20;
									Heroc += push;
									ballc += push;
									dispalyc += push;
								}
								else
								{
									push = Heroc - Enemy[1].Ec + 20;
									Heroc -= push;
									ballc -= push;
									dispalyc -= push;
								}

							}
						}
					}
				}
			}
			else
			{
				if ((Heroc + 5) >= (Enemy[1].Ec) && (Heroc + 5) <= (Enemy[1].Ec + 3) && (Enemy[1].Er == 9 && Heror == 15 || Enemy[1].Er == 4 && Heror == 10))
				{
					herohealth -= 0.5;

					if (Heroc - Enemy[1].Ec + 10 > 190)
					{
						push = Heroc - Enemy[1].Ec + 10;
						Heroc -= push;
						ballc -= push;
						dispalyc -= push;
					}
					else
					{
						push = (Enemy[1].Ec + 19) - Heroc + 10;
						Heroc += push;
						ballc += push;
						dispalyc += push;
					}

				}
				else
				{
					if ((Heroc + 5) >= (Enemy[1].Ec + 3) && (Heroc + 5) <= (Enemy[1].Ec + 14) && (Enemy[1].Er == 9 && Heror == 15 || Enemy[1].Er == 4 && Heror == 10))
					{
						herohealth -= 1;

						if (Heroc - Enemy[1].Ec + 5 > 190)
						{
							push = Heroc - Enemy[1].Ec + 5;
							Heroc -= push;
							ballc -= push;
							dispalyc -= push;
						}
						else
						{
							push = (Enemy[1].Ec + 19) - Heroc + 5;
							Heroc += push;
							ballc += push;
							dispalyc += push;
						}
					}
					else
					{
						if ((Heroc) <= (Enemy[1].Ec + 19) && (Heroc) >= (Enemy[1].Ec + 14) && (Enemy[1].Er == 9 && Heror == 15 || Enemy[1].Er == 4 && Heror == 10))
						{
							herohealth -= 0.5;

							if ((Enemy[1].Ec + 19) - (Heroc + 5) + 20 < 360)
							{
								push = (Enemy[1].Ec + 19) - Heroc + 20;
								Heroc += push;
								ballc += push;
								dispalyc += push;
							}
							else
							{
								push = Heroc - Enemy[1].Ec + 20;
								Heroc -= push;
								ballc -= push;
								dispalyc -= push;
							}


						}
						else
						{
							if ((Heroc) >= (Enemy[1].Ec + 3) && (Heroc) <= (Enemy[1].Ec + 19) && (Enemy[1].Er == 9 && Heror == 15 || Enemy[1].Er == 4 && Heror == 10))
							{
								herohealth -= 1;

								if ((Enemy[1].Ec + 19) - (Heroc + 5) + 20 < 360)
								{
									push = (Enemy[1].Ec + 19) - Heroc + 20;
									Heroc += push;
									ballc += push;
									dispalyc += push;
								}
								else
								{
									push = Heroc - Enemy[1].Ec + 20;
									Heroc -= push;
									ballc -= push;
									dispalyc -= push;
								}

							}
						}
					}
				}
			}
		}

		/*Abdallah*/
		//Stamina for Hero to make sure he will not jump twice "double jump"//
		if (jumpstate != 0)
		{
			jumpstate--;
			if (jumpstate == 0 && stateladder == 0 && map[Heror + 4][Heroc] == ' ' && map[Heror + 4][Heroc + 1] == ' ' && map[Heror + 4][Heroc + 2] == ' ' && map[Heror + 4][Heroc + 3] == ' ' && !(Heror == 15 && Heroc >= 340 && Heroc + 6 <= 347))
			{
				Heror++;
				displayr++;
			}
			state = 4;
		}
		else
		{
			if (jumpstate == 0 && map[Heror + 4][Heroc] == ' ' && map[Heror + 4][Heroc + 1] == ' ' && map[Heror + 4][Heroc + 2] == ' ' && map[Heror + 4][Heroc + 3] == ' ' && stateladder == 0)
			{
				state = 4;
				Heror++;
				displayr++;
			}
			else
			{
				if (jumpstate == 0 && map[Heror + 4][Heroc] != ' ' && map[Heror + 4][Heroc + 1] != ' ' && map[Heror + 4][Heroc + 2] != ' ' && map[Heror + 4][Heroc + 3] != ' ')
				{
					state = 0;
				}
			}
		}
		if (jumpcounter == 2)
		{
			jumpcounter = 7;
		}
		else
		{
			if (jumpcounter == 7)
			{
				jumpcounter--;
			}
			else
			{
				if (jumpcounter == 6)
				{
					jumpcounter--;
				}
				else
				{
					if (jumpcounter == 5)
					{
						jumpcounter--;
					}
					else
					{
						if (jumpcounter == 4)
						{
							jumpcounter--;
						}
						else
						{
							if (jumpcounter == 3)
							{
								jumpcounter = 0;
							}
						}
					}
				}
			}
		}
	}
}
void DrawMap(char map[][360], int& Key, int& opendoor, int keyL, int& movepar, int& movedir, int& bulletA, int shop)
{
	if (shop == 0)
	{
		/*Abdallah*/
		//clear the map and add the HUD//
		for (int r = 0; r < 60; r++)
		{
			for (int c = 0; c < 360; c++)
			{
				map[r][c] = ' ';
			}

		}
		for (int r = 0; r < 360; r++)
		{
			map[19][r] = '=';
		}
		for (int r = 12; r < 360; r++)
		{
			map[39][r] = '=';
		}

		for (int r = 12; r < 360; r++)
		{
			map[59][r] = '=';
		}
		/*Kareem*/
		//Elevator Door//
		for (int r = 22; r < 34; r++)
		{
			map[r][12] = '|';
		}
		if (opendoor == 1)
		{
			for (int r = 34; r < 40; r++)
			{
				map[r][12] = ' ';
			}
			for (int r = 40; r < 55; r++)
			{
				map[r][12] = '|';
			}
			for (int r = 55; r < 60; r++)
			{
				map[r][12] = ' ';
			}
		}
		else
		{
			for (int r = 34; r < 40; r++)
			{
				map[r][12] = '|';
			}
			for (int r = 40; r < 55; r++)
			{
				map[r][12] = '|';
			}
			for (int r = 55; r < 60; r++)
			{
				map[r][12] = '|';
			}
		}

		/*Abdallah*/
		//The Parkour//
		map[38][89] = 248;

		for (int c = 90;c <= 95;c++)
		{
			map[38][c] = 254;
		}

		map[38][96] = 248;

		map[33][100] = 248;

		for (int c = 101;c <= 106;c++)
		{
			map[33][c] = 254;
		}

		map[33][107] = 248;

		map[29][111] = 248;

		for (int c = 112;c <= 117;c++)
		{
			map[29][c] = 254;
		}

		map[29][118] = 248;


		map[33][119] = 248;

		for (int c = 120;c <= 125;c++)
		{
			map[33][c] = 254;
		}

		map[33][126] = 248;


		/*Abdallah*/
		//The moving part of The Parkour//
		map[28][movepar] = 248;

		for (int c = movepar + 1;c <= movepar + 16;c++)
		{
			map[28][c] = 254;
		}

		map[28][movepar + 17] = 248;
		if (movedir == 1 && movepar != 143)
		{
			movepar++;
		}
		else
		{
			movedir = 0;
		}
		if (movedir == 0 && movepar != 131)
		{
			movepar--;
		}
		else
		{
			movedir = 1;
		}
	
		/*Abdallah*/
		//Check if bulletActive cell disappears when player takes it//
		if (bulletA == 0)
		{
			map[27][137] = 207;
		}
		else
		{
			map[27][137] = ' ';
		}

		/*Abdallah*/
		//Boos's room open when player has the key//
		for (int r = 0; r < 19; r++)
		{
			map[r][189] = 186;
		}
		if (keyL == 1)
		{
			for (int r = 0; r < 19; r++)
			{
				map[r][189] = ' ';
			}
		}

		/*Kareem*/
		//draw The ladder and The Names//
		char ladder[18][9] =
		{
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		"|------|",
		};
		int i = 0, j = 0;

		for (int r = 19; r < 37; r++)
		{
			for (int c = 340; c < 348; c++)
			{
				map[r][c] = ladder[i][j];
				j++;
			}
			i++;
			j = 0;
		}

		char kareem[6][35] =
		{
			" _   __                   ___  ___",
			"| | / /                   |  l/  |",
			"| |/ /  __ _ _ __ ___  ___| .  . |",
			"|    l / _` | '__/ _ l/ _ l |l/| |",
			"| |l  l (_| | | |  __/  __l |  | |",
			"l_| l_/l__,_|_|  l___|l___l_|  |_/"
		};

		char Abdallah[6][47] =
		{
			"    ___  _         _       _ _       _        ",
			"   / _ l| |       | |     | | |     | |       ",
			"  / /_l l |__   __| | __ _| | | __ _| |__     ",
			"  |  _  | '_ l / _` |/ _` | | |/ _` | '_ l    ",
			"  | | | | |_) | (_| | (_| | | | (_| | | | |   ",
			"  l_| |_/_.__/ l__,_|l__,_|_|_|l__,_|_| |_|   "
		};

		char Moaz[6][29] =
		{
			"___  ___             ______ ",
			"|  l/  |            |___  / ",
			"| .  . | ___   __ _    / /  ",
			"| |l/| |/ _ l / _` |  / /   ",
			"| |  | | (_) | (_| |./ /___ ",
			"l_|  |_/l___/ l__,_|l_____/ "
		};
		char Thats[6][105] =
		{
			" _____ _           _   _        ______                                    _           _    ________   __",
			"|_   _| |         | | ( )       | ___ l                                  | |         | |   | ___ l l / /",
			"  | | | |__   __ _| |_|/ ___    | |_/ /___ _ __  _ __ ___  ___  ___ _ __ | |_ ___  __| |   | |_/ /l V / ",
			"  | | | '_ l / _` | __| / __|   |    // _ l '_ l| '__/ _ l/ __|/ _ l '_ l| __/ _ l/ _` |   | ___ l l /  ",
			"  | | | | | | (_| | |_  l__ l   | |l l  __/ |_) | | |  __/l__ l  __/ | | | ||  __/ (_| |   | |_/ / | |  ",
			"  l_/ |_| |_|l__,_|l__| |___/   l_| l_l___| .__/|_|  l___||___/l___|_| |_|l__l___|l__,_|   l____/  l_/  "
		};

		char congratiolation[6][94] =
		{
			" ____  ____  _____ ____  ____ _____ _  ____  _     ____ _____ _  ____  _           /l      /l",
			"/   _l/  _ l/  __//  __l/  _ Y__ __Y l/  _ l/ l   /  _ Y__ __Y l/  _ l/ l  /|                ",
			"|  /  | / l|| |  _|  l/|| / l| / l | || / l|| |   | / l| / l | || / l|| |l ||        _____   ",
			"|  l__| l_/|| |_//|    /| |-|| | | | || l_/|| |_/l| |-|| | | | || l_/|| | l||        l____l  ",
			"l____/l____/l____ll_/l_ll_/ l| l_/ l_/l____/l____/l_/ l| l_/ l_/l____/l_/  l|           ",
		};
		i = 0;
		j = 0;
		for (int r = 45; r < 51; r++)
		{
			for (int c = 20; c < 125; c++)
			{
				map[r][c] = Thats[i][j];
				j++;
			}
			i++;
			j = 0;
		}

		i = 0;
		j = 0;
		for (int r = 45; r < 51; r++)
		{
			for (int c = 128; c < 175; c++)
			{
				map[r][c] = Abdallah[i][j];
				j++;
			}
			i++;
			j = 0;
		}

		i = 0;
		j = 0;
		for (int r = 45; r < 51; r++)
		{
			for (int c = 180; c < 209; c++)
			{
				map[r][c] = Moaz[i][j];
				j++;
			}
			i++;
			j = 0;
		}

		i = 0;
		j = 0;
		for (int r = 45; r < 51; r++)
		{
			for (int c = 211; c < 246; c++)
			{
				map[r][c] = kareem[i][j];
				j++;
			}
			i++;
			j = 0;
		}

		i = 0;
		j = 0;
		for (int r = 48; r < 53; r++)
		{
			for (int c = 250; c < 344; c++)
			{
				map[r][c] = congratiolation[i][j];
				j++;
			}
			i++;
			j = 0;
		}

	}


}



void elevator(char map[][360], int& pos, int& dir, int& TimeCounter, int shop)
{
	if (shop == 0)
	{
		/*Moaz and fixed by kareem*/
		if (TimeCounter > 0)
		{
			TimeCounter--;
		}
		else
		{
			pos = pos + dir;

			if (pos >= 20)
			{
				dir = -dir;
				TimeCounter = 50;
			}
			else if (pos <= 0)
			{
				dir = -dir;
				TimeCounter = 50;
			}
		}

		for (int i = 0; i < 10; i++)
		{
			map[39 + pos][i] = '=';
		}
		map[39 + pos][0] = '=';
		map[39 + pos][1] = '=';
		map[39 + pos][2] = '=';
		map[39 + pos][3] = '=';
		map[39 + pos][4] = '=';
		map[39 + pos][5] = '=';
		map[39 + pos][6] = '=';
		map[39 + pos][7] = '=';
		map[39 + pos][8] = '=';
		map[39 + pos][9] = '=';
	}

}
void displaymap(char map[][360], int displayr, int displayc, int Score, int HeroHealth, int bullettype, int bulletA, int shop, int SellMbullet, int MbulletA, int laserA)
{
	system("cls");

	/*Moaz*/
	cout << "===================================== HUD =====================================" << endl;
	cout << "Score: " << Score << "   ";

	cout << "Health: ";
	for (int i = 0; i < HeroHealth; i++)
	{
		cout << "|";
	}
	/*Abdallah*/
	cout << "         " << "Bullet : ";
	if (bulletA == 0)
	{
		cout << "Locked";
	}
	else
	{
		if (bulletA == 1)
		{
			if (bullettype == 0)
			{
				cout << "Single";
			}
			else
			{
				if (MbulletA == 1)
				{
					cout << "Multiple";
				}
				else
				{
					cout << "Locked";
				}
			}
		}
	}
	/*Moaz*/
	cout << "         " << "Laser : ";
	if (laserA == 0)
	{
		cout << "Locked";
	}
	else
	{
		cout << "Active";
	}
	cout << endl;
	cout << "===============================================================================" << endl;
	/*Abdallah*/
	//Shop for player to Active Mbullet or Health//
	if (shop == 0)
	{
		for (int r = displayr; r < displayr + 20; r++)
		{
			for (int c = 0; c < 80; c++)
			{

				int realc = displayc + c;

				if (realc < 360)
				{
					cout << map[r][realc];
				}
				else
				{
					cout << ' ';
				}
			}
			cout << endl;
		}
	}
	else
	{
		if (shop == 1)
		{
			cout << endl << endl;
			cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
			cout << endl << endl;
			cout << "                                      SHOP                                     ";
			cout << endl << endl << endl << endl << endl;
			if (SellMbullet == 0)
			{
				cout << "            Press [G]                                         Press [E]        ";
				cout << "    Multiple Bullets : 150 point                          Health : 50 point    ";
			}
			else
			{
				cout << "                                                              Press [E]        ";
				cout << "            SOLD OUT                                      Health : 50 point    ";
			}
			cout << endl << endl << endl << endl;


			cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&";
		}

	}
}

void bullet(char movement, char map[][360], int& bulletstate, int Heroc, int Heror, int& bulletmovestate, int& bulletc, int characterstate, int& bullettype, int& Mbulletcount, int Mbulletc[30], int Mbulletmovestate[30], int Mbulletstate[30], int& state, int bulletA, int shop, int MbulletA)
{
	/*Abdallah*/
	if (shop == 0)
	{
		//Check if The Character is "HUMAN state" not "BALL state"//
		if (characterstate == 1)
		{
			//Check The Activation//
			if (bulletA == 1)
			{
				//Swap between Single and Miltple//
				if (movement == 'b' || movement == 'B')
				{

					if (bullettype == 0 && (bulletstate != 1 && bulletstate != 2))
					{

						bullettype = 1;
					}
					else
					{
						if (Mbulletcount == 0)
						{
							if (Mbulletstate[Mbulletcount] == 0)
							{
								bullettype = 0;
							}
						}
						else
						{
							if (Mbulletcount > 0)
							{
								if (Mbulletstate[Mbulletcount - 1] == 0)
								{
									bullettype = 0;
								}
							}
						}
					}
				}

				//check The bullet type//
				if (bullettype == 0)
				{
					//shoot to The Right//
					if (movement == 'x' || movement == 'X')
					{
						state = 5;
						if (bulletstate == 0)
						{
							bulletstate = 1;
						}
					}
					else
					{
						//shoot to The Left//
						if (movement == 'z' || movement == 'Z')
						{
							state = 6;
							if (bulletstate == 0)
							{
								bulletstate = 2;
							}
						}
					}
				}
				else
				{

					if (bullettype == 1)
					{
						if (MbulletA == 1)
						{
							if (movement == 'x' || movement == 'X')
							{
								state = 5;
								if (Mbulletcount < 30)
								{
									Mbulletc[Mbulletcount] = 0;
									Mbulletmovestate[Mbulletcount] = 0;
									Mbulletstate[Mbulletcount] = 1;
									Mbulletcount++;
								}
								else
								{
									Mbulletcount = 0;
								}
							}
							else
							{
								if (movement == 'z' || movement == 'Z')
								{
									state = 6;
									if (Mbulletcount < 30)
									{
										Mbulletc[Mbulletcount] = 0;
										Mbulletmovestate[Mbulletcount] = 0;
										Mbulletstate[Mbulletcount] = 2;
										Mbulletcount++;
									}
									else
									{
										Mbulletcount = 0;
									}
								}
							}
						}

					}


				}
			}

		}
	}


}
void laser(char movement, char map[][360], int& laserstate, int& laserA, int& characterstate)
{
	/*Moaz*/
	if (characterstate == 1 && laserA == 1)
	{
		if (movement == 'e' || movement == 'E')
		{
			laserstate = 1;
		}
		if (movement == 'q' || movement == 'Q')
		{
			laserstate = 2;
		}
		if (movement == 'r' || movement == 'R')
		{
			laserstate = 0;
		}
	}
}

void drawbullet(char map[][360], int& bulletstate, int Heroc, int Heror, int& bulletmovestate, int& bulletr, int& bulletc, int displayc, int NumE, Enemies* Enemy, int bullettype)
{
	/*Abdallah*/
	char bullet = '-';
	if (bullettype == 0)
	{
		if (bulletstate == 1)
		{
			if (bulletmovestate == 0)
			{
				if (map[Heror + 2][Heroc + 8] == ' ')
				{
					bulletr = Heror + 2;
					map[bulletr][Heroc + 8] = bullet;
					bulletmovestate = 1;
				}
			}
			else               // Move Right//
			{
				//first Checks if The bullet hits The Screen then check if it hits any enemy Then any obstacle//
				if (bulletmovestate == 1)
				{
					if (((Heroc + 8) + bulletc) < (displayc + 80))
					{
						if (Enemy[0].Health > 0)
						{
							if (Enemy[0].Health > 35)
							{
								if (bulletr >= Enemy[0].Er && bulletr <= (Enemy[0].Er + 4) && ((Heroc + 8) + bulletc) >= Enemy[0].Ec && ((Heroc + 8) + bulletc) <= (Enemy[0].Ec + 12))
								{
									Enemy[0].Health -= 75;
									bulletmovestate = 0;
									bulletstate = 0;
									bulletc = 0;
									bulletr = 0;
								}
							}
							else
							{
								if (Enemy[0].Health <= 35)
								{
									if (bulletr >= Enemy[0].Er && bulletr <= (Enemy[0].Er + 3) && ((Heroc + 8) + bulletc) >= Enemy[0].Ec && ((Heroc + 8) + bulletc) <= (Enemy[0].Ec + 10))
									{
										Enemy[0].Health -= 75;
										bulletmovestate = 0;
										bulletstate = 0;
										bulletc = 0;
										bulletr = 0;
									}
								}
							}
						}
						if (Enemy[1].Health > 0)
						{
							if (Enemy[1].Health > 120)
							{
								if (bulletr >= Enemy[1].Er && bulletr <= (Enemy[1].Er + 9) && ((Heroc + 8) + bulletc) >= Enemy[1].Ec && ((Heroc + 8) + bulletc) <= (Enemy[1].Ec + 43))
								{
									Enemy[1].Health -= 75;
									bulletmovestate = 0;
									bulletstate = 0;
									bulletc = 0;
									bulletr = 0;
								}
							}
							else
							{
								if (Enemy[1].Health <= 120)
								{
									if (bulletr >= Enemy[1].Er && bulletr <= (Enemy[1].Er + 10) && ((Heroc + 8) + bulletc) >= Enemy[1].Ec && ((Heroc + 8) + bulletc) <= (Enemy[1].Ec + 19))
									{
										Enemy[1].Health -= 75;
										bulletmovestate = 0;
										bulletstate = 0;
										bulletc = 0;
										bulletr = 0;
									}
								}
							}
						}
						if (Enemy[2].Health > 0)
						{
							if (bulletr >= Enemy[2].Er && bulletr <= (Enemy[2].Er + 13) && ((Heroc + 8) + bulletc) >= Enemy[2].Ec && ((Heroc + 8) + bulletc) <= (Enemy[2].Ec + 22))
							{
								Enemy[2].Health -= 75;
								bulletmovestate = 0;
								bulletstate = 0;
								bulletc = 0;
								bulletr = 0;
							}

						}
						if (Enemy[3].Health > 0)
						{
							if (Enemy[3].Health > 35)
							{
								if (bulletr >= Enemy[3].Er && bulletr <= (Enemy[3].Er + 4) && ((Heroc + 8) + bulletc) >= Enemy[3].Ec && ((Heroc + 8) + bulletc) <= (Enemy[3].Ec + 12))
								{
									Enemy[3].Health -= 75;
									bulletmovestate = 0;
									bulletstate = 0;
									bulletc = 0;
									bulletr = 0;
								}
							}
							else
							{
								if (Enemy[3].Health <= 35)
								{
									if (bulletr >= Enemy[3].Er && bulletr <= (Enemy[3].Er + 3) && ((Heroc + 8) + bulletc) >= Enemy[3].Ec && ((Heroc + 8) + bulletc) <= (Enemy[3].Ec + 10))
									{
										Enemy[3].Health -= 75;
										bulletmovestate = 0;
										bulletstate = 0;
										bulletc = 0;
										bulletr = 0;
									}
								}
							}
						}






						if (map[bulletr][((Heroc + 8) + bulletc)] == ' ' && bulletmovestate != 0 && bulletstate != 0)
						{
							map[(bulletr)][(Heroc + 8) + bulletc] = bullet;
							bulletc += 3;
						}
						else
						{
							bulletmovestate = 0;
							bulletstate = 0;
							bulletc = 0;
							bulletr = 0;
						}

					}
					else
					{
						bulletmovestate = 0;
						bulletstate = 0;
						bulletc = 0;
						bulletr = 0;
					}
				}
			}
		}
		else
		{
			if (bulletstate == 2)
			{
				if (bulletmovestate == 0)
				{
					if (map[Heror + 2][Heroc - 1] == ' ')
					{
						bulletr = Heror + 2;
						map[bulletr][Heroc - 1] = bullet;
						bulletmovestate = 1;
					}
				}
				else    //Move Left//
				{
					if (bulletmovestate == 1)
					{
						if (((Heroc - 1) + bulletc) > (displayc))
						{
							if (Enemy[0].Health > 0)
							{
								if (Enemy[0].Health > 35)
								{
									if (bulletr >= Enemy[0].Er && bulletr <= (Enemy[0].Er + 4) && ((Heroc - 1) + bulletc) >= Enemy[0].Ec && ((Heroc - 1) + bulletc) <= (Enemy[0].Ec + 12))
									{
										Enemy[0].Health -= 75;
										bulletmovestate = 0;
										bulletstate = 0;
										bulletc = 0;
										bulletr = 0;
									}
								}
								else
								{
									if (Enemy[0].Health <= 35)
									{
										if (bulletr >= Enemy[0].Er && bulletr <= (Enemy[0].Er + 3) && ((Heroc - 1) + bulletc) >= Enemy[0].Ec && ((Heroc - 1) + bulletc) <= (Enemy[0].Ec + 10))
										{
											Enemy[0].Health -= 75;
											bulletmovestate = 0;
											bulletstate = 0;
											bulletc = 0;
											bulletr = 0;
										}
									}
								}
							}
							if (Enemy[1].Health > 0)
							{
								if (Enemy[1].Health > 120)
								{
									if (bulletr >= Enemy[1].Er && bulletr <= (Enemy[1].Er + 9) && ((Heroc - 1) + bulletc) >= Enemy[1].Ec && ((Heroc - 1) + bulletc) <= (Enemy[1].Ec + 43))
									{
										Enemy[1].Health -= 75;
										bulletmovestate = 0;
										bulletstate = 0;
										bulletc = 0;
										bulletr = 0;
									}
								}
								else
								{
									if (Enemy[1].Health <= 120)
									{
										if (bulletr >= Enemy[1].Er && bulletr <= (Enemy[1].Er + 10) && ((Heroc - 1) + bulletc) >= Enemy[1].Ec && ((Heroc - 1) + bulletc) <= (Enemy[1].Ec + 19))
										{
											Enemy[1].Health -= 75;
											bulletmovestate = 0;
											bulletstate = 0;
											bulletc = 0;
											bulletr = 0;
										}
									}
								}
							}
							if (Enemy[2].Health > 0)
							{
								if (bulletr >= Enemy[2].Er && bulletr <= (Enemy[2].Er + 13) && ((Heroc - 1) + bulletc) >= Enemy[2].Ec && ((Heroc - 1) + bulletc) <= (Enemy[2].Ec + 22))
								{
									Enemy[2].Health -= 75;
									bulletmovestate = 0;
									bulletstate = 0;
									bulletc = 0;
									bulletr = 0;
								}
							}
							if (Enemy[3].Health > 0)
							{
								if (Enemy[3].Health > 35)
								{
									if (bulletr >= Enemy[3].Er && bulletr <= (Enemy[3].Er + 4) && ((Heroc - 1) + bulletc) >= Enemy[3].Ec && ((Heroc - 1) + bulletc) <= (Enemy[3].Ec + 12))
									{
										Enemy[3].Health -= 75;
										bulletmovestate = 0;
										bulletstate = 0;
										bulletc = 0;
										bulletr = 0;
									}
								}
								else
								{
									if (Enemy[3].Health <= 35)
									{
										if (bulletr >= Enemy[3].Er && bulletr <= (Enemy[3].Er + 3) && ((Heroc - 1) + bulletc) >= Enemy[3].Ec && ((Heroc - 1) + bulletc) <= (Enemy[3].Ec + 10))
										{
											Enemy[3].Health -= 75;
											bulletmovestate = 0;
											bulletstate = 0;
											bulletc = 0;
											bulletr = 0;
										}
									}
								}
							}
							if (map[bulletr][((Heroc - 1) + bulletc)] == ' ' && bulletmovestate != 0 && bulletstate != 0)
							{
								map[(bulletr)][(Heroc - 1) + bulletc] = bullet;
								bulletc -= 3;
							}
							else
							{
								bulletmovestate = 0;
								bulletstate = 0;
								bulletc = 0;
								bulletr = 0;
							}

						}
						else
						{
							bulletmovestate = 0;
							bulletstate = 0;
							bulletc = 0;
							bulletr = 0;
						}
					}
				}
			}
		}
	}

}
void drawMbullet(char map[][360], int& bulletstate, int Heroc, int Heror, int& bulletmovestate, int& bulletc, int displayc, int NumE, Enemies* Enemy, int bullettype, int Mbulletcount, int Mbulletr[30], int Mbulletc[30], int Mbulletmovestate[30], int Mbulletstate[30])
{
	/*Abdallah*/
	//Do The same as Single bullet//
	char bullet = '-';
	if (bullettype == 1)
	{
		for (int i = 0; i < 30; i++)
		{
			if (Mbulletstate[i] == 1)
			{
				if (Mbulletmovestate[i] == 0)
				{
					if (map[Heror + 2][Heroc + 8] == ' ')
					{
						Mbulletr[i] = Heror + 2;
						map[Mbulletr[i]][Heroc + 8] = bullet;
						Mbulletmovestate[i] = 1;
					}
				}
				else       //To move Right//
				{
					if (Mbulletmovestate[i] == 1)
					{
						if (((Heroc + 8) + Mbulletc[i]) < (displayc + 80))
						{
							if (Enemy[0].Health > 0)
							{
								if (Enemy[0].Health > 35)
								{
									if (Mbulletr[i] >= Enemy[0].Er && Mbulletr[i] <= (Enemy[0].Er + 4) && ((Heroc + 8) + Mbulletc[i]) >= Enemy[0].Ec && ((Heroc + 8) + Mbulletc[i]) <= (Enemy[0].Ec + 12))
									{
										Enemy[0].Health -= 75;
										Mbulletmovestate[i] = 0;
										Mbulletstate[i] = 0;
										Mbulletc[i] = 0;
										Mbulletr[i] = 0;
									}
								}
								else
								{
									if (Enemy[0].Health <= 35)
									{
										if (Mbulletr[i] >= Enemy[0].Er && Mbulletr[i] <= (Enemy[0].Er + 3) && ((Heroc + 8) + Mbulletc[i]) >= Enemy[0].Ec && ((Heroc + 8) + Mbulletc[i]) <= (Enemy[0].Ec + 10))
										{
											Enemy[0].Health -= 75;
											Mbulletmovestate[i] = 0;
											Mbulletstate[i] = 0;
											Mbulletc[i] = 0;
											Mbulletr[i] = 0;
										}
									}
								}
							}
							if (Enemy[2].Health > 0)
							{
								if (Mbulletr[i] >= Enemy[2].Er && Mbulletr[i] <= (Enemy[2].Er + 13) && ((Heroc + 8) + Mbulletc[i]) >= Enemy[2].Ec && ((Heroc + 8) + Mbulletc[i]) <= (Enemy[2].Ec + 22))
								{
									Enemy[2].Health -= 75;
									Mbulletmovestate[i] = 0;
									Mbulletstate[i] = 0;
									Mbulletc[i] = 0;
									Mbulletr[i] = 0;
								}
							}
							if (Enemy[1].Health > 0)
							{
								if (Enemy[1].Health > 120)
								{
									if (Mbulletr[i] >= Enemy[1].Er && Mbulletr[i] <= (Enemy[1].Er + 9) && ((Heroc + 8) + Mbulletc[i]) >= Enemy[1].Ec && ((Heroc + 8) + Mbulletc[i]) <= (Enemy[1].Ec + 43))
									{
										Enemy[1].Health -= 75;
										Mbulletmovestate[i] = 0;
										Mbulletstate[i] = 0;
										Mbulletc[i] = 0;
										Mbulletr[i] = 0;
									}
								}
								else
								{
									if (Enemy[1].Health <= 120)
									{
										if (Mbulletr[i] >= Enemy[1].Er && Mbulletr[i] <= (Enemy[1].Er + 10) && ((Heroc + 8) + Mbulletc[i]) >= Enemy[1].Ec && ((Heroc + 8) + Mbulletc[i]) <= (Enemy[1].Ec + 19))
										{
											Enemy[1].Health -= 75;
											Mbulletmovestate[i] = 0;
											Mbulletstate[i] = 0;
											Mbulletc[i] = 0;
											Mbulletr[i] = 0;
										}
									}
								}
							}


							//Any New Enemy can be added here//


							if (map[Mbulletr[i]][((Heroc + 8) + Mbulletc[i])] == ' ' && Mbulletmovestate[i] != 0 && Mbulletstate[i] != 0)
							{
								map[(Mbulletr[i])][(Heroc + 8) + Mbulletc[i]] = bullet;
								Mbulletc[i] += 3;
							}
							else
							{
								Mbulletmovestate[i] = 0;
								Mbulletstate[i] = 0;
								Mbulletc[i] = 0;
								Mbulletr[i] = 0;
							}

						}
						else
						{
							Mbulletmovestate[i] = 0;
							Mbulletstate[i] = 0;
							Mbulletc[i] = 0;
							Mbulletr[i] = 0;
						}
					}
				}
			}
			else
			{
				if (Mbulletstate[i] == 2)
				{
					if (Mbulletmovestate[i] == 0)
					{
						if (map[Heror + 2][Heroc - 1] == ' ')
						{
							Mbulletr[i] = Heror + 2;
							map[Mbulletr[i]][Heroc - 1] = bullet;
							Mbulletmovestate[i] = 1;
						}
					}
					else    //To Move Left//
					{
						if (Mbulletmovestate[i] == 1)
						{
							if (((Heroc - 1) + Mbulletc[i]) > (displayc))
							{
								if (Enemy[0].Health > 0)
								{
									if (Enemy[0].Health > 35)
									{
										if (Mbulletr[i] >= Enemy[0].Er && Mbulletr[i] <= (Enemy[0].Er + 4) && ((Heroc - 1) + Mbulletc[i]) >= Enemy[0].Ec && ((Heroc - 1) + Mbulletc[i]) <= (Enemy[0].Ec + 12))
										{
											Enemy[0].Health -= 75;
											Mbulletmovestate[i] = 0;
											Mbulletstate[i] = 0;
											Mbulletc[i] = 0;
											Mbulletr[i] = 0;
										}
									}
									else
									{
										if (Enemy[0].Health <= 35)
										{
											if (Mbulletr[i] >= Enemy[0].Er && Mbulletr[i] <= (Enemy[0].Er + 3) && ((Heroc - 1) + Mbulletc[i]) >= Enemy[0].Ec && ((Heroc - 1) + Mbulletc[i]) <= (Enemy[0].Ec + 10))
											{
												Enemy[0].Health -= 75;
												Mbulletmovestate[i] = 0;
												Mbulletstate[i] = 0;
												Mbulletc[i] = 0;
												Mbulletr[i] = 0;
											}
										}
									}
								}
								if (Enemy[2].Health > 0)
								{
									if (Mbulletr[i] >= Enemy[2].Er && Mbulletr[i] <= (Enemy[2].Er + 13) && ((Heroc - 1) + Mbulletc[i]) >= Enemy[2].Ec && ((Heroc - 1) + Mbulletc[i]) <= (Enemy[2].Ec + 22))
									{
										Enemy[2].Health -= 75;
										Mbulletmovestate[i] = 0;
										Mbulletstate[i] = 0;
										Mbulletc[i] = 0;
										Mbulletr[i] = 0;
									}
								}
								if (Enemy[1].Health > 0)
								{
									if (Enemy[1].Health > 120)
									{
										if (Mbulletr[i] >= Enemy[1].Er && Mbulletr[i] <= (Enemy[1].Er + 9) && ((Heroc - 1) + Mbulletc[i]) >= Enemy[1].Ec && ((Heroc - 1) + Mbulletc[i]) <= (Enemy[1].Ec + 43))
										{
											Enemy[1].Health -= 75;
											Mbulletmovestate[i] = 0;
											Mbulletstate[i] = 0;
											Mbulletc[i] = 0;
											Mbulletr[i] = 0;
										}
									}
									else
									{
										if (Enemy[1].Health <= 120)
										{
											if (Mbulletr[i] >= Enemy[1].Er && Mbulletr[i] <= (Enemy[1].Er + 10) && ((Heroc - 1) + Mbulletc[i]) >= Enemy[1].Ec && ((Heroc - 1) + Mbulletc[i]) <= (Enemy[1].Ec + 19))
											{
												Enemy[1].Health -= 75;
												Mbulletmovestate[i] = 0;
												Mbulletstate[i] = 0;
												Mbulletc[i] = 0;
												Mbulletr[i] = 0;
											}
										}
									}
								}



								//Any New Enemy can be added here//


								if (map[Mbulletr[i]][((Heroc - 1) + Mbulletc[i])] == ' ' && Mbulletmovestate[i] != 0 && Mbulletstate[i] != 0)
								{
									map[(Mbulletr[i])][(Heroc - 1) + Mbulletc[i]] = bullet;
									Mbulletc[i] -= 3;
								}
								else
								{
									Mbulletmovestate[i] = 0;
									Mbulletstate[i] = 0;
									Mbulletc[i] = 0;
									Mbulletr[i] = 0;
								}

							}
							else
							{
								Mbulletmovestate[i] = 0;
								Mbulletstate[i] = 0;
								Mbulletc[i] = 0;
								Mbulletr[i] = 0;
							}
						}
					}
				}
			}
		}
	}
}
void drawlaser(char map[][360], int& laserstate, int& Heroc, int& Heror, int& lasermovestate, int& laserc, int& laserr, int& displayc, int& NumE, Enemies* Enemy)
{
	/*Moaz*/
	char beam = '=';
	if (laserstate == 1)
	{
		laserr = Heror + 2;
		for (int c = Heroc + 8; c < 360; c++)
		{

			for (int e = 0; e < NumE; e++)
			{
				if (Enemy[e].Health > 0 &&
					laserr >= Enemy[e].Er &&
					laserr <= Enemy[e].Er + 5 &&
					c >= Enemy[e].Ec &&
					c <= Enemy[e].Ec + 12)
				{
					Enemy[e].Health -= 150;
				}
			}


			if (map[laserr][c] == ' ')
			{
				map[laserr][c] = beam;
			}
			else
			{

				break;
			}
		}
	}
	if (laserstate == 2)
	{
		laserr = Heror + 2;
		for (int c = Heroc - 1; c >= 0; c--)
		{
			for (int e = 0; e < NumE; e++)
			{
				if (Enemy[2].Health > 0 && laserr >= Enemy[2].Er && laserr <= Enemy[2].Er + 13 && c >= Enemy[2].Ec && c <= Enemy[2].Ec + 22)
				{

					Enemy[2].Health -= 4;
				}

			}

			if (map[laserr][c] == ' ')
			{

				map[laserr][c] = beam;
			}
			else
			{

				break;
			}
		}
	}
}

void Drawhero(char map[][360], int Heror, int Heroc, int state, int charcterstate, int& ballr, int& ballc)
{
	/*Abdallah and Kareem*/
	int i, j;
	char defHero[4][7] =
	{
	"  -   ",
	" (-+) ",
	"//II!!",
	"~ ^^  "
	};

	char rightHero[4][7] =
	{
	 "  -   ",
	 " ( -) ",
	 "//->  ",
	 "~ ^   "
	};

	char leftHero[4][7] =
	{
	 "  -   ",
	 " (+ ) ",
	 "  <-!!",
	 "   ^  "
	};

	char upHero[4][7] =
	{
	 "  -   ",
	 " (-+)~",
	 "!!xx//",
	 "  ^^  "
	};

	char downHero[4][7] =
	{
	 "  -   ",
	 " (--) ",
	 "//**!!",
	 "~ ^^  "
	};

	char BulletRHero[4][7] =
	{
	 "  -   ",
	 " ( -) ",
	 "!!# -~",
	 "  ^^  "
	};

	char BulletLHero[4][7] =
	{
	 "  -   ",
	 " (+ ) ",
	 "~- #!!",
	 "  ^^  "
	};

	char ballhero[3][9] =
	{
		 "  ****  ",
		 " ****** ",
		 "  ****  "
	};
	if (charcterstate == 1)
	{
		if (state == 0)
		{
			i = 0;
			j = 0;
			for (int r = Heror; r < (Heror + 4); r++)
			{
				for (int c = Heroc; c < (Heroc + 7); c++)
				{
					if (defHero[i][j] != ' ')
					{
						map[r][c] = defHero[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		if (state == 1)
		{
			i = 0;
			j = 0;
			for (int r = Heror; r < (Heror + 4); r++)
			{
				for (int c = Heroc; c < (Heroc + 7); c++)
				{
					if (rightHero[i][j] != ' ')
					{
						map[r][c] = rightHero[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		if (state == 2)
		{
			i = 0;
			j = 0;
			for (int r = Heror; r < (Heror + 4); r++)
			{
				for (int c = Heroc; c < (Heroc + 7); c++)
				{
					if (leftHero[i][j] != ' ')
					{
						map[r][c] = leftHero[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		if (state == 3)
		{
			i = 0;
			j = 0;
			for (int r = Heror; r < (Heror + 4); r++)
			{
				for (int c = Heroc; c < (Heroc + 7); c++)
				{
					if (upHero[i][j] != ' ')
					{
						map[r][c] = upHero[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		if (state == 4)
		{
			i = 0;
			j = 0;
			for (int r = Heror; r < (Heror + 4); r++)
			{
				for (int c = Heroc; c < (Heroc + 7); c++)
				{
					if (downHero[i][j] != ' ')
					{
						map[r][c] = downHero[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		if (state == 5)
		{
			i = 0;
			j = 0;
			for (int r = Heror; r < (Heror + 4); r++)
			{
				for (int c = Heroc; c < (Heroc + 7); c++)
				{
					if (BulletRHero[i][j] != ' ')
					{
						map[r][c] = BulletRHero[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		if (state == 6)
		{
			i = 0;
			j = 0;
			for (int r = Heror; r < (Heror + 4); r++)
			{
				for (int c = Heroc; c < (Heroc + 7); c++)
				{
					if (BulletLHero[i][j] != ' ')
					{
						map[r][c] = BulletLHero[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}



	}
	else
	{
		if (charcterstate == 0)
		{
			i = 0;
			j = 0;
			for (int r = ballr; r < (ballr + 3); r++)
			{
				for (int c = ballc; c < (ballc + 9); c++)
				{
					map[r][c] = ballhero[i][j];
					j++;
				}
				i++;
				j = 0;
			}
		}
	}
}
void movehero(char movement, char map[][360], int& Heror, int& Heroc, int& displayc, int& displayr, int& state, int& jumpstate, int& jumpcounter, int& characterstate, int& ballr, int& ballc, int& jumpstateball, int& stateladder, int& Key, int& opendoor, Enemies* Enemy, int NumE, int& shop, int& score, int& MbulletA, int& Health, int& SellMbullet)
{
	if (shop == 0)
	{
		/*Abdallah*/
		//Make sure Human is The only state can open Shop//
		if (characterstate == 1)
		{
			if (movement == 'p' || movement == 'P')
			{
				shop = 1;
			}
			/*Kareem*/
			//Open The Elevator Door//
			if (Heroc == 13 || Heroc == 14 && Heror == 35)
			{
				if (movement == 'e' || movement == 'E')
				{
					if (Key == 1)
					{
						if (opendoor == 0)
						{
							opendoor = 1;
						}
					}
				}
			}
			/*Abdallah*/
			if (movement == 'a' || movement == 'A')
			{
				if (Heroc > 0)
				{
					if (Heroc - 1 == 12 && Heror >= 35 && Heror <= 39 && opendoor == 0)
					{
					}
					else
					{
						if (map[Heror][Heroc - 1] == ' ' && map[Heror + 1][Heroc - 1] == ' ' && map[Heror + 2][Heroc - 1] == ' ' && map[Heror + 3][Heroc - 1] == ' '
							&& map[Heror][Heroc - 2] == ' ' && map[Heror + 1][Heroc - 2] == ' ' && map[Heror + 2][Heroc - 2] == ' ' && map[Heror + 3][Heroc - 2] == ' ' || Heroc - 1 >= 340 && Heroc - 1 <= 348)
						{
							Heroc--;
							ballc--;
							if (Heroc <= displayc + 40 && displayc > 0)
							{
								displayc--;
							}
						}
					}
				}
				state = 2;
			}
			if (movement == 'd' || movement == 'D')
			{
				if (Heroc + 7 < 359)
				{
					if (map[Heror][Heroc + 8] == ' ' && map[Heror + 1][Heroc + 8] == ' ' && map[Heror + 2][Heroc + 8] == ' ' && map[Heror + 3][Heroc + 8] == ' ' &&
						map[Heror][Heroc + 9] == ' ' && map[Heror + 1][Heroc + 9] == ' ' && map[Heror + 2][Heroc + 9] == ' ' && map[Heror + 3][Heroc + 9] == ' ' || Heroc + 9 >= 340 && Heroc + 9 <= 348)
					{
						Heroc++;
						ballc++;
						if (Heroc >= displayc + 40 && displayc + 80 < 360)
						{
							displayc++;
						}
					}
				}
				state = 1;
			}

			/*Kareem*/
			if ((movement == 'w' || movement == 'W') && stateladder == 1)
			{
				if (Heror > 0)
				{
					Heror--;
					ballr--;
					displayr--;

				}
				state = 3;

			}
			if ((movement == 's' || movement == 'S') && stateladder == 1)
			{
				if (Heror + 4 < 59 && map[Heror + 4][Heroc] != '=')
				{
					Heror++;
					displayr++;
					if (ballr + 3 < 59 && map[ballr + 3][ballc] != '=')
					{
						ballr++;
					}

				}
				state = 4;
			}

			/*Abdallah*/
			//Press Space to jump//
			//Make sure if there is any obstacle above and jumping depends on the distance between the obstacle and the hero's location// 
			if (movement == ' ')
			{
				if (jumpstate == 0 && jumpcounter <= 2)
				{
					if (map[Heror - 1][Heroc] == ' ' && map[Heror - 2][Heroc] == ' ' && map[Heror - 3][Heroc] == ' '
						&& map[Heror - 1][Heroc + 1] == ' ' && map[Heror - 2][Heroc + 1] == ' ' && map[Heror - 3][Heroc + 1] == ' '
						&& map[Heror - 1][Heroc + 2] == ' ' && map[Heror - 2][Heroc + 2] == ' ' && map[Heror - 3][Heroc + 2] == ' '
						&& map[Heror - 1][Heroc + 3] == ' ' && map[Heror - 2][Heroc + 3] == ' ' && map[Heror - 3][Heroc + 3] == ' '
						&& map[Heror - 1][Heroc + 4] == ' ' && map[Heror - 2][Heroc + 4] == ' ' && map[Heror - 3][Heroc + 4] == ' '
						&& map[Heror - 1][Heroc + 5] == ' ' && map[Heror - 2][Heroc + 5] == ' ' && map[Heror - 3][Heroc + 5] == ' ')
					{
						jumpstate = 3;
						Heror -= 3;
						state = 3;
						jumpcounter++;
						if (displayr - 4 >= 0)
						{
							displayr -= 4;
						}
						else
						{
							displayr = 0;
						}
					}
					else
					{
						if (map[Heror - 1][Heroc] == ' ' && map[Heror - 2][Heroc] == ' '
							&& map[Heror - 1][Heroc + 1] == ' ' && map[Heror - 2][Heroc + 1] == ' '
							&& map[Heror - 1][Heroc + 2] == ' ' && map[Heror - 2][Heroc + 2] == ' '
							&& map[Heror - 1][Heroc + 3] == ' ' && map[Heror - 2][Heroc + 3] == ' '
							&& map[Heror - 1][Heroc + 4] == ' ' && map[Heror - 2][Heroc + 4] == ' '
							&& map[Heror - 1][Heroc + 5] == ' ' && map[Heror - 2][Heroc + 5] == ' ')
						{
							jumpstate = 2;
							Heror -= 2;
							state = 3;
							jumpcounter++;
							if (displayr - 3 >= 0)
							{
								displayr -= 3;
							}
							else
							{
								displayr = 0;
							}
						}
						else
						{
							if (map[Heror - 1][Heroc] == ' '
								&& map[Heror - 1][Heroc + 1] == ' '
								&& map[Heror - 1][Heroc + 2] == ' '
								&& map[Heror - 1][Heroc + 3] == ' '
								&& map[Heror - 1][Heroc + 4] == ' '
								&& map[Heror - 1][Heroc + 5] == ' ')
							{
								jumpstate = 1;
								Heror -= 1;
								state = 3;
								jumpcounter++;
								if (displayr - 2 >= 0)
								{
									displayr -= 2;
								}
								else
								{
									displayr = 0;
								}
							}
							else
							{
							}
						}
					}

				}
			} 
			/*Kareem*/
			//Hits the frist enemy with hand//
			if (movement == 'f' || movement == 'F')
			{
				for (int e = 0; e < NumE; e++)
				{
					if (Enemy[e].Health > 0)
					{
						if (Heroc >= Enemy[e].Ec - 12 && Heroc <= Enemy[e].Ec + 12 && Heror >= Enemy[e].Er - 5 && Heror <= Enemy[e].Er + 5)
						{
							Enemy[e].Health -= 35;
						}
					}
				}
			}
			/*Abdalla*/
			//change the state between HUMAN and BALL//
			if (movement == 'g' || movement == 'G')
			{
				if (jumpstate == 0 && jumpstateball == 0)
				{
					characterstate = 0;
					ballr = Heror + 1;
					ballc = Heroc - 1;
				}
			}

		}
		else
		{
			/*Abdallah*/
			if (characterstate == 0)
			{

				if (ballc >= 0 && ballc + 9 <= 359)
				{
					if (movement == 'a' || movement == 'A')
					{
						if (ballc > 0)
						{
							if (map[ballr][ballc - 1] == ' ' && map[ballr + 1][ballc - 1] == ' ' && map[ballr + 2][ballc - 1] == ' ' && map[ballr][ballc - 2] == ' ' && map[ballr + 1][ballc - 2] == ' ' && map[ballr + 2][ballc - 2] == ' ')
							{
								Heroc -= 2;
								ballc -= 2;

								if (ballc <= displayc + 40 && displayc > 0)
								{
									displayc -= 2;

									if (displayc < 0)
									{
										displayc = 0;

									}
								}
							}

						}
					}
					if (movement == 'd' || movement == 'D')
					{
						if (ballc + 8 <= 359)
						{
							if (map[ballr][ballc + 10] == ' ' && map[ballr + 1][ballc + 10] == ' ' && map[ballr + 2][ballc + 10] == ' ' && map[ballr][ballc + 11] == ' ' && map[ballr + 1][ballc + 11] == ' ' && map[ballr + 2][ballc + 11] == ' ')
							{
								Heroc += 2;
								ballc += 2;

								if (ballc >= displayc + 40 && displayc + 80 < 360)
								{
									displayc += 2;
									if (displayc + 80 > 360)
									{
										displayc = 360 - 80;
									}
								}
							}

						}
					}
				}
				if (characterstate == 0 && jumpstateball == 0 && ballc <= 353)
				{
					if (movement == 'm' || movement == 'M')
					{
						ballr -= 5;
						displayr -= 5;

						ballc += 6;
						displayc += 6;
						jumpstateball = 6;
					}
				}
				if (movement == ' ')
				{
					if (jumpstateball == 0)
					{
						if (map[ballr - 1][ballc] == ' ' && map[ballr - 2][ballc] == ' ' && map[ballr - 3][ballc] == ' ' && map[ballr - 4][ballc] == ' ' && map[ballr - 5][ballc] == ' ' && map[ballr - 6][ballc] == ' '
							&& map[ballr - 1][ballc + 1] == ' ' && map[ballr - 2][ballc + 1] == ' ' && map[ballr - 3][ballc + 1] == ' ' && map[ballr - 4][ballc + 1] == ' ' && map[ballr - 5][ballc + 1] == ' ' && map[ballr - 6][ballc + 1] == ' '
							&& map[ballr - 1][ballc + 2] == ' ' && map[ballr - 2][ballc + 2] == ' ' && map[ballr - 3][ballc + 2] == ' ' && map[ballr - 4][ballc + 2] == ' ' && map[ballr - 5][ballc + 2] == ' ' && map[ballr - 6][ballc + 2] == ' '
							&& map[ballr - 1][ballc + 3] == ' ' && map[ballr - 2][ballc + 3] == ' ' && map[ballr - 3][ballc + 3] == ' ' && map[ballr - 4][ballc + 3] == ' ' && map[ballr - 5][ballc + 3] == ' ' && map[ballr - 6][ballc + 3] == ' '
							&& map[ballr - 1][ballc + 4] == ' ' && map[ballr - 2][ballc + 4] == ' ' && map[ballr - 3][ballc + 4] == ' ' && map[ballr - 4][ballc + 4] == ' ' && map[ballr - 5][ballc + 4] == ' ' && map[ballr - 6][ballc + 4] == ' '
							&& map[ballr - 1][ballc + 5] == ' ' && map[ballr - 2][ballc + 5] == ' ' && map[ballr - 3][ballc + 5] == ' ' && map[ballr - 4][ballc + 5] == ' ' && map[ballr - 5][ballc + 5] == ' ' && map[ballr - 6][ballc + 5] == ' '
							&& map[ballr - 1][ballc + 6] == ' ' && map[ballr - 2][ballc + 6] == ' ' && map[ballr - 3][ballc + 6] == ' ' && map[ballr - 4][ballc + 6] == ' ' && map[ballr - 5][ballc + 6] == ' ' && map[ballr - 6][ballc + 6] == ' '
							&& map[ballr - 1][ballc + 7] == ' ' && map[ballr - 2][ballc + 7] == ' ' && map[ballr - 3][ballc + 7] == ' ' && map[ballr - 4][ballc + 7] == ' ' && map[ballr - 5][ballc + 7] == ' ' && map[ballr - 6][ballc + 7] == ' ')
						{
							jumpstateball = 6;
							ballr -= 6;
							if (displayr - 7 >= 0)
							{
								displayr -= 7;
							}
							else
							{
								displayr = 0;
							}
						}
						else
						{
							if (map[ballr - 1][ballc] == ' ' && map[ballr - 2][ballc] == ' ' && map[ballr - 3][ballc] == ' ' && map[ballr - 4][ballc] == ' ' && map[ballr - 5][ballc] == ' '
								&& map[ballr - 1][ballc + 1] == ' ' && map[ballr - 2][ballc + 1] == ' ' && map[ballr - 3][ballc + 1] == ' ' && map[ballr - 4][ballc + 1] == ' ' && map[ballr - 5][ballc + 1] == ' '
								&& map[ballr - 1][ballc + 2] == ' ' && map[ballr - 2][ballc + 2] == ' ' && map[ballr - 3][ballc + 2] == ' ' && map[ballr - 4][ballc + 2] == ' ' && map[ballr - 5][ballc + 2] == ' '
								&& map[ballr - 1][ballc + 3] == ' ' && map[ballr - 2][ballc + 3] == ' ' && map[ballr - 3][ballc + 3] == ' ' && map[ballr - 4][ballc + 3] == ' ' && map[ballr - 5][ballc + 3] == ' '
								&& map[ballr - 1][ballc + 4] == ' ' && map[ballr - 2][ballc + 4] == ' ' && map[ballr - 3][ballc + 4] == ' ' && map[ballr - 4][ballc + 4] == ' ' && map[ballr - 5][ballc + 4] == ' '
								&& map[ballr - 1][ballc + 5] == ' ' && map[ballr - 2][ballc + 5] == ' ' && map[ballr - 3][ballc + 5] == ' ' && map[ballr - 4][ballc + 5] == ' ' && map[ballr - 5][ballc + 5] == ' '
								&& map[ballr - 1][ballc + 6] == ' ' && map[ballr - 2][ballc + 6] == ' ' && map[ballr - 3][ballc + 6] == ' ' && map[ballr - 4][ballc + 6] == ' ' && map[ballr - 5][ballc + 6] == ' '
								&& map[ballr - 1][ballc + 7] == ' ' && map[ballr - 2][ballc + 7] == ' ' && map[ballr - 3][ballc + 7] == ' ' && map[ballr - 4][ballc + 7] == ' ' && map[ballr - 5][ballc + 7] == ' ')
							{
								jumpstateball = 5;
								ballr -= 5;

								if (displayr - 6 >= 0)
								{
									displayr -= 6;
								}
								else
								{
									displayr = 0;
								}
							}
							else
							{
								if (map[ballr - 1][ballc] == ' ' && map[ballr - 2][ballc] == ' ' && map[ballr - 3][ballc] == ' ' && map[ballr - 4][ballc] == ' '
									&& map[ballr - 1][ballc + 1] == ' ' && map[ballr - 2][ballc + 1] == ' ' && map[ballr - 3][ballc + 1] == ' ' && map[ballr - 4][ballc + 1] == ' '
									&& map[ballr - 1][ballc + 2] == ' ' && map[ballr - 2][ballc + 2] == ' ' && map[ballr - 3][ballc + 2] == ' ' && map[ballr - 4][ballc + 2] == ' '
									&& map[ballr - 1][ballc + 3] == ' ' && map[ballr - 2][ballc + 3] == ' ' && map[ballr - 3][ballc + 3] == ' ' && map[ballr - 4][ballc + 3] == ' '
									&& map[ballr - 1][ballc + 4] == ' ' && map[ballr - 2][ballc + 4] == ' ' && map[ballr - 3][ballc + 4] == ' ' && map[ballr - 4][ballc + 4] == ' '
									&& map[ballr - 1][ballc + 5] == ' ' && map[ballr - 2][ballc + 5] == ' ' && map[ballr - 3][ballc + 5] == ' ' && map[ballr - 4][ballc + 5] == ' '
									&& map[ballr - 1][ballc + 6] == ' ' && map[ballr - 2][ballc + 6] == ' ' && map[ballr - 3][ballc + 6] == ' ' && map[ballr - 4][ballc + 6] == ' '
									&& map[ballr - 1][ballc + 7] == ' ' && map[ballr - 2][ballc + 7] == ' ' && map[ballr - 3][ballc + 7] == ' ' && map[ballr - 4][ballc + 7] == ' ')
								{
									jumpstateball = 4;
									ballr -= 4;

									if (displayr - 5 >= 0)
									{
										displayr -= 5;
									}
									else
									{
										displayr = 0;
									}
								}
								else
								{
									if (map[ballr - 1][ballc] == ' ' && map[ballr - 2][ballc] == ' ' && map[ballr - 3][ballc] == ' '
										&& map[ballr - 1][ballc + 1] == ' ' && map[ballr - 2][ballc + 1] == ' ' && map[ballr - 3][ballc + 1] == ' '
										&& map[ballr - 1][ballc + 2] == ' ' && map[ballr - 2][ballc + 2] == ' ' && map[ballr - 3][ballc + 2] == ' '
										&& map[ballr - 1][ballc + 3] == ' ' && map[ballr - 2][ballc + 3] == ' ' && map[ballr - 3][ballc + 3] == ' '
										&& map[ballr - 1][ballc + 4] == ' ' && map[ballr - 2][ballc + 4] == ' ' && map[ballr - 3][ballc + 4] == ' '
										&& map[ballr - 1][ballc + 5] == ' ' && map[ballr - 2][ballc + 5] == ' ' && map[ballr - 3][ballc + 5] == ' '
										&& map[ballr - 1][ballc + 6] == ' ' && map[ballr - 2][ballc + 6] == ' ' && map[ballr - 3][ballc + 6] == ' '
										&& map[ballr - 1][ballc + 7] == ' ' && map[ballr - 2][ballc + 7] == ' ' && map[ballr - 3][ballc + 7] == ' ')
									{
										jumpstateball = 3;
										ballr -= 3;

										if (displayr - 4 >= 0)
										{
											displayr -= 4;
										}
										else
										{
											displayr = 0;
										}
									}
									else
									{
										if (map[ballr - 1][ballc] == ' ' && map[ballr - 2][ballc] == ' '
											&& map[ballr - 1][ballc + 1] == ' ' && map[ballr - 2][ballc + 1] == ' '
											&& map[ballr - 1][ballc + 2] == ' ' && map[ballr - 2][ballc + 2] == ' '
											&& map[ballr - 1][ballc + 3] == ' ' && map[ballr - 2][ballc + 3] == ' '
											&& map[ballr - 1][ballc + 4] == ' ' && map[ballr - 2][ballc + 4] == ' '
											&& map[ballr - 1][ballc + 5] == ' ' && map[ballr - 2][ballc + 5] == ' '
											&& map[ballr - 1][ballc + 6] == ' ' && map[ballr - 2][ballc + 6] == ' '
											&& map[ballr - 1][ballc + 7] == ' ' && map[ballr - 2][ballc + 7] == ' ')
										{
											jumpstateball = 2;
											ballr -= 2;

											if (displayr - 3 >= 0)
											{
												displayr -= 3;
											}
											else
											{
												displayr = 0;
											}
										}
										else
										{
											if (map[ballr - 1][ballc] == ' '
												&& map[ballr - 1][ballc + 1] == ' '
												&& map[ballr - 1][ballc + 2] == ' '
												&& map[ballr - 1][ballc + 3] == ' '
												&& map[ballr - 1][ballc + 4] == ' '
												&& map[ballr - 1][ballc + 5] == ' '
												&& map[ballr - 1][ballc + 6] == ' '
												&& map[ballr - 1][ballc + 7] == ' ')
											{
												jumpstateball = 1;
												ballr -= 1;

												if (displayr - 2 >= 0)
												{
													displayr -= 2;
												}
												else
												{
													displayr = 0;
												}
											}
											else
											{
											}
										}
									}
								}
							}
						}
					}
				}
				if (movement == 'g' || movement == 'G')
				{
					if (jumpstate == 0 && jumpstateball == 0)
					{
						characterstate = 1;
						Heror = ballr - 1;
						Heroc = ballc + 1;
					}
				}
			}
		}
	}
	else
	{
		if (movement == 'g' || movement == 'G')
		{
			if (score >= 150 && SellMbullet == 0)
			{
				SellMbullet = 1;
				MbulletA = 1;
				score -= 150;
			}
		}
		if (movement == 'e' || movement == 'E')
		{
			if (score >= 50)
			{
				Health++;
				score -= 50;
			}
		}
		if (movement == 'p' || movement == 'P')
		{
			shop = 0;
		}
	}
}



void PutEnemies(Enemies* Enemy, int NumE)
{
	/*Kareem*/
	//Enemy's Data//
	Enemy[0].Er = 34;
	Enemy[0].Ec = 50;
	Enemy[0].Health = 100;
	Enemy[0].maxEc = 80;
	Enemy[0].minEc = 30;

	Enemy[1].Er = 9;
	Enemy[1].Ec = 240;
	Enemy[1].Type = 1;
	Enemy[1].Health = 500;
	Enemy[1].maxEc = 300;
	Enemy[1].minEc = 190;
	Enemy[1].dir = 1;
	Enemy[1].JumpTime = 0;

	Enemy[2].Er = 6;
	Enemy[2].Ec = 50;
	Enemy[2].Type = 2;
	Enemy[2].Health = 2000;
	Enemy[2].maxEc = 150;
	Enemy[2].minEc = 30;
	Enemy[2].dir = 1;
	Enemy[2].JumpTime = 0;

	Enemy[3].Er = 34;
	Enemy[3].Ec = 300;
	Enemy[3].Health = 100;
	Enemy[3].maxEc = 200;
	Enemy[3].minEc = 30;

}
void DrawEnemy(char map[][360], Enemies* Enemy, int NumE, int& keyL, int& Key, int& score, int& E1D, int& E2D, int& Estate, int& E3D, int& E4D, int& laserA)
{
	/*Kareem*/
	//All The draws made by Kareem//
	int i, j;
	char EnemyFullHP[5][13] = {
	 "    ___   ",
	 "   _|O_O|_ ",
	 ">--|__  __| ",
	 "     |_|   ",
	 "    /  ||  "
	};

	char EnemyDameged[4][11] = {
	 "     ___  ",
	 "    |o_o| ",
	 " >---|_|  ",
	 "    /   \\"
	};

	char EnemyLbullet[14][23] =
	{
		"       .    ____/__,",
		"      .' *  / |==l```",
		"     /      77 l |",
		"    /_.----??__,---.",
		"<--()_|_____<__|___| ",
		"    l  ````/|   ``/```",
		"            |____I|",
		"     `.   / !!!!!!! ",
		"       , /  | | I |",
		"            | | I |",
		"            | | I |",
		"            | | I |",
		"           _|_|_I_| ",
		"          /__/____|"
	};

	char EnemyRbullet[14][23] =
	{
		"    ,___l___   /  ",
		"      /==/ l  /   '",
		"      | /8 8 /      l",
		".-----,___//------_.l",
		"l____|__>______|_/)-->",
		" ``l```    |l```  ",
		"    |____I| l     ",
		"    !!!!!!!  l   ",
		"    |  | I|   l  ,",
		"    |  | I|    l .",
		"    |  | I|      ",
		"    |  | I|      ",
		"    |_|_I_|_     ",
		"    |__l____l   "

	};
	char EnemyLmove[14][24] =
	{
		"           ____/__,",
		"          / l==l```",
		"          77 l | ",
		"{=_=--.----ll__,-----.",
		" {l_|___|___<__|___| |",
		"          |    I|  |_|",
		"          !!!!!!!   O",
		"          | | I |",
		"          | | I |",
		"          | | I |",
		"          | | I |",
		"         _|_|_I_|",
		"        /__/____|"
	};
	char EnemyRmove[14][23] =
	{
		"    ,___l___   ",
		"      /==/ l",
		"      l /8 8| ",
		" .___//,___---,___=_+}",
		" | |_l____|__>__|_|_/}",
		" |_|  |`````|`````` ",
		"  O   |____I|",
		"      !!!!!!!",
		"      | | I |",
		"      | | I |",
		"      | | I |",
		"      | | I |",
		"      |_|_I_|_",
		"      |__l____l"

	};

	char EnemykeyRoomFull[10][44] =
	{
		"         __________________",
		"      ____|++============++|____",
		"     |      @@        @@     |",
		"     |           _~,_        |____,____)",
		" ____|====================================>",
		"|####|   _____    _____    _____   |###",
		"|####|  |_____|  |_____|  |_____|  |###",
		"|####|*****************************|###",
		"|____|_____________________________|___|",
		"   |-|                           |_|   "
	};
	char EnemykeyRoomDameged[11][20] =
	{
		" _______  ",
		"|+-----+|",
		"| 0   0 |  ",
		"| --^-- | ",
		"|-------|",
		"| ``` & |____,_)  ",
		"|-------|-------->",
		"| $  ,,,|~~~8",
		"|*******| & |",
		"|_______|~~~8",
		"  |   |"
	};



	if (Enemy[0].Health > 0)
	{
		int r = Enemy[0].Er;
		int c = Enemy[0].Ec;

		if (Enemy[0].Health > 35)
		{
			i = 0;
			j = 0;
			for (int row = r; row < (r + 5); row++)
			{
				for (int col = c; col < (c + 12); col++)
				{
					if (EnemyFullHP[i][j] != ' ')
					{
						map[row][col] = EnemyFullHP[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		else
		{
			i = 0;
			j = 0;
			for (int row = r; row < (r + 4); row++)
			{
				for (int col = c; col < (c + 10); col++)
				{
					if (EnemyDameged[i][j] != ' ')
					{
						map[row][col] = EnemyDameged[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
	}
	else
	{
		if (E1D == 0)
		{
			score += 25;
			E1D = 1;
		}
	}
	if (Enemy[3].Health > 0)
	{
		int r = Enemy[3].Er;
		int c = Enemy[3].Ec;

		if (Enemy[3].Health > 35)
		{
			i = 0;
			j = 0;
			for (int row = r; row < (r + 5); row++)
			{
				for (int col = c; col < (c + 12); col++)
				{
					if (EnemyFullHP[i][j] != ' ')
					{
						map[row][col] = EnemyFullHP[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		else
		{
			i = 0;
			j = 0;
			for (int row = r; row < (r + 4); row++)
			{
				for (int col = c; col < (c + 10); col++)
				{
					if (EnemyDameged[i][j] != ' ')
					{
						map[row][col] = EnemyDameged[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
	}
	else
	{
		if (E3D == 0)
		{
			score += 25;
			E3D = 1;
		}
	}

	if (Enemy[1].Health > 0)
	{
		int r = Enemy[1].Er - 1;
		int c = Enemy[1].Ec;

		if (Enemy[1].Health > 120)
		{
			i = 0;
			j = 0;
			for (int row = r; row < (r + 10); row++)
			{
				for (int col = c; col < (c + 44); col++)
				{
					if (row < 60 && col < 360 && EnemykeyRoomFull[i][j] != ' ')
					{
						map[row][col] = EnemykeyRoomFull[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}
		}
		else
		{
			i = 0; j = 0;
			for (int row = r; row < (r + 11); row++)
			{
				for (int col = c; col < (c + 20); col++)
				{
					if (row < 60 && col < 360 && EnemykeyRoomDameged[i][j] != ' ')
					{
						map[row][col] = EnemykeyRoomDameged[i][j];
					}
					j++;
				}
				i++; j = 0;
			}
		}
	}
	else
	{
		keyL = 1;
		Key = 1;
		laserA = 1;
		if (E2D == 0)
		{
			score += 150;
			E2D = 1;
		}
	}

	if (Enemy[2].Health > 0 && Enemy[2].Type == 2)
	{
		if (Estate == 1)
		{
			int r = Enemy[2].Er - 1;
			int c = Enemy[2].Ec;
			i = 0;
			j = 0;
			for (int row = r; row < (r + 14); row++)
			{
				for (int col = c; col < (c + 23); col++)
				{
					if (row < 60 && col < 360 && EnemyLbullet[i][j] != ' ')
					{
						map[row][col] = EnemyLbullet[i][j];
					}
					j++;
				}
				i++;
				j = 0;
			}

		}
		if (Estate == 2)
		{
			if (Enemy[2].Health > 0)
			{
				int r = Enemy[2].Er - 1;
				int c = Enemy[2].Ec;
				i = 0;
				j = 0;
				for (int row = r; row < (r + 14); row++)
				{
					for (int col = c; col < (c + 23); col++)
					{
						if (row < 60 && col < 360 && EnemyRbullet[i][j] != ' ')
						{
							map[row][col] = EnemyRbullet[i][j];
						}
						j++;
					}
					i++;
					j = 0;
				}
			}
		}


		if (Estate == 3)
		{
			if (Enemy[2].Health > 0)
			{
				int r = Enemy[2].Er - 1;
				int c = Enemy[2].Ec;
				i = 0;
				j = 0;
				for (int row = r; row < (r + 14); row++)
				{
					for (int col = c; col < (c + 23); col++)
					{
						if (map[row][col] == ' ' && EnemyLmove[i][j] != ' ')
						{
							map[row][col] = EnemyLmove[i][j];
						}
						j++;
					}
					i++;
					j = 0;
				}
			}
		}
		if (Estate == 0)
		{
			if (Enemy[2].Health > 0)
			{
				int r = Enemy[2].Er - 1;
				int c = Enemy[2].Ec;
				i = 0;
				j = 0;
				for (int row = r; row < (r + 14); row++)
				{
					for (int col = c; col < (c + 23); col++)
					{
						if (map[row][col] == ' ' && EnemyRmove[i][j] != ' ')
						{
							map[row][col] = EnemyRmove[i][j];
						}
						j++;
					}
					i++;
					j = 0;
				}
			}
		}

	}
	else
	{
		if (E4D == 0)
		{
			E4D = 1;
			score += 200;
		}
	}



}
void MoveEnemy(char map[][360], Enemies* enemy, int NumE, int shop, int& E20M, int& E10M, int& PNM, int& PosPN, int& Estate, int& ENH, int& EHS, int Heroc, int& EBC, int& EBR, int displayc, int& EBS, int Heror, int characterstate, int& herohealth, int& E3D)
{
	if (shop == 0)
	{
		/*Kareem*/
		for (int e = 0; e < NumE; e++)
		{
			if (enemy[e].Health > 0)
			{
				int randomMove = rand() % 6;

				if (randomMove == 1)
				{
					if (enemy[e].Health > 35)
					{
						if (map[enemy[e].Er][enemy[e].Ec + 12] == ' ' && map[enemy[e].Er][enemy[e].Ec + 16] == ' '
							&& map[enemy[e].Er + 4][enemy[e].Ec + 12] == ' ' && map[enemy[e].Er + 4][enemy[e].Ec + 16] == ' ')
						{
							if (enemy[e].Ec + 12 < 360)
							{
								enemy[e].Ec += 4;
							}
						}
					}
					else
					{
						if (map[enemy[e].Er][enemy[e].Ec + 10] == ' ' && map[enemy[e].Er][enemy[e].Ec + 14] == ' '
							&& map[enemy[e].Er + 3][enemy[e].Ec + 10] == ' ' && map[enemy[e].Er + 3][enemy[e].Ec + 14] == ' ')
						{
							if (enemy[e].Ec + 12 < 360)
							{
								enemy[e].Ec += 4;
							}
						}
					}

				}
				if (randomMove == 2)
				{
					if (enemy[e].Health > 35)
					{
						if (map[enemy[e].Er][enemy[e].Ec - 4] == ' ' && map[enemy[e].Er][enemy[e].Ec - 16] == ' '
							&& map[enemy[e].Er + 4][enemy[e].Ec - 4] == ' ' && map[enemy[e].Er + 4][enemy[e].Ec - 16] == ' ')
						{
							if (enemy[e].Ec - 12 > 0)
							{
								enemy[e].Ec -= 4;
							}
						}
					}
					else
					{
						if (map[enemy[e].Er][enemy[e].Ec - 4] == ' ' && map[enemy[e].Er][enemy[e].Ec - 14] == ' '
							&& map[enemy[e].Er + 3][enemy[e].Ec - 4] == ' ' && map[enemy[e].Er + 3][enemy[e].Ec - 14] == ' ')
						{
							if (enemy[e].Ec + 12 < 360)
							{
								enemy[e].Ec -= 4;
							}
						}
					}

				}

			}
			if (enemy[e].Type == 1)
			{
				if (enemy[e].Health > 0)
				{

					enemy[e].Ec += (enemy[e].dir * 1);
					if (enemy[e].Ec >= enemy[e].maxEc)
					{
						enemy[e].dir = -1;
					}
					else if (enemy[e].Ec <= enemy[e].minEc)
					{
						enemy[e].dir = 1;
					}


					if (enemy[e].JumpTime == 0)
					{
						int randomJump = rand() % 10;

						if (randomJump == 3)
						{
							enemy[e].JumpTime = 22;
							enemy[e].Er -= 5;
						}
					}
					else
					{
						enemy[e].JumpTime--;

						if (enemy[e].JumpTime == 0)
						{
							enemy[e].Er += 5;
						}
					}


				}
			}
			/*Abdallah*/
			//"Final Boss" Moves//
			//Depends on The player's movements//
			if (enemy[e].Type == 2 && enemy[e].Health > 0)
			{
				if (ENH == 0)
				{
					if (E10M == 1)
					{
						if (PNM == 1)
						{
							if (PosPN <= 20)
							{
								if (map[enemy[2].Er][enemy[2].Ec + 23] == ' ')
								{
									Estate = 0;
									PosPN++;
									enemy[2].Ec++;
								}
							}
							else
							{
								if (enemy[2].Ec - 40 >= enemy[2].minEc)
								{
									E10M = 0;
									E20M = 1;
									PNM = 0;
									PosPN = 0;
								}
								else
								{
									if (enemy[2].Ec - 20 >= enemy[2].minEc)
									{
										E10M = 1;
										E20M = 0;
										PNM = 0;
										PosPN = 0;
									}
									else
									{
										if (enemy[2].Ec + 40 <= enemy[2].maxEc)
										{
											E10M = 0;
											E20M = 1;
											PNM = 1;
											PosPN = 0;
										}
										else
										{
											if (enemy[2].Ec + 20 <= enemy[2].maxEc)
											{
												E10M = 1;
												E20M = 0;
												PNM = 1;
												PosPN = 0;
											}
										}
									}
								}
							}
						}
						else
						{
							if (PNM == 0)
							{
								if (PosPN >= -20)
								{
									if (map[enemy[2].Er][enemy[2].Ec - 1] == ' ')
									{
										Estate = 3;
										PosPN--;
										enemy[2].Ec--;
									}
								}
								else
								{
									if (enemy[2].Ec + 40 <= enemy[2].maxEc)
									{
										E10M = 0;
										E20M = 1;
										PNM = 1;
										PosPN = 0;
									}
									else
									{
										if (enemy[2].Ec + 20 <= enemy[2].maxEc)
										{
											E10M = 1;
											E20M = 0;
											PNM = 1;
											PosPN = 0;
										}
										else
										{
											if (enemy[2].Ec - 40 >= enemy[2].minEc)
											{
												E10M = 0;
												E20M = 1;
												PNM = 0;
												PosPN = 0;
											}
											else
											{
												if (enemy[2].Ec - 20 >= enemy[2].minEc)
												{
													E10M = 1;
													E20M = 0;
													PNM = 0;
													PosPN = 0;
												}
											}
										}
									}
								}
							}
						}

					}
					else
					{
						if (E20M == 1)
						{
							if (PNM == 1)
							{
								if (PosPN <= 40)
								{
									if (map[enemy[2].Er][enemy[2].Ec + 23] == ' ')
									{
										Estate = 0;
										PosPN++;
										enemy[2].Ec++;
									}

								}
								else
								{
									if (enemy[2].Ec - 20 >= enemy[2].minEc)
									{
										E10M = 1;
										E20M = 0;
										PNM = 0;
										PosPN = 0;
									}
									else
									{
										if (enemy[2].Ec - 40 >= enemy[2].minEc)
										{
											E10M = 0;
											E20M = 1;
											PNM = 0;
											PosPN = 0;
										}
										else
										{
											if (enemy[2].Ec + 20 <= enemy[2].maxEc)
											{
												E10M = 1;
												E20M = 0;
												PNM = 1;
												PosPN = 0;
											}
											else
											{
												if (enemy[2].Ec + 40 <= enemy[2].maxEc)
												{
													E10M = 0;
													E20M = 1;
													PNM = 1;
													PosPN = 0;
												}
											}
										}
									}
								}
							}
							else
							{
								if (PNM == 0)
								{
									if (PosPN >= -40)
									{
										if (map[enemy[2].Er][enemy[2].Ec - 1] == ' ')
										{
											Estate = 3;
											PosPN--;
											enemy[2].Ec--;
										}

									}
									else
									{
										if (enemy[2].Ec + 20 <= enemy[2].maxEc)
										{
											E10M = 1;
											E20M = 0;
											PNM = 1;
											PosPN = 0;
										}
										else
										{
											if (enemy[2].Ec + 40 <= enemy[2].maxEc)
											{
												E10M = 0;
												E20M = 1;
												PNM = 1;
												PosPN = 0;
											}
											else
											{
												if (enemy[2].Ec - 20 >= enemy[2].minEc)
												{
													E10M = 1;
													E20M = 0;
													PNM = 0;
													PosPN = 0;
												}
												else
												{
													if (enemy[2].Ec - 40 >= enemy[2].minEc)
													{
														E10M = 0;
														E20M = 1;
														PNM = 0;
														PosPN = 0;
													}
												}
											}
										}
									}
								}
							}
						}

					}
				}
				else
				{
					if (PosPN != 0)
					{
						PosPN = 0;
						E20M = 0;
						E10M = 1;
						PNM = 1;
						PosPN = 0;
					}
					EHS = Heroc - (enemy[2].Ec + 22);
					if (EHS > 20)
					{
						if (enemy[2].Ec - 1 > 0)
						{
							if (map[enemy[2].Er][enemy[2].Ec + 23] == ' ')
							{
								Estate = 0;
								enemy[2].Ec++;
								enemy[2].maxEc++;
								enemy[2].minEc++;
							}

						}
					}
					else
					{
						if (EHS < 20)
						{
							if (enemy[2].Ec + 1 < 180)
							{
								if (map[enemy[2].Er][enemy[2].Ec - 1] == ' ')
								{
									Estate = 3;
									enemy[2].Ec--;
									enemy[2].maxEc--;
									enemy[2].minEc--;
								}

							}
						}

					}
					if (EHS >= 20)
					{
						Estate = 2;
						if (EBS == 0)
						{
							EBS = 1;
							EBR = enemy[2].Er + 4;
							EBC = enemy[2].Ec + 24;
						}
						else
						{
							if (EBS == 1)
							{
								if (map[EBR][EBC] == ' ')
								{
									if (EBC > displayc && EBC < 360)
									{
										if (EBC >= Heroc && EBC <= Heroc + 6 && EBR >= Heror && EBR <= Heror + 3 && characterstate == 1)
										{
											EBS = 0;
											EBR = 0;
											EBC = 0;
											herohealth -= 2;
										}
										else
										{
											map[EBR][EBC] = '>';
											EBC += 4;
											if (EBR != 15)
											{
												EBR++;
											}
										}


									}
									else
									{
										EBS = 0;
										EBR = 0;
										EBC = 0;
									}
								}
								else
								{
									EBS = 0;
									EBR = 0;
									EBC = 0;
								}
							}
						}



					}

				}

			}

		}
	}


}



int main()
{
	//"Final Boss"//
	int E20M = 0;
	int E10M = 1;
	int PNM = 1;
	int PosPN = 0;
	int ENH = 0;
	int EHS = 0;
	int EBC = 0;
	int EBR = 0;
	int EBS = 0;



	//Mbullet//
	int Mbulletcount = 0;
	int Mbulletc[30];
	int Mbulletr[30];
	int Mbulletmovestate[30];
	int Mbulletstate[30];
	for (int i = 0;i < 30;i++)
	{
		Mbulletc[i] = 0;
		Mbulletr[i] = 0;
		Mbulletmovestate[i] = 0;
		Mbulletstate[i] = 0;
	}
	int MbulletA = 0;

	//bullet//
	int bulletstate = 0;
	int bulletmovestate = 0;
	int bulletc = 0;
	int bulletr = 0;
	int bullettype = 0;
	int bulletA = 0;

	int keyL = 0;

	int ct = 1;

	int E1D = 0;
	int E2D = 0;
	int E3D = 0;
	int E4D = 0;

	int movepar = 131;
	int pardir = 1;


	int Shop = 0;
	int SellMbullet = 0;

	char map[60][360];
	int displayr = 20, displayc = 20;
	char movement;
	int pos = 1;
	int dir = 1;
	int Heror = 35, Heroc = 20;
	int herohealth = 10;
	int state = 0;
	int Estate = 0;
	int jumpstate = 0, jumpstateball = 0;
	int jumpcounter = 0;
	int characterstate = 1;
	int ballr = 36, ballc = 270;
	int stateladder = 0;
	//score and health board//
	int score = 0;
	// laser //
	int laserA = 0;
	int laserstate = 0;
	int lasermovestate = 0;
	int laserr = 0;
	int laserc = 0;

	// Enemies //
	int NumE = 4;
	Enemies* Enemy = new Enemies[NumE];
	PutEnemies(Enemy, NumE);
	int opendoor = 0;
	int Key = 0;
	int TimeCounter = 0;
	while (1)
	{
		while (!_kbhit())
		{
			DrawMap(map, Key, opendoor, keyL, movepar, pardir, bulletA, Shop);
			elevator(map, pos, dir, TimeCounter, Shop);
			Drawhero(map, Heror, Heroc, state, characterstate, ballr, ballc);
			DrawEnemy(map, Enemy, NumE, keyL, Key, score, E1D, E2D, Estate, E3D, E4D, laserA);
			MoveEnemy(map, Enemy, NumE, Shop, E20M, E10M, PNM, PosPN, Estate, ENH, EHS, Heroc, EBC, EBR, displayc, EBS, Heror, characterstate, herohealth, E3D);
			drawMbullet(map, bulletstate, Heroc, Heror, bulletmovestate, bulletc, displayc, NumE, Enemy, bullettype, Mbulletcount, Mbulletr, Mbulletc, Mbulletmovestate, Mbulletstate);
			drawlaser(map, laserstate, Heroc, Heror, lasermovestate, laserc, laserr, displayc, NumE, Enemy);
			drawbullet(map, bulletstate, Heroc, Heror, bulletmovestate, bulletr, bulletc, displayc, NumE, Enemy, bullettype);
			displaymap(map, displayr, displayc, score, herohealth, bullettype, bulletA, Shop, SellMbullet, MbulletA, laserA);
			logic(map, jumpstate, Heror, herohealth, Heroc, state, jumpcounter, ballr, ballc, jumpstateball, stateladder, displayr, pos, Enemy, NumE, displayc, bulletA, Shop, ENH, ct);
			Sleep(70);
		}
		movement = _getch();
		bullet(movement, map, bulletstate, Heroc, Heror, bulletmovestate, bulletc, characterstate, bullettype, Mbulletcount, Mbulletc, Mbulletmovestate, Mbulletstate, state, bulletA, Shop, MbulletA);
		laser(movement, map, laserstate, laserA, characterstate);
		movehero(movement, map, Heror, Heroc, displayc, displayr, state, jumpstate, jumpcounter, characterstate, ballr, ballc, jumpstateball, stateladder, Key, opendoor, Enemy, NumE, Shop, score, MbulletA, herohealth, SellMbullet);

		if (herohealth <= 0 && ct == 3)
		{
			delete[]Enemy;
			break;
		}
		else
		{
			if (Heroc == 350 && Heror == 55)
			{
				delete[]Enemy;
				break;
			}
		}
	}
	return 0;
}