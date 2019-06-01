package b1120;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stringTokenizer = new StringTokenizer(br.readLine());
        String text1 = stringTokenizer.nextToken();
        String text2 = stringTokenizer.nextToken();

        int count = text2.length() - text1.length() + 1;
        int answer = text2.length();
        for (int i = 0; i < count; i++) {
            answer = Math.min(answer, findDifference(text1, text2, i));
        }
        System.out.println(answer);
    }

    public static int findDifference(String text1, String text2, int start) {
        int count = 0;
        for (int i = 0; i < text1.length(); i++) {
            if(text1.charAt(i) != text2.charAt(start + i)) count++;
        }
        return count;
    }
}
