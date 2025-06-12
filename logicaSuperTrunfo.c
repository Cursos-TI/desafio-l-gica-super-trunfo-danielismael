#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct CartaSuperTrunfo {
    char estado[2];   // Considerando estado como uma string para facilitar a comparação
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para calcular PIB per capita e densidade populacional
void calcularAtributos(struct CartaSuperTrunfo* carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
}

int main() {
    // Declaração de duas cartas (pré-cadastradas)
    struct CartaSuperTrunfo carta1 = {"SP", "A01", "São Paulo", 12000000, 1500, 500, 10, 0, 0};
    struct CartaSuperTrunfo carta2 = {"RJ", "B02", "Rio de Janeiro", 7000000, 1200, 300, 15, 0, 0};

    // Calcular atributos
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Variáveis para armazenar a escolha dos atributos
    int atributo1, atributo2;

    // Menu interativo para escolher os atributos
    printf("Escolha os atributos para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Populacional\n");
    printf("5. PIB per Capita\n");

    // Primeiro atributo
    do {
        printf("Escolha o primeiro atributo (1-5): ");
        scanf("%d", &atributo1);
    } while (atributo1 < 1 || atributo1 > 5);

    // Segundo atributo (não pode ser igual ao primeiro)
    do {
        printf("Escolha o segundo atributo (1-5), diferente do primeiro: ");
        scanf("%d", &atributo2);
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    // Exibição dos atributos escolhidos
    printf("\nVocê escolheu os atributos:\n");
    switch (atributo1) {
        case 1: printf("Atributo 1: População\n"); break;
        case 2: printf("Atributo 1: Área\n"); break;
        case 3: printf("Atributo 1: PIB\n"); break;
        case 4: printf("Atributo 1: Densidade Populacional\n"); break;
        case 5: printf("Atributo 1: PIB per Capita\n"); break;
    }
    switch (atributo2) {
        case 1: printf("Atributo 2: População\n"); break;
        case 2: printf("Atributo 2: Área\n"); break;
        case 3: printf("Atributo 2: PIB\n"); break;
        case 4: printf("Atributo 2: Densidade Populacional\n"); break;
        case 5: printf("Atributo 2: PIB per Capita\n"); break;
    }

    // Comparação e cálculo dos resultados para os atributos escolhidos
    float valor1_carta1, valor2_carta1, valor1_carta2, valor2_carta2;

    // Comparação para o primeiro atributo
    switch (atributo1) {
        case 1: valor1_carta1 = carta1.populacao; valor1_carta2 = carta2.populacao; break;
        case 2: valor1_carta1 = carta1.area; valor1_carta2 = carta2.area; break;
        case 3: valor1_carta1 = carta1.pib; valor1_carta2 = carta2.pib; break;
        case 4: valor1_carta1 = carta1.densidadePopulacional; valor1_carta2 = carta2.densidadePopulacional; break;
        case 5: valor1_carta1 = carta1.pibPerCapita; valor1_carta2 = carta2.pibPerCapita; break;
    }

    // Comparação para o segundo atributo
    switch (atributo2) {
        case 1: valor2_carta1 = carta1.populacao; valor2_carta2 = carta2.populacao; break;
        case 2: valor2_carta1 = carta1.area; valor2_carta2 = carta2.area; break;
        case 3: valor2_carta1 = carta1.pib; valor2_carta2 = carta2.pib; break;
        case 4: valor2_carta1 = carta1.densidadePopulacional; valor2_carta2 = carta2.densidadePopulacional; break;
        case 5: valor2_carta1 = carta1.pibPerCapita; valor2_carta2 = carta2.pibPerCapita; break;
    }

    // Exibição dos valores para os atributos escolhidos
    printf("\nValores das Cartas para os Atributos Escolhidos:\n");
    printf("Carta 1 (%s): %.2f e %.2f\n", carta1.nomeCidade, valor1_carta1, valor2_carta1);
    printf("Carta 2 (%s): %.2f e %.2f\n", carta2.nomeCidade, valor1_carta2, valor2_carta2);

    // Soma dos atributos para cada carta
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;

    // Determinar vencedor
    printf("\nSoma dos Atributos:\n");
    printf("Carta 1 (%s): %.2f\n", carta1.nomeCidade, soma_carta1);
    printf("Carta 2 (%s): %.2f\n", carta2.nomeCidade, soma_carta2);

    // Determinar o vencedor
    (soma_carta1 > soma_carta2) ? printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade) :
    (soma_carta2 > soma_carta1) ? printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade) :
    printf("Resultado: Empate!\n");

    return 0;
}
