// Funcoes.c
#include "Cabecalho.h"

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

// Implementação das funções

void Cadastrar_Produto(char *nome, int quantidade, float preco) {
    // Implementação
    strcpy(produtos[contador], nome);
    quantidades[contador] = quantidade;
    precos[contador] = preco;
    vendas_totais[contador] = 0;
    contador++;
}

int Verificar_Existencia_Produto(char *nome) {
    // Implementação
    int i;
    for (i = 0; i < contador; i++) {
        if (strcasecmp(produtos[i], nome) == 0) {
            return i; // produto encontrado
        }
    }
    return -1; // produto não encontrado
}

void Registrar_Produto() {
    // Implementação
    int quantidade;
    float preco;
    char nome[50];
    printf("Digite o Nome do produto: ");
    scanf("%s", nome);

    // faz a verificacao
    int index = Verificar_Existencia_Produto(nome);

    if (index == -1) {
        // produto não existe, cadastra um novo
        printf("Digite a Quantidade de produtos: ");
        scanf("%d", &quantidade);
        printf("Digite o Preco do produto: ");
        scanf("%f", &preco);
        Cadastrar_Produto(nome, quantidade, preco);
    } else {
        // caso o produto já existe
        printf("Produto '%s' já existe. Não é possível adicionar novamente.\n", nome);
    }
}

void Listar_Produtos() {
    // Implementação
    int i;
    for (i = 0; i < contador; i++) {
        printf("%d - %s\n", i, produtos[i]);
    }
}

void Consultar_Item(int index) {
    // Implementação
    if (index >= 0 && index < contador) {
        printf("Nome: %s\n", produtos[index]);
        printf("Quantidade: %d\n", quantidades[index]);
        printf("Preço: %.2f\n", precos[index]);
    } else {
        printf("Produto não encontrado.\n");
    }
}

void Matriz_Estoque() {
    // Implementação
    int i;
    printf("ID\tQuantidade\tPreço\n");

    for (i = 0; i < contador; i++) {
        printf("%d\t%d\t\t%.2f\n", i, quantidades[i], precos[i]);
    }
}

void Vender_Produto(int id, int pecas) {
    // Implementação
    if (quantidades[id] >= pecas) {
        quantidades[id] -= pecas;
        float valor_venda = precos[id] * pecas;

        vendas_totais[id] += valor_venda;
        vendas_id_produto[contador_vendas] = id;
        vendas_quantidade[contador_vendas] = pecas;
        vendas_valor_individual[contador_vendas] = valor_venda;

        contador_vendas++;
        
        //confirmação de venda
        printf("\n");
        printf("Produto vendido com sucesso!\n");
        printf("\n");
        
    } else {
        printf("Estoque insuficiente.\n");
    }
}

void Matriz_Vendas() {
    // Implementação
    printf("ID\tQuantidade Vendida\tValor da Venda\n");
    int i;
    for (i = 0; i < contador_vendas; i++) {
        printf("%d\t%d\t\t\t%.2f\n", vendas_id_produto[i], vendas_quantidade[i], vendas_valor_individual[i]);
    }
}

void Calcular_Total_Vendas() {
    // Implementação
    float total = 0;
    int i;
    for (i = 0; i < contador; i++) {
        total += vendas_totais[i];
    }
    printf("Total de vendas: R$ %.2f\n", total);
}

void Repor_Estoque(int index, int quantidade_adicionada) {
    // Implementação
    if (index >= 0 && index < contador) {
        quantidades[index] += quantidade_adicionada;
        printf("Estoque do produto '%s' reposto com sucesso!\n", produtos[index]);
        printf("Nova quantidade: %d\n", quantidades[index]);
    } else {
        printf("Produto não encontrado.\n");
    }
}

void Excluir_Produto(int index) {
    // Implementação
    if (index >= 0 && index < contador) {
        for (int i = index; i < contador - 1; i++) {
            strcpy(produtos[i], produtos[i + 1]);
            quantidades[i] = quantidades[i + 1];
            precos[i] = precos[i + 1];
            vendas_totais[i] = vendas_totais[i + 1];
        }
        contador--;
        printf("Produto excluído com sucesso!\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}
