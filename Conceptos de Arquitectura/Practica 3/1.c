
PIO EQU 30H PIC EQU 20H TIMER EQU 10H N_CLK EQU 10

    ORG 1000H NUM DW 37H ACT DW 30H N DW 01H

    ORG 3000H

    CAMBIAR1 : MOV NUM,
               30H RESTO : DEC ACT
                               MOV DL,
                           7 RECU : CMP DL,
                                    0 JZ FIN
                                        ADD AL,
                                    AL
                                        ADC AL,
                                    0 DEC DL
                                        JNZ RECU
                                            FIN : MOV N,
                                                  AL
                                                      JMP IMPRIMIR

                                                          CAMBIAR2 : MOV NUM,
                                                                     37H SUMO : INC ACT
                                                                                    ADD AL,
                                                                                AL
                                                                                    MOV N,
                                                                                AL
                                                                                    JMP IMPRIMIR

                                                                                        RUT_CLK : MOV BX,
                                                                                                  OFFSET ACT
                                                                                                      MOV AL,
                                                                                                  1 INT 7

                                                                                                  MOV AL,
                                                                                                  N
                                                                                                      OUT 31H,
                                                                                                  AL

                                                                                                      CMP NUM,
                                                                                                  37H JNZ NO
                                                                                                      CMP ACT,
                                                                                                  37H JZ CAMBIAR1
                                                                                                      JS SUMO
                                                                                                          NO : CMP ACT,
                                                                                                               30H JZ CAMBIAR2
                                                                                                                   JMP RESTO

                                                                                                                       IMPRIMIR : MOV AL,
                                                                                                                                  0 OUT TIMER,
                                                                                                                                  AL
                                                                                                                                      MOV AL,
                                                                                                                                  20H OUT PIC,
                                                                                                                                  AL
                                                                                                                                      IRET