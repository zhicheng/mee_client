main: utils.o
	cc -o mee_client mee_client.c -I/opt/local/include -L/opt/local/lib -lcurl -L/opt/local/lib -L/opt/local/lib -lz -I/opt/local/include/json -L/opt/local/lib -ljson $^ 

utils.o: utils.c utils.h
	gcc -c $<

