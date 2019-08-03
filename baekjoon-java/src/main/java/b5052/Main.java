package b5052;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    static Set<String> hash = new HashSet<>();

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int testCount = scan.nextInt();

        for (int i = 0; i < testCount; i++) {
            int phoneNumCount = scan.nextInt();
            for (int j = 0; j < phoneNumCount; j++) {
                hash.add(scan.next());
            }

            try {
                phoneNumCheck();
                System.out.println("YES");
            } catch(IllegalArgumentException e) {
                System.out.println("NO");
            }

            hash.clear();
        }
    }

    private static void phoneNumCheck() {
        for (String s : hash.toArray(new String[hash.size()])) {
            String temp = s;
            hash.remove(s);
            for (int i = 0; i < temp.length(); i++) {
                if(hash.contains(temp.substring(0, i + 1))){
                    throw new IllegalArgumentException();
                }
            }
            hash.add(temp);
        }   
    }

}
