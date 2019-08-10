package b1753;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static int V, E, K;
    private static ArrayList<Node>[] map;
    private static int[] distance;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        V = Integer.parseInt(stk.nextToken());
        E = Integer.parseInt(stk.nextToken());
        K = Integer.parseInt(br.readLine());
        init(br);

        dijkstra();

        for (int i = 1; i <= V; i++) {
            System.out.println(
                    distance[i] == Integer.MAX_VALUE ? "INF" : distance[i]
            );
        }
    }

    private static void dijkstra() {
        Queue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(K, 0));

        while (!queue.isEmpty()) {
            Node now = queue.poll();

            for (Node next : map[now.dest]) {
                if (distance[next.dest] > distance[now.dest] + next.weight) {
                    distance[next.dest] = distance[now.dest] + next.weight;
                    queue.add(new Node(next.dest, distance[next.dest]));
                }
            }
        }
    }

    private static void init(BufferedReader br) throws IOException {
        map = new ArrayList[V + 1];
        distance = new int[V + 1];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[K] = 0;

        for (int i = 1; i <= V; i++) {
            map[i] = new ArrayList<>();
        }

        for (int i = 0; i < E; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(stk.nextToken());
            int next = Integer.parseInt(stk.nextToken());
            int weight = Integer.parseInt(stk.nextToken());
            map[start].add(new Node(next, weight));
        }
    }

    private static class Node implements Comparable<Node> {
        private int dest;
        private int weight;

        public Node(int dest, int weight) {
            this.dest = dest;
            this.weight = weight;
        }

        @Override
        public int compareTo(Node o) {
            return this.weight - o.weight;
        }

    }
}
