// Main.c
#include "Cabecalho.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    // Exemplo de produtos
    Cadastrar_Produto("Camisa", 10, 35.0);
    Cadastrar_Produto("Calca", 5, 20.0);

    // Menu
    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1 - Listar produtos\n");
        printf("2 - Vender produto\n");
        printf("3 - Adicionar produto\n");
        printf("4 - Consultar estoque\n");
        printf("5 - Consultar item\n");
        printf("6 - Calcular total de vendas\n");
        printf("7 - Repor o estoque\n");
        printf("8 - Excluir produto\n");
        printf("0 - Sair\n");
        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                Listar_Produtos();
                break;
            case 2:
                printf("\nDigite o ID do produto a ser vendido: ");
                int index;
                scanf("%d", &index);
                printf("\nDigite a quantidade de produtos a ser vendido: ");
                int quantidade;
                scanf("%d", &quantidade);
                Vender_Produto(index, quantidade);
                break;
            case 3:
                Registrar_Produto();
                break;
            case 4:
                Matriz_Estoque();
                break;
            case 5:
                printf("Digite o ID do produto: \n");
                int id;
                scanf("%d", &id);
                Consultar_Item(id);
                break;
            case 6:
                Matriz_Vendas();
                printf("\n");
                Calcular_Total_Vendas();
                break;
            case 7:
                printf("\n");
                printf("Digite o ID do produto a ter o estoque reposto: ");
                int id_repor;
                scanf("%d", &id_repor);
                printf("Digite a quantidade a ser adicionada ao estoque: ");
                int quantidade_adicionada;
                scanf("%d", &quantidade_adicionada);
                Repor_Estoque(id_repor, quantidade_adicionada);
                break;
            case 8:
                printf("Digite o ID do produto a ser excluído: ");
                int id_excluir;
                scanf("%d", &id_excluir);
                Excluir_Produto(id_excluir);
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
