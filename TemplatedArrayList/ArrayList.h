#pragma once

template<class T>
class ArrayList
{
private:
	//attributes
	const static int DEFAULT_SIZE = 5;    //constant for the initial size
	T* list;                              // pointer to the array
	int count;                            // number of items in the list
	int capacity;                         // current size in memory

public: 
	//constructor
	ArrayList(void)
	{
		this->list = new T[DEFAULT_SIZE];
		this->capacity = DEFAULT_SIZE;
		this->count = 0;
	}

	ArrayList(int initialCapacity)
	{
		this->list = new T[initialCapacity];
		this->capacity = initialCapacity;
		this->count = 0;
	}

	//destructor
	~ArrayList(void)
	{
		//delete the array pointer
		if (this->list != nullptr)
		{
			delete[] this->list;
			this->list = nullptr;
		}
	}

	bool isEmpty(void)
	{
		return count == 0;    //array is empty if it has zero items
	}

	///get the item at the given position
	T get(int position)
	{
		if (position < count)
			return list[position];
		else
			return NULL;
	}
	
	void add(T data)
	{
		//if the array is full, double the size
		if (count == capacity)
		{
			capacity = 2 * capacity;
			T* temp = new T[capacity];

			//copy items from current array to bigger array
			for (int i = 0; i < count; i++)
			{
				temp[i] = list[i];
			}

			//delete the current array
			delete[] list;

			//rename the bigger aray to the current array name
			list = temp;
		}

		//add the date item to the array
		list[count] = data;

		//increment the count
		count++;
	}

	///Remove item at the given position
	void removeAt(int position)
	{
		//replace every item from that position on with the next item
		for (int i = position; i < count -1; i++)  // notice "count -1" to copy last item to next to last position
		{
			list[i] = list[i + 1];
		}

		//decrease the item count
		count--;
	}


	///get the count of items in the ArrayList
	int getCount(void)
	{
		return count;
	}

	///get the ArrayList current capacity
	int getCapacity()
	{
		return capacity;
	}
};