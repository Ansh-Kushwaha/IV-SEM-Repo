import java.util.*;

public class ShortestJobFirst {
    
    private int n;
    private Process []p;

    ShortestJobFirst() {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter number of Jobs : ");
        n = input.nextInt();
        p = new Process[n];

        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            p[i].exT = input.nextInt();
        }
        input.close();
    }

    ShortestJobFirst(int n) {
        this.n = n;
        p = new Process[n];
        Scanner input = new Scanner(System.in);

        for(int i = 0; i < n; i++) {
            System.out.print("Enter execution time of process " + (i + 1) + " : ");
            p[i] = new Process(i + 1, input.nextInt());
        }
        input.close();
    }

    public void calcAndDisplay() {
        Arrays.sort(p, new Comparator<Process>() {
            @Override
            public int compare(Process p1, Process p2) {
                return (p1.exT > p2.exT ? p1.exT : p2.exT);
            }
        });

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                p[i].toT += p[j].exT; // Turnover time
            }
            p[i].wT = p[i].toT - p[i].exT; // Waiting time
        }

        System.out.println("\tProcess\tE(t)\tT(t)\tW(t)");
        for(int i = 0; i < n; i++) {
            System.out.println("\tP" + p[i].id + "\t" + p[i].exT + "\t" + p[i].toT + "\t" + p[i].wT);
        }
    }

    public static void main(String[] args) {
        ShortestJobFirst sjf = new ShortestJobFirst();
    }
}