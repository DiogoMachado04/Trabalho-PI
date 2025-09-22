/**
	@file      Pacientes.h
	@brief     Structs e enumerados utilizados no programa
	@author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
	@date      30.12.2023
**/
#pragma once

#include <stdio.h>
#include <time.h>
#include "Constantes.h"

//Enumerado Refeicao
typedef enum Refeicao {
	PEQUENOALMOCO,  // 0
	ALMOCO,			// 1
	JANTAR			// 2
}Refeicao;

//Estrutura de um Plano
typedef struct Plano {
	int pacienteID;		//Identificacao unica do paciente
	Refeicao refeicao;	//Tipo de refeicao
	time_t data;		//Data da refeicao
	int min;			//Calorias Minimas
	int max;			//Calorias Maximas
} Plano;

//Estrutura de um Paciente
typedef struct Paciente {
	int pacienteID;				//Identificacao unica do paciente
	char nome[MAX_CARACTERES];	//Nome do paciente
	char telemovel[TEL];		//Numero de telemóvel
} Paciente;

typedef struct Dieta {
	int pacienteID;					//Identificacao unica do paciente
	time_t data;					//Data da refeicao
	Refeicao refeicao;				//Tipo de refeicao
	char alimento[MAX_CARACTERES];	//Alimento comido
	int cal;						//Numero de calorias do alimento
}Dieta;

//Estrutura de datas final e inicial de um plano
typedef struct Datas {
	time_t dataInicio;	//Data de inicio
	time_t dataFim;		//Data de fim
}Datas;

//Estrutura auxiliar para exercicios 3 e 6
typedef struct Ex3 {
	int pacienteID;				//Identificacao unica do paciente
	char nome[MAX_CARACTERES];	//Nome do paciente
	time_t data;				//Data da refeicao
	Refeicao refeicao;			//Tipo de refeicao
	int calConsumidas;			//Numero de calorias consumidas
	int calMin;					//Numero de calorias minimas no plano para esta refeicao
	int calMax;					//Numero de calorias maximas no plano para esta refeicao
	Datas datas;				//Estrutura Datas que contem a Data Final e a Data Inicial do tipo de refeicao no plano
}ResFunc3;











