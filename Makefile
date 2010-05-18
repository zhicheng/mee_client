cflags = -I/opt/local/include -I/opt/local/include/json
libs = -L/opt/local/lib -lcurl -ljson 

mc: utils.o main.c
	cc -o $@ $(cflags) $(libs) $^ 

utils.o: utils.c utils.h
	cc -c $<

clean:
	rm *.o
	rm mc 

