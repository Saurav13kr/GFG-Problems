//{ Driver Code Starts
// Driver code
const readline = require('readline');
const rl = readline.createInterface({input : process.stdin, output : process.stdout});

let inputLines = [];
let currentLine = 0;

rl.on('line', (line) => { inputLines.push(line.trim()); });

rl.on('close', () => { main(); });

function readLine() { return inputLines[currentLine++]; }

function main() {
    let tc = parseInt(readLine());
    while (tc > 0) {
        let arr = readLine().split(' ').map(Number);
        let ob = new Solution();
        let ans = ob.findTriplet(arr);
        // console.log(ans);
        if (ans) {
            console.log("true");
        } else {
            console.log("false");
        }
        console.log("~");
        tc--;
    }
}
// } Driver Code Ends


// User function Template for javascript

class Solution {
    findTriplet(arr) {
        arr.sort((a, b) => a - b);
        
        for (let k = 2; k < arr.length; k++) 
        {
            let [i, j] = [0, k - 1];
            
            while (i < j) 
            {
                const sum = arr[i] + arr[j];
                if (sum === arr[k]) return true;
                sum < arr[k] ? i++ : j--;
            }
        }
        
        return false;
    }
}

