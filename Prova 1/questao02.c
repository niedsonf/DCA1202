#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//Pra ficar bonitinho ;D
#define BLUE(string) "\x1b[34m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

//Printa todas as camadas da matriz tridimensional
void printArray(char ***a, int nx, int ny, int nz)
{
  printf("\n");
  for (int k = 0; k < nz; k++)
  {
    for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < ny; j++)
      {
        if (a[k][i][j] == 1)
        {

          printf(RED("%d "), a[k][i][j]);
        }
        else
        {
          printf(BLUE("%d "), a[k][i][j]);
        }
      }
      printf("\n");
    }
    printf("\n\n\n");
  }
}

//Printa a camada desejado pelo usuário
void printLayer(char ***a, int nx, int ny, int layer)
{
  printf("\n");
  
    for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < ny; j++)
      {
        if (a[layer][i][j] == 1)
        {

          printf(RED("%d "), a[layer][i][j]);
        }
        else
        {
          printf(BLUE("%d "), a[layer][i][j]);
        }
      }
      printf("\n");
    }
    printf("\n\n\n");
}

//Preenche o array com a ellipse, 1 para pontos contidos na ellipe e 0 para área externa não pertencente a ellipse
void fillArray(char ***a, int nx, int ny, int nz)
{
  //Define o raio da ellipse e seu centro
  int rx = nx / 2, ry = ny / 2, rz = nz / 2;
  int cx = ceil(nx / 2), cy = ceil(ny / 2), cz = ceil(nz / 2);
  //Percorre elemento a elemento e verifica se está contida na ellipse
  for (int z = 0; z < nz; z++)
  {
    for (int x = 0; x < nx; x++)
    {
      for (int y = 0; y < ny; y++)
      {
        float point = pow(((float)(z - cz) / rz), 2) +
                      pow(((float)(x - cx) / rx), 2) +
                      pow(((float)(y - cy) / ry), 2);
        if (point <= 1)
        {
          a[z][x][y] = 1;
        }
        else
        {
          a[z][x][y] = 0;
        }
      }
    }
  }
}

int main()
{
  int nx, ny, nz, layer;
  char ***a;

  printf("\nInsira o tamanho X da matriz:\n");
  scanf("%d", &nx);
  printf("Insira o tamanho Y da matriz:\n");
  scanf("%d", &ny);
  printf("Insira o tamanho Z da matriz:\n");
  scanf("%d", &nz);
  printf("Insira a camada a ser printada:\n");
  scanf("%d", &layer);

  //Alocação dos dois blocos auxiliares e do tamanho necessário para os elementos da matriz
  a = malloc(nz * sizeof(char **));
  a[0] = malloc(nz * nx * sizeof(char *));
  a[0][0] = malloc(nz * nx * ny * sizeof(char));

  //Redefine o endereçamento do primeiro bloco auxiliar, tomando como referência o elemento anterior e somando o número de linhas de cada camada da matriz
  for (int i = 1; i < nz; i++)
  {
    a[i] = a[i - 1] + nx;
  }

  //Redefine o endereçamento do segundo bloco auxiliar, tomando como referência o elemento anterior e somando o número de elementos de cada linha
  //O total de linhas vai ser o número de linhas de cada matriz bidimensional vezes a quantidade de camadas
  for (int j = 1; j < nx * nz; j++)
  {
    a[0][j] = a[0][j - 1] + ny;
  }

  //Preenche o array com a ellipse
  fillArray(a, nx, ny, nz);
  //Printa TODAS as camadas da matriz, vai ficar comentado pra facilitar a correção do prof :3
  //printArray(a, nx, ny, nz);
  printLayer(a, nx, ny, layer);

  //Liberação da memória alocada
  free(a[0][0]);
  free(a[0]);
  free(a);

  return 0;
}
