<?php
	
$name = $_POST['name'];
$address = $_POST['address'];
$phone = $_POST['phone'];
$mobile = $_POST['mobile'];
$email = $_POST['email'];

if (!empty($fname)) || (!empty($address)) || (!empty($phone)) || (!empty($mobile)) ||
	(!empty($email)) {
		
		$conn = mysqli_connect('localhost','root','','maindb');
			// Check connection
			if(mysqli_connect_error())
			{
			echo 'MySQL Error: ' . mysqli_connect_error();
			}
			else{
					//mysqli_select_db($conn, 'newdb');
			$query = "INSERT INTO Customers (CUSTOMER_NAME, ADDRESS, PHONE, MOBILE, EMAIL)
						VALUES ($name, $address, $phone, $mobile, $email);
			";

			if(mysqli_query($conn,$query)){
				echo '1 Record added successfully.';
				}else{
				echo 'Error record not added.' . '<br>';
				}
			}
			mysqli_close($conn);

	}//if
else {
	echo"All field are required";
	die();	
}

















?>