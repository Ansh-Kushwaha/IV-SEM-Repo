// Java program to implement solution of readers writers problem.

public class ReadersWriters {

    public static void main(String[] args) throws InterruptedException {
        final RW rw = new RW();

        Thread t1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    rw.write();
                }
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread t2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    rw.read(Thread.currentThread().getId());
                }
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread t3 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    rw.read(Thread.currentThread().getId());
                }
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread t4 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    rw.read(Thread.currentThread().getId());
                }
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        t1.start();
        t2.start();
        t3.start();
        t4.start();

        t1.join();
        t2.join();
        t3.join();
        t4.join();
    }
    
    public static class RW {
        int mutex = 1, wrt = 1, readCnt = 0;

        public void write() throws InterruptedException {
            while (true) {
                synchronized (this) {
                    if (wrt == 0)
                        wait();
                    System.out.println("Writer is writing");
                    
                    wrt++;
                    notify();
                    Thread.sleep(250);
                }
            }
        }

        public void read(long id) throws InterruptedException {
            while (true) {
                synchronized (this) {
                    if (wrt == 0 || mutex == 0)
                        wait();
                    
                    readCnt++;
                    if (readCnt == 1) {
                        wait();
                        wrt--;
                    }
                    if (mutex == 0) {
                        notifyAll();
                        mutex++;
                    }

                    System.out.println("Reader " + id + " is reading");

                    if (mutex == 0)
                        wait();
                    readCnt--;

                    if (readCnt == 0)
                        wrt++;
                    if (mutex == 0)
                        mutex++;
                    Thread.sleep(250);    
                }
            }
        }

        private void wait(int s) {
            while(s <= 0);
            s--;
        }

        private void signal(int s) {
            s++;
        }
    }
}
