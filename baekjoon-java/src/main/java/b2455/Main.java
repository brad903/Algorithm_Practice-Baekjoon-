package b2455;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int current = 0;
        String data = null;
        while ((data = br.readLine()) != null) {
            if ("".equals(data)) break;
            List<Integer> list = Arrays.stream(data.split(" "))
                    .map(Integer::parseInt)
                    .collect(Collectors.toList());

            current = current - list.get(0) + list.get(1);
            answer = Math.max(answer, current);
        }
        System.out.println(answer);
    }
}
