import java.util.Scanner;
import java.util.Arrays;

public class Shell {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // MyArrayList v = new MyArrayList(0);

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
                // v = new MyArrayList(cap);
            } else if (cmd.equals("show")) {
                // System.out.println(v);
            } else if (cmd.equals("status")) {
                // System.out.println(v.getStatus());
            } else if (cmd.equals("pop")) {
                // v.removeLast();
            } else if (cmd.equals("reserve")) {
                // int ncap = Integer.parseInt(parts[1]);
                // v.ensureCapacity(ncap);
            } else if (cmd.equals("push")) {
                // for (int i = 1; i < parts.length; i++) {
                //     int val = Integer.parseInt(parts[i]);
                //     v.add(val);
                // }
            } else if (cmd.equals("insert")) {
                // int idx = Integer.parseInt(parts[1]);
                // int val = Integer.parseInt(parts[2]);
                // v.add(idx, val);
            } else if (cmd.equals("erase")) {
                // int id = Integer.parseInt(parts[1]);
                // v.remove(id);
            } else if (cmd.equals("indexOf")) {
                // int value = Integer.parseInt(parts[1]);
                // System.out.println(v.indexOf(value));
            } else if (cmd.equals("contains")) {
                // int cval = Integer.parseInt(parts[1]);
                // System.out.println(v.contains(cval));
            } else if (cmd.equals("clear")) {
                // v.clear();
            } else if (cmd.equals("capacity")) {
                // System.out.println(v.getCapacity());
            } else if (cmd.equals("get")) {
                // int gidx = Integer.parseInt(parts[1]);
                // Integer gval = v.getAt(gidx);
                // if (gval != null)
                //     System.out.println(gval);
            } else if (cmd.equals("set")) {
                // int sidx = Integer.parseInt(parts[1]);
                // int sval = Integer.parseInt(parts[2]);
                // v.set(sidx, sval);
            } else {
                System.out.println("comando invalido");
            }
        }
        scanner.close();
    }
}
