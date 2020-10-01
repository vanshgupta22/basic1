<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="upload.php" method="post" enctype="multipart/form-data">
    <input type="file" name="upfile[]" multiple>
    <input type="submit" value="Upload">
    </form>
    <br />

    <form method="post">
    Please enter the image name to delete: <input type="text" name="imgname"> 
    <input type="submit" name="submit" value="Delete">

    <br />

    

    <?php
        if(isset($_POST['submit'])){  ///code to delete an image from the directory
            $imgname = $_POST['imgname'];
            if(!file_exists("images/$imgname")){
                echo $imgname .' Not Present';
            }
            else{
                unlink("images/$imgname");
                echo 'Deleted '. $imgname;
            }
        }
    ?>
    <br />
    <br />

<a href="album.php">Click here </a>to view album. <br />


</body>
</html>