class Solution(object):

    def noa(self, A, a):
        res = []
        for i in A:
            if i is a:
                continue
            else:
                res.append(i)
        
        return res
    
    def dfs(self, A, temp, ALL):
        if len(A) is 0:
            return
        
        if(len(A)) is 1:
            temp.append(A[0])
            ALL.append(temp)
            return
        
        for a in A:
            nowtemp = [z for z in temp]
            nowtemp.append(a)
            self.dfs(self.noa(A, a), nowtemp, ALL)
            
    
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        res = []
        
        temp = []
        self.dfs(nums, temp, res)
        
        return res
