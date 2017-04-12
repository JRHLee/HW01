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
	int change; // ���ӿ��� �̱� ������ ���⸦ �ٲ��� �Է¹޴� ����. �ٲٷ��� 0, �ٲ��� �������� 1�� �޴´�.
	int number = 3; // ������ ������ �� ���� ������ ��.
	int flag = 1;; // flag�� �츮���� ������� �������� ������ ���ؼ� ���� �����̴�.
	srand(time (NULL)); // ���⸦ ������ �߻����Ѽ� �Է��Ͽ��µ�, time�� ����Ͽ� ������ ������ ������ �޶����� �����Ͽ���.

	int probability = rand()%2; // change������ �̱� ������ ���⸦ �ٲ��� ���� �Է¹޾Ƽ� 50%�� Ȯ���� ���Ⱑ �ٲ�� �����Ͽ��� �ϴµ�, �̰��� probablilty��� ������ �޾Ƽ� ����Ͽ���. �� ������ 0�� ���� �ٲ��� �ʰ�, 1�� �� ���Ⱑ �ٲ�� �����Ͽ���.

	printf("Player Number : %d \n\n", number); // �� ���� ������ ������� ����Ѵ�.

	int Weapon_Scissor = 1;
	int Weapon_Stone = 2;
	int Weapon_Paper = 3;

	int opponent = 0; // �����ڰ� �������� �˷��ִ� ����
	int Amor_Life; // Amor���� ������ ������ ��Ÿ���� ���� ����. ���Ŀ� player1~3�� ������ ���� ����Ѵ�.
	int Fati_Life; // Fati���� ������ ������ ��Ÿ���� ���� ����. ���Ŀ� player4~6�� ������ ���� ����Ѵ�.


	// struct teamates�� ����Ͽ� ���� player�� ������ �Է��Ͽ���. player1~6������ ������ ���� ����ִ�.
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


	// �� �� �츮���� ���� ������ ����Ѵ�.
	printf("player1's Weapon : %d \n", player1.weapon);
	printf("player2's Weapon : %d \n", player2.weapon);
	printf("player3's Weapon : %d \n", player3.weapon);

	//�� ó�� player1�� ������ �����Ѵ�.
	printf ("Player1 start Game. \n");

	// �� �� player1�� �������� ���� �� ������ �ο��� ID�� �Է¹޴´�.
	printf ("Select Opponent ID (2004, 2005, 2006) : \n");
	scanf ("%d", &opponent);



	// do-while���� ����Ͽ� ��ü ������ �ݺ��� �����Ѵ�. �� ���������� ������ Amor_Life�� Fati_Life�� 0�̵Ǳ� �� ���� �����Ѵ�.(����)
	do {

		do {


			// �� �ݺ����� opponent�� ���� player4, 5, 6�� �� ����� ���� ���� ���̴�.

			if (opponent == player4.id){
				// �����ڰ� player4�̰�, �� �� player4�� ������� 0�� �ƴϸ� ����Ǵ� ���ǹ��̴�.
				if (player4.life != 0) {
					printf ("Player1's Opponent : Player4 \n");
					printf("\n");

					// �Ʒ� switch���� player1�� ���Ⱑ ���� ����, ����, ���� ���� ��츦 case 1,2,3���� ����� ��� ����� ���� �����Ͽ� § �ڵ��̴�.
					draw1 :
						switch (player1.weapon) {
						case 1:
							if (player4.weapon == Weapon_Scissor){
								printf("Player1 : Scissor, Player4 : Scissor \n");
								printf("draws \n");
								//����� �� �� ������ ���⸦ �ٽ� �������� �缳���� �� draw1�̶�� ������ ���� ������ ���ư� �ٽ� switch���� �ݺ��Ѵ�.
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
									//player1�� ���� �� ������� 0���� �ٽ� �����ϰ�, ���濡�� ���⸦ �ٲܰ����� �ƴ��� ����µ�, �츮���� �ƴϹǷ� �� ������ �׵鿡�� �������Ѵ�. ������ �츮�� ���Ӹ����Ͱ� �ƴϹǷ� �׵��� �׻� �ٲ۴ٰ� �����Ծ��ٰ� ���� �� 50%�� Ȯ���� ���⸦ �ٲ�� �����Ͽ���.
									player1.life = 0;

									if (probability == 1) {
										player4.weapon = player1.weapon;
										printf("Change the Weapon. \n"); //�ٲٴµ� �����ϸ� ���Ⱑ �ٲ���ٰ� ������ ����Ѵ�.
									}
									break; // �ݺ����� ����������.
								}

								else if (player4.weapon == Weapon_Paper) {
									printf("Player1 : Scissor, Player4 : Paper \n");
									printf("Player1 : Winner, Player4 : Loser \n");
									printf("Player4 Life = 0 \n");
									printf("\n");
									player4.life = 0;

									printf("You change the Weapon? Yes = 0, No =1 \n");// �츮���� �̰��� �� ���⸦ �ٲ��� ����� ������ ����Ѵ�.
									scanf("%d", &change);
									fflush(stdin);

									if (change == 0){
										if (probability == 1) {
											player1.weapon = player4.weapon;
											printf("Change the Weapon. \n");
											printf("New player1's weapon : %d \n", player1.weapon);// �� �� ���Ⱑ �ٲ���ٸ�, �츮������ �ٲ� ���Ⱑ �������� ��µȴ�.
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

					//�׸��� player1�� ������ 0�� �Ǿ��ٸ� �� ������ player2�� ����� �ο����Ѵ�. ���� player1.life == 0�̶�� ������ ����Ͽ���.
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


					//�׸��� player2�� ������ 0�� �Ǿ��ٸ� �� ������ player3�� ����� �ο����Ѵ�. ���� player2.life == 0�̶�� ������ ����Ͽ���.
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
					printf("Player4 has Zero Life.\n"); //���� �Է¹��� player ID�� Life�� 0�̶�� player�� ������� 0�̶�� ������ ����� �� �ݺ����� �ٽ� ����.
				}
			}


			// �� ���� ������ ID�� Player5�� �Է����� ����̴�. �� ������ �ڵ�� player4�� �����ϴ�.
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



			// �� ���� ������ ID�� Player6���� �Է����� ����̴�. �� ������ �ڵ�� player4�� �����ϴ�.
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

		}while(flag != 0); // flag�� 0�̵Ǵ� ������ �� ó�� ���ù��� Fati ���� ������ Life�� 0�� �Ǿ��� ���̴�. �� ��� �ݺ����� �����ϸ鼭 flag�� �ٽ� 1�� �ǰ�, ���� do-while�ݺ����� ����.



		flag = 1;

		// �� �ݺ����� Fati���� ����� ����ϴ� �ڵ��̴�. ������ Amor���� �ڵ�� �����ϴ�. �ٸ� �ڵ尡 ����Ǵ� ���Ǹ� �޶�����.(�̰͸� �ּ�ó��)
		do {

			if (player1.life != 0) {
				printf ("Opponent : Player1 \n");
				printf("\n");

				// player4�� ������ 0�� �ƴϰ�, player6�� ������ 0�� �� ���ǹ��� �����Ѵ�. player6�� ������ 0�̿��� ����Ǵ� ������ �� ó�� player1�� ����ڷ� player6�� �������� ����̴�.
				// �� �ڵ带 © �� player4���� ���������� 4,5,6�������, player5���� ���������� 5,6,4�� ������ ���� ����ǰ� �����Ͽ����Ƿ�, ���ǿ� player6�� ������ 0�̵ǵ��� �����Ͽ���.
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

		Amor_Life = player1.life + player2.life + player3.life; //Amor���� �� ������� ����Ѵ�.
		Fati_Life = player4.life + player5.life + player6.life; //Fati���� �� ������� ����Ѵ�.

	}while(Amor_Life != 0 && Fati_Life != 0); //���� Amor���̳� Fati���� ������� �� ���� �ϳ��� 0�� �ȴٸ� �ݺ����� Ż���Ѵ�.

	// �� ���� ������� ����ϰ�, �̱����� ����Ѵ�.
	printf("Amor_Life : %d \n" , Amor_Life);
	printf("Fati_Life : %d \n" , Fati_Life);

	if (Amor_Life > Fati_Life) {
		printf("AmorTeam WIn!");
	}
	else if (Amor_Life < Fati_Life) {
		printf("FatiTeam WIn!");
	}
}




