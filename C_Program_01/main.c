/*
 
 Estanislao Crivos Gandini (Junio 2023)
 
 Programa que calcula la depreciacion de un bien dado su costo inicial y la cantidad de años por los que es utilizado. Se pueden elegir tres metodos de calculo y el software devuelve la depreciacion por año en AR$.
 
 Trabajo correspondiente a la primer actividad del curso de nivelación en C del CESE 2023.
 
 */

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int option;
    float value;
    float aux;
    float depreciation;
    int years;
    float factor;
    int end = 0;
    float denom;
    
    while(end != 1)
    {
        printf("\nBienvenido al software de cálculo de depreciación de bienes...\n");
        printf("\nIndique el método que desee para realizar el cálculo: 1 (método lineal), 2 (método balance), 3 (método suma): ");
        scanf("%d", &option);
        
        if (option != 1 && option != 2 && option != 3)
        {
            printf("Esa opción no existe. Fin del programa...\n");
            end = 1;
        }
        
        if(option == 1 || option == 2 || option == 3)
        {
            printf("Ingrese el valor del bien en AR$: ");
            scanf("%f", &value);
            
            printf("Ingrese la cantidad de años a considerar: ");
            scanf("%d", &years);
            
            switch (option)
            {
                case 1:
                    depreciation = value/years;
                    printf("En este caso la depreciación es constante a lo largo de los años e igual a: %.1f AR$/AÑO\n", depreciation);
                    break;
                    
                case 2:
                    aux = 0;
                    factor = 2.0/years;
                    for(int i = 0; i < years; i++)
                    {
                        depreciation = factor * (value - aux);
                        aux += depreciation;
                        printf("La depreciación en el año %d es de %.1f AR$\n", i+1, depreciation);
                    }
                    break;
                    
                case 3:
                    denom = 0;
                    
                    // Calculo el denominador para el calculo
                    for(int i = 1.0; i <= years; i++) // (quiero que denom quede como float)
                    {
                        denom += i;
                    }
                    
                    // Calculo la depreciacion del bien
                    for(int i = 0; i < years; i++)
                    {
                        depreciation = ((years - i)/denom) * value; // La primer operacion debe resultar en float
                        printf("La depreciación en el año %d es de %.1f AR$\n", i+1, depreciation);
                    }
                    break;
            }
        }
    }
    
    return 0;
}
