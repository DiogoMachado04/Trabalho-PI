/**
	@file      IO.h
	@brief     Cabecalho das funcoes relativas as necessidades de IO da main
	@author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
	@date      30.12.2023
**/
#pragma once
#include "Pacientes.h"

#if defined(__APPLE__) || defined(__linux__)
#define SISTEMA_UNIX
#elif defined(_WIN32)
#define SISTEMA_WINDOWS
#endif
/*
* @brief Funcao que limpa o ecra em fun��o do Sistema Operativo ativo.
* @note Esta funcao usa diretivas de pre-processamento e a funcao system para determinar o comando de consola/terminal apropriado.
*/
void LimpaEcra();
/*
* @brief Funcao que apresenta informacao relativa ao projeto.
* @note Esta fun��o � invocada via terminal, atraves do uso da opcao '-info'.
*/
void MostraInfo();
/*
* @brief Funcao que apresenta o Menu principal.
* @note Esta funcao � invocada via main.c e disponibiliza informacao de navegacao na aplicacao.
*/
void MostraMenu();
/*
* @brief Fun��o que espera um prompt do utilizador.
* @note Esta fun��o � usada em conjunto com a fun��o @ref LimpaEcra() de forma a permitir ao utilizador o tempo necess�rio para ler a informa��o apresentada.
* @see LimpaEcra()
*/
int Continuar();
/**
 * @brief Fun��o que exibe informa��es de ajuda.
 * @note Esta fun��o, mediante o uso da flag -ajuda no terminal, informa acerca da sintaxe apropriada para o uso da aplica��o.
 */
void MostraAjuda();
/*
* @brief Funcao responsavel pelas leituras das datas iniciais.
* @param char* data - Apontador para o inic�o da string que armazena a informacao da data.
*/
int LerDataInicial(char* data);
/*
* @brief Funcao responsavel pelas leituras das datas finais.
* @param char* data - Apontador para o inicio da string que armazena a informacao da data.
*/
int LerDataFinal(char* data);
/*
*@brief Funcao responsavel pela leitura do ID do paciente.
*@return id - id representativo de um determinado paciente.
*/
int LerID();
/*
*@brief Funcao que le uma determinada refeicao.
*@note Esta funcao faz uso de um ciclo para obter uma identificacao de uma refeicao nos termos corretos.
*@return SUCESSO - Valor devolvido em caso de sucesso, permitindo voltar a funcao invocadora com a confirmacao da correta introducao da refeicao.
*/
int LerRefeicao(char refeicaoTemp[]);
/*
*@brief Funcao que le a quantidade de calorias.
*@return calorias - Quantidade de calorias a ser usadas como input no menu.
*/
int LerCalorias();

