let nums = [1,2,3,4,5,6,7];

// for each
nums.forEach(function(item, index) {
    console.log(item, index);
});

// map
const doubled = nums.map(function(item){
    return item*2;
});
console.log(doubled);

// filter
let evens = nums.filter(function (item) {
    return item % 2 === 0;
});
console.log(evens);

// reduce
let sum = nums.reduce(function(result, item) {
    return result+item;
}, 0);

console.log(sum);

// some
let hasNegativeNumbers = [1, 2, 3, -1, 4].some(function (item) {
    return item < 0;
})
console.log(hasNegativeNumbers);

// every
let allPostiveNumbers = nums.every(function (item) {
    return item > 0;
})

console.log(allPostiveNumbers);

const objects = [{id: 'a'}, {id: 'b', name: 'ryan'}, {id: 'c'}];
const found = objects.find(function (item) {
    return item.name === 'ryan';
});
console.log(found);

// find index
const foundIndex = objects.findIndex(function (item) {
    return item.id === 'c';
});
console.log(foundIndex);