#include <stdio.h>

#define BOARD_SIZE 10

// Enum para tipos de células no tabuleiro
typedef enum {
    CELULA_VAZIA = 0,
    NAVIO = 3,
    HABILIDADE = 1
} CellType;

// Função para inicializar (zerar) o tabuleiro
void InicializarTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = CELULA_VAZIA;
}

// Função para exibir o tabuleiro no console
void ExibirTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Funções para posicionar navios
void PosicionarNavioHorizontal(int board[BOARD_SIZE][BOARD_SIZE], int linha, int colunaInicio, int comprimento) {
    for (int j = colunaInicio; j < colunaInicio + comprimento && j < BOARD_SIZE; j++) {
        board[linha][j] = NAVIO;
    }
}

void PosicionarNavioVertical(int board[BOARD_SIZE][BOARD_SIZE], int linhaInicio, int coluna, int comprimento) {
    for (int i = linhaInicio; i < linhaInicio + comprimento && i < BOARD_SIZE; i++) {
        board[i][coluna] = NAVIO;
    }
}

void PosicionarNavioDiagonalPrincipal(int board[BOARD_SIZE][BOARD_SIZE], int linhaInicio, int colunaInicio, int comprimento) {
    for (int i = 0; i < comprimento && (linhaInicio + i) < BOARD_SIZE && (colunaInicio + i) < BOARD_SIZE; i++) {
        board[linhaInicio + i][colunaInicio + i] = NAVIO;
    }
}

void PosicionarNavioDiagonalSecundaria(int board[BOARD_SIZE][BOARD_SIZE], int linhaInicio, int colunaInicio, int comprimento) {
    for (int i = 0; i < comprimento && (linhaInicio + i) < BOARD_SIZE && (colunaInicio - i) >= 0; i++) {
        board[linhaInicio + i][colunaInicio - i] = NAVIO;
    }
}

// Funções para habilidades especiais
void HabilidadeCruz(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][y] = HABILIDADE;
        board[x][i] = HABILIDADE;
    }
}

void HabilidadeCone(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    // Verifica se posição válida para desenhar o cone
    if (x + 2 >= BOARD_SIZE || y - 2 < 0 || y + 2 >= BOARD_SIZE) return;

    board[x][y] = HABILIDADE;

    board[x + 1][y - 1] = HABILIDADE;
    board[x + 1][y] = HABILIDADE;
    board[x + 1][y + 1] = HABILIDADE;

    for (int j = y - 2; j <= y + 2; j++) {
        board[x + 2][j] = HABILIDADE;
    }
}

void HabilidadeOctaedro(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if (x < 1 || x >= BOARD_SIZE - 1 || y < 1 || y >= BOARD_SIZE - 1) return;

    board[x - 1][y] = HABILIDADE;
    board[x][y - 1] = HABILIDADE;
    board[x][y] = HABILIDADE;
    board[x][y + 1] = HABILIDADE;
    board[x + 1][y] = HABILIDADE;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    // --- NÍVEL NOVATO ---
    printf("NÍVEL NOVATO - Tabuleiro 5x5 com navios\n");
    int boardNovato[5][5] = {0};

    // Navio horizontal (linha 1, colunas 0-2)
    PosicionarNavioHorizontal(boardNovato, 1, 0, 3);

    // Navio vertical (coluna 3, linhas 2-4)
    PosicionarNavioVertical(boardNovato, 2, 3, 3);

    // Exibir board novato
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", boardNovato[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // --- NÍVEL AVENTUREIRO ---
    printf("NÍVEL AVENTUREIRO - Tabuleiro 10x10 com navios diagonais\n");
    InicializarTabuleiro(board);

    PosicionarNavioHorizontal(board, 2, 1, 3);       // horizontal linha 2
    PosicionarNavioVertical(board, 5, 5, 3);         // vertical coluna 5
    PosicionarNavioDiagonalPrincipal(board, 0, 0, 3);// diagonal principal topo-esquerda
    PosicionarNavioDiagonalSecundaria(board, 0, 9, 3);// diagonal secundária topo-direita

    ExibirTabuleiro(board);

    // --- NÍVEL MESTRE ---
    printf("NÍVEL MESTRE - Habilidade em CRUZ\n");
    InicializarTabuleiro(board);
    HabilidadeCruz(board, 4, 4);
    ExibirTabuleiro(board);

    printf("NÍVEL MESTRE - Habilidade em CONE\n");
    InicializarTabuleiro(board);
    HabilidadeCone(board, 2, 4);
    ExibirTabuleiro(board);

    printf("NÍVEL MESTRE - Habilidade em OCTAEDRO\n");
    InicializarTabuleiro(board);
    HabilidadeOctaedro(board, 4, 4);
    ExibirTabuleiro(board);

    return 0;
}
#include <stdio.h>

#define BOARD_SIZE 10

// Enum para tipos de células no tabuleiro
typedef enum {
    CELULA_VAZIA = 0,
    NAVIO = 3,
    HABILIDADE = 1
} CellType;

// Função para inicializar (zerar) o tabuleiro
void InicializarTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = CELULA_VAZIA;
}

// Função para exibir o tabuleiro no console
void ExibirTabuleiro(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Funções para posicionar navios
void PosicionarNavioHorizontal(int board[BOARD_SIZE][BOARD_SIZE], int linha, int colunaInicio, int comprimento) {
    for (int j = colunaInicio; j < colunaInicio + comprimento && j < BOARD_SIZE; j++) {
        board[linha][j] = NAVIO;
    }
}

void PosicionarNavioVertical(int board[BOARD_SIZE][BOARD_SIZE], int linhaInicio, int coluna, int comprimento) {
    for (int i = linhaInicio; i < linhaInicio + comprimento && i < BOARD_SIZE; i++) {
        board[i][coluna] = NAVIO;
    }
}

void PosicionarNavioDiagonalPrincipal(int board[BOARD_SIZE][BOARD_SIZE], int linhaInicio, int colunaInicio, int comprimento) {
    for (int i = 0; i < comprimento && (linhaInicio + i) < BOARD_SIZE && (colunaInicio + i) < BOARD_SIZE; i++) {
        board[linhaInicio + i][colunaInicio + i] = NAVIO;
    }
}

void PosicionarNavioDiagonalSecundaria(int board[BOARD_SIZE][BOARD_SIZE], int linhaInicio, int colunaInicio, int comprimento) {
    for (int i = 0; i < comprimento && (linhaInicio + i) < BOARD_SIZE && (colunaInicio - i) >= 0; i++) {
        board[linhaInicio + i][colunaInicio - i] = NAVIO;
    }
}

// Funções para habilidades especiais
void HabilidadeCruz(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i][y] = HABILIDADE;
        board[x][i] = HABILIDADE;
    }
}

void HabilidadeCone(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    // Verifica se posição válida para desenhar o cone
    if (x + 2 >= BOARD_SIZE || y - 2 < 0 || y + 2 >= BOARD_SIZE) return;

    board[x][y] = HABILIDADE;

    board[x + 1][y - 1] = HABILIDADE;
    board[x + 1][y] = HABILIDADE;
    board[x + 1][y + 1] = HABILIDADE;

    for (int j = y - 2; j <= y + 2; j++) {
        board[x + 2][j] = HABILIDADE;
    }
}

void HabilidadeOctaedro(int board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if (x < 1 || x >= BOARD_SIZE - 1 || y < 1 || y >= BOARD_SIZE - 1) return;

    board[x - 1][y] = HABILIDADE;
    board[x][y - 1] = HABILIDADE;
    board[x][y] = HABILIDADE;
    board[x][y + 1] = HABILIDADE;
    board[x + 1][y] = HABILIDADE;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];

    // --- NÍVEL NOVATO ---
    printf("NÍVEL NOVATO - Tabuleiro 5x5 com navios\n");
    int boardNovato[5][5] = {0};

    // Navio horizontal (linha 1, colunas 0-2)
    PosicionarNavioHorizontal(boardNovato, 1, 0, 3);

    // Navio vertical (coluna 3, linhas 2-4)
    PosicionarNavioVertical(boardNovato, 2, 3, 3);

    // Exibir board novato
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", boardNovato[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // --- NÍVEL AVENTUREIRO ---
    printf("NÍVEL AVENTUREIRO - Tabuleiro 10x10 com navios diagonais\n");
    InicializarTabuleiro(board);

    PosicionarNavioHorizontal(board, 2, 1, 3);       // horizontal linha 2
    PosicionarNavioVertical(board, 5, 5, 3);         // vertical coluna 5
    PosicionarNavioDiagonalPrincipal(board, 0, 0, 3);// diagonal principal topo-esquerda
    PosicionarNavioDiagonalSecundaria(board, 0, 9, 3);// diagonal secundária topo-direita

    ExibirTabuleiro(board);

    // --- NÍVEL MESTRE ---
    printf("NÍVEL MESTRE - Habilidade em CRUZ\n");
    InicializarTabuleiro(board);
    HabilidadeCruz(board, 4, 4);
    ExibirTabuleiro(board);

    printf("NÍVEL MESTRE - Habilidade em CONE\n");
    InicializarTabuleiro(board);
    HabilidadeCone(board, 2, 4);
    ExibirTabuleiro(board);

    printf("NÍVEL MESTRE - Habilidade em OCTAEDRO\n");
    InicializarTabuleiro(board);
    HabilidadeOctaedro(board, 4, 4);
    ExibirTabuleiro(board);

    return 0;
}
