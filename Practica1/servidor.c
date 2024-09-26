#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int servidorSocket, clienteSocket;
    struct sockaddr_in servidorAddr, clienteAddr;
    socklen_t addrTam;
    int numero;

    servidorSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (servidorSocket < 0) {
        printf("Error al crear el socket\n");
        return 1;
    }

    servidorAddr.sin_family = AF_INET;
    servidorAddr.sin_port = htons(12345);
    servidorAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(servidorSocket, (struct sockaddr *)&servidorAddr, sizeof(servidorAddr)) < 0) {
        printf("Error en el bind\n");
        return 1;
    }

    listen(servidorSocket, 5);
    printf("Esperando conexión del cliente...\n");

    addrTam = sizeof(clienteAddr);
    clienteSocket = accept(servidorSocket, (struct sockaddr *)&clienteAddr, &addrTam);
    printf("Cliente conectado.\n");

    while (1) {
        recv(clienteSocket, &numero, sizeof(numero), 0);
        numero = ntohl(numero); 

        if (numero == 0) {
            break;
        }

        printf("Número recibido: %d\n", numero);
        numero++;

        numero = htonl(numero); 
        send(clienteSocket, &numero, sizeof(numero), 0);
    }

    close(clienteSocket);
    close(servidorSocket);

    return 0;
}
