class TaskManager {
public:
    typedef pair<int ,int> p;
    priority_queue<p> maxheap; //// priority , taskid --- we need max pri or if pri equal than maxm taskid
    unordered_map<int,int>taskprioritymap; /// task , priority
    unordered_map<int,int>taskownermap; /// task ,userid
    TaskManager(vector<vector<int>>& tasks) {
        for(auto &task : tasks){
            add(task[0],task[1],task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        maxheap.push({priority,taskId});
        taskprioritymap[taskId] = priority;
        taskownermap[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        maxheap.push({newPriority,taskId});
        taskprioritymap[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        taskprioritymap[taskId] = -1;
    }
    
    int execTop() {
        while(!maxheap.empty()){
            auto[pri , taskId] = maxheap.top();
            maxheap.pop();
            if(pri == taskprioritymap[taskId]){
                taskprioritymap[taskId] = -1;
                return taskownermap[taskId];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */