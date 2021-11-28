#include "tracker.h"

void tracker_key_destroyed(gpointer data) {
	gint *id = (gint *)data;
	g_free(id);
}

void tracker_value_destroyed(gpointer data) {
	Repo *r = (Repo *)data;
	g_free(r -> org);
	g_free(r -> repo);
	g_free(r);
}

Tracker *newTracker() {
	Tracker *t = (Tracker *)g_malloc(sizeof(Tracker));
	if (!t) {
		return NULL;
	}
	t -> repos = g_hash_table_new_full(g_int_hash, g_int_equal,
			(GDestroyNotify)tracker_key_destroyed,
			(GDestroyNotify)tracker_value_destroyed);
	if (!t -> repos) {
		return NULL;
	}
	return t;
}

Repo *getRepo(Tracker *tracker, int id) {
	if (!tracker || !tracker -> repos) {
		return NULL;
	}

	gint *gid = g_new(gint, 1);
	*gid = id;
	Repo *r = (Repo *)g_hash_table_lookup(tracker -> repos, gid);
	g_free(gid);
	return r;
}

gboolean addRepo(Tracker *tracker, int id, const char *org, const char *repo) {
	if (!tracker || !tracker -> repos || !org || !repo) {
		return FALSE;
	}

	gint *gid = g_new(gint, 1);
	*gid = id;

	Repo *r = (Repo *)g_malloc(sizeof(Repo));
	if (!r) {
		return FALSE;
	}
	r -> org = g_strdup(org);
	r -> repo = g_strdup(repo);
	if (!r -> org || !r -> repo) {
		return FALSE;
	}
	g_hash_table_insert(tracker -> repos, gid, r);
	return TRUE;
}

gboolean removeRepo(Tracker *tracker, int id) {
	if (!tracker || !tracker -> repos) {
		return FALSE;
	}
	gint *gid = g_new(gint, 1);
	*gid = id;
	g_hash_table_remove(tracker -> repos, gid);
	g_free(gid);
	return TRUE;
}
