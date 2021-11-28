noinst_LIBRARIES = librepotracker.a
librepotracker_a_SOURCES = repo.c tracker.c
librepotracker_a_CFLAGS = -I../include `pkg-config --cflags glib-2.0`

bin_PROGRAMS = repoexample
repoexample_SOURCES = main.c
repoexample_CFLAGS = -I../include `pkg-config --cflags glib-2.0`
repoexample_LDFLAGS = `pkg-config --libs glib-2.0`
repoexample_LDADD = librepotracker.a
