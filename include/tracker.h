#ifndef TRACKER_H__
#define TRACKER_H__

#include <glib.h>

#include "repo.h"

typedef struct {
	GHashTable *repos;
} Tracker;

Tracker *newTracker();

Repo *getRepo(Tracker *tracker, int id);

gboolean addRepo(Tracker *tracker, int id, const char *org, const char *repo);

gboolean removeRepo(Tracker *tracker, int id);

#endif // TRACKER_H__
