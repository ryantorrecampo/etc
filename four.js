const readline= require('readline');
const rl= readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

var eps='&'
rl.question('\np,b,z=p,XY <- this format (taken directly from question)\n\n', (answer)=>
    {
        //console.log(answer.length);
        var data=answer.split("=");
        //console.log(data);
        var loc1=data[0].split(","), loc2=data[1].split(",");
        var i=loc1[0];
        var j=loc1[1];
        var k=loc1[2];
        var r=loc2[0];
        var s=loc2[1];
        //console.log(i+'/'+j+'/'+k+'/'+r+'/'+s);
        //process.exit(0);
        if(s.length>1)
        {
            console.log(`[${i},${k},p]->${j}[${r},${s[0]},p][p,${s[1]},p]|${j}[${r},${s[0]},q][q,${s[1]},p]\n[${i},${k},q]->${j}[${r},${s[0]},p][p,${s[1]},q]|${j}[${r},${s[0]},q][q,${s[1]},q]\n`);
            process.exit(0);
        }
        else if(s[0]==eps)
        {
            console.log(`[${i},${k},${r}]->${j}\n`);
            process.exit(0);
        }
        else
        {
            console.log(`[${i},${k},p]->${j}[${r},${s},p]\n[${i},${k},q]->${j}[${r},${s},q]\n`);
            process.exit(0);
        }
    }
)