public class Loop3 implements Runnable{

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