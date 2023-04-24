import java.util.Scanner;

public class FCFS {

    private int n;
    private int[] ex;
    private int[] t;
    private int[] wt;

    public FCFS() {
        set();
    }

    public FCFS(int n) {
        this.n = n;
        ex = new int[n];
        t = new int[n];
        wt = new int[n];
        Scanner input = new Scanner(System.in);
        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            ex[i] = input.nextInt();
        }
        input.close();
        System.out.println();
    }

    private void set() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of processes: ");
        n = input.nextInt();
        ex = new int[n];
        t = new int[n];
        wt = new int[n];
        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            ex[i] = input.nextInt();
        }
        input.close();
        System.out.println();
    }

    private void calcTurnoverTime() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                t[i] += ex[j];
            }
        }
    }
    
    private void calcWaitTime() {
        for(int i = 0; i < n; i++) {
            wt[i] = t[i] - ex[i];
        }
    }
    
    public double getAvgWaitingTime() {
        int totalWaitTime = 0;
        for(int wT : wt)
            totalWaitTime += wT;
        return (double) totalWaitTime / n;
    }

    public void getSchedule() {
        calcTurnoverTime();
        calcWaitTime();
        System.out.println("Process\tEx(t)\tT(t)\tW(t)");
        for(int i = 0; i < n; i++)
            System.out.println("P" + (i + 1) + "\t" + ex[i] + "\t" + t[i] + "\t" + wt[i]);
        System.out.println();
    }


    public static void main(String[] args) {
        FCFS fcfs = new FCFS();
        fcfs.getSchedule();
        System.out.println("Average waiting time : " + fcfs.getAvgWaitingTime());
    }
}