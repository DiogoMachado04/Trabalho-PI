/**
	@file      IO.c
	@brief     Funcoes relativas as necessidades de IO da main
	@author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
	@date      30.12.2023
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"
#include "Constantes.h"
#include "Pacientes.h"
#include "GereFicheirosBIN.h"
#include "GestaoFicheirosCSV.h"
#pragma warning (disable:4996)

/*
* @brief Funcao que apresenta informacao relativa ao projeto.
* @note Esta função é invocada via terminal, atraves do uso da opcao '-info'.
*/
void MostraInfo() {
	printf("********************************************************************************\n");
	printf("*                   Programacao Imperativa                                     *\n");
	printf("********************************************************************************\n");
	printf("*        PROJETO:                                                              *\n");
	printf("*                   Gestao de Pacientes / Plano Nutricional                    *\n");
	printf("*                                                                              *\n");
	printf("*        DEVELOPERS:                                                           *\n");
	printf("*                   Diogo Machado - a26042                                     *\n");
	printf("*                   Jose Alves - a27967                                        *\n");
	printf("*                   Paulo Melo - a29575                                        *\n");
	printf("*                                                                              *\n");
	printf("*                                                                              *\n");
	printf("*        PROFESSOR:                                                            *\n");
	printf("*                   Professor Luis Ferreira                                    *\n");
	printf("*                                                                              *\n");
	printf("********************************************************************************\n");
}

/*
* @brief Funcao que apresenta o Menu principal.
* @note Esta funcao é invocada via main.c e disponibiliza informacao de navegacao na aplicacao.
*/
void MostraMenu() {
	printf("****************************************************************************************************************\n");
	printf("*                                               --MENU--                                                       *\n");
	printf("* 1 - Numero de pacientes em excesso calorico, por periodo de tempo.                                           *\n");
	printf("* 2 - Lista de pacientes com ingestao calorica fora do plano, por periodo de tempo.                            *\n");
	printf("* 3 - Plano nutricional de um determinado cliente, num determinado periodo de tempo.                           *\n");
	printf("* 4 - Media das calorias consumidas por cliente, por periodo de tempo.                                         *\n");
	printf("* 5 - Tabela de informacao consolidada.                                                                        *\n");
	printf("* 6 - Mostra Ajuda.                                                                                            *\n");
	printf("* 7 - Mostra Info.                                                                                             *\n");
	printf("* 10 - Sair                                                                                                    *\n");
	printf("****************************************************************************************************************\n");
}

/*
* @brief Funcao que limpa o ecra em função do Sistema Operativo ativo.
* @note Esta funcao usa diretivas de pre-processamento e a funcao system para determinar o comando de consola/terminal apropriado.
*/
void LimpaEcra() {
	#ifdef SISTEMA_UNIX
		system("clear");
#elif defined(SISTEMA_WINDOWS)
system("cls");
#endif
}

/*
* @brief Função que espera um prompt do utilizador.
* @note Esta função é usada em conjunto com a função @ref LimpaEcra() de forma a permitir ao utilizador o tempo necessário para ler a informação apresentada.
* @see LimpaEcra()
*/
int Continuar() {
	printf("Prima qualquer tecla para continuar:");
	return _getch();
}

/**
 * @brief Função que exibe informações de ajuda.
 * @note Esta função, mediante o uso da flag -ajuda no terminal, informa acerca da sintaxe apropriada para o uso da aplicação.
 */
void MostraAjuda() {
	printf("Sintaxe:\n");
	printf("\t<nome_executavel> <opcao_tipo_ficheiro> <ficheiro_pacientes> <ficheiro_dietas> <ficheiro_planos>\n");
	printf("Ajuda:\n");
	printf("\t<nome_executavel> -info\n");
}


/*
* @brief Funcao responsavel pelas leituras das datas iniciais.
* @param char* data - Apontador para o inicío da string que armazena a informacao da data.
*/
int LerDataInicial(char* data) {
	int dia, mes, ano;
	int controloCiclo = 1;
	printf("Digite a data inicial (dd-mm-aaaa): ");
	scanf("%s", data);

	while (controloCiclo) {
		if (sscanf(data, "%d-%d-%d", &dia, &mes, &ano) == 3){
			LimpaEcra();
			return SUCESSO;
		}
		LimpaEcra();
		printf("Data invalida, insira novamente (dd-mm-aaaa): ");
		scanf("%s", &data);
	}
	
}

/*
* @brief Funcao responsavel pelas leituras das datas finais.
* @param char* data - Apontador para o inicio da string que armazena a informacao da data.
*/
int LerDataFinal(char* data) {
	int dia, mes, ano;
	int controloCiclo = 1;
	printf("Digite a data final (dd-mm-aaaa): ");
	scanf("%s", data);

	while (controloCiclo) {
		if (sscanf(data, "%d-%d-%d", &dia, &mes, &ano) == 3){
			LimpaEcra();
			return SUCESSO;
		}
		LimpaEcra();
		printf("Data invalida, insira novamente (dd-mm-aaaa): ");
		scanf("%s", &data);
	}
}

/*
*@brief Funcao responsavel pela leitura do ID do paciente.
*@return id - id representativo de um determinado paciente.
*/
int LerID() {
	int id;
	printf("Insira um ID:\n");
	scanf("%d", &id);

	return id;
}

/*
*@brief Funcao que le uma determinada refeicao.
*@note Esta funcao faz uso de um ciclo para obter uma identificacao de uma refeicao nos termos corretos.
*@return SUCESSO - Valor devolvido em caso de sucesso, permitindo voltar a funcao invocadora com a confirmacao da correta introducao da refeicao.
*/
int LerRefeicao(char refeicaoTemp[]) {
	int controloCiclo = 1;
	printf("Insira a refeicao: ");
	scanf("%s", refeicaoTemp);
	while (controloCiclo) {
		if (strcmp(refeicaoTemp, "pequeno almoco") == 0 || strcmp(refeicaoTemp, "almoco") == 0 || strcmp(refeicaoTemp, "jantar") == 0 ||
			strcmp(refeicaoTemp, "Pequeno Almoco") == 0 || strcmp(refeicaoTemp, "Almoco") == 0 || strcmp(refeicaoTemp, "Jantar") == 0) {
			LimpaEcra();
			return SUCESSO;
		}
			LimpaEcra();
			printf("Refeicao invalida, insira novamente:");
			scanf("%s", refeicaoTemp);
	}
}

/*
*@brief Funcao que le a quantidade de calorias.
*@return calorias - Quantidade de calorias a ser usadas como input no menu.
*/
int LerCalorias() {
	int calorias;
	printf("Introduza o numero de calorias: ");
	scanf("%d", &calorias);
	return calorias;
}
