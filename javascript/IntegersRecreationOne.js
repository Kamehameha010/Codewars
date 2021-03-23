/* 1, 246, 2, 123, 3, 82, 6, 41 are the divisors of number 246. Squaring these divisors we get: 1, 60516, 4, 15129, 9, 6724, 36, 1681.
 The sum of these squares is 84100 which is 290 * 290.Task

Find all integers between m and n (m and n integers such as 1 <= m <= n) such that the sum of their squared divisors is itself a square.

We will return an array of subarrays or of tuples (in C an array of Pair) or a string. The subarrays (or tuples or Pairs) will have two
elements: first the number the squared divisors of which is a square and then the sum of the squared divisors.
 */

function listSquared(m, n) {
    let result = [];
    for (let i = m; i <= n; ++i) {
        let divisors = [];
        for (let j = 1; j <= i; ++j) {
            if (i % j == 0)
                divisors.push(Math.pow(j,2));
        }
        let sum = divisors.length > 1 ? divisors.reduce((acc, cur) => acc + cur) : 1;

        if (Number.isInteger(Math.sqrt(sum))) {
            result.push([i, sum]);
        }

    }
    return result;
}


console.log(listSquared(1, 250));


