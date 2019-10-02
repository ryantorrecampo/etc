let arr = ['George Louis Coztanza', 'Alexander Timothy Wilhelm', 'Bob Jonathan Sacamano'];

const initials = word => {
    let name = word.split(' ');
    let x = name.map(item => item.charAt(0));
    x.reverse();
    return x;
}

arr.forEach(function(item) {
    console.log(initials(item));
});
