<?php
$log_file ='testcurl.txt';
$values = $_POST['db'];
$str = date("M d Y H:i:s",time()).' '.$id.' '.$values."\n";

//now we open the file
if(file_exists($log_file)){
	$fp=fopen($log_file,a); // the file is opened as append mode
	fwrite($fp,$str);
	fclose($fp);
}else{
	$fp = fopen($log_file,w);
	fwrite($fp, $str);
	fclose($fp);
}

?>