var array = new Array(100_000_000).fill(0);

function giveMeArray(array) {};

console.time("passByReference");
giveMeArray(array);
console.timeEnd("passByReference");


console.time("passByValue");
giveMeArray([...array]);
console.timeEnd("passByValue");