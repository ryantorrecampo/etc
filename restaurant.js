let list = ["Juanitos", "Wok", "Celaya", "ghengis"];

function rand(items) {
  return items[~~(items.length * Math.random())];
}

console.log(rand(list));
