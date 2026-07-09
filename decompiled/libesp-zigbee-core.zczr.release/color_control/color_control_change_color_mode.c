/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_change_color_mode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint color_control_change_color_mode(int param_1,int param_2)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  ushort uVar7;
  ushort uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  int extraout_a1;
  undefined4 uVar17;
  ushort *puVar18;
  byte *pbVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  byte local_50 [2];
  ushort uStack_4e;
  undefined2 uStack_4c;
  undefined1 auStack_48 [8];
  int iStack_40;
  byte bStack_3c;
  undefined1 uStack_3b;
  byte bStack_38;
  undefined1 auStack_36 [14];
  
  pbVar19 = local_50;
  local_50[1] = 0;
  uStack_4e = 0;
  uStack_4c = 0;
  local_50[0] = (byte)param_2;
  if (param_1 == 0) {
    param_1 = __assert_func(0,0,0);
    param_2 = extraout_a1;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  iVar9 = color_control_srv_get_attr_desc(uVar1,0x4001);
  bVar2 = **(byte **)(iVar9 + 8);
  memset(auStack_48,0,0x18);
  uVar10 = zcl_packet_to_message(auStack_48,param_1);
  if (uVar10 == 0) {
    uStack_3b = (undefined1)param_2;
    bStack_38 = 0xfe;
    iStack_40 = param_1;
    bStack_3c = bVar2;
    zcl_core_action_schedule(0x1c,auStack_48);
    uVar10 = (uint)bStack_38;
    if (uVar10 != 0) goto _L0;
    memcpy(local_50,auStack_36,6);
    uVar8 = uStack_4e;
    uVar7 = uStack_4c;
_L0:
    uStack_4c = uVar7;
    uStack_4e = uVar8;
    if (local_50[0] == 2) {
_L0:
      puVar18 = &uStack_4e;
      uVar17 = 7;
      goto _L0;
    }
    if (2 < local_50[0]) {
      if (local_50[0] != 3) {
        return 0x87;
      }
_L0:
      puVar18 = &uStack_4e;
      uVar17 = 0x4000;
      goto _L0;
    }
    if (local_50[0] == 0) goto _L0;
_L0:
    color_control_srv_set_attr_value(uVar1,3,&uStack_4e);
    puVar18 = &uStack_4c;
    uVar17 = 4;
  }
  else {
_L0:
    if (uVar10 != 0xfe) {
      return uVar10;
    }
    if (bVar2 == 2) {
      iVar9 = color_control_srv_get_attr_desc(uVar1,7);
      uVar8 = 0;
      if (iVar9 != 0) {
        uVar8 = **(ushort **)(iVar9 + 8);
      }
      if (local_50[0] != 0) {
        if (local_50[0] != 1) {
          uVar7 = uStack_4c;
          if (local_50[0] != 3) goto _L0;
          __floatunsisf(uVar8);
          uVar17 = __divsf3(0x447a0000);
          if (uVar8 < 0xfb) {
            __mulsf3(0xc041a77a);
            __addsf3(0x4006d9b5);
            __mulsf3(uVar17);
            __addsf3(0x3e63fa5a);
            __mulsf3(uVar17);
            uVar17 = __addsf3(0x3e7628cc);
            __mulsf3(0x40453b86);
            __subsf3(0x40bbf2c9);
            __mulsf3(uVar17);
            __addsf3(0x40701283);
            __mulsf3(uVar17);
            uVar12 = 0x3ebd7294;
          }
          else {
            __mulsf3(0xbe884164);
            __subsf3(0x3e6ffb8b);
            __mulsf3(uVar17);
            __addsf3(0x3f60b0a9);
            __mulsf3(uVar17);
            uVar17 = __addsf3(0x3e383a54);
            if (uVar8 < 0x1c3) {
              __mulsf3(0xbf747772);
              __subsf3(0x3fafe553);
              __mulsf3(uVar17);
              __addsf3(0x4005d902);
              __mulsf3(uVar17);
              uVar12 = 0x3e2b8228;
            }
            else {
              __mulsf3(0xbf8d9de8);
              __subsf3(0x3fac8ee0);
              __mulsf3(uVar17);
              __addsf3(0x400be030);
              __mulsf3(uVar17);
              uVar12 = 0x3e4f0cae;
            }
          }
          uVar13 = __subsf3(uVar12);
          iVar9 = __gtsf2(uVar17,0x3f800000);
          uVar12 = 0x3f800000;
          if (iVar9 < 1) {
            uVar12 = uVar17;
          }
          iVar9 = __gtsf2(uVar13,0x3f800000);
          uVar17 = 0x3f800000;
          if (iVar9 < 1) {
            uVar17 = uVar13;
          }
          iVar9 = __ltsf2(uVar17,0);
          uVar13 = 0;
          if (-1 < iVar9) {
            uVar13 = uVar17;
          }
          __mulsf3(uVar13,0x477eff00);
          uVar8 = __fixunssfsi();
          uStack_4c = uVar8;
          iVar9 = __ltsf2(uVar12,0);
          uVar17 = 0;
          if (-1 < iVar9) {
            uVar17 = uVar12;
          }
          __mulsf3(uVar17,0x477eff00);
          uVar6 = __fixunssfsi();
          __floatunsisf(uVar6);
          uVar17 = __divsf3(0x477eff00);
          __floatunsisf(uVar8);
          uVar12 = __divsf3(0x477eff00);
          __subsf3(0x3f800000,uVar17);
          uVar13 = __subsf3(uVar12);
          uVar14 = __mulsf3(uVar17,0x404f6402);
          uVar15 = __mulsf3(uVar12,0x3fc4c155);
          uVar14 = __subsf3(uVar14,uVar15);
          uVar15 = __mulsf3(uVar13,0x3eff3ffb);
          uVar14 = __subsf3(uVar14,uVar15);
          uVar15 = __mulsf3(uVar17,0xbf782129);
          uVar16 = __mulsf3(uVar12,0x3ff02081);
          uVar15 = __addsf3(uVar15,uVar16);
          uVar16 = __mulsf3(uVar13,0x3d2a36a0);
          uVar15 = __addsf3(uVar15,uVar16);
          uVar17 = __mulsf3(uVar17,0x3d63ef28);
          uVar12 = __mulsf3(uVar12,0x3e50f0a6);
          uVar17 = __subsf3(uVar17,uVar12);
          uVar12 = __mulsf3(uVar13,0x3f8755f8);
          uVar12 = __addsf3(uVar17,uVar12);
          iVar9 = __gtsf2(uVar14,0x3f800000);
          uVar17 = 0x3f800000;
          if (iVar9 < 1) {
            uVar17 = uVar14;
          }
          iVar9 = __gtsf2(uVar15,0x3f800000);
          uVar13 = 0x3f800000;
          if (iVar9 < 1) {
            uVar13 = uVar15;
          }
          iVar9 = __gtsf2(uVar12,0x3f800000);
          uVar14 = 0x3f800000;
          if (iVar9 < 1) {
            uVar14 = uVar12;
          }
          iVar9 = __ltsf2(uVar17,0);
          uVar12 = 0;
          if (-1 < iVar9) {
            uVar12 = uVar17;
          }
          __mulsf3(uVar12,0x477fff00);
          uVar20 = __fixunssfsi();
          iVar9 = __ltsf2(uVar13,0);
          uVar20 = uVar20 & 0xffff;
          uVar17 = 0;
          if (-1 < iVar9) {
            uVar17 = uVar13;
          }
          __mulsf3(uVar17,0x477fff00);
          uVar22 = __fixunssfsi();
          iVar9 = __ltsf2(uVar14,0);
          uVar22 = uVar22 & 0xffff;
          uVar17 = 0;
          if (-1 < iVar9) {
            uVar17 = uVar14;
          }
          __mulsf3(uVar17,0x477fff00);
          uVar23 = __fixunssfsi();
          uVar23 = uVar23 & 0xffff;
          uVar24 = uVar20;
          if (uVar20 < uVar22) {
            uVar24 = uVar22;
          }
          if (uVar24 < uVar23) {
            uVar24 = uVar23;
          }
          if (uVar24 == 0) {
            uVar4 = 0;
            uVar10 = 0;
          }
          else {
            uVar10 = uVar20;
            if (uVar22 < uVar20) {
              uVar10 = uVar22;
            }
            if (uVar23 < uVar10) {
              uVar10 = uVar23;
            }
            uVar21 = uVar24 - uVar10 & 0xffff;
            uVar10 = 0;
            uVar4 = (uVar21 * 0xfe) / uVar24 & 0xff;
            if (uVar21 != 0) {
              if (uVar20 == uVar24) {
                uVar10 = (((uVar22 - uVar23) * 0xfe) / uVar21) / 6 & 0xff;
              }
              else {
                if (uVar22 == uVar24) {
                  iVar9 = (int)(uVar23 - uVar20) / (int)uVar21 + 2;
                }
                else {
                  iVar9 = (int)(uVar20 - uVar22) / (int)uVar21 + 4;
                }
                uVar10 = (uint)(iVar9 * 0xfe) / 6 & 0xff;
              }
            }
          }
_L0:
          uVar3 = (undefined1)uVar4;
          uStack_4e = (ushort)(uVar10 << 8);
_L0:
          uStack_4c = CONCAT11(uStack_4c._1_1_,uVar3);
          goto _L0;
        }
        __floatunsisf(uVar8);
        uVar17 = __divsf3(0x447a0000);
        if (uVar8 < 0xfb) {
          __mulsf3(0xc041a77a);
          __addsf3(0x4006d9b5);
          __mulsf3(uVar17);
          __addsf3(0x3e63fa5a);
          __mulsf3(uVar17);
          uVar17 = __addsf3(0x3e7628cc);
          __mulsf3(0x40453b86);
          __subsf3(0x40bbf2c9);
          __mulsf3(uVar17);
          __addsf3(0x40701283);
          __mulsf3(uVar17);
          uVar12 = 0x3ebd7294;
        }
        else {
          __mulsf3(0xbe884164);
          __subsf3(0x3e6ffb8b);
          __mulsf3(uVar17);
          __addsf3(0x3f60b0a9);
          __mulsf3(uVar17);
          uVar17 = __addsf3(0x3e383a54);
          if (uVar8 < 0x1c3) {
            __mulsf3(0xbf747772);
            __subsf3(0x3fafe553);
            __mulsf3(uVar17);
            __addsf3(0x4005d902);
            __mulsf3(uVar17);
            uVar12 = 0x3e2b8228;
          }
          else {
            __mulsf3(0xbf8d9de8);
            __subsf3(0x3fac8ee0);
            __mulsf3(uVar17);
            __addsf3(0x400be030);
            __mulsf3(uVar17);
            uVar12 = 0x3e4f0cae;
          }
        }
        uVar13 = __subsf3(uVar12);
        iVar9 = __gtsf2(uVar17,0x3f800000);
        uVar12 = 0x3f800000;
        if (iVar9 < 1) {
          uVar12 = uVar17;
        }
        iVar9 = __ltsf2(uVar12,0);
        uVar17 = 0;
        if (-1 < iVar9) {
          uVar17 = uVar12;
        }
        __mulsf3(uVar17,0x477eff00);
        uStack_4e = __fixunssfsi();
        iVar9 = __gtsf2(uVar13,0x3f800000);
        uVar12 = 0x3f800000;
        if (iVar9 < 1) {
          uVar12 = uVar13;
        }
        iVar9 = __ltsf2(uVar12,0);
        uVar17 = 0;
        if (-1 < iVar9) {
          uVar17 = uVar12;
        }
_L0:
        __mulsf3(uVar17,0x477eff00);
        uStack_4c = __fixunssfsi();
        goto _L0;
      }
      __floatunsisf(uVar8);
      uVar17 = __divsf3(0x447a0000);
      if (uVar8 < 0xfb) {
        __mulsf3(0xc041a77a);
        __addsf3(0x4006d9b5);
        __mulsf3(uVar17);
        __addsf3(0x3e63fa5a);
        __mulsf3(uVar17);
        uVar17 = __addsf3(0x3e7628cc);
        __mulsf3(0x40453b86);
        __subsf3(0x40bbf2c9);
        __mulsf3(uVar17);
        __addsf3(0x40701283);
        __mulsf3(uVar17);
        uVar12 = 0x3ebd7294;
      }
      else {
        __mulsf3(0xbe884164);
        __subsf3(0x3e6ffb8b);
        __mulsf3(uVar17);
        __addsf3(0x3f60b0a9);
        __mulsf3(uVar17);
        uVar17 = __addsf3(0x3e383a54);
        if (uVar8 < 0x1c3) {
          __mulsf3(0xbf747772);
          __subsf3(0x3fafe553);
          __mulsf3(uVar17);
          __addsf3(0x4005d902);
          __mulsf3(uVar17);
          uVar12 = 0x3e2b8228;
        }
        else {
          __mulsf3(0xbf8d9de8);
          __subsf3(0x3fac8ee0);
          __mulsf3(uVar17);
          __addsf3(0x400be030);
          __mulsf3(uVar17);
          uVar12 = 0x3e4f0cae;
        }
      }
      uVar13 = __subsf3(uVar12);
      iVar9 = __gtsf2(uVar17,0x3f800000);
      uVar12 = 0x3f800000;
      if (iVar9 < 1) {
        uVar12 = uVar17;
      }
      iVar9 = __ltsf2(uVar12,0);
      uVar17 = 0;
      if (-1 < iVar9) {
        uVar17 = uVar12;
      }
      __mulsf3(uVar17,0x477eff00);
      uVar8 = __fixunssfsi();
      uStack_4e = uVar8;
      iVar9 = __gtsf2(uVar13,0x3f800000);
      uVar17 = 0x3f800000;
      if (iVar9 < 1) {
        uVar17 = uVar13;
      }
      iVar9 = __ltsf2(uVar17,0);
      uVar12 = 0;
      if (-1 < iVar9) {
        uVar12 = uVar17;
      }
      __mulsf3(uVar12,0x477eff00);
      uVar7 = __fixunssfsi();
      uStack_4c = uVar7;
      __floatunsisf(uVar8);
      uVar17 = __divsf3(0x477eff00);
      __floatunsisf(uVar7);
      uVar12 = __divsf3(0x477eff00);
      __subsf3(0x3f800000,uVar17);
      uVar13 = __subsf3(uVar12);
      uVar14 = __mulsf3(uVar17,0x404f6402);
      uVar15 = __mulsf3(uVar12,0x3fc4c155);
      uVar14 = __subsf3(uVar14,uVar15);
      uVar15 = __mulsf3(uVar13,0x3eff3ffb);
      uVar14 = __subsf3(uVar14,uVar15);
      uVar15 = __mulsf3(uVar17,0xbf782129);
      uVar16 = __mulsf3(uVar12,0x3ff02081);
      uVar15 = __addsf3(uVar15,uVar16);
      uVar16 = __mulsf3(uVar13,0x3d2a36a0);
      uVar15 = __addsf3(uVar15,uVar16);
      uVar17 = __mulsf3(uVar17,0x3d63ef28);
      uVar12 = __mulsf3(uVar12,0x3e50f0a6);
      uVar17 = __subsf3(uVar17,uVar12);
      uVar12 = __mulsf3(uVar13,0x3f8755f8);
      uVar12 = __addsf3(uVar17,uVar12);
      iVar9 = __gtsf2(uVar14,0x3f800000);
      uVar17 = 0x3f800000;
      if (iVar9 < 1) {
        uVar17 = uVar14;
      }
      iVar9 = __gtsf2(uVar15,0x3f800000);
      uVar13 = 0x3f800000;
      if (iVar9 < 1) {
        uVar13 = uVar15;
      }
      iVar9 = __gtsf2(uVar12,0x3f800000);
      uVar14 = 0x3f800000;
      if (iVar9 < 1) {
        uVar14 = uVar12;
      }
      iVar9 = __ltsf2(uVar17,0);
      uVar12 = 0;
      if (-1 < iVar9) {
        uVar12 = uVar17;
      }
      __mulsf3(uVar12,0x477fff00);
      uVar10 = __fixunssfsi();
      iVar9 = __ltsf2(uVar13,0);
      uVar10 = uVar10 & 0xffff;
      uVar17 = 0;
      if (-1 < iVar9) {
        uVar17 = uVar13;
      }
_L0:
      __mulsf3(uVar17,0x477fff00);
      uVar4 = __fixunssfsi();
      iVar9 = __ltsf2(uVar14,0);
      uVar4 = uVar4 & 0xffff;
      uVar17 = 0;
      if (-1 < iVar9) {
        uVar17 = uVar14;
      }
      __mulsf3(uVar17,0x477fff00);
      uVar22 = __fixunssfsi();
      uVar22 = uVar22 & 0xffff;
      uVar20 = uVar10;
      if (uVar10 < uVar4) {
        uVar20 = uVar4;
      }
      if (uVar20 < uVar22) {
        uVar20 = uVar22;
      }
      if (uVar20 == 0) {
        uStack_4c = (ushort)uStack_4c._1_1_ << 8;
      }
      else {
        uVar24 = uVar10;
        if (uVar4 < uVar10) {
          uVar24 = uVar4;
        }
        if (uVar22 < uVar24) {
          uVar24 = uVar22;
        }
        uVar24 = uVar20 - uVar24 & 0xffff;
        uStack_4c = CONCAT11(uStack_4c._1_1_,(char)((uVar24 * 0xfe) / uVar20));
        if (uVar24 != 0) {
          if (uVar10 == uVar20) {
            uStack_4e = CONCAT11(uStack_4e._1_1_,(char)((((uVar4 - uVar22) * 0xfe) / uVar24) / 6));
          }
          else {
            if (uVar4 == uVar20) {
              iVar9 = (int)(uVar22 - uVar10) / (int)uVar24 + 2;
            }
            else {
              iVar9 = (int)(uVar10 - uVar4) / (int)uVar24 + 4;
            }
            uStack_4e = CONCAT11(uStack_4e._1_1_,(char)((uint)(iVar9 * 0xfe) / 6));
          }
          goto _L0;
        }
      }
      uStack_4e = uStack_4e & 0xff00;
    }
    else {
      if (bVar2 < 3) {
        if (bVar2 == 0) {
          iVar9 = color_control_srv_get_attr_desc(uVar1,0);
          iVar11 = color_control_srv_get_attr_desc(uVar1,1);
          uVar10 = 0;
          if (iVar9 != 0) {
            uVar10 = (uint)**(byte **)(iVar9 + 8);
          }
          uVar4 = 0;
          if (iVar11 != 0) {
            uVar4 = (uint)**(byte **)(iVar11 + 8);
          }
          if (local_50[0] == 1) {
            uVar22 = ((uVar10 % 0x2a) * 0xffff) / 0x2a;
            uVar20 = (uVar4 * 0xffff) / 0xfe;
            uVar24 = uVar22 * uVar20;
            uVar4 = (0xffff - uVar22) * uVar20;
_L0:
            uVar21 = 0xfffe;
            uVar25 = ((0xffff - uVar24 / 0xffff) * 0xfffe) / 0xffff & 0xffff;
            uVar20 = ((0xffff - uVar20) * 0xfffe) / 0xffff & 0xffff;
            uVar24 = ((0xffff - uVar4 / 0xffff) * 0xfffe) / 0xffff & 0xffff;
            uVar23 = (uVar10 / 0x2a) % 6;
            uVar10 = uVar21;
            uVar4 = uVar20;
            uVar22 = uVar24;
            if (uVar23 != 2) {
              if (uVar23 < 3) {
                uVar5 = uVar24;
                uVar4 = uVar25;
                uVar22 = uVar20;
                if (uVar23 == 0) {
_L0:
                  uVar10 = uVar5;
                  uVar4 = uVar21;
                  uVar22 = uVar20;
                }
              }
              else {
                uVar10 = uVar25;
                uVar22 = uVar21;
                if ((uVar23 != 3) &&
                   (uVar5 = uVar20, uVar10 = uVar20, uVar4 = uVar24, uVar20 = uVar25, uVar23 != 4))
                goto _L0;
              }
            }
            __floatunsisf(uVar4);
            uVar17 = __divsf3(0x477fff00);
            __floatunsisf(uVar10);
            uVar12 = __divsf3(0x477fff00);
            __floatunsisf(uVar22);
            uVar13 = __divsf3(0x477fff00);
            uVar14 = __mulsf3(uVar17,0x3ed32d0a);
            uVar15 = __mulsf3(uVar12,0x3eb714ba);
            uVar14 = __addsf3(uVar14,uVar15);
            uVar15 = __mulsf3(uVar13,0x3e38c0cf);
            uVar14 = __addsf3(uVar14,uVar15);
            uVar15 = __mulsf3(uVar17,0x3e59c66d);
            uVar16 = __mulsf3(uVar12,0x3f3714ba);
            uVar15 = __addsf3(uVar15,uVar16);
            uVar16 = __mulsf3(uVar13,0x3d93cd57);
            uVar15 = __addsf3(uVar15,uVar16);
            uVar17 = __mulsf3(uVar17,0x3c9e6256);
            uVar12 = __mulsf3(uVar12,0x3df41b76);
            uVar17 = __addsf3(uVar17,uVar12);
            uVar12 = __mulsf3(uVar13,0x3f734214);
            uVar17 = __addsf3(uVar17,uVar12);
            uVar12 = __addsf3(uVar14,uVar15);
            uVar17 = __addsf3(uVar17,uVar12);
            iVar9 = __eqsf2(0);
            if (iVar9 == 0) {
              uStack_4c = 0;
              uStack_4e = 0;
              goto _L0;
            }
            __divsf3(uVar14,uVar17);
            __mulsf3(0x477eff00);
            uStack_4e = __fixunssfsi();
            uVar17 = __divsf3(uVar15,uVar17);
            goto _L0;
          }
          if (local_50[0] != 2) {
            if (local_50[0] == 3) goto _L0;
            uStack_4e = CONCAT11(uStack_4e._1_1_,(char)uVar10);
            uStack_4c = CONCAT11(uStack_4c._1_1_,(char)uVar4);
            uVar8 = uStack_4e;
            uVar7 = uStack_4c;
            goto _L0;
          }
          uVar22 = ((uVar10 % 0x2a) * 0xffff) / 0x2a;
          uVar20 = (uVar4 * 0xffff) / 0xfe;
          uVar24 = uVar22 * uVar20;
          uVar4 = (0xffff - uVar22) * uVar20;
_L0:
          uVar21 = 0xfffe;
          uVar25 = ((0xffff - uVar24 / 0xffff) * 0xfffe) / 0xffff & 0xffff;
          uVar22 = ((0xffff - uVar20) * 0xfffe) / 0xffff & 0xffff;
          uVar24 = ((0xffff - uVar4 / 0xffff) * 0xfffe) / 0xffff & 0xffff;
          uVar23 = (uVar10 / 0x2a) % 6;
          uVar10 = uVar21;
          uVar4 = uVar22;
          uVar20 = uVar24;
          if (uVar23 != 2) {
            if (uVar23 < 3) {
              uVar5 = uVar24;
              uVar4 = uVar25;
              uVar20 = uVar22;
              if (uVar23 == 0) {
_L0:
                uVar10 = uVar5;
                uVar4 = uVar21;
                uVar20 = uVar22;
              }
            }
            else {
              uVar10 = uVar25;
              uVar20 = uVar21;
              if ((uVar23 != 3) &&
                 (uVar5 = uVar22, uVar10 = uVar22, uVar4 = uVar24, uVar22 = uVar25, uVar23 != 4))
              goto _L0;
            }
          }
          __floatunsisf(uVar4);
          uVar17 = __divsf3(0x477fff00);
          __floatunsisf(uVar10);
          uVar12 = __divsf3(0x477fff00);
          __floatunsisf(uVar20);
          uVar13 = __divsf3(0x477fff00);
          uVar14 = __mulsf3(uVar17,0x3ed32d0a);
          uVar15 = __mulsf3(uVar12,0x3eb714ba);
          uVar14 = __addsf3(uVar14,uVar15);
          uVar15 = __mulsf3(uVar13,0x3e38c0cf);
          uVar14 = __addsf3(uVar14,uVar15);
          uVar15 = __mulsf3(uVar17,0x3e59c66d);
          uVar16 = __mulsf3(uVar12,0x3f3714ba);
          uVar15 = __addsf3(uVar15,uVar16);
          uVar16 = __mulsf3(uVar13,0x3d93cd57);
          uVar15 = __addsf3(uVar15,uVar16);
          uVar17 = __mulsf3(uVar17,0x3c9e6256);
          uVar12 = __mulsf3(uVar12,0x3df41b76);
          uVar17 = __addsf3(uVar17,uVar12);
          uVar12 = __mulsf3(uVar13,0x3f734214);
          uVar17 = __addsf3(uVar17,uVar12);
          uVar12 = __addsf3(uVar14,uVar15);
          uVar17 = __addsf3(uVar17,uVar12);
          iVar9 = __eqsf2(0);
          if (iVar9 == 0) {
            uVar7 = 0;
            uVar6 = 0;
          }
          else {
            __divsf3(uVar14,uVar17);
            __mulsf3(0x477eff00);
            uVar6 = __fixunssfsi();
            __divsf3(uVar15,uVar17);
            __mulsf3(0x477eff00);
            uVar7 = __fixunssfsi();
          }
          uStack_4c = uVar7;
          __floatunsisf(uVar6);
        }
        else {
          iVar9 = color_control_srv_get_attr_desc(uVar1,3);
          iVar11 = color_control_srv_get_attr_desc(uVar1,4);
          uVar8 = 0;
          if (iVar9 != 0) {
            uVar8 = **(ushort **)(iVar9 + 8);
          }
          uVar7 = 0;
          if (iVar11 != 0) {
            uVar7 = **(ushort **)(iVar11 + 8);
          }
          if (local_50[0] == 0) {
            __floatunsisf();
            uVar17 = __divsf3(0x477eff00);
            __floatunsisf(uVar7);
            uVar12 = __divsf3(0x477eff00);
            __subsf3(0x3f800000,uVar17);
            uVar13 = __subsf3(uVar12);
            uVar14 = __mulsf3(uVar17,0x404f6402);
            uVar15 = __mulsf3(uVar12,0x3fc4c155);
            uVar14 = __subsf3(uVar14,uVar15);
            uVar15 = __mulsf3(uVar13,0x3eff3ffb);
            uVar14 = __subsf3(uVar14,uVar15);
            uVar15 = __mulsf3(uVar17,0xbf782129);
            uVar16 = __mulsf3(uVar12,0x3ff02081);
            uVar15 = __addsf3(uVar15,uVar16);
            uVar16 = __mulsf3(uVar13,0x3d2a36a0);
            uVar15 = __addsf3(uVar15,uVar16);
            uVar17 = __mulsf3(uVar17,0x3d63ef28);
            uVar12 = __mulsf3(uVar12,0x3e50f0a6);
            uVar17 = __subsf3(uVar17,uVar12);
            uVar12 = __mulsf3(uVar13,0x3f8755f8);
            uVar12 = __addsf3(uVar17,uVar12);
            iVar9 = __gtsf2(uVar14,0x3f800000);
            uVar17 = 0x3f800000;
            if (iVar9 < 1) {
              uVar17 = uVar14;
            }
            iVar9 = __gtsf2(uVar15,0x3f800000);
            uVar13 = 0x3f800000;
            if (iVar9 < 1) {
              uVar13 = uVar15;
            }
            iVar9 = __gtsf2(uVar12,0x3f800000);
            uVar14 = 0x3f800000;
            if (iVar9 < 1) {
              uVar14 = uVar12;
            }
            iVar9 = __ltsf2(uVar17,0);
            uVar12 = 0;
            if (-1 < iVar9) {
              uVar12 = uVar17;
            }
            __mulsf3(uVar12,0x477fff00);
            uVar10 = __fixunssfsi();
            iVar9 = __ltsf2(uVar13,0);
            uVar10 = uVar10 & 0xffff;
            uVar17 = 0;
            if (-1 < iVar9) {
              uVar17 = uVar13;
            }
            goto _L0;
          }
          if (local_50[0] != 2) {
            if (local_50[0] == 3) {
              __floatunsisf();
              uVar17 = __divsf3(0x477eff00);
              __floatunsisf(uVar7);
              uVar12 = __divsf3(0x477eff00);
              __subsf3(0x3f800000,uVar17);
              uVar13 = __subsf3(uVar12);
              uVar14 = __mulsf3(uVar17,0x404f6402);
              uVar15 = __mulsf3(uVar12,0x3fc4c155);
              uVar14 = __subsf3(uVar14,uVar15);
              uVar15 = __mulsf3(uVar13,0x3eff3ffb);
              uVar14 = __subsf3(uVar14,uVar15);
              uVar15 = __mulsf3(uVar17,0xbf782129);
              uVar16 = __mulsf3(uVar12,0x3ff02081);
              uVar15 = __addsf3(uVar15,uVar16);
              uVar16 = __mulsf3(uVar13,0x3d2a36a0);
              uVar15 = __addsf3(uVar15,uVar16);
              uVar17 = __mulsf3(uVar17,0x3d63ef28);
              uVar12 = __mulsf3(uVar12,0x3e50f0a6);
              uVar17 = __subsf3(uVar17,uVar12);
              uVar12 = __mulsf3(uVar13,0x3f8755f8);
              uVar12 = __addsf3(uVar17,uVar12);
              iVar9 = __gtsf2(uVar14,0x3f800000);
              uVar17 = 0x3f800000;
              if (iVar9 < 1) {
                uVar17 = uVar14;
              }
              iVar9 = __gtsf2(uVar15,0x3f800000);
              uVar13 = 0x3f800000;
              if (iVar9 < 1) {
                uVar13 = uVar15;
              }
              iVar9 = __gtsf2(uVar12,0x3f800000);
              uVar14 = 0x3f800000;
              if (iVar9 < 1) {
                uVar14 = uVar12;
              }
              iVar9 = __ltsf2(uVar17,0);
              uVar12 = 0;
              if (-1 < iVar9) {
                uVar12 = uVar17;
              }
              __mulsf3(uVar12,0x477fff00);
              uVar10 = __fixunssfsi();
              iVar9 = __ltsf2(uVar13,0);
              uVar10 = uVar10 & 0xffff;
              uVar17 = 0;
              if (-1 < iVar9) {
                uVar17 = uVar13;
              }
              __mulsf3(uVar17,0x477fff00);
              uVar4 = __fixunssfsi();
              iVar9 = __ltsf2(uVar14,0);
              uVar4 = uVar4 & 0xffff;
              uVar17 = 0;
              if (-1 < iVar9) {
                uVar17 = uVar14;
              }
              __mulsf3(uVar17,0x477fff00);
              uVar22 = __fixunssfsi();
              uVar22 = uVar22 & 0xffff;
              uVar20 = uVar10;
              if (uVar10 < uVar4) {
                uVar20 = uVar4;
              }
              if (uVar20 < uVar22) {
                uVar20 = uVar22;
              }
              uVar24 = 0;
              if (uVar20 != 0) {
                uVar24 = uVar10;
                if (uVar4 < uVar10) {
                  uVar24 = uVar4;
                }
                if (uVar22 < uVar24) {
                  uVar24 = uVar22;
                }
                uVar23 = uVar20 - uVar24 & 0xffff;
                uVar24 = 0;
                if (uVar23 != 0) {
                  if (uVar10 == uVar20) {
                    uVar24 = (((uVar4 - uVar22) * 0xfe) / uVar23) / 6 & 0xff;
                  }
                  else {
                    if (uVar4 == uVar20) {
                      iVar9 = (int)(uVar22 - uVar10) / (int)uVar23 + 2;
                    }
                    else {
                      iVar9 = (int)(uVar10 - uVar4) / (int)uVar23 + 4;
                    }
                    uVar24 = (uint)(iVar9 * 0xfe) / 6 & 0xff;
                  }
                }
              }
              uStack_4e = (ushort)(uVar24 << 8);
              uVar3 = (undefined1)uVar7;
              goto _L0;
            }
            goto _L0;
          }
          __floatunsisf();
        }
        __divsf3(0x477eff00);
        uVar17 = __subsf3(0x3ea9fbe7);
        __floatunsisf(uVar7);
        __divsf3(0x477eff00);
        uVar12 = __subsf3(0x3e3e425b);
        uVar17 = __divsf3(uVar17,uVar12);
        __mulsf3(0xc3e08000);
        __addsf3(0x455c5000);
        __mulsf3(uVar17);
        uVar12 = __mulsf3(uVar17);
        uVar17 = __mulsf3(uVar17,0x45d53a66);
        __subsf3(uVar12,uVar17);
        uVar12 = __addsf3(0x45ac82a4);
        iVar9 = __gtsf2(0x461c4000);
        uVar17 = 0x461c4000;
        if (iVar9 < 1) {
          uVar17 = uVar12;
        }
        iVar9 = __ltsf2(uVar17,0x447a0000);
        uVar12 = 0x447a0000;
        if (-1 < iVar9) {
          uVar12 = uVar17;
        }
        uStack_4e = __fixunssfsi(uVar12);
        goto _L0;
      }
      if (bVar2 != 3) {
        return 0x87;
      }
      iVar9 = color_control_srv_get_attr_desc(uVar1,0x4000);
      iVar11 = color_control_srv_get_attr_desc(uVar1,1);
      uVar10 = 0;
      if (iVar9 != 0) {
        uVar10 = (uint)**(ushort **)(iVar9 + 8);
      }
      uVar4 = 0;
      if (iVar11 != 0) {
        uVar4 = (uint)**(byte **)(iVar11 + 8);
      }
      if (local_50[0] != 0) {
        if (local_50[0] == 1) {
          uVar10 = uVar10 >> 8;
          uVar22 = ((uVar10 % 0x2a) * 0xffff) / 0x2a;
          uVar20 = (uVar4 * 0xffff) / 0xfe;
          uVar24 = uVar22 * uVar20;
          uVar4 = (0xffff - uVar22) * uVar20;
          goto _L0;
        }
        if (local_50[0] == 2) {
          uVar10 = uVar10 >> 8;
          uVar22 = ((uVar10 % 0x2a) * 0xffff) / 0x2a;
          uVar20 = (uVar4 * 0xffff) / 0xfe;
          uVar24 = uVar22 * uVar20;
          uVar4 = (0xffff - uVar22) * uVar20;
          goto _L0;
        }
        uStack_4c = CONCAT11(uStack_4c._1_1_,(char)uVar4);
        uVar8 = (ushort)uVar10;
        uVar7 = uStack_4c;
        goto _L0;
      }
      uStack_4e = CONCAT11(uStack_4e._1_1_,(char)(uVar10 >> 8));
      uStack_4c = CONCAT11(uStack_4c._1_1_,(char)uVar4);
    }
_L0:
    color_control_srv_set_attr_value(uVar1,0,&uStack_4e);
    puVar18 = &uStack_4c;
    uVar17 = 1;
  }
_L0:
  uVar10 = color_control_srv_set_attr_value(uVar1,uVar17,puVar18);
  if (uVar10 == 0) {
    if (param_2 == 3) {
      auStack_48[0] = 0;
      pbVar19 = auStack_48;
    }
    uVar10 = color_control_srv_set_attr_value(uVar1,8,pbVar19);
    if (uVar10 == 0) {
      uVar10 = color_control_srv_set_attr_value(uVar1,0x4001,local_50);
    }
  }
  return uVar10;
}

