import java.util.*;

public class Main {
    // Classe auxiliar para representar o retorno em formato (booleano, inteiro)
    static class Result {
        boolean found;
        int position;

        Result(boolean found, int position) {
            this.found = found;
            this.position = position;
        }
    }

    public static Result betterSearch(List<Integer> arr, int value) {
        return new Result(false, 0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] tokens = sc.nextLine().split(" ");
        List<Integer> vet = new ArrayList<>();
        for (int i = 1; i < tokens.length - 1; i++) {
            vet.add(Integer.parseInt(tokens[i]));
        }
        int value = Integer.parseInt(sc.nextLine());
        Result result = betterSearch(vet, value);
        System.out.println((result.found ? "V" : "F") + " " + result.position);
        sc.close();
    }
}
