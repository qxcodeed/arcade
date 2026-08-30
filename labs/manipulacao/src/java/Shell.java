import java.util.Arrays;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Shell {
    static List<Integer> get_men(List<Integer> vet) {
        // @DROP
        List<Integer> unique = new ArrayList<Integer>();
        for (int elem : vet) {
            if (elem > 0) {
                unique.add(elem);
            }
        }
        return unique;
        // @UNC
        // return new ArrayList<>();
    }

    static List<Integer> get_calm_women(List<Integer> vet) {
        // @DROP
        List<Integer> unique = new ArrayList<Integer>();
        for (int elem : vet) {
            if (elem < 0 && Math.abs(elem) < 10) {
                unique.add(elem);
            }
        }
        return unique;
        // @UNC
        // return new ArrayList<>();
    }

    static List<Integer> sort(List<Integer> vet) {
        // @DROP
        Collections.sort(vet);
        return vet;
        // @UNC
        // return new ArrayList<>();
    }

    static List<Integer> sort_stress(List<Integer> vet) {
        // @DROP
        Collections.sort(vet, (a, b) -> Integer.compare(Math.abs(a), Math.abs(b)));
        return vet;
        // @UNC
        // return new ArrayList<>();
    }

    static List<Integer> reverse(List<Integer> vet) {
        // @DROP
        var other = new ArrayList<Integer>();
        for (int i = vet.size() - 1; i >= 0; i--) {
            other.add(vet.get(i));
        }
        return other;
        // @UNC
        // return new ArrayList<>();
    }

    static boolean exists(List<Integer> vet, int value) {
        // @DROP
        return vet.contains(value);
        // @UNC
        // return false;
    }

    static List<Integer> unique(List<Integer> vet) {
        // @DROP
        List<Integer> unique = new ArrayList<Integer>();
        for (int elem : vet) {
            if (!exists(unique, elem)) {
                unique.add(elem);
            }
        }
        return unique;
        // @UNC
        // return new ArrayList<>();
    }

    static List<Integer> repeated(List<Integer> vet) {
        // @DROP
        List<Integer> unique = new ArrayList<Integer>();
        List<Integer> repeated = new ArrayList<Integer>();

        for (int elem : vet) {
            if (!exists(unique, elem)) {
                unique.add(elem);
            } else {
                repeated.add(elem);
            }
        }
        return repeated;
        // @UNC
        // return new ArrayList<>();
    }

    public static void main(String[] _args) {
        while (true) {
            var line = scanner.nextLine();
            var args = line.split(" ");
            var cmd = args[0];
            System.out.println("$" + line);

            if (cmd.equals("end")) {
                break;
            } else if (cmd.equals("get_men")) {
                var array = strToVet(args[1]);
                System.out.println("" + get_men(array));
            } else if (cmd.equals("get_calm_women")) {
                var array = strToVet(args[1]);
                System.out.println("" + get_calm_women(array));
            } else if (cmd.equals("sort")) {
                var array = strToVet(args[1]);
                System.out.println("" + sort(array));
            } else if (cmd.equals("sort_stress")) {
                var array = strToVet(args[1]);
                System.out.println("" + sort_stress(array));
            } else if (cmd.equals("reverse")) {
                var array = strToVet(args[1]);
                var other = reverse(array);
                System.out.println("" + array);
                System.out.println("" + other);
            } else if (cmd.equals("exists")) {
                var array = strToVet(args[1]);
                var value = Integer.parseInt(args[2]);
                System.out.println("" + exists(array, value));
            } else if (cmd.equals("unique")) {
                var array = strToVet(args[1]);
                System.out.println("" + unique(array));
            } else if (cmd.equals("repeated")) {
                var array = strToVet(args[1]);
                System.out.println("" + repeated(array));
            } else {
                System.out.println("Invalid command");
            }
        }
    }

    public static List<Integer> strToVet(String s) {
        if (s.equals("[]"))
            return new ArrayList<>();
        List<String> parts = Arrays.asList(s.substring(1, s.length() - 1).split(","));
        List<Integer> result = new ArrayList<>();
        for (String part : parts)
            result.add(Integer.parseInt(part.trim()));
        return result;
    }

    static Scanner scanner = new Scanner(System.in);
}