package com.bank.dao.impl;

import com.bank.dao.AccountDao;
import com.bank.pojo.Account;
import com.bank.utils.SqlSessionUtil;
import org.apache.ibatis.session.SqlSession;

public class AccountDaoImpl implements AccountDao {

	@Override
	public Account selectByActno(String actno) {
		SqlSession sqlSession = SqlSessionUtil.openSession();
		Account account = sqlSession.selectOne("bank.selectByActno", actno);
//		sqlSession.close();
		return account;
	}

	@Override
	public int updateByActno(Account account) {
		SqlSession sqlSession = SqlSessionUtil.openSession();
		int count = sqlSession.update("bank.updateByActno", account);
//		sqlSession.commit();
//		sqlSession.close();
		return count;
	}


}
