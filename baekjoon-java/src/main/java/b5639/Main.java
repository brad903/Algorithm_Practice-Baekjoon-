package b5639;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            Node root = new Node(Integer.parseInt(br.readLine()));
            String input;
            while ((input = br.readLine()) != null) {
                int value = Integer.parseInt(input);
                root = root.addValue(root, value);
            }
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

    public static class Node {
        private int value;
        private Node left;
        private Node right;

        public Node(int value) {
            this.value = value;
            this.left = null;
            this.right = null;
        }

        public Node addValue(Node node, int value) {
            if(node == null) return new Node(value);
            if (node.value > value) {
                node.left = addValue(node.left, value);
            }
            if (node.value < value) {
                node.right = addValue(node.right, value);
            }
            return node;
        }
    }
}
