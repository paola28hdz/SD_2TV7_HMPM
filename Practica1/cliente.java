import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Cliente {
    public static void main(String[] args) {
        try {
            Socket socket = new Socket("127.0.0.1", 12345);
            DataOutputStream salida = new DataOutputStream(socket.getOutputStream());
            DataInputStream entrada = new DataInputStream(socket.getInputStream());
            Scanner scanner = new Scanner(System.in);

            int numero;
            do {
                System.out.print("Ingresa un número (0 para salir): ");
                numero = scanner.nextInt();

                salida.writeInt(numero);

                if (numero != 0) {
                    int respuesta = entrada.readInt();
                    System.out.println("Servidor incrementó el número a: " + respuesta);
                }
            } while (numero != 0);

            socket.close();
            scanner.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
