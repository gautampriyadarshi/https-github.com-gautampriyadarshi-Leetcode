/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filteredArr = [];
    for (let i = 0; arr.length > i; i++) {
        if (Boolean(fn(arr[i], i)) === true) {
           filteredArr.push(arr[i]);
        }
    }
    return filteredArr;
};