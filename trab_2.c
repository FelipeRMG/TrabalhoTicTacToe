/*
Autor:Felipe da Rocha Moralles Guterres
RGM:023401
Graduando em Ciência da Computação UEMS- Universidade Estadual de Mato Grosso do Sul
última modificação:22/06/13
Descrição: Criar um jogo da velha (Tic-Tac-Toe)
*/
#include<stdio.h>
#define TAM 3//Matriz do jogo de tamanho 3X3
void inicializa(char x[][TAM])//função para inicializar a matriz em cada posição irá ter um ponto (".")
{
    int i,j;
    for(i=0 ; i<TAM ; i++)
    {
        for(j=0 ; j<TAM ; j++)
            x[i][j]='.';

        printf("\n");
    }

    for(i=0 ; i<TAM ; i++)//loop que faz a modelagem (divisão das posições) com caracteres hexadecimais
    {
        printf(" %c \xBA %c \xBA %c\n",x[i][0],x[i][1],x[i][2]);
        if(i<3-1)
            printf("ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");//quadro com  caracteres da modelagem
    }
}//fim função inicializa

void imprimi(char x[][TAM])//função imprimi a matriz a cada jogada dos usuários
{
    int i,j;
    for(i=0 ; i<TAM ; i++)
    {
        printf(" %c \xBA %c \xBA %c\n",x[i][0],x[i][1],x[i][2]);//modelagem da divisão dos caracteres
        if(i<3-1)
            printf("ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");//modelagem da divisão dos caracteres
    }
}//fim função imprimi

void jogada(int y , char x[][TAM] , char ch)//função da jogada
{
    int line,column;
    do
    {
        printf("\n%d-Jogador\n",y);//pede para o usuário as coordenadas da jogada do usuário
        printf("Digite a Linha:  ");//linha da coordenada
        scanf("%d",&line);
        printf("Digite a Coluna: ");//Coluna da coordenada
        scanf("%d",&column);
    }
    while(line>3 || line<1 || column>3 || column<1);//esse loop é para obrigar o usuário a fornecer uma posição válida

    if(x[line-1][column-1]!='.')//se o usuário informar uma jogada que já foi realizada...
        while(x[line-1][column-1]!='.')//...entrará nesse loop até informar uma coordenada válida
        {
            printf("\n\nERROR 503 - SERVICE UNAVAILABLE\n\n");
            printf("\nDigite Novamente a jogada\n");
            printf("Jogador %d\n",y);
            printf("Digite a Linha:  ");
            scanf("%d",&line);
            printf("Digite a Coluna: ");
            scanf("%d",&column);
        }
    if(x[line-1][column-1]=='.')//quando o usuário informar uma coordenada válida
        x[line-1][column-1]=ch;
}//fim função jogada

int verifica(int y,char x[][TAM],int w)//função de verificar se houve ganhador, ou o jogo acabou empatado
{
    int i,vdd=0;//vdd será um variavel, que se entrar em uma verificação mandará um valor para dar um Break na main
    for(i=0 ; i<TAM ; i++)
    {
        if(x[i][0]==x[i][1] && x[i][1]==x[i][2]&&x[i][0]!='.')//verifica as linhas
        {
            printf("jogador %d VENCEU!",y);
            vdd=1;
        }
    }

    for(i=0 ; i<TAM ; i++)
    {
        if(x[0][i]==x[1][i] && x[1][i]==x[2][i] && x[0][i]!='.')//verifica as colunas
        {
            printf("jogador %d VENCEU!",y);
            vdd=1;
        }
    }
    if(x[0][0]==x[1][1]&&x[1][1]==x[2][2]&&x[1][1]!='.')//verifica diagonal principal
    {
        printf("jogador %d VENCEU!",y);
        vdd=1;
    }
    if(x[2][0]==x[1][1]&&x[1][1]==x[0][2]&&x[1][1]!='.')//verifica diagonal sencundaria
    {
        printf("jogador %d VENCEU!",y);
        vdd=1;

    }
    if(w==9 && vdd==0)//verifica se houve empate
        printf("Jogo Empatado!");

    return vdd;
}

int main()
{
    char old[TAM][TAM];
    int  i=1;
    inicializa(old);
    printf("\n");
    while(i<=9)//cada loop seria uma jogada, como no máximo são 9 jogadas terá 9 interações
    {
        if(i%2)//primeiro jogador jogará com ("X")
        {
            jogada(1,old,'X');//chama  função jogada passando o numero e o caracter do jogador, e a matriz
            printf("\n");
            imprimi(old);//imprimi a matriz apos a jogada
            if(verifica(1,old,i))//verfica se houver ganhador o programa para
                break;
        }
        else//segundo jogado jogará com ("O")
        {
            jogada(2,old,'O');//chama  função jogada passando o numero e o caracter do jogador, e a matriz
            printf("\n");
            imprimi(old);//imprimi a matriz apos a jogada
            if(verifica(2,old,i))//verfica se houver ganhador o programa para
                break;
        }
        i++;//controlador das jogadas
    }
    return 0 ;
}
