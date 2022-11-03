# Step 1. define global simulator object
set ns [new Simulator]
# Step 2. Define different colors for data flows (for NAM)
$ns color 1 Green
$ns color 2 Pink
# Step 3. Opening the NAM trace file
set nt [open simulate.nam w]
$ns namtrace-all $nt
# Step 4. Opening the Trace file
set tr [open simulate.tr w]
$ns trace-all $tr
# Step 5. Define a 'finish' procedure
proc finish {} {
global ns nt tr
$ns flush-trace
#Close the NAM trace file
close $nt
close $tr
exec nam simulate.nam &
exit 0
}
# Step 6. Creation of six nodes
set n0 [$ns node]
set n1 [$ns node]
# Step 7. Creating links between the nodes
$ns duplex-link $n0 $n1 10Mb 10ms DropTail
#Step 8. Provide node positions to visualize in NAM window
$ns duplex-link-op $n0 $n1 orient right-down
#Step 9 Setting up a TCP connection
set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n0 $tcp
#Step 10 If we setup tcp traffic source then connect it with tcp sink
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink
$ns connect $tcp $sink
$tcp set fid_ 2
#Step 11 Setting up a FTP over TCP connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
#Step 12 Scheduling events for the CBR and FTP agents
$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 5.0 "finish"
#Step 13 Run the simulation
$ns run