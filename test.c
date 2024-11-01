#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
DOTPROD:
Vektory v souboru musí být zadané ve stylu:

1 2.0 0.005 -0.5
5.0 3.0 -5.02 00.2

*/

char filePath[256];

void sqrt_function();
void mandelbrot_function();
void dotprod_function(char filePath[256]);

int main() {
    char funkce[256];
    printf("Jakou funkci chces pouzit \n (sqrt/mandelbrot/dotprod): \n");

    fgets(funkce, sizeof(funkce), stdin);
    funkce[strcspn(funkce, "\n")] = 0;

    //tohle je maximalne nechutne reseni ale funguje to takze asi whatever :D
    if (strcmp(funkce, "sqrt") == 0) {
        sqrt_function();
    } else if (strcmp(funkce, "mandelbrot") == 0) {
        mandelbrot_function();
    } else if (strcmp(funkce, "dotprod") == 0) {
        printf("Zadejte cestu k souboru:\n");
        fgets(filePath, sizeof(filePath), stdin);
        filePath[strcspn(filePath, "\n")] = 0;
        dotprod_function(filePath);
    } else {
        printf("Neplatna funkce\n");
    }

    return 0;
}

void sqrt_function() {
    printf("sqrt funkce\n");
}

void mandelbrot_function() {
    printf("mandelbrotovamnamina\n");
    }


void dotprod_function(char filePath[256]) {
    char line1[512], line2[512], *vector;
    double vector1[256], vector2[256], soucin; //maximalni pocet prvků ve vektoru je 256 (v pripade zvetsit)
    int Vectory1, Vectory2, i;

    FILE *file;

    if (strlen(filePath) == 0) {
        strcpy(filePath, "stdir");
    }

    file = fopen(filePath, "r");
    if (file == NULL) {
        fprintf(stderr, "Chyba pri otevirani souboru");
    }

    if (fgets(line1, sizeof(line1), file) == NULL) {
        fprintf(stderr, "Chyba pri cteni prvniho radku");
        fclose(file);
    }
    if (fgets(line2, sizeof(line2), file) == NULL) {
        fprintf(stderr, "Chyba pri cteni druheho radku");
        fclose(file);
    }

    fclose(file);

    vector = strtok(line1, " "); 
    i = 0;

    while (vector != NULL) {
        vector1[i] = atof(vector);
        vector = strtok(NULL, " ");
        i++;
    }

    Vectory1 = i;

    i = 0;
    vector = strtok(line2, " "); 
    while (vector != NULL) {
        vector2[i] = atof(vector);
        vector = strtok(NULL, " ");
        i++;
    }

    Vectory2 = i;

    if (Vectory1 != Vectory2) {
        fprintf(stderr, "Vektory maji ruzne delky, nelze vypocitat\n");
    }

    i = 0;
    soucin = 0;

    while(Vectory1 != i){
        soucin += vector1[i] * vector2[i];
        i++;
    }

    printf("\n============================\nSoucin vektoru je:\n %.17e\n============================\n", soucin);
}
