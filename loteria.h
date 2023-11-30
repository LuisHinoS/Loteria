#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMEROS_ESCOLHA 5
#define NUMEROS_SORTEIO 50

int main() {
    int numerosEscolhidos[NUMEROS_ESCOLHA];
    int numerosSorteados[NUMEROS_SORTEIO];

    srand(time(NULL));

    printf("Digite seus cinco números (de 1 a 100): ");
    for (int i = 0; i < NUMEROS_ESCOLHA; i++) {
        scanf("%d", &numerosEscolhidos[i]);

        if (numerosEscolhidos[i] < 1 || numerosEscolhidos[i] > 100) {
            printf("Por favor, escolha números entre 1 e 100.\n");
            return 1;
        }

        for (int j = 0; j < i; j++) {
            if (numerosEscolhidos[i] == numerosEscolhidos[j]) {
                printf("Por favor, não repita números.\n");
                return 1;
            }
        }
    }

    for (int i = 0; i < NUMEROS_SORTEIO; i++) {
        numerosSorteados[i] = rand() % 100 + 1;
    }

    int acertos = 0;
    for (int i = 0; i < NUMEROS_ESCOLHA; i++) {
        for (int j = 0; j < NUMEROS_SORTEIO; j++) {
            if (numerosEscolhidos[i] == numerosSorteados[j]) {
                acertos++;
                break;
            }
        }
    }

    printf("Números sorteados: ");
    for (int i = 0; i < NUMEROS_SORTEIO; i++) {
        printf("%d ", numerosSorteados[i]);
    }
    printf("\n");

    if (acertos == NUMEROS_ESCOLHA) {
        printf("Parabéns! Você acertou todos os números e ganhou!\n");
    } else {
        printf("Você não acertou todos os números. Voce perdeu.\n");
    }

    return 0;
}
