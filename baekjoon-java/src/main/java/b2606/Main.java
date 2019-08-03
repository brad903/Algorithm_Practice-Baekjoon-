package b2606;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static Map<Integer, List<Integer>> linkInfo;
    private static boolean[] visit;

    public static void main(String[] args) {
        try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(br.readLine());
            int linkCount = Integer.parseInt(br.readLine());
            visit = new boolean[n + 1];
            linkInfo = getLinkInfo(br, linkCount);

            int answer = 0;
            Queue<Integer> queue = new LinkedList<>();
            queue.add(1);
            visit[1] = true;
            while(!queue.isEmpty()) {
                List<Integer> value = linkInfo.get(queue.poll());
                for (Integer num : value) {
                    if(visit[num]) continue;
                    queue.add(num);
                    visit[num] = true;
                    answer++;
                }
            }

            System.out.println(answer);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static Map<Integer, List<Integer>> getLinkInfo(BufferedReader br, int linkCount) throws IOException {
        Map<Integer, List<Integer>> localLinkInfo = new HashMap<>();
        for (int i = 0; i < linkCount; i++) {
            int[] nums = getNums(br);
            putNums(nums[0], nums[1], localLinkInfo);
            putNums(nums[1], nums[0], localLinkInfo);
        }
        return localLinkInfo;
    }

    private static void putNums(int num1, int num2, Map<Integer, List<Integer>> localLinkInfo) {
        List<Integer> value = localLinkInfo.getOrDefault(num1, new ArrayList<>());
        if(value.contains(num2)) return;
        value.add(num2);
        localLinkInfo.put(num1, value);
    }

    private static int[] getNums(BufferedReader br) throws IOException {
        return Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
    }
}
