class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        n=len(nums)-2
        closets=nums[0]+nums[1]+nums[2]
        for i in range(n):
            left=i+1
            right=len(nums)-1
            while left<right:
                current=nums[i]+nums[left]+nums[right]
                if abs(current-target)<abs(closets-target):
                    closets=current
                if current <target:
                    left+=1
                elif current> target:
                    right-=1
                else:
                    return target
        return closets
        