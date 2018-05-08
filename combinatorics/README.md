# Electronic Stack Exchange design ( top-K problem)

You work in an electronic exchange.

Throughout the day, you receive ticks (trading data) which consists of product name and its traded volume of stocks.<br/>
Eg: {name: vodafone, volume: 20}.

* You have to tell top k products traded by volume throughout the day


### Formal problem statement: 

design a class `StackExchange(k)` which supports the following operations.
* `trade(product, volume)`
* `get_top_traded()`


**P.S** You may also find this problem in a different form as 'Browser design', 
where you have to report the top **k** visited sites at any point of time. This would be like trading stocks, with `volume = 1` at all times.


## About my implementation
**Time complexity**
* trade : `O(log n + log k)`
	* if I switch to unordered_map, the expected complexity would be `O(log k)`
	* worst case complexity `O(n + log k)`
* top k : `O(k)`


## Hints/ Approach

The main thing about this problem would be to decide upon which data structures to use.
* One table (`map`/`unordered_map` in C++) to keep track of all products vs their volume traded
* One heap/ balanced BST kind of structure (`set` in C++) to keep track of the current top k products.
* When you get a new trade record, if the cumulative volume traded is more than the smallest of the top-k set , remove the smaller record, and insert this new record into the top-k set instead.
