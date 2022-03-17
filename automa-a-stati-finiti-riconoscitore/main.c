/*

  Implementszione in c di un automa deterministico a stati finiti
  che riconosce parole con un numero pari di lettere "a" e un
  numero dispari di "b"

  Spicoli Piersilvio - Uniba computer science

*/

#include <stdio.h>
#include <stdlib.h>
#define max 100

//prototipo di riconoscitore dell'automa
int m_automa(char*);

int m_automa(char* stringa)
{
    //var. locali
    enum{q0, q1, q2, q3, pozza} stato = q0; //definizione degli stati di transizione
    int i = 0;

    //algoritmo dell'automa
    while((stringa[i] != '\0' && stringa[i] != '\n') && stato != pozza)
    {
        switch(stato)
        {
        case q0:

            if(stringa[i] == 'a')
            {
                stato = q3;
            }
            else if(stringa[i] == 'b')
            {
                stato = q1;
            }
            else
            {
                stato = pozza;
            }

         break;
         case q1:

            if(stringa[i] == 'a')
            {
                stato = q2;
            }
            else if(stringa[i] == 'b')
            {
                stato = q0;
            }
            else
            {
                stato = pozza;
            }

         break;
         case q2:

            if(stringa[i] == 'a')
            {
                stato = q1;
            }
            else if(stringa[i] == 'b')
            {
                stato = q3;
            }
            else
            {
                stato = pozza;
            }

         break;
         case q3:

            if(stringa[i] == 'a')
            {
                stato = q0;
            }
            else if(stringa[i] == 'b')
            {
                stato = q2;
            }
            else
            {
                stato = pozza;
            }

         break;
        }
        ++i;
    }

    if(stato == q1)
        return !0;
    else
        return 0;
}

int main()
{
    //var. locali
    char input[max + 1];
    FILE* file;

    file = fopen("test_automa.txt", "r");
    if(file == NULL)
    {
         puts("\tImpossibile aprire il file!\n");
    }
    else
    {
        puts("\n\tImplementazione in C di un automa deterministico a stati finiti");
        puts("\tche riconosce parole con un numero pari di lettere a e un");
        puts("\tnumero dispari di b\n");

        while(!feof(file))
        {
            if(fgets(input, max, file))
            {
                if(m_automa(input))
                {
                    printf("\tstringa riconosciuta! _> %s\n", input);
                }
                else
                {
                    printf("\tstringa non riconosciuta! _> %s \n", input);
                }
            }
        }
    }

    fclose(file);

    puts("\n");
    system("pause");
    return 0;
}
