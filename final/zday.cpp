/*Christopher Torralba	Section: B
Date 4/28/2016		Hw: Final Project*/


#include <iostream>
using namespace std;

struct Node
{
	Node* m_next = NULL;
	int m_weight;
	string m_name;
	
	Node (int weight, string name)
	{
		m_weight = weight;
		m_name = name;
	}
	
};

struct Location
{
	string m_name;
	int numNeighbors;
	Node* m_neighbor = NULL;

	void addVertex(int weight, string name)
	{
		if (m_neighbor == NULL)
		{
			m_neighbor = new Node (weight, name);
	  }
	  else
	  {
	  	Node * r = m_neighbor;
	  	while (r->m_next != NULL)
	  	{
	  		r = r->m_next;
	  	}
	  	r->m_next = new Node(weight, name);
	  }
	}
};

bool reachable(Location* places, int numPlaces, int tokens, string goal, Node* start)
{
  while (start != NULL)
  {
  	tokens = tokens - start->m_weight;
  	if((start->m_name == goal) && (tokens >= 0))
    {
  	  return true;
    }
  	else
  	  {
  	  	Node* next = NULL;
  	  	for (int i = 0; i < numPlaces; i++)
  	  	{
  	  		if (places[i].m_name == start->m_name)
  	  		  next = places[i].m_neighbor;
  	  	}
  	  	bool solved = reachable(places, numPlaces, tokens, goal, next);
  	  	if (solved)
  	  	  return true;
  	  	else
  	  	  tokens = tokens + start->m_weight;
		  }
  	start = start->m_next;
  }
  return false;
}

int main()
{
  int cases, tokens;
  int numPlaces, edgeWeight, airportNum;
  bool found;
  string city, placeName, neighborName;
  Location* places = NULL;
  
  cin >> cases;
  for (int k = 0; k < cases; k++)
  {
    //setup
  	cin >> tokens >> city >> numPlaces;
  	places = new Location[numPlaces];
	  for (int i = 0; i < numPlaces; i++)
	  {
	  	//ith place points to a new location containing neighbors
	  	//assuming airport IS ALL LOWERCASE
	  	cin >> places[i].m_name;
	  	cin >> places[i].numNeighbors;
	  	for (int j = 0; j < places[i].numNeighbors; j++)
	    {
	    	cin >> neighborName;
	    	cin >> edgeWeight;
	    	places[i].addVertex(edgeWeight, neighborName);
	    }
	  }
	  
	  // ACCESS
		/* for (int i = 0; i < numPlaces; i++)
	  {
	    cout << places[i].m_name << " neighbors are: ";
	    Node * r = places[i].m_neighbor;
	    while (r != NULL)
	    {
	    	cout << r->m_name <<" " << r->m_weight << " ";
				r = r->m_next;
	    }
	    cout << endl;
	  }*/
	  
	  //finding starting place
	  for (short i = 0; i < numPlaces; i++)
	  {
	    if (places[i].m_name == "airport")
	    {
	    	airportNum = i;
	    }
	  }
	  
	  //output
	  cout << "In " << city << ", Dr. Zoidberg can reach:" << endl;
	  found = false;
	  //finding adjacent and comparing with tokens
	  Node* r = places[airportNum].m_neighbor;
	  for (short i = 0; i < numPlaces; i++) //number of places
	  {
	  	if (places[i].m_name != "airport")
	  	{
	  	  if (reachable(places, numPlaces, tokens, places[i].m_name, r))
	  	  {
	  	  	found = true;
	  	    cout << places[i].m_name << endl;
	  	  }
	    }
	  }
	  if (found == false)
	    cout << "Nothing :-(" << endl;
	  cout << endl;
	  

	  //deallocating memory
	  for (int i = 0; i < numPlaces; i++)
	  {
	    Node* current = places[i].m_neighbor;
	    Node * ahead;
	    while (current != NULL)
	    {
	    	ahead = current->m_next;
	    	delete current;
	    	current = ahead;
	    }
	  }
    delete [] places;
	}
}
