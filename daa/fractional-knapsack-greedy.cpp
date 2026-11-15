#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item
{
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), cmp);
    double finalValue = 0.0;

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].weight <= W)
        {
            W -= items[i].weight;
            finalValue += items[i].value;
        }
        else
        {
            finalValue += items[i].value * ((double)W / (double)items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    int W = 50;
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    cout << "Maximum value in Fractional Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}