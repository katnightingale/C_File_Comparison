/*Name: Katherine Nightingale
Program Description: Program that takes two files and compares them, character by character.  It then outputs the percentage of mismatches, as well as the percentage of non-tested characters.  User can
choose whether to test for case sensitivity, and whether or not to compare punctuation.
*/
#include <stdio.h>
#pragma warning (disable : 4996)

void main() {
	FILE* fp2a, * fp2b;
	char caseTest, punctTest, ch, ch2;
	float mismatchPercent; float noTestPercent;
	char file1[] = "file2a.txt";
	char file2[] = "file2b.txt";
	int caseSensitivity = 0, punctSensitivity = 1; //means case insensitive and punctuation sensitive
	int letterCount = 0, mismatch = 0; int noTest = 0;
	printf("Case insensitive? Y/N\n");
	scanf(" %c", &caseTest);
	printf("Compare letters only? Y/N\n");
	scanf(" %c", &punctTest);
	fp2a = fopen(file1, "r");
	fp2b = fopen(file2, "r");
	ch = getc(fp2a);
	ch2 = getc(fp2b);
	if (tolower(caseTest) == 'n') {
		caseSensitivity = 1; //1 means case sensitive
	}
	if (tolower(punctTest) == 'y') {
		punctSensitivity = 0; //0 means punctuation insensitive
	}
	mismatchPercent = 0;
	noTestPercent = 0;
	while (ch != EOF) {
		letterCount++;
		if (caseSensitivity == 1 && punctSensitivity == 1) { //testing for case sensitivity and punctuation
			if (isalpha(ch) && isalpha(ch2)) {
				if (ch != ch2) {
					mismatch++;
				}
			}
			else if (!isalpha(ch) && !isalpha(ch2)) {
				if (ch != ch2) {
					mismatch++;
				}
			}
		}
		if (caseSensitivity == 1 && punctSensitivity == 0) { //testing for case sensitivity only
			if (isalpha(ch) && isalpha(ch2)) {
				if (ch != ch2) {
					mismatch++;
				}
			}
			else {
				noTest++;
			}
		}
		if (caseSensitivity == 0 && punctSensitivity == 1) { //testing for punctuation only
			if (isalpha(ch) && isalpha(ch2)) {
				if (tolower(ch) != tolower(ch2)) {
					mismatch++;
				}
			}
			else if (!isalpha(ch) && !isalpha(ch2)) {
				if (ch != ch2) {
					mismatch++;
				}
			}
		}
		if (caseSensitivity == 0 && punctSensitivity == 0) { //testing for neither case sensitivity or punctuation
			if (isalpha(ch) && isalpha(ch2)) {
				if (tolower(ch) != tolower(ch2)) {
					mismatch++;
				}
			}
			else if (!isalpha(ch) && !isalpha(ch2)) {
				noTest++;
			}
		}
		mismatchPercent = (float)mismatch / letterCount;
		mismatchPercent *= 100;
		noTestPercent = (float)noTest / letterCount;
		noTestPercent *= 100;
		ch = getc(fp2a);
		ch2 = getc(fp2b);
	}
	fclose(fp2a);
	fclose(fp2b);
	printf("\n\nComparing %s to %s", file1, file2);
	if (caseSensitivity == 1 && punctSensitivity == 1) {
		printf(" testing for case sensitivity and nonletter characters.");
	}
	if (caseSensitivity == 1 && punctSensitivity == 0) {
		printf(" testing for case sensitivity only.");
	}
	if (caseSensitivity == 0 && punctSensitivity == 1) {
		printf(" testing for nonletter characters only.");
	}
	if (caseSensitivity == 0 && punctSensitivity == 0) {
		printf(" not testing for case sensitivity or nonletter characters.");
	}
	printf("\nFile size: %d characters\nMismatches: %.2f%%\nNot tested: %.2f%%\n", letterCount, mismatchPercent, noTestPercent);
}
/* OUTPUT:
Case insensitive? Y/N
y
Compare letters only? Y/N
y


Comparing file2a.txt to file2b.txt not testing for case sensitivity or nonletter characters.
File size: 728 characters
Mismatches: 2.20%
Not tested: 23.21%

Case insensitive? Y/N
n
Compare letters only? Y/N
n


Comparing file2a.txt to file2b.txt testing for case sensitivity and nonletter characters.
File size: 728 characters
Mismatches: 7.28%
Not tested: 0.00%

*/
