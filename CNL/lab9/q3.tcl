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

# Step 6. Creation of four nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# Step 7. Creating links between the nodes
$ns duplex-link $n0 $n1 2Mb 20ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail


# #Step9. Provide node positions to visualize in NAM window
# $ns duplex-link-op $n0 $n1 orient right-down
# $ns duplex-link-op $n2 $n3 orient left

#Step 11 Setting up a TCP connection
set tcp1 [new Agent/TCP]
$tcp1 set class_ 1
$ns attach-agent $n0 $tcp1

#Step 12 If we setup tcp traffic source then connect it with tcp sink
set sink [new Agent/TCPSink]
$ns attach-agent $n1 $sink
$ns connect $tcp1 $sink
$tcp1 set fid_ 2

#Step 13 Setting up a FTP over TCP connection
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ftp1 set type_ FTP

#Step 11 Setting up a TCP connection
set tcp2 [new Agent/TCP]
$tcp2 set class_ 2
$ns attach-agent $n2 $tcp2

#Step 12 If we setup tcp traffic source then connect it with tcp sink
set sink [new Agent/TCPSink]
$ns attach-agent $n3 $sink
$ns connect $tcp2 $sink
$tcp2 set fid_ 1

#Step 13 Setting up a FTP over TCP connection
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
$ftp2 set type_ FTP

# # Step 9. Setup a UDP connection
# set udp [new Agent/UDP]
# $ns attach-agent $n2 $udp

# # Step 10. If we setup udp traffic source then connect it with null
# set null [new Agent/Null]
# $ns attach-agent $n3 $null
# $ns connect $udp $null
# $udp set fid_ 1

# # Step 11. Setting up a CBR over UDP connection
# set cbr [new Application/Traffic/CBR]
# $cbr attach-agent $udp
# $cbr set type_ CBR
# $cbr set packet_size_ 1000
# $cbr set rate_ 1mb
# $cbr set random_ false

#Step 17 Scheduling events for the CBR and FTP agents
$ns at 0.1 "$ftp1 start"
$ns at 5.0 "$ftp1 stop"
$ns at 0.1 "$ftp2 start"
$ns at 5.0 "$ftp2 stop"
# $ns at 0.1 "$cbr start"
# $ns at 5.0 "$cbr stop"
$ns at 6.0 "finish"

#Step 18 Run the simulation
$ns run
