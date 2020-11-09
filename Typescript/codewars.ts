function descendingOrder(n: number) {
  return n.toString().split("")
    .map(x => parseInt(x))
    .sort((a, b) => b - a).join("");
}

function countBits(n: number) {
  // Program Me
  return [...n.toString(2)]
    .map(Number)
    .reduce((acc, curr) => acc += curr);
}

function isSquare(n: number): boolean {
  if (n < 0) return false;
  return /\d+?:\./.test(Math.sqrt(n).toString())
}

function bouncingBall(h: number, bounce: number, window: number): number {
  const isValid = h > 0 && (bounce > 0 && bounce < 1) && window < h;
  if (!isValid)
    return -1;
  return h > window ? 2 + bouncingBall((h * bounce), bounce, window) : -1
}

function squareDigits(num: number) {
  // may the code be with you
  return parseInt(Array.of(...num.toString()).map(x => Math.pow(parseInt(x), 2)).join(""));
}

//js
function diamond(n: number) {
  if (n <= 0 || n % 2 == 0) return null;
  if (n == 1) return "*\n";
  let space: number = Math.round(n / 2);
  let str: string = "";
  for (let i = 1; i <= n; i += 2) {
    str += " ".repeat(--space);
    for (let j = 1; j <= i; ++j)
      str += "*";
    str += "\n";
  }

  return str + (str.split("\n").reverse().slice(2).join("\n") + "\n");
}
/* 
expect(toBase64('this is a string!!')).to.equal('dGhpcyBpcyBhIHN0cmluZyEh');
expect(fromBase64('dGhpcyBpcyBhIHN0cmluZyEh')).to.equal('this is a string!!');
  }); */


function toBase64(str: string): string {
  // Encode this string to Base64
  //return Buffer.from(str).toString('base64')
  return btoa(str);
}

function fromBase64(str: string): string {
  // Decode this string from Base64
  //ts return Buffer.from(str,'base64').toString()
  return atob(str);
}


