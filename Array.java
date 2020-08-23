import java.util.Iterator;

@SuppressWarnings("unchecked")
public class Array <T> implements Iterable <T> {

	private T [] buffer;
	private int length = 0;
	private int capacity = 0;
	
	public Array() {
		this(8);
	}
	
	public Array(int capacity) {
		if (capacity < 0) throw new IllegalArgumentException("Illegal capacity: " + capacity);
		this.capacity = capacity;
		this.buffer = (T[]) new Object [capacity];
	}
	
	public int size() {
		return this.length;
	}
	
	public boolean isEmpty() {
		return size() == 0;
	}
	
	public T get(int index) {
		if (index >= capacity || index<0) {
			throw new IllegalArgumentException("Illegal index: " + index);
		}
		return buffer[index];
	}
	
	public void set(int index, T value) {
		if (index >= this.capacity || index<0) {
			throw new IllegalArgumentException("Illegal index: " + index);
		}
		this.buffer[index] = value;
	}
	
	public void clear() {
		for(int i=0; i<this.capacity; i++) {
			this.buffer[i] = null;
		}
		this.length = 0;
	}
	
	public void add(T value) {
		if (this.length+1 > this.capacity) {
			if(this.length == 0) {this.capacity = 1; }
			else { this.capacity *= 2; }
			T [] newArray = (T[]) new Object [this.capacity];
			for(int i=0; i<this.length; i++) {
				newArray[i] = this.buffer[i];
			}
			this.buffer = newArray;
		}
		
		this.buffer[this.length++] = value;
	}
	
	public void removeAt(int index) {
		if (index >= this.length || index<0) {
			throw new IndexOutOfBoundsException();
		}
		T[] newArray = (T[]) new Object[this.length-1];
		for(int i=0, j=0; i<this.length; i++, j++) {
			if(i == index) { j--;}
			else newArray[j] = this.buffer[i];
		}
		this.buffer = newArray;
		this.capacity = this.capacity -1;		
	}
	
	@Override
	public Iterator<T> iterator() {
		return new Iterator<T> () {
			int index = 0; 
			@Override
			public boolean hasNext() {
				return index < length;
			}

			@Override
			public T next() {
				return buffer[index++];
			}
			
		};
	}
	
	@Override
	public String toString() {
		if (this.length == 0) {
			return "[]";
		}
		else {
			StringBuilder string = new StringBuilder(this.length).append("[");
			for (int i=0; i< this.length-1; i++) {
				string.append(this.buffer[i] + ", ");
			}
			return string.append(this.buffer[this.length-1] + "]").toString();
		}
		
	}
	
}
