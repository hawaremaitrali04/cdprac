#include <stdio.h>
#include <string.h>

char op[2], arg1[5], arg2[5], result[5];

int main() {
    FILE *fp1, *fp2;

    fp1 = fopen("C:\\Users\\SMRUTI DESHPANDE\\OneDrive\\Desktop\\exp9\\input.txt", "r");
    if (fp1 == NULL) {
        perror("Error opening input file");
        return 1;
    }

    fp2 = fopen("C:\\Users\\SMRUTI DESHPANDE\\OneDrive\\Desktop\\exp9\\output.txt", "w");
    if (fp2 == NULL) {
        perror("Error opening output file");
        fclose(fp1);
        return 1;
    }

    while (fscanf(fp1, "%s %s %s %s", op, arg1, arg2, result) == 4) {
        if (strcmp(op, "+") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nADD R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "*") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMUL R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "-") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nSUB R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "/") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nDIV R0, %s", arg2);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
        else if (strcmp(op, "=") == 0) {
            fprintf(fp2, "\nMOV R0, %s", arg1);
            fprintf(fp2, "\nMOV %s, R0", result);
        }
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);

    return 0;
}