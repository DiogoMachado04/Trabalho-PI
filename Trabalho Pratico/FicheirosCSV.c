/**
    @file      GestaoFicheirosCSV.c
    @brief     Funcoes que gerem ficheiros CSV
    @author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
    @date      30.12.2023
**/
#include "Pacientes.h"
#include <string.h>
#include"Utilidades.h"

#pragma warning (disable: 4996)

#pragma region Ler Dados CSV
/**
    @brief  Le dados de pacientes de um ficheiro CSV.
    @param  fileName      - Nome do ficheiro CSV a ser lido.
    @param  pacientes     - Array de estruturas Paciente para armazenar os dados lidos.
    @retval               - Retorna o número de pacientes lidos com sucesso. Caso o ficheiro nao exista ou esteja corrompido, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int LerPacientesCSV(char fileName[], Paciente pacientes[]) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) return ERRO_AO_ABRIR_FICHEIRO;
    int numeroPacientes = 0;
    while (fscanf(fp, "%d;%[^;];%s\n", &pacientes[numeroPacientes].pacienteID, pacientes[numeroPacientes].nome, pacientes[numeroPacientes].telemovel)==3) {
        numeroPacientes++;
    }
    fclose(fp);
    return numeroPacientes;
}

/**
    @brief  Le dados de planos de dieta de um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser lido.
    @param  planos   - Array de estruturas Plano para armazenar os dados lidos.
    @retval          - Retorna o número de planos de dieta lidos com sucesso. Caso o ficheiro nao exista ou esteja corrompido, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int LerPlanosCSV(char fileName[], Plano planos[]) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) return ERRO_AO_ABRIR_FICHEIRO;
    int numeroPlanos = 0;
    char dataTemp[MAX_DATA_TEMP];
    char refeicaoTemp[MAX_REFEICAO_TEMP];
    while (fscanf(fp, "%d;%[^;];%[^;];%d;%d\n", &planos[numeroPlanos].pacienteID, dataTemp, refeicaoTemp, &planos[numeroPlanos].min, &planos[numeroPlanos].max)==5) {
        planos[numeroPlanos].data = ConverteData(dataTemp);
        planos[numeroPlanos].refeicao=DefineRefeicaoEnum(refeicaoTemp);
        numeroPlanos++;
    }
    fclose(fp);
    return numeroPlanos;
}

/**
    @brief  Le dados de dietas de um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser lido.
    @param  dietas   - Array de estruturas Dieta para armazenar os dados lidos.
    @retval          - Retorna o número de dietas lidas com sucesso. Caso o ficheiro nao exista ou esteja corrompido, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int LerDietasCSV(char fileName[], Dieta dietas[]) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) return ERRO_AO_ABRIR_FICHEIRO;
    int numeroDietas = 0;
    char dataTemp[MAX_DATA_TEMP];
    char refeicaoTemp[MAX_REFEICAO_TEMP];
    while (fscanf(fp, "%d;%[^;];%[^;];%[^;];%d\n", &dietas[numeroDietas].pacienteID, dataTemp, refeicaoTemp, dietas[numeroDietas].alimento, &dietas[numeroDietas].cal)==5) {
        dietas[numeroDietas].data = ConverteData(dataTemp);
        dietas[numeroDietas].refeicao = DefineRefeicaoEnum(refeicaoTemp);
        numeroDietas++;
    }
    fclose(fp);
    return numeroDietas;
}
#pragma endregion

#pragma region Exportar CSV
/**
    @brief  Escreve dados de pacientes em um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser escrito.
    @param  pacientes - Array de estruturas Paciente contendo os dados a serem escritos.
    @param  num       - Número de pacientes a serem escritos.
    @retval           - Retorna SUCESSO se os dados foram escritos com sucesso. Caso contrario, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int EscreverPacientesCSV(char fileName[], Paciente pacientes[], int num) {
    FILE* fp = fopen(fileName, "w");
    if (fp == NULL) {
        return ERRO_AO_ABRIR_FICHEIRO;
    }
    for (int i = 0; i < num; i++) {
        fprintf(fp, "%d;%s;%s\n", pacientes[i].pacienteID, pacientes[i].nome, pacientes[i].telemovel);
    }
    fclose(fp);
    return SUCESSO;
}

/**
    @brief  Escreve dados de dietas em um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser escrito.
    @param  dietas   - Array de estruturas Dieta contendo os dados a serem escritos.
    @param  num      - Número de dietas a serem escritas.
    @retval           - Retorna SUCESSO se os dados foram escritos com sucesso. Caso contrario, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int EscreverDietaCSV(char fileName[], Dieta dietas[], int num) {
    FILE* fp = fopen(fileName, "w");
    char dataTemp[MAX_DATA_TEMP];
    char refeicaoTemp[MAX_REFEICAO_TEMP];
    if (fp == NULL) {
        return ERRO_AO_ABRIR_FICHEIRO;
    }
    for (int i = 0; i < num; i++) {
        ConverteDataVolta(dietas[i].data, dataTemp);
        ConverteRefeicaoString(dietas[i].refeicao, refeicaoTemp);
        fprintf(fp, "%d;%s;%s;%s;%d\n", dietas[i].pacienteID, dataTemp, refeicaoTemp, dietas[i].alimento, dietas[i].cal);
    }
    fclose(fp);
    return SUCESSO;
}

/**
    @brief  Escreve dados de planos de dieta em um ficheiro CSV.
    @param  fileName - Nome do ficheiro CSV a ser escrito.
    @param  planos   - Array de estruturas Plano contendo os dados a serem escritos.
    @param  num      - Número de planos de dieta a serem escritos.
    @retval           - Retorna SUCESSO se os dados foram escritos com sucesso. Caso contrario, retorna ERRO_AO_ABRIR_FICHEIRO.
**/
int EscreverPlanosCSV(char fileName[], Plano planos[], int num) {
    FILE* fp = fopen(fileName, "w");
    char dataTemp[MAX_DATA_TEMP];
    char refeicaoTemp[MAX_REFEICAO_TEMP];
    if (fp == NULL) {
        return ERRO_AO_ABRIR_FICHEIRO;
    }
    for (int i = 0; i < num; i++) {
        ConverteDataVolta(planos[i].data, dataTemp);
        ConverteRefeicaoString(planos[i].refeicao, refeicaoTemp);
        fprintf(fp, "%d;%s;%s;%d;%d\n", planos[i].pacienteID, dataTemp, refeicaoTemp, planos[i].min, planos[i].max);
    }
    fclose(fp);
    return SUCESSO;
}
#pragma endregion

