class Stack:
	def __init__(self):
		self.stack = list()

	def push(self,data):
		self.stack.append(data)


	def pop(self):
		return self.stack.pop()


	def display(self):
		print("HEAD -> ", end="")
		self.stack.reverse()
		for i in self.stack:
			print(i, " -> " ,end="")

		print("TAIL")
		self.stack.reverse()

	def count(self):
		return len(self.stack)


class Queue:
	def __init__(self):
		self.queue = list()

	def push(self,data):
		self.queue.insert(0,data)


	def pop(self):
		return self.queue.pop()


	def display(self):
		print("HEAD -> ", end="")
		self.queue.reverse()
		for i in self.queue:
			print(i, " -> " ,end="")

		print("TAIL")
		self.queue.reverse()

	def count(self):
		return len(self.queue)




if __name__ == '__main__':
	stack = Stack()

	print("--Stack--")
	stack.push(1)
	stack.push(2)
	stack.push(3)
	stack.push(4)

	stack.display()

	stack.pop()

	stack.display()
	print("No. of elements: ", stack.count())


	queue = Queue()

	print("--Queue--")
	queue.push(1)
	queue.push(2)
	queue.push(3)
	queue.push(4)

	queue.display()
	print("No. of elements: ", queue.count())

	queue.pop()

	queue.display()


