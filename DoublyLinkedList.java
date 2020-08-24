import java.util.Iterator;

public class DoublyLinkedList<T> implements Iterable <T>{

	private int size = 0;
	private Node <T> head = null;
	
	// node
	private class Node <T> {
		T data;
		Node <T> prev, next;
		public Node(T data, Node <T>prev, Node <T>next) {
			this.data = data;
			this.prev = prev;
			this.next = next;
		}
		@Override
		public String toString() {
			return data.toString();
		}
	}
	
	// clear the list
	public void clear() {
		Node <T> trav = this.head;
		while(trav != null) {
			Node <T>next = trav.next;
			trav.prev = trav.next = null;
			trav.data = null;
			trav = next;			
		}
		head = trav = null;
		size = 0;
	}
	
	// size of the list
	public int size() {
		return size;
	}
	
	// isEmpty
	public boolean isEmpty() {
		return size() == 0;
	}
	
	// Add an element to the beginning of the list
	public void addFirst(T element) {
		// create a new node
		Node <T> newNode = new Node<T>(element, null, null);
		if(isEmpty()) {
			head = newNode;
		}
		else {
			newNode.next = this.head;
			this.head = newNode;
			newNode.next.prev = newNode;
		}
		size++;
	}
	
	// Add an element to the last index of the list
	public void addLast(T element) {
		// create a new node
		Node <T> newNode = new Node<T>(element, null, null);
		
		Node <T> trav = this.head;
		
		while(trav.next != null) {
			trav = trav.next;
		}
		trav.next = newNode;
		newNode.prev = trav;
		trav = null;
		size++;
	}
	
	// Get the first element in the list
	public T peekFirst() {
		if(isEmpty()) throw new RuntimeException("Empty list");
		return head.data;
	}
	
	// Get the last element in the list
	public T peekLast() {
		if(isEmpty()) throw new RuntimeException("Empty list");
		
		Node <T> trav = this.head;
		while(trav.next != null) {
			trav = trav.next;
		}
		
		return trav.data;
	}
	
	// Remove the first element in the list
	public T removeFirst() {
		if(isEmpty()) throw new RuntimeException("Empty list");
		
		Node <T> trav = this.head;
		this.head = trav.next;
		trav.next.prev = this.head;
		size--;
		return trav.data;
	}
	
	@Override
	public Iterator<T> iterator() {
		return new Iterator<T>() {
			private Node<T> trav = head;
			@Override
			public boolean hasNext() {
				return trav != null;
			}

			@Override
			public T next() {
				T data = trav.data;
				trav = trav.next;
				return data;
			}
			
		};
	}
	
	@Override
	public String toString() {
		StringBuilder string = new StringBuilder();
		string.append("[");
		Node <T> trav = head;
		while(trav != null) {
			string.append(trav.data + ", ");
			trav = trav.next;
		}
		string.append("]");
		return string.toString();
	}

}
