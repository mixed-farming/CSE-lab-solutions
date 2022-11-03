# Step 1. define global simulator object
set ns [new Simulator]
# Step 2. Define different colors for data flows (for NAM)
$ns color 1 green
$ns color 2 Red
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
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

# Step 7. Creating links between the nodes
$ns duplex-link $n1 $n2 2Mb 20ms DropTail
$ns duplex-link $n3 $n4 1Mb 10ms DropTail

#Step9. Provide node positions to visualize in NAM window
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n3 $n4 orient right-down

#Step 11 Setting up a TCP connection
set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n1 $tcp
#Step 12 If we setup tcp traffic source then connect it with tcp sink
set sink [new Agent/TCPSink]
$ns attach-agent $n2 $sink
$ns connect $tcp $sink
$tcp set fid_ 2
#Step 13 Setting up a FTP over TCP connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

#Step 11 Setting up a TCP connection
set tcp [new Agent/TCP]
$tcp set class_ 2
$ns attach-agent $n3 $tcp
#Step 12 If we setup tcp traffic source then connect it with tcp sink
set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 1
#Step 13 Setting up a FTP over TCP connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP

#Step 17 Scheduling events for the CBR and FTP agents
$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 5.0 "finish"
#Step 18 Run the simulation
$ns run