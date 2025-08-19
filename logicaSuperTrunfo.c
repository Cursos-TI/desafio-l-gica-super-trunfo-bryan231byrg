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

    //Variaveis das Cartas
    Carta carta1, carta2;
   
//Entrada de Dados Carta 1
    printf ("Olá, por favor preencha abaixo os dados da carta 1 e 2!\n\n");

    printf ("Insira o Nome do seu estado: ");
    scanf (" %[^\n]", carta1.estado);

    printf ("Insira o Código da carta: ");
    scanf (" %[^\n]", carta1.codigoCarta);

    printf ("Insira o Nome da sua Cidade: ");
    scanf (" %[^\n]", carta1.nomeCidade);

    do {
        printf ("Insira a população: ");
        scanf ("%lu", &carta1.populacao);
        if (carta1.populacao <= 0) {
            printf("⚠️ Erro: população não pode ser zero. Digite novamente.\n");
        }
    } while (carta1.populacao <= 0);

    do {
    printf("Insira a área: ");
    scanf("%f", &carta1.area);
    if (carta1.area <= 0) {
        printf("⚠️ Erro: área não pode ser zero. Digite novamente.\n");
    }
    } while (carta1.area <= 0);

     do {
    printf ("Insira o PIB: ");
    scanf ("%f", &carta1.pib);
    if (carta1.pib <= 0) {
        printf("⚠️ Erro: PIB não pode ser negativo. Digite novamente.\n");
        scanf ("%f", &carta1.pib);
     }
    } while (carta1.pib <= 0);

    printf ("Insira a quantidade de pontos turisticos: ");
    scanf ("%d", &carta1.numPontosTuristicos);

    //Entrada de Dados Carta 2
    printf ("Agradeçemos o cadastro da Carta 1!\n Agora por favor faça o mesmo para a carta 2!\n\n");

    printf ("Insira o Nome do seu estado: ");
    scanf (" %[^\n]", carta2.estado);

    printf ("Insira o Código da carta: ");
    scanf (" %[^\n]", carta2.codigoCarta);

    printf ("Insira o Nome da sua Cidade: ");
    scanf (" %[^\n]", carta2.nomeCidade);

    do {
    printf ("Insira a população: ");
    scanf ("%lu", &carta2.populacao);
    if (carta2.populacao <= 0) {
        printf("⚠️ Erro: população não pode ser zero. Digite novamente.\n");
    }
} while (carta2.populacao <= 0);

    do {
    printf("Insira a área: ");
    scanf("%f", &carta2.area);
    if (carta2.area <= 0) {
        printf("⚠️ Erro: área não pode ser zero. Digite novamente.\n");
    }
} while (carta2.area <= 0);

    do {
    printf ("Insira o PIB: ");
    scanf ("%f", &carta2.pib);
    if (carta2.pib <= 0) {
        printf("⚠️ Erro: PIB não pode ser negativo. Digite novamente.\n");
        scanf ("%f", &carta2.pib);
     }
    } while (carta2.pib <= 0);
    

    printf ("Insira a quantidade de pontos turisticos: ");
    scanf ("%d", &carta2.numPontosTuristicos);

    // Ajuste da população (entrada em milhões)
    carta1.populacao *= 1000000;
    carta2.populacao *= 1000000;

      // Ajuste da população (entrada em Bilhões)
    carta1.pib *= 1000000000;
    carta2.pib *= 1000000000;

    // Calculo do PIB per capita (entrada do PIB em bilhões → multiplicado por 1 bi)
    carta1.pibPerCapita = (carta1.pib * 1000000000) / (float)carta1.populacao;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / (float)carta2.populacao;

    // Calculo da Densidade Demográfica
    carta1.densidadeDemografica = (float)carta1.populacao / carta1.area;
    carta2.densidadeDemografica = (float)carta2.populacao / carta2.area;

    //Saida de Dados da Carta 1
    printf ("Carta 1\n");
    printf ("Estado: %s\n", carta1.estado);
    printf ("Código da Carta: %s\n", carta1.codigoCarta);
    printf ("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf ("População: %lu\n", carta1.populacao);
    printf ("Área: %.2f km²\n", carta1.area);
    printf ("PIB: %.2f\n", carta1.pib);
    printf ("Números de Pontos Turisticos: %d\n", carta1.numPontosTuristicos);
    printf ("Densidade Demografica: %.2f hab/km²\n", carta1.densidadeDemografica);
    printf ("PIB per capita: %.2f\n\n", carta1.pibPerCapita);

    //Saida de Dados da Carta 2
    printf ("Carta 2\n");
    printf ("Estado: %s\n", carta2.estado);
    printf ("Código da Carta: %s\n", carta2.codigoCarta);
    printf ("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf ("População: %lu\n", carta2.populacao);
    printf ("Área: %.2f km²\n", carta2.area);
    printf ("PIB: %.2f\n", carta2.pib);
    printf ("Números de Pontos Turisticos: %d\n", carta2.numPontosTuristicos);
    printf ("Densidade Demografica: %.2f hab/km²\n", carta2.densidadeDemografica);
    printf ("PIB per capita: %.2f\n\n", carta2.pibPerCapita);

    //Variavel para o menu interativo
    int opcao;

    //Mensagem de transição
    printf ("Agora, selecione abaixo os atributos que deseja compararar entre as duas cartas!\n\n");

    //Menu Interativo
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Quantidade de Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("A população da Cidade %s é %lu\n", carta1.nomeCidade, carta1.populacao);
        printf("A população da Cidade %s é %lu\n", carta2.nomeCidade, carta2.populacao);
        if (carta1.populacao > carta2.populacao)
        {
            printf ("A Cidade Vencedora é %s\n", carta1.nomeCidade);
        } else if (carta1.populacao < carta2.populacao)
        {
            printf ("A cidade Vencedora é %s\n", carta2.nomeCidade);
        } else {
            printf("As cidades têm a mesma população.\n");
                } 
        break;
        

    case 2:
        printf("A Área da Cidade %s é %.2f km²\n", carta1.nomeCidade, carta1.area);
        printf("A Área da Cidade %s é %.2f km²\n", carta2.nomeCidade, carta2.area);
        if (carta1.area > carta2.area)
        {
            printf ("A Cidade Vencedora é %s\n", carta1.nomeCidade);
        } else if (carta1.area < carta2.area)
        {
            printf ("A cidade Vencedora é %s\n", carta2.nomeCidade);
        } else {
            printf("As cidades têm a mesma área.\n");
        }
        break;

    case 3:
        printf("O PIB da Cidade %s é %.2f\n", carta1.nomeCidade, carta1.pib);
        printf("O PIB da Cidade %s é %.2f\n", carta2.nomeCidade, carta2.pib);
        if (carta1.pib > carta2.pib)
        {
            printf ("A Cidade Vencedora é %s\n", carta1.nomeCidade);
        } else if (carta1.pib < carta2.pib)
        {
            printf ("A cidade Vencedora é %s\n", carta2.nomeCidade);
        } else {
            printf("As cidades têm o mesmo PIB.\n");
            }
        break;
        

    case 4:
        printf("A quantidade de Pontos Turisticos da Cidade %s é %d\n", carta1.nomeCidade, carta1.numPontosTuristicos);
        printf("A quantidade de Pontos Turisticos da Cidade %s é %d\n", carta2.nomeCidade, carta2.numPontosTuristicos);
        if (carta1.numPontosTuristicos > carta2.numPontosTuristicos)
        {
            printf ("A Cidade Vencedora é %s\n", carta1.nomeCidade);
        } else if (carta1.numPontosTuristicos < carta2.numPontosTuristicos)
        {
            printf ("A cidade Vencedora é %s\n", carta2.nomeCidade);
        } else {
            printf("As cidades têm a mesma quantidade de pontos turísticos.\n");
        }
        break;

    case 5:
        printf("A densidade Demografica da Cidade %s é %.2f hab/km²\n", carta1.nomeCidade, carta1.densidadeDemografica);
        printf("A densidade Demografica da Cidade %s é %.2f hab/km²\n", carta2.nomeCidade, carta2.densidadeDemografica);
        if (carta1.densidadeDemografica < carta2.densidadeDemografica)
        {
            printf ("A Cidade Vencedora é %s\n", carta1.nomeCidade);
        } else if (carta1.densidadeDemografica > carta2.densidadeDemografica)
        {
            printf ("A cidade Vencedora é %s\n", carta2.nomeCidade);
        } else {
            printf("As cidades têm a mesma densidade populacional.\n");
            }
        break;

    default:
        do {
        printf("Opção inválida. Por favor, escolha uma opção válida (1-5): ");
        scanf("%d", &opcao);
        } while (opcao < 1 || opcao > 5);
        break;
    

    return 0;
}

    }
