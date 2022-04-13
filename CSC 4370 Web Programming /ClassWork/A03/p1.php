<html>
<body>
<?php
function isBitten()
{
$r = rand(0,1);
if ($r == 1)
{
return true;
}
else
{
return false;
}
}
$result = isBitten();
if ($result == true)
{
echo "Charlie ate my lunch";
}
else
{
echo "Charlie did not ate my lunch";
}
?>
</body>
</html>