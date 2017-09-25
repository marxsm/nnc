org 100h
jmp global
a:
	DD 0

b:
	DD 0

c:
	DD 0

Addition:
Addition_a:
	DD 0
	POP EBX
	MOV EBX, [EBX]
	MOV EAX, EBX
	MOV EBX, [Addition_a]
	MOV [EBX], EAX


Addition_b:
	DD 0
	POP EBX
	MOV EBX, [EBX]
	MOV EAX, EBX
	MOV EBX, [Addition_b]
	MOV [EBX], EAX


	PUSHD [Addition_a]
	PUSHD [Addition_b]
	POP EBX
	MOV EAX, [EBX]
	POP EBX
	ADD EAX, [EBX]
	PUSH EAX

	RET

Multiply:
Multiply_a:
	DD 0
	POP EBX
	MOV EBX, [EBX]
	MOV EAX, EBX
	MOV EBX, [Multiply_a]
	MOV [EBX], EAX


Multiply_b:
	DD 0
	POP EBX
	MOV EBX, [EBX]
	MOV EAX, EBX
	MOV EBX, [Multiply_b]
	MOV [EBX], EAX


	PUSHD [Multiply_a]
	PUSHD [Multiply_b]
	POP EBX
	MOV EAX, [EBX]
	POP EBX
	MUL dword [EBX]
	PUSH EAX

	RET

main:
	PUSHD [a]
_C1:
	DD 6
	PUSHD [_C1]
	POP EAX
	POP EBX
	MOV [EBX], EAX

	PUSHD [b]
_C2:
	DD 9
	PUSHD [_C2]
	POP EAX
	POP EBX
	MOV [EBX], EAX

	PUSHD [c]
_C3:
	DD 69
	PUSHD [_C3]
	POP EAX
	POP EBX
	MOV [EBX], EAX

	PUSHD [a]
	PUSHD [b]
	CALL Addition

	PUSHD [a]
	PUSHD [b]
	PUSHD [c]
	CALL Multiply

	PUSHD [a]
	PUSHD [b]
	CALL Addition

	PUSHD [a]
	PUSHD [b]
	PUSHD [c]
	CALL write

	PUSHD [a]
	PUSHD [b]
	CALL Addition

	PUSHD [a]
	PUSHD [b]
	PUSHD [c]
	CALL Multiply

	PUSHD [a]
	PUSHD [b]
	CALL Addition

	PUSHD [a]
	PUSHD [b]
	PUSHD [c]
_C4:
	DD 0
	PUSHD [_C4]
	RET

global:
	CALL main
