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
        int mutex = 1, rw_mutex = 1, readerCnt = 0;

        public void write() throws InterruptedException {
            while (true) {
                synchronized (this) {
                    wait(rw_mutex);
                    System.out.println("Writer is writing.");
                    signal(rw_mutex);
                }
            }
        }

        public void read(long id) throws InterruptedException {
            while (true) {
                synchronized (this) {
                    wait(mutex);
                    readerCnt++;
                    if (readerCnt == 1)
                        wait(rw_mutex);
                    signal(mutex);
                    System.out.println("Reader " + id + " is reading.");
                    wait(mutex);
                    readerCnt--;
                    if (readerCnt == 0)
                        signal(rw_mutex);
                    signal(mutex);
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
