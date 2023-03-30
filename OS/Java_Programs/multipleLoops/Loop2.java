public class Loop2 implements Runnable{

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