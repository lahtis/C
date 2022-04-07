// C program for the above approach
// using char and int

#include <stdio.h>

int main(int argc, char *argv[]) {

	// Substitute the file_path string
	// with full path of CSV file

	FILE* fp = fopen("account.cvs", "a+");

	char name[50];
	int accountno, amount;

	if (!fp) {
		// Error in file opening
		printf("Can't open file\n");
		return 0;
	}

	// Asking user input for the
	// new record to be added
	printf("\nEnter Account Holder Name\n");
	scanf("%s", name);
	printf("\nEnter Account Number\n");
	scanf("%d", &accountno);
	printf("\nEnter Available Amount\n");
	scanf("%d", &amount);

	// Saving data in file
	fprintf(fp, "%s, %d, %d\n", name, accountno, amount);

	printf("\nNew Account added to record\n");

	fclose(fp);
	return 0;
}

