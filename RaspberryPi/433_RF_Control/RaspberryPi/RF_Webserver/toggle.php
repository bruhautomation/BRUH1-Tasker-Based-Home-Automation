<?php
$outletLight = $_POST['outletId'];
$outletStatus = $_POST['outletStatus'];
if ($outletLight == "1" && $outletStatus == "on") {
    $rfCode = "sudo python /home/pi/rf/rf.py a";
} else if ($outletLight == "1" && $outletStatus == "off") {
    $rfCode = "sudo python /home/pi/rf/rf.py b";
} else if ($outletLight == "2" && $outletStatus == "on") {
    $rfCode = "sudo python /home/pi/rf/rf.py c";
} else if ($outletLight == "2" && $outletStatus == "off") {
    $rfCode = "sudo python /home/pi/rf/rf.py d";
} else if ($outletLight == "3" && $outletStatus == "on") {
    $rfCode = "sudo python /home/pi/rf/rf.py e";
} else if ($outletLight == "3" && $outletStatus == "off") {
    $rfCode = "sudo python /home/pi/rf/rf.py f";
} else if ($outletLight == "4" && $outletStatus == "on") {
    $rfCode = "sudo python /home/pi/rf/rf.py g";
} else if ($outletLight == "4" && $outletStatus == "off") {
    $rfCode = "sudo python /home/pi/rf/rf.py h";
} else if ($outletLight == "5" && $outletStatus == "on") {
    $rfCode = "sudo python /home/pi/rf/rf.py i";
} else if ($outletLight == "5" && $outletStatus == "off") {
    $rfCode = "sudo python /home/pi/rf/rf.py j";
} else if ($outletLight == "6" && $outletStatus == "on") {
    $rfCode = "sudo /home/pi/wemo/wemo switch insight on";
} else if ($outletLight == "6" && $outletStatus == "off") {
    $rfCode = "sudo /home/pi/wemo/wemo switch insight off";
} else if ($outletLight == "7" && $outletStatus == "on") {
    $rfCode = "sudo python /home/pi/rf/rf.py k";
} else if ($outletLight == "7" && $outletStatus == "off") {
    $rfCode = "sudo python /home/pi/rf/rf.py l";
} else if ($outletLight == "8" && $outletStatus == "on") {
    $rfCode = "sudo python /home/pi/rf/rf.py m";
} else if ($outletLight == "8" && $outletStatus == "off") {
    $rfCode = "sudo python /home/pi/rf/rf.py n";	
} else if ($outletLight == "9" && $outletStatus == "on") {
    $rfCode = "sudo python /home/pi/rf/rf.py o";
} else if ($outletLight == "9" && $outletStatus == "off") {
    $rfCode = "sudo python /home/pi/rf/rf.py p";	
	
}
//$rfPath = '/var/www/rfoutlet/codesend ' . $rfCode;
shell_exec($rfCode);
echo json_encode(['success' => true, 'rfPath' => $rfPath]);
?>
