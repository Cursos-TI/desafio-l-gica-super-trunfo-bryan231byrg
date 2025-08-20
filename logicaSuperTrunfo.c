#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigoCarta[50];
    char nomeCidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadeDemografica;
    float pibPerCapita;
} Carta;

int main () {

    Carta carta1, carta2;

    printf ("Olá! Preencha os dados das cartas 1 e 2.\n\n");

    // ---------- Cadastro Carta 1 ----------
    printf("Carta 1\n");
    printf("Nome do estado: ");
    scanf(" %[^\n]", carta1.estado);

    printf("Código da carta: ");
    scanf(" %[^\n]", carta1.codigoCarta);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    do {
        printf("População (em milhões): ");
        scanf("%lu", &carta1.populacao);
        if (carta1.populacao <= 0) printf("⚠️ Erro: população não pode ser zero.\n");
    } while (carta1.populacao <= 0);

    do {
        printf("Área (km²): ");
        scanf("%f", &carta1.area);
        if (carta1.area <= 0) printf("⚠️ Erro: área não pode ser zero.\n");
    } while (carta1.area <= 0);

    do {
        printf("PIB (em bilhões): ");
        scanf("%f", &carta1.pib);
        if (carta1.pib <= 0) printf("⚠️ Erro: PIB não pode ser zero.\n");
    } while (carta1.pib <= 0);

    printf("Quantidade de pontos turísticos: ");
    scanf("%d", &carta1.numPontosTuristicos);

    // ---------- Cadastro Carta 2 ----------
    printf("\nCarta 2\n");
    printf("Nome do estado: ");
    scanf(" %[^\n]", carta2.estado);

    printf("Código da carta: ");
    scanf(" %[^\n]", carta2.codigoCarta);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    do {
        printf("População (em milhões): ");
        scanf("%lu", &carta2.populacao);
        if (carta2.populacao <= 0) printf("⚠️ Erro: população não pode ser zero.\n");
    } while (carta2.populacao <= 0);

    do {
        printf("Área (km²): ");
        scanf("%f", &carta2.area);
        if (carta2.area <= 0) printf("⚠️ Erro: área não pode ser zero.\n");
    } while (carta2.area <= 0);

    do {
        printf("PIB (em bilhões): ");
        scanf("%f", &carta2.pib);
        if (carta2.pib <= 0) printf("⚠️ Erro: PIB não pode ser zero.\n");
    } while (carta2.pib <= 0);

    printf("Quantidade de pontos turísticos: ");
    scanf("%d", &carta2.numPontosTuristicos);

    // ---------- Ajustes ----------
    carta1.populacao * 1000000;
    carta2.populacao * 1000000;

    carta1.pib * 1000000000;
    carta2.pib * 1000000000;

    carta1.pibPerCapita = carta1.pib / (float)carta1.populacao;
    carta2.pibPerCapita = carta2.pib / (float)carta2.populacao;

    carta1.densidadeDemografica = (float)carta1.populacao / carta1.area;
    carta2.densidadeDemografica = (float)carta2.populacao / carta2.area;

    // ---------- Escolha de dois atributos ----------
    int atributo1, atributo2;
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    scanf("%d", &atributo1);
    while (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida. Escolha novamente: ");
        scanf("%d", &atributo1);
    }

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch(i){
                case 1: printf("1. População\n"); break;
                case 2: printf("2. Área\n"); break;
                case 3: printf("3. PIB\n"); break;
                case 4: printf("4. Pontos Turísticos\n"); break;
                case 5: printf("5. Densidade Demográfica\n"); break;
            }
        }
    }
    scanf("%d", &atributo2);
    while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida. Escolha novamente: ");
        scanf("%d", &atributo2);
    }

    // ---------- Atribuir valores escolhidos ----------
    float valorCarta1A1, valorCarta2A1, valorCarta1A2, valorCarta2A2;

    switch(atributo1) {
        case 1: valorCarta1A1 = carta1.populacao; valorCarta2A1 = carta2.populacao; break;
        case 2: valorCarta1A1 = carta1.area; valorCarta2A1 = carta2.area; break;
        case 3: valorCarta1A1 = carta1.pib; valorCarta2A1 = carta2.pib; break;
        case 4: valorCarta1A1 = carta1.numPontosTuristicos; valorCarta2A1 = carta2.numPontosTuristicos; break;
        case 5: valorCarta1A1 = carta1.densidadeDemografica; valorCarta2A1 = carta2.densidadeDemografica; break;
    }

    switch(atributo2) {
        case 1: valorCarta1A2 = carta1.populacao; valorCarta2A2 = carta2.populacao; break;
        case 2: valorCarta1A2 = carta1.area; valorCarta2A2 = carta2.area; break;
        case 3: valorCarta1A2 = carta1.pib; valorCarta2A2 = carta2.pib; break;
        case 4: valorCarta1A2 = carta1.numPontosTuristicos; valorCarta2A2 = carta2.numPontosTuristicos; break;
        case 5: valorCarta1A2 = carta1.densidadeDemografica; valorCarta2A2 = carta2.densidadeDemografica; break;
    }

    // ---------- Comparação ----------
    int vencedorA1 = (atributo1 == 5) ? (valorCarta1A1 < valorCarta2A1 ? 1 : (valorCarta1A1 > valorCarta2A1 ? 2 : 0))
                                     : (valorCarta1A1 > valorCarta2A1 ? 1 : (valorCarta1A1 < valorCarta2A1 ? 2 : 0));

    int vencedorA2 = (atributo2 == 5) ? (valorCarta1A2 < valorCarta2A2 ? 1 : (valorCarta1A2 > valorCarta2A2 ? 2 : 0))
                                     : (valorCarta1A2 > valorCarta2A2 ? 1 : (valorCarta1A2 < valorCarta2A2 ? 2 : 0));

    float somaCarta1 = valorCarta1A1 + valorCarta1A2;
    float somaCarta2 = valorCarta2A1 + valorCarta2A2;

    // ---------- Resultados ----------
    printf("\n--- RESULTADOS ---\n");
    printf("%s: Atributo1=%.2f, Atributo2=%.2f, Soma=%.2f\n", carta1.nomeCidade, valorCarta1A1, valorCarta1A2, somaCarta1);
    printf("%s: Atributo1=%.2f, Atributo2=%.2f, Soma=%.2f\n", carta2.nomeCidade, valorCarta2A1, valorCarta2A2, somaCarta2);

    if (somaCarta1 > somaCarta2) {
        printf("A carta vencedora é %s!\n", carta1.nomeCidade);
    } else if (somaCarta2 > somaCarta1) {
        printf("A carta vencedora é %s!\n", carta2.nomeCidade);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
