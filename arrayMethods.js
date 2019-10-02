// ARRAY 1
const texasss = [
  {
    name: 'Mike',
    age: 23,
    gender: 'm',
    us: false,
  },
  {
    name: 'Liz',
    age: 20,
    gender: 'f',
    us: true,
  },
  {
    name: 'Chris',
    age: 102,
    gender: 'm',
    us: true,
  },
  {
    name: 'Chuloo',
    age: 27,
    gender: 'm',
    us: false,
  },
  {
    name: 'Annie',
    age: 30,
    gender: 'f',
    us: true,
  },
]

// Part 1 - Find all users older than 24
// Part 2 - Find the total age of all users
// Part 3 - List all female coders

const users24 = texasss.filter(item => item.age > 24);
const totalAgeT = texasss.reduce((prev, curr) => prev + curr.age, 0);
const femaleCoders = texasss.filter(item => item.gender == 'f');
console.log(users24);
console.log(totalAgeT);
console.log(femaleCoders);


// ARRAY 2
const newieyork = [
  {
    name: 'Michelle',
    age: 19,
    coder:true,
    gender: 'f',
    us: true,
  },
  {
    name: 'Sam',
    age: 25,
    coder:false,
    gender: 'm',
    us: false,
  },
  {
    name: 'Ivy',
    age: 26,
    coder:true,
    gender: 'f',
    us: false,
  },
  {
    name: 'Nick',
    age: 32,
    coder:true,
    gender: 'm',
    us: true,
  },
  {
    name: 'Jim Beglin',
    age: 65,
    coder:false,
    gender: 'm',
    us: true,
  },
]

// Part 1 - List all users in US in ascending order
// Part 2 - Sort all users by age
// Part 3 -  List all female coders

const usOnly = newieyork.filter(item => item.us == true);
const sortByAge = newieyork.sort((a,b) => a.age > b.age ? 1 : -1);
const femalesOnly = newieyork.filter(item => item.gender == 'f');

console.log(usOnly.sort((a,b) => a-b));
console.log(sortByAge);
console.log(femalesOnly);

// ARRAY 3
const vegzas = [
  {
    name: 'Charly',
    age: 32,
    coder:true,
    gender: 'm',
  },
  {
    name: 'Law',
    age: 21,
    coder:true,
    gender: 'm',
  },
  {
    name: 'Rosey',
    age: 42,
    coder:false,
    gender: 'f',
  },
  {
    name: 'Steph',
    age: 18,
    coder:true,
    gender:'f'
  },
  {
    name: 'Jon',
    age: 47,
    coder:false,
    gender: 'm',
  },
]

// Part 1 - Find the total age of male coders under 25
// Part 2 - List all male coders over 30
// Part 3 - Find the total age of everyone in texasss, newieyork and vegzas combined.

const total25 = function(arr) {
  return arr
    .filter(item => item.age < 25 && item.gender == 'm')
    .map(item => item.age)
    .reduce((prev, curr) => prev + curr)
}


const coders30 = vegzas.filter(item => item.age > 30 && item.gender == 'm');

const totalAges = [];

const age1 = texasss.map(item => totalAges.push(item));
const age2 = newieyork.map(item => totalAges.push(item));
const age3 = vegzas.map(item => totalAges.push(item));

const finalAges = totalAges.reduce((prev, next) => prev + next.name + " ", 'Names: ');

console.log('part 1');
console.log(total25(vegzas));
console.log(coders30);

