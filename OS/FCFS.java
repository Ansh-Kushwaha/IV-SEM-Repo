import java.util.Scanner;

public class FCFS {
    private int n;
    private int[] Ex;
    private int[] T;
    private int[] W;

    public FCFS() {
        set();
    }

    public FCFS(int n) {
        this.n = n;
        Ex = new int[n];
        T = new int[n];
        W = new int[n];
        Scanner input = new Scanner(System.in);
        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            Ex[i] = input.nextInt();
        }
        input.close();
        System.out.println();
    }

    private void set() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of processes: ");
        n = input.nextInt();
        Ex = new int[n];
        T = new int[n];
        W = new int[n];
        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            Ex[i] = input.nextInt();
        }
        input.close();
        System.out.println();
    }

    public void getTurnoverTime() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                T[i] += Ex[j];
            }
        }
        System.out.println("Turnover time of each process :");
        System.out.println("\tProcess" + "\tTime");
        for(int i = 0; i < n; i++)
            System.out.println("\tP" + (i + 1) + "\t" + T[i]);
        System.out.println();
    }

    public void getProcessWaitingTime() {
        System.out.println("Waiting time of each process :");
        System.out.println("\tProcess" + "\tTime");
        for(int i = 0; i < n; i++) {
            W[i] = T[i] - Ex[i];
            System.out.println("\tP" + (i + 1) + "\t" + W[i]);
        }
        System.out.println();
    }

    public double getAvgWaitingTime() {
        int totalWaitTime = 0;
        for(int wT : W)
            totalWaitTime += wT;
        return (double) totalWaitTime / n;
    }

}