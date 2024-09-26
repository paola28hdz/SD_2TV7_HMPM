#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int clienteSocket;
    struct sockaddr_in servidorAddr;
    char mensaje[100] = "Hola\n";
    char respuesta[100];

    clienteSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clienteSocket < 0) {
        printf("Error al crear el socket\n");
        return 1;
    }

    servidorAddr.sin_family = AF_INET;
    servidorAddr.sin_port = htons(5000); 
    servidorAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clienteSocket, (struct sockaddr *)&servidorAddr, sizeof(servidorAddr)) < 0) {
        printf("Error al conectar con el servidor\n");
        return 1;
    }

    printf("Conectado\n");

    send(clienteSocket, mensaje, strlen(mensaje), 0);
    printf("Mensaje enviado\n");

    recv(clienteSocket, respuesta, sizeof(respuesta), 0);
    printf("Respuesta del servidor: %s\n", respuesta);

    close(clienteSocket);

    return 0;
}