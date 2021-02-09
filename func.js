function touched() {
let text = {
    "persons": [
        {
            "age": "?",
            "name": "Arudina"
        },
        {
            "age": 19,
            "name": "Saito"
        }
    ]
}
document.write('Kyaaa Someone touched me!');
let jso = JSON.parse(text);
console.log(jso)
}