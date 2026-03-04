#include <stdio.h>
#include "./sensor1d.h"

void s_init(Sensor1D *s) {
	for(int i = 0; i < 10; i++) {
		s->dados[i] = -1;
	}
}

void s_add(Sensor1D *s, float valor) {
	for(int i = 0; i < 10; i++) {
		if(s->dados[i] == -1) {
			s->dados[i] = valor;
			break;
		}
	}
}

float s_media(const Sensor1D *s){
    float soma = 0;
    int count = 0;

    for(int i = 0; i < 10; i++) {
        if(s->dados[i] != -1) {
            soma += s->dados[i];
            count++;
        }
    }
    return count > 0 ? soma / count : 0.0f;
}

float s_max(const Sensor1D *s) {
	float max = 0;

	for(int i = 0; i < 10; i++) {
		if(s->dados[i] > max) {
			max = s->dados[i];
		}
	}

	return max;
}

void s_print(const Sensor1D *s) {
	for(int i = 0; i < 10; i++ ) {
		if(s->dados[i] != -1) {
				printf("[%.2f]", s->dados[i]);
		}
	}
}

