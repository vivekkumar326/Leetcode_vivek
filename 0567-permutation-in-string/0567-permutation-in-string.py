class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1)>len(s2):
            return False
        count1=[0]*26
        count2=[0]*26

        for ch in s1:
            count1[ord(ch)-ord('a')]+=1
        k=len(s1)

        for i in range(k):
            count2[ord(s2[i])-ord('a')]+=1
        if count1==count2:
            return True

        #window slide to check 

        for i in range(k,len(s2)):
            count2[ord(s2[i])-ord('a')]+=1

            #remove prevoius character
            count2[ord(s2[i-k])-ord('a')]-=1
            if count1==count2:
                return True
        return False

        