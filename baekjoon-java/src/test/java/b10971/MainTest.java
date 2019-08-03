package b10971;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MainTest {

    @Test
    public void bitMove() {
        int N = 4;
        int result = 1 << 4;
        assertEquals(16, result);
    }

    @Test
    public void bitOr() {
        byte a = 0b1011;
        byte b = 0b100;
        assertEquals(15, a | b);
    }
}