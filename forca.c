#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "color.h"

void Texto_Jogo_da_Forca(){
    system("mode con:cols=80 lines=25"); // Define o tamanho da tela

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    Colorgreen();

    printf("%*s\n", columns / 2 + strlen("=-=-=-=-=-=-=-=-= JOGO DA FORCA =-=-=-=-=-=-=-=-=-=") / 2, "=-=-=-=-=-=-=-=-= JOGO DA FORCA =-=-=-=-=-=-=-=-=-=\n");
}

void game(char word[100], char letra, char word_hidden[100]){
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] == letra)
        {
            word_hidden[i] = letra;
        } 
    }
}

void desenhar_forca(int tentativas) {
    printf("_________________\n");
    if (tentativas < 7) printf("|                 |\n");
    else printf("|/                |\n");
    if (tentativas < 6) printf("|                 0\n");
    if (tentativas == 5) printf("|                 |\n");
    else if (tentativas == 4) printf("|                /|\n");
    else if (tentativas <= 3) printf("|                /|\\\n");
    if (tentativas == 2) printf("|                / \n");
    else if (tentativas <= 1) printf("|                / \\\n");
    else if (tentativas <= 0) printf("|                / |");
    printf("\n|\n");
    printf("|_________________|\n");
}

int resposta(){
    Texto_Jogo_da_Forca();
    Colorwhite();
    
    printf("Voce gostaria de continuar jogando?\n1) SIM\n2) NAO\n");
    int resposta;
    scanf("%d", &resposta);

    if (resposta == 1)
    {
            return 1;
    }
    return 0;     
}

int main(){

        char word[100];
        char name_player1[10];
        char name_player2[10];
        char word_hidden[100];
        int tentativas = 6;
        char letras[50];
        int contador = 0;
        int tamanho = 0;
        char zerarletras[100];
        char dica[100];

    do {
        Texto_Jogo_da_Forca();
        memset(letras, 0, sizeof(letras));

        Colorred();
        printf("Player 1, digite seu nome: ");
        scanf("%s", name_player1);

        Colorverdeagua();
        printf("\nPlayer 2, digite seu nome: ");
        scanf("%s", name_player2);

        system("cls"); 
    
        Texto_Jogo_da_Forca();
    
        Colorred();
        printf("%s", name_player1);
        Colorwhite();
        printf(", escolha uma palavra para o jogo (Apenas em minusculo): ");
        Colorred();
        scanf("%s", word);
        Colorwhite();

        Colorazul();
        printf("%s", name_player1);
        Colorwhite();
        printf(", digite uma dica: ");
        Colorazul();
        scanf("%s", dica);

        for (int i = 0; i < strlen(word); i++) {
            word_hidden[i] = '_';
        }

        system("cls"); 
        char letra;

        desenhar_forca(tentativas);

        do {
            Texto_Jogo_da_Forca();
            Colorrosa();
            desenhar_forca(tentativas);

            printf("Dica: %s\n", dica);
            printf("A palavra tem %d letras.\n\n", strlen(word));

            if(tamanho != 0){
                printf("Letras: ");
                for (int i = 0; i < tamanho; i++)
            {
                printf("%c ", letras[i]);
            }
                printf("\n\n");
            }
                tamanho++;

            for (int i = 0; i < strlen(word); i++) {
                printf("%c ", word_hidden[i]);
            }

            printf("\n\n");

            Colorverdeagua();
            printf("%s", name_player2);
            Colorwhite();
            printf(", digite uma letra (%d tentativas restantes):", tentativas);
            Colorverdeagua();
            scanf(" %c", &letra);

            letras[contador] = letra;
            contador++;

            if (strchr(word, letra) == NULL) {
                tentativas--;
            } else {
                game(word, letra, word_hidden);
            }

        } while (strcmp(word, word_hidden) != 0 && strchr(word_hidden, '_') != NULL && tentativas != 0);


        Texto_Jogo_da_Forca();

        if (tentativas == 0) {
            Colorred();
            printf("\nQue pena %s! Voce perdeu!\n\n", name_player2);
            Colorwhite();
            printf("A palavra correta era: %s", word);
            tentativas = 6;
        }
        else {
            Colorverdeclaro();
            printf("\nParabens %s! Voce venceu!\n\n", name_player2); 
            Colorwhite();
            printf("A palavra correta era: %s", word);
            tentativas = 6;
        }
        
        system("pause>nul");
        system("cls");

        Texto_Jogo_da_Forca();
        Colorwhite();
        printf("A palavra era: %s\n", word);

        system ("cls");

    } while (resposta());

        system("pause>nul");
}     