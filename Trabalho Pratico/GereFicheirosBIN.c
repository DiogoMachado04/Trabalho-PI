/**
	@file      GereFicheirosBIN.c
	@brief     Funcoes que gerem ficheiros binarios
	@author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
	@date      30.12.2023
**/
#include <stdio.h>
#include "GereFicheirosBIN.h"
#include "Pacientes.h"
#include "Constantes.h"
#pragma warning (disable:4996)

#pragma region Escrever  Ficheiro BIN
/**
	@brief  Escreve dados dos pacientes num ficheiro binario.
	@param  fileName  - Nome do ficheiro binario.
	@param  pacientes - Array de estruturas Paciente.
	@param  n         - Numero de pacientes no array.
	@retval            - Codigo de sucesso ou erro.
**/
int EscreverFicheiroPacientesBIN(char fileName[], Paciente pacientes[], int n) {
	FILE* fp = fopen(fileName, "wb");
	if (fp == NULL) {
		return ERRO_AO_ABRIR_FICHEIRO;
	}

	for (int i = 0; i < n; i++) {
		fwrite(&pacientes[i], 1, sizeof(Paciente), fp);
	}
	fclose(fp);
	return SUCESSO;
}

/**
	@brief  Escreve dados das dietas num ficheiro binario.
	@param  fileName - Nome do ficheiro binario.
	@param  dietas   - Array de estruturas Dieta.
	@param  n        - Numero de dietas no array.
	@retval           - Codigo de sucesso ou erro.
**/
int EscreverFicheiroDietasBIN(char fileName[], Dieta dietas[], int n) {
	FILE* fp = fopen(fileName, "wb");
	if (fp == NULL) {
		return ERRO_AO_ABRIR_FICHEIRO;
	}

	for (int i = 0; i < n; i++) {
		fwrite(&dietas[i], 1, sizeof(Dieta), fp);
	}
	fclose(fp);
	return SUCESSO;
}

/**
	@brief  Escreve dados dos planos num ficheiro binario.
	@param  fileName - Nome do ficheiro binario.
	@param  planos   - Array de estruturas Plano.
	@param  n        - Numero de planos no array.
	@retval           - Codigo de sucesso ou erro.
**/
int EscreverFicheiroPlanosBIN(char fileName[], Plano planos[], int n) {
	FILE* fp = fopen(fileName, "wb");
	if (fp == NULL) {
		return ERRO_AO_ABRIR_FICHEIRO;
	}

	for (int i = 0; i < n; i++) {
		fwrite(&planos[i], 1, sizeof(Plano), fp);
	}
	fclose(fp);
	return SUCESSO;
}

#pragma endregion

#pragma region Ler Ficheiro BIN
/**
	@brief  Le dados dos pacientes de um ficheiro binario.
	@param  fileName    - Nome do ficheiro binario.
	@param  pacientes   - Array de estruturas Paciente.
	@retval             - Numero de pacientes lidos ou codigo de erro.
**/
int LerFicheiroPacientesBIN(char fileName[], Paciente pacientes[]) {
	FILE* fp = fopen(fileName, "rb");
	int numeroPacientes = 0;
	if (fp == NULL) {
		return ERRO_AO_ABRIR_FICHEIRO;
	}
	while (fread(&pacientes[numeroPacientes], 1, sizeof(Paciente), fp)) {
		numeroPacientes++;
	}
	fclose(fp);
	return numeroPacientes;
}

/**
	@brief  Le dados das dietas de um ficheiro binario.
	@param  fileName    - Nome do ficheiro binario.
	@param  dietas      - Array de estruturas Dieta.
	@retval             - Numero de dietas lidas ou codigo de erro.
**/
int LerFicheiroDietasBIN(char fileName[], Dieta dietas[]) {
	FILE* fp = fopen(fileName, "rb");
	int numeroDietas = 0;
	if (fp == NULL) {
		return ERRO_AO_ABRIR_FICHEIRO;
	}
	while (fread(&dietas[numeroDietas], 1, sizeof(Dieta), fp)) {
		numeroDietas++;
	}
	fclose(fp);
	return numeroDietas;
}

/**
	@brief  Le dados dos planos de um ficheiro binário.
	@param  fileName    - Nome do ficheiro binário.
	@param  planos      - Array de estruturas Plano.
	@retval             - Número de planos lidos ou código de erro.
**/
int LerFicheiroPlanosBIN(char fileName[], Plano planos[]) {
	FILE* fp = fopen(fileName, "rb");
	int numeroPlanos = 0;
	if (fp == NULL) {
		return ERRO_AO_ABRIR_FICHEIRO;
	}
	while (fread(&planos[numeroPlanos], 1, sizeof(Plano), fp)) {
		numeroPlanos++;
	}
	fclose(fp);
	return numeroPlanos;
}
#pragma endregion