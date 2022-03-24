<html>
    <head>
        <title>
        </title>
    </head>
    <body>
        
    <?php
    function remove_all($str,$replace) {
        $remove = "";
        for($i=0; $i<strlen($str); $i++){
        if($str[$i]!=$replace[0])
        $remove .= $str[$i];
        }
        return $remove;
        }
        $results = remove_all("Summer is Here","e");
        echo $results;
?>

    </body>
</html>