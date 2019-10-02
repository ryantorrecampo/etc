let artists = ['Travis Scott', 'Playboi Carti', 'Gunna', 'Lil Baby', 'Drake', 'Lil Uzi Vert'];
let songs = ['Houstonfornication', 'Magnolia', 'Drip or Drown', 'Never Recover', 'Going Bad', 'XO TOUR LIF3'];

const playlist = [];

for(let i in songs){
  playlist.push({});
}

let i = 1;
playlist.map(item => {
  let curr = songs.shift();
  let curr2 = artists.shift();
  item.artist = curr2;
  item.song = curr;
  item.sayName = function(){
    console.log(`[${i}] You are currently listening to ${this.song} by ${this.artist}`);
    i++;
  }
  songs.push(curr);
  artists.push(curr2);
});

playlist.map(item => item.sayName());