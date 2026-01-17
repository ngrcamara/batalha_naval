#include <stdio.h>
#include <stdlib.h>

int main() {

	//tamanho dos objetos...
	const int TAMANHO_TABULEIRO = 10;
	const int TAMANHO_NAVIO = 3;

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

	int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
	int navio_H[TAMANHO_NAVIO] = { INDICADOR_NAVIO, INDICADOR_NAVIO, INDICADOR_NAVIO };
	int navio_V[TAMANHO_NAVIO] = { INDICADOR_NAVIO, INDICADOR_NAVIO, INDICADOR_NAVIO };
	int navio_D[TAMANHO_NAVIO] = { INDICADOR_NAVIO, INDICADOR_NAVIO, INDICADOR_NAVIO };


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
	if (((LINHA_NAVIO_D1 + (TAMANHO_NAVIO-1)) > (TAMANHO_TABULEIRO - 1)) || ((COLUNA_NAVIO_D1 + (TAMANHO_NAVIO - 1)) > (TAMANHO_TABULEIRO - 1))) {
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


	//imprime o tabuleiro...
	printf("Imprimindo o tabuleiro...\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10;j++) {
			printf("\t%d", tabuleiro[i][j]);
		}
		printf("\n");
	}

	return 0;
}
