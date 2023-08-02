package com.etsuya.system.utils;

import com.etsuya.system.bean.Emp;

import java.lang.reflect.InvocationTargetException;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 * ClassName: EmpBaseDAO
 * Package: com.etsuya.system.utils
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/5 16:31
 * @Version: 1.0
 */
public class EmpBaseDAO extends BaseDAO{
	public ArrayList<Emp> queryList() throws Exception {
		return super.query(Emp.class, "select * from emp");
	}

	public int insertEmp(Emp emp) throws Exception {
		return super.update("insert into emp (name, age) values(?, ?)", emp.getName(), emp.getAge());
	}

	public int updateEmp(Emp emp) throws Exception {
		return super.update("update emp set name=?, age=? where id=?", emp.getName(), emp.getAge(), emp.getId());
	}

	public int deleteEmp(int id) throws Exception {
		return super.update("delete from emp where id=?", id);
	}

	public Emp queryEmpById(int id) throws Exception {
		ArrayList<Emp> query = super.query(Emp.class, "select * from emp where id=?", id);
		if(query.size() == 0){
			return null;
		}
		return query.get(0);
	}
}
