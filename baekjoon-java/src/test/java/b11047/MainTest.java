package b11047;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class MainTest {

    @Test
    public void 몫구하기() {
        int change = 4200;
        int coin = 1000;
        System.out.println(change / coin);
    }
}