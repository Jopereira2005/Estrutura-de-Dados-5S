#ifndef MAPA_H
#define MAPA_H

#define MAX_LINHAS 40
#define MAX_COLUNAS 40

typedef struct {
  char local[MAX_LINHAS][MAX_COLUNAS];
  int linhas;
  int colunas;
} Mapa;

// Prototipos das funcoes do mapa
int carrega_mapa(Mapa *m, const char *caminho_arquivo);
void imprime_mapa(Mapa *m);

#endif