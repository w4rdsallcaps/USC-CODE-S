;TEAM 3 CEASAR CYPHER

.MODEL SMALL
.STACK 100h

.DATA
    SHIFT       EQU 3
    plaintext   DB 'HelloWorld', 0          ; original string (>=10 chars), null-terminated
    ciphertext  DB 32 DUP(?)                ; separate buffer for the encrypted string
    msg_out     DB 'Encrypted: $'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    MOV ES, AX

    ; ---- Encrypt the string ----
    LEA SI, plaintext       ; SI -> source (original string)
    LEA DI, ciphertext      ; DI -> destination (encrypted string)

ENCRYPT_LOOP:
    MOV AL, [SI]
    CMP AL, 0
    JE  ENCRYPT_DONE        ; stop at null terminator

    CMP AL, 'A'
    JL  COPY_CHAR
    CMP AL, 'Z'
    JLE SHIFT_UPPER

    CMP AL, 'a'
    JL  COPY_CHAR
    CMP AL, 'z'
    JLE SHIFT_LOWER

    JMP COPY_CHAR

SHIFT_UPPER:
    SUB AL, 'A'             ; normalize to 0-25
    ADD AL, SHIFT
    XOR AH, AH
    MOV BL, 26
    DIV BL                  ; AH = remainder = (char + shift) mod 26
    ADD AH, 'A'
    MOV AL, AH
    JMP STORE_CHAR

SHIFT_LOWER:
    SUB AL, 'a'             ; normalize to 0-25
    ADD AL, SHIFT
    XOR AH, AH
    MOV BL, 26
    DIV BL                  ; AH = remainder = (char + shift) mod 26
    ADD AH, 'a'
    MOV AL, AH
    JMP STORE_CHAR

COPY_CHAR:
    ; AL already holds the character to copy unchanged
    JMP STORE_CHAR

STORE_CHAR:
    MOV [DI], AL            ; write encrypted (or copied) char to ciphertext buffer
    INC SI
    INC DI
    JMP ENCRYPT_LOOP

ENCRYPT_DONE:
    MOV BYTE PTR [DI], 0    ; null-terminate the encrypted string

    ; ---- Print "Encrypted: " ----
    LEA DX, msg_out
    MOV AH, 09h
    INT 21h

    ; ---- Print the encrypted string ----
    LEA SI, ciphertext
PRINT_LOOP:
    MOV DL, [SI]
    CMP DL, 0
    JE  PRINT_DONE
    MOV AH, 02h
    INT 21h
    INC SI
    JMP PRINT_LOOP
PRINT_DONE:

    ;Exit
    MOV AH, 4Ch
    INT 21h
MAIN ENDP
END MAIN