class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        if len(p)>len(s):
            return []
        count_p=[0]*26
        count_s=[0]*26


        for ch in p:
            count_p[ord(ch)-ord('a')]+=1
        k=len(p)

        #first window
        for i in range(k):
            count_s[ord(s[i])-ord('a')]+=1
        result=[]

        if count_s==count_p:
            result.append(0)
        #now slide the window to check next window
        for i in range(k,len(s)):
            count_s[ord(s[i])-ord('a')]+=1
            count_s[ord(s[i-k])-ord('a')]-=1

            if count_p==count_s:
                result.append(i-k+1)
        return result
        

        