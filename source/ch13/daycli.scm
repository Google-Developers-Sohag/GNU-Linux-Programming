;  Define a couple of server constants
(define host "localhost")
(define port 13)

(define (stream-client)
  (let ((sock (socket-connect protocol-family/internet
               socket-type/stream host port)))
    (let ((result (read-string 100 (socket:inport sock))))
      (write-string result) 
      (newline)
      (close-socket sock) ) ) )

;
;  Invoke the stream client
;
(stream-client)

