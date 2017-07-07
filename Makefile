all: time_stats.so ts_example

time_stats.so:
	gcc src/time_stats.c -c -fPIC -shared -o time_stats.so -D _BSD_SOURCE

ts_example: time_stats.so
	gcc ts_example.c time_stats.so -lm -I src/ -o ts_example

clean:
	rm -f time_stats.so ts_example

