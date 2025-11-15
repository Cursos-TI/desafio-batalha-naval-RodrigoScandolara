#include <stdio.h>


int main(){

    int index1;
    int index2; 
    
    //Declaração do vetor de tipo char para o a coluna j do jogo
    char letras[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    //Declaração da Matriz contendo o tabuleiro do jogo
    int tabuleiro[10][10] = {

        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

    };

    printf("\n## JOGO DE BATALHA NAVAL! ##\n");
    printf("\n");
    printf("   "); //3 espaços para alinhar a linha com os títulos das colunas com cada coluna

    //Loop para exibir os títulos das colunas
    for (int colunas = 0; colunas < 10; colunas++){
        printf("%c ", letras[colunas]);

    }

    printf("\n");


    //Declaração dos vetores dos navios e áreas de habilidade
    int navio1[] = {3, 3, 3};
    int navio2[] = {3, 3, 3, 3, 3};
    int navio3[] = {3, 3, 3};
    int navio4[] = {3, 3, 3, 3};

    int cone[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    int cruz[] = {1, 1, 1, 1, 1};
    int octaedro[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};


    index1 = 2; //Index para fixar a linha do navio 1
    int j = 4; //Variável "coluna" para navio 1
    
    index2 = 8; //Index para fixar a coluna do navio 2
    int i = 3; //Variável "linha" para navio 2
    
    
    //Exibição área Cone
    for (int x = 0; x < 9; x++){
        for (int i = 6; i < 9; i++){
            for (int j = 0; j < 5; j++){
                
                int distancia = i - 6;
                int jInicio = 2 - distancia;
                int jFinal = 2 + distancia;
                
                for (int j = jInicio; j <= jFinal; j++){
                   tabuleiro [i][j] = cone[x];
                  
                }
            
            }
        }
    }

    //Exibição área Cruz
    int x = 0;
    for (int i = 1; i < 4; i++){
        for (int j = 0; j < 3; j++){
               
            if (i == 2){
                tabuleiro [i][j] = cruz[x];
                x++;

                }else if (i == 1 || i == 3){
                    if (j == 1){
                    tabuleiro [i][j] = cruz[x];
                    x++;
                    
                }
            }
        }
    }

    //Exibição do octaedro
    for (int x = 0; x < 13; x++){
        for (int i = 1; i < 6; i++){
            for (int j = 5; j < 10; j++){

                int colunaCentro = 7;
                int linhaCentro = 3;
                int largura;

                if (i == 1 || i == 5){
                    largura = 0;
                }else if (i == 2 || i == 4){
                    largura = 1;
                }else{
                    largura = 2;
                }

                if (j >= (colunaCentro - largura) && j <= (colunaCentro + largura)){
                    tabuleiro [i][j] = octaedro[x];
                }

            }
            
        }
    }

    //Loop para posicionar os navios 1 e 2
    for (int x = 0; x < 3; x++){
    
        tabuleiro[index1][j + x] = navio1[x];
        
    }

    for (int x = 0; x < 5; x++){
        tabuleiro[i + x][index2] = navio2[x];
        
    }

    //Loops aninahdos para navios 3 e 4
    for (int x = 0; x < 3; x++){
        for (int i = 6; i < 9; i++){
            for (int j = 0; j < 3; j++){
                if ((i - j) == 6){
                    tabuleiro[i][j] = navio3[x];
                
                    
                }
            }
        }
    }

    for (int x = 0; x < 4; x++){
        for (int i = 3; i >= 0; i--){
            for (int j = 0; j < 4; j++){
                if ((j + i) == 3){
                    
                    tabuleiro[i][j] = navio4[x];
                
                }
            }
        }
    }

        //Loop para exibir a numeração das linhas no tabuleiro
        for (int i = 0; i < 10; i++){
            printf("%2d", i + 1); // "%2d" para que os números seja exibidos com duas casas, fazendo com que a linha 10 fique alinhada

            //Loop interno para a exibição do tabuleiro contendo somente água.
            for (int j = 0; j < 10; j++){
                printf(" %d", tabuleiro[i][j]);

             
                }
                printf("\n"); //Para que se pule linhas e não se imprima tudo em seguida
            }

        printf("\n");

return 0;

    }

