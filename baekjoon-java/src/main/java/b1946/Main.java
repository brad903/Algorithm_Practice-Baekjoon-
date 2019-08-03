package b1946;

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
        int N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            int count = Integer.parseInt(br.readLine());
            List<Applicant> applicants = getApplicants(br, count);
            int pass = screenApplicants(applicants);
            System.out.println(pass);
        }
    }

    private static int screenApplicants(List<Applicant> applicants) {
        int pass = 0;
        int current = applicants.size();
        for (Applicant applicant : applicants) {
            if (applicant.interviewScore <= current) {
                current = applicant.interviewScore;
                pass++;
            }
        }
        return pass;
    }

    private static List<Applicant> getApplicants(BufferedReader br, int count) throws IOException {
        List<Applicant> applicants = new ArrayList<>();
        for (int j = 0; j < count; j++) {
            StringTokenizer stk = new StringTokenizer(br.readLine());
            applicants.add(new Applicant(stk.nextToken(), stk.nextToken()));
        }
        Collections.sort(applicants);
        return applicants;
    }

    public static class Applicant implements Comparable<Applicant> {
        private int paperScore;
        private int interviewScore;

        public Applicant(String paperScore, String interviewScore) {
            this.paperScore = Integer.parseInt(paperScore);
            this.interviewScore = Integer.parseInt(interviewScore);
        }

        @Override
        public int compareTo(Applicant o) {
            return paperScore - o.paperScore;
        }
    }
}
