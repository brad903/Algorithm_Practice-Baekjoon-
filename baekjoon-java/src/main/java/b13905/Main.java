package b13905;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Main {
    static List<List<Graph>> graph;
    static boolean[] check;
    static int endNum;
    static List<Integer> answers = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] settingVal = Arrays.stream(br.readLine().split(" ")).mapToInt(s -> Integer.parseInt(s)).toArray();
        int vertexNum = settingVal[0];
        int edgeNum = settingVal[1];

        int[] startToEnd = Arrays.stream(br.readLine().split(" ")).mapToInt(s -> Integer.parseInt(s)).toArray();
        int startNum = startToEnd[0];
        endNum = startToEnd[1];

        graph = new ArrayList<>();
        check = new boolean[vertexNum + 1];
        for (int i = 0; i <= vertexNum; i++) {
            graph.add(new ArrayList<>());
            check[i] = false;
        }

        for (int i = 0; i < edgeNum; i++) {
            int[] vals = Arrays.stream(br.readLine().split(" ")).mapToInt(s -> Integer.parseInt(s)).toArray();
            graph.get(vals[0]).add(new Graph(vals[1], vals[2]));
            graph.get(vals[1]).add(new Graph(vals[0], vals[2]));
        }

        for (List<Graph> graphs : graph) {
            Collections.sort(graphs);  // 각 정점에서 가중치 큰 것 순서대로 정렬
        }

        dfs(startNum, 1000000);

        if(answers.isEmpty()) System.out.println(0);
        else System.out.println(Collections.max(answers));
    }

    static void dfs(int x, int min) {
        check[x] = true;
        for (int i = 0; i < graph.get(x).size(); i++) {
            if(!answers.isEmpty()) {  // answers에 더 큰수가 있으면 더이상 탐색말고 종료
                if(min <= Collections.max(answers)) return;
            }
            int tempEnd = graph.get(x).get(i).end;
            int tempWeight = graph.get(x).get(i).weight;
            int tempMin = Math.min(tempWeight, min);
            if(tempEnd == endNum) {
                answers.add(tempMin);
                return;
            }
            if(!check[tempEnd]) {
                dfs(tempEnd, tempMin);
                check[tempEnd] = false;
            }
        }
    }
}

class Graph implements Comparable {
    int weight;
    int end;

    public Graph(int end, int weight) {
        this.weight = weight;
        this.end = end;
    }

    @Override
    public int compareTo(Object o) {
        return ((Graph)o).weight - weight;
    }
}
