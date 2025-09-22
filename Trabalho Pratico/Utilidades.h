/**
    @file      Utilidades.h
    @brief     Cabecalhos das funcoes auxiliares as funcoes principais do programa
    @author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
    @date      30.12.2023
**/
#pragma once
#include "Pacientes.h"
#include <time.h>

/**
    @brief  Converte uma string de data no formato "dia-mes-ano" para um valor do tipo time_t.
    @param  dataTemp - String contendo a data no formato "dia-mes-ano".
    @retval           - Retorna o valor do tipo time_t correspondente a data convertida
                      se a conversao for bem-sucedida, senao, retorna um codigo de erro.
**/
int ConverteData(char dataTemp[]);
/**
    @brief  Converte um valor do tipo time_t para uma string no formato "dia-mes-ano".
    @param  data             - Valor do tipo time_t a ser convertido.
    @param  dataConvertida   - String para armazenar a data convertida.
    @retval                  - Retorna DATA_CONVERTIDA_COM_SUCESSO se a conversao for bem-sucedida.
                              Se a conversao falhar, retorna um codigo de erro.
**/
int ConverteDataVolta(time_t data, char dataConvertida[]);
/**
    @brief  Converte uma string que representa uma refeicao para o valor correspondente da enumeração RefeicaoEnum.
    @param  refeicaoTemp - String que contem a representacao da refeicao.
    @retval              - Retorna o valor correspondente da enumeracao RefeicaoEnum.
                          Se a string nao corresponder a nenhuma refeicao, retorna INSUCESSO.
**/
int DefineRefeicaoEnum(char refeicaotemp[]);
/**
    @brief  Ordena um array de pacientes em ordem decrescente com base no identificador do paciente.
    @param  pacientes - Array de estruturas Paciente a ser ordenado.
    @param  n         - Numero de elementos no array.
    @retval            - Retorna SUCESSO se a ordenacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
**/
int OrdenaOrdemDecrescentePacientes(Paciente pacientes[], int n);
/**
    @brief  Ordena um array de estruturas ResFunc3 em ordem decrescente com base no identificador do paciente.
    @param  dietas - Array de estruturas ResFunc3 a ser ordenado.
    @param  n      - Numero de elementos no array.
    @retval         - Retorna SUCESSO se a ordenacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
**/
int OrdenaOrdemDecrescentePessoasForaIntervalo(ResFunc3 dietas[], int n);
/**
    @brief  Verifica se uma data esta dentro de um determinado periodo.
    @param  dataInicial - Data inicial do periodo.
    @param  dataFinal   - Data final do periodo.
    @param  data        - Data a ser verificada.
    @retval             - Retorna SUCESSO se a data estiver dentro do periodo. Caso contrario, retorna INSUCESSO.
**/
int VerificaPeriodo(time_t dataInicial, time_t dataFinal, time_t data);
/**
    @brief  Converte um valor da enumeracao Refeicao para uma string correspondente.
    @param  refeicao           - Valor da enumeracao Refeicao a ser convertido.
    @param  refeicaoConvertida - String para armazenar a refeicao convertida.
    @retval                    - Retorna SUCESSO se a conversao for bem-sucedida. Caso contrario, retorna INSUCESSO.
**/
int ConverteRefeicaoString(Refeicao refeicao, char refeicaoConvertida[]);
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
int SomaCaloriasPeriodo(Dieta dietas[], Paciente pacientes[], int numDietas, int numPacientes, int somaCalorias[], time_t dataInicial, time_t dataFinal);
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
int SomaCaloriasRefeicao(Paciente pacientes[], Dieta dietas[], Plano planos[], int numPacientes, int numDietas, int numPlanos, ResFunc3 pessoasForaIntervalo[], int numDietasForaIntervalo, time_t dataInicial, time_t dataFinal);
/**
    @brief  Atualiza as datas de inicio e fim com base na data fornecida.
    @param  data     - Data a ser comparada com as datas de inicio e fim.
    @param  controlo - Array de estruturas ResFunc3 que contem as informacoes registadas ate ao momento.
    @param  i        - Indice no array controlo.
    @retval          - Retorna SUCESSO se a atualizacao for bem-sucedida. Caso contrario, retorna INSUCESSO.
**/
int DataInicioDataFim(time_t data, ResFunc3 controlo[], int i);
/**
    @brief  Verifica se existe um registo para o paciente e refeicao fornecidos.
    @param  controlo    - Array de estruturas ResFunc3 que contem as informacoes registadas ate ao momento.
    @param  pacienteID  - Identificador do paciente a ser verificado.
    @param  refeicao    - Enumeracao Refeicao a ser verificada.
    @param  indice      - Indice atual do array controlo.
    @retval             - Retorna SUCESSO se o registo existe. Caso contrario, retorna INSUCESSO.
**/
int VerificaRegisto(ResFunc3 controlo[], int pacienteID, Refeicao refeicao, int indice);
/**
    @brief  Cria um registo inicial para o paciente e refeicao fornecidos com base na dieta fornecida.
    @param  controlo    - Array de estruturas ResFunc3 que contem as informacoes registadas ate ao momento.
    @param  dietas      - Array de estruturas Dieta que contem informacoes sobre as dietas dos pacientes.
    @param  indice      - Indice atual do array controlo.
    @param  i           - Indice atual do array dietas.
    @retval             - Retorna SUCESSO se o registo for criado com sucesso. Caso contrario, retorna INSUCESSO.
**/
int CriaRegisto(ResFunc3 controlo[], Dieta dietas[], int indice, int i);
/**
    @brief  Verifica se existem mais registos para a mesma refeicao do paciente fornecido.
    @param  controlo    - Array de estruturas ResFunc3 que contem informacoes de controlo.
    @param  dietas      - Array de estruturas Dieta que contem informacoes sobre as dietas dos pacientes.
    @param  i           - Indice atual do array dietas.
    @param  indice      - Indice atual do array controlo.
    @param  numDietas   - Numero total de dietas no array dietas.
    @retval             - Retorna SUCESSO se a verificacao for concluida com sucesso. Caso contrario, retorna INSUCESSO.
**/
int VerificaExisteMaisRegistosMesmaRefeicao(ResFunc3 controlo[], Dieta dietas[], int i, int indice, int numDietas);
/**
    @brief  Guarda o nome do paciente no registo de controlo com base no ID do paciente.
    @param  controlo       - Array de estruturas ResFunc3 que contem informacoes de controlo.
    @param  pacientes      - Array de estruturas Paciente que contem informacoes sobre os pacientes.
    @param  numPacientes   - Numero total de pacientes no array pacientes.
    @param  indice         - Indice atual do array controlo.
    @retval                - Retorna SUCESSO se o nome for guardado com sucesso. Caso contrario, retorna INSUCESSO.
**/
int GuardaNomePaciente(ResFunc3 controlo[], Paciente pacientes[], int numPacientes, int indice);
/**
    @brief  Soma os limites de calorias no registo de controlo com base no ID do paciente e refeicao.
    @param  controlo       - Array de estruturas ResFunc3 que contem informacoes de controlo.
    @param  planos         - Array de estruturas Plano que contem informacoes sobre os planos de dieta.
    @param  indice         - Indice atual do array controlo.
    @param  numPlanos      - Numero total de planos no array planos.
    @retval                - Retorna SUCESSO se os limites de calorias forem somados com sucesso. Caso contrario, retorna INSUCESSO.
**/
int SomaLimitesCalorias(ResFunc3 controlo[], Plano planos[], int indice, int numPlanos);