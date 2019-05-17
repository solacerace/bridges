#include "pch.h"
#include <stdio.h>
#include <cstdlib>
#include <stdexcept>
#include <map>
#include <memory>
#include <atomic>
#include <set>
#include <unordered_map>
using namespace std;
class Order {
public:
	int OrderId;
	int Quantity;
	double Price;
	char Side;
	Order(int orderId, char side, int quantity, double price);
	Order(const Order &) = default;
};

class OrderBookInfo {
public:
	std::atomic<int> TotalQuantity;
	std::atomic<int> TotalOrderNum;
	OrderBookInfo(int quantity);
	OrderBookInfo(const OrderBookInfo &) = default;
};

/*
	OrderBook is a level 3 orderbook.  Please fill out the stub below.
*/
class OrderBook {
	unordered_map<int, shared_ptr<Order>> orders;
	map<double, shared_ptr<OrderBookInfo>, greater<double>> buyOrderBook;
	map<double, shared_ptr<OrderBookInfo>> sellOrderBook;

public:
	// adds order to order book
	void newOrder(int orderId, char side, int size, double price) {
		if (orders.find(orderId) != orders.end() || size <= 0 || (side != 'b' && side != 's')) {
			throw std::invalid_argument("Invalid operation");
		}
		orders[orderId] = make_shared<Order>(orderId, side, size, price);

		if (side == 'b') {
			auto orderBook = buyOrderBook.find(price);
			if (orderBook != buyOrderBook.end()) {
				auto orderBookInfo = orderBook->second;
				++orderBookInfo->TotalOrderNum;
				orderBookInfo->TotalQuantity += size;
			}
			else {
				buyOrderBook[price] =
					make_shared<OrderBookInfo>(size);
			}
		}
		else if (side == 's') {
			auto orderBook = sellOrderBook.find(price);
			if (orderBook != sellOrderBook.end()) {
				auto orderBookInfo = orderBook->second;
				++orderBookInfo->TotalOrderNum;
				orderBookInfo->TotalQuantity += size;
			}
			else {
				sellOrderBook[price] =
					make_shared<OrderBookInfo>(size);
			}
		}
	}
	// changes quantity contained in order
	void changeOrder(int orderId, int newSize) {
		if (newSize <= 0 || orders.find(orderId) == orders.end()) {
			throw std::invalid_argument("Invalid operation");
		}
		auto order = orders[orderId];

		int diff = 0;
		shared_ptr<OrderBookInfo> orderBookInfo;
		if (order->Side == 'b') {
			auto orderBook = buyOrderBook.find(order->Price);
			if (orderBook == buyOrderBook.end()) {
				throw std::invalid_argument("Invalid operation");
			}
			orderBookInfo = orderBook->second;
		}
		else if (order->Side == 's') {
			auto orderBook = sellOrderBook.find(order->Price);
			if (orderBook == sellOrderBook.end()) {
				throw std::invalid_argument("Invalid operation");
			}
			orderBookInfo = orderBook->second;
		}
		else {
			throw std::invalid_argument("Invalid operation");
		}

		diff = newSize - order->Quantity;
		order->Quantity = newSize;
		orderBookInfo->TotalQuantity += diff;
	}
	// replaces order with different order
	void replaceOrder(int oldOrderId, int orderId, char side, int size,
		double price) {
		deleteOrder(oldOrderId);
		newOrder(orderId, side, size, price);
	}
	// deletes order from orderbook
	void deleteOrder(int orderId) {
		auto it = orders.find(orderId);
		if (it == orders.end()) {
			throw std::invalid_argument("Invalid operation");
		}
		auto order = it->second;
		std::set<double> orderBookPrices;
		shared_ptr<OrderBookInfo> orderBookInfo;
		if (order->Side == 'b') {
			auto orderBook = buyOrderBook.find(order->Price);
			if (orderBook == buyOrderBook.end()) {
				throw std::invalid_argument("Invalid operation");
			}
			orderBookInfo = orderBook->second;
		}
		else if (order->Side == 's') {
			auto orderBook = sellOrderBook.find(order->Price);
			if (orderBook == sellOrderBook.end()) {
				throw std::invalid_argument("Invalid operation");
			}
			orderBookInfo = orderBook->second;
		}
		else {
			throw std::invalid_argument("Invalid operation");
		}

		orderBookInfo->TotalQuantity -= order->Quantity;
		--orderBookInfo->TotalOrderNum;
		if (orderBookInfo->TotalQuantity <= 0) {
			orderBookPrices.erase(order->Price);
			if (order->Side == 'b') {
				buyOrderBook.erase(order->Price);
			}
			else {
				sellOrderBook.erase(order->Price);
			}
		}
		orders.erase(orderId);
	}
	// returns the number of levels on the side
	int getNumLevels(char side) {
		if (side == 'b') {
			return buyOrderBook.size();
		}
		else if (side == 's') {
			return sellOrderBook.size();
		}
		else {
			throw std::invalid_argument("Invalid operation");
		}
	}
	// returns the price of a level.  Level 0 is top of book.
	double getLevelPrice(char side, int level) {

		if (side == 'b' && level < buyOrderBook.size()) {
			auto it(buyOrderBook.begin());
			std::advance(it, level);
			return it->first;
		}
		else if (side == 's' && level < sellOrderBook.size()) {
			auto it(sellOrderBook.begin());
			std::advance(it, level);
			return it->first;
		}
		else {
			throw std::invalid_argument("Invalid operation");
		}
	}
	// returns the size of a level.
	int getLevelSize(char side, int level) {
		if (side == 'b' && level < buyOrderBook.size()) {
			auto it(buyOrderBook.begin());
			std::advance(it, level);
			return it->second->TotalQuantity;
		}
		else if (side == 's' && level < sellOrderBook.size()) {
			auto it(sellOrderBook.begin());
			std::advance(it, level);
			return it->second->TotalQuantity;
		}
		else {
			throw std::invalid_argument("Invalid operation");
		}
	}
	// returns the number of orders contained in price level.
	int getLevelOrderCount(char side, int level) {
		if (side == 'b' && level < buyOrderBook.size()) {
			auto it(buyOrderBook.begin());
			std::advance(it, level);
			return it->second->TotalOrderNum;
		}
		else if (side == 's' && level < sellOrderBook.size()) {
			auto it(sellOrderBook.begin());
			std::advance(it, level);
			return it->second->TotalOrderNum;
		}
		else {
			throw std::invalid_argument("Invalid operation");
		}
	}
};

Order::Order(int orderId, char side, int quantity, double price) {
	OrderId = orderId;
	Side = side;
	Quantity = quantity;
	Price = price;
}

OrderBookInfo::OrderBookInfo(int quantity) {
	TotalQuantity = quantity;
	TotalOrderNum = 1;
}

int main()
{
	OrderBook orderBook;
	orderBook.newOrder(1, 'b', 100, 100.1);
	orderBook.newOrder(2, 'b', 101, 100.1);
	orderBook.newOrder(3, 'b', 102, 100.1);
	orderBook.newOrder(4, 'b', 103, 100.2);
	orderBook.newOrder(5, 'b', 104, 100.2);
	orderBook.newOrder(6, 'b', 105, 100.2);
	orderBook.newOrder(7, 'b', 106, 100.3);
	orderBook.newOrder(8, 'b', 107, 100.3);
	orderBook.newOrder(9, 'b', 108, 100.3);

	orderBook.newOrder(101, 's', 100, 100.1);
	orderBook.newOrder(102, 's', 101, 100.1);
	orderBook.newOrder(103, 's', 102, 100.1);
	orderBook.newOrder(104, 's', 103, 100.2);
	orderBook.newOrder(105, 's', 104, 100.2);
	orderBook.newOrder(106, 's', 105, 100.2);
	orderBook.newOrder(107, 's', 106, 100.3);
	orderBook.newOrder(108, 's', 107, 100.3);
	orderBook.newOrder(109, 's', 108, 100.3);
	_ASSERT(orderBook.getNumLevels('b') == 3);
	_ASSERT(orderBook.getNumLevels('s') == 3);
	_ASSERT(abs(orderBook.getLevelPrice('b', 0) - 100.3) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('b', 1) - 100.2) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('b', 2) - 100.1) < 0.001);

	_ASSERT(abs(orderBook.getLevelPrice('s', 0) - 100.1) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('s', 1) - 100.2) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('s', 2) - 100.3) < 0.001);

	_ASSERT(orderBook.getLevelSize('b', 0) == 321);
	_ASSERT(orderBook.getLevelSize('b', 1) == 312);
	_ASSERT(orderBook.getLevelSize('b', 2) == 303);

	_ASSERT(orderBook.getLevelSize('s', 0) == 303);
	_ASSERT(orderBook.getLevelSize('s', 1) == 312);
	_ASSERT(orderBook.getLevelSize('s', 2) == 321);

	_ASSERT(orderBook.getLevelOrderCount('b', 0) == 3);
	_ASSERT(orderBook.getLevelOrderCount('b', 1) == 3);
	_ASSERT(orderBook.getLevelOrderCount('b', 2) == 3);

	_ASSERT(orderBook.getLevelOrderCount('s', 0) == 3);
	_ASSERT(orderBook.getLevelOrderCount('s', 1) == 3);
	_ASSERT(orderBook.getLevelOrderCount('s', 2) == 3);

	//Test ChangeOrder
	orderBook.changeOrder(1, 200);
	orderBook.changeOrder(9, 208);

	orderBook.changeOrder(101, 200);
	orderBook.changeOrder(109, 208);

	_ASSERT(orderBook.getNumLevels('b') == 3);
	_ASSERT(orderBook.getNumLevels('s') == 3);
	_ASSERT(abs(orderBook.getLevelPrice('b', 0) - 100.3) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('b', 1) - 100.2) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('b', 2) - 100.1) < 0.001);

	_ASSERT(abs(orderBook.getLevelPrice('s', 0) - 100.1) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('s', 1) - 100.2) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('s', 2) - 100.3) < 0.001);

	_ASSERT(orderBook.getLevelSize('b', 0) == 421);
	_ASSERT(orderBook.getLevelSize('b', 1) == 312);
	_ASSERT(orderBook.getLevelSize('b', 2) == 403);

	_ASSERT(orderBook.getLevelSize('s', 0) == 403);
	_ASSERT(orderBook.getLevelSize('s', 1) == 312);
	_ASSERT(orderBook.getLevelSize('s', 2) == 421);

	_ASSERT(orderBook.getLevelOrderCount('b', 0) == 3);
	_ASSERT(orderBook.getLevelOrderCount('b', 1) == 3);
	_ASSERT(orderBook.getLevelOrderCount('b', 2) == 3);

	_ASSERT(orderBook.getLevelOrderCount('s', 0) == 3);
	_ASSERT(orderBook.getLevelOrderCount('s', 1) == 3);
	_ASSERT(orderBook.getLevelOrderCount('s', 2) == 3);

	orderBook.replaceOrder(1, 10, 'b', 100, 100.3);
	orderBook.replaceOrder(9, 110, 's', 100, 100.3);
	orderBook.replaceOrder(110, 11, 'b', 100, 100.1);

	_ASSERT(orderBook.getNumLevels('b') == 3);
	_ASSERT(orderBook.getNumLevels('s') == 3);
	_ASSERT(abs(orderBook.getLevelPrice('b', 0) - 100.3) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('b', 1) - 100.2) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('b', 2) - 100.1) < 0.001);

	_ASSERT(abs(orderBook.getLevelPrice('s', 0) - 100.1) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('s', 1) - 100.2) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('s', 2) - 100.3) < 0.001);

	_ASSERT(orderBook.getLevelSize('b', 0) == 313);
	_ASSERT(orderBook.getLevelSize('b', 1) == 312);
	_ASSERT(orderBook.getLevelSize('b', 2) == 303);

	_ASSERT(orderBook.getLevelSize('s', 0) == 403);
	_ASSERT(orderBook.getLevelSize('s', 1) == 312);
	_ASSERT(orderBook.getLevelSize('s', 2) == 421);

	_ASSERT(orderBook.getLevelOrderCount('b', 0) == 3);
	_ASSERT(orderBook.getLevelOrderCount('b', 1) == 3);
	_ASSERT(orderBook.getLevelOrderCount('b', 2) == 3);

	_ASSERT(orderBook.getLevelOrderCount('s', 0) == 3);
	_ASSERT(orderBook.getLevelOrderCount('s', 1) == 3);
	_ASSERT(orderBook.getLevelOrderCount('s', 2) == 3);

	orderBook.deleteOrder(2);
	orderBook.deleteOrder(3);
	orderBook.deleteOrder(11);

	orderBook.deleteOrder(101);
	orderBook.deleteOrder(102);
	orderBook.deleteOrder(103);

	_ASSERT(orderBook.getNumLevels('b') == 2);
	_ASSERT(orderBook.getNumLevels('s') == 2);
	_ASSERT(abs(orderBook.getLevelPrice('b', 0) - 100.3) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('b', 1) - 100.2) < 0.001);

	_ASSERT(abs(orderBook.getLevelPrice('s', 0) - 100.2) < 0.001);
	_ASSERT(abs(orderBook.getLevelPrice('s', 1) - 100.3) < 0.001);

	_ASSERT(orderBook.getLevelSize('b', 0) == 313);
	_ASSERT(orderBook.getLevelSize('b', 1) == 312);

	_ASSERT(orderBook.getLevelSize('s', 0) == 312);
	_ASSERT(orderBook.getLevelSize('s', 1) == 421);

	_ASSERT(orderBook.getLevelOrderCount('b', 0) == 3);
	_ASSERT(orderBook.getLevelOrderCount('b', 1) == 3);

	_ASSERT(orderBook.getLevelOrderCount('s', 0) == 3);
	_ASSERT(orderBook.getLevelOrderCount('s', 1) == 3);


	orderBook.deleteOrder(7);
	orderBook.deleteOrder(8);
	orderBook.deleteOrder(10);

	orderBook.deleteOrder(107);
	orderBook.deleteOrder(108);
	orderBook.deleteOrder(109);



	_ASSERT(orderBook.getNumLevels('b') == 1);
	_ASSERT(orderBook.getNumLevels('s') == 1);
	_ASSERT(abs(orderBook.getLevelPrice('b', 0) - 100.2) < 0.001);

	_ASSERT(abs(orderBook.getLevelPrice('s', 0) - 100.2) < 0.001);

	_ASSERT(orderBook.getLevelSize('b', 0) == 312);

	_ASSERT(orderBook.getLevelSize('s', 0) == 312);

	_ASSERT(orderBook.getLevelOrderCount('b', 0) == 3);

	_ASSERT(orderBook.getLevelOrderCount('s', 0) == 3);


	return 0;
}