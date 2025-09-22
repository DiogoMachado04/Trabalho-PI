/**
	@file      Funcoes.h
	@brief     Cabecalhos das funcoes principais do programa
	@author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
	@date      30.12.2023
**/
#pragma once
#include "Pacientes.h"
#include <time.h>

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
int NumeroDePacientesQueUltrapassaramCalorias(Dieta dietas[], Paciente pacientes[], int numDietas, int calorias, int numPacientes, time_t dataInicial, time_t dataFinal);
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
int PacientesRealizaramRefeicaoCaloriasForaIntervalo(Dieta dietas[], Paciente pacientes[], Plano planos[], int numDietas, int numPacientes, int numPlanos, time_t dataInicial, time_t dataFinal);
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
int ListarPlanoParaRefeicao(Plano planos[], int id, Refeicao refeicao, int numPlanos, time_t dataInicial, time_t dataFinal);
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
int MediaCaloriasPorRefeicao(Dieta dietas[], Paciente pacientes[], int numDietas, int numPacientes, time_t dataInicial, time_t dataFinal);
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
int Tabela(Plano planos[], Dieta dietas[], Paciente pacientes[], int numDietas, int numPlanos, int numPacientes);