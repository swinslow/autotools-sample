noinst_PROGRAMS = runtests
runtests_SOURCES = tests.c testrepo.c
runtests_CFLAGS = -I../include `pkg-config --cflags glib-2.0`
runtests_LDFLAGS = `pkg-config --libs glib-2.0`
runtests_LDADD = ../src/librepotracker.a
