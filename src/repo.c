#include <string.h>
#include <stdio.h>
#include <glib.h>

#include "repo.h"

const char *getRepoURL(Repo *r) {
	char *url = NULL;

	if (!r || !(r -> org) || !(r -> repo)) {
		return NULL;
	}

	// "https://github.com/ORG/REPO" => 20 + ORG + REPO + '/0'
	int url_len = 21 + strlen(r -> org) + strlen(r -> repo);
	url = (char *)malloc(sizeof(char) * url_len);
	if (!url) {
		return NULL;
	}

	int retval = snprintf(url, url_len, "https://github.com/%s/%s", r -> org, r -> repo);
	if (retval == 0) {
		return NULL;
	}
	return url;
}
