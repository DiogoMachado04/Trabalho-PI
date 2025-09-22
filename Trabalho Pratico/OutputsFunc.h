/**
    @file      OutputsFunc.h
    @brief     Cabecalhos das funcoes relativas aos outputs das funcoes do programa
    @author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
    @date      30.12.2023
**/
#pragma once
#include "Pacientes.h"

/**
     @brief  Mostra o numero de pacientes que ultrapassaram o limite de calorias especificado.
     @param  contador           - Numero de pacientes que ultrapassaram o limite de calorias.
     @retval                    - Nenhum valor de retorno.
 **/
void MostraNumPacientesUltrapassaramCal(int contador);
/**
     @brief  Mostra as informacoes de um plano de dieta.
     @param  planos             - Estrutura Plano que contem os dados do plano de dieta.
     @param  dataConvertida     - String que contem a data convertida para apresentacao.
     @param  refeicaoConvertida - String que contem a refeicao convertida para apresentacao.
     @retval                    - Nenhum valor de retorno.
 **/
void MostraPlano(Plano planos, char dataConvertida[], char refeicaoConvertida[]);
/**
     @brief  Mostra as medias de consumo de calorias por refeicao para um paciente.
     @param  media              - Valor da media de consumo de calorias.
     @param  id                 - Identificador do paciente.
     @param  refeicao           - String que contem a refeicao para apresentacao.
     @param  nome               - String que contem o nome do paciente para apresentacao.
     @retval                    - Nenhum valor de retorno.
 **/
void MostrarMedias(float media, int id, char refeicao[], char nome[]);
/**
     @brief  Mostra as dietas fora do intervalo especificado.
     @param  pacientesForaIntervalo - Array de estruturas ResFunc3 que contem as informacoes das dietas fora do intervalo.
     @param  numDietasForaIntervalo - Numero total de dietas fora do intervalo.
     @retval                        - Nenhum valor de retorno.
 **/
void MostraDietasForaIntervalo(ResFunc3 pacientesForaIntervalo[], int numDietasForaIntervalo);
/**
    @brief  Mostra a tabela de registos das refeicoes.
    @param  controlo - Array de estruturas ResFunc3 que contem as informacoes a incluir na tabela.
    @param  indice   - Indice para percorrer o array de controlo.
    @retval           - Nenhum valor de retorno.
**/
void MostraTabela(ResFunc3 controlo[], int indice);