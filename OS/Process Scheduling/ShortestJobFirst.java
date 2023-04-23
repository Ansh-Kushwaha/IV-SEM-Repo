import java.util.*;

public class ShortestJobFirst {
    
    private int n;
    private String[] id;
    private int[] Ex;
    private int[] T;
    private int[] W;

    public ShortestJobFirst() {
        set();
    }

    public ShortestJobFirst(int n) {
        this.n = n;
        id = new String[n];
        Ex = new int[n];
        T = new int[n];
        W = new int[n];
        Scanner input = new Scanner(System.in);
        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            id[i] = "P" + Integer.toString(i + 1);
            Ex[i] = input.nextInt();
        }
        input.close();
        System.out.println();
    }

    private void set() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of processes: ");
        n = input.nextInt();
        id = new String[n];
        Ex = new int[n];
        T = new int[n];
        W = new int[n];
        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            id[i] = "P" + Integer.toString(i + 1);
            Ex[i] = input.nextInt();
        }
        input.close();
        System.out.println();
    }

    private void calcTurnoverTime() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                T[i] += Ex[j];
            }
        }
    }

    private void calcWaitTime() {
        for(int i = 0; i < n; i++) {
            W[i] = T[i] - Ex[i];
        }
    }

    public double getAvgWaitingTime() {
        int totalWaitTime = 0;
        for(int wT : W)
            totalWaitTime += wT;
        return (double) totalWaitTime / n;
    }

    public void getSchedule() {
        // Sorting processes according to their execution time
        for(int i = 0; i < n - 1; i++) {
            int idx = i;
            for(int j = i + 1; j < n; j++) {
                if(Ex[j] < Ex[i])
                    idx = j;
            }
            if(idx != i) {
                String t1 = id[i];
                id[i] = id[idx];
                id[idx] = t1;
                int t2 = Ex[i];
                Ex[i] = Ex[idx];
                Ex[idx] = t2;
            }
        }
        calcTurnoverTime();
        calcWaitTime();
        System.out.println("Process\tEx(t)\tT(t)\tW(t)");
        for(int i = 0; i < n; i++)
            System.out.println(id[i] + "\t" + Ex[i] + "\t" + T[i] + "\t" + W[i]);
        System.out.println();
    }

    public static void main(String[] args) {
        ShortestJobFirst sjf = new ShortestJobFirst();
        sjf.getSchedule();
        System.out.println("Average waiting time : " + sjf.getAvgWaitingTime());
    }
}