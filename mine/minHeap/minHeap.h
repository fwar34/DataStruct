/*************************************************************************
    > File Name: minHeaplink.h
    > Author: Feng
    > Created Time: 2017年05月25日 星期四 09时39分04秒
    > Content: 数组描述的小根堆
	> 从0开始存储则数组中第i个元素的左孩子索引为2i+1右孩子索引为2i+2，父节点为(i-1)/2向下取整
	> 如果从1开始存储则数组中第i个元素的做还是索引为2i右孩子索引为2i+1，父节点为i/2向下取整
 ************************************************************************/

template <typename K>
class minheap
{
private:
	K* m_heap;
	size_t m_size;
	size_t m_totalsize;
public:
	minheap(size_t n)
	{
		m_heap = new K[n];
		m_size = 0;
		m_totalsize = n;
	}

	K min();
	void insert(K key);
	void remove(K key);

private:
	void resize();
	void filter_up(size_t index, K key);
	void filter_down(size_t index, K key);
};

template <typename K>
void minheap<K>::resize()
{
	K* old = m_heap;
	m_totalsize = 2 * m_totalsize;
	m_heap = new K[m_totalsize];
	memset(m_heap, 0, m_totalsize * sizeof(K));
	memcpy(m_heap, old, m_totalsize / 2 * sizeof(K));
	delete[] old;
}

template <typename K>
void minheap<K>::filter_up(size_t index, K key)
{
	//(index - 1) / 2是index的父节点在数组中的索引
	while (index > 0)
	{
		size_t parent = (index - 1) / 2;
		if (key < m_heap[parent])
		{
			m_heap[index] = m_heap[parent];
			index = parent;
		}
		else
		{
			break;
		}
	}
	m_heap[index] = key;
}

template <typename K>
void minheap<K>::filter_down(size_t index, K key)
{
	while (2 * index + 1 < m_size)
	{
		size_t left = 2 * index + 1;
		if (m_heap[left] < key)
		{
			m_heap[index] = m_heap[left];
			index = left;
		}
		else
		{
			if (m_heap[left + 1] < key)
			{
				m_heap[index] = m_heap[left + 1];
				index = left + 1;
			}
			else
			{
				break;
			}
		}
	}
	m_heap[index] = key;
}

template <typename K>
void minheap<K>::filter_down2(size_t index, K key)
{
	while (2 * index + 1 < m_size)
	{
		size_t child = 2 * index + 1;
		if (m_heap[child] > m_heap[child + 1])
		{
			child = child + 1;
		}
		
		if (m_heap[child] < key)
		{
			m_heap[index] = m_heap[child];
			index = child;
		}
		else
		{
			break;
		}
	}
	m_heap[index] = key;
}

template <typename K>
K minheap<K>::min()
{
	return m_heap[0];
}

template <typename K>
void minheap<K>::insert(K key)
{
	if (m_size == m_totalsize)
	{
		resize();
	}
	
	filter_up(m_size, key);
	m_size++;
}

template <typename K>
void minheap<K>::removemin()
{
	if (m_size == 0)
	{
		return;
	}
	
	if (m_size == 1)
	{
		m_size--;
		return;
	}
	
	m_heap[0] = m_heap[m_size - 1];
	filter_down(0, m_heap[0]);
	m_size--;
}