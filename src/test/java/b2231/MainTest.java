package b2231;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class MainTest {

    @Test
    public void validateTest() {
        assertEquals(213, Main.getSum(210));
    }
}