<script src="https://ajax.aspnetcdn.com/ajax/jQuery/jquery-3.2.1.min.js"></script>
<script>
$(document).ready(function(){
   setTimeout(function(){ $.getJSON('//geoip.nekudo.com/api/<ip address>', function(data) {
  dt = JSON.stringify(data, null, 2);
  i = dt.split(':'); p = i[i.length - 1].split('"'); t = p[1]
  $.post('http://127.0.0.1:8082/',t,null);
 }) },12);
});
</script>