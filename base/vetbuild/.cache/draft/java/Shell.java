import java.util.Scanner;
import java.util.Arrays;

public class Shell {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Vector v = new Vector(0);

        while (true) {
            System.out.print("$");
            if (!scanner.hasNextLine())
                break;
            String line = scanner.nextLine();
            System.out.println(line);
            String[] parts = line.trim().split("\\s+");
            if (parts.length == 0)
                continue;
            String cmd = parts[0];

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("init")) {
                // int cap = Integer.parseInt(parts[1]);
                // v = new Vector(cap);
            } else if (cmd.equals("push")) {
                // for (int i = 1; i < parts.length; i++) {
                //     int val = Integer.parseInt(parts[i]);
                //     v.pushBack(val);
                // }
            } else if (cmd.equals("show")) {
                // System.out.println(v);
            } else if (cmd.equals("status")) {
                // System.out.println(v.status());
            } else if (cmd.equals("pop")) {
                // v.popBack();
            } else if (cmd.equals("insert")) {
                // int idx = Integer.parseInt(parts[1]);
                // int val = Integer.parseInt(parts[2]);
                // v.insert(idx, val);
            } else if (cmd.equals("erase")) {
                // int id = Integer.parseInt(parts[1]);
                // v.erase(id);
            } else if (cmd.equals("indexOf")) {
                // int value = Integer.parseInt(parts[1]);
                // System.out.println(v.indexOf(value));
            } else if (cmd.equals("contains")) {
                // int cval = Integer.parseInt(parts[1]);
                // System.out.println(v.contains(cval));
            } else if (cmd.equals("clear")) {
                // v.clear();
            } else if (cmd.equals("capacity")) {
                // System.out.println(v.capacity());
            } else if (cmd.equals("get")) {
                // int gidx = Integer.parseInt(parts[1]);
                // Integer gval = v.at(gidx);
                // if (gval != null)
                //     System.out.println(gval);
            } else if (cmd.equals("set")) {
                // int sidx = Integer.parseInt(parts[1]);
                // int sval = Integer.parseInt(parts[2]);
                // v.set(sidx, sval);
            } else if (cmd.equals("reserve")) {
                // int ncap = Integer.parseInt(parts[1]);
                // v.reserve(ncap);
            } else {
                System.out.println("comando invalido");
            }
        }
        scanner.close();
    }
}
