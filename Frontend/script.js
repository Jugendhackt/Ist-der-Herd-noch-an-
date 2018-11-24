  var an = true;
function toggle(){
  if(an){
  document.getElementById("anzeige").innerHTML ="der Herd ist an";
  }
  else {
    document.getElementById("anzeige").innerHTML ="der Herd ist aus";
  }
    an = !an;
}
