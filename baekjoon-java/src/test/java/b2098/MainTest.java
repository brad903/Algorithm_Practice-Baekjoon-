package b2098;

import org.junit.Test;

public class MainTest {

    @Test
    public void test() {
        int visit = 6;
        int i = 2;

        int result = visit & (1 << i);
        System.out.println(result);
        System.out.println((1 << i));
    }

    @Test
    public void test2() {
        int n = 6;
    }
}