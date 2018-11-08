class Solution(object):

    def noa(self, A, index):
        res = []
        for i, ele in enumerate(A):
            if i is index:
                continue
            else:
                res.append(ele)
        
        return res
    
    def dfs(self, A, temp, ALL):
        if len(A) is 0:
            return
        
        if(len(A)) is 1:
            temp.append(A[0])
            if temp not in ALL:
                ALL.append(temp)
            return
        
        for i,a in enumerate(A):
            nowtemp = [z for z in temp]
            nowtemp.append(a)
            self.dfs(self.noa(A, i), nowtemp, ALL)
            
    
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        res = []
        
        temp = []
        self.dfs(nums, temp, res)
        
        return res
