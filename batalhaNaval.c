#include <stdio.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define tamanhoNavio 3      // constante para definir o tamanho do Navio.
#define tamanhoTabuleiro 10 // constante para definir o tamanho do Tabuleiro.
#define linhaHabilidade 3   // constante para definir o tamanho da linha da Habilidade.
#define colunaHabilidade 5  // constante para definir o tamanho da coluna da Habilidade.


int main() {
    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    int tabuleiro[10][10] = { 0 };                                                // Inicializa o tabuleiro 10X10 com zeros.
    char coordenadaX[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };  // Inicializa as Letras das colunas como coordenada.
    int cone[linhaHabilidade][colunaHabilidade];                                  // Inicializa a matriz cone


    int erro = 0; // Verificador de erro.
    int sobreposicaoDetectada = 0; // Verificador de sobreposição.

    // Coordenadas iniciais dos navios.
    int linhaNavioH = 0, colunaNavioH = 1;  // Navio horizontal começa em B6
    int linhaNavioV = 0, colunaNavioV = 5;  // Navio vertical começa em I7
    int linhaNavioDs = 2, colunaNavioDs = 7; // Navio Diagonal começa em A3
    int linhaNavioDd = 1, colunaNavioDd = 0; // Navio Diagonal começa em F7

    // Coordenadas iniciais das habilidades.
    int origemLinha = 3, origemColuna = 7; // linha e coluna onde a habilidade cone será aplicada.

    // Validação e posicionamento do navio horizontal
    for (int i = 0; i < tamanhoNavio; i++) { // Verifica se há espaço para o navio horizontal e se não há sobreposição
        if (colunaNavioH + i >= tamanhoTabuleiro) {
            printf("Erro: navio horizontal fora dos limites do tabuleiro!\n");
            erro = 1;
            break;
        }
        if (tabuleiro[linhaNavioH][colunaNavioH + i] != 0) { // Verifica se a posição já está ocupada
            printf("Erro: sobreposição detectada no navio horizontal!\n");
            erro = 1;
            break;
        }
        tabuleiro[linhaNavioH][colunaNavioH + i] += 3; // Posiciona navio horizontal
    }

    // Validação e posicionamento do navio vertical
    for (int i = 0; i < tamanhoNavio; i++) { // Verifica se há espaço para o navio vertical e se não há sobreposição
        if (linhaNavioV + i >= tamanhoTabuleiro) {
            printf("Erro: navio vertical fora dos limites do tabuleiro!\n");
            erro = 1;
            break;
        }
        if (tabuleiro[linhaNavioV + i][colunaNavioV] != 0) { // Verifica se a posição já está ocupada
            printf("Erro: sobreposição detectada no navio vertical!\n");
            erro = 1;
            break;
        }
        tabuleiro[linhaNavioV + i][colunaNavioV] += 3; // Posiciona navio vertical
    }

    // Validação e posicionamento do navio diagonal (subindo)
    for (int i = 0; i < tamanhoNavio; i++) { // Verifica se há espaço para o navio diagonal subindo
        if (linhaNavioDs - i < 0 || colunaNavioDs + i >= tamanhoTabuleiro) {
            printf("Erro: navio diagonal subindo fora dos limites do tabuleiro!\n");
            erro = 1;
            break;
        }
        if (tabuleiro[linhaNavioDs - i][colunaNavioDs + i] != 0) { // Verifica se a posição já está ocupada
            printf("Erro: sobreposição detectada no navio diagonal subindo!\n");
            erro = 1;
            break;
        }
        tabuleiro[linhaNavioDs - i][colunaNavioDs + i] += 3; // Posiciona navio diagonal subindo
    }

    // Validação e posicionamento do navio diagonal (descendo)
    for (int i = 0; i < tamanhoNavio; i++) { // Verifica se há espaço para o navio diagonal descendo
        if (linhaNavioDd + i >= tamanhoTabuleiro || colunaNavioDd + i >= tamanhoTabuleiro) {
            printf("Erro: navio diagonal descendo fora dos limites do tabuleiro!\n");
            erro = 1;
            break;
        }
        if (tabuleiro[linhaNavioDd + i][colunaNavioDd + i] != 0) { // Verifica se a posição já está ocupada
            printf("Erro: sobreposição detectada no navio diagonal descendo!\n");
            erro = 1;
            break;
        }
        tabuleiro[linhaNavioDd + i][colunaNavioDd + i] += 3; // Posiciona navio diagonal descendo
    }

    if (erro) return 0; // Se houve erro, encerra o programa.

    // Verifica se a matriz cone cabe no tabuleiro a partir da origem central
    if (origemLinha + linhaHabilidade - 1 >= tamanhoTabuleiro || origemColuna - (linhaHabilidade - 1) < 0 || origemColuna + (linhaHabilidade - 1) >= tamanhoTabuleiro) {
        printf("Erro: habilidade cone fora dos limites do tabuleiro!\n");
        return 0;
    }

    // Preenche a matriz cone com base no centro expandindo em forma de cone.
    for (int i = 0; i < linhaHabilidade; i++) {
        for (int j = 0; j < colunaHabilidade; j++) {
            if (j >= 2 - i && j <= 2 + i) { // Se a posição estiver dentro do alcance lateral do cone.
                cone[i][j] = 1;             // Marca como área atingida pela habilidade.
            } else {
                cone[i][j] = 0;             // Fora da área atingida pela habilidade.
            }
        }
    }

    // Aplica a habilidade cone no tabuleiro com base na origem
    for (int i = 0; i < linhaHabilidade; i++) {
        for (int j = 0; j < colunaHabilidade; j++) {
            if (cone[i][j] == 1) {
                int linhaAfetada = origemLinha + i; // Aplica o deslocamento vertical
                int colunaAfetada = origemColuna + (j - 2); // Aplica o deslocamento horizontal

                // Aplica diretamente a habilidade no tabuleiro, sem a verificação de limites, pois já foi validado anteriormente
                tabuleiro[linhaAfetada][colunaAfetada] = 1; // Marca a célula do tabuleiro como atingida
            }
        }
    }

    // Imprime o cabeçalho das colunas (coordenadas X)
    printf("\t");  // Espaço inicial para alinhar com os números das linhas
    for (int l = 0; l < tamanhoTabuleiro; l++) {
        printf("%c\t", coordenadaX[l]);
    }
    printf("\n\n\n"); // imprime 3 linhas abaixo

    // Imprime o tabuleiro com os números das linhas (coordenadas Y)
    for (int i = 0; i < tamanhoTabuleiro; i++) {
        printf("%d\t", i + 1);  // Imprime o número da linha (1 a 10)
        for (int j = 0; j < tamanhoTabuleiro; j++) {
            printf("%d\t", tabuleiro[i][j]);  // Imprime o valor da célula
        }
        printf("\n\n\n");  // Pula 3 linhas após cada linha do tabuleiro
    }

 // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
