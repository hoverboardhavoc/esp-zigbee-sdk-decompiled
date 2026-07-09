/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_update_default_color
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 color_control_update_default_color(undefined1 param_1,uint param_2,char *param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  ushort uVar19;
  byte bStack_36;
  char cStack_34;
  
  cStack_34 = '\0';
  if (param_3 == (char *)0x0) {
    uVar2 = 0;
  }
  else if (param_2 == 2) {
    iVar8 = color_control_srv_get_attr_desc(param_1,7);
    if (iVar8 == 0) {
      uVar19 = 0;
    }
    else {
      uVar19 = **(ushort **)(iVar8 + 8);
    }
    cVar1 = *param_3;
    if (cVar1 == '\0') {
      __floatunsisf(uVar19);
      uVar2 = __divsf3(0x447a0000);
      if (uVar19 < 0xfb) {
        __mulsf3(0xc041a77a);
        __addsf3(0x4006d9b5);
        __mulsf3(uVar2);
        __addsf3(0x3e63fa5a);
        __mulsf3(uVar2);
        uVar2 = __addsf3(0x3e7628cc);
        __mulsf3(0x40453b86);
        __subsf3(0x40bbf2c9);
        __mulsf3(uVar2);
        __addsf3(0x40701283);
        __mulsf3(uVar2);
        uVar9 = __subsf3(0x3ebd7294);
      }
      else {
        __mulsf3(0xbe884164);
        __subsf3(0x3e6ffb8b);
        __mulsf3(uVar2);
        __addsf3(0x3f60b0a9);
        __mulsf3(uVar2);
        uVar2 = __addsf3(0x3e383a54);
        if (uVar19 < 0x1c3) {
          __mulsf3(0xbf747772);
          __subsf3(0x3fafe553);
          __mulsf3(uVar2);
          __addsf3(0x4005d902);
          __mulsf3(uVar2);
          uVar9 = __subsf3(0x3e2b8228);
        }
        else {
          __mulsf3(0xbf8d9de8);
          __subsf3(0x3fac8ee0);
          __mulsf3(uVar2);
          __addsf3(0x400be030);
          __mulsf3(uVar2);
          uVar9 = __subsf3(0x3e4f0cae);
        }
      }
      iVar8 = __gtsf2(uVar2,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar2,0);
        if (iVar8 < 0) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0x3f800000;
      }
      __mulsf3(uVar2,0x477eff00);
      uVar4 = __fixunssfsi();
      *(undefined2 *)(param_3 + 2) = uVar4;
      iVar8 = __gtsf2(uVar9,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar9,0);
        if (iVar8 < 0) {
          uVar9 = 0;
        }
      }
      else {
        uVar9 = 0x3f800000;
      }
      __mulsf3(uVar9,0x477eff00);
      uVar5 = __fixunssfsi();
      *(undefined2 *)(param_3 + 4) = uVar5;
      __floatunsisf(uVar4);
      uVar2 = __divsf3(0x477eff00);
      __floatunsisf(uVar5);
      uVar9 = __divsf3(0x477eff00);
      __subsf3(0x3f800000,uVar2);
      uVar10 = __subsf3(uVar9);
      uVar11 = __mulsf3(uVar2,0x404f6402);
      uVar12 = __mulsf3(uVar9,0x3fc4c155);
      uVar11 = __subsf3(uVar11,uVar12);
      uVar12 = __mulsf3(uVar10,0x3eff3ffb);
      uVar11 = __subsf3(uVar11,uVar12);
      uVar12 = __mulsf3(uVar2,0xbf782129);
      uVar13 = __mulsf3(uVar9,0x3ff02081);
      uVar12 = __addsf3(uVar12,uVar13);
      uVar13 = __mulsf3(uVar10,0x3d2a36a0);
      uVar12 = __addsf3(uVar12,uVar13);
      uVar2 = __mulsf3(uVar2,0x3d63ef28);
      uVar9 = __mulsf3(uVar9,0x3e50f0a6);
      uVar2 = __subsf3(uVar2,uVar9);
      uVar9 = __mulsf3(uVar10,0x3f8755f8);
      uVar2 = __addsf3(uVar2,uVar9);
      iVar8 = __gtsf2(uVar11,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar11,0);
        if (iVar8 < 0) {
          uVar11 = 0;
        }
      }
      else {
        uVar11 = 0x3f800000;
      }
      iVar8 = __gtsf2(uVar12,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar12,0);
        if (iVar8 < 0) {
          uVar12 = 0;
        }
      }
      else {
        uVar12 = 0x3f800000;
      }
      iVar8 = __gtsf2(uVar2,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar2,0);
        if (iVar8 < 0) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0x3f800000;
      }
      __mulsf3(uVar11,0x477fff00);
      uVar14 = __fixunssfsi();
      uVar14 = uVar14 & 0xffff;
      __mulsf3(uVar12,0x477fff00);
      uVar15 = __fixunssfsi();
      uVar15 = uVar15 & 0xffff;
      __mulsf3(uVar2,0x477fff00);
      uVar16 = __fixunssfsi();
      uVar16 = uVar16 & 0xffff;
      uVar18 = uVar14;
      if (uVar15 < uVar14) {
        uVar18 = uVar15;
      }
      if (uVar16 < uVar18) {
        uVar18 = uVar16;
      }
      uVar17 = uVar14;
      if (uVar14 < uVar15) {
        uVar17 = uVar15;
      }
      if (uVar17 < uVar16) {
        uVar17 = uVar16;
      }
      uVar18 = uVar17 - uVar18 & 0xffff;
      uVar2 = 0;
      if (uVar17 == 0) {
        param_3[4] = '\0';
        param_3[2] = '\0';
      }
      else {
        param_3[4] = (char)((uVar18 * 0xfe) / uVar17);
        if (uVar18 == 0) {
          param_3[2] = '\0';
        }
        else if (uVar14 == uVar17) {
          param_3[2] = (char)((((uVar15 - uVar16) * 0xfe) / uVar18) / 6);
        }
        else if (uVar15 == uVar17) {
          param_3[2] = (char)((uint)(((int)(uVar16 - uVar14) / (int)uVar18 + 2) * 0xfe) / 6);
        }
        else {
          param_3[2] = (char)((uint)(((int)(uVar14 - uVar15) / (int)uVar18 + 4) * 0xfe) / 6);
        }
      }
    }
    else if (cVar1 == '\x01') {
      __floatunsisf(uVar19);
      uVar2 = __divsf3(0x447a0000);
      if (uVar19 < 0xfb) {
        __mulsf3(0xc041a77a);
        __addsf3(0x4006d9b5);
        __mulsf3(uVar2);
        __addsf3(0x3e63fa5a);
        __mulsf3(uVar2);
        uVar2 = __addsf3(0x3e7628cc);
        __mulsf3(0x40453b86);
        __subsf3(0x40bbf2c9);
        __mulsf3(uVar2);
        __addsf3(0x40701283);
        __mulsf3(uVar2);
        uVar9 = __subsf3(0x3ebd7294);
      }
      else {
        __mulsf3(0xbe884164);
        __subsf3(0x3e6ffb8b);
        __mulsf3(uVar2);
        __addsf3(0x3f60b0a9);
        __mulsf3(uVar2);
        uVar2 = __addsf3(0x3e383a54);
        if (uVar19 < 0x1c3) {
          __mulsf3(0xbf747772);
          __subsf3(0x3fafe553);
          __mulsf3(uVar2);
          __addsf3(0x4005d902);
          __mulsf3(uVar2);
          uVar9 = __subsf3(0x3e2b8228);
        }
        else {
          __mulsf3(0xbf8d9de8);
          __subsf3(0x3fac8ee0);
          __mulsf3(uVar2);
          __addsf3(0x400be030);
          __mulsf3(uVar2);
          uVar9 = __subsf3(0x3e4f0cae);
        }
      }
      iVar8 = __gtsf2(uVar2,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar2,0);
        if (iVar8 < 0) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0x3f800000;
      }
      __mulsf3(uVar2,0x477eff00);
      uVar4 = __fixunssfsi();
      *(undefined2 *)(param_3 + 2) = uVar4;
      iVar8 = __gtsf2(uVar9,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar9,0);
        if (iVar8 < 0) {
          uVar9 = 0;
        }
      }
      else {
        uVar9 = 0x3f800000;
      }
      __mulsf3(uVar9,0x477eff00);
      uVar4 = __fixunssfsi();
      *(undefined2 *)(param_3 + 4) = uVar4;
      uVar2 = 0;
    }
    else if (cVar1 == '\x03') {
      __floatunsisf(uVar19);
      uVar2 = __divsf3(0x447a0000);
      if (uVar19 < 0xfb) {
        __mulsf3(0xc041a77a);
        __addsf3(0x4006d9b5);
        __mulsf3(uVar2);
        __addsf3(0x3e63fa5a);
        __mulsf3(uVar2);
        uVar2 = __addsf3(0x3e7628cc);
        __mulsf3(0x40453b86);
        __subsf3(0x40bbf2c9);
        __mulsf3(uVar2);
        __addsf3(0x40701283);
        __mulsf3(uVar2);
        uVar9 = __subsf3(0x3ebd7294);
      }
      else {
        __mulsf3(0xbe884164);
        __subsf3(0x3e6ffb8b);
        __mulsf3(uVar2);
        __addsf3(0x3f60b0a9);
        __mulsf3(uVar2);
        uVar2 = __addsf3(0x3e383a54);
        if (uVar19 < 0x1c3) {
          __mulsf3(0xbf747772);
          __subsf3(0x3fafe553);
          __mulsf3(uVar2);
          __addsf3(0x4005d902);
          __mulsf3(uVar2);
          uVar9 = __subsf3(0x3e2b8228);
        }
        else {
          __mulsf3(0xbf8d9de8);
          __subsf3(0x3fac8ee0);
          __mulsf3(uVar2);
          __addsf3(0x400be030);
          __mulsf3(uVar2);
          uVar9 = __subsf3(0x3e4f0cae);
        }
      }
      iVar8 = __gtsf2(uVar2,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar2,0);
        if (iVar8 < 0) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0x3f800000;
      }
      __mulsf3(uVar2,0x477eff00);
      uVar4 = __fixunssfsi();
      *(undefined2 *)(param_3 + 2) = uVar4;
      iVar8 = __gtsf2(uVar9,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar9,0);
        if (iVar8 < 0) {
          uVar9 = 0;
        }
      }
      else {
        uVar9 = 0x3f800000;
      }
      __mulsf3(uVar9,0x477eff00);
      uVar5 = __fixunssfsi();
      *(undefined2 *)(param_3 + 4) = uVar5;
      __floatunsisf(uVar4);
      uVar2 = __divsf3(0x477eff00);
      __floatunsisf(uVar5);
      uVar9 = __divsf3(0x477eff00);
      __subsf3(0x3f800000,uVar2);
      uVar10 = __subsf3(uVar9);
      uVar11 = __mulsf3(uVar2,0x404f6402);
      uVar12 = __mulsf3(uVar9,0x3fc4c155);
      uVar11 = __subsf3(uVar11,uVar12);
      uVar12 = __mulsf3(uVar10,0x3eff3ffb);
      uVar11 = __subsf3(uVar11,uVar12);
      uVar12 = __mulsf3(uVar2,0xbf782129);
      uVar13 = __mulsf3(uVar9,0x3ff02081);
      uVar12 = __addsf3(uVar12,uVar13);
      uVar13 = __mulsf3(uVar10,0x3d2a36a0);
      uVar12 = __addsf3(uVar12,uVar13);
      uVar2 = __mulsf3(uVar2,0x3d63ef28);
      uVar9 = __mulsf3(uVar9,0x3e50f0a6);
      uVar2 = __subsf3(uVar2,uVar9);
      uVar9 = __mulsf3(uVar10,0x3f8755f8);
      uVar2 = __addsf3(uVar2,uVar9);
      iVar8 = __gtsf2(uVar11,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar11,0);
        if (iVar8 < 0) {
          uVar11 = 0;
        }
      }
      else {
        uVar11 = 0x3f800000;
      }
      iVar8 = __gtsf2(uVar12,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar12,0);
        if (iVar8 < 0) {
          uVar12 = 0;
        }
      }
      else {
        uVar12 = 0x3f800000;
      }
      iVar8 = __gtsf2(uVar2,0x3f800000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar2,0);
        if (iVar8 < 0) {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0x3f800000;
      }
      __mulsf3(uVar11,0x477fff00);
      uVar14 = __fixunssfsi();
      uVar14 = uVar14 & 0xffff;
      __mulsf3(uVar12,0x477fff00);
      uVar15 = __fixunssfsi();
      uVar15 = uVar15 & 0xffff;
      __mulsf3(uVar2,0x477fff00);
      uVar16 = __fixunssfsi();
      uVar16 = uVar16 & 0xffff;
      uVar18 = uVar14;
      if (uVar15 < uVar14) {
        uVar18 = uVar15;
      }
      if (uVar16 < uVar18) {
        uVar18 = uVar16;
      }
      uVar17 = uVar14;
      if (uVar14 < uVar15) {
        uVar17 = uVar15;
      }
      if (uVar17 < uVar16) {
        uVar17 = uVar16;
      }
      uVar18 = uVar17 - uVar18 & 0xffff;
      if (uVar17 == 0) {
        bStack_36 = 0;
      }
      else {
        cStack_34 = (char)((uVar18 * 0xfe) / uVar17);
        if (uVar18 == 0) {
          bStack_36 = 0;
        }
        else if (uVar14 == uVar17) {
          bStack_36 = (byte)((((uVar15 - uVar16) * 0xfe) / uVar18) / 6);
        }
        else if (uVar15 == uVar17) {
          bStack_36 = (byte)((uint)(((int)(uVar16 - uVar14) / (int)uVar18 + 2) * 0xfe) / 6);
        }
        else {
          bStack_36 = (byte)((uint)(((int)(uVar14 - uVar15) / (int)uVar18 + 4) * 0xfe) / 6);
        }
      }
      *(ushort *)(param_3 + 2) = (ushort)bStack_36 << 8;
      param_3[4] = cStack_34;
      uVar2 = 0;
    }
    else {
      *(ushort *)(param_3 + 2) = uVar19;
      uVar2 = 0;
    }
  }
  else if (param_2 < 3) {
    if (param_2 == 0) {
      iVar8 = color_control_srv_get_attr_desc(param_1,0);
      iVar6 = color_control_srv_get_attr_desc(param_1,1);
      if (iVar8 == 0) {
        uVar18 = 0;
      }
      else {
        uVar18 = (uint)**(byte **)(iVar8 + 8);
      }
      if (iVar6 == 0) {
        uVar14 = 0;
      }
      else {
        uVar14 = (uint)**(byte **)(iVar6 + 8);
      }
      cVar1 = *param_3;
      uVar2 = 0;
      if (cVar1 == '\x01') {
        uVar16 = (uVar14 * 0xffff) / 0xfe;
        uVar15 = ((0xffff - uVar16) * 0xfffe) / 0xffff & 0xffff;
        uVar17 = ((uVar18 % 0x2a) * 0xffff) / 0x2a & 0xffff;
        uVar14 = ((0xffff - (uVar17 * uVar16) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar17 = ((0xffff - ((0xffff - uVar17) * uVar16) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar16 = (uVar18 / 0x2a) % 6;
        uVar18 = uVar15;
        if (uVar16 == 2) {
          uVar14 = 0xfffe;
          uVar3 = uVar17;
        }
        else if (uVar16 < 3) {
          uVar3 = uVar15;
          if (uVar16 == 0) {
            uVar18 = 0xfffe;
            uVar14 = uVar17;
          }
          else if (uVar16 == 1) {
            uVar18 = uVar14;
            uVar14 = 0xfffe;
          }
          else {
            uVar3 = uVar14;
            uVar18 = 0xfffe;
            uVar14 = uVar15;
          }
        }
        else if (uVar16 == 3) {
          uVar3 = 0xfffe;
        }
        else if (uVar16 == 4) {
          uVar3 = 0xfffe;
          uVar18 = uVar17;
          uVar14 = uVar15;
        }
        else {
          uVar3 = uVar14;
          uVar18 = 0xfffe;
          uVar14 = uVar15;
        }
        __floatunsisf(uVar18);
        uVar9 = __divsf3(0x477fff00);
        __floatunsisf(uVar14);
        uVar10 = __divsf3(0x477fff00);
        __floatunsisf(uVar3);
        uVar11 = __divsf3(0x477fff00);
        uVar12 = __mulsf3(uVar9,0x3ed32d0a);
        uVar13 = __mulsf3(uVar10,0x3eb714ba);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar11,0x3e38c0cf);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar9,0x3e59c66d);
        uVar7 = __mulsf3(uVar10,0x3f3714ba);
        uVar13 = __addsf3(uVar13,uVar7);
        uVar7 = __mulsf3(uVar11,0x3d93cd57);
        uVar13 = __addsf3(uVar13,uVar7);
        uVar9 = __mulsf3(uVar9,0x3c9e6256);
        uVar10 = __mulsf3(uVar10,0x3df41b76);
        uVar9 = __addsf3(uVar9,uVar10);
        uVar10 = __mulsf3(uVar11,0x3f734214);
        uVar9 = __addsf3(uVar9,uVar10);
        __addsf3(uVar12,uVar13);
        uVar9 = __addsf3(uVar9);
        iVar8 = __eqsf2(0);
        if (iVar8 == 0) {
          param_3[4] = '\0';
          param_3[5] = '\0';
          param_3[2] = '\0';
          param_3[3] = '\0';
        }
        else {
          __divsf3(uVar12,uVar9);
          __mulsf3(0x477eff00);
          uVar4 = __fixunssfsi();
          *(undefined2 *)(param_3 + 2) = uVar4;
          __divsf3(uVar13,uVar9);
          __mulsf3(0x477eff00);
          uVar4 = __fixunssfsi();
          *(undefined2 *)(param_3 + 4) = uVar4;
        }
      }
      else if (cVar1 == '\x02') {
        uVar16 = (uVar14 * 0xffff) / 0xfe;
        uVar15 = ((0xffff - uVar16) * 0xfffe) / 0xffff & 0xffff;
        uVar17 = ((uVar18 % 0x2a) * 0xffff) / 0x2a & 0xffff;
        uVar14 = ((0xffff - (uVar17 * uVar16) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar17 = ((0xffff - ((0xffff - uVar17) * uVar16) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar16 = (uVar18 / 0x2a) % 6;
        uVar18 = uVar15;
        if (uVar16 == 2) {
          uVar14 = 0xfffe;
          uVar3 = uVar17;
        }
        else if (uVar16 < 3) {
          uVar3 = uVar15;
          if (uVar16 == 0) {
            uVar18 = 0xfffe;
            uVar14 = uVar17;
          }
          else if (uVar16 == 1) {
            uVar18 = uVar14;
            uVar14 = 0xfffe;
          }
          else {
            uVar3 = uVar14;
            uVar18 = 0xfffe;
            uVar14 = uVar15;
          }
        }
        else if (uVar16 == 3) {
          uVar3 = 0xfffe;
        }
        else if (uVar16 == 4) {
          uVar3 = 0xfffe;
          uVar18 = uVar17;
          uVar14 = uVar15;
        }
        else {
          uVar3 = uVar14;
          uVar18 = 0xfffe;
          uVar14 = uVar15;
        }
        __floatunsisf(uVar18);
        uVar9 = __divsf3(0x477fff00);
        __floatunsisf(uVar14);
        uVar10 = __divsf3(0x477fff00);
        __floatunsisf(uVar3);
        uVar11 = __divsf3(0x477fff00);
        uVar12 = __mulsf3(uVar9,0x3ed32d0a);
        uVar13 = __mulsf3(uVar10,0x3eb714ba);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar11,0x3e38c0cf);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar9,0x3e59c66d);
        uVar7 = __mulsf3(uVar10,0x3f3714ba);
        uVar13 = __addsf3(uVar13,uVar7);
        uVar7 = __mulsf3(uVar11,0x3d93cd57);
        uVar13 = __addsf3(uVar13,uVar7);
        uVar9 = __mulsf3(uVar9,0x3c9e6256);
        uVar10 = __mulsf3(uVar10,0x3df41b76);
        uVar9 = __addsf3(uVar9,uVar10);
        uVar10 = __mulsf3(uVar11,0x3f734214);
        uVar9 = __addsf3(uVar9,uVar10);
        __addsf3(uVar12,uVar13);
        uVar9 = __addsf3(uVar9);
        iVar8 = __eqsf2(0);
        if (iVar8 == 0) {
          param_3[4] = '\0';
          param_3[5] = '\0';
          param_3[2] = '\0';
          param_3[3] = '\0';
        }
        else {
          __divsf3(uVar12,uVar9);
          __mulsf3(0x477eff00);
          uVar4 = __fixunssfsi();
          *(undefined2 *)(param_3 + 2) = uVar4;
          __divsf3(uVar13,uVar9);
          __mulsf3(0x477eff00);
          uVar4 = __fixunssfsi();
          *(undefined2 *)(param_3 + 4) = uVar4;
        }
        __floatunsisf(*(undefined2 *)(param_3 + 2));
        uVar9 = __divsf3(0x477eff00);
        __floatunsisf(*(undefined2 *)(param_3 + 4));
        uVar10 = __divsf3(0x477eff00);
        uVar9 = __subsf3(uVar9,0x3ea9fbe7);
        uVar10 = __subsf3(uVar10,0x3e3e425b);
        uVar9 = __divsf3(uVar9,uVar10);
        __mulsf3(0xc3e08000);
        __addsf3(0x455c5000);
        __mulsf3(uVar9);
        uVar10 = __mulsf3(uVar9);
        uVar9 = __mulsf3(uVar9,0x45d53a66);
        __subsf3(uVar10,uVar9);
        uVar9 = __addsf3(0x45ac82a4);
        iVar8 = __gtsf2(0x461c4000);
        if (iVar8 < 1) {
          iVar8 = __ltsf2(uVar9,0x447a0000);
          if (iVar8 < 0) {
            uVar9 = 0x447a0000;
          }
        }
        else {
          uVar9 = 0x461c4000;
        }
        uVar4 = __fixunssfsi(uVar9);
        *(undefined2 *)(param_3 + 2) = uVar4;
      }
      else if (cVar1 == '\x03') {
        *(short *)(param_3 + 2) = (short)(uVar18 << 8);
        param_3[4] = (char)uVar14;
      }
      else {
        param_3[2] = (char)uVar18;
        param_3[4] = (char)uVar14;
      }
    }
    else if (param_2 == 1) {
      iVar8 = color_control_srv_get_attr_desc(param_1,3);
      iVar6 = color_control_srv_get_attr_desc(param_1,4);
      if (iVar8 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = **(undefined2 **)(iVar8 + 8);
      }
      if (iVar6 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = **(undefined2 **)(iVar6 + 8);
      }
      cVar1 = *param_3;
      if (cVar1 == '\0') {
        __floatunsisf();
        uVar2 = __divsf3(0x477eff00);
        __floatunsisf(uVar5);
        uVar9 = __divsf3(0x477eff00);
        __subsf3(0x3f800000,uVar2);
        uVar10 = __subsf3(uVar9);
        uVar11 = __mulsf3(uVar2,0x404f6402);
        uVar12 = __mulsf3(uVar9,0x3fc4c155);
        uVar11 = __subsf3(uVar11,uVar12);
        uVar12 = __mulsf3(uVar10,0x3eff3ffb);
        uVar11 = __subsf3(uVar11,uVar12);
        uVar12 = __mulsf3(uVar2,0xbf782129);
        uVar13 = __mulsf3(uVar9,0x3ff02081);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar10,0x3d2a36a0);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar2 = __mulsf3(uVar2,0x3d63ef28);
        uVar9 = __mulsf3(uVar9,0x3e50f0a6);
        uVar2 = __subsf3(uVar2,uVar9);
        uVar9 = __mulsf3(uVar10,0x3f8755f8);
        uVar2 = __addsf3(uVar2,uVar9);
        iVar8 = __gtsf2(uVar11,0x3f800000);
        if (iVar8 < 1) {
          iVar8 = __ltsf2(uVar11,0);
          if (iVar8 < 0) {
            uVar11 = 0;
          }
        }
        else {
          uVar11 = 0x3f800000;
        }
        iVar8 = __gtsf2(uVar12,0x3f800000);
        if (iVar8 < 1) {
          iVar8 = __ltsf2(uVar12,0);
          if (iVar8 < 0) {
            uVar12 = 0;
          }
        }
        else {
          uVar12 = 0x3f800000;
        }
        iVar8 = __gtsf2(uVar2,0x3f800000);
        if (iVar8 < 1) {
          iVar8 = __ltsf2(uVar2,0);
          if (iVar8 < 0) {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0x3f800000;
        }
        __mulsf3(uVar11,0x477fff00);
        uVar14 = __fixunssfsi();
        uVar14 = uVar14 & 0xffff;
        __mulsf3(uVar12,0x477fff00);
        uVar15 = __fixunssfsi();
        uVar15 = uVar15 & 0xffff;
        __mulsf3(uVar2,0x477fff00);
        uVar16 = __fixunssfsi();
        uVar16 = uVar16 & 0xffff;
        uVar18 = uVar14;
        if (uVar15 < uVar14) {
          uVar18 = uVar15;
        }
        if (uVar16 < uVar18) {
          uVar18 = uVar16;
        }
        uVar17 = uVar14;
        if (uVar14 < uVar15) {
          uVar17 = uVar15;
        }
        if (uVar17 < uVar16) {
          uVar17 = uVar16;
        }
        uVar18 = uVar17 - uVar18 & 0xffff;
        uVar2 = 0;
        if (uVar17 == 0) {
          param_3[4] = '\0';
          param_3[2] = '\0';
        }
        else {
          param_3[4] = (char)((uVar18 * 0xfe) / uVar17);
          if (uVar18 == 0) {
            param_3[2] = '\0';
          }
          else if (uVar14 == uVar17) {
            param_3[2] = (char)((((uVar15 - uVar16) * 0xfe) / uVar18) / 6);
          }
          else if (uVar15 == uVar17) {
            param_3[2] = (char)((uint)(((int)(uVar16 - uVar14) / (int)uVar18 + 2) * 0xfe) / 6);
          }
          else {
            param_3[2] = (char)((uint)(((int)(uVar14 - uVar15) / (int)uVar18 + 4) * 0xfe) / 6);
          }
        }
      }
      else if (cVar1 == '\x02') {
        __floatunsisf();
        uVar2 = __divsf3(0x477eff00);
        __floatunsisf(uVar5);
        uVar9 = __divsf3(0x477eff00);
        uVar2 = __subsf3(uVar2,0x3ea9fbe7);
        uVar9 = __subsf3(uVar9,0x3e3e425b);
        uVar2 = __divsf3(uVar2,uVar9);
        __mulsf3(0xc3e08000);
        __addsf3(0x455c5000);
        __mulsf3(uVar2);
        uVar9 = __mulsf3(uVar2);
        uVar2 = __mulsf3(uVar2,0x45d53a66);
        __subsf3(uVar9,uVar2);
        uVar2 = __addsf3(0x45ac82a4);
        iVar8 = __gtsf2(0x461c4000);
        if (iVar8 < 1) {
          iVar8 = __ltsf2(uVar2,0x447a0000);
          if (iVar8 < 0) {
            uVar2 = 0x447a0000;
          }
        }
        else {
          uVar2 = 0x461c4000;
        }
        uVar4 = __fixunssfsi(uVar2);
        *(undefined2 *)(param_3 + 2) = uVar4;
        uVar2 = 0;
      }
      else if (cVar1 == '\x03') {
        __floatunsisf();
        uVar2 = __divsf3(0x477eff00);
        __floatunsisf(uVar5);
        uVar9 = __divsf3(0x477eff00);
        __subsf3(0x3f800000,uVar2);
        uVar10 = __subsf3(uVar9);
        uVar11 = __mulsf3(uVar2,0x404f6402);
        uVar12 = __mulsf3(uVar9,0x3fc4c155);
        uVar11 = __subsf3(uVar11,uVar12);
        uVar12 = __mulsf3(uVar10,0x3eff3ffb);
        uVar11 = __subsf3(uVar11,uVar12);
        uVar12 = __mulsf3(uVar2,0xbf782129);
        uVar13 = __mulsf3(uVar9,0x3ff02081);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar10,0x3d2a36a0);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar2 = __mulsf3(uVar2,0x3d63ef28);
        uVar9 = __mulsf3(uVar9,0x3e50f0a6);
        uVar2 = __subsf3(uVar2,uVar9);
        uVar9 = __mulsf3(uVar10,0x3f8755f8);
        uVar2 = __addsf3(uVar2,uVar9);
        iVar8 = __gtsf2(uVar11,0x3f800000);
        if (iVar8 < 1) {
          iVar8 = __ltsf2(uVar11,0);
          if (iVar8 < 0) {
            uVar11 = 0;
          }
        }
        else {
          uVar11 = 0x3f800000;
        }
        iVar8 = __gtsf2(uVar12,0x3f800000);
        if (iVar8 < 1) {
          iVar8 = __ltsf2(uVar12,0);
          if (iVar8 < 0) {
            uVar12 = 0;
          }
        }
        else {
          uVar12 = 0x3f800000;
        }
        iVar8 = __gtsf2(uVar2,0x3f800000);
        if (iVar8 < 1) {
          iVar8 = __ltsf2(uVar2,0);
          if (iVar8 < 0) {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0x3f800000;
        }
        __mulsf3(uVar11,0x477fff00);
        uVar14 = __fixunssfsi();
        uVar14 = uVar14 & 0xffff;
        __mulsf3(uVar12,0x477fff00);
        uVar15 = __fixunssfsi();
        uVar15 = uVar15 & 0xffff;
        __mulsf3(uVar2,0x477fff00);
        uVar16 = __fixunssfsi();
        uVar16 = uVar16 & 0xffff;
        uVar18 = uVar14;
        if (uVar15 < uVar14) {
          uVar18 = uVar15;
        }
        if (uVar16 < uVar18) {
          uVar18 = uVar16;
        }
        uVar17 = uVar14;
        if (uVar14 < uVar15) {
          uVar17 = uVar15;
        }
        if (uVar17 < uVar16) {
          uVar17 = uVar16;
        }
        uVar18 = uVar17 - uVar18 & 0xffff;
        if (uVar17 == 0) {
          bStack_36 = 0;
        }
        else if (uVar18 == 0) {
          bStack_36 = 0;
        }
        else if (uVar14 == uVar17) {
          bStack_36 = (byte)((((uVar15 - uVar16) * 0xfe) / uVar18) / 6);
        }
        else if (uVar15 == uVar17) {
          bStack_36 = (byte)((uint)(((int)(uVar16 - uVar14) / (int)uVar18 + 2) * 0xfe) / 6);
        }
        else {
          bStack_36 = (byte)((uint)(((int)(uVar14 - uVar15) / (int)uVar18 + 4) * 0xfe) / 6);
        }
        *(ushort *)(param_3 + 2) = (ushort)bStack_36 << 8;
        param_3[4] = (char)uVar5;
        uVar2 = 0;
      }
      else {
        *(undefined2 *)(param_3 + 2) = uVar4;
        *(undefined2 *)(param_3 + 4) = uVar5;
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0x87;
    }
  }
  else if (param_2 == 3) {
    iVar8 = color_control_srv_get_attr_desc(param_1,0x4000);
    iVar6 = color_control_srv_get_attr_desc(param_1,1);
    if (iVar8 == 0) {
      uVar18 = 0;
    }
    else {
      uVar18 = (uint)**(ushort **)(iVar8 + 8);
    }
    if (iVar6 == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = (uint)**(byte **)(iVar6 + 8);
    }
    cVar1 = *param_3;
    if (cVar1 == '\0') {
      param_3[2] = (char)(uVar18 >> 8);
      param_3[4] = (char)uVar14;
      uVar2 = 0;
    }
    else if (cVar1 == '\x01') {
      uVar16 = (uVar14 * 0xffff) / 0xfe;
      uVar14 = ((0xffff - uVar16) * 0xfffe) / 0xffff & 0xffff;
      uVar17 = (((uVar18 >> 8) + (uVar18 / 0x2a00) * -0x2a & 0xff) * 0xffff) / 0x2a & 0xffff;
      uVar15 = ((0xffff - (uVar17 * uVar16) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
      uVar16 = ((0xffff - ((0xffff - uVar17) * uVar16) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
      uVar18 = (uVar18 / 0x2a00) % 6;
      if (uVar18 == 2) {
        uVar3 = 0xfffe;
        uVar17 = uVar16;
      }
      else {
        uVar3 = uVar14;
        if (uVar18 < 3) {
          uVar17 = uVar14;
          if (uVar18 == 0) {
            uVar3 = uVar16;
            uVar14 = 0xfffe;
          }
          else if (uVar18 == 1) {
            uVar3 = 0xfffe;
            uVar14 = uVar15;
          }
          else {
            uVar17 = uVar15;
            uVar14 = 0xfffe;
          }
        }
        else if (uVar18 == 3) {
          uVar17 = 0xfffe;
          uVar3 = uVar15;
        }
        else if (uVar18 == 4) {
          uVar17 = 0xfffe;
          uVar14 = uVar16;
        }
        else {
          uVar17 = uVar15;
          uVar14 = 0xfffe;
        }
      }
      __floatunsisf(uVar14);
      uVar2 = __divsf3(0x477fff00);
      __floatunsisf(uVar3);
      uVar9 = __divsf3(0x477fff00);
      __floatunsisf(uVar17);
      uVar10 = __divsf3(0x477fff00);
      uVar11 = __mulsf3(uVar2,0x3ed32d0a);
      uVar12 = __mulsf3(uVar9,0x3eb714ba);
      uVar11 = __addsf3(uVar11,uVar12);
      uVar12 = __mulsf3(uVar10,0x3e38c0cf);
      uVar11 = __addsf3(uVar11,uVar12);
      uVar12 = __mulsf3(uVar2,0x3e59c66d);
      uVar13 = __mulsf3(uVar9,0x3f3714ba);
      uVar12 = __addsf3(uVar12,uVar13);
      uVar13 = __mulsf3(uVar10,0x3d93cd57);
      uVar12 = __addsf3(uVar12,uVar13);
      uVar2 = __mulsf3(uVar2,0x3c9e6256);
      uVar9 = __mulsf3(uVar9,0x3df41b76);
      uVar2 = __addsf3(uVar2,uVar9);
      uVar9 = __mulsf3(uVar10,0x3f734214);
      uVar2 = __addsf3(uVar2,uVar9);
      __addsf3(uVar11,uVar12);
      uVar2 = __addsf3(uVar2);
      iVar8 = __eqsf2(0);
      if (iVar8 == 0) {
        param_3[4] = '\0';
        param_3[5] = '\0';
        param_3[2] = '\0';
        param_3[3] = '\0';
        uVar2 = 0;
      }
      else {
        __divsf3(uVar11,uVar2);
        __mulsf3(0x477eff00);
        uVar4 = __fixunssfsi();
        *(undefined2 *)(param_3 + 2) = uVar4;
        __divsf3(uVar12,uVar2);
        __mulsf3(0x477eff00);
        uVar4 = __fixunssfsi();
        *(undefined2 *)(param_3 + 4) = uVar4;
        uVar2 = 0;
      }
    }
    else if (cVar1 == '\x02') {
      uVar16 = (uVar14 * 0xffff) / 0xfe;
      uVar14 = ((0xffff - uVar16) * 0xfffe) / 0xffff & 0xffff;
      uVar17 = (((uVar18 >> 8) + (uVar18 / 0x2a00) * -0x2a & 0xff) * 0xffff) / 0x2a & 0xffff;
      uVar15 = ((0xffff - (uVar17 * uVar16) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
      uVar16 = ((0xffff - ((0xffff - uVar17) * uVar16) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
      uVar18 = (uVar18 / 0x2a00) % 6;
      if (uVar18 == 2) {
        uVar3 = 0xfffe;
        uVar17 = uVar16;
      }
      else {
        uVar3 = uVar14;
        if (uVar18 < 3) {
          uVar17 = uVar14;
          if (uVar18 == 0) {
            uVar3 = uVar16;
            uVar14 = 0xfffe;
          }
          else if (uVar18 == 1) {
            uVar3 = 0xfffe;
            uVar14 = uVar15;
          }
          else {
            uVar17 = uVar15;
            uVar14 = 0xfffe;
          }
        }
        else if (uVar18 == 3) {
          uVar17 = 0xfffe;
          uVar3 = uVar15;
        }
        else if (uVar18 == 4) {
          uVar17 = 0xfffe;
          uVar14 = uVar16;
        }
        else {
          uVar17 = uVar15;
          uVar14 = 0xfffe;
        }
      }
      __floatunsisf(uVar14);
      uVar2 = __divsf3(0x477fff00);
      __floatunsisf(uVar3);
      uVar9 = __divsf3(0x477fff00);
      __floatunsisf(uVar17);
      uVar10 = __divsf3(0x477fff00);
      uVar11 = __mulsf3(uVar2,0x3ed32d0a);
      uVar12 = __mulsf3(uVar9,0x3eb714ba);
      uVar11 = __addsf3(uVar11,uVar12);
      uVar12 = __mulsf3(uVar10,0x3e38c0cf);
      uVar11 = __addsf3(uVar11,uVar12);
      uVar12 = __mulsf3(uVar2,0x3e59c66d);
      uVar13 = __mulsf3(uVar9,0x3f3714ba);
      uVar12 = __addsf3(uVar12,uVar13);
      uVar13 = __mulsf3(uVar10,0x3d93cd57);
      uVar12 = __addsf3(uVar12,uVar13);
      uVar2 = __mulsf3(uVar2,0x3c9e6256);
      uVar9 = __mulsf3(uVar9,0x3df41b76);
      uVar2 = __addsf3(uVar2,uVar9);
      uVar9 = __mulsf3(uVar10,0x3f734214);
      uVar2 = __addsf3(uVar2,uVar9);
      __addsf3(uVar11,uVar12);
      uVar2 = __addsf3(uVar2);
      iVar8 = __eqsf2(0);
      if (iVar8 == 0) {
        param_3[4] = '\0';
        param_3[5] = '\0';
        param_3[2] = '\0';
        param_3[3] = '\0';
      }
      else {
        __divsf3(uVar11,uVar2);
        __mulsf3(0x477eff00);
        uVar4 = __fixunssfsi();
        *(undefined2 *)(param_3 + 2) = uVar4;
        __divsf3(uVar12,uVar2);
        __mulsf3(0x477eff00);
        uVar4 = __fixunssfsi();
        *(undefined2 *)(param_3 + 4) = uVar4;
      }
      __floatunsisf(*(undefined2 *)(param_3 + 2));
      uVar2 = __divsf3(0x477eff00);
      __floatunsisf(*(undefined2 *)(param_3 + 4));
      uVar9 = __divsf3(0x477eff00);
      uVar2 = __subsf3(uVar2,0x3ea9fbe7);
      uVar9 = __subsf3(uVar9,0x3e3e425b);
      uVar2 = __divsf3(uVar2,uVar9);
      __mulsf3(0xc3e08000);
      __addsf3(0x455c5000);
      __mulsf3(uVar2);
      uVar9 = __mulsf3(uVar2);
      uVar2 = __mulsf3(uVar2,0x45d53a66);
      __subsf3(uVar9,uVar2);
      uVar2 = __addsf3(0x45ac82a4);
      iVar8 = __gtsf2(0x461c4000);
      if (iVar8 < 1) {
        iVar8 = __ltsf2(uVar2,0x447a0000);
        if (iVar8 < 0) {
          uVar2 = 0x447a0000;
        }
      }
      else {
        uVar2 = 0x461c4000;
      }
      uVar4 = __fixunssfsi(uVar2);
      *(undefined2 *)(param_3 + 2) = uVar4;
      uVar2 = 0;
    }
    else {
      *(short *)(param_3 + 2) = (short)uVar18;
      param_3[4] = (char)uVar14;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0x87;
  }
  return uVar2;
}

