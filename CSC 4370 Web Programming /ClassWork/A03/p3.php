<?php
$month = array ('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August','September', 'October', 'November', 'December');
for ($x = 0; $x <= 11; $x++) {
echo "$month[$x], ";
}
?>
<!--2-->
<?php
$month = array ('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August','September', 'October', 'November', 'December');
sort($month);
for ($x = 0; $x <= 11; $x++) {
echo "$month[$x], ";
}
?>
<!--3-->
<!--3i-->
<?php
$month = array ('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August','September', 'October', 'November', 'December');
foreach ($month as &$val) {
echo "$val, ";
}
?>
<!--3ii-->
<?php
$month = array ('January', 'February', 'March', 'April', 'May', 'June', 'July', 'August','September', 'October', 'November', 'December');
sort($month);
foreach ($month as &$val) {
echo "$val, ";
}
?>