package com.etsuya.Equals;

public class Order {
	private int orderId;
	private String orderName;
	
	public Order(int OrderId, String orderName) {
		this.orderId = orderId;
		this.orderName = orderName;
	}
	
	public boolean equals(Order obj) {
		if(this == obj) return true;
		if(obj instanceof Order) {
			Order order = (Order) obj;
			if(obj.orderId == orderId && orderName == obj.orderName) return true;
			return false;
		} else {
			return false;
		}
	}
}
