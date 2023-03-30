public class Test {
    public static void main(String[] args) {
        Thread lt1 = new Thread(new Loop1());
        Thread lt2 = new Thread(new Loop2());
        Thread lt3 = new Thread(new Loop3());

        lt1.start();
        lt2.start();
        lt3.start();
    }
}