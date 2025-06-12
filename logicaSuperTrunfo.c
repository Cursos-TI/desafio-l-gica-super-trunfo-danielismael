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

void compararCartas(struct CartaSuperTrunfo carta1, struct CartaSuperTrunfo carta2, int atributo) {
    switch (atributo) {
        case 1: // Comparar nome das cidades (apenas exibição)
            printf("\nComparação de Cartas (Atributo: Nome da Cidade)\n");
            printf("Carta 1 - %s (%c)\n", carta1.nomeCidade, carta1.estado);
            printf("Carta 2 - %s (%c)\n", carta2.nomeCidade, carta2.estado);
            printf("Resultado: A comparação é apenas para exibição, não há vencedor.\n");
            break;

        case 2: // Comparar população
            printf("\nComparação de Cartas (Atributo: População)\n");
            printf("Carta 1 - %s (%c): %lu habitantes\n", carta1.nomeCidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%c): %lu habitantes\n", carta2.nomeCidade, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // Comparar área
            printf("\nComparação de Cartas (Atributo: Área)\n");
            printf("Carta 1 - %s (%c): %.2f km²\n", carta1.nomeCidade, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%c): %.2f km²\n", carta2.nomeCidade, carta2.estado, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Comparar PIB
            printf("\nComparação de Cartas (Atributo: PIB)\n");
            printf("Carta 1 - %s (%c): R$ %.2f bilhões\n", carta1.nomeCidade, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%c): R$ %.2f bilhões\n", carta2.nomeCidade, carta2.estado, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Comparar número de pontos turísticos
            printf("\nComparação de Cartas (Atributo: Pontos Turísticos)\n");
            printf("Carta 1 - %s (%c): %d pontos turísticos\n", carta1.nomeCidade, carta1.estado, carta1.pontosTuristicos);
            printf("Carta 2 - %s (%c): %d pontos turísticos\n", carta2.nomeCidade, carta2.estado, carta2.pontosTuristicos);
            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6: // Comparar densidade populacional (menor valor vence)
            printf("\nComparação de Cartas (Atributo: Densidade Populacional)\n");
            printf("Carta 1 - %s (%c): %.2f habitantes por km²\n", carta1.nomeCidade, carta1.estado, carta1.densidadePopulacional);
            printf("Carta 2 - %s (%c): %.2f habitantes por km²\n", carta2.nomeCidade, carta2.estado, carta2.densidadePopulacional);
            if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
            } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }
}

int main() {
    // Declaração das cartas (já cadastradas)
    struct CartaSuperTrunfo carta1 = {
        'A', "A01", "Cidade 1", 500000, 200.5, 100, 20, 2.49, 200000
    };
    struct CartaSuperTrunfo carta2 = {
        'B', "B01", "Cidade 2", 600000, 150.5, 120, 25, 3.98, 200000
    };

    int opcao;

    while (1) {
        // Menu interativo
        printf("\n=== Menu de Comparação de Cartas ===\n");
        printf("Escolha um atributo para comparação:\n");
        printf("1 - Nome da Cidade\n");
        printf("2 - População\n");
        printf("3 - Área\n");
        printf("4 - PIB\n");
        printf("5 - Pontos Turísticos\n");
        printf("6 - Densidade Populacional\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Saindo do programa...\n");
            break;
        }

        // Chama a função para comparar as cartas com o atributo escolhido
        compararCartas(carta1, carta2, opcao);
    }

    return 0;
}
