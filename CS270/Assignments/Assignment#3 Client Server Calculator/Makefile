cc = gcc
cflags = 
tgts = calculator_client.out calculator_server.out


all:
	make calculator_client
	make calculator_server

calculator_client: calculator_client.c
	$(cc) $(cflags) calculator_client.c -o calculator_client.out

calculator_server: calculator_server.c
	$(cc) $(cflags) calculator_server.c -o calculator_server.out

clean:
	rm $(tgts)