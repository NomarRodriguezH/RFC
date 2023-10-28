#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Función para dividir una cadena en palabras separadas
void dividirOracionEnPalabras(const char *nombreCompleto, char nombre[20][20], int *numPalabras) {
    int longitud = strlen(nombreCompleto);
    int inicio = 0;

    for (int i = 0; i < longitud; i++) {
        if (nombreCompleto[i] == ' ' || nombreCompleto[i] == '\n') {
            int k = 0;
            for (int j = inicio; j < i; j++) {
                if (nombreCompleto[j] != ' ') {
                    nombre[*numPalabras][k++] = nombreCompleto[j];
                }
            }
            nombre[*numPalabras][k] = '\0';
            (*numPalabras)++;
            inicio = i + 1;
        }
    }
}

// Obtener las últimas dos letras de una cadena
void obtenerUltimasDosLetras(const char *cadena, char ultimasDosCaracteres[3]) {
     int longitud = strlen(cadena);
    if (longitud >= 2) {
        strncpy(ultimasDosCaracteres, cadena + longitud - 2, 2);
        ultimasDosCaracteres[2] = '\0';
    } else {
        printf("La cadena es demasiado corta para extraer los últimos 2 caracteres.\n");
    }
}

// Obtener la vocal inmediata
char obtenerVocalNombre(const char *nombre) {
    char vocalPaterno = '-';
    char vocales[] = {'A', 'E', 'I', 'O', 'U'};

    for (int i = 1; i <= strlen(nombre); i++) { 
        for (int j = 0; j < sizeof(vocales) / sizeof(vocales[0]); j++) {
            if (tolower(nombre[i]) == tolower(vocales[j])) {
                vocalPaterno = toupper(vocales[j]);
                break;
            }
        }
        if (vocalPaterno != '-') {
            break;
        }
    }
    return vocalPaterno;
}

// Obtener los dígitos del mes de una fecha
void obtenerDigitosMes(const char *fecha, char digitosMes[3]) {
    char fechaSeparada[20][20];
    int numPalabras = 0;
    dividirOracionEnPalabras(fecha, fechaSeparada, &numPalabras);

    for (int i = 0; i < numPalabras; i++) {
        if (strcmp(fechaSeparada[i], "enero") == 0) {
            strcpy(digitosMes, "01");
        } else if (strcmp(fechaSeparada[i], "febrero") == 0){
            strcpy(digitosMes, "02");
        } else if (strcmp(fechaSeparada[i], "marzo") == 0){
            strcpy(digitosMes, "03");
        } else if (strcmp(fechaSeparada[i], "abril") == 0){
            strcpy(digitosMes, "04");
        } else if (strcmp(fechaSeparada[i], "mayo") == 0){
            strcpy(digitosMes, "05");
        } else if (strcmp(fechaSeparada[i], "junio") == 0){
            strcpy(digitosMes, "06");
        } else if (strcmp(fechaSeparada[i], "julio") == 0){
            strcpy(digitosMes, "07");
        } else if (strcmp(fechaSeparada[i], "agosto") == 0){
            strcpy(digitosMes, "08");
        } else if (strcmp(fechaSeparada[i], "septiembre") == 0){
            strcpy(digitosMes, "09");
        } else if (strcmp(fechaSeparada[i], "octubre") == 0){
            strcpy(digitosMes, "10");
        } else if (strcmp(fechaSeparada[i], "noviembre") == 0){
            strcpy(digitosMes, "11");
        } else if (strcmp(fechaSeparada[i], "diciembre") == 0){
            strcpy(digitosMes, "12");
        }
    }
}

int main() {
    char RFC[100];
    char nombreCompleto[30];
    char primerLetraPaterno;
    char vocalPaterno = '-';
    char primerLetraMaterno;
    char primerLetraNombre;
    char fechaNacimiento[50];
    char digitosMes[3];
    char digitosDia[3];
    char nombre[20][20];
    char fechaSeparada[20][20];
    int numPalabras = 0;
    char fechaNacimientoAux[50];
    char ultimosDosCaracteres[3];

    printf("Ingrese su nombre empezando por apellido paterno:\n");
    fgets(nombreCompleto, sizeof(nombreCompleto), stdin);

    printf("Ingrese su fecha de nacimiento (DD/MM/AAAA):\n");
    fgets(fechaNacimiento, sizeof(fechaNacimiento), stdin);

    if (numPalabras == 3) {
        printf("Primer Apellido: %s\nSegundo Apellido: %s\nNombre: %s\n", nombre[0], nombre[1], nombre[2]);
    } else {
        printf("Ingrese su nombre completo como aparece en su acta de nacimiento.\n");
    }


    size_t longitud = strlen(fechaNacimiento);
    if (longitud > 0 && fechaNacimiento[longitud - 1] == '\n') {
        fechaNacimiento[longitud - 1] = '\0';
    }
    strcpy(fechaNacimientoAux, fechaNacimiento);

    obtenerUltimasDosLetras(fechaNacimientoAux, ultimosDosCaracteres);

    dividirOracionEnPalabras(nombreCompleto, nombre, &numPalabras);

  
    vocalPaterno = obtenerVocalNombre(nombre[1]);
    primerLetraPaterno = nombre[1][0];
    primerLetraMaterno = nombre[2][0];
    primerLetraNombre = nombre[0][0];

    obtenerDigitosMes(fechaNacimiento, digitosMes);

    strncpy(digitosDia, fechaNacimiento, 2);
    digitosDia[2] = '\0';

    sprintf(RFC, "%c%c%c%c%s%s%s", primerLetraPaterno, vocalPaterno, primerLetraMaterno, primerLetraNombre, ultimosDosCaracteres, digitosMes, digitosDia);
    printf("Tu RFC es: %s\n", RFC);

    return 0;
}