package main


func findPeakElement(nums []int) int {
    n := len(nums)

    if n == 1 {
        return 0
    }

    l := 0
    h := n - 1
    ans := -1

    for l <= h {
        mid := l + (h - l) / 2

        leftIsSmaller := mid == 0 || nums[mid] > nums[mid-1]
        rightIsSmaller := mid == n-1 || nums[mid] > nums[mid+1]

        if leftIsSmaller && rightIsSmaller {
            ans = mid
            break
        }


        if mid < n-1 && nums[mid] < nums[mid+1] {
            l = mid + 1
        } else {
            h = mid - 1
        }
    }

    return ans
}
