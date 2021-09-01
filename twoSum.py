
def twoSum(nums,target):
    #dictionary to store the index
    hashdict = {}
    for i in range(len(nums)):
        # if target - nums[i] is in hashdict we can return it
        if target - nums[i] in hashdict:
            return [i,hashdict[target-nums[i]]]
        #store the value as index and index as value
        hashdict[nums[i]] = i



val = twoSum([2,7,11,15],9)
print(val)