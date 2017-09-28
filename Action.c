Action()
{
lr_start_transaction("MainURL");

	web_url("newtours.demoaut.com", 
		"URL=http://newtours.demoaut.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

lr_end_transaction("MainURL", LR_AUTO);

	lr_think_time(5);

lr_start_transaction("Register_Link");

	web_link("REGISTER", 
		"Text=REGISTER", 
		"Snapshot=t3.inf", 
		LAST);

lr_end_transaction("Register_Link", LR_AUTO);

	lr_think_time(5);

	web_set_sockets_option("SSL_VERSION", "2&3");

lr_start_transaction("Submit_Registration");

	web_submit_form("mercurycreate_account.php", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=firstName", "Value={fname}", ENDITEM, 
		"Name=lastName", "Value={lname}", ENDITEM, 
		"Name=phone", "Value=9876543210", ENDITEM, 
		"Name=userName", "Value={fname}.{lname}@fakeemail.org", ENDITEM, 
		"Name=address1", "Value=1 Overyonder St", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=city", "Value=Here", ENDITEM, 
		"Name=state", "Value=CA", ENDITEM, 
		"Name=postalCode", "Value=95125", ENDITEM, 
		"Name=country", "Value=UNITED STATES", ENDITEM, 
		"Name=email", "Value={fname}{lname}{RanVal}", ENDITEM, 
		"Name=password", "Value=password", ENDITEM, 
		"Name=confirmPassword", "Value=password", ENDITEM, 
		"Name=register.x", "Value=29", ENDITEM, 
		"Name=register.y", "Value=13", ENDITEM, 
		LAST);

lr_end_transaction("Submit_Registration", LR_AUTO);

	return 0;
}