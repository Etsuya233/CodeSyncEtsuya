package com.etsuya.system.test;

import com.etsuya.system.bean.Emp;
import com.etsuya.system.utils.EmpBaseDAO;

import java.util.ArrayList;

/**
 * ClassName: UtilsTest
 * Package: com.etsuya.system.test
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/5 16:30
 * @Version: 1.0
 */
public class UtilsTest {
	public static void main(String[] args) throws Exception {
		EmpBaseDAO empBaseDAO = new EmpBaseDAO();
//		//test insert
//		empBaseDAO.insertEmp(new Emp(1, 100, "NMSL"));
//		//test query
//		ArrayList<Emp> emps = empBaseDAO.queryList();
//		for (Emp emp : emps) {
//			System.out.println(emp.getId() + " " + emp.getName() + " " + emp.getAge());
//		}
		//test update
		empBaseDAO.updateEmp(new Emp(1, 100, "NB"));
		//test delete
		empBaseDAO.deleteEmp(1003);
		ArrayList<Emp> emps1 = empBaseDAO.queryList();
		for (Emp emp : emps1) {
			System.out.println(emp.getId() + " " + emp.getName() + " " + emp.getAge());
		}
	}
}
