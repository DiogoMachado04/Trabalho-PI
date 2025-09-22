/**
    @file      GestaoFicheirosCSV.h
    @brief     Cabecalhos das funcoes que gerem ficheiros CSV
    @author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
    @date      30.12.2023
**/
#pragma once
#include "Pacientes.h"

/**
    @brief  Le dados de pacientes de um ficheiro CSV.
    @param  fileName      - Nome do ficheiro CSV a ser lido.
    @param  pacientes     - Array de estruturas Paciente para armazenar os dados lidos.
    @retval               - Retorna o número de pacientes lidos com sucesso. Caso o ficheiro nao exista ou esteja corrompido, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int LerPacientesCSV(char fileName[], Paciente pacientes[]);
/**
    @brief  Le dados de planos de dieta de um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser lido.
    @param  planos   - Array de estruturas Plano para armazenar os dados lidos.
    @retval          - Retorna o número de planos de dieta lidos com sucesso. Caso o ficheiro nao exista ou esteja corrompido, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int LerPlanosCSV(char fileName[], Plano planos[]);
/**
    @brief  Le dados de dietas de um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser lido.
    @param  dietas   - Array de estruturas Dieta para armazenar os dados lidos.
    @retval          - Retorna o número de dietas lidas com sucesso. Caso o ficheiro nao exista ou esteja corrompido, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int LerDietasCSV(char fileName[], Dieta dietas[]);
/**
    @brief  Escreve dados de pacientes em um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser escrito.
    @param  pacientes - Array de estruturas Paciente contendo os dados a serem escritos.
    @param  num       - Número de pacientes a serem escritos.
    @retval           - Retorna SUCESSO se os dados foram escritos com sucesso. Caso contrario, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int EscreverPacientesCSV(char fileName[], Paciente pacientes[], int num);
/**
    @brief  Escreve dados de dietas em um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser escrito.
    @param  dietas   - Array de estruturas Dieta contendo os dados a serem escritos.
    @param  num      - Número de dietas a serem escritas.
    @retval           - Retorna SUCESSO se os dados foram escritos com sucesso. Caso contrario, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int EscreverDietaCSV(char fileName[], Dieta dietas[], int num);
/**
    @brief  Escreve dados de planos de dieta em um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser escrito.
    @param  planos   - Array de estruturas Plano contendo os dados a serem escritos.
    @param  num      - Número de planos de dieta a serem escritos.
    @retval           - Retorna SUCESSO se os dados foram escritos com sucesso. Caso contrario, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int EscreverPlanosCSV(char fileName[], Plano planos[], int num);

