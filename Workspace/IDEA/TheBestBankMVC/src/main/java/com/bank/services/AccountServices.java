package com.bank.services;

public interface AccountServices {
	void transfer(String fromAccount, String toAccount, double money) throws Exception;
}
