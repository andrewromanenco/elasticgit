#include "gith.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define GITH_RANDOM_STRING_LEN 8

void createRandomString(char *s, time_t randBase) {
	srand((unsigned)randBase);
	static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
	int i;
	for (i = 0; i < 8; ++i) {
		s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
	 }

    s[GITH_RANDOM_STRING_LEN] = 0;


}

void gith_log_usage(ssize_t xread, ssize_t xwrite, ssize_t uread, ssize_t uwrite, char *sx) {
	time_t tms = time(NULL);
	char* fileName = getenv("HST_LOG_FILE");
	FILE *file;
	if (fileName) {
		char *tmpFileName = malloc(100);
		sprintf(tmpFileName, "/var/log/gith/%s.%s", fileName, sx);
		file = fopen(tmpFileName, "w");
		free(tmpFileName);	
	} else{
		char *randomName = malloc(GITH_RANDOM_STRING_LEN + 1);
		createRandomString(randomName, tms);
		char *tmpFileName = malloc(100);
		sprintf(tmpFileName, "/var/log/gith/%ld.%s.%s",(long)tms, randomName, sx);
		file = fopen(tmpFileName, "w");
		free(randomName);
		free(tmpFileName);	
	}

	char *envVar;

	fprintf(file, "%s", "{\n");

	envVar = getenv("HST_USER_NAME");
	if (envVar) {
		fprintf(file, "\t\"user\": \"%s\",\n", envVar);
	} else {
		fprintf(file, "\t\"user\": \"%s\",\n", "");
	}

	envVar = getenv("HST_REPO");
	if (envVar) {
		fprintf(file, "\t\"repo\": \"%s\",\n", envVar);
	} else {
		fprintf(file, "\t\"repo\": \"%s\",\n", "");
	}

	envVar = getenv("HST_OPERATION");
	if (envVar) {
		fprintf(file, "\t\"operation\": \"%s\",\n", envVar);
	} else {
		fprintf(file, "\t\"operation\": \"%s\",\n", "");
	}

	fprintf(file, "\t\"xread\": %ld,\n", (long)xread);
	fprintf(file, "\t\"xwrite\": %ld,\n", (long)xwrite);
	fprintf(file, "\t\"uread\": %ld,\n", (long)uread);
	fprintf(file, "\t\"timestamp\": %ld\n", (long)tms);

	fprintf(file, "%s", "}");

	fclose(file);
}