#include<iostream>
#include"Story.h"
#include<string>
using namespace std;
class Story
{
private:
	string storyName;
	int priority; 
	int teamNumber;
	int storyNumber;
	bool isDone;
public:
	Story()
	{
		storyName = "";
		priority = 0;
		teamNumber = 0;
		storyNumber = 0;
		isDone = false;
	}
	Story(string a, int b, int c, int d, bool k)
	{
		storyName = a;
		priority = b;
		teamNumber = c;
		storyNumber = d;
		isDone = k;
	}
	Story(const Story& s)
	{
		storyName = s.storyName;
		priority = s.priority;
		teamNumber = s.teamNumber;
		storyNumber = s.storyNumber;
		isDone = s.isDone;
	}
	Story& operator=(const Story& s)
	{
		storyName = s.storyName;
		priority = s.priority;
		teamNumber = s.teamNumber;
		storyNumber = s.storyNumber;
		isDone = s.isDone;
		return *this;
	}
	string getStoryName()
	{
		return storyName;
	}
	void setStoryName(string a)
	{
		storyName = a;

	}
	int getpriority()
	{
		return priority;
	}
	void setpriority(int &b)
	{
		priority = b;
	}
	int getteamNumber()
	{
		return teamNumber;
	}
    void setteamNumber(int c)
	{
		teamNumber = c;
	}
	int getstoryNumber()
	{
		return storyNumber;
	}
	int setstoryNumber(int d)
	{
		storyNumber = d;
	}
	bool getisDone()
	{
		return isDone;
	}
	void setIsDone(bool &k)
	{
		isDone = k;
	}
	void Display()
	{
		cout << "Story Name:   " << storyName << endl;
		cout << "Priority:     " << priority << endl;
		cout << "Story Number: " << storyNumber << endl;
		cout << "Team Number:  " << teamNumber << endl;
		cout << "IsDone:       " << isDone << endl;
		cout << "--------------------" << endl;
	}
	bool operator==(const Story& s)
	{
		if (storyName == s.storyName && priority == s.priority && teamNumber == s.teamNumber && storyNumber == s.storyNumber && isDone == s.isDone)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	~Story()
	{

	}

};
int main()
{
	Story f("blum", 1, 2, 3, 0);
	Story j("mlum", 4, 2, 1, 0);
	Story l("Baba", 3, 2, 1, 0);
	Story h("kaka", 3, 2, 1, 1);

	Story m("Dada", 2, 2, 1, 0);

	Story o("bibli", 5, 2, 1, 1);

	MyListLinked<Story> obj =  MyListLinked<Story>();
	cout << obj.isEmpty() << endl;

	obj.insert_at_last(f);
	obj.insert_at_last(j);

	obj.insert_at_last(l);

	obj.insert_at_last(m);

	cout << obj.isEmpty() << endl;

	

	obj.display_mylist();
	cout << "-----------\n";
	obj.remove_story("blum");
	obj.display_mylist();

	 obj.Wrap_Search("mlum");
	cout << "--------\n";
	obj.SearchKey("lum");
	obj.assignPriority("Dada", 6);
	obj.display_mylist();
	obj.assignPriority("Dada", 4);
	obj.display_mylist();

	///////
	obj.assignTeamNumber("Dada", 4);
	obj.display_mylist();
	obj.assignTeamNumber("Dada", 3);
	obj.display_mylist();


	cout << "********\n";
	obj.FindByPriority(3);


	obj.MarkStory("mlum", 1);


	obj.AddBefore("Dada", h);

	obj.display_mylist();
	///////////////////////
	int gh = 3;

	cout << obj.teamDone(gh);
	cout << endl;
	obj.Replacestory("Dada", o);
	obj.display_mylist();
	////////////////
	cout << "0000000000000000000\n";
	obj.push_first(h);
	obj.display_mylist();
///////////////
	obj.AddAfter("mlum", h);
	obj.display_mylist();
	/////

	obj.DoneornotDone();
	cout << obj.WrapSize();
	cout << endl;








	return 0;
}