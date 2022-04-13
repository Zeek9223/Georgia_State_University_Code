
<?php
$count=0;
echo '<table style="width:300px" border="1" cellspacing="1" cellpadding="1" align="center">';
{
echo "<tr>";
for($y=0;$y<8;$y++)
{
$count=$count+1;
if($count%2 == 0)
{
echo '<td height="35" width="35" style="background-color:red;"></td>'; 
}
else{
echo '<td height="35" width="35" style="background-color:black;>"</td>';
}
}
echo "</tr>";
}
echo "</table></html>";
?>