class Solution:
    def __init__(self):
        # DSU using rank and path compression
        self.rank = []
        self.parent = []

    # Find with path compression
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def Union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX == rootY:
            return

        # Union by rank
        if self.rank[rootX] < self.rank[rootY]:
            rootX, rootY = rootY, rootX

        self.parent[rootY] = rootX

        if self.rank[rootX] == self.rank[rootY]:
            self.rank[rootX] += 1

    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:

        n = len(source)

        self.parent = [0] * n
        self.rank = [0]* n

        for i in range(n):
            self.parent[i] = i

        for vec in allowedSwaps:
            self.Union(vec[0],vec[1])

        groupfreq = {}

        for i in range(n):
            curr = source[i]
            parent = self.find(i)
            if parent not in groupfreq:
                groupfreq[parent] = {}
            
            if curr not in groupfreq[parent]:
                groupfreq[parent][curr] = 0

            groupfreq[parent][curr] += 1

        hammingdist = 0
        for i in range(n):
            parent = self.find(i)

            if target[i] in groupfreq[parent] and groupfreq[parent][target[i]] > 0:
                groupfreq[parent][target[i]] -= 1
            
            else:
                hammingdist += 1

        return hammingdist

        