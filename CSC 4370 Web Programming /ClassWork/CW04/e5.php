<html>
    <head>
        <title>
        </title>
    </head>
    <body>
        
    <?php
function count_words($str) {
$ss=explode(" ",$str);
$wca = array();
foreach($ss as $word => $word_count)
{
   if (array_key_exists( $word_count , $wca))
{
$wca[$word_count]+=1;
}
else
{
$wca[$word_count]=1;
}
}
print_r($wca);
}
$str =strtolower("Hey Hey well");
count_words($str);
?>
    </body>
</html>