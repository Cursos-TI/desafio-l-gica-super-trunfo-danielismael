#include <stdio.h>

// Estrutura que representa uma carta do Super Trunfo
struct CartaSuperTrunfo {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    // Declaração de duas cartas
    struct CartaSuperTrunfo carta1;
    struct CartaSuperTrunfo carta2;

    // Entrada de dados para a carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (letra A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("População: ");
    scanf("%lu", &carta1.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontosTuristicos);

    // Calcula densidade e PIB per capita
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;

    // Entrada de dados para a carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (letra A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Código da carta (ex: B02): ");
    scanf("%s", carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("População: ");
    scanf("%lu", &carta2.populacao);

    printf("Área (em km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Calcula densidade e PIB per capita
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    // ==== Comparação por atributo: PIB per capita ====
    printf("\nComparação de Cartas (Atributo: PIB per Capita)\n");
    printf("Carta 1 - %s (%c): R$ %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%c): R$ %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);

    // Estrutura de decisão para determinar o vencedor
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
