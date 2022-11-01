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
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
# Step 7. Creating links between the nodes
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail
$ns duplex-link $n3 $n4 2Mb 10ms DropTail
$ns duplex-link $n3 $n5 2Mb 10ms DropTail
# Step8. Setting Queue Size of link (n2-n3) to 10
$ns queue-limit $n2 $n3 10
#Step9. Provide node positions to visualize in NAM window
$ns duplex-link-op $n0 $n2 orient right-down
$ns duplex-link-op $n1 $n2 orient right-up
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link-op $n3 $n4 orient right-up
$ns duplex-link-op $n3 $n5 orient right-down
#Step 10. Monitoring the queue for link (n2-n3) (n3-n4). (for NAM)
$ns duplex-link-op $n2 $n3 queuePos 0.5
#Step 11 Setting up a TCP connection
set tcp [new Agent/TCP]
$tcp set class_ 1
$ns attach-agent $n0 $tcp
#Step 12 If we setup tcp traffic source then connect it with tcp sink
set sink [new Agent/TCPSink]
$ns attach-agent $n4 $sink
$ns connect $tcp $sink
$tcp set fid_ 2
#Step 13 Setting up a FTP over TCP connection
set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ftp set type_ FTP
#Step 14 Setup a UDP connection
set udp [new Agent/UDP]
$ns attach-agent $n1 $udp
#Step 15 If we setup udp traffic source then connect it with null
set null [new Agent/Null]
$ns attach-agent $n5 $null
$ns connect $udp $null
$udp set fid_ 1
#Step 16 Setting up a CBR over UDP connection
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false
#Step 17 Scheduling events for the CBR and FTP agents
$ns at 0.1 "$cbr start"
$ns at 1.0 "$ftp start"
$ns at 4.0 "$ftp stop"
$ns at 4.5 "$cbr stop"
$ns at 5.0 "finish"
#Step 18 Run the simulation
$ns run