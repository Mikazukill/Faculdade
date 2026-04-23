#include <stdio.h>

#define MAX_ENUNCIADO 100
#define MAX_QUESTOES 60

#define FALSO      0
#define VERDADEIRO 1

typedef enum {
  FACIL, MEDIA, DIFICIL
} nivel_t;


typedef struct {
  nivel_t nivel;
  char enunciado[MAX_ENUNCIADO+1];
  int resposta;
} questao_t;

questao_t questoes[MAX_QUESTOES] = {
  { FACIL, "Em C, uma string é um vetor de caracteres terminado por '\\0'.", VERDADEIRO },
  { FACIL, "O caractere '\\0' indica o início de uma string em C.", FALSO },
  { FACIL, "Strings em C são armazenadas em posições de memória sequenciais.", VERDADEIRO },
  { FACIL, "O especificador %s é usado para imprimir strings com printf.", VERDADEIRO },
  { FACIL, "O compilador adiciona automaticamente '\\0' ao final de literais string.", VERDADEIRO },
  { FACIL, "Arrays podem armazenar dados de tipos diferentes.", FALSO },
  { FACIL, "Structs permitem agrupar dados de diferentes tipos.", VERDADEIRO },
  { FACIL, "Os campos de uma struct são acessados com o operador '.'.", VERDADEIRO },
  { FACIL, "Uma struct deve ser definida antes de ser usada.", VERDADEIRO },
  { FACIL, "typedef permite usar o nome da struct diretamente como tipo.", VERDADEIRO },
  { FACIL, "Unions armazenam simultaneamente todos os seus campos.", FALSO },
  { FACIL, "Enums são usados para definir constantes nomeadas.", VERDADEIRO },
  { FACIL, "strlen retorna o tamanho de uma string.", VERDADEIRO },
  { FACIL, "strcpy copia uma string incluindo o '\\0'.", VERDADEIRO },
  { FACIL, "strcat concatena duas strings.", VERDADEIRO },
  { FACIL, "strcmp compara duas strings.", VERDADEIRO },
  { FACIL, "strchr encontra a primeira ocorrência de um caractere.", VERDADEIRO },
  { FACIL, "strstr encontra uma substring dentro de outra string.", VERDADEIRO },
  { FACIL, "Enums começam sempre com valor 1 por padrão.", FALSO },
  { FACIL, "Structs são homogêneas.", FALSO },
  { MEDIA, "O tamanho de uma string em C inclui o caractere '\\0'.", FALSO },
  { MEDIA, "strncpy evita estouro de buffer ao limitar a cópia.", VERDADEIRO },
  { MEDIA, "strncat limita a quantidade de caracteres concatenados.", VERDADEIRO },
  { MEDIA, "strcmp retorna apenas verdadeiro ou falso.", FALSO },
  { MEDIA, "strchr retorna NULL se o caractere não for encontrado.", VERDADEIRO },
  { MEDIA, "strtok divide uma string em tokens com base em delimitadores.", VERDADEIRO },
  { MEDIA, "memcpy copia bytes entre áreas de memória.", VERDADEIRO },
  { MEDIA, "memset preenche memória com um valor específico.", VERDADEIRO },
  { MEDIA, "Structs podem ser atribuídas diretamente em C ANSI.", VERDADEIRO },
  { MEDIA, "Ao atribuir uma struct a outra, apenas o primeiro campo é copiado.", FALSO },
  { MEDIA, "Structs podem ser passadas por valor ou por referência.", VERDADEIRO },
  { MEDIA, "Passagem por referência usa ponteiros.", VERDADEIRO },
  { MEDIA, "O operador '->' acessa campos via ponteiro para struct.", VERDADEIRO },
  { MEDIA, "Em unions, o tamanho é a soma de todos os campos.", FALSO },
  { MEDIA, "Em unions, apenas um campo é válido por vez.", VERDADEIRO },
  { MEDIA, "Escrever em um campo de union sobrescreve os outros.", VERDADEIRO },
  { MEDIA, "Enums podem ter valores explicitamente definidos.", VERDADEIRO },
  { MEDIA, "Enums sempre precisam de typedef para serem usados.", FALSO },
  { MEDIA, "Arrays são estruturas heterogêneas.", FALSO },
  { MEDIA, "Uma struct pode conter arrays como campos.", VERDADEIRO },
  { DIFICIL, "strlen conta o '\\0' no tamanho retornado.", FALSO },
  { DIFICIL, "strncpy sempre adiciona '\\0' ao final da string destino.", FALSO },
  { DIFICIL, "strcmp retorna 0 quando as strings são iguais.", VERDADEIRO },
  { DIFICIL, "strncmp compara strings completas sempre.", FALSO },
  { DIFICIL, "strtok modifica a string original.", VERDADEIRO },
  { DIFICIL, "memcpy é segura para regiões de memória sobrepostas.", FALSO },
  { DIFICIL, "memset pode ser usada para inicializar strings com '\\0'.", VERDADEIRO },
  { DIFICIL, "Ao passar struct por valor, há cópia completa dos dados.", VERDADEIRO },
  { DIFICIL, "Passar struct por referência é mais eficiente em termos de memória.", VERDADEIRO },
  { DIFICIL, "(*ptr).campo e ptr->campo são equivalentes.", VERDADEIRO },
  { DIFICIL, "Em unions, todos os campos ocupam espaços distintos na memória.", FALSO },
  { DIFICIL, "O tamanho de uma union é determinado pelo maior campo.", VERDADEIRO },
  { DIFICIL, "Ler um campo diferente do último escrito em uma union é comportamento seguro.", FALSO },
  { DIFICIL, "Enums são armazenados internamente como inteiros.", VERDADEIRO },
  { DIFICIL, "Valores de enums sempre começam em 0, mesmo com atribuição explícita.", FALSO },
  { DIFICIL, "É possível iterar sobre enums usando incremento.", VERDADEIRO },
  { DIFICIL, "Uma string literal pode ser modificada diretamente.", FALSO },
  { DIFICIL, "Arrays de char inicializados com string literal incluem automaticamente '\\0'.", VERDADEIRO },
  { DIFICIL, "strcat não verifica limites do buffer destino.", VERDADEIRO },
  { DIFICIL, "strcpy é sempre segura independentemente do tamanho do destino.", FALSO }
};

int main() {
  
  for (int i=0; i<MAX_QUESTOES; ++i) {
      printf("%s\n", questoes[i].enunciado);
      if ( questoes[i].resposta )
         printf("> VERDADEIRO\n");
      else
         printf("> FALSO\n");
      printf("\n");
  }
  return 0;
}

