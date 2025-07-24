document.querySelector('#title').addEventListener("click", function() {
    let red = Math.floor(Math.random() * 256);
    let green = Math.floor(Math.random() * 256);
    let blue = Math.floor(Math.random() * 256);

    document.querySelector('#title').style.color = `rgb(${red}, ${green}, ${blue})`;
    console.log(red, green, blue);
});


