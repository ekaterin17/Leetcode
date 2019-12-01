/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> gr;
        for (auto& employee : employees) {
            gr[employee->id] = employee;
        }
        
        int ans = 0;
        queue<Employee*> q;
        q.push(gr[id]);
        while (!q.empty()) {
            Employee* u = q.front();
            q.pop();
            ans += u->importance;
            for (const int& id : u->subordinates) {
                q.push(gr[id]);
            }
        }
        return ans;
    }
};
