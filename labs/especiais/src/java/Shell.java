import java.util.Scanner;
import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

class Pair {
    Integer first;
    Integer second;

    Pair(Integer first, Integer second) {
        this.first = first;
        this.second = second;
    }

    public String toString() {
        return "(" + first + ", " + second + ")";
    }
};

class Student {
    public static List<Pair> occurr(List<Integer> vet) {
        // @DROP
        int size = vet.size();
        if (size == 0)
            return new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < size; i++) {
            int key = Math.abs(vet.get(i));
            if (map.containsKey(key))
                map.put(key, map.get(key) + 1);
            else
                map.put(key, 1);
        }
        List<Pair> output = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet())
            output.add(new Pair(entry.getKey(), entry.getValue()));
        return output;
        // @UNC
        // return new ArrayList<Pair>();
    }

    public static List<Pair> teams(List<Integer> vet) {
        // @DROP
        int size = vet.size();
        if (size == 0)
            return new ArrayList<>();
        List<Pair> output = new ArrayList<>();
        output.add(new Pair(vet.get(0), 1));
        for (int i = 1; i < size; i++) {
            if (output.get(output.size() - 1).first.equals(vet.get(i))) {
                int count = output.get(output.size() - 1).second;
                output.set(output.size() - 1, new Pair(vet.get(i), count + 1));
            } else
                output.add(new Pair(vet.get(i), 1));
        }
        return output;
        // @UNC
        // return new ArrayList<Pair>();
    }

    public static List<Integer> mnext(List<Integer> vet) {
        // @DROP
        int size = vet.size();
        List<Integer> output = new ArrayList<>();
        for (int i = 0; i < size; i++)
            if (vet.get(i) > 0 && (hasWoman(vet, size, i - 1) || hasWoman(vet, size, i + 1)))
                output.add(1);
            else
                output.add(0);
        return output;
        // @UNC
        // return new ArrayList<Integer>();
    }

    private static boolean hasWoman(List<Integer> vet, int size, int index) {
        // @DROP
        return index >= 0 && index < size && vet.get(index) < 0;
        // @UNC
        // return true;
    }

    public static List<Integer> alone(List<Integer> vet) {
        // @DROP
        int size = vet.size();
        List<Integer> output = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            if (vet.get(i) > 0 && (!hasWoman(vet, size, i - 1) && !hasWoman(vet, size, i + 1))) {
                output.add(1);
            } else {
                output.add(0);
            }
        }
        return output;
        // @UNC
        // return new ArrayList<Integer>();
    }

    public static int couple(List<Integer> vet) {
        // @DROP
        int qtd = 0;
        int size = vet.size();
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (vet.get(i) != 0 && vet.get(j) != 0 && vet.get(j).equals(-vet.get(i))) {
                    vet.set(i, 0);
                    vet.set(j, 0);
                    qtd++;
                }
            }
        }
        return qtd;
        // @UNC
        // return 0;
    }

    public static boolean hasSubseq(List<Integer> vet, List<Integer> seq, int pos) {
        // @DROP
        for (int i = 0; i < seq.size(); i++)
            if (pos + i >= vet.size() || !vet.get(pos + i).equals(seq.get(i)))
                return false;
        return true;
        // @UNC
        // return true;
    }

    public static int subseq(List<Integer> vet, List<Integer> seq) {
        // @DROP
        int vetSize = vet.size();
        for (int i = 0; i < vetSize; i++)
            if (hasSubseq(vet, seq, i))
                return i;
        return -1;
        // @UNC
        // return -1;
    }

    public static List<Integer> erase(List<Integer> vet, List<Integer> pos_list) {
        // @DROP
        List<Integer> output = new ArrayList<>();
        for (int i = 0; i < vet.size(); i++) {
            if (!pos_list.contains(i)) {
                output.add(vet.get(i));
            }
        }
        return output;
        // @UNC
        // return new ArrayList<Integer>();
    }

    public static List<Integer> clear(List<Integer> vet, int value) {
        // @DROP
        List<Integer> output = new ArrayList<>();
        for (int elem : vet) {
            if (elem != value) {
                output.add(elem);
            }
        }
        return output;
        // @UNC
        // return new ArrayList<Integer>();
    }
}

public class Shell {
    public static void main(String[] _args) {
        while (true) {
            var line = scanner.nextLine();
            var args = line.split(" ");
            System.out.println('$' + line);

            if (args[0].equals("end")) {
                break;
            }
            else if (args[0].equals("occurr")) {
                var array = strToVet(args[1]);
                System.out.println("" + Student.occurr(array));
            }
            else if (args[0].equals("teams")) {
                var array = strToVet(args[1]);
                System.out.println("" + Student.teams(array));
            }
            else if (args[0].equals("mnext")) {
                var array = strToVet(args[1]);
                System.out.println("" + Student.mnext(array));
            }
            else if (args[0].equals("alone")) {
                var array = strToVet(args[1]);
                System.out.println("" + Student.alone(array));
            }
            else if (args[0].equals("erase")) {
                var array = strToVet(args[1]);
                var positions = strToVet(args[2]);
                System.out.println("" + Student.erase(array, positions));
            }
            else if (args[0].equals("clear")) {
                var array = strToVet(args[1]);
                var value = Integer.parseInt(args[2]);
                System.out.println("" + Student.clear(array, value));
            }
            else if (args[0].equals("subseq")) {
                var array = strToVet(args[1]);
                var seq = strToVet(args[2]);
                System.out.println("" + Student.subseq(array, seq));
            }
            else if (args[0].equals("couple")) {
                var array = strToVet(args[1]);
                System.out.println("" + Student.couple(array));
            }
            else {
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
