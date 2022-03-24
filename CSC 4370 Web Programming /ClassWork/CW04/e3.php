<html>
    <head>
        <title>
        </title>
    </head>
    <body>
        
    <?php
function triangle($n)//function

{
for ($i = 0; $i < $n; $i++)
{
for($j = 0; $j <= $i; $j++ )
{
echo "* ";
}
echo "\n";
}
}
$n =readline('Enter a value: ');
triangle($n);

?>

    </body>
</html>