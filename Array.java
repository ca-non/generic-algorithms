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
		for(int i=0; i<capacity; i++) {
			buffer[i] = null;
		}
		length = 0;
	}
	
	public void add(T value) {
		if (length+1 > capacity) {
			
		}
		buffer[length] = value;
	}
	
	@Override
	public Iterator<T> iterator() {
		// TODO Auto-generated method stub 
		return null;
	}
	
}
