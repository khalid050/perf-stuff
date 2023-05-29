console.time("populateMatrix");

var size = 100000000
let regularString = "";

for (let i = 0; i < size; i++) {
  regularString += "a";
}



console.log(regularString);
console.timeEnd("populateMatrix");
