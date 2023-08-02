package com.bank.services.impl;

import com.bank.dao.AccountDao;
import com.bank.dao.impl.AccountDaoImpl;
import com.bank.exception.MoneyNotEnoughException;
import com.bank.exception.TransferException;
import com.bank.pojo.Account;
import com.bank.services.AccountServices;
import com.bank.utils.SqlSessionUtil;
import org.apache.ibatis.session.SqlSession;

public class AccountServicesImpl implements AccountServices {
	private AccountDao accountDao = SqlSessionUtil.openSession().getMapper(AccountDao.class);

	@Override
	public void transfer(String fromAccount, String toAccount, double money) throws Exception {
		//判断余额
		Account fromAccount1 = accountDao.selectByActno(fromAccount);
		double fromAccountBalance = fromAccount1.getBalance();
		if(fromAccountBalance < money){
			throw new MoneyNotEnoughException("余额不足！请检查余额！");
		}
		//转账
		fromAccount1.setBalance(fromAccountBalance - money);
		int c1 = accountDao.updateByActno(fromAccount1);
		Account toAccount1 = accountDao.selectByActno(toAccount);
		toAccount1.setBalance(toAccount1.getBalance() + money);
		int c2 = accountDao.updateByActno(toAccount1);
		//输出结果
		if(c1 + c2 != 2){
			throw new TransferException("余额不足！操你妈的！");
		}

		SqlSessionUtil.commitSession();
		SqlSessionUtil.closeSession();
	}
}
