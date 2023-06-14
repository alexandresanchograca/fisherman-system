#include <stdio.h>
#include "CSVOperations.h"
#include "LinkedList.h"
#include "Crud.h"



//Enunciado A
// 
//Desenvolva um programa em linguagem C para gerir as vendas de uma loja.
//O programa deve ler um ficheiro CSV contendo os dados dos produtos(c�digo, designa��o, pre�o) e armazen� - los em mem�ria.
//O programa deve permitir que o utilizador adicione, remova ou edite produtos, bem como pesquisar produtos por c�digo ou nome.
//O programa tamb�m deve ler outro ficheiro CSV contendo as vendas realizadas pela loja(c�digo do produto, quantidade vendida, data da venda), e atualizar os dados dos produtos em mem�ria de acordo com as vendas realizadas.
//O programa deve ser capaz de gerar um relat�rio de vendas, exibindo o total vendido por produto, bem como o total de vendas e o total arrecadado pela loja.
//O programa deve ser modular, com cada funcionalidade implementada num m�dulo separado, como leitura de dados, escrita de dados, pesquisa, atualiza��o de vendas e gera��o de relat�rio.
//O programa deve ter um menu de op��es para que o utilizador possa escolher que funcionalidade utilizar.O c�digo deve ser bem organizado e documentado, seguindo as melhores pr�ticas de programa��o em C.

//guardar o ficheiro