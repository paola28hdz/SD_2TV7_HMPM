import java.io.*;
import java.net.*;

public class Servidor {
    public static void main(String[] args) {
        try {
            ServerSocket servidorSocket = new ServerSocket(5000);
            System.out.println("Servidor iniciado en el puerto 5000.");
  
            Socket clienteSocket = servidorSocket.accept();
            System.out.println("Cliente conectado.");

            BufferedReader entrada = new BufferedReader(new InputStreamReader(clienteSocket.getInputStream()));
            PrintWriter salida = new PrintWriter(clienteSocket.getOutputStream(), true);

            String mensajeRecibido = entrada.readLine();
            System.out.println("Mensaje recibido del cliente: " + mensajeRecibido);

            String mensajeRespuesta = "Hola, ¿qué tal?";
            salida.println(mensajeRespuesta);
            salida.flush(); 
            System.out.println("Mensaje enviado al cliente: " + mensajeRespuesta);

            entrada.close();
            salida.close();
            clienteSocket.close();
            servidorSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}