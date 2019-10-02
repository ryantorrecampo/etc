promises = new Promise(function(resolve, reject){
  setTimeout(function() {
    resolve(console.log("Promise resolved!"))}, 2000);
  });
console.log(promises);
