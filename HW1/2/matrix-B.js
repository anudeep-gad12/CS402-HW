const prompt = require("prompt-sync")({ sigint: true });

const randomNumbers = (type) => {
  if (type === "1") return Math.floor(Math.random() * 1000);
  if (type === "2") return Math.random() * 1000;
};

/*********************************  
        Taking input of 1st matrix
 **********************************************/
const inputMatrix1 = (rows, columns, type) => {
  let matrix = new Array(rows).fill(new Array(columns).fill(0));
  // console.log("Matrix1: ", matrix);

  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      matrix[i][j] = randomNumbers(type);
    }
  }
  console.log(matrix);

  return matrix;
};

/*********************************  
        Taking input of 2nd matrix
 **********************************************/

const inputMatrix2 = (rows, columns, type) => {
  let matrix = new Array(rows).fill(new Array(columns).fill(0));

  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix[i].length; j++) {
      matrix[i][j] = randomNumbers(type);
    }
  }

  return matrix;
};

/*********************************  
        Result matrix
 **********************************************/

const result = (rows, columns) => {
  let res = new Array(rows).fill(0).map((e) => new Array(columns).fill(0));
  return res;
};

/*********************************  
       Matrix multiplication
 **********************************************/

const multiplyMatrix = (mat1, mat2, res) => {
  let sum = 0;
  for (let i = 0; i < res.length; i++) {
    for (let j = 0; j < res[i].length; j++) {
      sum = 0;
      for (let k = 0; k < mat2.length; k++) {
        sum += mat1[i][k] * mat2[k][j];
      }
      res[i][j] = sum;
    }
  }
  return res;
};

/*********************************  
 The main function, this is where the code starts execution
        
 **********************************************/

const main = () => {
  const rows1 = Number(prompt("Enter the number of rows of 1st matrix: "));
  const columns1 = Number(
    prompt("Enter the number of columns of 1st matrix: ")
  );
  const rows2 = Number(prompt("Enter the number of rows of 1st matrix: "));
  const columns2 = Number(
    prompt("Enter the number of columns of 1st matrix: ")
  );
  if (isNaN(rows1) || isNaN(rows2) || isNaN(columns1) || isNaN(columns2))
    return "Enter a valid Number, Try Again!";

  if (columns1 !== rows2)
    return "The number of columns of 1st matrix must match the number of rows of 2nd matrix! Try again";

  const numType = prompt(
    "Enter the number type PRESS1 : Integer, PRESS2 : Double : "
  );

  console.log(numType);

  if (numType !== "1" && numType !== "2")
    return "Enter a valid number type, Try Again!";

  const mat1 = inputMatrix1(rows1, columns1, numType);
  const mat2 = inputMatrix2(rows2, columns2, numType);
  const res = result(rows1, columns2);
  console.log("Matrix1 : ", mat1);
  console.log("Matrix2 : ", mat2);
  return multiplyMatrix(mat1, mat2, res);
};

console.log("Result : ", main());
