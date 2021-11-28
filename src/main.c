#include <stdio.h>

#include "tracker.h"
#include "repo.h"

int main(int argc, char *argv[]) {
	Tracker *t = newTracker();

	addRepo(t, 1, "spdx", "tools-golang");
	addRepo(t, 2, "spdx", "spdx-examples");
	addRepo(t, 3, "swinslow", "spdxLicenseManager");
	addRepo(t, 4, "fossology", "fossdriver");
	addRepo(t, 5, "lfscanning", "scaffold");
	addRepo(t, 6, "spdx", "license-list-XML");

	Repo *r = getRepo(t, 4);
	printf("Repo 4: %s\n", getRepoURL(r));

	return 0;
}
