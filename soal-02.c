/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 3 - Pointers and Functions
*Percobaan        : -
*Hari dan Tanggal : Jumat, 4 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-02.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_ROW 5
#define INPUT_COLUMN 5
#define FILTER_ROW 3
#define FILTER_COLUMN 3
#define MAX_STRING 200

// Deklarasi variabel
int inputMatrix[INPUT_ROW*INPUT_COLUMN];
float filterMatrix[FILTER_ROW*FILTER_COLUMN];
float outputMatrix[(INPUT_ROW-FILTER_ROW+1)*(INPUT_COLUMN-FILTER_COLUMN+1)];

//----------------------------------- FUNGSI MEMBACA FILE -----------------------------------//
// Deskripsi: mengekstrak informasi dari file eksternal dan menyimpannya ke dalam variabel input dan filter
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
//---------------------------------------------------------------------------------------//
void getMatrix(int *input, float *filter){
	FILE *filePointer ;
	 
	char filename[MAX_STRING];
	char buffer[MAX_STRING];
	char *token;
	int i = 0;

	printf("Masukkan nama file: ");
	scanf("%s", filename);
 
	filePointer = fopen(filename, "r") ;
	 
	if ( filePointer == NULL )
	{
		printf("File gagal dibuka.\n");
		isFileExist = 0;
	}
	else
	{
		fgets (buffer, MAX_STRING, filePointer);
		token = strtok(buffer, ",");
		while(token != NULL){
			*(input+i) = atoi(token);
			token = strtok(NULL, ",");
			i++;
		}

		i = 0;

		fgets (buffer, MAX_STRING, filePointer);
		token = strtok(buffer, ",");
		while(token != NULL){
			*(filter+i) = atof(token);
			token = strtok(NULL, ",");
			i++;
		}

		fclose(filePointer);
	}

	return;
}

//----------------------------------- FUNGSI KONVOLUSI -----------------------------------//
// Deskripsi: fungsi untuk konvolusi matriks input dengan filter. hasilnya disimpan pada variabel output
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
// *output : pointer matriks output
//---------------------------------------------------------------------------------------//
void convolution(int *input, float *filter, float *output){
	//-----Tuliskan kode anda disini------//
	
}

//----------------------------------- FUNGSI OUTPUT -----------------------------------//
// Deskripsi : fungsi untuk mencetak matriks input, filter, dan output
// Parameter:
// *input : pointer matriks input
// *filter : pointer matriks filter
// *output : pointer matriks output
//---------------------------------------------------------------------------------------//
void printMatrix(int *input, float *filter, float *output){
	printf("Matriks input: \n");
	for(int row = 0; row < INPUT_ROW; row++){
		for(int col = 0; col < INPUT_COLUMN; col++){
			printf("%d\t", *(input+row*(INPUT_COLUMN) + col));
		}
		printf("\n");
	}

	printf("Matriks filter: \n");
	for(int row = 0; row < FILTER_ROW; row++){
		for(int col = 0; col < FILTER_COLUMN; col++){
			printf("%.2f\t", *(filter+row*(FILTER_COLUMN) + col));
		}
		printf("\n");
	}

	printf("Matriks output: \n");
	for(int row = 0; row < INPUT_ROW-FILTER_ROW+1; row++){
		for(int col = 0; col < INPUT_COLUMN-FILTER_COLUMN+1; col++){
			printf("%.2f\t", *(output+row*(INPUT_COLUMN - FILTER_COLUMN + 1) + col));
		}
		printf("\n");
	}
}

int main(){
	//-----Tuliskan kode anda disini------//

}