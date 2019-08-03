package b3048;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer stk = new StringTokenizer(br.readLine());
        int leftCount = Integer.parseInt(stk.nextToken());
        int rightCount = Integer.parseInt(stk.nextToken());
        List<Ant> ants = getAnts(br);

        int time = Integer.parseInt(br.readLine());
        while (time-- != 0) {
            List<Integer> swapIndex = new ArrayList<>();
            for (int i = 0; i < ants.size() - 1; i++) {
                if (ants.get(i).shouldJump(ants.get(i + 1))) {
                    swapIndex.add(i);
                }
            }
            for (Integer index : swapIndex) {
                Collections.swap(ants, index, index + 1);
            }
        }

        StringBuilder sb = new StringBuilder();
        for (Ant ant : ants) {
            sb.append(ant.getName());
        }
        System.out.println(sb.toString());
    }

    private static List<Ant> getAnts(BufferedReader br) throws IOException {
        List<Ant> ants = new ArrayList<>();
        ants.addAll(parseAnts(br.readLine(), Direction.LEFT_TO_RIGHT));
        ants.addAll(parseAnts(br.readLine(), Direction.RIGHT_TO_LEFT));
        return ants;
    }

    private static List<Ant> parseAnts(String antsLine, Direction direction) {
        List<Ant> ants = new ArrayList<>();
        String[] parsed = antsLine.split("");
        for (String s : parsed) {
            ants.add(new Ant(s, direction));
        }
        if (direction.equals(Direction.LEFT_TO_RIGHT)) Collections.reverse(ants);
        return ants;
    }

    public static class Ant {
        private String name;
        private Direction direction;

        public Ant(String name, Direction direction) {
            this.name = name;
            this.direction = direction;
        }

        public String getName() {
            return name;
        }

        public Direction getDirection() {
            return direction;
        }

        public boolean shouldJump(Ant other) {
            return this.direction == Direction.LEFT_TO_RIGHT && other.direction == Direction.RIGHT_TO_LEFT;
        }

        @Override
        public String toString() {
            return "Ant{name='" + name + ", direction=" + direction + '}';
        }
    }

    enum Direction {
        LEFT_TO_RIGHT,
        RIGHT_TO_LEFT;
    }
}
