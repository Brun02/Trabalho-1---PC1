#include "Estoque.h"

void imprimeMenu(){
 puts("\n+----------------------------------------------------+\n|   CONTROLE DE ESTOQUE ALI-IFB                      |\n|                                                    |\n|   1 - Cadastrar novo produto;                      |\n|   2 - Atualizar informações de um produto;         |\n|   3 - Vender produto;                              |\n|   4 - Consultar informações de um produto;         |\n|   5 - Consultar quantidade de todos os produtos;   |\n|   6 - Finalizar Programa;                          |\n+----------------------------------------------------+");
}

void geracodigo(char* pais, int valor, char* codigo){
    char num[3];
    sprintf(num, "%d", valor);
    for(int i=0; i<8; i++){
        if(i<2){
            codigo[i]= toupper(pais[i]);
        }

        else if(i==2){
            
            strcat(codigo, "IFB");
            i=4;
        }
        else{
            if(valor>99){
              strcat(codigo, num);
              codigo[8] = '\0';
              break;
            }
            else if(valor>9){
                strcat(codigo, "0");
                strcat(codigo, num);
                codigo[8] = '\0';
                break;
            }
            else{
                strcat(codigo, "00");
                strcat(codigo, num);
                codigo[8] = '\0';
                break;
            }
        }

    }
}