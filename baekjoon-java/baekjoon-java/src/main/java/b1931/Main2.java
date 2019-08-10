package b1931;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;

public class Main2 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Queue<Meeting> meetings = getMeetings(n, br);

        int answer = 0;
        int curTime = 0;
        while (!meetings.isEmpty()) {
            Meeting meeting = meetings.poll();

            if (meeting.start >= curTime) {
                curTime = meeting.end;
                answer++;
            }
        }

        System.out.println(answer);
    }

    private static Queue<Meeting> getMeetings(int n, BufferedReader br) throws IOException {
        Queue<Meeting> meetings = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            int[] arr = toArray(br.readLine());
            meetings.add(new Meeting(arr[0], arr[1]));
        }
        return meetings;
    }

    private static int[] toArray(String readLine) {
        String[] arr = readLine.split(" ");
        return new int[]{Integer.parseInt(arr[0]), Integer.parseInt(arr[1])};
    }

    static class Meeting implements Comparable<Meeting> {
        private int start;
        private int end;
        private int gap;

        public Meeting(int start, int end) {
            this.start = start;
            this.end = end;
            this.gap = end - start;
        }

        @Override
        public int compareTo(Meeting o) {
            if (this.end == o.end) {
                return this.start - o.start;
            }
            return this.end - o.end;
        }

        @Override
        public String toString() {
            return "[" +
                    "start=" + start +
                    ", end=" + end +
                    ", gap=" + gap +
                    ']';
        }
    }
}
