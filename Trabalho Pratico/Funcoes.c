/**
	@file      Funcoes.c
	@brief     Funcoes principais do programa
	@author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
	@date      30.12.2023
**/
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Constantes.h"
#include "Pacientes.h"
#include "Utilidades.h"
#include "OutputsFunc.h"
#include "Media.h"
#pragma warning (disable:4996)

 /**
	 @brief  Calcula o número de pacientes que ultrapassaram um determinado numero de calorias num dado periodo.
	 @param  dietas        - Array de estruturas Dieta que contem os dados das dietas.
	 @param  pacientes     - Array de estruturas Paciente que contem os dados dos pacientes.
	 @param  numDietas     - Numero total de dietas no array dietas.
	 @param  calorias      - Limite de calorias a ser verificado.
	 @param  numPacientes  - Numero total de pacientes no array pacientes.
	 @param  dataInicial   - Data inicial do periodo a ser considerado.
	 @param  dataFinal     - Data final do periodo a ser considerado.
	 @retval               - Retorna SUCESSO se a operação for bem-sucedida. Caso contrario, retorna INSUCESSO.
 **/
int NumeroDePacientesQueUltrapassaramCalorias(Dieta dietas[], Paciente pacientes[], int numDietas, int calorias, int numPacientes, time_t dataInicial, time_t dataFinal) {
	int somaCalorias[MAX_PACIENTES];
	int contador = 0;
	
	if (SomaCaloriasPeriodo(dietas, pacientes, numDietas, numPacientes, somaCalorias, dataInicial, dataFinal) == SUCESSO) {
		for (int i = 0; i < numPacientes; i++) {
			if (calorias < somaCalorias[i]) {
				contador++;
			}
		}
		MostraNumPacientesUltrapassaramCal(contador);
		return SUCESSO;
	}
	return INSUCESSO;
}

 /**
	 @brief  Identifica e mostra as dietas em que as calorias estao fora do intervalo estabelecido pelos planos alimentares.
	 @param  dietas             - Array de estruturas Dieta que contem os dados das dietas.
	 @param  pacientes          - Array de estruturas Paciente que contem os dados dos pacientes.
	 @param  planos             - Array de estruturas Plano que contem os dados dos planos de dieta.
	 @param  numDietas          - Numero total de dietas no array dietas.
	 @param  numPacientes       - Numero total de pacientes no array pacientes.
	 @param  numPlanos          - Numero total de planos no array planos.
	 @param  dataInicial        - Data inicial do periodo a ser considerado.
	 @param  dataFinal          - Data final do periodo a ser considerado.
	 @retval                    - Retorna SUCESSO se a operacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
 **/
int PacientesRealizaramRefeicaoCaloriasForaIntervalo(Dieta dietas[], Paciente pacientes[], Plano planos[], int numDietas, int numPacientes, int numPlanos, time_t dataInicial, time_t dataFinal) {
	ResFunc3 pessoasForaIntervalo[MAX_PACIENTES];
	int numDietasForaIntervalo = 0;
	numDietasForaIntervalo = SomaCaloriasRefeicao(pacientes, dietas, planos, numPacientes, numDietas, numPlanos, pessoasForaIntervalo, numDietasForaIntervalo, dataInicial, dataFinal);
	if (numDietasForaIntervalo== INSUCESSO) {
		return INSUCESSO;
	}

	OrdenaOrdemDecrescentePessoasForaIntervalo(pessoasForaIntervalo, numDietasForaIntervalo);
	MostraDietasForaIntervalo(pessoasForaIntervalo, numDietasForaIntervalo);

	return SUCESSO;
}

 /**
	 @brief  Lista os planos de uma refeicao em especifico, para um determinado paciente, dentro de um determinado periodo de tempo.
	 @param  planos             - Array de estruturas Plano que contem os dados dos planos de dieta.
	 @param  id                 - Identificador do paciente.
	 @param  refeicao           - Enumeracao que representa a refeicao desejada.
	 @param  numPlanos          - Numero total de planos no array planos.
	 @param  dataInicial        - Data inicial do periodo a ser considerado.
	 @param  dataFinal          - Data final do periodo a ser considerado.
	 @retval                    - Retorna SUCESSO se a operacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
 **/
int ListarPlanoParaRefeicao(Plano planos[], int id, Refeicao refeicao, int numPlanos, time_t dataInicial, time_t dataFinal) {
	char dataConvertida[MAX_DATA_TEMP];
	char refeicaoConvertida[MAX_REFEICAO_TEMP];

	for (int i = 0; i < numPlanos; i++) {
		if ((planos[i].refeicao == refeicao) && VerificaPeriodo(dataInicial, dataFinal, planos[i].data)==SUCESSO &&
			id == planos[i].pacienteID) {
			ConverteRefeicaoString(planos[i].refeicao, refeicaoConvertida);
			ConverteDataVolta(planos[i].data, dataConvertida);
			MostraPlano(planos[i], refeicaoConvertida, dataConvertida);
		}
	}
	return SUCESSO;
}

 /**
	 @brief  Calcula e mostra a media de calorias por refeicao para cada paciente num periodo de tempo.
	 @param  dietas             - Array de estruturas Dieta que contem os dados das dietas.
	 @param  pacientes          - Array de estruturas Paciente que contem os dados dos pacientes.
	 @param  numDietas          - Numero total de dietas no array dietas.
	 @param  numPacientes       - Numero total de pacientes no array pacientes.
	 @param  dataInicial        - Data inicial do periodo a ser considerado.
	 @param  dataFinal          - Data final do periodo a ser considerado.
	 @retval                    - Retorna SUCESSO se a operacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
 **/
int MediaCaloriasPorRefeicao(Dieta dietas[], Paciente pacientes[], int numDietas, int numPacientes, time_t dataInicial, time_t dataFinal) {
	float media;
	int soma, contador;
	char refeicaoTemp[MAX_REFEICAO_TEMP];

	for (int i = 0; i < numPacientes; i++) {
		for (int k = PEQUENOALMOCO; k <= JANTAR; k++) {
			media = 0;
			soma = 0;
			contador = 0;
			for (int j = 0; j < numDietas; j++) {
				if ((dietas[j].pacienteID == pacientes[i].pacienteID) && (k == dietas[j].refeicao) 
					&& VerificaPeriodo(dataInicial, dataFinal, dietas[j].data) == SUCESSO) {
					soma += dietas[j].cal;
					contador++;
				}
			}
			if (soma > 0) {
				media = CalculaMedia(soma, contador);
				ConverteRefeicaoString(k, refeicaoTemp);
				MostrarMedias(media, pacientes[i].pacienteID,  refeicaoTemp, pacientes[i].nome);
			}
		}
	}
	return SUCESSO;
}
/**
	@brief  Funcao que realiza a analise e processamento de dados relacionados com dietas, planos e pacientes.
	@param  planos       - Array de estruturas Plano que contem informacoes sobre planos de dieta.
	@param  dietas       - Array de estruturas Dieta que contem informacoes sobre dietas dos pacientes.
	@param  pacientes    - Array de estruturas Paciente que contem informacoes sobre os pacientes.
	@param  numDietas    - Numero total de dietas no array dietas.
	@param  numPlanos    - Numero total de planos no array planos.
	@param  numPacientes - Numero total de pacientes no array pacientes.
	@retval              - Retorna SUCESSO se a funcao for executada com exito, senao retorna INSUCESSO.
**/
int Tabela(Plano planos[], Dieta dietas[], Paciente pacientes[], int numDietas, int numPlanos, int numPacientes) {
	if (numDietas < 0 || numPlanos < 0 || numPacientes < 0) return INSUCESSO;
	ResFunc3 controlo[MAX_PACIENTES] = { -1 };
    int indice = 0;
    for (int i = 0; i < numDietas; i++) {
        if (VerificaRegisto(controlo, dietas[i].pacienteID, dietas[i].refeicao, indice) == SUCESSO) continue; //se existe registo, passa para o indice seguinte
        else { //caso nao exista registo, cria-o            
            CriaRegisto(controlo, dietas, indice, i);
            VerificaExisteMaisRegistosMesmaRefeicao(controlo, dietas, i, indice, numDietas);
            GuardaNomePaciente(controlo, pacientes, numPacientes, indice);
            SomaLimitesCalorias(controlo, planos, indice, numPlanos);
            indice++;
        }

    }
    MostraTabela(controlo, indice);
	return SUCESSO;
}
