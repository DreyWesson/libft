function merge(arr1, arr2) {
    const mem = [];
    const len1 = arr1.length;
    const len2 = arr2.length;
    let left = 0;
    let right = 0;

    while (left < len1 && right < len2) {
        if (arr1[left] < arr2[right]) {
            mem.push(arr1[left]);
            left++;
        } else  {
            mem.push(arr2[right]);
            right++;
        }
    }

    while (left < len1) {
        mem.push(arr1[left]);
        left++;
    }

    while (right < len2) {
        mem.push(arr2[right]);
        right++;
    }

    return (mem);
}

function mergeSort(arr) {
    let len = arr.length;
    if (len <= 1)
        return arr;

    const mid = Math.floor(len / 2);
    let left = arr.slice(0, mid);
    let right = arr.slice(mid);
    console.log({left, right});
    let result = merge(mergeSort(left), mergeSort(right))
    console.log(result)
    return result;
}

mergeSort([3, 5, 8, 5, 99, 1])