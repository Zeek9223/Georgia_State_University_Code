<html>

<head>
<title>10 Best Restaurants in Atlanta </title>
</head>
<body>
<h2>
Top 10 Best Restaurants in Atlanta
</h2>
<?php
$restaurants=array("Fogo de Chão"=>"40.50",
"Aviva by Kameel"=> "15.00",
"Bone's Restaurant"=> "65.00",
"Umi Sushi Buckhed"=> "40.50",
"Fandangles"=>"30.00",
"Capital Grille"=>"60.50",
"Canoe"=> "35.50",
"One Flew South"=>"21.00",
"Fox Bros.BBQ"=>"15.00",
"South City Kitechen Midtown"=>"29.00"
);
if(isset($_GET['Cost']))
{
arsort($restaurants);
}
if(isset($_GET['Name']))
{
ksort($restaurants);
}
?>
<form>
<a href='Restaurants.php?Cost=true'>Average Cost</a>
&nbsp; &nbsp;&nbsp;&nbsp;
<a href='Restaurants.php?Name=true'>Name</a>
<br> <br>
<table border=1>
<tr>
<th>Restaurant Name</th>
<th>Average Cost</th>
</tr>
<?php
foreach($restaurants as $name => $cost)
{
?>
<tr>
<td><?php echo $name ?> </td>
<td><?php echo "$".$cost ?> </td>
</tr>
<?php
}
?>
</table>
</form>
</body>
</html>