#include "Estoque.h"
typedef struct produto
{
  char nome[50];
  char pais[50];
  int qtd_itens;
  char codigo[10];
} produto;

int main(void)
{
  struct produto p[999];
  int opcao, opcaoatt, qtdprod = 0, i = 0, novo_item, n, compcod = 0,exclusao=0;
  char verifprod[8], novo_nome, novo_pais;
  do
  {
    imprimeMenu();
    printf("\nSelecione a opção desejada: ");
    scanf("%i", &opcao);
    getchar();
    if (opcao == 1)
    {
      if (qtdprod-exclusao < 20)
      {
        puts("\nQual o nome do Produto? ");
        scanf(" %[^\n]s", p[i].nome);
        //fgets(p[i].nome, 50, stdin);
        puts("Qual o País de Origem? ");
        scanf(" %[^\n]s", p[i].pais);
        //fgets(p[i].pais, 50, stdin);
        puts("Quantos itens deste produto? ");
        scanf("%i", &p[i].qtd_itens);
        getchar();
        geracodigo(p[i].pais, i, (p[i].codigo));
        qtdprod++;
        i++;
      }
      else
      {
        puts("Não é possível adicionar mais produtos no estoque");
      }
      
    }
    else if (opcao == 2)
    {
      puts("Digite o código do produto: ");
      scanf(" %[^\n]s", verifprod);

      for (int m = qtdprod - 1; m >= 0; m--)
      {
        if (strcmp(verifprod, p[m].codigo) == 0)
        {
          puts("\nAtualizar informações de um produto:\n\n 1 - Alterar nome;\n 2 - Alterar País de origem;\n 3 - Adicionar mais itens;");
          scanf("%i", &opcaoatt);
          if (opcaoatt == 1)
          {
            puts("\nQual o novo nome?");
            scanf(" %[^\n]s", &novo_nome);
            strcpy(p[m].nome, &novo_nome);
          }
          else if (opcaoatt == 2)
          {
            puts("\nQual o novo país?");
            scanf(" %[^\n]s", &novo_pais);
            strcpy(p[m].pais, &novo_pais);
            geracodigo(p[m].pais, m, p[m].codigo);
          }
          else if (opcaoatt == 3)
          {
            puts("\nQuantos itens para adicionar?");
            scanf("%i", &novo_item);
            p[m].qtd_itens += novo_item;
          }
          compcod++;
          break;
        }
      }
      if (compcod == 0)
      {
        puts("Código inválido!");
      }
      compcod = 0;
    }
    else if (opcao == 3)
    {
      puts("\nDigite o código do produto: ");
      scanf(" %[^\n]s", verifprod);
      for (int m = qtdprod - 1; m >= 0; m--)
      {
        if (strcmp(verifprod, p[m].codigo) == 0)
        {
          puts("\nQuantos itens para vender?");
          scanf("%i", &novo_item);
          if (novo_item < 0)
          {
            puts("Não foi possível vender essa quantidade");
          }
          else if(novo_item > p[m].qtd_itens){
            puts("Não existem itens suficientes para este produto");
          }
          else if (novo_item - p[m].qtd_itens == 0)
          {
            for (n = m + 1; n <= qtdprod; n++)
            {
              p[n - 1] = p[n];
              
            }
            exclusao++;
          }
          else
          {
            p[m].qtd_itens += -novo_item;
          }
          compcod++;
          break;
        }
      }
      if (compcod == 0)
      {
        puts("Código inválido!");
      }
    }
    else if(opcao==4){
      puts("Digite o código do produto: ");
      scanf(" %[^\n]s", verifprod);
      for(int m=qtdprod-1;m>=0;m--){
        if(strcmp(verifprod, p[m].codigo)==0){
          printf("Nome do Produto: %s\n", p[m].nome);
          printf("Pais de Origem: %s\n", p[m].pais);
          printf("Quantidade de Itens: %i\n", p[m].qtd_itens);
          printf("Codigo: %s\n", p[m].codigo);
          compcod++;
          break;
        }
      }if(compcod==0){
        puts("Código inválido!");
      }
      compcod=0;
    }else if(opcao==5){
      for(int j=0; j<qtdprod; j++){
        if(strlen(p[j].codigo)==8)
        printf("%s\t%i\n", p[j].codigo, p[j].qtd_itens);
      }

    }
  } while (opcao != 6);

  return 0;
}