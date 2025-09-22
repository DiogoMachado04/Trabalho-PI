/**
    @file      Utilidades.c
    @brief     Funcoes auxiliares as funcoes principais do programa
    @author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
    @date      30.12.2023
**/
#pragma warning (disable: 4996)
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "Constantes.h"
#include "Pacientes.h"

/**
    @brief  Converte uma string de data no formato "dia-mes-ano" para um valor do tipo time_t.
    @param  dataTemp - String contendo a data no formato "dia-mes-ano".
    @retval           - Retorna o valor do tipo time_t correspondente a data convertidase a conversao for bem-sucedida, senao, retorna um codigo de erro.
                      
**/
int ConverteData(char dataTemp[]) {
    struct tm tm = { 0 }; //colocar a data toda a zeros
    int dia;
    int mes;
    int ano;

    if (sscanf(dataTemp, "%d-%d-%d", &dia, &mes, &ano) != 3)
        return ERRO_DATA_FORMATO_INVALIDO;

    tm.tm_year = ano - 1900; //Anos desde 1900
    tm.tm_mon = mes - 1;     //Mes desde Janeiro (Indice 0)
    tm.tm_mday = dia;        //Dia do mes
    tm.tm_isdst = -1;        //Unknown DST (daylight time) status

    time_t data = mktime(&tm);

    if (data != -1)
        return data;
    
    return ERRO_AO_CONVERTER_DATA;
}

/**
    @brief  Converte um valor do tipo time_t para uma string no formato "dia-mes-ano".
    @param  data             - Valor do tipo time_t a ser convertido.
    @param  dataConvertida   - String para armazenar a data convertida.
    @retval                  - Retorna DATA_CONVERTIDA_COM_SUCESSO se a conversao for bem-sucedida.
                              Se a conversao falhar, retorna um codigo de erro.
**/
int ConverteDataVolta(time_t data, char dataConvertida[]) {
    char buffer[MAX_DATA_TEMP];
    struct tm* dataTemp;
    dataTemp = localtime(&data);

    if((strftime(buffer, sizeof(buffer), "%d-%m-%Y", dataTemp))==0)
        return ERRO_AO_CONVERTER_DATA;
    else{
        strcpy(dataConvertida, buffer);
        return DATA_CONVERTIDA_COM_SUCESSO;
    }
}

/**
    @brief  Converte uma string que representa uma refeicao para o valor correspondente da enumeração RefeicaoEnum.
    @param  refeicaoTemp - String que contem a representacao da refeicao.
    @retval              - Retorna o valor correspondente da enumeracao RefeicaoEnum.
                          Se a string nao corresponder a nenhuma refeicao, retorna INSUCESSO.
**/
int DefineRefeicaoEnum(char refeicaotemp[]) {
    if ((strcmp(refeicaotemp, "pequeno almoco") == 0) || (strcmp(refeicaotemp, "Pequeno Almoco") == 0)) {
        return PEQUENOALMOCO;
    }
    if ((strcmp(refeicaotemp, "almoco") == 0) || (strcmp(refeicaotemp, "Almoco") == 0)) {
        return ALMOCO;
    }
    if ((strcmp(refeicaotemp, "jantar") == 0) || (strcmp(refeicaotemp, "Jantar") == 0)) {
        return JANTAR;
    }
    return INSUCESSO;
}

/**
    @brief  Ordena um array de pacientes em ordem decrescente com base no identificador do paciente.
    @param  pacientes - Array de estruturas Paciente a ser ordenado.
    @param  n         - Numero de elementos no array.
    @retval            - Retorna SUCESSO se a ordenacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
**/
int OrdenaOrdemDecrescentePacientes(Paciente pacientes[], int n) {
    Paciente aux;

    if (n < 0) {
        return INSUCESSO;
    }

    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pacientes[j].pacienteID > pacientes[i].pacienteID) {
                aux = pacientes[i];
                pacientes[i] = pacientes[j];
                pacientes[j] = aux;
            }
        }
    }
    return SUCESSO;
}

/**
    @brief  Ordena um array de estruturas ResFunc3 em ordem decrescente com base no identificador do paciente.
    @param  dietas - Array de estruturas ResFunc3 a ser ordenado.
    @param  n      - Numero de elementos no array.
    @retval         - Retorna SUCESSO se a ordenacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
**/
int OrdenaOrdemDecrescentePessoasForaIntervalo(ResFunc3 dietas[], int n) {
    ResFunc3 aux;

    if (n < 0) {
        return INSUCESSO;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dietas[j].pacienteID > dietas[i].pacienteID) {
                aux = dietas[i];
                dietas[i] = dietas[j];
                dietas[j] = aux;
            }
        }
    }
    return SUCESSO;
}

/**
    @brief  Verifica se uma data esta dentro de um determinado periodo.
    @param  dataInicial - Data inicial do periodo.
    @param  dataFinal   - Data final do periodo.
    @param  data        - Data a ser verificada.
    @retval             - Retorna SUCESSO se a data estiver dentro do periodo. Caso contrario, retorna INSUCESSO.
**/
int VerificaPeriodo(time_t dataInicial, time_t dataFinal, time_t data) {
    
    if (dataInicial <= data && dataFinal >= data) {
        return SUCESSO;
    }

    return INSUCESSO;
}

/**
    @brief  Converte um valor da enumeracao Refeicao para uma string correspondente.
    @param  refeicao           - Valor da enumeracao Refeicao a ser convertido.
    @param  refeicaoConvertida - String para armazenar a refeicao convertida.
    @retval                    - Retorna SUCESSO se a conversao for bem-sucedida. Caso contrario, retorna INSUCESSO.
**/
int ConverteRefeicaoString(Refeicao refeicao, char refeicaoConvertida[]) {
    if (refeicao == PEQUENOALMOCO) {
        strcpy(refeicaoConvertida, "Pequeno Almoco");
        return SUCESSO;
    }
    if (refeicao == ALMOCO) {
        strcpy(refeicaoConvertida, "Almoco");
        return SUCESSO;
    }
    if (refeicao == JANTAR) {
        strcpy(refeicaoConvertida, "Jantar");
        return SUCESSO;
    }
    return INSUCESSO;
}

/**
    @brief  Calcula a soma de calorias consumidas por paciente num determinado periodo.
    @param  dietas        - Array de estruturas Dieta que contem informacoes sobre as dietas dos pacientes.
    @param  pacientes     - Array de estruturas Paciente que contem informacoes sobre os pacientes.
    @param  numDietas     - Numero total de dietas no array dietas.
    @param  numPacientes  - Numero total de pacientes no array pacientes.
    @param  somaCalorias  - Array para armazenar a soma de calorias para cada paciente.
    @param  dataInicial   - Data inicial do periodo.
    @param  dataFinal     - Data final do periodo.
    @retval               - Retorna SUCESSO se o calculo for bem-sucedido. Caso contrario, retorna INSUCESSO.
**/
int SomaCaloriasPeriodo(Dieta dietas[], Paciente pacientes[], int numDietas, int numPacientes, int somaCalorias[], time_t dataInicial, time_t dataFinal) {

    if (numPacientes < 0) {
        return INSUCESSO;
    }

    for (int i = 0; i < numPacientes; i++) {
        int soma = 0;
        for (int j = 0; j < numDietas; j++) {
            if (dietas[j].pacienteID == pacientes[i].pacienteID && VerificaPeriodo(dataInicial, dataFinal, dietas[j].data) == SUCESSO) {
                soma += dietas[j].cal;
            }
        }
        somaCalorias[i] = soma;
    }
    return SUCESSO;
}

/**
    @brief  Calcula e armazena as calorias consumidas fora do intervalo para cada plano de dieta.
    @param  pacientes              - Array de estruturas Paciente que contem informacoes sobre os pacientes.
    @param  dietas                 - Array de estruturas Dieta que contem informacoes sobre as dietas dos pacientes.
    @param  planos                 - Array de estruturas Plano que contem informacoes sobre os planos de dieta.
    @param  numPacientes           - Numero total de pacientes no array pacientes.
    @param  numDietas              - Numero total de dietas no array dietas.
    @param  numPlanos              - Numero total de planos no array planos.
    @param  pessoasForaIntervalo   - Array de estruturas ResFunc3 para armazenar as pessoas fora do intervalo.
    @param  numDietasForaIntervalo - Numero total de pessoas fora do intervalo (retorno por referencia).
    @param  dataInicial            - Data inicial do periodo.
    @param  dataFinal              - Data final do periodo.
    @retval                        - Retorna o numero total de pessoas fora do intervalo.
**/
int SomaCaloriasRefeicao(Paciente pacientes[], Dieta dietas[], Plano planos[], int numPacientes, int numDietas, int numPlanos, ResFunc3 pessoasForaIntervalo[], int numDietasForaIntervalo, time_t dataInicial, time_t dataFinal) {
    
    if (numPacientes < 0 || numDietas < 0 || numPlanos < 0) {
        return INSUCESSO;
    }

    int calorias;
    for (int i = 0; i < numPlanos; i++) {
        calorias = 0;
        for (int j = 0; j < numDietas; j++) {
            if (planos[i].pacienteID == dietas[j].pacienteID && planos[i].refeicao == dietas[j].refeicao
                && planos[i].data == dietas[j].data && VerificaPeriodo(dataInicial, dataFinal, planos[i].data) == SUCESSO
                && VerificaPeriodo(dataInicial, dataFinal, dietas[j].data) == SUCESSO) {
                calorias += dietas[j].cal;
            }
        }
        if (planos[i].max<calorias || planos[i].min>calorias) {
            for (int k = 0; k < numPacientes; k++) {
                if (planos[i].pacienteID == pacientes[k].pacienteID) {
                    pessoasForaIntervalo[numDietasForaIntervalo].pacienteID = pacientes[k].pacienteID;
                    strcpy(pessoasForaIntervalo[numDietasForaIntervalo].nome, pacientes[k].nome);
                    pessoasForaIntervalo[numDietasForaIntervalo].refeicao = planos[i].refeicao;
                    pessoasForaIntervalo[numDietasForaIntervalo].data = planos[i].data;
                    pessoasForaIntervalo[numDietasForaIntervalo].calConsumidas = calorias;
                    pessoasForaIntervalo[numDietasForaIntervalo].calMin = planos[i].min;
                    pessoasForaIntervalo[numDietasForaIntervalo].calMax = planos[i].max;
                    numDietasForaIntervalo++;
                }
            }
        }
    }
    return numDietasForaIntervalo;
}

/**
    @brief  Atualiza as datas de inicio e fim com base na data fornecida.
    @param  data     - Data a ser comparada com as datas de inicio e fim.
    @param  controlo - Array de estruturas ResFunc3 que contem as informacoes registadas ate ao momento.
    @param  i        - Indice no array controlo.
    @retval          - Retorna SUCESSO se a atualizacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
**/
int DataInicioDataFim(time_t data, ResFunc3 controlo[], int i) {

    if (i < 0) return INSUCESSO;

    if (controlo[i].datas.dataInicio > data) {
        controlo[i].datas.dataInicio = data;
        if (controlo[i].datas.dataFim == 0) controlo[i].datas.dataFim = data;
        return SUCESSO;
    }
    if (data > controlo[i].datas.dataFim) {
        controlo[i].datas.dataFim = data;
        if (controlo[i].datas.dataInicio == 0) controlo[i].datas.dataInicio = data;
        return SUCESSO;
    }
    else return SUCESSO;
}

/**
    @brief  Verifica se existe um registo para o paciente e refeicao fornecidos.
    @param  controlo    - Array de estruturas ResFunc3 que contem as informacoes registadas ate ao momento.
    @param  pacienteID  - Identificador do paciente a ser verificado.
    @param  refeicao    - Enumeracao Refeicao a ser verificada.
    @param  indice      - Indice atual do array controlo.
    @retval             - Retorna SUCESSO se o registo existe. Caso contrario, retorna INSUCESSO.
**/
int VerificaRegisto(ResFunc3 controlo[], int pacienteID, Refeicao refeicao, int indice) {
    for (int j = 0; j <= indice; j++) {
        if (controlo[j].pacienteID == pacienteID && controlo[j].refeicao == refeicao) return SUCESSO;
    }
    return INSUCESSO;
}

/**
    @brief  Cria um registo inicial para o paciente e refeicao fornecidos com base na dieta fornecida.
    @param  controlo    - Array de estruturas ResFunc3 que contem as informacoes registadas ate ao momento.
    @param  dietas      - Array de estruturas Dieta que contem informacoes sobre as dietas dos pacientes.
    @param  indice      - Indice atual do array controlo.
    @param  i           - Indice atual do array dietas.
    @retval             - Retorna SUCESSO se o registo for criado com sucesso. Caso contrario, retorna INSUCESSO.
**/
int CriaRegisto(ResFunc3 controlo[], Dieta dietas[], int indice, int i) {
    if (i < 0) return INSUCESSO;

    controlo[indice].pacienteID = dietas[i].pacienteID;
    controlo[indice].datas.dataInicio = dietas[i].data;
    controlo[indice].datas.dataFim = dietas[i].data;
    controlo[indice].refeicao = dietas[i].refeicao;
    controlo[indice].calConsumidas = dietas[i].cal;
    return SUCESSO;
}

/**
    @brief  Verifica se existem mais registos para a mesma refeicao do paciente fornecido.
    @param  controlo    - Array de estruturas ResFunc3 que contem informacoes de controlo.
    @param  dietas      - Array de estruturas Dieta que contem informacoes sobre as dietas dos pacientes.
    @param  i           - Indice atual do array dietas.
    @param  indice      - Indice atual do array controlo.
    @param  numDietas   - Numero total de dietas no array dietas.
    @retval             - Retorna SUCESSO se a verificacao for concluida com sucesso. Caso contrario, retorna INSUCESSO.
**/
int VerificaExisteMaisRegistosMesmaRefeicao(ResFunc3 controlo[], Dieta dietas[], int i, int indice, int numDietas) {
    if (i < 0) return INSUCESSO;
    for (int j = i + 1; j < numDietas; j++) {
        if (dietas[i].pacienteID == dietas[j].pacienteID && dietas[i].refeicao == dietas[j].refeicao) {
            controlo[indice].calConsumidas += dietas[j].cal;
            DataInicioDataFim(dietas[j].data, controlo, indice);
        }
    } return SUCESSO;
}

/**
    @brief  Guarda o nome do paciente no registo de controlo com base no ID do paciente.
    @param  controlo       - Array de estruturas ResFunc3 que contem informacoes de controlo.
    @param  pacientes      - Array de estruturas Paciente que contem informacoes sobre os pacientes.
    @param  numPacientes   - Numero total de pacientes no array pacientes.
    @param  indice         - Indice atual do array controlo.
    @retval                - Retorna SUCESSO se o nome for guardado com sucesso. Caso contrario, retorna INSUCESSO.
**/
int GuardaNomePaciente(ResFunc3 controlo[], Paciente pacientes[], int numPacientes, int indice) {
    if (indice < 0) return INSUCESSO;
    for (int k = 0; k < numPacientes; k++) {
        if (controlo[indice].pacienteID == pacientes[k].pacienteID) {
            strcpy(controlo[indice].nome, pacientes[k].nome);
            break;
        }
    } return SUCESSO;
}

/**
    @brief  Soma os limites de calorias no registo de controlo com base no ID do paciente e refeicao.
    @param  controlo       - Array de estruturas ResFunc3 que contem informacoes de controlo.
    @param  planos         - Array de estruturas Plano que contem informacoes sobre os planos de dieta.
    @param  indice         - Indice atual do array controlo.
    @param  numPlanos      - Numero total de planos no array planos.
    @retval                - Retorna SUCESSO se os limites de calorias forem somados com sucesso. Caso contrario, retorna INSUCESSO.
**/
int SomaLimitesCalorias(ResFunc3 controlo[], Plano planos[], int indice, int numPlanos) {
    if (indice < 0) return INSUCESSO;
    for (int h = 0; h < numPlanos; h++) {
        if (controlo[indice].pacienteID == planos[h].pacienteID && controlo[indice].refeicao == planos[h].refeicao) {
            controlo[indice].calMin += planos[h].min;
            controlo[indice].calMax += planos[h].max;
        }
    }return SUCESSO;
}
    