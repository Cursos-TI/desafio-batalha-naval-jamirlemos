#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int tabuleiro[10][10] = { 0 };                                                // Inicializa o tabuleiro 10X10 com zeros
    char coordenadaX[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };  // Inicializa as Letras das colunas como coordenada
    int erro = 0;
  
    // Coordenadas iniciais dos navios
    int linhaNavioH = 2, colunaNavioH = 3;  // Navio horizontal começa em D3
    int linhaNavioV = 5, colunaNavioV = 7;  // Navio vertical começa em H6
  
    // Validação do navio horizontal (3 posições dentro do tabuleiro com 10 posições)
    if (colunaNavioH + 2 >= 10) { // Como o Navio já tem o início de sua posição
      printf("Erro: navio horizontal fora dos limites do tabuleiro!\n");
      erro = 1; // variavel erro recebe o valor 1, caso a posição do navio extrapole o tabuleiro
    }
  
    // Validação do navio vertical (3 posições dentro do tabuleiro com 10 posições)
    if (linhaNavioV + 2 >= 10) { // Como o Navio já tem o início de sua posição
      printf("Erro: navio vertical fora dos limites do tabuleiro!\n");
      erro = 1; // variavel erro recebe o valor 1, caso a posição do navio extrapole o tabuleiro
    }
  
      // Se não houver erro, posiciona os navios
      if (!erro) { // mesma coisa de erro == 0;
        for (int i = 0; i < 3; i++) { // loop percorrendo o tamanho de um navio
          tabuleiro[linhaNavioH][colunaNavioH + i] += 3;       // Posiciona navio horizontal
          tabuleiro[linhaNavioV + i][colunaNavioV] += 3;       // Posiciona navio vertical
          }
      }
  
    // Verifica se há sobreposição dos navios
    for (int i = 0; i < 10; i++) {     // loop para percorrer as linhas (A-J) da matriz do tabuleiro.
      for (int j = 0; j < 10; j++) {  // loop para percorrer as colunas(1-10) da matriz do tabuleiro.
        if (tabuleiro[i][j] > 3) {    // condicional para verificar a coordenada é maior que 3.
          printf("Erro: sobreposição de navios detectada na posição %c%d!\n", coordenadaX[j], i + 1);
          erro = 1;
        }
      }
    }

      // Imprime o cabeçalho das colunas (coordenadas X)
      printf("\t");  // Espaço inicial para alinhar com os números das linhas
      for (int l = 0; l < 10; l++) {
        printf("%c\t", coordenadaX[l]);
      }
      printf("\n\n\n"); // imprime 3 linhas abaixo
  
      // Imprime o tabuleiro com os números das linhas (coordenadas Y)
      for (int i = 0; i < 10; i++) {
        printf("%d\t", i + 1);  // Imprime o número da linha (1 a 10)
        for (int j = 0; j < 10; j++) {
          printf("%d\t", tabuleiro[i][j]);  // Imprime o valor da célula
        }
        printf("\n\n\n");  // Pula 3 linhas após cada linha do tabuleiro
      }
    
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

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
