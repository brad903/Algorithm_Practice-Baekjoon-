package b4673;

import org.junit.Test;

import static org.junit.Assert.*;

public class MainTest {

    @Test
    public void getSumOfDigits() {
        assertEquals(7, Main.getSumOfDigits(223));
    }
}