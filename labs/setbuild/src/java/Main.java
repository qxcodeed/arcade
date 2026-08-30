import java.util.*;
// @DROP

class Set {
    private int[] data;
    private int size;
    private int capacity;

    public Set(int capacity) {
        this.capacity = capacity;
        this.data = new int[capacity];
        this.size = 0;
    }

    private int binarySearch(int value) {
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (data[mid] == value)
                return mid;
            else if (data[mid] < value)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    public void insert(int value) {
        if (size == capacity)
            reserve(Math.max(1, capacity * 2));
        if (binarySearch(value) != -1)
            return;
        data[size++] = value;
        Arrays.sort(data, 0, size);
    }

    public boolean erase(int value) {
        int index = binarySearch(value);
        if (index == -1)
            return false;
        for (int i = index; i < size - 1; i++)
            data[i] = data[i + 1];
        size--;
        return true;
    }

    public boolean contains(int value) {
        return binarySearch(value) != -1;
    }

    private void reserve(int newCapacity) {
        if (newCapacity > capacity) {
            data = Arrays.copyOf(data, newCapacity);
            capacity = newCapacity;
        }
    }

    public void clear() {
        size = 0;
    }

    public String toString() {
        if (size == 0) return "[]";
        StringBuilder sb = new StringBuilder("[");
        sb.append(data[0]);
        for (int i = 1; i < size; i++) {
            sb.append(", ").append(data[i]);
        }
        sb.append("]");
        return sb.toString();
    }
}

// @KEEP
public class Main {
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        Set set = new Set(0); // @COM

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
                // @COM
                int capacity = Integer.parseInt(parts[1]);
                set = new Set(capacity);
            } else if (cmd.equals("insert")) {
                // @COM
                for (int i = 1; i < parts.length; i++) {
                    int val = Integer.parseInt(parts[i]);
                    // @DROP
                    set.insert(val);
                }
            } else if (cmd.equals("show")) {
                // @COM
                // @DROP
                System.out.println(set);
            } else if (cmd.equals("erase")) {
                // @COM
                int valErase = Integer.parseInt(parts[1]);
                // @DROP
                if (!set.erase(valErase)) {
                    System.out.println("value not found");
                }
            } else if (cmd.equals("contains")) {
                // @COM
                int valCheck = Integer.parseInt(parts[1]);
                // @DROP
                System.out.println(set.contains(valCheck));
            } else if (cmd.equals("clear")) {
                // @COM
                // @DROP
                set.clear();
            } else {
                System.out.println("comando invalido");
            }
        }
    }
}
