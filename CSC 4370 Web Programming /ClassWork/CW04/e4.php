<html>
    <head>
        <title>
        </title>
    </head>
    <body>
        
    <?php  
function word_count($str){   
  $wspace = 0;  
  $words = 1; 
  $include = $wspace; 
  $counter = 0; 
  $i = 0;
  while ($i < strlen($str)){ 
      if ($str[$i] == " "||$str[$i] == "\n" || $str[$i] == "\t")  
          $include = $wspace; 
      else if ($include == $wspace) {  
          $include = $words;  
          ++$counter; } 
      ++$i;  } 
  return $counter; }
$str = "hello,how are you ";  
echo "Words: " . word_count($str);  
?>  

    </body>
</html>