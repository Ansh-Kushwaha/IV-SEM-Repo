import java.util.*;

public class OptimalMergePattern {
    private static void merge(Integer[] arr1, Integer[] arr2, Integer[] arr3) {
        int i = 0, j = 0, k = 0;
        while (i < arr1.length && j < arr2.length) {
            if (arr1[1] <= arr2[j]) {
                arr3[k++] = arr1[i++];
            }
            else {
                arr3[k++] = arr2[j++];
            }
        }
        if (i == arr1.length)
            while (j < arr2.length)
                arr3[k++] = arr2[j++];
        else
            while (i < arr1.length)
                arr3[k++] = arr1[i++];
    }

    private static Integer[] optimalMerge(List<Integer[]> files) {
        PriorityQueue<Integer[]> pq = new PriorityQueue<>(files.size(),new Comparator<Integer[]>() {
            @Override
            public int compare(Integer[] f1, Integer[] f2) {
                if (f1.length < f2.length)
                    return 1;
                return -1;
            }
        });

        for (Integer[] f : files)
            pq.offer(f);
        
        while (pq.size() > 1) {
            Integer[] f1 = pq.poll();
            Integer[] f2 = pq.poll();
            System.out.println("Merged files of size : " + f1.length + " & " + f2.length);
            Integer[] merged = new Integer[f1.length + f2.length];
            merge(f1, f2, merged);
            pq.offer(merged);
        }
        
        return pq.poll();
    }

    public static void main(String[] agrs) {
        Integer[] a = {1, 2};
        Integer[] b = {4, 6, 7, 8};
        Integer[] c = {1};
        Integer[] d = {10, 13, 14, 29};
        Integer[] res;

        ArrayList<Integer[]> files = new ArrayList<>();
        files.add(a);
        files.add(b);
        files.add(c);
        files.add(d);

        res = optimalMerge(files);
        for (Integer n : res)
            System.out.print(n + " ");
        System.out.println();
    }
}
