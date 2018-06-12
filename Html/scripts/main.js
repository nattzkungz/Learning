function revealMessage() {
    document.getElementById("hiddenMessage").style.display = 'block';
}

function countdown(){
  var currentVal = getElementById("countdown").innerhtml;
  var newVal = currentVal - 1;
  getElementById("countdown").innerhtml = newVal;
}
