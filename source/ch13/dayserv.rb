require 'socket'

# Create a new TCP Server using port 13
servsock = TCPserver::new("daytime")

# Debug data -- emit the server socket info
print("server address : ", servsock.addr::join(":"), "\n")

while true

  # Await a connection from a client socket
  clisock = servsock::accept

  # Emit some debugging data on the peer
  print("accepted ", clisock.peeraddr::join(":"), "\n")
  print(clisock, " is accepted\n")

  # Emit the time through the socket to the client
  clisock.write( Time::new )
  clisock.write( "\n" )

  # Close the client connection
  clisock.close

end

