<?php
$conn = mysqli_connect('localhost','root','','dborder');

	if(mysqli_connect_error()){
		echo 'MySQL Error: ' . mysqli_connect_error();}
	else{

	$query = "INSERT INTO CUSTOMER(CUSTOMER_NAME, ADDRESS, PHONE, MOBILE, EMAIL) 
	
			VALUES('$_POST[customerName]', '$_POST[customerAddress]', '$_POST[customerPhone]', '$_POST[customerMobile]', '$_POST[customerEmail]')";
	
	if(mysqli_query($conn,$query1)){
		echo '1 Record added successfully.';
	}else{
		echo 'Error record not added.' . '<br>';
		}
	
	}
?>