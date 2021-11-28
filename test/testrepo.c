#include <glib.h>

#include "repo.h"

static void test_repo_geturl1() {
	Repo *r = (Repo *)g_malloc(sizeof(Repo));
	r -> org = "swinslow";
	r -> repo = "spdxLicenseManager";
	const char *url = getRepoURL(r);
	g_assert_cmpstr(url, ==, "https://github.com/swinslow/spdxLicenseManager");
	g_free(r);
}

void add_repo_tests() {
	g_test_add_func("/repo/geturl1", test_repo_geturl1);
}
