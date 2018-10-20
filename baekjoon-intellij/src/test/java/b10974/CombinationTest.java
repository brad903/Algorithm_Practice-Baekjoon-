package b10974;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class CombinationTest {

    @Test
    public void permutation() {
        List<int[]> list = new ArrayList<>();
        int[] test1 = {1, 2, 3};
        int[] test2 = {1, 2, 3};
        list.add(test1);
        list.add(test2);

        System.out.println(list.get(0).equals(list.get(1)));
    }
}