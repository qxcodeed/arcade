import java.util.*;
public class Main {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        // Set set = new Set(0);

        while (true) {
            System.out.print("$");
            String line = scanner.nextLine();
            System.out.println(line);
            String[] parts = line.trim().split("\\s+");
            if (parts.length == 0) continue;

            String cmd = parts[0];

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("init")) {
                // int capacity = Integer.parseInt(parts[1]);
                // set = new Set(capacity);
            } else if (cmd.equals("insert")) {
                // for (int i = 1; i < parts.length; i++) {
                //     int val = Integer.parseInt(parts[i]);
                // }
            } else if (cmd.equals("show")) {
            } else if (cmd.equals("erase")) {
                // int valErase = Integer.parseInt(parts[1]);
            } else if (cmd.equals("contains")) {
                // int valCheck = Integer.parseInt(parts[1]);
            } else if (cmd.equals("clear")) {
            } else {
                System.out.println("comando invalido");
            }
        }
    }
}
