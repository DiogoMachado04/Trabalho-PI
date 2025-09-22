/**
	@file      GereFicheirosBIN.h
	@brief     Cabecalhos das funcoes que gerem ficheiros binarios
	@author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
	@date      30.12.2023
**/
#pragma once
#include "Pacientes.h"

/**
	@brief  Escreve dados dos pacientes num ficheiro binario.
	@param  fileName  - Nome do ficheiro binario.
	@param  pacientes - Array de estruturas Paciente.
	@param  n         - Numero de pacientes no array.
	@retval            - Codigo de sucesso ou erro.
**/
int EscreverFicheiroPacientesBIN(char fileName[], Paciente pacientes[], int n);
/**
	@brief  Le dados dos pacientes de um ficheiro binario.
	@param  fileName    - Nome do ficheiro binario.
	@param  pacientes   - Array de estruturas Paciente.
	@retval             - Numero de pacientes lidos ou codigo de erro.
**/
int LerFicheiroPacientesBIN(char fileName[], Paciente pacientes[]);
/**
	@brief  Escreve dados das dietas num ficheiro binario.
	@param  fileName - Nome do ficheiro binario.
	@param  dietas   - Array de estruturas Dieta.
	@param  n        - Numero de dietas no array.
	@retval           - Codigo de sucesso ou erro.
**/
int EscreverFicheiroDietasBIN(char fileName[], Dieta dietas[], int n);
/**
	@brief  Le dados das dietas de um ficheiro binario.
	@param  fileName    - Nome do ficheiro binario.
	@param  dietas      - Array de estruturas Dieta.
	@retval             - Numero de dietas lidas ou codigo de erro.
**/
int LerFicheiroDietasBIN(char fileName[], Dieta dietas[]);
/**
	@brief  Escreve dados dos planos num ficheiro binario.
	@param  fileName - Nome do ficheiro binario.
	@param  planos   - Array de estruturas Plano.
	@param  n        - Numero de planos no array.
	@retval           - Codigo de sucesso ou erro.
**/
int EscreverFicheiroPlanosBIN(char fileName[], Plano planos[], int n);
/**
	@brief  Le dados dos planos de um ficheiro binário.
	@param  fileName    - Nome do ficheiro binário.
	@param  planos      - Array de estruturas Plano.
	@retval             - Número de planos lidos ou código de erro.
**/
int LerFicheiroPlanosBIN(char fileName[], Plano planos[]);
