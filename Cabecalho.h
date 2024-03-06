// Cabecalho.h

#ifndef CABECALHO_H
#define CABECALHO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dados dos produtos
extern char produtos[100][50];
extern int quantidades[100];
extern float precos[100];
extern float vendas_totais[100];

// Dados das vendas
extern int vendas_id_produto[100];
extern int vendas_quantidade[100];
extern float vendas_valor_individual[100];
extern int contador;
extern int contador_vendas;

// Protótipo das funções
void Cadastrar_Produto(char *nome, int quantidade, float preco);
void Registrar_Produto();
void Excluir_Produto(int index);
int Verificar_Existencia_Produto(char *nome);
void Listar_Produtos();
void Consultar_Item(int index);
void Matriz_Estoque();
void Vender_Produto(int id, int pecas);
void Calcular_Total_Vendas();
void Matriz_Vendas();
void Repor_Estoque(int index, int quantidade_adicionada);

#endif
