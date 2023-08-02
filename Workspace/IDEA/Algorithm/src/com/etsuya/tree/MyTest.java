package com.etsuya.tree;

import org.junit.Test;

import java.util.Arrays;

/**
 * ClassName: MyTest
 * Package: com.etsuya.tree
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/27 16:50
 * @Version: 1.0
 */
public class MyTest {
	@Test
	public void test(){
		int[] inorder = {2,1};
		int[] postorder = {2,1};
		buildTree(inorder, postorder);

	}

	int[] inorder;
	int[] postorder;
	TreeNode ret;
	int length;

	public TreeNode buildTree(int[] inorder, int[] postorder) {
		length = inorder.length;
		this.inorder = inorder;
		this.postorder = postorder;
		return opera(0, length - 1, 0, length - 1);
	}

	public TreeNode opera(int inH, int inT, int postH, int postT){
		if(inH == inT){
			return new TreeNode(inorder[inH]);
		}
		int val = postorder[postT];
		int valIn = 0;
		for(int i = inH; i <= inT; i++){
			if(inorder[i] == val){
				valIn = i;
				break;
			}
		}
		TreeNode node = new TreeNode(val);
		node.left = opera(inH, valIn - 1, postH, postH + valIn - inH - 1);
		node.right = opera(valIn + 1, inT, postH + valIn - inH, postT - 1);
		return node;
	}

	 public class TreeNode {
	     int val;
	     TreeNode left;
	     TreeNode right;
	     TreeNode() {}
	     TreeNode(int val) { this.val = val; }
		 TreeNode(int val, TreeNode left, TreeNode right) {
			 this.val = val;
			 this.left = left;
			 this.right = right;
		 }
	}
}
