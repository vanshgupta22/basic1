<!DOCTYPE html>

<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="styles.css">
    <title>Albums</title>
</head>

<body>
<h1>Album</h1>
<?php
    // Starting Sessio
    session_start();  
    // Scanning Directory and making array
    $directory = "images/";
    $arr = scandir($directory);
?>
<!-- Controls of Album -->
<form action="" method="post">
<input type="submit" name="first" value="First" class="buttons">
<input type="submit" name="pre" value="Prev" class="buttons">
<input type="submit" name="next" value="Next" class="buttons">
<input type="submit" name="last" value="Last" class="buttons">
</form>
<br />
<br />

<?php
// Total Images
$tot = count($arr);

if($tot > 2) {

    if(isset($_POST['first']) || (isset($_POST['pre']) && $_SESSION['count'] === 2)) {
        echo "<img style='height: 300px;widht: 300px;' src='images/$arr[2]' alt='albums_images'>";
        $_SESSION['count'] = 2;
    }
    else if(isset($_POST['last']) || (isset($_POST['next']) && $_SESSION['count'] === ($tot-1))) {
        $last = $tot - 1;
        echo "<img style='height: 300px;widht: 300px;' src='images/$arr[$last]' alt='albums_images'>";
        $_SESSION['count'] = $last;
    }
    else if(isset($_POST['pre'])) {
        $_SESSION['count']--;
        $ind = $_SESSION['count'];
        echo "<img style='height: 300px;widht: 300px;' src='images/$arr[$ind]' alt='albums_images'>";
    }
    else if(isset($_POST['next'])) {
        $_SESSION['count']++;
        $ind = $_SESSION['count'];
        echo "<img style='height: 300px;widht: 300px;' src='images/$arr[$ind]' alt='albums_images'>";
    }
} 
else {
    echo "Images Directory Empty, Please  <a href='newupload.php'> click here</a> to upload new images.";
}
?>
<br>
<br>
<br>


<form action="newupload.php">
<input type="submit" class="buttons" value="Click Here To Delete or Upload Images">
</form>



</body>
</html>