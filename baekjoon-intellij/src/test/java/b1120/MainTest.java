package b1120;

import org.junit.Test;

import static org.junit.Assert.*;

public class MainTest {

    @Test
    public void difference() {
        String text1 = "af";
        String text2 = "flkjaflasj";
        int start = 1;
        assertEquals(2, Main.findDifference(text1, text2, start));
    }

    @Test
    public void difference2() {
        String text1 = "af";
        String text2 = "flkjaflasj";
        int start = 4;
        assertEquals(0, Main.findDifference(text1, text2, start));
    }

    @Test
    public void difference3() {
        String text1 = "flsadfassj";
        String text2 = "flkjaflasj";
        int start = 0;
        assertEquals(5, Main.findDifference(text1, text2, start));
    }
}