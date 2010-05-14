cflags = -I/opt/local/include -I/opt/local/include/json
libs = -L/opt/local/lib -lcurl -ljson 

mee_client: utils.o mee_client.c
	cc -o $@ $(cflags) $(libs) $^ 

utils.o: utils.c utils.h
	cc -c $<

clean:
	rm *.o
	rm mee_client

