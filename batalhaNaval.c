#include <stdio.h>

#define TAMANHO_TABULEIRO 10

// Função para exibir um tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para limpar o tabuleiro
void limparTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para desenhar uma habilidade em cruz
void habilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        tabuleiro[i][y] = 1;
        tabuleiro[x][i] = 1;
    }
}

// Função para desenhar uma habilidade em cone (simples, 3 linhas em pirâmide)
void habilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    if (x + 2 < TAMANHO_TABULEIRO && y >= 2 && y + 2 < TAMANHO_TABULEIRO) {
        tabuleiro[x][y] = 1;
        tabuleiro[x + 1][y - 1] = 1;
        tabuleiro[x + 1][y] = 1;
        tabuleiro[x + 1][y + 1] = 1;
        for (int j = y - 2; j <= y + 2; j++) {
            tabuleiro[x + 2][j] = 1;
        }
    }
}

// Função para desenhar uma habilidade em octaedro (forma de diamante)
void habilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    if (x >= 1 && x < TAMANHO_TABULEIRO - 1 && y >= 1 && y < TAMANHO_TABULEIRO - 1) {
        tabuleiro[x - 1][y] = 1;
        tabuleiro[x][y - 1] = 1;
        tabuleiro[x][y] = 1;
        tabuleiro[x][y + 1] = 1;
        tabuleiro[x + 1][y] = 1;
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    limparTabuleiro(tabuleiro);

    // NÍVEL NOVATO
    printf("NÍVEL NOVATO - Navios em tabuleiro 5x5\n");
    int tabuleiroNovato[5][5] = {0};

    // Navio horizontal na linha 1
    for (int j = 0; j < 3; j++) {
        tabuleiroNovato[1][j] = 3;
        printf("Navio horizontal em: (%d, %d)\n", 1, j);
    }

    // Navio vertical na coluna 3
    for (int i = 2; i < 5; i++) {
        tabuleiroNovato[i][3] = 3;
        printf("Navio vertical em: (%d, %d)\n", i, 3);
    }

    printf("\n");

    // NÍVEL AVENTUREIRO
    printf("NÍVEL AVENTUREIRO - Tabuleiro 10x10 com navios diagonais\n");
    limparTabuleiro(tabuleiro);

    // Navio horizontal
    for (int j = 1; j <= 3; j++) {
        tabuleiro[2][j] = 3;
    }

    // Navio vertical
    for (int i = 5; i <= 7; i++) {
        tabuleiro[i][5] = 3;
    }

    // Navio diagonal principal
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio diagonal secundária
    for (int i = 0; i < 3; i++) {
        tabuleiro[i][9 - i] = 3;
    }

    exibirTabuleiro(tabuleiro);

    // NÍVEL MESTRE - Habilidades especiais
    printf("NÍVEL MESTRE - Habilidade em CRUZ\n");
    limparTabuleiro(tabuleiro);
    habilidadeCruz(tabuleiro, 4, 4);
    exibirTabuleiro(tabuleiro);

    printf("NÍVEL MESTRE - Habilidade em CONE\n");
    limparTabuleiro(tabuleiro);
    habilidadeCone(tabuleiro, 2, 4);
    exibirTabuleiro(tabuleiro);

    printf("NÍVEL MESTRE - Habilidade em OCTAEDRO\n");
    limparTabuleiro(tabuleiro);
    habilidadeOctaedro(tabuleiro, 4, 4);
    exibirTabuleiro(tabuleiro);

    return 0;
}
