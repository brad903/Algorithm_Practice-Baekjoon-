package b12865;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class MainTest {

    @Test
    public void 배열_초기값_0인지_체크() {
        int[][] table = new int[4 + 1][7 + 1];
        assertThat(table[0][4]).isEqualTo(0);
    }
}