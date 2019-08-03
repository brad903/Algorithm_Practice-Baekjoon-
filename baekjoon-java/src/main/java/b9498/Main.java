package b9498;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static Map<Integer, String> grades = new HashMap<>();

    static {
        grades.put(10, "A");
        grades.put(9, "A");
        grades.put(8, "B");
        grades.put(7, "C");
        grades.put(6, "D");
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine()) / 10;
        if(grades.containsKey(num)) System.out.println(grades.get(num));
        else System.out.println("F");
    }
}
