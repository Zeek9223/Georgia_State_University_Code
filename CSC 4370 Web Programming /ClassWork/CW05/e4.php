<?php
if($_SERVER['REQUEST_METHOD'] == 'POST')
{
$_name = $_POST['name'];
$_section = $_POST['section'];
$_credit = $_POST['credit'];
$_cardtype = $_POST['cardtype'];
echo "<h1> Thanks, sucker! </h1>";
echo "<br>";
echo "Your information has been recorded.<br>";
echo "Name:<br> $_name<br>";
echo "Section:<br> $_section<br>";
echo "Credit:<br> $_credit($_cardtype)<br>";
}
else if ($show_hide_div == 1)
  
echo '
  
   <div class="a"><h1> Thanks, sucker! </h1> </div>
   <p></p>
<h3> Your informatiion has been recorded.</h3>
       <b><label >Name</label></b>
       &nbsp &nbsp &nbsp '.$name.'<p></p>
       <b><label >Section</label></b>
       &nbsp &nbsp &nbsp '.$section.'<p></p>
       <br>
       <b><label >Credit Card</label></b>
       &nbsp &nbsp &nbsp '.$credit.'('.$cardtype.')<p></p>
       </b>
       <br>
';
else if ($show_hide_div == 2)
   echo '
   <div class="a"><h1> Sorry</h1><div>
   <br>
   <h3>You did not fill out the form completely. <a href="sucker.php"> Try again?</h3>
   ';
?>