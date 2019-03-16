package b1931;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Queue<Meeting> meetings = getMeetings(n, br);

        int answer = 0;
        int remaining = -1;
        int time = 0;
        while (!meetings.isEmpty() || remaining >= 0) {
            boolean chekced = false;
            if (remaining < 0) {
                Meeting meeting = meetings.poll();
                remaining = meeting.gap;
                time = meeting.start;
            }

            while (!meetings.isEmpty() && meetings.peek().start == time) {
                Meeting mayChange = meetings.poll();
                if(mayChange.gap == 0) {
                    answer++;
                    chekced = true;
                }
                if (mayChange.gap < remaining) {
                    remaining = mayChange.gap;
                }
            }

            System.out.println(String.format("time : %d, remaining : %d, answer : %d", time, remaining, answer));

            if(!chekced && remaining == 0) answer++;
            remaining--;
            time++;
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
            return this.start - o.start;
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
