class Test {
    public static void main(String[] args) {
        FCFS sc = new FCFS();
        sc.getTurnoverTime();
        sc.getProcessWaitingTime();
        System.out.println("Average Waiting time : " + sc.getAvgWaitingTime());
    }
}