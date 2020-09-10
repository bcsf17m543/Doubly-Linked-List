#include<iostream>
using namespace std;
template<typename Object>
class MyListLinked 
{
private:
	class node {
	public:
		Object val;
		node* next;
		node* prev;
		node(const Object& d)
		{
			val = d;
			next = NULL;
			prev = NULL;
		}
		node()//for header nodes
		{
			val = Object();
			next = NULL;
			prev = NULL;
		}
		
	};
	long Size;
	node* head;
	node* tail;
	void Search(node* &temp,string c,bool & k)
	{
		
		if (temp != tail)
		{
			if (temp->val.getStoryName() == c)
			{
				k = true;
				return;
			}
			Search(temp->next, c,k);
		}
	}
	
public:
	
	void Wrap_Search(string c)
	{
		bool ck = false;
		node* temp = head;
		 Search(temp, c,ck);
		 cout << ck;
		
	}
	MyListLinked()
	{
		Size = 0;
		head = new node();
		tail = new node();
		head->next = tail;
		tail->prev = head;
		
	}
	~MyListLinked()
	{
		node *tmp = head;
		while (tmp != tail)
		{
			node *junk = tmp;
			tmp = tmp->next;
			delete junk;
		}
		delete tail;
	}
	void insert_at_last(const Object &c)
	{

		node *temp = new node(c);
		
		
			temp->prev = tail;
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
			//temp->next = tail;

			Size++;
		
	}
	void assignTeamNumber(string c, int a)
	{
		if (a > 3 || a < 1)
		{
			return;
		}
		else
		{
			node* temp = head;

			while (temp != tail)
			{
				if (temp->next->val.getStoryName() == c)
				{

					temp->next->val.setteamNumber(a);
					break;

				}
				temp = temp->next;


			}
		}
	}
	void assignPriority(string c, int a)
	{
		if (a > 5 || a < 1)
		{
			return;
		}
		else
		{
			node* temp = head;

			while (temp != tail)
			{
				if (temp->next->val.getStoryName() == c)
				{

					temp->next->val.setpriority(a);
					break;

				}
				temp = temp->next;


			}
		}
	}
	/*void OrderByp()
	{
		node* temp = head->next;
		while (temp != tail)
		{

		}
	}*/
	void FindByPriority(int c)
	{
		node* temp = head->next;

		while (temp != tail)
		{
			if (temp->val.getpriority() == c)
			{

				temp->val.Display();

			}
			temp = temp->next;

			cout << endl;
		}
	}
	void SearchKey(const string &c)
	{
		node* temp = head;
		bool jk = false;

		while (temp != tail)
		{
			for (int i = 0; i < temp->val.getStoryName().length(); i++)
			{
				if (temp->val.getStoryName()[i] == c[0])
				{
					for (int j = 1; j < c.length() - 1; j++)
					{
						if (temp->val.getStoryName()[i + j] == c[j])
						{
							jk = true;
						}
						else
						{
							jk = false;
						}
					}
					if (jk)
					{
						temp->val.Display();
					}
				}
			}
			temp = temp->next;

		}

	}
	void display_mylist()
	{
		node* tmp = head->next;
		//tmp = tmp->next;
		while (tmp != tail)
		{
			tmp->next->val.Display();
			tmp = tmp->next;
		}
		cout << endl;
	}
	void push_first(const Object &c)
	{
			node *temp = new node(c);
			temp->next = head->next;
			head->next = temp;

			temp->prev = head;

			//head= temp;
			//temp->next = tail;

			Size++;
		

	}
	void Showhead()
	{
		head->val.Display();
	}
	bool Is_Full()
	{
		// cout << "No need in case of linked list";
		return false;
	}
	void Intiate(const Object &c)
	{
		cout << "No need in case of linked list";

	}
	Object last()
	{
		if (tail->prev != head)
		{
			return tail->prev->val;
		}
	}
	Object first() const
	{
		if (head->next != tail)
		{
			return head->next->val;
		}
	}
	void pop_last()
	{
		if (tail->prev != head)
		{
			tail->prev = tail->prev->prev;
			tail->prev->next = tail;
			Size--;
		}
	}
	void pop_first()
	{
		if (head->next != tail)
		{
			head->next = head->next->next;
			head->next->prev = head;
			Size--;
		}
	}
	int indexOf(const Object &c)
	{
		int indx = 0;
		node*temp = head;
		while (temp->next != tail)
		{
			if (c == temp->next->val)
			{
				break;
			}
			temp = temp->next;
			indx++;
		}
		return indx;
	}
	
	void remove_story(const string &c)
	{
		node* temp = head->next;
		
		while (temp->next!= NULL)
		{
			if (temp->val.getStoryName() == c)
			{
				temp->next->prev = temp->prev;

				temp->prev->next = temp->next;
				Size--;
				delete temp;
				return;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	void AddBefore(string c, const Object &y)
	{
		node* temp = head->next;
		node* tmp = new node(y);
		while (temp != tail)
		{
			if (temp->next->val.getStoryName() == c)
			{
				temp = temp->next;
				tmp->next = temp;
				tmp->prev = temp->prev;
				temp->prev->next = tmp;
				temp->prev = tmp;
				Size++;
				return;
			}
			temp = temp->next;

			cout << endl;
		}
	}
	void AddAfter(string c,const Object &y)
	{
		node* temp = head->next;
		node* tmp = new node(y);
		while (temp != tail)
		{
			if (temp->val.getStoryName()== c)
			{
				temp = temp->next;
				tmp->next = temp;
				tmp->prev = temp->prev;
				temp->prev->next = tmp;
				temp->prev = tmp;
				Size++;
				return;
			}
			temp = temp->next;

			cout << endl;
		}
	}
	bool MarkStory(string b,bool k)
	{
		node* temp = head;
		while (temp != tail)
		{
			if (temp->next->val.getStoryName() == b)
			{
				if (temp->val.getisDone() == true)
				{
					//temp->val.setIsDone(k);
					temp->val.Display();
				}
			}
			temp = temp->next;

			cout << endl;
		}
		return temp->val.getisDone();
	}
	void Replacestory(string c,const Object&k)
	{
		node* temp = head;

		while (temp != tail)
		{
			if (temp->next->val.getStoryName() == c)
			{

				temp->next->val = k;
				return;

			}
			temp = temp->next;

		}
	}
	bool teamDone(int &c)
	{
		node* temp = head;

		while (temp != tail)
		{
			if (temp->next->val.getteamNumber() == c)
			{
				if (temp->val.getisDone())
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	void DoneornotDone()
	{
		node* temp = head;

		while (temp != tail)
		{
			
				if (temp->next->val.getisDone())
				{
					cout << "Done :\n";
					temp->next->val.Display();
					cout << "----------";
				}
				else
				{
					cout << "Not Done\n";
					temp->next->val.Display();
					cout << "----------";
				}
				temp = temp->next;

			}
			
		
	}
	/*int SizeofStory(node* temp,int size)
	{
		if(temp == tail)
		{
			return size;
		}
		else
		{
			return size + SizeofStory(temp->next, size);
		}
	}*/

	int WrapSize()
	{
		
		return Size;
	}
	bool isEmpty() const
	{
		if (head->next == tail)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	long size() const
	{
		return Size;
	}
};
