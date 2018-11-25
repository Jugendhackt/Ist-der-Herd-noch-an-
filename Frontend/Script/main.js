  var an = true;
function toggle(){
  if(an){
  document.getElementById("anzeige").innerHTML ="Der Herd ist an";
  $("#image").attr("src","Icon.v.2.Fire.png");
  // playSound('alarm');
}
  else {
    document.getElementById("anzeige").innerHTML ="Der Herd ist aus";
    $("#image").attr("src","Icon.v.2.NoFire.png");
  }
    an = !an;
}


$(document).ready(function(){
  getstate();
  setInterval(getstate,5000);
  // function playSound(filename){
  //         var mp3Source = '<source src="Script/sound/' + filename + '.mp3" type="audio/mpeg"></source>';
  //         var oggSource = '<source src="Script/sound/' + filename + '.ogg" type="audio/ogg"></source>';
  //         // var embedSource = '<embed hidden="true" autostart="true" loop="false" src="Scipt/sound/' + filename +'.mp3">';
  //         console.log("ALARRRM");
  //         document.getElementById("sound").innerHTML='<audio autoplay controls loop>' + mp3Source + oggSource + 'Your browser does not support the audio element. </audio>';
  //         // var audio = new Audio(mp3Source);
  //         // audio.play();
  // }
});
function getstate(){
  $.get("http://http.stg.freifunk-iot.de/sample.json", function(data, status){
      an= data.an;
      console.log("Data: " + an + "\nStatus: " + status);
      if (status) {
        toggle();
      }
  });
}
