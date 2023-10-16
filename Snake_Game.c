#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

char gamearea[100][100];
int yilan[2][100] = {0};
char body[300];
int N,M,yemsayisi,i,j,yenilenYem = 0;
	
	printf("Oyun alaninin satir ve sutun sayilarini giriniz.(3'ten buyuk olacak sekilde)\nSatir sayisi: ");
	scanf("%d", &N);
	while(N<4){
		printf("Satir sayisini tekrar giriniz: ");
		scanf("%d", &N);
	}
	printf("Sutun Sayisi: ");
	scanf("%d", &M);
	while(M<4){
		printf("Sutun sayisini tekrar giriniz: ");
		scanf("%d", &M);
	}
int maxyem = ((M-2)*(N-2)-1);
	printf("(En fazla %d tane olacak sekilde) Yem sayisini giriniz: ", maxyem);
	scanf("%d", &yemsayisi);
	while(yemsayisi < 1 || yemsayisi > maxyem){
		printf("(En fazla %d tane olacak sekilde) Yem sayisini dogru giriniz: ", maxyem);
		scanf("%d", &yemsayisi);
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1){
                gamearea[i][j] = '*';
            } else {
                gamearea[i][j] = ' ';
            }
        }
    }
    int row,col;
    srand(time(0));
    
    	for (i = 0; i < yemsayisi; i++){
       		row = 1 + rand() % (N-2);
        	col = 1 + rand() % (M-2);
        	while(gamearea[row][col]=='0'){
        		row = 1 + rand() % (N-2);
        		col = 1 + rand() % (M-2);
			}
			gamearea[row][col] = '0';
		}
		row = 1 + rand() % (N-2);
        col = 1 + rand() % (M-2);
        while(gamearea[row][col]=='0'){
        	row = 1 + rand() % (N-2);
        	col = 1 + rand() % (M-2);
		}
    	gamearea[row][col] = '1';
    	yilan[0][0]=row;
    	yilan[1][0]=col;
   
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			printf(" %c", gamearea[i][j]);
		}
		printf("\n");
	}	
	
	for(i=0;i<300;i++){
		if(i>=0 && i<8){
			body[i]=i+50;
		}
		else if(i>=8 && i<=33){
			body[i]=i+89;
		}
		else if(i>=34 && i<=59){
			body[i]=i+31;
		}
		else{
			body[i]='o';
		}
	}
	int hamle = 0;
	int tmp1, tmp2, ctrl = 0, krow, kcol;
	char yon;
	while(ctrl == 0 && yemsayisi > 0){
		printf("\nKalan yem sayisi: %d\nYapilan hamle sayisi: %d\n(u=yukari, d=asagi, l=sol, r=sag)\nHamle yapiniz:", yemsayisi, hamle);
		scanf(" %c", &yon);
		while(yon != 'u' && yon != 'd' && yon != 'l' && yon != 'r'){
			printf("Yonu dogru giriniz:");
			scanf(" %c", &yon);
		}
		tmp1 = row;
		tmp2 = col;
		if(yon == 'u'){			
			row = row - 1;
		}
		else if(yon == 'd'){
			row = row + 1;
		}
		else if(yon == 'l'){
			col = col - 1;
		}
		else{
			col = col + 1;
		}
		hamle ++;
		if(gamearea[row][col] == '0' || gamearea[row][col] == ' '){
			if(gamearea[row][col] == '0'){
				yenilenYem++;
				yemsayisi --;
				gamearea[row][col] = '1';
				gamearea[tmp1][tmp2] = '*';
			}
			else{
				gamearea[row][col] = '1';
				gamearea[tmp1][tmp2] = ' ';
			}
			
			for(i=0;i<N;i++){
				for(j=0;j<M;j++){
					printf(" %c", gamearea[i][j]);
				}
				printf("\n");
			}
		}
		else{
			ctrl = -1;
		}
	}
	if(ctrl == -1){
		printf("Kaybettiniz!\n");
	}
	else if(yemsayisi == 0){
		printf("Kazandiniz!\n");
	}
	printf("Oyun bitti!\nCikmak icin bir tus giriniz: ");
	int p;
	scanf("%d", &p);
	return 0;
}
