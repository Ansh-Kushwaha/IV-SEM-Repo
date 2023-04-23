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
        calcTurnoverTime();
        calcWaitTime();
        System.out.println("Process\tEx(t)\tT(t)\tW(t)");
        for(int i = 0; i < n; i++)
            System.out.println("P" + (i + 1) + "\t" + Ex[i] + "\t" + T[i] + "\t" + W[i]);
        System.out.println();
    }


    public static void main(String[] args) {
        FCFS fcfs = new FCFS();
        fcfs.getSchedule();
        System.out.println("Average waiting time : " + fcfs.getAvgWaitingTime());
    }
}