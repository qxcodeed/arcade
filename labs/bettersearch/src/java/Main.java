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
        // @UNC
        // return new Result(false, 0);
        // @DROP
        int low = 0, high = arr.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (arr.get(mid) == value) {
                return new Result(true, mid);
            } else if (arr.get(mid) < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return new Result(false, low);
    }

    // @KEEP
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
