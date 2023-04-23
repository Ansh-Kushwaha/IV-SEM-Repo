class Loop1 implements Runnable{
    @Override
    public void run() {
        while(true) {
            try {
                System.out.println("Loop 1");
                Thread.sleep(50);
            } catch(InterruptedException e) {
                System.out.println("Thread " + this + " interrupted.");
            }
        }
    }
}

class Loop2 implements Runnable{

    @Override
    public void run() {
        while(true) {
            try {
                System.out.println("Loop 2");
                Thread.sleep(50);
            } catch(InterruptedException e) {
                System.out.println("Thread " + this + " interrupted.");
            }
        }
    }
}

class Loop3 implements Runnable{

    @Override
    public void run() {
        while(true) {
            try {
                System.out.println("Loop 3");
                Thread.sleep(50);
            } catch(InterruptedException e) {
                System.out.println("Thread " + this + " interrupted.");
            }
        }
    }
}

public class MultithreadingLoops {
    public static void main(String[] args) {
        Thread lt1 = new Thread(new Loop1());
        Thread lt2 = new Thread(new Loop2());
        Thread lt3 = new Thread(new Loop3());

        lt1.start();
        lt2.start();
        lt3.start();
    }
}