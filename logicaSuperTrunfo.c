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

// Função para calcular a densidade populacional e o PIB per capita
void calcularAtributos(struct CartaSuperTrunfo *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
}

// Função para comparar o atributo escolhido
void compararCartas(struct CartaSuperTrunfo carta1, struct CartaSuperTrunfo carta2) {
    // Escolha do atributo para comparação - aqui escolhemos "PIB per Capita"
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
}

int main() {
    // Declaração de duas cartas
    struct CartaSuperTrunfo carta1 = {
        'A', "A01", "São Paulo", 12000000, 1500.0, 2100.0, 500, 0, 0
    };
    struct CartaSuperTrunfo carta2 = {
        'B', "B02", "Rio de Janeiro", 6800000, 1200.0, 800.0, 300, 0, 0
    };

    // Cálculo de densidade e PIB per capita para cada carta
    calcularAtributos(&carta1);
    calcularAtributos(&carta2);

    // Comparação entre as cartas pelo PIB per capita
    compararCartas(carta1, carta2);

    return 0;
}
