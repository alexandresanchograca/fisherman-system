#include <ctype.h>

//Funcoes para dar loop a um array de carateres (string) e por tudo em lowercase
char* toLower(char* s) {
	for (char* p = s; *p; p++) *p = tolower(*p);
	return s;
}
char* toUpper(char* s) {
	for (char* p = s; *p; p++) *p = toupper(*p);
	return s;
}