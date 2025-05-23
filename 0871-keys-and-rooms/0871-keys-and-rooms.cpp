#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();               // Total number of rooms
        vector<bool> visited(n, false);     // Keep track of visited rooms
        queue<int> q;                       // Queue for BFS

        // Start from room 0
        visited[0] = true;                  // Mark room 0 as visited
        q.push(0);                         // Add room 0 to the queue

        while (!q.empty()) {
            int currentRoom = q.front();   // Get the next room to explore
            q.pop();

            // Check all keys in the current room
            for (int key : rooms[currentRoom]) {
                // If we haven't visited the room for this key yet
                if (!visited[key]) {
                    visited[key] = true;   // Mark the room as visited
                    q.push(key);           // Add this room to the queue to explore its keys later
                }
            }
        }

        // After BFS, check if all rooms were visited
        for (bool roomVisited : visited) {
            if (!roomVisited) {
                return false;  // Found a room that was not visited
            }
        }

        return true;  // All rooms visited
    }
};
