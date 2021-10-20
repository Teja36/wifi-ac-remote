const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head><meta name="viewport" content="width=device-width, initial-scale=1.0, user-scalable=no">

<title>LG AC Remote</title>

<style>
  html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}
  body {margin-top: 50px;} 
  h2 {  color: #444444;margin-bottom: 50px;}
  .button {display: block;width: 80px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}
  .button-on {background-color: #1abc9c;}
  .button-on:active {background-color: #16a085;}
  select {font-size: 15px;margin-bottom: 10px;}
  input {display: block;width: 150px;background-color: #1abc9c;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}
  
</style>
</head>

<body>

<h2>LG AC Remote<h2>

<a class="button button-on" href="/OnOff">On/Off</a>

<a class="button button-on" href="/Swing">Swing</a>

<a class="button button-on" href="/JetCool">JetCool</a>

<form action="/OffTimer">
<select name="timer" >

  <option value="1"> 1 hr </option>
  <option value="2" > 2 hrs </option>
  <option value="3" > 3 hrs </option>
  <option value="4" > 4 hrs </option>
  <option value="45" > 4 hrs 30 mins </option>
  <option value="5" > 5 hrs </option>
  <option value="55" selected> 5 hrs 30 mins </option>
  <option value="6" > 6 hrs </option>

</select>
<input  type="submit" value="Set Timer">
</form> 

<a class="button button-on" href="/TimerCancel">Cancel</a>

</body>
</html>
)=====";
