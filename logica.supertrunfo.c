#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float populacao;
    float area;
    float pib;
    float idh;
} Carta;

void mostrarCarta(Carta c) {
    printf("\n--- %s ---\n", c.nome);
    printf("População: %.1f milhões\n", c.populacao);
    printf("Área: %.1f km²\n", c.area);
    printf("PIB: %.1f bilhões US$\n", c.pib);
    printf("IDH: %.3f\n", c.idh);
}

int compararAtributos(float valor1, float valor2) {
    if (valor1 > valor2) return 1;
    else if (valor1 < valor2) return -1;
    else return 0;
}

int compararPorAtributo(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1: return compararAtributos(c1.populacao, c2.populacao);
        case 2: return compararAtributos(c1.area, c2.area);
        case 3: return compararAtributos(c1.pib, c2.pib);
        case 4: return compararAtributos(c1.idh, c2.idh);
        default: return 0;
    }
}

int main() {
    Carta brasil = {"Brasil", 214.0, 8516.0, 2290.0, 0.765};
    Carta eua = {"Estados Unidos", 331.0, 9834.0, 25700.0, 0.921};
    Carta japao = {"Japão", 125.0, 377.0, 4960.0, 0.925};
    Carta franca = {"França", 67.0, 551.0, 3410.0, 0.903};

    int opcaoMenu, atributo1, atributo2;
    int resultado, pontos1, pontos2;
    int p1, p2;
    Carta carta1, carta2;
    Carta paises[4] = {brasil, eua, japao, franca};

    do {
        printf("\n===================================\n");
        printf("       SUPER TRUNFO: PAISES\n");
        printf("===================================\n");
        printf("1 - Ver cartas\n");
        printf("2 - Comparar um atributo\n");
        printf("3 - Comparar dois atributos\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoMenu);

        switch (opcaoMenu) {
            case 1:
                for (int i = 0; i < 4; i++) {
                    mostrarCarta(paises[i]);
                }
                break;

            case 2:
                printf("Escolha a primeira carta (1-Brasil, 2-EUA, 3-Japão, 4-França): ");
                scanf("%d", &p1);
                printf("Escolha a segunda carta (1-Brasil, 2-EUA, 3-Japão, 4-França): ");
                scanf("%d", &p2);

                if (p1 < 1 || p1 > 4 || p2 < 1 || p2 > 4) {
                    printf("Carta inválida. Tente novamente.\n");
                    continue;
                }

                carta1 = paises[p1 - 1];
                carta2 = paises[p2 - 1];

                printf("Escolha o atributo para comparar:\n");
                printf("1 - População\n2 - Área\n3 - PIB\n4 - IDH\n");
                scanf("%d", &atributo1);

                resultado = compararPorAtributo(carta1, carta2, atributo1);

                printf("\n---------------------------------\n");
                if (resultado == 1)
                    printf("%s vence!\n", carta1.nome);
                else if (resultado == -1)
                    printf("%s vence!\n", carta2.nome);
                else
                    printf("Empate!\n");
                break;

            case 3:
                printf("Escolha a primeira carta (1-Brasil, 2-EUA, 3-Japão, 4-França): ");
                scanf("%d", &p1);
                printf("Escolha a segunda carta (1-Brasil, 2-EUA, 3-Japão, 4-França): ");
                scanf("%d", &p2);

                if (p1 < 1 || p1 > 4 || p2 < 1 || p2 > 4) {
                    printf("Carta inválida. Tente novamente.\n");
                    continue;
                }

                carta1 = paises[p1 - 1];
                carta2 = paises[p2 - 1];

                printf("Escolha dois atributos para comparar (1-População, 2-Área, 3-PIB, 4-IDH): ");
                scanf("%d %d", &atributo1, &atributo2);

                pontos1 = pontos2 = 0;

                resultado = compararPorAtributo(carta1, carta2, atributo1);
                if (resultado == 1) pontos1++;
                else if (resultado == -1) pontos2++;

                resultado = compararPorAtributo(carta1, carta2, atributo2);
                if (resultado == 1) pontos1++;
                else if (resultado == -1) pontos2++;

                printf("\n---------------------------------\n");
                if (pontos1 > pontos2)
                    printf("%s vence!\n", carta1.nome);
                else if (pontos2 > pontos1)
                    printf("%s vence!\n", carta2.nome);
                else
                    printf("Empate!\n");
                break;

            case 4:
                printf("Saindo do jogo. Até logo!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcaoMenu != 4);

    return 0;
}