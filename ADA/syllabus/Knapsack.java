import java.util.Arrays;
import java.util.Comparator;

public class Knapsack {
    static class Item {
        int profit, weight;

        public Item(int p, int w) {
            profit = p;
            weight = w;
        }
    }

    private static double greedyKnapsack(Item[] items, int m) {
        // Sorting items in non-increasing order of pi/wi
        Arrays.sort(items, new Comparator<Item>() {
            @Override
            public int compare(Item a, Item b) {
                double ppw1 = (double) a.profit / (double) a.weight;
                double ppw2 = (double) b.profit / (double) b.weight;

                if (ppw1 < ppw2)
                    return 1;
                else
                    return -1;
            }
        });

        int u = m;
        double maxProfit = 0.0;
        int i;
        for (i = 0; i < items.length; i++) {
            if (items[i].weight > u)
                break;
            maxProfit = items[i].profit;
            u = u - items[i].weight;
        }

        if (i < items.length) {
            maxProfit += items[i].profit * (double) u / (double) items[i].weight;
        }

        return maxProfit;
    }

    public static void main(String[] args) {
        Item[] items = { new Item(25, 18),
                         new Item(24, 15),
                         new Item(15, 10) };
        int m = 20;
        double maxProfit = greedyKnapsack(items, m);
        System.out.println("Max Profit : " + maxProfit);
    }
}