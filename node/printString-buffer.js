console.time("stringBuffer");

var size = 100000000;
const stringBuffer = Buffer.alloc(size, 'a');
process.stdout.write(stringBuffer + "\n");
console.timeEnd("stringBuffer");
