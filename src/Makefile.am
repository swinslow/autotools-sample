noinst_LIBRARIES = librepotracker.a
librepotracker_a_SOURCES = repo.c tracker.c
librepotracker_a_CFLAGS = -I../include $(glib_CFLAGS)

bin_PROGRAMS = repoexample
repoexample_SOURCES = main.c
repoexample_CFLAGS = -I../include $(glib_CFLAGS)
repoexample_LDADD = librepotracker.a $(glib_LIBS)
