/**
    @file      main.c
    @brief     Funcao principal
    @author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
    @date      30.12.2023
**/
#include <stdio.h>
#include "Constantes.h"
#include "GereFicheirosBIN.h"
#include "GestaoFicheirosCSV.h"
#include "Pacientes.h"
#include "Utilidades.h"
#include "IO.h"
#include <string.h>
#include "Funcoes.h"
#pragma comment (lib, "LibMedia.lib")
#pragma warning (disable:4996)
/**
 * @brief Fun��o principal do programa.
 *
 * @note Esta fun��o serve como ponto de entrada do programa.
 * Inicializa o ambiente, verifica a abertura de ficheiros,
 * exibe informa��es ou apresenta um menu interativo,
 * dependendo dos argumentos fornecidos.
 *
 * @param argc N�mero de argumentos na linha de comando.
 * @param argv Array de strings contendo os argumentos da linha de comando.
 * @return 0 em caso de sucesso.
 */
int main(int argc, char* argv[]) {

#pragma region VARIAVEIS
	int comando, controloDeCiclo, id, calorias;
	int numPlanos, numDietas, numPacientes;
	Paciente pacientes[MAX_PACIENTES];
	Dieta dietas[MAX_DIETAS];
	Plano planos[MAX_PLANOS];

	char dataInicial[MAX_DATA_TEMP];
	char dataFinal[MAX_DATA_TEMP];
	char refeicaoTemp[MAX_REFEICAO_TEMP];
#pragma endregion
	if (argc == 1) {
		printf("Nao foram introduzidos ficheiros. A tentar carregar informacao...\n");
		Continuar();
		LimpaEcra();
		numPacientes = LerFicheiroPacientesBIN("Pacientes.bin", pacientes);
		numDietas = LerFicheiroDietasBIN("Dietas.bin", dietas);
		numPlanos = LerFicheiroPlanosBIN("Planos.bin", planos);
		if (numPacientes == ERRO_AO_ABRIR_FICHEIRO || numDietas == ERRO_AO_ABRIR_FICHEIRO || numPlanos == ERRO_AO_ABRIR_FICHEIRO) {
			printf("Nao foi possivel ler ficheiros\n");
			Continuar();
			return ERRO_AO_ABRIR_FICHEIRO;
		}
		else {
			printf("Ficheiros carregados com sucesso\n");
			Continuar();
		}
	}

/*
* @brief Disponibiliza��o de imforma��o sobre o projeto e seus autores.
* @note Deve ser invocada apenas pelo terminal, atrav�s do uso da flag "-info"
* @return Sucesso - Valor correspondente ao sucesso da invoca��o da fun��o.
*/
#pragma region INFO
	if (argc > 1 && strcmp(argv[1], "-info") == 0) {
		MostraInfo();
		return SUCESSO;
	}
#pragma endregion

/*
* @brief Disponibiliza��o de ajuda.
* @note Ajuda relativa � sintaxe a usar com o programa e deve ser invocada usando a flag "-ajuda" via terminal.
* @return ERRO_AO_ABRIR_FICHEIRO - Erro correspondente � falha da abertura do ficheiro.
*/
#pragma region AJUDA
	if (argc > 1 && strcmp(argv[1], "-ajuda") == 0) {
		MostraAjuda();
		return SUCESSO;
	}
#pragma endregion

/*
* @brief Abertura de ficheiros.
* @note Se a fun��o main.c n�o receber argumentos � fornecido um aviso de erro.
* @return ERRO_AO_ABRIR_FICHEIRO - Erro correspondente � falha da abertura do ficheiro.
*/
#pragma region ABERTURA_FICHEIROS
	if (argc > 1 && argc < 5 ) {
		printf("Nao foram introduzidos os argumentos necessarios");
		return ERRO_AO_ABRIR_FICHEIRO;
	}
#pragma endregion

#pragma region IMPORTACAO_DADOS
	
	if (argc == 5) {
		char* nomePaciente = argv[2];
		char* nomeDieta = argv[3];
		char* nomePlano = argv[4];
		if (strcmp(argv[1], "-bin") == 0) {
			numPacientes = LerFicheiroPacientesBIN(nomePaciente, pacientes);
			numDietas = LerFicheiroDietasBIN(nomeDieta, dietas);
			numPlanos = LerFicheiroPlanosBIN(nomePlano, planos);
		}
		if (strcmp(argv[1], "-csv") == 0) {
			numPacientes = LerPacientesCSV(nomePaciente, pacientes);
			numDietas = LerDietasCSV(nomeDieta, dietas);
			numPlanos = LerPlanosCSV(nomePlano, planos);
		}
		if (numPacientes == ERRO_AO_ABRIR_FICHEIRO || numDietas == ERRO_AO_ABRIR_FICHEIRO || numPlanos == ERRO_AO_ABRIR_FICHEIRO) {
			printf("N�o foi possivel ler ficheiros\n");
			return ERRO_AO_ABRIR_FICHEIRO;
		}
	}
#pragma endregion

/*
* @brief Menu de utiliza��o do programa.
* @note Faz uso de um switch case contido num ciclo para disponibilizar as v�rias op��es, controlando-o atrav�s da vari�vel controloDeCiclo.
*/
#pragma region MENU
	controloDeCiclo = 1;

	while(controloDeCiclo != 0) {
		LimpaEcra();
		MostraMenu();
		printf("Digite o numero da operacao pretendida: ");
		scanf("%d", &comando);

		switch (comando) {
			case 1:
			LimpaEcra();
			LerDataInicial(dataInicial);
			LerDataFinal(dataFinal);
			calorias = LerCalorias();
			LimpaEcra();
			NumeroDePacientesQueUltrapassaramCalorias(dietas, pacientes, numDietas, calorias, numPacientes, ConverteData(dataInicial), ConverteData(dataFinal));
			Continuar();
			LimpaEcra();
				break;

			case 2:
			LimpaEcra();
			LerDataInicial(dataInicial);
			LerDataFinal(dataFinal);
			PacientesRealizaramRefeicaoCaloriasForaIntervalo(dietas, pacientes, planos, numDietas, numPacientes, numPlanos, ConverteData(dataInicial), ConverteData(dataFinal));
			Continuar();
			LimpaEcra();
				break;

			case 3:
			LimpaEcra();
			LerDataInicial(dataInicial);
			LerDataFinal(dataFinal);
			id = LerID();
			LimpaEcra();
			LerRefeicao(refeicaoTemp);

			ListarPlanoParaRefeicao(planos, id, DefineRefeicaoEnum(refeicaoTemp), numPlanos, ConverteData(dataInicial), ConverteData(dataFinal));
			Continuar();
			LimpaEcra();
				break;

			case 4:
			LimpaEcra();
			LerDataInicial(dataInicial);
			LerDataFinal(dataFinal);
			MediaCaloriasPorRefeicao(dietas, pacientes, numDietas, numPacientes, ConverteData(dataInicial), ConverteData(dataFinal));
			Continuar();
			LimpaEcra();
				break;

			case 5:
			LimpaEcra();
			Tabela(planos, dietas, pacientes, numDietas, numPlanos, numPacientes);
			Continuar();
			LimpaEcra();
				break;
			case 6:
				LimpaEcra();
				MostraAjuda();
				Continuar();
				LimpaEcra();
				break;
			case 7:
				LimpaEcra();
				MostraInfo();
				Continuar();
				LimpaEcra();
				break;
			case 10:
			LimpaEcra();
				printf("\tObrigado pela sua utilizacao.\n\tMantenha um estilo de vida saudavel.\n\n");
				controloDeCiclo = 0;

				break;

			default:
			while (getchar() != '\n') ;
			LimpaEcra();
				printf("\tOperacao Invalida!\n");
			LimpaEcra();
		}
	}
#pragma endregion

#pragma region ESCRITA_FICHEIROS
	EscreverFicheiroPacientesBIN("Pacientes.bin", pacientes, numPacientes);
	EscreverFicheiroDietasBIN("Dietas.bin", dietas, numDietas);
	EscreverFicheiroPlanosBIN("Planos.bin", planos, numPlanos);
#pragma endregion

return 0;
}