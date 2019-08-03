package b1110;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String n = formatting(br.readLine());
        String newNum = n;
        int answer = 0;
        while (true) {
            int temp = 0;
            for (int i = 0; i < newNum.length(); i++) {
                temp += newNum.charAt(i) - '0';
            }
            StringBuilder sb = new StringBuilder();
            newNum = sb.append(getLast(newNum)).append(getLast(String.valueOf(temp))).toString();
            answer++;

            if (n.equals(newNum)) break;
        }

        System.out.println(answer);
    }

    private static String formatting(String readLine) {
        int num = Integer.parseInt(readLine);
        if (num < 10) return "0" + readLine;
        return readLine;
    }

    private static Character getLast(String text) {
        return text.charAt(text.length() - 1);
    }
}
