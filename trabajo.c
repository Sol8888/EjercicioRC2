#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void opcion1(int matriz2017[7][2], int matriz2018[7][2], int matriz2019[7][2], int matriz2020[7][2], int matriz2021[7][2]);

void guardarDatos(int matriz2017[7][2], int matriz2018[7][2], int matriz2019[7][2], int matriz2020[7][2], int matriz2021[7][2]);

int main() {
    setlocale(LC_ALL, ""); // Establecer configuración regional para imprimir caracteres especiales
    int opcion;
    int matriz2017[7][2] = {{100, 50}, {150, 75}, {152, 70}, {10, 8}, {5, 4}, {70, 60}, {80, 30}};
    int matriz2018[7][2] = {{150, 155}, {30, 20}, {100, 50}, {5, 100}, {99, 86}, {78, 54}, {3, 60}};
    int matriz2019[7][2] = {{200, 115}, {100, 78}, {90, 65}, {50, 42}, {20, 15}, {15, 7}, {60, 89}};
    int matriz2020[7][2] = {{28, 92}, {183, 18}, {33, 32}, {93, 93}, {123, 26}, {51, 34}, {52, 54}};
    int matriz2021[7][2] = {{156, 78}, {200, 46}, {75, 38}, {90, 47}, {34, 15}, {82, 98}, {69, 74}};

    do {
        wprintf(L"---- Menú ----\n");
        wprintf(L" 1. Año en el que ingresó la mayor cantidad de alumnos\n");
        wprintf(L" 2. Carrera que recibió la mayor cantidad de alumnos en el último año\n");
        wprintf(L" 3. Año en donde Software recibió la mayor cantidad de alumnos\n");
        wprintf(L" 4. Guardar datos y salir\n");
        wprintf(L" Opción: ");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                opcion1(matriz2017, matriz2018, matriz2019, matriz2020, matriz2021);
                break;
            case 2:
                opcion2(matriz2021);
                break;
            case 3:
                opcion3(matriz2017, matriz2018, matriz2019, matriz2020, matriz2021);
                break;
            case 4:
                guardarDatos(matriz2017, matriz2018, matriz2019, matriz2020, matriz2021);
                wprintf(L"Guardando datos en el archivo \"datos.txt\"...\n");
                wprintf(L"Saliendo...\n");
                break;
            default:
                wprintf(L"Opción inválida. Intente nuevamente.\n");
                break;
        }

        wprintf(L"\n");

    } while (opcion != 4);
}

void opcion1(int matriz2017[7][2], int matriz2018[7][2], int matriz2019[7][2], int matriz2020[7][2], int matriz2021[7][2]) {
    int i, j;
    int mayor = 0;
    int anoMayor = 0;
    int sumas[5] = {0};
    int anos[5] = {2017, 2018, 2019, 2020, 2021};

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 2; j++) {
            sumas[0] += matriz2017[i][j];
            sumas[1] += matriz2018[i][j];
            sumas[2] += matriz2019[i][j];
            sumas[3] += matriz2020[i][j];
            sumas[4] += matriz2021[i][j];
        }
    }

    for (i = 0; i < 5; i++) {
        if (sumas[i] > mayor) {
            mayor = sumas[i];
            anoMayor = anos[i];
        }
    }

    wprintf(L"El año en donde más estudiantes ingresaron a la universidad fue %d.\n", anoMayor);
}

void opcion2(int matriz2021[7][2]) {
    int i, j;
    int total;
    int mayor = 0;
    int fila = 0;

    wchar_t carreras[7][25] = {
        L"Ing. Software", L"Administración", L"Economía", L"Relaciones internacionales",
        L"Matemáticas", L"Contabilidad", L"Ing. Industrial"
    };

    for (i = 0; i < 7; i++) {
        total = 0;
        for (j = 0; j < 2; j++) {
            total += matriz2021[i][j];
            if (total > mayor) {
                mayor = total;
                fila = i;
            }
        }
    }

    wprintf(L"La carrera en donde más estudiantes ingresaron el último año es: %ls\n", carreras[fila]);
}

void opcion3(int matriz2017[7][2], int matriz2018[7][2], int matriz2019[7][2], int matriz2020[7][2], int matriz2021[7][2]) {
    int i, j;
    int mayor = 0;
    int anoMayor = 0;
    int sumas[5] = {0};
    int anos[5] = {2017, 2018, 2019, 2020, 2021};

    for (i = 0; i < 1; i++) {
        for (j = 0; j < 1; j++) {
            sumas[0] += matriz2017[i][j];
            sumas[1] += matriz2018[i][j];
            sumas[2] += matriz2019[i][j];
            sumas[3] += matriz2020[i][j];
            sumas[4] += matriz2021[i][j];
        }
    }

    for (i = 0; i < 5; i++) {
        if (sumas[i] > mayor) {
            mayor = sumas[i];
            anoMayor = anos[i];
        }
    }

    wprintf(L"El año en donde más estudiantes ingresaron a la carrera de Ing. Software fue: %d\n", anoMayor);
}

void guardarDatos(int matriz2017[7][2], int matriz2018[7][2], int matriz2019[7][2], int matriz2020[7][2], int matriz2021[7][2]) {
    FILE* archivo;
    archivo = fopen("datos.txt", "w");

    if (archivo == NULL) {
        wprintf(L"No se pudo abrir el archivo para guardar los datos.\n");
        return;
    }

    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 2; j++) {
            fprintf(archivo, "%d ", matriz2017[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fprintf(archivo, "\n");

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 2; j++) {
            fprintf(archivo, "%d ", matriz2018[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fprintf(archivo, "\n");

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 2; j++) {
            fprintf(archivo, "%d ", matriz2019[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fprintf(archivo, "\n");

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 2; j++) {
            fprintf(archivo, "%d ", matriz2020[i][j]);
        }
        fprintf(archivo, "\n");
    }
    fprintf(archivo, "\n");

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 2; j++) {
            fprintf(archivo, "%d ", matriz2021[i][j]);
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
}
