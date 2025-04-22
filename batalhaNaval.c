#include <stdio.h>
// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define tamanhoNavio 3       // constante para definir o tamanho do Navio.
#define tamanhoTabuleiro 10  // constante para definir o tamanho do Tabuleiro.
#define linhaHabilidade 3    // constante para definir o tamanho da linha da Habilidade.
#define colunaHabilidade 5   // constante para definir o tamanho da coluna da Habilidade.


int main() {
  // Nível Mestre - Habilidades Especiais com Matrizes
  // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
  // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
  // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

  int tabuleiro[10][10] = { 0 };                                                // Inicializa o tabuleiro 10X10 com zeros.
  char coordenadaX[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };  // Inicializa as Letras das colunas como coordenada.
  int cone[linhaHabilidade][colunaHabilidade] = { 0 };                          // Inicializa a matriz cone com zeros.
  int cruz[linhaHabilidade][colunaHabilidade] = { 0 };                          // Inicializa a matriz cruz com zeros.
  int octaedro[linhaHabilidade][colunaHabilidade] = { 0 };                      // Inicializa a matriz octaedro com zeros.

  int erro = 0;                   // Verificador de erro.
  int sobreposicaoDetectada = 0;  // Verificador de sobreposição.

  // Coordenadas iniciais dos navios.
  int linhaNavioH = 0, colunaNavioH = 1;    // Navio horizontal começa em B1.
  int linhaNavioV = 0, colunaNavioV = 5;    // Navio vertical começa em F1.
  int linhaNavioDs = 2, colunaNavioDs = 7;  // Navio Diagonal começa em H3.
  int linhaNavioDd = 1, colunaNavioDd = 0;  // Navio Diagonal começa em A2.

  // Coordenadas iniciais das habilidades.
  int Linha_cone = 3, Coluna_cone = 7;          // linha e coluna onde a habilidade cone será aplicada.
  int Linha_cruz = 6, Coluna_cruz = 2;          // linha e coluna onde a habilidade cruz será aplicada.
  int Linha_octaedro = 8, Coluna_octaedro = 7;  // linha e coluna onde a habilidade octaedro será aplicada.

  // Validação e posicionamento do navio horizontal.
  for (int i = 0; i < tamanhoNavio; i++) {  // Verifica se há espaço para o navio horizontal e se não há sobreposição.
    if (colunaNavioH + i >= tamanhoTabuleiro) {
      printf("Erro: navio horizontal fora dos limites do tabuleiro!\n");
      erro = 1;
      break;
    }
    if (tabuleiro[linhaNavioH][colunaNavioH + i] > tamanhoNavio) {  // Verifica se a posição já está ocupada por uma parte de um navio.
      printf("Erro: sobreposição detectada no navio horizontal!\n");
      erro = 1;
      break;
    }
    tabuleiro[linhaNavioH][colunaNavioH + i] += tamanhoNavio;  // Posiciona navio horizontal.
  }

  // Validação e posicionamento do navio vertical.
  for (int i = 0; i < tamanhoNavio; i++) {  // Verifica se há espaço para o navio vertical e se não há sobreposição.
    if (linhaNavioV + i >= tamanhoTabuleiro) {
      printf("Erro: navio vertical fora dos limites do tabuleiro!\n");
      erro = 1;
      break;
    }
    if (tabuleiro[linhaNavioV + i][colunaNavioV] > tamanhoNavio) {  // Verifica se a posição já está ocupada por uma parte de um navio.
      printf("Erro: sobreposição detectada no navio vertical!\n");
      erro = 1;
      break;
    }
    tabuleiro[linhaNavioV + i][colunaNavioV] += tamanhoNavio;  // Posiciona navio vertical.
  }

  // Validação e posicionamento do navio diagonal (subindo).
  for (int i = 0; i < tamanhoNavio; i++) {  // Verifica se há espaço para o navio diagonal subindo.
    if (linhaNavioDs - i < 0 || colunaNavioDs + i >= tamanhoTabuleiro) {
      printf("Erro: navio diagonal subindo fora dos limites do tabuleiro!\n");
      erro = 1;
      break;
    }
    if (tabuleiro[linhaNavioDs - i][colunaNavioDs + i] > tamanhoNavio) {  // Verifica se a posição já está ocupada por uma parte de um navio.
      printf("Erro: sobreposição detectada no navio diagonal subindo!\n");
      erro = 1;
      break;
    }
    tabuleiro[linhaNavioDs - i][colunaNavioDs + i] += tamanhoNavio;  // Posiciona navio diagonal subindo.
  }

  // Validação e posicionamento do navio diagonal (descendo).
  for (int i = 0; i < tamanhoNavio; i++) {  // Verifica se há espaço para o navio diagonal descendo.
    if (linhaNavioDd + i >= tamanhoTabuleiro || colunaNavioDd + i >= tamanhoTabuleiro) {
      printf("Erro: navio diagonal descendo fora dos limites do tabuleiro!\n");
      erro = 1;
      break;
    }
    if (tabuleiro[linhaNavioDd + i][colunaNavioDd + i] > tamanhoNavio) {  // Verifica se a posição já está ocupada por uma parte de um navio.
      printf("Erro: sobreposição detectada no navio diagonal descendo!\n");
      erro = 1;  // erro recebe 1
      break;
    }
    tabuleiro[linhaNavioDd + i][colunaNavioDd + i] += tamanhoNavio;  // Posiciona navio diagonal descendo.
  }

  // Verifica se a matriz cone cabe no tabuleiro a partir da origem.
  if (Linha_cone + linhaHabilidade - 1 >= tamanhoTabuleiro || Coluna_cone - (linhaHabilidade - 1) < 0 || Coluna_cone + (linhaHabilidade - 1) >= tamanhoTabuleiro) {
    printf("Erro: habilidade cone fora dos limites do tabuleiro!\n");
    erro = 1;  // erro recebe 1
  }

  // Validação para verificar se a cruz cabe no tabuleiro a partir da origem.
  if (Linha_cruz - 1 < 0 || Linha_cruz + 1 >= tamanhoTabuleiro || Coluna_cruz - 2 < 0 || Coluna_cruz + 2 >= tamanhoTabuleiro) {
    printf("Erro: habilidade cruz fora dos limites do tabuleiro!\n");
    erro = 1;  // erro recebe 1
  }

  // Validação para verificar se o octaedro cabe no tabuleiro a partir da origem.
  if (Linha_octaedro - 1 < 0 || Linha_octaedro + 1 >= tamanhoTabuleiro || Coluna_octaedro - 1 < 0 || Coluna_octaedro + 1 >= tamanhoTabuleiro) {
    printf("Erro: habilidade octaedro fora dos limites do tabuleiro!\n");
    erro = 1;
  }

  if (erro) return 0;  // Se houver erro de limites ou sobreposição, encerra o programa.

  // Preenche a matriz cone com base no centro expandindo em forma de cone.
  for (int i = 0; i < linhaHabilidade; i++) {
    for (int j = 0; j < colunaHabilidade; j++) {
      if (j >= 2 - i && j <= 2 + i) {  // Se a posição estiver dentro do alcance lateral do cone.
        cone[i][j] = 1;                // Marca como área atingida pela habilidade.
      }
    }
  }

  // Aplica a habilidade cone no tabuleiro com base na origem.
  for (int i = 0; i < linhaHabilidade; i++) {
    for (int j = 0; j < colunaHabilidade; j++) {
      if (cone[i][j] == 1) {
        int linhaAfetada = Linha_cone + i;          // Aplica o deslocamento vertical.
        int colunaAfetada = Coluna_cone + (j - 2);  // Aplica o deslocamento horizontal.

        // Aplica diretamente a habilidade no tabuleiro, sem a verificação de limites, pois já foi validado anteriormente.
        tabuleiro[linhaAfetada][colunaAfetada] = 1;  // Marca a célula do tabuleiro como atingida.
      }
    }
  }

  // Preenche a matriz cruz para formar o padrão da cruz
  for (int i = 0; i < linhaHabilidade; i++) {
    for (int j = 0; j < colunaHabilidade; j++) {
      if (i == 1 || j == 2) {  // Linha central e coluna central
        cruz[i][j] = 1;        // Marca as posições da cruz como 1
      }
    }
  }

  // Aplica a habilidade cruz no tabuleiro.
  for (int i = 0; i < linhaHabilidade; i++) {
    for (int j = 0; j < colunaHabilidade; j++) {
      if (cruz[i][j] == 1) {
        int linhaAfetada = Linha_cruz + i - 1;    // Ajusta o deslocamento vertical.
        int colunaAfetada = Coluna_cruz + j - 2;  // Ajusta o deslocamento horizontal.

        tabuleiro[linhaAfetada][colunaAfetada] = 1;  // Marca o tabuleiro com a habilidade.
      }
    }
  }

  // Preenche a matriz octaedro com o formato 3x5 em padrão diamante.
  for (int i = 0; i < linhaHabilidade; i++) {
    for (int j = 0; j < colunaHabilidade; j++) {
      if ((i == 0 && j == 2) || (i == 1 && (j >= 1 && j <= 3)) || (i == 2 && j == 2)) {
        octaedro[i][j] = 1;
      }
    }
  }

  // Aplica a habilidade octaedro no tabuleiro com base na origem.
  for (int i = 0; i < linhaHabilidade; i++) {
    for (int j = 0; j < colunaHabilidade; j++) {
      if (octaedro[i][j] == 1) {
        int linhaAfetada = Linha_octaedro + i - 1;    // Ajuste vertical com base no centro.
        int colunaAfetada = Coluna_octaedro + j - 2;  // Ajuste horizontal com base no centro.
        tabuleiro[linhaAfetada][colunaAfetada] = 1;   // Marca a célula como atingida.
      }
    }
  }

  // Imprime o cabeçalho das colunas (coordenadas X).
  printf("\t");  // Espaço inicial para alinhar com os números das linhas.
  for (int l = 0; l < tamanhoTabuleiro; l++) {
    printf("%c\t", coordenadaX[l]);
  }
  printf("\n\n\n");  // imprime tamanhoNavio linhas abaixo.

  // Imprime o tabuleiro com os números das linhas (coordenadas Y).
  for (int i = 0; i < tamanhoTabuleiro; i++) {
    printf("%d\t", i + 1);  // Imprime o número da linha (1 a 10).
    for (int j = 0; j < tamanhoTabuleiro; j++) {
      printf("%d\t", tabuleiro[i][j]);  // Imprime o valor da célula.
    }
    printf("\n\n\n");  // Pula tamanhoNavio linhas após cada linha do tabuleiro.
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
