package b5639;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            Node root = new Node(Integer.parseInt(br.readLine()), null);
            String input = br.readLine();
            while (input != null) {
                int value = Integer.parseInt(input);
                root = root.addValue(value);
                input = br.readLine();
            }
            root = backToRoot(root);
            travel(root);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void travel(Node root) {
        if (root.left != null) travel(root.left);
        if (root.right != null) travel(root.right);
        System.out.println(root.value);
    }

    private static Node backToRoot(Node root) {
        while (root.root != null) {
            root = root.root;
        }
        return root;
    }

    public static class Node {
        private int value;
        private Node root;
        private Node left;
        private Node right;

        public Node(int value, Node root) {
            this.value = value;
            this.root = root;
            this.left = null;
            this.right = null;
        }

        public Node addValue(int value) {
            if (value < this.value) {
                return this.left = new Node(value, this);
            }
            if (root != null && value > this.root.value) {
                return this.root.addValue(value);
            }
            if (value > this.value) {
                return this.right = new Node(value, this);
            }
            return this;
        }
    }
}
