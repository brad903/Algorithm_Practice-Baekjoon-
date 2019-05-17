package b7344;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            int count = Integer.parseInt(br.readLine());
            String[] nums = br.readLine().split(" ");
            List<Point> points = init(count, nums);

            int answer = 0;
            while(!points.isEmpty()) {
                answer++;
                Iterator<Point> iterator = points.iterator();
                Point target = iterator.next();
                iterator.remove();
                while(iterator.hasNext()) {
                    Point next = iterator.next();
                    if(next.x >= target.x && next.y >= target.y) {
                        iterator.remove();
                    }
                }
            }
            System.out.println(answer);
        }
    }

    private static List<Point> init(int count, String[] nums) {
        List<Point> points = new ArrayList<>();
        int index = 0;
        for (int j = 0; j < count; j++) {
            points.add(new Point(nums[index++], nums[index++]));
        }
        Collections.sort(points);
        return points;
    }

    public static class Point implements Comparable<Point> {
        private int x;
        private int y;

        public Point(String x, String y) {
            this.x = Integer.parseInt(x);
            this.y = Integer.parseInt(y);
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }

        @Override
        public int compareTo(Point o) {
            if(this.x == o.x) return this.y - o.y;
            return this.x - o.x;
        }
    }
}
