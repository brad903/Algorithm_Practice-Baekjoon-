package b10974;

import org.junit.Test;

import java.util.*;

import static org.junit.Assert.*;

public class MainTest {
    int[] arr = {1,2,3,4};

    @Test
    public void swap() {
        Main.swap(arr, 2, 3);
        System.out.println(Arrays.toString(arr));
    }

    @Test
    public void permutation() {
        Main.permutation(arr, 0, 3, 5);
    }

    @Test
    public void test() {
        List<String> list = new ArrayList<>();
        String array1 = "[1 3 2]";
        String array2 = "[1 2 3]";
        list.add(array1);
        list.add(array2);
        Collections.sort(list);
        for (String s : list) {
            System.out.println(s);
        }
    }
}