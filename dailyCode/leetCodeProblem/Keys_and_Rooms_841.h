
//https://leetcode.com/problems/keys-and-rooms/description/
//841. Keys and Rooms
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;
#ifndef ___Keys_and_Rooms_841_h___
#define ___Keys_and_Rooms_841_h___
class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		vector<bool> visited(rooms.size(), false);
		queue<int> keys;

		// 방문 하나 할 때마다 -1
		int room_count = rooms.size();

		visited[0] = true;
		room_count--;
		for (int key = 0; key < rooms[0].size(); key++)
			keys.push(rooms[0][key]);

		while (!keys.empty())
		{
			int room = keys.front();
			keys.pop();

			if (visited[room] == true)
				continue;
			visited[room] = true;
			room_count--;

			for (int key_in_room = 0; key_in_room < rooms[room].size(); key_in_room++)
			{
				keys.push(rooms[room][key_in_room]);
			}
		}

		return room_count == 0 ? true : false;

	}
};


#endif // ___Keys_and_Rooms_841_h___
