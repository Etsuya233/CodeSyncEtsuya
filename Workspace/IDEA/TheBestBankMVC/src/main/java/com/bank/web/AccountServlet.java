package com.bank.web;

import com.bank.services.AccountServices;
import com.bank.services.impl.AccountServicesImpl;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

@WebServlet("/transfer")
public class AccountServlet extends HttpServlet {
	AccountServices accountServices = new AccountServicesImpl();

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		String fromAccount = req.getParameter("fromAccount");
		String toAccount = req.getParameter("toAccount");
		double amount = Double.parseDouble(req.getParameter("amount"));

		//转账
		try {
			accountServices.transfer(fromAccount, toAccount, amount);
			resp.sendRedirect(req.getContextPath() + "/transferResult.html");
		} catch (Exception e){
			resp.sendRedirect(req.getContextPath() + "/transferError.html");
		}
	}
}
