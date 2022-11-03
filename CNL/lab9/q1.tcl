# Step 1. define global simulator object
set ns [new Simulator]
# Step 2. Define different colors for data flows (for NAM)
$ns color 1 Purple
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

#Step8. Provide node positions to visualize in NAM window
$ns duplex-link-op $n0 $n1 orient right

#Step 9 Setup a UDP connection
set udp [new Agent/UDP]
$ns attach-agent $n0 $udp
#Step 10 If we setup udp traffic source then connect it with null
set null [new Agent/Null]
$ns attach-agent $n1 $null
$ns connect $udp $null
$udp set fid_ 1
#Step 11 Setting up a CBR over UDP connection
set cbr [new Application/Traffic/CBR]
$cbr attach-agent $udp
$cbr set type_ CBR
$cbr set packet_size_ 1000
$cbr set rate_ 1mb
$cbr set random_ false
#Step 12 Scheduling events for the CBR and FTP agents
$ns at 0.1 "$cbr start"
$ns at 4.5 "$cbr stop"
$ns at 5.0 "finish"
#Step 13 Run the simulation
$ns run