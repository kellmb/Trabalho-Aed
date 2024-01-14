#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dados dos produtos
char produtos[100][50];
int quantidades[100];
float precos[100];
float vendas_totais[100];

// Dados das vendas
int vendas_id_produto[100];
int vendas_quantidade[100];
float vendas_valor_individual[100]; 
int contador = 0;
int contador_vendas = 0;

void cadastrar_produto(char *nome, int quantidade, float preco);

void adicionar_produto();

void listar_produtos();

void consultar_estoque();

void ver_Matriz();

void vender_produto(int id, int pecas);

void calcular_total_vendas();

void ver_Matriz_Vendas();

int main(void) {
    // Exemplo de produtos
    cadastrar_produto("Camisa", 10, 35.0);
    cadastrar_produto("Calca", 5, 20.0);

    // Menu
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Listar produtos\n");
        printf("2 - Vender produto\n");
        printf("3 - Adicionar produto\n");
        printf("4 - Consultar estoque\n");
        printf("5 - Calcular total de vendas\n");
        printf("0 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listar_produtos();
                break;
            case 2:
                printf("\nDigite o ID do produto a ser vendido: ");
                int index;
                scanf("%d", &index);
                printf("\nDigite a quantidade de produtos a ser vendido: ");
                int quantidade;
                scanf("%d", &quantidade);
                vender_produto(index, quantidade);
                break;
            case 3:
                adicionar_produto();
                break;
            case 4:
                ver_Matriz();
                break;
            case 5:
                calcular_total_vendas();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}


void cadastrar_produto(char *nome, int quantidade, float preco) {
    strcpy(produtos[contador], nome);
    quantidades[contador] = quantidade;
    precos[contador] = preco;
    vendas_totais[contador] = 0;
    contador++;
}

void adicionar_produto() {
    int quantidade;
    float preco;
    char nome[50];
    printf("Digite o Nome do produto: ");
    scanf("%s", nome);
    printf("Digite a Quantidade de produtos: ");
    scanf("%d", &quantidade);
    printf("Digite o Preço do produto: ");
    scanf("%f", &preco);

    cadastrar_produto(nome, quantidade, preco);
}

void listar_produtos() {
    int i;
    for (i = 0; i < contador; i++) {
        printf("%d - %s\n", i, produtos[i]);
    }
}

void consultar_estoque() {
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    if (id >= 0 && id < contador) {
        printf("Nome: %s\n", produtos[id]);
        printf("Quantidade: %d\n", quantidades[id]);
        printf("Preço: %.2f\n", precos[id]);
        printf("Vendas totais: %.2f\n", vendas_totais[id]);
    } else {
        printf("Produto não encontrado.\n");
    }
}

void ver_Matriz() {
    int i;

    printf("ID\tQuantidade\tPreço\n");

    for (i = 0; i < contador; i++) {
        printf("%d\t%d\t\t%.2f\n", i, quantidades[i], precos[i]);
    }
}

void vender_produto(int id, int pecas) {
    if (quantidades[id] >= pecas) {
        quantidades[id] -= pecas;
        float valor_venda = precos[id] * pecas;

        vendas_totais[id] += valor_venda;
        vendas_id_produto[contador_vendas] = id;
        vendas_quantidade[contador_vendas] = pecas;
        vendas_valor_individual[contador_vendas] = valor_venda;

        contador_vendas++;
    } else {
        printf("Estoque insuficiente.\n");
    }
}

void calcular_total_vendas() {
    float total = 0;
    int i;
    for (i = 0; i < contador; i++) {
        total += vendas_totais[i];
    }
    printf("Total de vendas: R$ %.2f\n", total);

    printf("\nMatriz de Vendas:\n");
    ver_Matriz_Vendas();
}

void ver_Matriz_Vendas() {
    printf("ID\tQuantidade Vendida\tValor da Venda\n");

    for (int i = 0; i < contador_vendas; i++) {
        printf("%d\t%d\t\t\t%.2f\n", vendas_id_produto[i], vendas_quantidade[i], vendas_valor_individual[i]);
    }
}
