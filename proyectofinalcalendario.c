#include <stdio.h>
#include <time.h>

int main()
{

    int dia, mes, anio, diaDeSemana;
    int febrero;
    int diasTotalesdelmes;
    int moduloMes;
    int elige = 0;

    time_t sisTime;
    struct tm *tiempo;
    time(&sisTime); //time obtiene el tiempo del sistema y se lo pasa a la direccion de sisTime.
    tiempo = localtime(&sisTime);
    //Convierte los valores de sisTime a compatibles con la estructura tm y luego asigno ese valor a tiempo.

imprime_calendario:
    printf("\tººººººººººººººººººººººººººººººCALENDARIOºººººººººººººººººººººººººººººº\n\n");
    if (elige == 0)
    {
        dia = tiempo->tm_mday;
        mes = (tiempo->tm_mon);
        anio = (tiempo->tm_year) + 1900;
        printf("Hoy es: ");
    }
    else
    {
        elige = 0;
        printf("La fecha es: ");
    }

    printf("%d/%d/%d \n\n\n", dia, mes + 1, anio);

    // Identifica si el anio corresponde a un anio bisiesto o no
    if ((anio % 4 == 0) && (anio % 100 != 0) || anio % 400 == 0)
    {
        febrero = 29;
    }
    else
    {
        febrero = 28;
    }

    switch (mes)
    {
    case 0:
        printf("\t\tENERO\t%d", anio);
        diasTotalesdelmes = 31;
        break;
    case 1:
        printf("\t\tFEBRERO\t%d", anio);
        diasTotalesdelmes = febrero;
        break;
    case 2:
        printf("\t\tMARZO\t%d", anio);
        diasTotalesdelmes = 31;
        break;
    case 3:
        printf("\t\tABRIL\t%d", anio);
        diasTotalesdelmes = 30;
        break;
    case 4:
        printf("\t\tMAYO\t%d", anio);
        diasTotalesdelmes = 31;
        break;
    case 5:
        printf("\t\tJUNIO\t%d", anio);
        diasTotalesdelmes = 30;
        break;
    case 6:
        printf("\t\tJULIO\t%d", anio);
        diasTotalesdelmes = 31;
        break;
    case 7:
        printf("\t\tAGOSTO\t%d", anio);
        diasTotalesdelmes = 31;
        break;
    case 8:
        printf("\t\tSEPTIEMBRE\t%d", anio);
        diasTotalesdelmes = 30;
        break;
    case 9:
        printf("\t\tOCTUBRE\t%d", anio);
        diasTotalesdelmes = 31;
        break;
    case 10:
        printf("\t\tNOVIEMBRE\t%d", anio);
        diasTotalesdelmes = 30;
        break;
    case 11:
        printf("\t\tDICIEMBRE\t%d", anio);
        diasTotalesdelmes = 31;
        break;
    default:
        break;
    }

    if (febrero == 29)
    {
        switch (mes)
        {
        case 0:
            moduloMes = 0;
            break;
        case 1:
            moduloMes = 3;
            break;
        case 2:
            moduloMes = 4;
            break;
        case 3:
            moduloMes = 0;
            break;
        case 4:
            moduloMes = 2;
            break;
        case 5:
            moduloMes = 5;
            break;
        case 6:
            moduloMes = 0;
            break;
        case 7:
            moduloMes = 3;
            break;
        case 8:
            moduloMes = 6;
            break;
        case 9:
            moduloMes = 1;
            break;
        case 10:
            moduloMes = 4;
            break;
        case 11:
            moduloMes = 6;
            break;
        }
    }
    else
    {
        switch (mes)
        {
        case 0:
            moduloMes = 0;
            break;
        case 1:
            moduloMes = 3;
            break;
        case 2:
            moduloMes = 3;
            break;
        case 3:
            moduloMes = 6;
            break;
        case 4:
            moduloMes = 1;
            break;
        case 5:
            moduloMes = 4;
            break;
        case 6:
            moduloMes = 6;
            break;
        case 7:
            moduloMes = 2;
            break;
        case 8:
            moduloMes = 5;
            break;
        case 9:
            moduloMes = 0;
            break;
        case 10:
            moduloMes = 3;
            break;
        case 11:
            moduloMes = 5;
            break;
        }

        // identifica el inicio de la semana, tomando en cuenta
        // Do, Lu, Ma, Mi, Ju, Vi, Sa
        // 0 , 1 ,  2,  3,  4,  5,  6
        diaDeSemana = ((anio - 1) % 7 + ((anio - 1) / 4 - (3 * ((anio - 1) / 100 + 1) / 4)) % 7 + moduloMes + 1 % 7) % 7;

        int i, m;

        printf("\nDo\tLu\tMar\tMier\tJue\tVier\tSab\n");

        for (m = 0; m < diaDeSemana; m++) 
        { //da espacios para acomodar el primer dia de la semana.
            printf("\t");
        }

        for (i = 1; i <= diasTotalesdelmes; i++)
        {

            if (i == 8 - diaDeSemana || i == 15 - diaDeSemana || i == 22 - diaDeSemana || i == 29 - diaDeSemana || i == 36 - diaDeSemana)
                printf("\n");
            
            if (i == dia) // resalta el dia en color verde si coincide con el ingresado
            {
                printf("\033[42;30m");
            }

            printf("%d\t", i);
            printf("\033[0m"); // reset de color
            
        }

        while (elige == 0)
        {
            printf("\n\nQuieres buscar alguna fecha? \n\tSi = 1 No = 2\t ");
            scanf("%d", &elige);

            if (elige == 1)
            {
                printf("\nEscribe un dia: ");
                scanf("%d", &dia);

                printf("Escribe un mes: ");
                scanf("%d", &mes);

                mes -= 1;

                printf("Escribe un anio: ");
                scanf("%d", &anio);
                goto imprime_calendario;
            }
            else if (elige == 2)
            {
                return 0;
            }
            else
            {
                printf("Error al elegir opcion...");
                elige = 0;
            }
        }
    }

    return 0;
}