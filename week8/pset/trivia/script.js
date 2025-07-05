document.querySelector('#option1').onclick = function() {
    document.querySelector("#option1").style.backgroundColor = "red";
    document.querySelector("#feedback1").innerHTML = "Incorrect!";
}

document.querySelector('#option2').onclick = function() {
    document.querySelector("#option2").style.backgroundColor = "red";
    document.querySelector("#feedback1").innerHTML = "Incorrect!";
}

document.querySelector('#correct').onclick = function() {
    document.querySelector("#correct").style.backgroundColor = "green";
    document.querySelector("#feedback1").innerHTML = "Correct!";
}

document.querySelector('#form').addEventListener("submit", function(event) {
    event.preventDefault();
    let answer = document.querySelector('#answer').value;

    if (answer.toLowerCase() === 'washington')
    {
        document.querySelector('#answer').style.backgroundColor = "green";
        document.querySelector('#feedback2').innerHTML = "Correct!";
    }
    else
    {
        document.querySelector('#answer').style.backgroundColor = "red";
        document.querySelector('#feedback2').innerHTML = "Incorrect!";
    }
});



