public class Process {
    public int id, exT, toT, wT, arT;

    public Process(int id, int exT) {
        this.id = id;
        this.exT = exT;
    }

    public Process(int id, int exT, int arT) {
        this.id = id;
        this.exT = exT;
        this.arT = arT;
    }
}