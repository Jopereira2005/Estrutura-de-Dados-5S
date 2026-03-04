#include <stdio.h>
#include "./sensor1d.h"

int main() {
	Sensor1D s;

	s_init(&s); // complete com o argumento correto
	float leitura;
	for (int i = 0; i < 10; i++) {
		printf("Digite a leitura %d: ", i+1);
		scanf("%f", &leitura);
		// adicione o valor lido no Sensor1D
		s_add(&s, leitura);
	}
	printf("\nLeituras registradas:\n");
	// imprimir os valores armazenados no Sensor1D
	s_print(&s);
	
	printf("\nMedia = %.2f\n", s_media(&s)); // utilize a função correta do Sensor1D
	printf("Maximo = %.2f\n", s_max(&s));   // utilize a função correta do Sensor1D
	return 0;
}