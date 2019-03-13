      PROGRAM GEN
      IMPLICIT NONE
C
C SAMPLE CALLING PROGRAM FOR SUBROUTINE CREATENEW
C SUBROUTINE CREATENEW GENERATES THE INSTANCES OF 2BP ACCORDING TO
C            LODI, MARTELLO AND VIGO
C            HEURISTIC AND METAHEURISTIC APPROACHES FOR A CLASS OF TWO-DIMENSIONAL
C            BIN PACKING PROBLEMS
C            INFORMS, JOURNAL ON COMPUTING, TO APPEAR
C
      CHARACTER*2 CL(10),FNAME*20
      INTEGER     H(100),W(100),I,II,J,N,HBIN,WBIN
C
C I          = CLASS OF THE INSTANCE
C N          = NUMBER OF THE ITEMS OF THE INSTANCE
C H(1,...,N) = HEIGHTS OF THE ITEMS
C H(1,...,N) = WIDTHS OF THE ITEMS
C HBIN       = HEIGHT OF THE BIN
C WBIN       = WIDTH OF THE BIN
C J          = NUMBER OF THE INSTANCE (1,...,10)
C
      CL(1)  = '01'
      CL(2)  = '02'
      CL(3)  = '03'
      CL(4)  = '04'
      CL(5)  = '05'
      CL(6)  = '06'
      CL(7)  = '07'
      CL(8)  = '08'
      CL(9)  = '09'
      CL(10) = '10'
      DO I=1,10
         FNAME = 'CLASS_'//CL(I)//'.2BP'
         OPEN(UNIT=10,FILE=FNAME,STATUS='UNKNOWN')
         DO N=20,100,20
            DO J=1,10
               CALL CREATENEW(I,N,H,W,HBIN,WBIN,J)
               WRITE(10,'(I5,8X,A)')I,'PROBLEM CLASS'              
               WRITE(10,'(I5,8X,A)')N,'N. OF ITEMS'
               WRITE(10,'(2I5,3X,A)')J,(I-1)*50+(N-20)/2+J,
     *'RELATIVE AND ABSOLUTE N. OF INSTANCE'
               WRITE(10,'(2I5,3X,A)')HBIN,WBIN,'HBIN,WBIN'
               WRITE(10,'(2I5,3X,A)')H(1),W(1),'H(I),W(I),I=1,...,N'
               DO II=2,N
                  WRITE(10,'(2I5)')H(II),W(II)
               ENDDO
               WRITE(10,*)
            ENDDO
         ENDDO
         CLOSE(10)
      ENDDO
C
      STOP
      END
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
      SUBROUTINE CREATENEW(CLASS,NITEM,HITEM,WITEM,HBIN,WBIN,PROB)
      IMPLICIT NONE
C
      INTEGER CLASS,NITEM,HITEM(*),WITEM(*),HBIN,WBIN,PROB
      INTEGER HMAX,WMAX,J,HLI,HLS,WLI,WLS
      REAL    SEED
      REAL    X,P1,P2,P3,RNN
C
C CLASS =  1 ----> Berkey and Wang 1
C CLASS =  2 ----> Berkey and Wang 2
C CLASS =  3 ----> Berkey and Wang 3
C CLASS =  4 ----> Berkey and Wang 4
C CLASS =  5 ----> Berkey and Wang 5
C CLASS =  6 ----> Berkey and Wang 6
C CLASS =  7 ----> Martello and Vigo 1
C CLASS =  8 ----> Martello and Vigo 2
C CLASS =  9 ----> Martello and Vigo 3
C CLASS = 10 ----> Martello and Vigo 4
C
      SEED = -2000
      X = NITEM*PROB*31.47-SEED
      CALL RNNINIT(X)
C
      IF (CLASS .EQ. 1) THEN
         HBIN = 10
         WBIN = 10
         HMAX = 10
         WMAX = 10
      ENDIF
      IF (CLASS .EQ. 2) THEN
         HBIN = 30
         WBIN = 30
         HMAX = 10
         WMAX = 10
      ENDIF
      IF (CLASS .EQ. 3) THEN
         HBIN = 40
         WBIN = 40
         HMAX = 35
         WMAX = 35
      ENDIF
      IF (CLASS .EQ. 4) THEN
         HBIN = 100
         WBIN = 100
         HMAX = 35
         WMAX = 35
      ENDIF
      IF (CLASS .EQ. 5) THEN
         HBIN = 100
         WBIN = 100
         HMAX = 100
         WMAX = 100
      ENDIF
      IF (CLASS .EQ. 6) THEN
         HBIN = 300
         WBIN = 300
         HMAX = 100
         WMAX = 100
      ENDIF
      IF (CLASS .GT. 6) THEN
         IF (CLASS .GT. 10) THEN
            WRITE(6,*)'CLASS UNKNOWN = ',CLASS
            STOP
         ENDIF
         HBIN = 100
         WBIN = 100
         HMAX = 100
         WMAX = 100
         IF (CLASS .EQ. 7) THEN
            P1=0.7
            P2=0.1
            P3=0.1
         ENDIF
         IF (CLASS .EQ. 8) THEN
            P1=0.1
            P2=0.7
            P3=0.1
         ENDIF
         IF (CLASS .EQ. 9) THEN
            P1=0.1
            P2=0.1
            P3=0.7
         ENDIF
         IF (CLASS .EQ. 10) THEN
            P1=0.1
            P2=0.1
            P3=0.1
         ENDIF
C
         DO J=1,NITEM
            HLI = 1
            WLI = 1
            HLS = HMAX
            WLS = WMAX
            X = RNN()
            IF (X .LT. P1) THEN
               WLI = WMAX*2/3
               HLS = HMAX/2
            ELSE 
               IF (X .LT. (P1+P2)) THEN
                  HLI = HMAX*2/3
                  WLS = WMAX/2
               ELSE 
                  IF (X .LT. (P1+P2+P3)) THEN
                     WLI = WMAX/2
                     HLI = HMAX/2
                  ELSE
                     WLS = WMAX/2
                     HLS = HMAX/2
                  ENDIF
               ENDIF
            ENDIF
            HITEM(J) = INT((HLS-HLI+1)*RNN()) + HLI
            WITEM(J) = INT((WLS-WLI+1)*RNN()) + WLI
         ENDDO
      ELSE
         DO J=1,NITEM
            HITEM(J) = INT((HMAX)*RNN()) + 1
            WITEM(J) = INT((WMAX)*RNN()) + 1
         ENDDO
      ENDIF
C
      RETURN
      END
C
C
C     ------------------
      SUBROUTINE RNNINIT(SEED)
C     ------------------
      REAL    SEED,U,RNN,VAL
      INTEGER I,ISEED
      COMMON /RNNC/VAL
C
      VAL = 0.0
      ISEED = INT(SEED) + 1
      DO I=1,ISEED
         U = RNN()
      ENDDO
      RETURN
      END
C
C     --------------------
      REAL FUNCTION RNN()
C     --------------------
      INTEGER IA,IM,IC
      REAL    VAL
      PARAMETER (IA=7141, IC=54773, IM=259200)
      COMMON /RNNC/VAL
      VAL = MOD (INT(VAL)*IA+IC,IM)
      RNN = VAL/IM
      RETURN
      END
C