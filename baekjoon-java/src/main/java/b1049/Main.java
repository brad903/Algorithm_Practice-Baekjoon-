package b1049;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static final int PIECE_PER_BOX = 6;
    private static int piecePrice = 1000;
    private static int boxPrice = 1000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] metaData = br.readLine().split(" ");
        int brokenNum = Integer.parseInt(metaData[0]);
        int brandNum = Integer.parseInt(metaData[1]);
        int price = 0;
        findOptimalPrice(br, brandNum);

        while (brokenNum > 0) {
            if (brokenNum >= PIECE_PER_BOX) {
                int boxNum = brokenNum / PIECE_PER_BOX;
                price += Math.min(boxPrice * boxNum, piecePrice * PIECE_PER_BOX * boxNum);
                brokenNum -= boxNum * PIECE_PER_BOX;
                continue;
            }
            price += Math.min(boxPrice, piecePrice * brokenNum);
            brokenNum = 0;
        }

        bw.write(price + "\n");
        bw.close();
    }

    private static void findOptimalPrice(BufferedReader br, int brandNum) throws IOException {
        for (int i = 0; i < brandNum; i++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            boxPrice = Math.min(boxPrice, Integer.parseInt(stk.nextToken()));
            piecePrice = Math.min(piecePrice, Integer.parseInt(stk.nextToken()));
        }
    }
}
