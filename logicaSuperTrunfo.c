#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados das cartas
typedef struct {
    char pais[30];
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

// Função para exibir o menu e retornar a escolha do jogador
int exibirMenu(char *mensagem, int atributosDisponiveis[]) {
    int escolha;

    printf("%s\n", mensagem);
    if (atributosDisponiveis[0]) printf("1. Populacao\n");
    if (atributosDisponiveis[1]) printf("2. Area\n");
    if (atributosDisponiveis[2]) printf("3. PIB\n");
    if (atributosDisponiveis[3]) printf("4. Pontos Turisticos\n");

    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);

    if (escolha < 1 || escolha > 4 || !atributosDisponiveis[escolha - 1]) {
        printf("Opcao invalida! Tente novamente.\n\n");
        return exibirMenu(mensagem, atributosDisponiveis);
    }

    atributosDisponiveis[escolha - 1] = 0; // Desabilita o atributo escolhido
    return escolha;
}

// Função para realizar a comparação dos atributos
float obterValorPorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontosTuristicos;
        default: return 0;
    }
}

// Função principal
int main() {
    Carta carta1 = {"Brasil", 213000000, 8516000.0, 2.2, 15};
    Carta carta2 = {"Argentina", 45100000, 2780000.0, 0.5, 10};

    int atributosDisponiveis[4] = {1, 1, 1, 1};
    int atributo1, atributo2;

    printf("Comparacao entre as cartas:\n");
    printf("Carta 1: %s\n", carta1.pais);
    printf("Carta 2: %s\n\n", carta2.pais);

    // Escolha dos atributos para comparação
    atributo1 = exibirMenu("Escolha o primeiro atributo para comparacao:", atributosDisponiveis);
    atributo2 = exibirMenu("Escolha o segundo atributo para comparacao:", atributosDisponiveis);

    // Valores dos atributos
    float valor1A1 = obterValorPorAtributo(carta1, atributo1);
    float valor2A1 = obterValorPorAtributo(carta2, atributo1);
    float valor1A2 = obterValorPorAtributo(carta1, atributo2);
    float valor2A2 = obterValorPorAtributo(carta2, atributo2);

    // Comparação individual
    int vencedorA1 = (atributo1 == 2) ? (valor1A1 < valor2A1) : (valor1A1 > valor2A1);
    int vencedorA2 = (atributo2 == 2) ? (valor1A2 < valor2A2) : (valor1A2 > valor2A2);

    // Soma dos valores
    float soma1 = valor1A1 + valor1A2;
    float soma2 = valor2A1 + valor2A2;

    // Resultado final
    printf("\nResultados da comparacao:\n");
    printf("%s: Atributo %d = %.2f, Atributo %d = %.2f, Soma = %.2f\n", carta1.pais, atributo1, valor1A1, atributo2, valor1A2, soma1);
    printf("%s: Atributo %d = %.2f, Atributo %d = %.2f, Soma = %.2f\n", carta2.pais, atributo1, valor2A1, atributo2, valor2A2, soma2);

    if (soma1 > soma2) {
        printf("Vencedor: %s\n", carta1.pais);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s\n", carta2.pais);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
