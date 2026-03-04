# TAD Sensor1D: armazenar e analisar 10 leituras de um sensor

  Contexto: Um braço robótico mede a temperatura do motor durante um curto teste. Você deve armazenar 10 leituras e calcular a média e o valor máximo, imprimindo os dados de forma organizada.

---

## Objetivos de aprendizagem

- Entender o conceito de TAD (separar o que faz do como faz).
- .h como interface (contrato) e .c como implementação.
- Usar vetor estático (sem alocação dinâmica).
- Funções simples: inicializar, inserir, imprimir, média e máximo.
- Programa principal que usa o TAD sem conhecer sua implementação interna.

---

## Estrutura do projeto

  sensor1d.h      <- interface (TAD)
  sensor1d.c      <- implementação
  main.c          <- programa de teste

---

## Instruções

- Crie três arquivos: sensor1d.h, sensor1d.c e main.c.
- Implemente a interface exatamente como descrita em sensor1d.h.
- Implemente as funções no sensor1d.c.
- Complete o arquivo main.c usando corretamente a TAD sensor1d.
- Teste o seu programa usando 10 leituras.

---

## Arquivo: sensor1d.h

```markdown
typedef struct {
    float dados[10];
    int qtd;
} Sensor1D;
void s_init(Sensor1D* s);
void s_add(Sensor1D* s, float valor);
float s_media(const Sensor1D* s);
float s_max(const Sensor1D* s);
void s_print(const Sensor1D* s);
```

---

## Arquivo: main.c - complete

```markdown
#include <stdio.h>
#include "sensor1d.h"

int main() {
    Sensor1D s;
    s_init(    ); // complete com o argumento correto
    float leitura;
    for (int i = 0; i < 10; i++) {
        printf("Digite a leitura %d: ", i);
        scanf("%f", &leitura);
        // adicione o valor lido no Sensor1D
    }
    printf("\nLeituras registradas:\n");
    // imprimir os valores armazenados no Sensor1D
    printf("\nMedia = %.2f\n",               ); // utilize a função correta do Sensor1D
    printf("Maximo = %.2f\n",                );// utilize a função correta do Sensor1D
    return 0;
}
```
