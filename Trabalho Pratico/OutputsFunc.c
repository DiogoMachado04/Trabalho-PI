/**
    @file      OutputsFunc.c
    @brief     Funcoes relativas aos outputs das funcoes do programa
    @author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
    @date      30.12.2023
**/
#include <stdio.h>
#include "Pacientes.h"
#include "Utilidades.h"

 /**
     @brief  Mostra o numero de pacientes que ultrapassaram o limite de calorias especificado.
     @param  contador           - Numero de pacientes que ultrapassaram o limite de calorias.
     @retval                    - Nenhum valor de retorno.
 **/
void MostraNumPacientesUltrapassaramCal(int contador) {
	printf("%d pessoas excederam as calorias indicadas\n", contador);
}

 /**
     @brief  Mostra as informacoes de um plano de dieta.
     @param  planos             - Estrutura Plano que contem os dados do plano de dieta.
     @param  dataConvertida     - String que contem a data convertida para apresentacao.
     @param  refeicaoConvertida - String que contem a refeicao convertida para apresentacao.
     @retval                    - Nenhum valor de retorno.
 **/
void MostraPlano(Plano planos, char dataConvertida[], char refeicaoConvertida[]) {
	printf("%d;%s;%s;%d;%d\n", planos.pacienteID, dataConvertida, refeicaoConvertida, planos.min, planos.max);
}

 /**
     @brief  Mostra as medias de consumo de calorias por refeicao para um paciente.
     @param  media              - Valor da media de consumo de calorias.
     @param  id                 - Identificador do paciente.
     @param  refeicao           - String que contem a refeicao para apresentacao.
     @param  nome               - String que contem o nome do paciente para apresentacao.
     @retval                    - Nenhum valor de retorno.
 **/
void MostrarMedias(float media, int id, char refeicao[], char nome[]) {
	printf("O paciente %d chamado %s consumiu uma media de %.2f calorias ao %s\n", id, nome, media, refeicao);
}

 /**
     @brief  Mostra as dietas fora do intervalo especificado.
     @param  pacientesForaIntervalo - Array de estruturas ResFunc3 que contem as informacoes das dietas fora do intervalo.
     @param  numDietasForaIntervalo - Numero total de dietas fora do intervalo.
     @retval                        - Nenhum valor de retorno.
 **/

void MostraDietasForaIntervalo(ResFunc3 pacientesForaIntervalo[], int numDietasForaIntervalo) {
	char dataTemp[MAX_DATA_TEMP];
	char refeicaoTemp[MAX_REFEICAO_TEMP];
	printf("|-------|-----------------|-----------------|-----------------|-----------------|------------|------------\n");
	printf("| %-5s | %-15s | %-15s | %-15s | %-15s | %-10s | %-10s |\n", "Num", "Nome", "Data", "Refeicao", "Cal Consum", "Min", "Max");
	printf("|-------|-----------------|-----------------|-----------------|-----------------|------------|------------\n");
	for (int i = 0; i < numDietasForaIntervalo; i++) {
		ConverteDataVolta(pacientesForaIntervalo[i].data, dataTemp);
		ConverteRefeicaoString(pacientesForaIntervalo[i].refeicao, refeicaoTemp);
		printf("| %-5d | %-15s | %-15s | %-15s | %-15d | %-10d | %-10d |\n", pacientesForaIntervalo[i].pacienteID, pacientesForaIntervalo[i].nome, dataTemp, refeicaoTemp,
		pacientesForaIntervalo[i].calConsumidas, pacientesForaIntervalo[i].calMin, pacientesForaIntervalo[i].calMax);
		printf("|-------|-----------------|-----------------|-----------------|-----------------|------------|------------\n");
	}
}

/**
    @brief  Mostra a tabela de registos das refeicoes.
    @param  controlo - Array de estruturas ResFunc3 que contem as informacoes a incluir na tabela.
    @param  indice   - Indice para percorrer o array de controlo.
    @retval           - Nenhum valor de retorno.
**/
void MostraTabela(ResFunc3 controlo[], int indice) {
    printf("|-------|-----------------|-----------------|-----------------|-----------------|----------|----------|----------|\n");
    printf("| %-5s | %-15s | %-15s | %-15s | %-15s | %-8s | %-8s | %-8s |\n",
        "ID", "Nome", "Tipo Refeicao", "Data de Inicio", "Data de Fim", "Cal Min", "Cal Max", "Consumo");
    printf("|-------|-----------------|-----------------|-----------------|-----------------|----------|----------|----------|\n");
    for (int i = 0; i < indice; i++) {
        char refeicaoConvertida[MAX_REFEICAO_TEMP];
        char dataIni[MAX_DATA_TEMP];
        char dataFim[MAX_DATA_TEMP];
        ConverteRefeicaoString(controlo[i].refeicao, refeicaoConvertida);
        ConverteDataVolta(controlo[i].datas.dataInicio, dataIni);
        ConverteDataVolta(controlo[i].datas.dataFim, dataFim);
        printf("| %-5d | %-15s | %-15s | %-15s | %-15s | %-8d | %-8d | %-8d |\n",
            controlo[i].pacienteID, controlo[i].nome, refeicaoConvertida,
            dataIni, dataFim, controlo[i].calMin, controlo[i].calMax, controlo[i].calConsumidas);
        printf("|-------|-----------------|-----------------|-----------------|-----------------|----------|----------|----------|\n");
    }
}