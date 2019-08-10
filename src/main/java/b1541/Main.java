package b1541;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        List<String> splitted = splitWhole(input);

        int answer = 0;
        boolean wait = false;
        for (String s : splitted) {
            if (isOperator(s)) {
                if(s.equals("-")) wait = true;
                continue;
            }
            int sign = (wait)? -1 : 1;
            answer += (sign * Integer.parseInt(s));
        }

        System.out.println(answer);
    }

    private static boolean isOperator(String s) {
        return s.equals("-") || s.equals("+");
    }

    private static List<String> splitWhole(String input) {
        char[] chars = input.toCharArray();

        List<String> splitted = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        for (char aChar : chars) {
            if (isNumber(aChar)) {
                sb.append(aChar);
                continue;
            }
            splitted.add(sb.toString());
            sb.setLength(0);
            splitted.add(String.valueOf(aChar));
        }
        splitted.add(sb.toString());
        return splitted;
    }

    private static boolean isNumber(char aChar) {
        return aChar >= '0' && aChar <= '9';
    }
}