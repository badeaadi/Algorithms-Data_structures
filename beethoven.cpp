/* Programa: beethoven.c
   Autor: thiagoamm
   Data: 23/03/06 */

/* Bibliotecas internas */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* Pausas */
#define breve 8000
#define semibreve 4000
#define minima 2000
#define seminima 1000
#define colcheia 500
#define semicolcheia 250
#define fusa 125
#define semifusa 62.5


/* Frequencia das notas */
#define DO 261
#define RE 294
#define MI 326
#define FA 348
#define SOL 391
#define LA 435
#define SI 489
#define Do  522

/* Funcao principal */
int main(void)
{
  int i;

  for (i = 0; i <= 1000; i++)
  {
    /* Primeira parte */
    Beep(MI,colcheia);Beep(MI,colcheia);Beep(FA,colcheia);
    Beep(SOL,colcheia);Beep(SOL,colcheia);Beep(FA,colcheia);
    Beep(MI,colcheia);Beep(RE,colcheia);Beep(DO,colcheia);
    Beep(DO,colcheia);Beep(RE,colcheia);Beep(MI,colcheia);
    Beep(MI,700);Beep(RE,semicolcheia);Beep(RE,seminima);

    /* Pausa */
    Beep(0,semibreve);

    /* Segunda parte */
    Beep(MI,colcheia);Beep(MI,colcheia);Beep(FA,colcheia);
    Beep(SOL,colcheia);Beep(SOL,colcheia);Beep(FA,colcheia);
    Beep(MI,colcheia);Beep(RE,colcheia);Beep(DO,colcheia);
    Beep(DO,colcheia);Beep(RE,colcheia);Beep(MI,colcheia);
    Beep(RE,600);Beep(RE,300);Beep(DO,350);Beep(DO,600);

    /* Pausa */
    Beep(0,semibreve);

    /* Terceira parte */
    Beep(RE,colcheia);Beep(RE,colcheia);Beep(MI,colcheia);Beep(DO,colcheia);
    Beep(RE,colcheia);Beep(FA,colcheia);Beep(MI,colcheia);Beep(DO,colcheia);
    Beep(RE,colcheia);Beep(FA,colcheia);Beep(MI,colcheia);Beep(DO,colcheia);
    Beep(RE,colcheia);Beep(SOL,500);Beep(SOL,900);

    /* Pausa */
    Beep(0,semibreve);

    /* BIS --> Seguna parte */
    Beep(MI,colcheia);Beep(MI,colcheia);Beep(FA,colcheia);
    Beep(SOL,colcheia);Beep(SOL,colcheia);Beep(FA,colcheia);
    Beep(MI,colcheia);Beep(RE,colcheia);Beep(DO,colcheia);
    Beep(DO,colcheia);Beep(RE,colcheia);Beep(MI,colcheia);
    Beep(RE,600);Beep(RE,300);Beep(DO,350);Beep(DO,600);

    /* Pausa */
    Beep(0,breve);
  }
  return(0);
}
