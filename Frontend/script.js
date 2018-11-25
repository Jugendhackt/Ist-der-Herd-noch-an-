  var an = true;
function toggle(){
  if(an){
  document.getElementById("anzeige").innerHTML ="Der Herd ist an";
  $("#image").attr("src","Icon.v.2.Fire.png");
}
  else {
    document.getElementById("anzeige").innerHTML ="Der Herd ist aus";
    $("#image").attr("src","Icon.v.2.NoFire.png");
  }
  
}


$(document).ready(function(){
  getstate();
  setInterval(getstate,1000);
});
function getstate(){
  $.get("http://http.stg.freifunk-iot.de/sample.json", function(data, status){
      an= data.an;
      console.log("Data: " + an + "\nStatus: " + status);
      if (status) {

      }
  });

}
