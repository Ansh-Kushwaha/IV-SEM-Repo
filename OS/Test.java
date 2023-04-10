class Test {
    public static void main(String[] args) {
        FCFS sc = new FCFS();
        sc.getSchedule();

        System.out.println("Average Waiting time : " + sc.getAvgWaitingTime());
    }
}