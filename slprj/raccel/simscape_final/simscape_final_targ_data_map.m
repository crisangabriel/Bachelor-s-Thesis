    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (rtP)
        ;%
            section.nData     = 33;
            section.data(33)  = dumData; %prealloc

                    ;% rtP.ArrayCurrent
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtP.ArrayVoltage
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 3111;

                    ;% rtP.Irradiance
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 3294;

                    ;% rtP.RepeatingSequence_rep_seq_y
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3311;

                    ;% rtP.RepeatingSequence_rep_seq_y_jww4cxb3xy
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 3313;

                    ;% rtP.StateSpace_DS_param
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 3315;

                    ;% rtP.TransferFcn_A
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 3319;

                    ;% rtP.TransferFcn_C
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 3320;

                    ;% rtP.FromWs_Time0
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 3321;

                    ;% rtP.FromWs_Data0
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 3323;

                    ;% rtP.StateSpace_AS_param
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 3325;

                    ;% rtP.StateSpace_BS_param
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 3341;

                    ;% rtP.StateSpace_CS_param
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 3361;

                    ;% rtP.StateSpace_DS_param_cz3yopvi0n
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 3385;

                    ;% rtP.StateSpace_X0_param
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 3415;

                    ;% rtP.donotdeletethisgain_Gain
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 3419;

                    ;% rtP.LookUpTable1_bp01Data
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 3420;

                    ;% rtP.uMHzsamples_Amp
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 3422;

                    ;% rtP.uMHzsamples_Period
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 3423;

                    ;% rtP.uMHzsamples_Duty
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 3424;

                    ;% rtP.uMHzsamples_PhaseDelay
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 3425;

                    ;% rtP.Saturation_UpperSat
                    section.data(22).logicalSrcIdx = 21;
                    section.data(22).dtTransOffset = 3426;

                    ;% rtP.Saturation_LowerSat
                    section.data(23).logicalSrcIdx = 22;
                    section.data(23).dtTransOffset = 3427;

                    ;% rtP.LookUpTable1_bp01Data_cnvefmrvbz
                    section.data(24).logicalSrcIdx = 23;
                    section.data(24).dtTransOffset = 3428;

                    ;% rtP.donotdeletethisgain_Gain_fvxcttqcfp
                    section.data(25).logicalSrcIdx = 24;
                    section.data(25).dtTransOffset = 3430;

                    ;% rtP.donotdeletethisgain_Gain_lgq0rbvoze
                    section.data(26).logicalSrcIdx = 25;
                    section.data(26).dtTransOffset = 3431;

                    ;% rtP.TransferFcn1_A
                    section.data(27).logicalSrcIdx = 26;
                    section.data(27).dtTransOffset = 3432;

                    ;% rtP.TransferFcn1_C
                    section.data(28).logicalSrcIdx = 27;
                    section.data(28).dtTransOffset = 3433;

                    ;% rtP.SwitchCurrents_Value
                    section.data(29).logicalSrcIdx = 28;
                    section.data(29).dtTransOffset = 3434;

                    ;% rtP.SwitchCurrents_Value_aynlaxlp3g
                    section.data(30).logicalSrcIdx = 29;
                    section.data(30).dtTransOffset = 3436;

                    ;% rtP.Constant_Value
                    section.data(31).logicalSrcIdx = 30;
                    section.data(31).dtTransOffset = 3439;

                    ;% rtP.Constant_Value_ctutefl32y
                    section.data(32).logicalSrcIdx = 31;
                    section.data(32).dtTransOffset = 3440;

                    ;% rtP.eee_Value
                    section.data(33).logicalSrcIdx = 32;
                    section.data(33).dtTransOffset = 3441;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtP.PVVICurves2DLookupTable_maxIndex
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (rtB)
        ;%
            section.nData     = 18;
            section.data(18)  = dumData; %prealloc

                    ;% rtB.abuqvgw4ua
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.m4cchbruom
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

                    ;% rtB.cnkqn5cq34
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 4;

                    ;% rtB.komxp1m4wp
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 5;

                    ;% rtB.o20komhacz
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 6;

                    ;% rtB.la52j4vcgf
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 12;

                    ;% rtB.lxbjkrt1na
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 15;

                    ;% rtB.lo4k4qjncy
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 16;

                    ;% rtB.h0uehzgjjn
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 17;

                    ;% rtB.k0pihcl1dy
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 18;

                    ;% rtB.gpis0zvuxp
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 19;

                    ;% rtB.o1kbtlj4kh
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 20;

                    ;% rtB.hqowogsuxf
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 21;

                    ;% rtB.oh1bjpifcg
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 22;

                    ;% rtB.d5gcx4z2ek
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 23;

                    ;% rtB.muug30hfrt
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 24;

                    ;% rtB.eegmnycxav
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 25;

                    ;% rtB.fxy4mvun3n
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 26;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtB.ow25jkzfhv
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% rtB.mwopycrmyl
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% rtB.avft534bzw
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 9;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (rtDW)
        ;%
            section.nData     = 21;
            section.data(21)  = dumData; %prealloc

                    ;% rtDW.dnnn0nu0zb
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.aoqbzw24yh
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 4;

                    ;% rtDW.fr1e1xckpl
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 5;

                    ;% rtDW.fjp44ee5ax
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 6;

                    ;% rtDW.no4vepxkrz
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 7;

                    ;% rtDW.nb12wxexy1
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 11;

                    ;% rtDW.ef10paht5m
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 15;

                    ;% rtDW.cosdp1wu4w
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 19;

                    ;% rtDW.lvrt4bac12
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 23;

                    ;% rtDW.dutnzjrzkf
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 24;

                    ;% rtDW.j01dz0mnne
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 25;

                    ;% rtDW.jsymurmz45
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 26;

                    ;% rtDW.eppwlrjdji
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 27;

                    ;% rtDW.j0laytj34w
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 28;

                    ;% rtDW.f5vqif0wgf
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 29;

                    ;% rtDW.dqvjx3jolm
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 30;

                    ;% rtDW.bxebon4qnu
                    section.data(17).logicalSrcIdx = 16;
                    section.data(17).dtTransOffset = 31;

                    ;% rtDW.ia3rykgwil
                    section.data(18).logicalSrcIdx = 17;
                    section.data(18).dtTransOffset = 32;

                    ;% rtDW.kwtpxxi2kh
                    section.data(19).logicalSrcIdx = 18;
                    section.data(19).dtTransOffset = 33;

                    ;% rtDW.eetww0o3hn
                    section.data(20).logicalSrcIdx = 19;
                    section.data(20).dtTransOffset = 34;

                    ;% rtDW.h2hkmnje1k
                    section.data(21).logicalSrcIdx = 20;
                    section.data(21).dtTransOffset = 35;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.cy1425fqxu
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% rtDW.npdjbxplf3.AS
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.c5zfcz3wqy.TimePtr
                    section.data(2).logicalSrcIdx = 23;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.d0znnfktb4.AS
                    section.data(3).logicalSrcIdx = 24;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.oztoqsargi.LoggedData
                    section.data(4).logicalSrcIdx = 25;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.p3sfttpmzm.LoggedData
                    section.data(5).logicalSrcIdx = 26;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.lmmjbpotji.LoggedData
                    section.data(6).logicalSrcIdx = 27;
                    section.data(6).dtTransOffset = 7;

                    ;% rtDW.hkktxe1lpb.LoggedData
                    section.data(7).logicalSrcIdx = 28;
                    section.data(7).dtTransOffset = 8;

                    ;% rtDW.dkrsl0kl2e.LoggedData
                    section.data(8).logicalSrcIdx = 29;
                    section.data(8).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% rtDW.bisrotwkmc
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bzwtriiduw
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.h01almjvh0
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.b020pa3iys
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% rtDW.g50qfbcmcf
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bkwsxkusxs
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.bfivdkhzmt
                    section.data(3).logicalSrcIdx = 36;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.n23urvprlg
                    section.data(4).logicalSrcIdx = 37;
                    section.data(4).dtTransOffset = 4;

                    ;% rtDW.bkas1funiq
                    section.data(5).logicalSrcIdx = 38;
                    section.data(5).dtTransOffset = 629;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.alk0fbzgi4
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.i4bhulkutv.PrevIndex
                    section.data(2).logicalSrcIdx = 40;
                    section.data(2).dtTransOffset = 11;

                    ;% rtDW.g1wwsnainz
                    section.data(3).logicalSrcIdx = 41;
                    section.data(3).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% rtDW.ous2glk3vz
                    section.data(1).logicalSrcIdx = 42;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% rtDW.jme2moc1et
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.beqq1oqdr3
                    section.data(2).logicalSrcIdx = 44;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.kvqfradwlq
                    section.data(3).logicalSrcIdx = 45;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 13;
            section.data(13)  = dumData; %prealloc

                    ;% rtDW.afcgtasyrg
                    section.data(1).logicalSrcIdx = 46;
                    section.data(1).dtTransOffset = 0;

                    ;% rtDW.bxgmk1eaw0
                    section.data(2).logicalSrcIdx = 47;
                    section.data(2).dtTransOffset = 1;

                    ;% rtDW.nbbupkxuro
                    section.data(3).logicalSrcIdx = 48;
                    section.data(3).dtTransOffset = 2;

                    ;% rtDW.p4rnq0dwuk
                    section.data(4).logicalSrcIdx = 49;
                    section.data(4).dtTransOffset = 3;

                    ;% rtDW.pwk2utciwp
                    section.data(5).logicalSrcIdx = 50;
                    section.data(5).dtTransOffset = 4;

                    ;% rtDW.kxrkzyjlww
                    section.data(6).logicalSrcIdx = 51;
                    section.data(6).dtTransOffset = 5;

                    ;% rtDW.ni51rbhl2o
                    section.data(7).logicalSrcIdx = 52;
                    section.data(7).dtTransOffset = 6;

                    ;% rtDW.mmrindr4fr
                    section.data(8).logicalSrcIdx = 53;
                    section.data(8).dtTransOffset = 7;

                    ;% rtDW.iuyncjvcn5
                    section.data(9).logicalSrcIdx = 54;
                    section.data(9).dtTransOffset = 8;

                    ;% rtDW.j0d32edslo
                    section.data(10).logicalSrcIdx = 55;
                    section.data(10).dtTransOffset = 9;

                    ;% rtDW.kldd00soyg
                    section.data(11).logicalSrcIdx = 56;
                    section.data(11).dtTransOffset = 10;

                    ;% rtDW.ewri5fxxq1
                    section.data(12).logicalSrcIdx = 57;
                    section.data(12).dtTransOffset = 11;

                    ;% rtDW.kbqlsft4jh
                    section.data(13).logicalSrcIdx = 58;
                    section.data(13).dtTransOffset = 12;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 2638811857;
    targMap.checksum1 = 2278787672;
    targMap.checksum2 = 549373888;
    targMap.checksum3 = 185719008;

