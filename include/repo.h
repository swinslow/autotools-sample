#ifndef REPO_H__
#define REPO_H__

#include <stddef.h>

typedef struct {
	char *org;
	char *repo;
} Repo;

const char *getRepoURL(Repo *r);

#endif  // REPO_H__
