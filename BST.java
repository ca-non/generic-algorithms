import java.util.LinkedList;
import java.util.Queue;

public class BST <T extends Comparable <T>>{
	
	private int nodeCount = 0;
	private Node root = null;
	
	private class Node{
		T data;
		Node left, right;
		public Node (T data, Node left, Node right) {
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public int size() {
		return this.nodeCount
				;
	}
	
	public boolean add(T data) {
		if(contains(data)) {
			return false;
		}
		else {
			this.root = add(this.root, data);
			nodeCount++;
			return true;
		}
	}
	
	public boolean contains(T data) {
		
		return search (root, data);

	}
	
	private boolean search(Node node, T data) {
		if(node == null) {
			return false;
		}
		else if(data.compareTo(node.data) == 0) {
			return true;
		}
		else if(data.compareTo(node.data) < 0) {
			return search(node.left, data);
		}
		else {
			return search(node.right, data);
		}
	}
	
	public Node add(Node node, T data) {
		// Create new node
		Node newNode = new Node(data, null, null);
		if(node == null) {
			node = newNode;
		}
		else {
			if(data.compareTo(node.data) < 0) {
				node.left = add(node.left, data);
			}
			else {
				node.right = add(node.right, data);
			}
		}
		
		return node;
	}
	
	
	@SuppressWarnings("null")
	public T max() {
		Node trav = root;
	
		while(trav.right != null) {
			trav = trav.right;
		}
		
		return (T)trav.data;
	}
	

	
	@SuppressWarnings("null")
	public T min() {
		Node trav = root;
	
		while(trav.left != null) {
			trav = trav.left;
		}
		
		return (T)trav.data;
	}
	
	public int height() {
		return findHeight(root);
	}
	
	
	private int findHeight(Node node) {
		if (node == null) {
			return -1;
		}
		
		return (Math.max(findHeight(node.left), findHeight(node.right)) + 1);
	}
	
	public void inOrder() {
		inOrder(this.root);
		System.out.println();
	}
	
	private void inOrder(Node node) {
		if (node != null) {
			inOrder(node.left);
			System.out.print(node.data + " ");
			inOrder(node.right);
		}
		
	}
	
	public void postOrder() {
		postOrder(this.root);
		System.out.println();
	}
	
	private void postOrder(Node node) {
		if (node != null) {
			inOrder(node.left);
			inOrder(node.right);
			System.out.print(node.data + " ");
		}
	}
	
	public void preOrder() {
		preOrder(this.root);
		System.out.println();
	}
	
	private void preOrder(Node node) {
		if (node != null) {
			System.out.print(node.data + " ");
			inOrder(node.left);
			inOrder(node.right);
		}
	}
	
	
	public void levelOrder() {
		levelOrder(root);
		System.out.println();
	}
	
	private void levelOrder(Node node) {
		if(node == null) {
			return;
		}
		
		Queue<Node> q = new LinkedList<Node>();
		q.add(node);
		
		while(!q.isEmpty()) {
			Node temp = q.peek();
			System.out.print(temp.data + " ");
			
			if(temp.left != null) { q.add(temp.left); }
			if(temp.right != null) { q.add(temp.right); }
			q.remove();
		}
		
		
	}
	
}
