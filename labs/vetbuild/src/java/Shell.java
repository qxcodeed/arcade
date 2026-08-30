import java.util.Scanner;
import java.util.Arrays;

// @DROP
class MyArrayList {
    private int[] data;            // Guarda os elementos do vetor
    private int size;              // Guarda o número atual de elementos
    private int capacity;          // Guarda a capacidade atual do vetor

    public MyArrayList(int capacity) {  // Cria um novo vetor
        this.data = new int[capacity];
        this.size = 0;
        this.capacity = capacity;
    }

    public int len() {
        return size;
    }

    public int cap() {
        return capacity;
    }

    
    public void add(int value) {  // Adiciona um valor ao final
        if (size == capacity) {
            ensureCapacity(Math.max(1, capacity * 2));
        }
        data[size++] = value;
    }

    public boolean removeLast() {  // Remove o último elemento
        if (size == 0) {
            System.out.println("vector is empty");
            return false;
        }
        size--;
        return true;
    }

    public boolean add(int index, int value) {
        if (index < 0 || index > size) {
            System.out.println("index out of range");

        }
        if (size == capacity) {
            ensureCapacity(Math.max(1, capacity * 2));
        }
        System.arraycopy(data, index, data, index + 1, size - index);
        data[index] = value;
        size++;
        return true;
    }

    public boolean remove(int index) {
        if (index < 0 || index >= size) {
            System.out.println("index out of range");
            return false;
        }
        System.arraycopy(data, index + 1, data, index, size - index - 1);
        size--;
        return true;
    }

    public int indexOf(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value)
                return i;
        }
        return -1;
    }

    public boolean contains(int value) {
        return indexOf(value) != -1;
    }

    public void ensureCapacity(int newCapacity) {
        if (newCapacity > capacity) {
            data = Arrays.copyOf(data, newCapacity);
            capacity = newCapacity;
        }
    }

    public int getSize() {
        return size;
    }

    public int getCapacity() {
        return capacity;
    }

    public String getStatus() {
        return String.format("size:%d capacity:%d", size, capacity);
    }

    @Override
    public String toString() {
        if (size == 0)
            return "[]";
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        sb.append(data[0]);
        for (int i = 1; i < size; i++) {
            sb.append(", ").append(data[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    public int get(int index) {
        return data[index];
    }

    public Integer getAt(int index) {
        if (index < 0 || index >= size) {
            System.out.println("index out of range");
            return null;
        }
        return data[index];
    }

    public boolean set(int index, int value) {
        if (index < 0 || index >= size) {
            System.out.println("index out of range");
            return false;
        }
        data[index] = value;
        return true;
    }

    public void clear() {
        size = 0;
    }

    public MyArrayList slice(int start, int end) {
        start = ((start % this.size) + this.size) % this.size;
        end = ((end % this.size) + this.size) % this.size;
        MyArrayList other = new MyArrayList(end - start);
        other.size = end - start;
        System.arraycopy(this.data, start, other.data, 0, end - start);
        return other;
    }
}

// @KEEP
public class Shell {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        MyArrayList v = new MyArrayList(0); // @COM

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
                // @COM
                int cap = Integer.parseInt(parts[1]);
                v = new MyArrayList(cap);
            } else if (cmd.equals("show")) {
                // @COM
                System.out.println(v);
            } else if (cmd.equals("status")) {
                // @COM
                System.out.println(v.getStatus());
            } else if (cmd.equals("pop")) {
                // @COM
                v.removeLast();
            } else if (cmd.equals("reserve")) {
                // @COM
                int ncap = Integer.parseInt(parts[1]);
                v.ensureCapacity(ncap);
            } else if (cmd.equals("push")) {
                // @COM
                for (int i = 1; i < parts.length; i++) {
                    int val = Integer.parseInt(parts[i]);
                    v.add(val);
                }
            } else if (cmd.equals("insert")) {
                // @COM
                int idx = Integer.parseInt(parts[1]);
                int val = Integer.parseInt(parts[2]);
                v.add(idx, val);
            } else if (cmd.equals("erase")) {
                // @COM
                int id = Integer.parseInt(parts[1]);
                v.remove(id);
            } else if (cmd.equals("indexOf")) {
                // @COM
                int value = Integer.parseInt(parts[1]);
                System.out.println(v.indexOf(value));
            } else if (cmd.equals("contains")) {
                // @COM
                int cval = Integer.parseInt(parts[1]);
                System.out.println(v.contains(cval));
            } else if (cmd.equals("clear")) {
                // @COM
                v.clear();
            } else if (cmd.equals("capacity")) {
                // @COM
                System.out.println(v.getCapacity());
            } else if (cmd.equals("get")) {
                // @COM
                int gidx = Integer.parseInt(parts[1]);
                Integer gval = v.getAt(gidx);
                if (gval != null)
                    System.out.println(gval);
            } else if (cmd.equals("set")) {
                // @COM
                int sidx = Integer.parseInt(parts[1]);
                int sval = Integer.parseInt(parts[2]);
                v.set(sidx, sval);
            } else if (cmd.equals("slice")) {
                // @COM
                int start = Integer.parseInt(parts[1]);
                int end = Integer.parseInt(parts[2]);
                MyArrayList sliced = v.slice(start, end);
                System.out.println(sliced);
            } else {
                System.out.println("comando invalido");
            }
        }
        scanner.close();
    }
}
