#ifndef LISTNODE_H
#define LISTNODE_H

template<typename NODETYPE> class List;

template<typename NODETYPE>
class ListNode
{
	friend class List<NODETYPE>;

private:
	NODETYPE data;
	ListNode<NODETYPE>* nextPtr;
public:
	explicit ListNode(const NODETYPE& info)
		:data(info), nextPtr(nullptr)
	{
		//Empty body
	}

	NODETYPE getData() const
	{
		return data;
	}

};

#endif

