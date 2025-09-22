/**
    @file      Media.c
    @brief     Funcao media utilizada na lib
    @author    Diogo Machado (26042), Jose Alves (27967), Paulo Melo (29575)
    @date      30.12.2023
**/

/**
    @brief  Calcula a media a partir da soma total e do contador.
    @param  soma      - Soma total dos valores.
    @param  contador  - Contador do numero de valores.
    @retval           - Retorna a media calculada como um valor decimal (float).
**/
float CalculaMedia(int soma, int contador) {
    return (float)soma / contador;
}