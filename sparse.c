#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int *values;
    int *columns;
    int *row_ptr;
    int num_rows;
    int num_nonzeros;
} SparseMatrixCSR;
void initializeSparseMatrix(SparseMatrixCSR *matrix, int num_rows, int num_nonzeros) {
    matrix->num_rows = num_rows;
    matrix->num_nonzeros = num_nonzeros;
    matrix->values = (int *)malloc(num_nonzeros * sizeof(int));
    matrix->columns = (int *)malloc(num_nonzeros * sizeof(int));
    matrix->row_ptr = (int *)malloc((num_rows + 1) * sizeof(int));
}
void setSparseMatrixValues(SparseMatrixCSR *matrix, int *values, int *columns, int *row_ptr) {
    for (int i = 0; i < matrix->num_nonzeros; i++) {
        matrix->values[i] = values[i];
        matrix->columns[i] = columns[i];
    }
    for (int i = 0; i <= matrix->num_rows; i++) {
        matrix->row_ptr[i] = row_ptr[i];
    }
}
void printSparseMatrix(const SparseMatrixCSR *matrix) {
    printf("Values: ");
    for (int i = 0; i < matrix->num_nonzeros; i++) {
        printf("%d ", matrix->values[i]);
    }
    printf("\n");
printf("Columns: ");
    for (int i = 0; i < matrix->num_nonzeros; i++) {
        printf("%d ", matrix->columns[i]);
    }
    printf("\n");
printf("Row pointers: ");
    for (int i = 0; i <= matrix->num_rows; i++) {
        printf("%d ", matrix->row_ptr[i]);
    }
    printf("\n");
}
void freeSparseMatrix(SparseMatrixCSR *matrix) {
    free(matrix->values);
    free(matrix->columns);
    free(matrix->row_ptr);
}
int main() {
    SparseMatrixCSR matrix;
    int num_rows = 4;
    int num_nonzeros = 5;
initializeSparseMatrix(&matrix, num_rows, num_nonzeros);
int values[] = {1, 2, 3, 4, 5};        // Non-zero values
int columns[] = {0, 1, 2, 3, 0};       // Column indices
int row_ptr[] = {0, 1, 2, 4, 5};       // Row pointers
setSparseMatrixValues(&matrix, values, columns, row_ptr);
printSparseMatrix(&matrix);
freeSparseMatrix(&matrix);
return 0;
}

