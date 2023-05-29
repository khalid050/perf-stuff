function initializeMatrix(rows, cols) {
  const size = rows * cols;
  const buffer = new ArrayBuffer(size * 4);
  const matrix = new Int32Array(buffer);
  return matrix;
}

function printMatrix(rows, cols, matrix) {
  for (let i = 0; i < rows; i++) {
    let rowStr = '';
    for (let j = 0; j < cols; j++) {
      rowStr += matrix[i * cols + j] + ' ';
    }
    process.stdout.write('[ ' + rowStr + ']\n');
  }
}

// Bruh!
// function printMatrix(rows, cols, matrix) {
//   for (let i = 0; i < rows; i++) {
//     for (let j = 0; j < cols; j++) {
//       process.stdout.write(matrix[i * cols + j] + ' ');
//     }
//     process.stdout.write(']\n');
//   }
// }

function populateMatrix(rows, cols, matrix) {
  for (let i = 0; i < rows; i++) {
    for (let j = 0; j < cols; j++) {
      matrix[i * cols + j] = i + (2 * i * j);
    }
  }
}

function main() {
  const rows = 5000;
  const cols = 5000;
  console.time("populateMatrix");
  const matrix = initializeMatrix(rows, cols);
  populateMatrix(rows, cols, matrix);
  printMatrix(rows, cols, matrix);
  console.timeEnd("populateMatrix");
}

main();
