#include <stdio.h>
#include <stdlib.h>

void aplicaHabilidade(int tab[10][10], int hab[3][5], int linha, int coluna) {
//procedimento para aplicar a habilidade no tabuleiro...


	if (((linha - 1) < 0) || ((coluna - 2) < 0)) {
		printf("Erro! Coordenada invalida para habilidade ");
		exit(1);
	}

	if (((linha + 1) > 9) || ((coluna + 2) > 9 )) {
		printf("Erro! Coordenada invalida para habilidade ");
		exit(1);
	}

	for (int i = linha - 1; i <= linha + 1; i++) {
		for (int j = coluna - 2; j <= coluna + 2; j++) {
			int indVer = 1 + i - linha;
			int indHor = 2 + j - coluna;
			if (hab[indVer][indHor] == 1) {
				tab[i][j] = 5;
			}
			//printf("Linha=%d, Coluna=%d, Indver=%d, indHor=%d\n",i,j, indVer, indHor);
		}
	}

}

int main() {

	//tamanho dos objetos...
	const int TAMANHO_TABULEIRO = 10;
	const int TAMANHO_NAVIO = 3;
	const int TAMANHO_HAB = 5;

	//Coordenadas iniciais dos navios...
	const int LINHA_NAVIO_H = 9;
	const int COLUNA_NAVIO_H = 7;
	const int LINHA_NAVIO_V = 0;
	const int COLUNA_NAVIO_V = 0;
	const int LINHA_NAVIO_D1 = 4;
	const int COLUNA_NAVIO_D1 = 4;
	const int LINHA_NAVIO_D2 = 6;
	const int COLUNA_NAVIO_D2 = 4;


	//indicadores...
	const int INDICADOR_AGUA = 0;
	const int INDICADOR_NAVIO = 3;
	const int INDICADOR_HABILIDADE = 5;

	int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
	int navio_H[TAMANHO_NAVIO] = { INDICADOR_NAVIO, INDICADOR_NAVIO, INDICADOR_NAVIO };
	int navio_V[TAMANHO_NAVIO] = { INDICADOR_NAVIO, INDICADOR_NAVIO, INDICADOR_NAVIO };
	int navio_D[TAMANHO_NAVIO] = { INDICADOR_NAVIO, INDICADOR_NAVIO, INDICADOR_NAVIO };
	int habCone[3][TAMANHO_HAB];
	int habCruz[3][TAMANHO_HAB];
	int habOcta[3][TAMANHO_HAB];

	//inicializa o tabuleiro com agua em todas as casas...
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tabuleiro[i][j] = INDICADOR_AGUA;
		}
	}

	//posiciona o navio vertical...
	if ((LINHA_NAVIO_V < 0) || (COLUNA_NAVIO_V < 0)) {
		printf("Erro! Coordenada invalida para navio vertical.");
		exit(1);
	}
	if (((LINHA_NAVIO_V + (TAMANHO_NAVIO - 1)) > (TAMANHO_TABULEIRO - 1)) || (COLUNA_NAVIO_V > (TAMANHO_TABULEIRO - 1))) {
		printf("Erro! Coordenada invalida para navio vertical.");
		exit(1);
	}
	for (int i = 0; i < TAMANHO_NAVIO; i++) {
		tabuleiro[i][COLUNA_NAVIO_V] = navio_V[i];

	}

	//posicionando o navio horizontal...
	if ((LINHA_NAVIO_H < 0) || (COLUNA_NAVIO_H < 0)) {
		printf("Erro! Coordenada invalida para navio horizontal - negativa.");
		exit(1);
	}
	if ((LINHA_NAVIO_H > (TAMANHO_TABULEIRO - 1)) || ((COLUNA_NAVIO_H + (TAMANHO_NAVIO - 1)) > (TAMANHO_TABULEIRO - 1))) {
		printf("Erro! Coordenada invalida para navio horizontal.");
		exit(1);
	}
	for (int i = 0; i < 3;i++) {
		if (tabuleiro[LINHA_NAVIO_H][COLUNA_NAVIO_H + i] == INDICADOR_AGUA) {
			tabuleiro[LINHA_NAVIO_H][COLUNA_NAVIO_H + i] = navio_H[i];
		}
		else {
			printf("Erro! Um navio esta soprepondo o outro.");
			exit(1);
		}
	}

	//posicionando o navio diagonal 1...
	if ((LINHA_NAVIO_D1 < 0) || (COLUNA_NAVIO_D1 < 0)) {
		printf("Erro! Coordenada invalida para navio diagonal - negativa.");
		exit(1);
	}
	if (((LINHA_NAVIO_D1 + (TAMANHO_NAVIO - 1)) > (TAMANHO_TABULEIRO - 1)) || ((COLUNA_NAVIO_D1 + (TAMANHO_NAVIO - 1)) > (TAMANHO_TABULEIRO - 1))) {
		printf("Erro! Coordenada invalida para navio diagonal.");
		exit(1);
	}
	for (int i = 0; i < 3;i++) {
		if (tabuleiro[LINHA_NAVIO_D1 + i][COLUNA_NAVIO_D1 + i] == INDICADOR_AGUA) {
			tabuleiro[LINHA_NAVIO_D1 + i][COLUNA_NAVIO_D1 + i] = navio_D[i];
		}
		else {
			printf("Erro! Um navio esta soprepondo o outro.");
			exit(1);
		}
	}

	//posicionando o navio diagonal 2...
	if ((LINHA_NAVIO_D2 < 0) || (COLUNA_NAVIO_D2 < 0)) {
		printf("Erro! Coordenada invalida para navio diagonal - negativa.");
		exit(1);
	}
	if (((LINHA_NAVIO_D2 + (TAMANHO_NAVIO - 1)) > (TAMANHO_TABULEIRO - 1)) || ((COLUNA_NAVIO_D2 + (TAMANHO_NAVIO - 1)) > (TAMANHO_TABULEIRO - 1))) {
		printf("Erro! Coordenada invalida para navio diagonal.");
		exit(1);
	}
	for (int i = 0; i < 3;i++) {
		if (tabuleiro[LINHA_NAVIO_D2 + i][COLUNA_NAVIO_D2 + i] == INDICADOR_AGUA) {
			tabuleiro[LINHA_NAVIO_D2 + i][COLUNA_NAVIO_D2 + i] = navio_D[i];
		}
		else {
			printf("Erro! Um navio esta soprepondo o outro.");
			exit(1);
		}
	}

	//criacao da matriz habilidade - cone... OK, testado
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < TAMANHO_HAB; j++) {
			if (((i == 0) && (j == 2)) || ((i == 1) && (j > 0) && (j < 4)) || (i == 2)) {
				habCone[i][j] = 1;
			} else {
				habCone[i][j] = INDICADOR_AGUA;
			}
		}
	}

	//criacao de matriz de habilidade - cruz... Ok, testado
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < TAMANHO_HAB; j++) {
			if (((i == 0) && (j == 2)) || (i == 1) || ((i == 2) && (j==2))) {
				habCruz[i][j] = 1;
			}
			else {
				habCruz[i][j] = INDICADOR_AGUA;
			}
		}
	}

	//criacao de matriz de habilidade - octaedro... ok, testado
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < TAMANHO_HAB; j++) {
			if (((i == 0) && (j == 2)) || ( (i == 1) && (j >0 ) && (j < 4))|| ((i == 2) && (j == 2))) {
				habOcta[i][j] = 1;
			}
			else {
				habOcta[i][j] = INDICADOR_AGUA;
			}
		}
	}


	//aplica as habilidades no tabuleiro...
	aplicaHabilidade(tabuleiro, habOcta, 4, 4);
	aplicaHabilidade(tabuleiro, habCone, 1, 3);
	aplicaHabilidade(tabuleiro, habCruz, 8, 2);


	//imprime o tabuleiro...
	printf("Imprimindo o tabuleiro...\n");
	for (int i = 0; i < 10; i++) {
		printf("\t%d", i);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%d", i);
		for (int j = 0; j < 10;j++) {
			printf("\t%d", tabuleiro[i][j]);
		}
		printf("\n");
	}

	return 0;
}
