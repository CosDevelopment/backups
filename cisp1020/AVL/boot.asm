[org 0x07c00]


mov ah,0x0e
mov si, msg
jmp Print
mov si,othermsg
jmp Print
jmp $ ; jump to urrent address = infinite loop

; padding and magic number
msg: db 'hello world',0 
othermsg db 'josh a hoe',0
Print:

strloop:
mov cx,0
cmp [si],cx
jge printChar
ret
printChar:
mov al,[si]
int 0x10
add si,1
jmp strloop
times 510 - ($-$$) db 0

dw 0xaa55
