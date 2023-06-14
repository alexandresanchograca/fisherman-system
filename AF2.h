#include <stdio.h>
#include "CSVOperations.h"
#include "LinkedList.h"
#include "Crud.h"



//Enunciado A
// 
//Desenvolva um programa em linguagem C para gerir as vendas de uma loja.
//O programa deve ler um ficheiro CSV contendo os dados dos produtos(código, designação, preço) e armazená - los em memória.
//O programa deve permitir que o utilizador adicione, remova ou edite produtos, bem como pesquisar produtos por código ou nome.
//O programa também deve ler outro ficheiro CSV contendo as vendas realizadas pela loja(código do produto, quantidade vendida, data da venda), e atualizar os dados dos produtos em memória de acordo com as vendas realizadas.
//O programa deve ser capaz de gerar um relatório de vendas, exibindo o total vendido por produto, bem como o total de vendas e o total arrecadado pela loja.
//O programa deve ser modular, com cada funcionalidade implementada num módulo separado, como leitura de dados, escrita de dados, pesquisa, atualização de vendas e geração de relatório.
//O programa deve ter um menu de opções para que o utilizador possa escolher que funcionalidade utilizar.O código deve ser bem organizado e documentado, seguindo as melhores práticas de programação em C.

//guardar o ficheiro