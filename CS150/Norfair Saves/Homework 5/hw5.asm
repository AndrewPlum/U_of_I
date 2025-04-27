;Name: Andrew Plum
;Class: CS 150
;Date: 5/8/22

NextSubsetMemberGet:

SetUp:
                    pop r1; pop return call address here
                    pop r0; pop return call address here
                    pop r16; arguments passed in
                    pop r17; arguments passed in
                    push r0; push return call address back on stack
                    push r1; push return call address back on stack
                    push r25; preserve value on stack
                    push r24; preserve value on stack
                    push r23; preserve value on stack
                    push r22; preserve value on stack
                    push r21; preserve value on stack
                    push r20; preserve value on stack
                    push r19; preserve value on stack
                    push r18; preserve value on stack
                    eor r1, r1; clear in case of immediate special case
                    eor r0, r0; clear in case of immediate special case

SpecialCaseAllClear:
                    cpi r16, 0x00
                    brbc 1, SpecialCaseAllSet
                    cpi r17, 0x00
                    brbs 1, Done

SpecialCaseAllSet:
                    cpi r16, 0xff
                    brbc 1, CountSetNumOnesOrig
                    cpi r17, 0xff
                    brbs 1, Done

CountSetNumOnesOrig:
                    mov r19, r17
                    mov r18, r16
                    ldi r20, 0x00; counter of set bits
                    ldi r21, 0x10; counter of how many times left to execute
                    ldi r22, 0xff; for subtracting 1
                    ldi r23, 0x01; for adding 1

CheckIfBitSetLow:
                    cpi r21, 0x08; check if still in lower register
                    brbs 1, CheckIfBitSetHigh; branch if zero bit set
                    add r21, r22; decrement execution counter
                    lsr r18
                    brbc 0, CheckIfBitSetLow
                    add r20, r23; add 1 to counter of set bits
                    rjmp CheckIfBitSetLow

CheckIfBitSetHigh:
                    cpi r21, 0x00; check if done shifting
                    brbs 1, FindNextPattern; branch if zero bit set
                    add r21, r22; decrement execution counter
                    lsr r19
                    brbc 0, CheckIfBitSetHigh
                    add r20, r23; add 1 to counter of set bits
                    rjmp CheckIfBitSetHigh

FindNextPattern:
                    mov r19, r17
                    mov r18, r16
                    mov r0, r18
                    mov r1, r19

AddFindNextPattern:
                    add r0, r23; add 1 to lower register
                    mov r18, r0; copy possible answer
                    mov r19, r1; copy possible answer
                    brbc 0, CountSetNumOnesNew; skip carry if zero bit clear
                    add r1, r23; add 1 to higher register if carry
                    brbs 0, DoneMaxDetected; if upper register carry done because max pattern detected
                    mov r19, r1; copy possible answer again if changed from earlier

CountSetNumOnesNew:
                    ldi r24, 0x00; counter of set bits of new pattern
                    ldi r25, 0x10; counter of how many times left to execute for new pattern

NewCheckBitSetLow:
                    cpi r25, 0x08; check if still in lower register
                    brbs 1, NewCheckBitSetHigh; branch if zero bit set
                    add r25, r22; decrement execution counter
                    lsr r18
                    brbc 0, NewCheckBitSetLow
                    add r24, r23; add 1 to counter of set bits
                    rjmp NewCheckBitSetLow

NewCheckBitSetHigh:
                    cpi r25, 0x00; check if done shifting
                    brbs 1, CheckIfNewPattern; branch if zero bit set
                    add r25, r22; decrement execution counter
                    lsr r19
                    brbc 0, NewCheckBitSetHigh
                    add r24, r23; add 1 to counter of set bits
                    rjmp NewCheckBitSetHigh

CheckIfNewPattern:
                    cp r20, r24
                    brbc 1, AddFindNextPattern

Done:
                    pop r18; pop preserved value from stack
                    pop r19; pop preserved value from stack
                    pop r20; pop preserved value from stack
                    pop r21; pop preserved value from stack
                    pop r22; pop preserved value from stack
                    pop r23; pop preserved value from stack
                    pop r24; pop preserved value from stack
                    pop r25; pop preserved value from stack
                    ret; end of subroutine

DoneMaxDetected:
                    eor r0, r0; clear
                    eor r1, r1; clear
                    rjmp Done; pops will be done there and then return



