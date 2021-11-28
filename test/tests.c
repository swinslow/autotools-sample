#include <glib.h>

#include "tests.h"

int main(int argc, char *argv[]) {
	g_test_init(&argc, &argv, NULL);

	add_repo_tests();

	return g_test_run();
}
