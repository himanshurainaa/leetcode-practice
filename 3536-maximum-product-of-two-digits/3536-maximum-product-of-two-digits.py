class Solution(object):
    def maxProduct(self, n):
        b=str(n)
        product=1
        max1=0
        max2=0
        for i in b:
            x=int(i)
            if max1<x:
                max2=max1
                max1=x
            elif max2<x:
                max2=x
        product=max1*max2
        return product      