<?php
if($_SERVER['REQUEST_METHOD'] == 'POST')
{
echo "<h1> Thanks, sucker! </h1>";
echo "<br>";
echo "Your information has been recorded.<br>";
echo "Name:<br> $_name<br>";
echo "Section:<br> $_section<br>";
echo "Credit:<br> $_credit($_cardtype)<br>";
}
?>