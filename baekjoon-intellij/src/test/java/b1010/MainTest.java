package b1010;

import org.junit.Test;

import static org.junit.Assert.*;
import static org.assertj.core.api.Assertions.assertThat;

public class MainTest {
    Main main = new Main();

    @Test
    public void factoryMethod() {
        assertThat(Main.factoryMethod(4)).isEqualTo(24);
    }

    @Test
    public void factoryMethod2() {
        System.out.println(Main.factoryMethod(20));
    }

    @Test
    public void upperPart() {
        System.out.println(Main.upperPart(7, 5));
    }
}