import java.util.Scanner;

public class RoundRobin {

    private int n;
    private int[] Ex;
    private int[] T;
    private int[] W;
    private int quantum;

    public RoundRobin() {
        set();
    }

    public RoundRobin(int n) {
        this.n = n;
        Ex = new int[n];
        T = new int[n];
        W = new int[n];
        Scanner input = new Scanner(System.in);
        System.out.println("Enter time quantum : ");
        this.quantum = input.nextInt();
        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            Ex[i] = input.nextInt();
        }
        input.close();
        System.out.println();
    }

    private void set() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter time quantum : ");
        this.quantum = input.nextInt();
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
        for(int i = 0; i < n; i++)
            T[i] = Ex[i] + W[i];
    }
    
    private void calcWaitTime() {
        int remExT[] = new int[n];
        for(int i = 0; i < n; i++)
            remExT[i] = Ex[i];
        int currTime = 0;

        while(true) {
            boolean done = true;
            for(int i = 0; i < n; i++) {
                if(remExT[i] > 0) {
                    done = false;
                    if(remExT[i] > quantum) {
                        currTime += quantum;
                        remExT[i] -= quantum;
                    }
                    else {
                        currTime += quantum;
                        W[i] = currTime - Ex[i];
                        remExT[i] = 0;
                    }
                }
            }
            if(done)
                break;
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
        RoundRobin rr = new RoundRobin();
        rr.getSchedule();
        System.out.println("Average waiting time : " + rr.getAvgWaitingTime());
    }
}