#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct teamates {
	char *teamname;
	int id;
	int weapon;
	int life;
} teamate;


int main()
{
	int change; // 게임에서 이긴 선수의 무기를 바꿀지 입력받는 변수. 바꾸려면 0, 바꾸지 않으려면 1을 받는다.
	int number = 3; // 게임을 진행할 각 팀의 선수의 수.
	int flag = 1;; // flag는 우리팀과 상대팀의 게임턴을 나누기 위해서 만든 변수이다.
	srand(time (NULL)); // 무기를 난수를 발생시켜서 입력하였는데, time을 사용하여 변수가 실행할 때마다 달라지게 설정하였다.

	int probability = rand()%2; // change변수로 이긴 선수의 무기를 바꿀지 말지 입력받아서 50%의 확률로 무기가 바뀌게 설정하여야 하는데, 이것을 probablilty라는 변수로 받아서 사용하였다. 이 변수가 0일 때는 바뀌지 않고, 1일 땐 무기가 바뀌도록 설정하였다.

	printf("Player Number : %d \n\n", number); // 각 팀의 선수가 몇명인지 출력한다.

	int Weapon_Scissor = 1;
	int Weapon_Stone = 2;
	int Weapon_Paper = 3;

	int opponent = 0; // 경쟁자가 누구인지 알려주는 변수
	int Amor_Life; // Amor팀의 생명의 총합을 나타내기 위한 변수. 이후에 player1~3의 생명을 합쳐 출력한다.
	int Fati_Life; // Fati팀의 생명의 총합을 나타내기 위한 변수. 이후에 player4~6의 생명을 합쳐 출력한다.


	// struct teamates를 사용하여 각각 player의 정보를 입력하였다. player1~6까지의 정보가 전부 담겨있다.
	struct teamates player1;
	player1.teamname = "Amor";
	player1.id = 1001;
	player1.weapon = (rand()%3 + 1);
	player1.life = 1;

	struct teamates player2;
	player2.teamname = "Amor";
	player2.id = 1002;
	player2.weapon = (rand()%3 + 1);
	player2.life = 1;

	struct teamates player3;
	player3.teamname = "Amor";
	player3.id = 1003;
	player3.weapon = (rand()%3 + 1);
	player3.life = 1;

	struct teamates player4;
	player4.teamname = "Fati";
	player4.id = 2004;
	player4.weapon = (rand()%3 + 1);
	player4.life = 1;

	struct teamates player5;
	player5.teamname = "Fati";
	player5.id = 2005;
	player5.weapon = (rand()%3 + 1);
	player5.life = 1;

	struct teamates player6;
	player6.teamname = "Fati";
	player6.id = 2006;
	player6.weapon = (rand()%3 + 1);
	player6.life = 1;


	// 그 뒤 우리팀의 무기 정보를 출력한다.
	printf("player1's Weapon : %d \n", player1.weapon);
	printf("player2's Weapon : %d \n", player2.weapon);
	printf("player3's Weapon : %d \n", player3.weapon);

	//맨 처음 player1이 게임을 시작한다.
	printf ("Player1 start Game. \n");

	// 그 후 player1이 상대방팀의 선수 중 누구와 싸울지 ID를 입력받는다.
	printf ("Select Opponent ID (2004, 2005, 2006) : \n");
	scanf ("%d", &opponent);



	// do-while문을 사용하여 전체 게임의 반복을 설정한다. 이 가위바위보 게임은 Amor_Life나 Fati_Life가 0이되기 전 까지 진행한다.(조건)
	do {

		do {


			// 이 반복문은 opponent가 각각 player4, 5, 6일 때 경우의 수를 담은 것이다.

			if (opponent == player4.id){
				// 경쟁자가 player4이고, 이 때 player4의 생명력이 0이 아니면 실행되는 조건문이다.
				if (player4.life != 0) {
					printf ("Player1's Opponent : Player4 \n");
					printf("\n");

					// 아래 switch문은 player1의 무기가 각각 가위, 바위, 보일 때의 경우를 case 1,2,3으로 나누어서 모든 경우의 수를 생각하여 짠 코드이다.
					draw1 :
						switch (player1.weapon) {
						case 1:
							if (player4.weapon == Weapon_Scissor){
								printf("Player1 : Scissor, Player4 : Scissor \n");
								printf("draws \n");
								//비겼을 땐 두 선수의 무기를 다시 랜덤으로 재설정한 뒤 draw1이라고 설정해 놓은 곳으로 돌아가 다시 switch문을 반복한다.
								player1.weapon = (rand()%3 + 1);
								player4.weapon = (rand()%3 + 1);
								goto draw1;
							}
							else if (player4.weapon >= Weapon_Scissor ) {
								if (player4.weapon == Weapon_Stone) {
									printf("Player1 : Scissor, Player4 : Stone \n");
									printf("Player1 : Loser, Player4 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									//player1이 졌을 땐 생명력을 0으로 다시 저장하고, 상대방에게 무기를 바꿀것인지 아닌지 물어보는데, 우리팀이 아니므로 이 질문은 그들에게 보여야한다. 하지만 우리는 게임마스터가 아니므로 그들이 항상 바꾼다고 마음먹었다고 가정 후 50%의 확률로 무기를 바뀌게 설정하였다.
									player1.life = 0;

									if (probability == 1) {
										player4.weapon = player1.weapon;
										printf("Change the Weapon. \n"); //바꾸는데 성공하면 무기가 바뀌었다고 문구를 출력한다.
									}
									break; // 반복문을 빠져나간다.
								}

								else if (player4.weapon == Weapon_Paper) {
									printf("Player1 : Scissor, Player4 : Paper \n");
									printf("Player1 : Winner, Player4 : Loser \n");
									printf("Player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");// 우리팀이 이겼을 땐 무기를 바꿀지 물어보는 문구를 출력한다.
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);// 그 후 무기가 바뀌었다면, 우리팀에겐 바뀐 무기가 무엇인지 출력된다.
										}
									}
									break;
								}
								break;
							}
							break;

						case 2:
							if (player4.weapon == Weapon_Stone){
								printf("Player1 : Stone, Player4 : Stone \n");
								printf("draws \n");
								player1.weapon = (rand()%3 + 1);
								player4.weapon = (rand()%3 + 1);
								goto draw1;
							}
							else if (player4.weapon >= Weapon_Scissor ) {
								if (player4.weapon == Weapon_Scissor) {
									printf("Player1 : Stone, Player4 : Scissor \n");
									printf("Player1 : Winner, Player4 : Loser \n");
									printf("Player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}
									break;
								}
								else if (player4.weapon == Weapon_Paper) {
									printf("Player1 : Stone, Player4 : Paper \n");
									printf("Player1 : Loser, Player4 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player4.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								break;
							}
							break;


						case 3:
							if (player4.weapon == Weapon_Paper){
								printf("Player1 : Paper, Player4 : Paper \n");
								printf("draws \n");
								player1.weapon = (rand()%3 + 1);
								player4.weapon = (rand()%3 + 1);
								goto draw1;
							}
							else if (player4.weapon >= Weapon_Scissor ) {
								if (player4.weapon == Weapon_Scissor) {
									printf("Player1 : Paper, Player4 : Scissor \n");
									printf("Player1 : Loser, Player4 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player4.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								else if (player4.weapon == Weapon_Stone) {
									printf("Player1 : Paper, Player4 : Stone \n");
									printf("Player1 : Winner, Player4 : Loser \n");
									printf("Player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}
									break;
								}
								break;
							}
							break;
						}

					//그리고 player1의 생명이 0이 되었다면 그 다음엔 player2가 상대방과 싸워야한다. 따라서 player1.life == 0이라는 조건을 사용하였다.
					if (player1.life == 0) {
						draw2:
							switch (player2.weapon) {
							case 1:
								if (player4.weapon == Weapon_Scissor){
									printf("Player2 : Scissor, Player4 : Scissor \n");
									printf("draws\n");
									player2.weapon = (rand()%3 + 1);
									player4.weapon = (rand()%3 + 1);
									goto draw2;
								}
								else if (player4.weapon >= Weapon_Scissor ) {
									if (player4.weapon == Weapon_Stone) {
										printf("Player2 : Scissor, Player4 : Stone \n");
										printf("Player2 : Loser, Player4 : Winner \n");
										printf("Player2 Life = 0 \n");
										printf("\n");
										player2.life = 0;


										if (probability == 1) {
											player4.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player4.weapon == Weapon_Paper) {
										printf("Player2 : Scissor, Player4 : Paper \n");
										printf("Player2 : Winner, Player4 : Loser \n");
										printf("Player4 Life = 0 \n");
										printf("\n");
										player4.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										fflush(stdin);

										if (change == 0){
											if (probability == 1) {
												player2.weapon = player4.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										break;
									}
									break;
								}
								break;

							case 2:
								if (player4.weapon == Weapon_Stone){
									printf("Player2 : Stone, Player4 : Stone \n");
									printf("draws \n");
									player2.weapon = (rand()%3 + 1);
									player4.weapon = (rand()%3 + 1);
									goto draw2;
								}
								else if (player4.weapon >= Weapon_Scissor ) {
									if (player4.weapon == Weapon_Scissor) {
										printf("Player2 : Stone, Player4 : Scissor \n");
										printf("Player2 : Winner, Player4 : Loser \n");
										printf("Player4 Life = 0 \n");
										printf("\n");

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										fflush(stdin);

										if (change == 0){
											if (probability == 1) {
												player2.weapon = player4.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										player4.life = 0;
										break;
									}
									else if (player4.weapon == Weapon_Paper) {
										printf("Player2 : Stone, Player4 : Paper \n");
										printf("Player2 : Loser, Player4 : Winner \n");
										printf("Player2 Life = 0 \n");
										printf("\n");
										player2.life = 0;


										if (probability == 1) {
											player4.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									break;
								}
								break;

							case 3:
								if (player4.weapon == Weapon_Paper){
									printf("Player2 : Paper, Player4 : Paper \n");
									printf("draws \n");
									player2.weapon = (rand()%3 + 1);
									player4.weapon = (rand()%3 + 1);
									goto draw2;
								}
								else if (player4.weapon >= Weapon_Scissor ) {
									if (player4.weapon == Weapon_Scissor) {
										printf("Player2 : Paper, Player4 : Scissor \n");
										printf("Player2 : Loser, Player4 : Winner \n");
										printf("Player2 Life = 0 \n");
										printf("\n");
										player2.life = 0;
										if (probability == 1) {
											player4.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player4.weapon == Weapon_Stone) {
										printf("Player2 : Paper, Player4 : Stone \n");
										printf("Player2 : Winner, Player4 : Loser \n");
										printf("Player4 Life = 0 \n");
										printf("\n");
										player4.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										fflush(stdin);

										if (change == 0){
											if (probability == 1) {
												player2.weapon = player4.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										break;
									}

									break;
								}
								break;
							}
					break;

					}


					//그리고 player2의 생명이 0이 되었다면 그 다음엔 player3이 상대방과 싸워야한다. 따라서 player2.life == 0이라는 조건을 사용하였다.
					if (player2.life == 0) {
						draw3 :
							switch (player3.weapon) {
							case 1:
								if (player4.weapon == Weapon_Scissor){
									printf("Player3 : Scissor, Player4 : Scissor \n");
									printf("draws \n");
									player3.weapon = (rand()%3 + 1);
									player4.weapon = (rand()%3 + 1);
									goto draw3;
								}
								else if (player4.weapon > Weapon_Scissor ) {
									if (player4.weapon == Weapon_Stone) {
										printf("Player3 : Scissor, Player4 : Stone \n");
										printf("Player3 : Loser, Player4 : Winner \n");
										printf("Player3 Life = 0 \n");
										printf("\n");
										player3.life = 0;


										if (probability == 1) {
											player4.weapon = player3.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player4.weapon == Weapon_Paper) {
										printf("Player3 : Scissor, Player4 : Paper \n");
										printf("Player3 : Winner, Player4 : Loser \n");
										printf("Player4 Life = 0 \n");
										printf("\n");
										player4.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										fflush(stdin);

										if (change == 0){
											if (probability == 1) {
												player3.weapon = player4.weapon;
												printf("Change the Weapon. \n");
												printf("New player3's weapon : %d \n", player3.weapon);
											}
										}
										break;
									}
									break;
								}
								break;

							case 2:
								if (player4.weapon == Weapon_Stone){
									printf("Player3 : Stone, Player4 : Stone \n");
									printf("draws \n");
									player3.weapon = (rand()%3 + 1);
									player4.weapon = (rand()%3 + 1);
									goto draw3;
								}
								else if (player4.weapon > Weapon_Scissor ) {
									if (player4.weapon == Weapon_Scissor) {
										printf("Player3 : Stone, Player4 : Scissor \n");
										printf("Player3 : Winner, Player4 : Loser \n");
										printf("Player4 Life = 0 \n");
										printf("\n");
										player4.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										fflush(stdin);

										if (change == 0){
											if (probability == 1) {
												player3.weapon = player4.weapon;
												printf("Change the Weapon. \n");
												printf("New player3's weapon : %d \n", player3.weapon);
											}
										}
										break;
									}
									else if (player4.weapon == Weapon_Paper) {
										printf("Player3 : Stone, Player4 : Paper \n");
										printf("Player3 : Loser, Player4 : Winner \n");
										printf("Player3 Life = 0 \n");
										printf("\n");
										player3.life = 0;


										if (probability == 1) {
											player4.weapon = player3.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									break;
								}
								break;

							case 3:
								if (player4.weapon == Weapon_Paper){
									printf("Player3 : Paper, Player4 : Paper \n");
									printf("draws \n");
									player3.weapon = (rand()%3 + 1);
									player4.weapon = (rand()%3 + 1);
									goto draw3;
								}
								else if (player4.weapon > Weapon_Scissor ) {
									if (player4.weapon == Weapon_Scissor) {
										printf("Player3 : Paper, Player4 : Scissor \n");
										printf("Player3 : Loser, Player4 : Winner \n");
										printf("Player3 Life = 0 \n");
										printf("\n");
										player3.life = 0;


										if (probability == 1) {
											player4.weapon = player3.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player4.weapon == Weapon_Stone) {
										printf("Player3 : Paper, Player4 : Stone \n");
										printf("Player3 : Winner, Player4 : Loser \n");
										printf("Player4 Life = 0 \n");
										printf("\n");
										player4.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										fflush(stdin);

										if (change == 0){
											if (probability == 1) {
												player3.weapon = player4.weapon;
												printf("Change the Weapon. \n");
												printf("New player3's weapon : %d \n", player3.weapon);
											}
										}
										break;
									}
									break;
								}
								break;
							}
					}

				}
				break;

				if (player4.life == 0) {
					printf("Player4 has Zero Life.\n"); //만약 입력받은 player ID의 Life가 0이라면 player의 생명력이 0이라는 문구를 출력한 후 반복문을 다시 돈다.
				}
			}


			// 이 경우는 상대방의 ID를 Player5로 입력했을 경우이다. 그 이후의 코드는 player4와 동일하다.
			if (opponent == player5.id){
				if (player5.life != 0) {
					printf ("Player1's Opponent : player5 \n");
					printf("\n");

					draw4 :
						switch (player1.weapon) {
						case 1:
							if (player5.weapon == Weapon_Scissor){
								printf("Player1 : Scissor, player5 : Scissor \n");
								printf("draws \n");
								player1.weapon = (rand()%3 + 1);
								player5.weapon = (rand()%3 + 1);
								goto draw4;
							}
							else if (player5.weapon >= Weapon_Scissor ) {
								if (player5.weapon == Weapon_Stone) {
									printf("Player1 : Scissor, player5 : Stone \n");
									printf("Player1 : Loser, player5 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player5.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}

								else if (player5.weapon == Weapon_Paper) {
									printf("Player1 : Scissor, player5 : Paper \n");
									printf("Player1 : Winner, player5 : Loser \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player1.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}
									break;
								}
								break;
							}
							break;

						case 2:
							if (player5.weapon == Weapon_Stone){
								printf("Player1 : Stone, player5 : Stone \n");
								printf("draws \n");
								player1.weapon = (rand()%3 + 1);
								player5.weapon = (rand()%3 + 1);
								goto draw4;
							}
							else if (player5.weapon >= Weapon_Scissor ) {
								if (player5.weapon == Weapon_Scissor) {
									printf("Player1 : Stone, player5 : Scissor \n");
									printf("Player1 : Winner, player5 : Loser \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player1.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}
									break;
								}
								else if (player5.weapon == Weapon_Paper) {
									printf("Player1 : Stone, player5 : Paper \n");
									printf("Player1 : Loser, player5 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player5.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								break;
							}
							break;


						case 3:
							if (player5.weapon == Weapon_Paper){
								printf("Player1 : Paper, player5 : Paper \n");
								printf("draws \n");
								player1.weapon = (rand()%3 + 1);
								player5.weapon = (rand()%3 + 1);
								goto draw4;
							}
							else if (player5.weapon >= Weapon_Scissor ) {
								if (player5.weapon == Weapon_Scissor) {
									printf("Player1 : Paper, player5 : Scissor \n");
									printf("Player1 : Loser, player5 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player5.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								else if (player5.weapon == Weapon_Stone) {
									printf("Player1 : Paper, player5 : Stone \n");
									printf("Player1 : Winner, player5 : Loser \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player1.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}
									break;
								}
								break;
							}
							break;
						}

					if (player1.life == 0) {
						draw5:
							switch (player2.weapon) {
							case 1:
								if (player5.weapon == Weapon_Scissor){
									printf("Player2 : Scissor, player5 : Scissor \n");
									printf("draws \n");
									player2.weapon = (rand()%3 + 1);
									player5.weapon = (rand()%3 + 1);
									goto draw5;
								}
								else if (player5.weapon >= Weapon_Scissor ) {
									if (player5.weapon == Weapon_Stone) {
										printf("Player2 : Scissor, player5 : Stone \n");
										printf("Player2 : Loser, player5 : Winner \n");
										printf("Player2 Life = 0 \n");
										printf("\n");
										player2.life = 0;


										if (probability == 1) {
											player5.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player5.weapon == Weapon_Paper) {
										printf("Player2 : Scissor, player5 : Paper \n");
										printf("Player2 : Winner, player5 : Loser \n");
										printf("player5 Life = 0 \n");
										printf("\n");
										player5.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player2.weapon = player5.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										break;
									}
									break;
								}
								break;

							case 2:
								if (player5.weapon == Weapon_Stone){
									printf("Player2 : Stone, player5 : Stone \n");
									printf("draws \n");
									player2.weapon = (rand()%3 + 1);
									player5.weapon = (rand()%3 + 1);
									goto draw5;
								}
								else if (player5.weapon >= Weapon_Scissor ) {
									if (player5.weapon == Weapon_Scissor) {
										printf("Player2 : Stone, player5 : Scissor \n");
										printf("Player2 : Winner, player5 : Loser \n");
										printf("player5 Life = 0 \n");
										printf("\n");
										player5.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player2.weapon = player5.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										break;
									}
									break;
								}
								else if (player5.weapon == Weapon_Paper) {
									printf("Player2 : Stone, player5 : Paper \n");
									printf("Player2 : Loser, player5 : Winner \n");
									printf("Player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;


									if (probability == 1) {
										player5.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								break;





							case 3:
								if (player5.weapon == Weapon_Paper){
									printf("Player2 : Paper, player5 : Paper \n");
									printf("draws \n");
									player2.weapon = (rand()%3 + 1);
									player5.weapon = (rand()%3 + 1);
									goto draw5;
								}
								else if (player5.weapon >= Weapon_Scissor ) {
									if (player5.weapon == Weapon_Scissor) {
										printf("Player2 : Paper, player5 : Scissor \n");
										printf("Player2 : Loser, player5 : Winner \n");
										printf("Player2 Life = 0 \n");
										printf("\n");
										player2.life = 0;


										if (probability == 1) {
											player5.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player5.weapon == Weapon_Stone) {
										printf("Player2 : Paper, player5 : Stone \n");
										printf("Player2 : Winner, player5 : Loser \n");
										printf("player5 Life = 0 \n");
										printf("\n");
										player5.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player2.weapon = player5.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										break;
									}
									break;
								}
								break;
							}
					}
				}


				if (player2.life == 0) {
					draw6 :
						switch (player3.weapon) {
						case 1:
							if (player5.weapon == Weapon_Scissor){
								printf("Player3 : Scissor, player5 : Scissor \n");
								printf("draws \n");
								player3.weapon = (rand()%3 + 1);
								player5.weapon = (rand()%3 + 1);
								goto draw6;
							}
							else if (player5.weapon > Weapon_Scissor ) {
								if (player5.weapon == Weapon_Stone) {
									printf("Player3 : Scissor, player5 : Stone \n");
									printf("Player3 : Loser, player5 : Winner \n");
									printf("Player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player5.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								else if (player5.weapon == Weapon_Paper) {
									printf("Player3 : Scissor, player5 : Paper \n");
									printf("Player3 : Winner, player5 : Loser \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player3.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}
									break;
								}
								break;
							}
							break;

						case 2:
							if (player5.weapon == Weapon_Stone){
								printf("Player3 : Stone, player5 : Stone \n");
								printf("draws \n");
								player3.weapon = (rand()%3 + 1);
								player5.weapon = (rand()%3 + 1);
								goto draw6;
							}
							else if (player5.weapon > Weapon_Scissor ) {
								if (player5.weapon == Weapon_Scissor) {
									printf("Player3 : Stone, player5 : Scissor \n");
									printf("Player3 : Winner, player5 : Loser \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player3.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}
									break;
								}
								else if (player5.weapon == Weapon_Paper) {
									printf("Player3 : Stone, player5 : Paper \n");
									printf("Player3 : Loser, player5 : Winner \n");
									printf("Player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player5.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								break;
							}
							break;

						case 3:
							if (player5.weapon == Weapon_Paper){
								printf("Player3 : Paper, player5 : Paper \n");
								printf("draws \n");
								player3.weapon = (rand()%3 + 1);
								player5.weapon = (rand()%3 + 1);
								goto draw6;
							}
							else if (player5.weapon > Weapon_Scissor ) {
								if (player5.weapon == Weapon_Scissor) {
									printf("Player3 : Paper, player5 : Scissor \n");
									printf("Player3 : Loser, player5 : Winner \n");
									printf("Player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player5.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								else if (player5.weapon == Weapon_Stone) {
									printf("Player3 : Paper, player5 : Stone \n");
									printf("Player3 : Winner, player5 : Loser \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player3.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}
									break;
								}
								break;
							}
							break;
						}

				}
				break;

				if (player5.life == 0) {
					printf("player5 has Zero Life.\n");
				}
			}



			// 이 경우는 상대방의 ID를 Player6으로 입력했을 경우이다. 그 이후의 코드는 player4와 동일하다.
			if (opponent == player6.id){
				if (player6.life != 0) {
					printf ("Player1's Opponent : player6 \n");
					printf("\n");

					draw7 :
						switch (player1.weapon) {
						case 1:
							if (player6.weapon == Weapon_Scissor){
								printf("Player1 : Scissor, player6 : Scissor \n");
								printf("draws \n");
								player1.weapon = (rand()%3 + 1);
								player6.weapon = (rand()%3 + 1);
								goto draw7;
							}
							else if (player6.weapon >= Weapon_Scissor ) {
								if (player6.weapon == Weapon_Stone) {
									printf("Player1 : Scissor, player6 : Stone \n");
									printf("Player1 : Loser, player6 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player6.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}

								else if (player6.weapon == Weapon_Paper) {
									printf("Player1 : Scissor, player6 : Paper \n");
									printf("Player1 : Winner, player6 : Loser \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player1.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}
									break;
								}
								break;
							}
							break;

						case 2:
							if (player6.weapon == Weapon_Stone){
								printf("Player1 : Stone, player6 : Stone \n");
								printf("draws \n");
								player1.weapon = (rand()%3 + 1);
								player6.weapon = (rand()%3 + 1);
								goto draw7;
							}
							else if (player6.weapon >= Weapon_Scissor ) {
								if (player6.weapon == Weapon_Scissor) {
									printf("Player1 : Stone, player6 : Scissor \n");
									printf("Player1 : Winner, player6 : Loser \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player1.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}
									break;
								}
								else if (player6.weapon == Weapon_Paper) {
									printf("Player1 : Stone, player6 : Paper \n");
									printf("Player1 : Loser, player6 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player6.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								break;
							}
							break;


						case 3:
							if (player6.weapon == Weapon_Paper){
								printf("Player1 : Paper, player6 : Paper \n");
								printf("draws \n");
								player1.weapon = (rand()%3 + 1);
								player6.weapon = (rand()%3 + 1);
								goto draw7;
							}
							else if (player6.weapon >= Weapon_Scissor ) {
								if (player6.weapon == Weapon_Scissor) {
									printf("Player1 : Paper, player6 : Scissor \n");
									printf("Player1 : Loser, player6 : Winner \n");
									printf("Player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player6.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									flag = 0;
									break;
								}
								else if (player6.weapon == Weapon_Stone) {
									printf("Player1 : Paper, player6 : Stone \n");
									printf("Player1 : Winner, player6 : Loser \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									if (change == 0){
										if (probability == 1) {
											player1.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}
									break;
								}
								break;
							}
							break;
						}

					if (player1.life == 0) {
						draw8:
							switch (player2.weapon) {
							case 1:
								if (player6.weapon == Weapon_Scissor){
									printf("Player2 : Scissor, player6 : Scissor \n");
									printf("draws \n");
									player2.weapon = (rand()%3 + 1);
									player6.weapon = (rand()%3 + 1);
									goto draw8;
								}
								else if (player6.weapon >= Weapon_Scissor ) {
									if (player6.weapon == Weapon_Stone) {
										printf("Player2 : Scissor, player6 : Stone \n");
										printf("Player2 : Loser, player6 : Winner \n");
										printf("Player2 Life = 0 \n");
										printf("\n");
										player2.life = 0;


										if (probability == 1) {
											player6.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player6.weapon == Weapon_Paper) {
										printf("Player2 : Scissor, player6 : Paper \n");
										printf("Player2 : Winner, player6 : Loser \n");
										printf("player6 Life = 0 \n");
										printf("\n");
										player6.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player2.weapon = player6.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										break;
									}
									break;
								}
								break;

							case 2:
								if (player6.weapon == Weapon_Stone){
									printf("Player2 : Stone, player6 : Stone \n");
									printf("draws \n");
									player2.weapon = (rand()%3 + 1);
									player6.weapon = (rand()%3 + 1);
									goto draw8;
								}
								else if (player6.weapon >= Weapon_Scissor ) {
									if (player6.weapon == Weapon_Scissor) {
										printf("Player2 : Stone, player6 : Scissor \n");
										printf("Player2 : Winner, player6 : Loser \n");
										printf("player6 Life = 0 \n");
										printf("\n");
										player6.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player2.weapon = player6.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										break;
									}
									else if (player6.weapon == Weapon_Paper) {
										printf("Player2 : Stone, player6 : Paper \n");
										printf("Player2 : Loser, player6 : Winner \n");
										printf("Player2 Life = 0 \n");
										printf("\n");
										player2.life = 0;


										if (probability == 1) {
											player6.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									break;
								}
								break;

							case 3:
								if (player6.weapon == Weapon_Paper){
									printf("Player2 : Paper, player6 : Paper \n");
									printf("draws \n");
									player2.weapon = (rand()%3 + 1);
									player6.weapon = (rand()%3 + 1);
									goto draw8;
								}
								else if (player6.weapon >= Weapon_Scissor ) {
									if (player6.weapon == Weapon_Scissor) {
										printf("Player2 : Paper, player6 : Scissor \n");
										printf("Player2 : Loser, player6 : Winner \n");
										printf("Player2 Life = 0 \n");
										printf("\n");
										player2.life = 0;


										if (probability == 1) {
											player6.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player6.weapon == Weapon_Stone) {
										printf("Player2 : Paper, player6 : Stone \n");
										printf("Player2 : Winner, player6 : Loser \n");
										printf("player6 Life = 0 \n");
										printf("\n");
										player6.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player2.weapon = player6.weapon;
												printf("Change the Weapon. \n");
												printf("New player2's weapon : %d \n", player2.weapon);
											}
										}
										break;
									}
									break;
								}
								break;
							}
					}


					if (player2.life == 0) {
						draw9 :
							switch (player3.weapon) {
							case 1:
								if (player6.weapon == Weapon_Scissor){
									printf("Player3 : Scissor, player6 : Scissor \n");
									printf("draws \n");
									player3.weapon = (rand()%3 + 1);
									player6.weapon = (rand()%3 + 1);
									goto draw9;
								}
								else if (player6.weapon > Weapon_Scissor ) {
									if (player6.weapon == Weapon_Stone) {
										printf("Player3 : Scissor, player6 : Stone \n");
										printf("Player3 : Loser, player6 : Winner \n");
										printf("Player3 Life = 0 \n");
										printf("\n");
										player3.life = 0;


										if (probability == 1) {
											player6.weapon = player3.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player6.weapon == Weapon_Paper) {
										printf("Player3 : Scissor, player6 : Paper \n");
										printf("Player3 : Winner, player6 : Loser \n");
										printf("player6 Life = 0 \n");
										printf("\n");
										player6.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player3.weapon = player6.weapon;
												printf("Change the Weapon. \n");
												printf("New player3's weapon : %d \n", player3.weapon);
											}
										}
										break;
									}
									break;
								}
								break;

							case 2:
								if (player6.weapon == Weapon_Stone){
									printf("Player3 : Stone, player6 : Stone \n");
									printf("draws \n");
									player3.weapon = (rand()%3 + 1);
									player6.weapon = (rand()%3 + 1);
									goto draw9;
								}
								else if (player6.weapon > Weapon_Scissor ) {
									if (player6.weapon == Weapon_Scissor) {
										printf("Player3 : Stone, player6 : Scissor \n");
										printf("Player3 : Winner, player6 : Loser \n");
										printf("player6 Life = 0 \n");
										printf("\n");
										player6.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player3.weapon = player6.weapon;
												printf("Change the Weapon. \n");
												printf("New player3's weapon : %d \n", player3.weapon);
											}
										}
										break;
									}
									else if (player6.weapon == Weapon_Paper) {
										printf("Player3 : Stone, player6 : Paper \n");
										printf("Player3 : Loser, player6 : Winner \n");
										printf("Player3 Life = 0 \n");
										printf("\n");
										player3.life = 0;


										if (probability == 1) {
											player6.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									break;
								}
								break;

							case 3:
								if (player6.weapon == Weapon_Paper){
									printf("Player3 : Paper, player6 : Paper \n");
									printf("draws \n");
									player3.weapon = (rand()%3 + 1);
									player6.weapon = (rand()%3 + 1);
									goto draw9;
								}
								else if (player6.weapon > Weapon_Scissor ) {
									if (player6.weapon == Weapon_Scissor) {
										printf("Player3 : Paper, player6 : Scissor \n");
										printf("Player3 : Loser, player6 : Winner \n");
										printf("Player3 Life = 0 \n");
										printf("\n");
										player3.life = 0;


										if (probability == 1) {
											player6.weapon = player2.weapon;
											printf("Change the Weapon. \n");
										}

										flag = 0;
										break;
									}
									else if (player6.weapon == Weapon_Stone) {
										printf("Player3 : Paper, player6 : Stone \n");
										printf("Player3 : Winner, player6 : Loser \n");
										printf("player6 Life = 0 \n");
										printf("\n");
										player6.life = 0;

										printf("You change the Weapon? Yes = 0, No =1 \n");
										scanf("%d", &change);
										if (change == 0){
											if (probability == 1) {
												player3.weapon = player6.weapon;
												printf("Change the Weapon. \n");
												printf("New player3's weapon : %d \n", player3.weapon);
											}
										}
										break;
									}
									break;
								}
								break;
							}
					break;

					}
					break;

					if (player6.life == 0) {
						printf("player6 has Zero Life.\n");
					}
				}
			}

		}while(flag != 0); // flag가 0이되는 조건은 맨 처음 선택받은 Fati 팀의 상대방의 Life가 0이 되었을 때이다. 이 경우 반복문을 종료하면서 flag는 다시 1이 되고, 다음 do-while반복문을 돈다.



		flag = 1;

		// 이 반복문은 Fati팀이 상대방과 경기하는 코드이다. 진행은 Amor팀의 코드와 동일하다. 다만 코드가 실행되는 조건만 달라졌다.(이것만 주석처리)
		do {

			if (player1.life != 0) {
				printf ("Opponent : Player1 \n");
				printf("\n");

				// player4의 생명이 0이 아니고, player6의 생명이 0일 때 조건문을 수행한다. player6의 생명이 0이여야 실행되는 이유는 맨 처음 player1의 대결자로 player6을 선택했을 경우이다.
				// 이 코드를 짤 때 player4부터 시작했으면 4,5,6순서대로, player5부터 시작했으면 5,6,4의 순서와 같이 진행되게 설정하였으므로, 조건에 player6의 생명이 0이되도록 설정하였다.
				if (player4.life != 0 && player6.life == 0) {
					draw10:
						switch (player4.weapon) {
						case 1:
							if (player1.weapon == Weapon_Scissor){
								printf("player4 : Scissor, player1 : Scissor \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw10;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Stone) {
									printf("player4 : Scissor, player1 : Stone \n");
									printf("player4 : Loser, player1 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player1.weapon == Weapon_Paper) {
									printf("player4 : Scissor, player1 : Paper \n");
									printf("player4 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player4.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}
							break;

						case 2:
							if (player1.weapon == Weapon_Stone){
								printf("player4 : Stone, player1 : Stone \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw10;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Scissor) {
									printf("player4 : Stone, player1 : Scissor \n");
									printf("player4 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;

									if (probability == 1) {
										player4.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								else if (player1.weapon == Weapon_Paper) {
									printf("player4 : Stone, player1 : Paper \n");
									printf("player4 : Loser, player1 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}
								break;
							}
							break;


						case 3:
							if (player1.weapon == Weapon_Paper){
								printf("player4 : Paper, player1 : Paper \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw10;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Scissor) {
									printf("player4 : Paper, player1 : Scissor \n");
									printf("player4 : Loser, player1 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player1.weapon == Weapon_Stone) {
									printf("player4 : Paper, player1 : Stone \n");
									printf("player4 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player4.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}
							break;

						}

				}




				if (player5.life != 0) {
					draw11:
						switch (player5.weapon) {
						case 1:
							if (player1.weapon == Weapon_Scissor){
								printf("player5 : Scissor, player1 : Scissor \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw11;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Stone) {
									printf("player5 : Scissor, player1 : Stone \n");
									printf("player5 : Loser, player1 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player1.weapon == Weapon_Paper) {
									printf("player5 : Scissor, player1 : Paper \n");
									printf("player5 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player5.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}

							break;


						case 2:
							if (player1.weapon == Weapon_Stone){
								printf("player5 : Stone, player1 : Stone \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw11;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Scissor) {
									printf("player5 : Stone, player1 : Scissor \n");
									printf("player5 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player5.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								else if (player1.weapon == Weapon_Paper) {
									printf("player5 : Stone, player1 : Paper \n");
									printf("player5 : Loser, player1 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}
								break;
							}

							break;



						case 3:
							if (player1.weapon == Weapon_Paper){
								printf("player5 : Paper, player1 : Paper \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw11;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Scissor) {
									printf("player5 : Paper, player1 : Scissor \n");
									printf("player5 : Loser, player1 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player1.weapon == Weapon_Stone) {
									printf("player5 : Paper, player1 : Stone \n");
									printf("player5 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player5.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}
							break;


						}
				}






				if (player6.life != 0) {
					draw12:
						switch (player6.weapon) {
						case 1:
							if (player1.weapon == Weapon_Scissor){
								printf("player6 : Scissor, player1 : Scissor \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw12;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Stone) {
									printf("player6 : Scissor, player1 : Stone \n");
									printf("player6 : Loser, player1 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player1.weapon == Weapon_Paper) {
									printf("player6 : Scissor, player1 : Paper \n");
									printf("player6 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player6.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
							}
							break;



						case 2:
							if (player1.weapon == Weapon_Stone){
								printf("player6 : Stone, player1 : Stone \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw12;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Scissor) {
									printf("player6 : Stone, player1 : Scissor \n");
									printf("player6 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player6.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								else if (player1.weapon == Weapon_Paper) {
									printf("player6 : Stone, player1 : Paper \n");
									printf("player6 : Loser, player1 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}
								break;
							}
							break;





						case 3:
							if (player1.weapon == Weapon_Paper){
								printf("player6 : Paper, player1 : Paper \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player1.weapon = (rand()%3 + 1);
								goto draw12;
							}
							else if (player1.weapon >= Weapon_Scissor ) {
								if (player1.weapon == Weapon_Scissor) {
									printf("player6 : Paper, player1 : Scissor \n");
									printf("player6 : Loser, player1 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player1.weapon == Weapon_Stone) {
									printf("player6 : Paper, player1 : Stone \n");
									printf("player6 : Winner, player1 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player1.life = 0;


									if (probability == 1) {
										player6.weapon = player1.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}

							break;


						}
				}

			}


			if (player2.life != 0) {
				printf ("Opponent : player2 \n");
				printf("\n");

				if (player4.life != 0 && player6.life == 0) {
					draw13 :
						switch (player4.weapon) {
						case 1:
							if (player1.weapon == Weapon_Scissor){
								printf("player4 : Scissor, player2 : Scissor \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw13;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Stone) {
									printf("player4 : Scissor, player2 : Stone \n");
									printf("player4 : Loser, player2 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player2.weapon == Weapon_Paper) {
									printf("player4 : Scissor, player2 : Paper \n");
									printf("player4 : Winner, player2 : Loser \n");
									printf("player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;

									if (probability == 1) {
										player4.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;

							}

							break;


						case 2:
							if (player2.weapon == Weapon_Stone){
								printf("player4 : Stone, player2 : Stone \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw13;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Scissor) {
									printf("player4 : Stone, player2 : Scissor \n");
									printf("player4 : Winner, player2 : Loser \n");
									printf("player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;


									if (probability == 1) {
										player4.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								else if (player2.weapon == Weapon_Paper) {
									printf("player4 : Stone, player2 : Paper \n");
									printf("player4 : Loser, player2 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}
								break;
							}
							break;



						case 3:
							if (player2.weapon == Weapon_Paper){
								printf("player4 : Paper, player2 : Paper \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw13;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Scissor) {
									printf("player4 : Paper, player2 : Scissor \n");
									printf("player4 : Loser, player2 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player2.weapon == Weapon_Stone) {
									printf("player4 : Paper, player2 : Stone \n");
									printf("player4 : Winner, player2 : Loser \n");
									printf("player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;


									if (probability == 1) {
										player4.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}
							break;


						}

				}





				if (player5.life != 0){
					draw14:
						switch (player5.weapon) {
						case 1:
							if (player2.weapon == Weapon_Scissor){
								printf("player5 : Scissor, player2 : Scissor \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw14;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Stone) {
									printf("player5 : Scissor, player2 : Stone \n");
									printf("player5 : Loser, player2 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player2.weapon == Weapon_Paper) {
									printf("player5 : Scissor, player2 : Paper \n");
									printf("player5 : Winner, player2 : Loser \n");
									printf("player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;

									if (probability == 1) {
										player5.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;

							}

							break;

						case 2:
							if (player2.weapon == Weapon_Stone){
								printf("player5 : Stone, player2 : Stone \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw14;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Scissor) {
									printf("player5 : Stone, player2 : Scissor \n");
									printf("player5 : Winner, player2 : Loser \n");
									printf("player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;

									if (probability == 1) {
										player5.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								else if (player2.weapon == Weapon_Paper) {
									printf("player5 : Stone, player2 : Paper \n");
									printf("player5 : Loser, player2 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}
								break;

							}
							break;



						case 3:
							if (player2.weapon == Weapon_Paper){
								printf("player5 : Paper, player2 : Paper \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw14;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Scissor) {
									printf("player5 : Paper, player2 : Scissor \n");
									printf("player5 : Loser, player2 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player2.weapon == Weapon_Stone) {
									printf("player5 : Paper, player2 : Stone \n");
									printf("player5 : Winner, player2 : Loser \n");
									printf("player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;


									if (probability == 1) {
										player5.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;

							}
							break;

						}
				}





				if (player6.life != 0) {
					draw15:
						switch (player6.weapon) {
						case 1:
							if (player2.weapon == Weapon_Scissor){
								printf("player5 : Scissor, player2 : Scissor \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw15;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Stone) {
									printf("player6 : Scissor, player2 : Stone \n");
									printf("player6 : Loser, player2 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player2.weapon == Weapon_Paper) {
									printf("player6 : Scissor, player2 : Paper \n");
									printf("player6 : Winner, player2 : Loser \n");
									printf("player1 Life = 0 \n");
									printf("\n");
									player2.life = 0;


									if (probability == 1) {
										player6.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}

							break;

						case 2:
							if (player2.weapon == Weapon_Stone){
								printf("player6 : Stone, player2 : Stone \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw15;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Scissor) {
									printf("player6 : Stone, player2 : Scissor \n");
									printf("player6 : Winner, player2 : Loser \n");
									printf("player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;

									if (probability == 1) {
										player6.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								else if (player2.weapon == Weapon_Paper) {
									printf("player6 : Stone, player2 : Paper \n");
									printf("player6 : Loser, player2 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}
								break;
							}
							break;



						case 3:
							if (player2.weapon == Weapon_Paper){
								printf("player6 : Paper, player2 : Paper \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player2.weapon = (rand()%3 + 1);
								goto draw15;
							}
							else if (player2.weapon >= Weapon_Scissor ) {
								if (player2.weapon == Weapon_Scissor) {
									printf("player6 : Paper, player2 : Scissor \n");
									printf("player6 : Loser, player2 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player2.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player2's weapon : %d \n", player2.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player2.weapon == Weapon_Stone) {
									printf("player6 : Paper, player2 : Stone \n");
									printf("player6 : Winner, player2 : Loser \n");
									printf("player2 Life = 0 \n");
									printf("\n");
									player2.life = 0;


									if (probability == 1) {
										player6.weapon = player2.weapon;
										printf("Change the Weapon. \n");
									}
								}
								break;
							}
							break;
						}
				break;

				}
			}





			if (player2.life == 0) {
				printf("player2 has Zero Life.\n");
			}




			if (player3.life != 0) {
				printf ("Opponent : player3 \n");
				printf("\n");

				if (player6.life == 0 && player4.life != 0) {
					draw16:
						switch (player4.weapon) {
						case 1:
							if (player3.weapon == Weapon_Scissor){
								printf("player5 : Scissor, player3 : Scissor \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw16;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Stone) {
									printf("player4 : Scissor, player3 : Stone \n");
									printf("player4 : Loser, player3 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player3.weapon == Weapon_Paper) {
									printf("player4 : Scissor, player3 : Paper \n");
									printf("player4 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player4.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}
							break;

						case 2:
							if (player3.weapon == Weapon_Stone){
								printf("player4 : Stone, player3 : Stone \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw16;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Scissor) {
									printf("player4 : Stone, player3 : Scissor \n");
									printf("player4 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player4.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								else if (player3.weapon == Weapon_Paper) {
									printf("player4 : Stone, player3 : Paper \n");
									printf("player4 : Loser, player3 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}
									flag = 0;
									break;
								}
								break;
							}
							break;


						case 3:
							if (player3.weapon == Weapon_Paper){
								printf("player4 : Paper, player3 : Paper \n");
								printf("draws \n");
								player4.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw16;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Scissor) {
									printf("player4 : Paper, player3 : Scissor \n");
									printf("player4 : Loser, player3 : Winner \n");
									printf("player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player3.weapon == Weapon_Stone) {
									printf("player4 : Paper, player3 : Stone \n");
									printf("player4 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;

									if (probability == 1) {
										player4.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}
							break;
						}

				}




				if (player5.life != 0) {
					draw17:
						switch (player5.weapon) {
						case 1:
							if (player3.weapon == Weapon_Scissor){
								printf("player5 : Scissor, player3 : Scissor \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw17;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Stone) {
									printf("player5 : Scissor, player3 : Stone \n");
									printf("player5 : Loser, player3 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player3.weapon == Weapon_Paper) {
									printf("player5 : Scissor, player3 : Paper \n");
									printf("player5 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player5.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}
							break;

						case 2:
							if (player3.weapon == Weapon_Stone){
								printf("player5 : Stone, player3 : Stone \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw17;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Scissor) {
									printf("player5 : Stone, player3 : Scissor \n");
									printf("player5 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player5.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								else if (player3.weapon == Weapon_Paper) {
									printf("player5 : Stone, player3 : Paper \n");
									printf("player5 : Loser, player3 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}

									flag = 0;
									break;
								}
								break;
							}
							break;

						case 3:
							if (player3.weapon == Weapon_Paper){
								printf("player5 : Paper, player3 : Paper \n");
								printf("draws \n");
								player5.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw17;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Scissor) {
									printf("player5 : Paper, player3 : Scissor \n");
									printf("player5 : Loser, player3 : Winner \n");
									printf("player5 Life = 0 \n");
									printf("\n");
									player5.life = 0;


									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player5.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player3.weapon == Weapon_Stone) {
									printf("player5 : Paper, player3 : Stone \n");
									printf("player5 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;

									if (probability == 1) {
										player5.weapon = player3.weapon;
										printf("Change the Weapon. \n");
										printf("New player5's weapon : %d \n", player5.weapon);
									}

									break;
								}
								break;
							}
							break;
						}

				}






				if (player6.life != 0) {
					draw18 :
						switch (player6.weapon) {
						case 1:
							if (player3.weapon == Weapon_Scissor){
								printf("player6 : Scissor, player3 : Scissor \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw18;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Stone) {
									printf("player6 : Scissor, player3 : Stone \n");
									printf("player6 : Loser, player3 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}

									flag = 0;
									break;
								}

								else if (player3.weapon == Weapon_Paper) {
									printf("player6 : Scissor, player3 : Paper \n");
									printf("player6 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player6.weapon = player3.weapon;
										printf("Change the Weapon. \n");
									}

									break;
								}
								break;
							}



							break;

						case 2:
							if (player3.weapon == Weapon_Stone){
								printf("player6 : Stone, player3 : Stone \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw18;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Scissor) {
									printf("player6 : Stone, player3 : Scissor \n");
									printf("player6 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;

									if (probability == 1) {
										player6.weapon = player3.weapon;
										printf("Change the Weapon. \n");
										printf("New player6's weapon : %d \n", player6.weapon);
									}

									break;
								}
								else if (player3.weapon == Weapon_Paper) {
									printf("player6 : Stone, player3 : Paper \n");
									printf("player6 : Loser, player3 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}

									flag = 0;
									break;
								}
								break;
							}
							break;


						case 3:
							if (player3.weapon == Weapon_Paper){
								printf("player6 : Paper, player3 : Paper \n");
								printf("draws \n");
								player6.weapon = (rand()%3 + 1);
								player3.weapon = (rand()%3 + 1);
								goto draw18;
							}
							else if (player3.weapon >= Weapon_Scissor ) {
								if (player3.weapon == Weapon_Scissor) {
									printf("player6 : Paper, player3 : Scissor \n");
									printf("player6 : Loser, player3 : Winner \n");
									printf("player6 Life = 0 \n");
									printf("\n");
									player6.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player3.weapon = player6.weapon;
											printf("Change the Weapon. \n");
											printf("New player3's weapon : %d \n", player3.weapon);
										}
									}

									flag = 0;
									break;
								}
								else if (player3.weapon == Weapon_Stone) {
									printf("player6 : Paper, player3 : Stone \n");
									printf("player6 : Winner, player3 : Loser \n");
									printf("player3 Life = 0 \n");
									printf("\n");
									player3.life = 0;


									if (probability == 1) {
										player6.weapon = player3.weapon;
										printf("Change the Weapon. \n");
										printf("New player6's weapon : %d \n", player6.weapon);
									}

									break;
								}
								break;
							}
							break;
						}
				break;

				}

			}


			break;

			if (player3.life == 0) {
				printf("player3 has Zero Life.\n");
			}



		}while(flag != 0);

		Amor_Life = player1.life + player2.life + player3.life; //Amor팀의 총 생명력을 계산한다.
		Fati_Life = player4.life + player5.life + player6.life; //Fati팀의 총 생명력을 계산한다.

	}while(Amor_Life != 0 && Fati_Life != 0); //만약 Amor팀이나 Fati팀의 생명력이 두 팀중 하나가 0이 된다면 반복문을 탈출한다.

	// 각 팀의 생명력을 출력하고, 이긴팀을 출력한다.
	printf("Amor_Life : %d \n" , Amor_Life);
	printf("Fati_Life : %d \n" , Fati_Life);

	if (Amor_Life > Fati_Life) {
		printf("AmorTeam WIn!");
	}
	else if (Amor_Life < Fati_Life) {
		printf("FatiTeam WIn!");
	}
}




