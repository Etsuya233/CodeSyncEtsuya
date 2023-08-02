package com.bank.dao;

import com.bank.pojo.Account;

public interface AccountDao {
	Account selectByActno(String actno);
	int updateByActno(Account account);

}
