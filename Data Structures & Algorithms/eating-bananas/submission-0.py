class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left, right = 1, max(piles)

        while left < right:
            k = (left + right) // 2
            hours = sum((p + k - 1) // k for p in piles)

            if hours <= h:
                right = k
            else:
                left = k + 1

        return left