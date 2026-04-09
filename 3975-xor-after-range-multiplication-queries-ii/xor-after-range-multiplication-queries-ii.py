# class Solution:
#     def xorAfterQueries(self, nums: List[int], queries: List[List[int]]) -> int:
#         n = len(nums)
#         blocksize = ceil(sqrt(n))

#         smallkmap = defaultdict(list)

#         for(query : queries):
#             L = query[0]
#             R = query[1]
#             K = query[2]
#             V = query[3]

#             if(k >= blockSize)
#                 for i in range(L,R):
#                     nums[i]= (nums[i] * V) % M;
#             else
#                 smallKMap[K].append(query)
        
#         for()




class Solution:
    def xorAfterQueries(self, nums, queries):
        M = 10**9 + 7
        n = len(nums)
        block_size = math.ceil(math.sqrt(n))

        smallKMap = defaultdict(list)

        # Process large K directly, store small K queries
        for L, R, K, V in queries:
            if K >= block_size:
                for i in range(L, R + 1, K):
                    nums[i] = (nums[i] * V) % M
            else:
                smallKMap[K].append((L, R, V))

        # Process small K queries
        for K, all_queries in smallKMap.items():
            diff = [1] * n

            for L, R, V in all_queries:
                diff[L] = (diff[L] * V) % M

                steps = (R - L) // K
                nxt = L + (steps + 1) * K

                if nxt < n:
                    # modular inverse using Fermat’s theorem
                    diff[nxt] = (diff[nxt] * pow(V, M - 2, M)) % M

            # cumulative product with step K
            for i in range(n):
                if i - K >= 0:
                    diff[i] = (diff[i] * diff[i - K]) % M

            # apply updates
            for i in range(n):
                nums[i] = (nums[i] * diff[i]) % M

        # compute XOR result
        result = 0
        for num in nums:
            result ^= num

        return result