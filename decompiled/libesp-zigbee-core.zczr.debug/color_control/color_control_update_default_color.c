/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_update_default_color
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
color_control_update_default_color
          (uint16_t ep_id,uint8_t old_mode,ezb_zcl_color_control_color_t *new_color)

{
  uint8_t uVar1;
  ezb_zcl_status_t eVar2;
  uint uVar3;
  uint16_t uVar4;
  uint16_t uVar5;
  zcl_attr_desc_t *pzVar6;
  zcl_attr_desc_t *pzVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined3 in_register_0000202d;
  uint uVar18;
  uint uVar19;
  ushort uVar20;
  byte bStack_36;
  ezb_zcl_color_control_color_t old_color;
  
  uVar19 = CONCAT31(in_register_0000202d,old_mode);
  old_color.mode = '\0';
  if (new_color == (ezb_zcl_color_control_color_t *)0x0) {
    eVar2 = '\0';
  }
  else {
    uVar1 = (uint8_t)ep_id;
    if (uVar19 == 2) {
      pzVar7 = color_control_srv_get_attr_desc(uVar1,7);
      if (pzVar7 == (zcl_attr_desc_t *)0x0) {
        uVar20 = 0;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        uVar20 = *pzVar7->data_p;
      }
      uVar1 = new_color->mode;
      if (uVar1 == '\0') {
        __floatunsisf(uVar20);
        uVar8 = __divsf3(0x447a0000);
        if (uVar20 < 0xfb) {
          __mulsf3(0xc041a77a);
          __addsf3(0x4006d9b5);
          __mulsf3(uVar8);
          __addsf3(0x3e63fa5a);
          __mulsf3(uVar8);
          uVar8 = __addsf3(0x3e7628cc);
          __mulsf3(0x40453b86);
          __subsf3(0x40bbf2c9);
          __mulsf3(uVar8);
          __addsf3(0x40701283);
          __mulsf3(uVar8);
          uVar9 = __subsf3(0x3ebd7294);
        }
        else {
          __mulsf3(0xbe884164);
          __subsf3(0x3e6ffb8b);
          __mulsf3(uVar8);
          __addsf3(0x3f60b0a9);
          __mulsf3(uVar8);
          uVar8 = __addsf3(0x3e383a54);
          if (uVar20 < 0x1c3) {
            __mulsf3(0xbf747772);
            __subsf3(0x3fafe553);
            __mulsf3(uVar8);
            __addsf3(0x4005d902);
            __mulsf3(uVar8);
            uVar9 = __subsf3(0x3e2b8228);
          }
          else {
            __mulsf3(0xbf8d9de8);
            __subsf3(0x3fac8ee0);
            __mulsf3(uVar8);
            __addsf3(0x400be030);
            __mulsf3(uVar8);
            uVar9 = __subsf3(0x3e4f0cae);
          }
        }
        iVar10 = __gtsf2(uVar8,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar8,0);
          if (iVar10 < 0) {
            uVar8 = 0;
          }
        }
        else {
          uVar8 = 0x3f800000;
        }
        __mulsf3(uVar8,0x477eff00);
        uVar4 = __fixunssfsi();
        (new_color->field_1).field_1.x = uVar4;
        iVar10 = __gtsf2(uVar9,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar9,0);
          if (iVar10 < 0) {
            uVar9 = 0;
          }
        }
        else {
          uVar9 = 0x3f800000;
        }
        __mulsf3(uVar9,0x477eff00);
        uVar5 = __fixunssfsi();
        (new_color->field_1).field_1.y = uVar5;
        __floatunsisf(uVar4);
        uVar8 = __divsf3(0x477eff00);
        __floatunsisf(uVar5);
        uVar9 = __divsf3(0x477eff00);
        __subsf3(0x3f800000,uVar8);
        uVar11 = __subsf3(uVar9);
        uVar12 = __mulsf3(uVar8,0x404f6402);
        uVar13 = __mulsf3(uVar9,0x3fc4c155);
        uVar12 = __subsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar11,0x3eff3ffb);
        uVar12 = __subsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar8,0xbf782129);
        uVar14 = __mulsf3(uVar9,0x3ff02081);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar14 = __mulsf3(uVar11,0x3d2a36a0);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar8 = __mulsf3(uVar8,0x3d63ef28);
        uVar9 = __mulsf3(uVar9,0x3e50f0a6);
        uVar8 = __subsf3(uVar8,uVar9);
        uVar9 = __mulsf3(uVar11,0x3f8755f8);
        uVar8 = __addsf3(uVar8,uVar9);
        iVar10 = __gtsf2(uVar12,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar12,0);
          if (iVar10 < 0) {
            uVar12 = 0;
          }
        }
        else {
          uVar12 = 0x3f800000;
        }
        iVar10 = __gtsf2(uVar13,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar13,0);
          if (iVar10 < 0) {
            uVar13 = 0;
          }
        }
        else {
          uVar13 = 0x3f800000;
        }
        iVar10 = __gtsf2(uVar8,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar8,0);
          if (iVar10 < 0) {
            uVar8 = 0;
          }
        }
        else {
          uVar8 = 0x3f800000;
        }
        __mulsf3(uVar12,0x477fff00);
        uVar15 = __fixunssfsi();
        uVar15 = uVar15 & 0xffff;
        __mulsf3(uVar13,0x477fff00);
        uVar16 = __fixunssfsi();
        uVar16 = uVar16 & 0xffff;
        __mulsf3(uVar8,0x477fff00);
        uVar17 = __fixunssfsi();
        uVar17 = uVar17 & 0xffff;
        uVar19 = uVar15;
        if (uVar16 < uVar15) {
          uVar19 = uVar16;
        }
        if (uVar17 < uVar19) {
          uVar19 = uVar17;
        }
        uVar18 = uVar15;
        if (uVar15 < uVar16) {
          uVar18 = uVar16;
        }
        if (uVar18 < uVar17) {
          uVar18 = uVar17;
        }
        uVar19 = uVar18 - uVar19 & 0xffff;
        eVar2 = '\0';
        if (uVar18 == 0) {
          (new_color->field_1).field_0.saturation = '\0';
          *(undefined1 *)&new_color->field_1 = 0;
        }
        else {
          (new_color->field_1).field_0.saturation = (uint8_t)((uVar19 * 0xfe) / uVar18);
          if (uVar19 == 0) {
            *(undefined1 *)&new_color->field_1 = 0;
          }
          else if (uVar15 == uVar18) {
            *(char *)&new_color->field_1 = (char)((((uVar16 - uVar17) * 0xfe) / uVar19) / 6);
          }
          else if (uVar16 == uVar18) {
            *(char *)&new_color->field_1 =
                 (char)((uint)(((int)(uVar17 - uVar15) / (int)uVar19 + 2) * 0xfe) / 6);
          }
          else {
            *(char *)&new_color->field_1 =
                 (char)((uint)(((int)(uVar15 - uVar16) / (int)uVar19 + 4) * 0xfe) / 6);
          }
        }
      }
      else if (uVar1 == '\x01') {
        __floatunsisf(uVar20);
        uVar8 = __divsf3(0x447a0000);
        if (uVar20 < 0xfb) {
          __mulsf3(0xc041a77a);
          __addsf3(0x4006d9b5);
          __mulsf3(uVar8);
          __addsf3(0x3e63fa5a);
          __mulsf3(uVar8);
          uVar8 = __addsf3(0x3e7628cc);
          __mulsf3(0x40453b86);
          __subsf3(0x40bbf2c9);
          __mulsf3(uVar8);
          __addsf3(0x40701283);
          __mulsf3(uVar8);
          uVar9 = __subsf3(0x3ebd7294);
        }
        else {
          __mulsf3(0xbe884164);
          __subsf3(0x3e6ffb8b);
          __mulsf3(uVar8);
          __addsf3(0x3f60b0a9);
          __mulsf3(uVar8);
          uVar8 = __addsf3(0x3e383a54);
          if (uVar20 < 0x1c3) {
            __mulsf3(0xbf747772);
            __subsf3(0x3fafe553);
            __mulsf3(uVar8);
            __addsf3(0x4005d902);
            __mulsf3(uVar8);
            uVar9 = __subsf3(0x3e2b8228);
          }
          else {
            __mulsf3(0xbf8d9de8);
            __subsf3(0x3fac8ee0);
            __mulsf3(uVar8);
            __addsf3(0x400be030);
            __mulsf3(uVar8);
            uVar9 = __subsf3(0x3e4f0cae);
          }
        }
        iVar10 = __gtsf2(uVar8,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar8,0);
          if (iVar10 < 0) {
            uVar8 = 0;
          }
        }
        else {
          uVar8 = 0x3f800000;
        }
        __mulsf3(uVar8,0x477eff00);
        uVar4 = __fixunssfsi();
        (new_color->field_1).field_1.x = uVar4;
        iVar10 = __gtsf2(uVar9,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar9,0);
          if (iVar10 < 0) {
            uVar9 = 0;
          }
        }
        else {
          uVar9 = 0x3f800000;
        }
        __mulsf3(uVar9,0x477eff00);
        uVar4 = __fixunssfsi();
        (new_color->field_1).field_1.y = uVar4;
        eVar2 = '\0';
      }
      else if (uVar1 == '\x03') {
        __floatunsisf(uVar20);
        uVar8 = __divsf3(0x447a0000);
        if (uVar20 < 0xfb) {
          __mulsf3(0xc041a77a);
          __addsf3(0x4006d9b5);
          __mulsf3(uVar8);
          __addsf3(0x3e63fa5a);
          __mulsf3(uVar8);
          uVar8 = __addsf3(0x3e7628cc);
          __mulsf3(0x40453b86);
          __subsf3(0x40bbf2c9);
          __mulsf3(uVar8);
          __addsf3(0x40701283);
          __mulsf3(uVar8);
          uVar9 = __subsf3(0x3ebd7294);
        }
        else {
          __mulsf3(0xbe884164);
          __subsf3(0x3e6ffb8b);
          __mulsf3(uVar8);
          __addsf3(0x3f60b0a9);
          __mulsf3(uVar8);
          uVar8 = __addsf3(0x3e383a54);
          if (uVar20 < 0x1c3) {
            __mulsf3(0xbf747772);
            __subsf3(0x3fafe553);
            __mulsf3(uVar8);
            __addsf3(0x4005d902);
            __mulsf3(uVar8);
            uVar9 = __subsf3(0x3e2b8228);
          }
          else {
            __mulsf3(0xbf8d9de8);
            __subsf3(0x3fac8ee0);
            __mulsf3(uVar8);
            __addsf3(0x400be030);
            __mulsf3(uVar8);
            uVar9 = __subsf3(0x3e4f0cae);
          }
        }
        iVar10 = __gtsf2(uVar8,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar8,0);
          if (iVar10 < 0) {
            uVar8 = 0;
          }
        }
        else {
          uVar8 = 0x3f800000;
        }
        __mulsf3(uVar8,0x477eff00);
        uVar4 = __fixunssfsi();
        (new_color->field_1).field_1.x = uVar4;
        iVar10 = __gtsf2(uVar9,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar9,0);
          if (iVar10 < 0) {
            uVar9 = 0;
          }
        }
        else {
          uVar9 = 0x3f800000;
        }
        __mulsf3(uVar9,0x477eff00);
        uVar5 = __fixunssfsi();
        (new_color->field_1).field_1.y = uVar5;
        __floatunsisf(uVar4);
        uVar8 = __divsf3(0x477eff00);
        __floatunsisf(uVar5);
        uVar9 = __divsf3(0x477eff00);
        __subsf3(0x3f800000,uVar8);
        uVar11 = __subsf3(uVar9);
        uVar12 = __mulsf3(uVar8,0x404f6402);
        uVar13 = __mulsf3(uVar9,0x3fc4c155);
        uVar12 = __subsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar11,0x3eff3ffb);
        uVar12 = __subsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar8,0xbf782129);
        uVar14 = __mulsf3(uVar9,0x3ff02081);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar14 = __mulsf3(uVar11,0x3d2a36a0);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar8 = __mulsf3(uVar8,0x3d63ef28);
        uVar9 = __mulsf3(uVar9,0x3e50f0a6);
        uVar8 = __subsf3(uVar8,uVar9);
        uVar9 = __mulsf3(uVar11,0x3f8755f8);
        uVar8 = __addsf3(uVar8,uVar9);
        iVar10 = __gtsf2(uVar12,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar12,0);
          if (iVar10 < 0) {
            uVar12 = 0;
          }
        }
        else {
          uVar12 = 0x3f800000;
        }
        iVar10 = __gtsf2(uVar13,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar13,0);
          if (iVar10 < 0) {
            uVar13 = 0;
          }
        }
        else {
          uVar13 = 0x3f800000;
        }
        iVar10 = __gtsf2(uVar8,0x3f800000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar8,0);
          if (iVar10 < 0) {
            uVar8 = 0;
          }
        }
        else {
          uVar8 = 0x3f800000;
        }
        __mulsf3(uVar12,0x477fff00);
        uVar15 = __fixunssfsi();
        uVar15 = uVar15 & 0xffff;
        __mulsf3(uVar13,0x477fff00);
        uVar16 = __fixunssfsi();
        uVar16 = uVar16 & 0xffff;
        __mulsf3(uVar8,0x477fff00);
        uVar17 = __fixunssfsi();
        uVar17 = uVar17 & 0xffff;
        uVar19 = uVar15;
        if (uVar16 < uVar15) {
          uVar19 = uVar16;
        }
        if (uVar17 < uVar19) {
          uVar19 = uVar17;
        }
        uVar18 = uVar15;
        if (uVar15 < uVar16) {
          uVar18 = uVar16;
        }
        if (uVar18 < uVar17) {
          uVar18 = uVar17;
        }
        uVar19 = uVar18 - uVar19 & 0xffff;
        if (uVar18 == 0) {
          bStack_36 = 0;
        }
        else {
          old_color.mode = (uint8_t)((uVar19 * 0xfe) / uVar18);
          if (uVar19 == 0) {
            bStack_36 = 0;
          }
          else if (uVar15 == uVar18) {
            bStack_36 = (byte)((((uVar16 - uVar17) * 0xfe) / uVar19) / 6);
          }
          else if (uVar16 == uVar18) {
            bStack_36 = (byte)((uint)(((int)(uVar17 - uVar15) / (int)uVar19 + 2) * 0xfe) / 6);
          }
          else {
            bStack_36 = (byte)((uint)(((int)(uVar15 - uVar16) / (int)uVar19 + 4) * 0xfe) / 6);
          }
        }
        (new_color->field_1).field_1.x = (ushort)bStack_36 << 8;
        (new_color->field_1).field_0.saturation = old_color.mode;
        eVar2 = '\0';
      }
      else {
        (new_color->field_1).field_1.x = uVar20;
        eVar2 = '\0';
      }
    }
    else if (uVar19 < 3) {
      if (uVar19 == 0) {
        pzVar7 = color_control_srv_get_attr_desc(uVar1,0);
        pzVar6 = color_control_srv_get_attr_desc(uVar1,1);
        if (pzVar7 == (zcl_attr_desc_t *)0x0) {
          uVar19 = 0;
        }
        else {
                    /* WARNING: Load size is inaccurate */
          uVar19 = (uint)*pzVar7->data_p;
        }
        if (pzVar6 == (zcl_attr_desc_t *)0x0) {
          uVar15 = 0;
        }
        else {
                    /* WARNING: Load size is inaccurate */
          uVar15 = (uint)*pzVar6->data_p;
        }
        uVar1 = new_color->mode;
        eVar2 = '\0';
        if (uVar1 == '\x01') {
          uVar17 = (uVar15 * 0xffff) / 0xfe;
          uVar16 = ((0xffff - uVar17) * 0xfffe) / 0xffff & 0xffff;
          uVar18 = ((uVar19 % 0x2a) * 0xffff) / 0x2a & 0xffff;
          uVar15 = ((0xffff - (uVar18 * uVar17) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
          uVar18 = ((0xffff - ((0xffff - uVar18) * uVar17) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
          uVar17 = (uVar19 / 0x2a) % 6;
          uVar19 = uVar16;
          if (uVar17 == 2) {
            uVar15 = 0xfffe;
            uVar3 = uVar18;
          }
          else if (uVar17 < 3) {
            uVar3 = uVar16;
            if (uVar17 == 0) {
              uVar19 = 0xfffe;
              uVar15 = uVar18;
            }
            else if (uVar17 == 1) {
              uVar19 = uVar15;
              uVar15 = 0xfffe;
            }
            else {
              uVar3 = uVar15;
              uVar19 = 0xfffe;
              uVar15 = uVar16;
            }
          }
          else if (uVar17 == 3) {
            uVar3 = 0xfffe;
          }
          else if (uVar17 == 4) {
            uVar3 = 0xfffe;
            uVar19 = uVar18;
            uVar15 = uVar16;
          }
          else {
            uVar3 = uVar15;
            uVar19 = 0xfffe;
            uVar15 = uVar16;
          }
          __floatunsisf(uVar19);
          uVar8 = __divsf3(0x477fff00);
          __floatunsisf(uVar15);
          uVar9 = __divsf3(0x477fff00);
          __floatunsisf(uVar3);
          uVar11 = __divsf3(0x477fff00);
          uVar12 = __mulsf3(uVar8,0x3ed32d0a);
          uVar13 = __mulsf3(uVar9,0x3eb714ba);
          uVar12 = __addsf3(uVar12,uVar13);
          uVar13 = __mulsf3(uVar11,0x3e38c0cf);
          uVar12 = __addsf3(uVar12,uVar13);
          uVar13 = __mulsf3(uVar8,0x3e59c66d);
          uVar14 = __mulsf3(uVar9,0x3f3714ba);
          uVar13 = __addsf3(uVar13,uVar14);
          uVar14 = __mulsf3(uVar11,0x3d93cd57);
          uVar13 = __addsf3(uVar13,uVar14);
          uVar8 = __mulsf3(uVar8,0x3c9e6256);
          uVar9 = __mulsf3(uVar9,0x3df41b76);
          uVar8 = __addsf3(uVar8,uVar9);
          uVar9 = __mulsf3(uVar11,0x3f734214);
          uVar8 = __addsf3(uVar8,uVar9);
          __addsf3(uVar12,uVar13);
          uVar8 = __addsf3(uVar8);
          iVar10 = __eqsf2(0);
          if (iVar10 == 0) {
            (new_color->field_1).field_1.y = 0;
            (new_color->field_1).field_1.x = 0;
          }
          else {
            __divsf3(uVar12,uVar8);
            __mulsf3(0x477eff00);
            uVar4 = __fixunssfsi();
            (new_color->field_1).field_1.x = uVar4;
            __divsf3(uVar13,uVar8);
            __mulsf3(0x477eff00);
            uVar4 = __fixunssfsi();
            (new_color->field_1).field_1.y = uVar4;
          }
        }
        else if (uVar1 == '\x02') {
          uVar17 = (uVar15 * 0xffff) / 0xfe;
          uVar16 = ((0xffff - uVar17) * 0xfffe) / 0xffff & 0xffff;
          uVar18 = ((uVar19 % 0x2a) * 0xffff) / 0x2a & 0xffff;
          uVar15 = ((0xffff - (uVar18 * uVar17) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
          uVar18 = ((0xffff - ((0xffff - uVar18) * uVar17) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
          uVar17 = (uVar19 / 0x2a) % 6;
          uVar19 = uVar16;
          if (uVar17 == 2) {
            uVar15 = 0xfffe;
            uVar3 = uVar18;
          }
          else if (uVar17 < 3) {
            uVar3 = uVar16;
            if (uVar17 == 0) {
              uVar19 = 0xfffe;
              uVar15 = uVar18;
            }
            else if (uVar17 == 1) {
              uVar19 = uVar15;
              uVar15 = 0xfffe;
            }
            else {
              uVar3 = uVar15;
              uVar19 = 0xfffe;
              uVar15 = uVar16;
            }
          }
          else if (uVar17 == 3) {
            uVar3 = 0xfffe;
          }
          else if (uVar17 == 4) {
            uVar3 = 0xfffe;
            uVar19 = uVar18;
            uVar15 = uVar16;
          }
          else {
            uVar3 = uVar15;
            uVar19 = 0xfffe;
            uVar15 = uVar16;
          }
          __floatunsisf(uVar19);
          uVar8 = __divsf3(0x477fff00);
          __floatunsisf(uVar15);
          uVar9 = __divsf3(0x477fff00);
          __floatunsisf(uVar3);
          uVar11 = __divsf3(0x477fff00);
          uVar12 = __mulsf3(uVar8,0x3ed32d0a);
          uVar13 = __mulsf3(uVar9,0x3eb714ba);
          uVar12 = __addsf3(uVar12,uVar13);
          uVar13 = __mulsf3(uVar11,0x3e38c0cf);
          uVar12 = __addsf3(uVar12,uVar13);
          uVar13 = __mulsf3(uVar8,0x3e59c66d);
          uVar14 = __mulsf3(uVar9,0x3f3714ba);
          uVar13 = __addsf3(uVar13,uVar14);
          uVar14 = __mulsf3(uVar11,0x3d93cd57);
          uVar13 = __addsf3(uVar13,uVar14);
          uVar8 = __mulsf3(uVar8,0x3c9e6256);
          uVar9 = __mulsf3(uVar9,0x3df41b76);
          uVar8 = __addsf3(uVar8,uVar9);
          uVar9 = __mulsf3(uVar11,0x3f734214);
          uVar8 = __addsf3(uVar8,uVar9);
          __addsf3(uVar12,uVar13);
          uVar8 = __addsf3(uVar8);
          iVar10 = __eqsf2(0);
          if (iVar10 == 0) {
            (new_color->field_1).field_1.y = 0;
            (new_color->field_1).field_1.x = 0;
          }
          else {
            __divsf3(uVar12,uVar8);
            __mulsf3(0x477eff00);
            uVar4 = __fixunssfsi();
            (new_color->field_1).field_1.x = uVar4;
            __divsf3(uVar13,uVar8);
            __mulsf3(0x477eff00);
            uVar4 = __fixunssfsi();
            (new_color->field_1).field_1.y = uVar4;
          }
          __floatunsisf((new_color->field_1).field_1.x);
          uVar8 = __divsf3(0x477eff00);
          __floatunsisf((new_color->field_1).field_1.y);
          uVar9 = __divsf3(0x477eff00);
          uVar8 = __subsf3(uVar8,0x3ea9fbe7);
          uVar9 = __subsf3(uVar9,0x3e3e425b);
          uVar8 = __divsf3(uVar8,uVar9);
          __mulsf3(0xc3e08000);
          __addsf3(0x455c5000);
          __mulsf3(uVar8);
          uVar9 = __mulsf3(uVar8);
          uVar8 = __mulsf3(uVar8,0x45d53a66);
          __subsf3(uVar9,uVar8);
          uVar8 = __addsf3(0x45ac82a4);
          iVar10 = __gtsf2(0x461c4000);
          if (iVar10 < 1) {
            iVar10 = __ltsf2(uVar8,0x447a0000);
            if (iVar10 < 0) {
              uVar8 = 0x447a0000;
            }
          }
          else {
            uVar8 = 0x461c4000;
          }
          uVar4 = __fixunssfsi(uVar8);
          (new_color->field_1).field_1.x = uVar4;
        }
        else if (uVar1 == '\x03') {
          (new_color->field_1).field_1.x = (uint16_t)(uVar19 << 8);
          (new_color->field_1).field_0.saturation = (uint8_t)uVar15;
        }
        else {
          *(char *)&new_color->field_1 = (char)uVar19;
          (new_color->field_1).field_0.saturation = (uint8_t)uVar15;
        }
      }
      else if (uVar19 == 1) {
        pzVar7 = color_control_srv_get_attr_desc(uVar1,3);
        pzVar6 = color_control_srv_get_attr_desc(uVar1,4);
        if (pzVar7 == (zcl_attr_desc_t *)0x0) {
          uVar4 = 0;
        }
        else {
                    /* WARNING: Load size is inaccurate */
          uVar4 = *pzVar7->data_p;
        }
        if (pzVar6 == (zcl_attr_desc_t *)0x0) {
          uVar5 = 0;
        }
        else {
                    /* WARNING: Load size is inaccurate */
          uVar5 = *pzVar6->data_p;
        }
        uVar1 = new_color->mode;
        if (uVar1 == '\0') {
          __floatunsisf();
          uVar8 = __divsf3(0x477eff00);
          __floatunsisf(uVar5);
          uVar9 = __divsf3(0x477eff00);
          __subsf3(0x3f800000,uVar8);
          uVar11 = __subsf3(uVar9);
          uVar12 = __mulsf3(uVar8,0x404f6402);
          uVar13 = __mulsf3(uVar9,0x3fc4c155);
          uVar12 = __subsf3(uVar12,uVar13);
          uVar13 = __mulsf3(uVar11,0x3eff3ffb);
          uVar12 = __subsf3(uVar12,uVar13);
          uVar13 = __mulsf3(uVar8,0xbf782129);
          uVar14 = __mulsf3(uVar9,0x3ff02081);
          uVar13 = __addsf3(uVar13,uVar14);
          uVar14 = __mulsf3(uVar11,0x3d2a36a0);
          uVar13 = __addsf3(uVar13,uVar14);
          uVar8 = __mulsf3(uVar8,0x3d63ef28);
          uVar9 = __mulsf3(uVar9,0x3e50f0a6);
          uVar8 = __subsf3(uVar8,uVar9);
          uVar9 = __mulsf3(uVar11,0x3f8755f8);
          uVar8 = __addsf3(uVar8,uVar9);
          iVar10 = __gtsf2(uVar12,0x3f800000);
          if (iVar10 < 1) {
            iVar10 = __ltsf2(uVar12,0);
            if (iVar10 < 0) {
              uVar12 = 0;
            }
          }
          else {
            uVar12 = 0x3f800000;
          }
          iVar10 = __gtsf2(uVar13,0x3f800000);
          if (iVar10 < 1) {
            iVar10 = __ltsf2(uVar13,0);
            if (iVar10 < 0) {
              uVar13 = 0;
            }
          }
          else {
            uVar13 = 0x3f800000;
          }
          iVar10 = __gtsf2(uVar8,0x3f800000);
          if (iVar10 < 1) {
            iVar10 = __ltsf2(uVar8,0);
            if (iVar10 < 0) {
              uVar8 = 0;
            }
          }
          else {
            uVar8 = 0x3f800000;
          }
          __mulsf3(uVar12,0x477fff00);
          uVar15 = __fixunssfsi();
          uVar15 = uVar15 & 0xffff;
          __mulsf3(uVar13,0x477fff00);
          uVar16 = __fixunssfsi();
          uVar16 = uVar16 & 0xffff;
          __mulsf3(uVar8,0x477fff00);
          uVar17 = __fixunssfsi();
          uVar17 = uVar17 & 0xffff;
          uVar19 = uVar15;
          if (uVar16 < uVar15) {
            uVar19 = uVar16;
          }
          if (uVar17 < uVar19) {
            uVar19 = uVar17;
          }
          uVar18 = uVar15;
          if (uVar15 < uVar16) {
            uVar18 = uVar16;
          }
          if (uVar18 < uVar17) {
            uVar18 = uVar17;
          }
          uVar19 = uVar18 - uVar19 & 0xffff;
          eVar2 = '\0';
          if (uVar18 == 0) {
            (new_color->field_1).field_0.saturation = '\0';
            *(undefined1 *)&new_color->field_1 = 0;
          }
          else {
            (new_color->field_1).field_0.saturation = (uint8_t)((uVar19 * 0xfe) / uVar18);
            if (uVar19 == 0) {
              *(undefined1 *)&new_color->field_1 = 0;
            }
            else if (uVar15 == uVar18) {
              *(char *)&new_color->field_1 = (char)((((uVar16 - uVar17) * 0xfe) / uVar19) / 6);
            }
            else if (uVar16 == uVar18) {
              *(char *)&new_color->field_1 =
                   (char)((uint)(((int)(uVar17 - uVar15) / (int)uVar19 + 2) * 0xfe) / 6);
            }
            else {
              *(char *)&new_color->field_1 =
                   (char)((uint)(((int)(uVar15 - uVar16) / (int)uVar19 + 4) * 0xfe) / 6);
            }
          }
        }
        else if (uVar1 == '\x02') {
          __floatunsisf();
          uVar8 = __divsf3(0x477eff00);
          __floatunsisf(uVar5);
          uVar9 = __divsf3(0x477eff00);
          uVar8 = __subsf3(uVar8,0x3ea9fbe7);
          uVar9 = __subsf3(uVar9,0x3e3e425b);
          uVar8 = __divsf3(uVar8,uVar9);
          __mulsf3(0xc3e08000);
          __addsf3(0x455c5000);
          __mulsf3(uVar8);
          uVar9 = __mulsf3(uVar8);
          uVar8 = __mulsf3(uVar8,0x45d53a66);
          __subsf3(uVar9,uVar8);
          uVar8 = __addsf3(0x45ac82a4);
          iVar10 = __gtsf2(0x461c4000);
          if (iVar10 < 1) {
            iVar10 = __ltsf2(uVar8,0x447a0000);
            if (iVar10 < 0) {
              uVar8 = 0x447a0000;
            }
          }
          else {
            uVar8 = 0x461c4000;
          }
          uVar4 = __fixunssfsi(uVar8);
          (new_color->field_1).field_1.x = uVar4;
          eVar2 = '\0';
        }
        else if (uVar1 == '\x03') {
          __floatunsisf();
          uVar8 = __divsf3(0x477eff00);
          __floatunsisf(uVar5);
          uVar9 = __divsf3(0x477eff00);
          __subsf3(0x3f800000,uVar8);
          uVar11 = __subsf3(uVar9);
          uVar12 = __mulsf3(uVar8,0x404f6402);
          uVar13 = __mulsf3(uVar9,0x3fc4c155);
          uVar12 = __subsf3(uVar12,uVar13);
          uVar13 = __mulsf3(uVar11,0x3eff3ffb);
          uVar12 = __subsf3(uVar12,uVar13);
          uVar13 = __mulsf3(uVar8,0xbf782129);
          uVar14 = __mulsf3(uVar9,0x3ff02081);
          uVar13 = __addsf3(uVar13,uVar14);
          uVar14 = __mulsf3(uVar11,0x3d2a36a0);
          uVar13 = __addsf3(uVar13,uVar14);
          uVar8 = __mulsf3(uVar8,0x3d63ef28);
          uVar9 = __mulsf3(uVar9,0x3e50f0a6);
          uVar8 = __subsf3(uVar8,uVar9);
          uVar9 = __mulsf3(uVar11,0x3f8755f8);
          uVar8 = __addsf3(uVar8,uVar9);
          iVar10 = __gtsf2(uVar12,0x3f800000);
          if (iVar10 < 1) {
            iVar10 = __ltsf2(uVar12,0);
            if (iVar10 < 0) {
              uVar12 = 0;
            }
          }
          else {
            uVar12 = 0x3f800000;
          }
          iVar10 = __gtsf2(uVar13,0x3f800000);
          if (iVar10 < 1) {
            iVar10 = __ltsf2(uVar13,0);
            if (iVar10 < 0) {
              uVar13 = 0;
            }
          }
          else {
            uVar13 = 0x3f800000;
          }
          iVar10 = __gtsf2(uVar8,0x3f800000);
          if (iVar10 < 1) {
            iVar10 = __ltsf2(uVar8,0);
            if (iVar10 < 0) {
              uVar8 = 0;
            }
          }
          else {
            uVar8 = 0x3f800000;
          }
          __mulsf3(uVar12,0x477fff00);
          uVar15 = __fixunssfsi();
          uVar15 = uVar15 & 0xffff;
          __mulsf3(uVar13,0x477fff00);
          uVar16 = __fixunssfsi();
          uVar16 = uVar16 & 0xffff;
          __mulsf3(uVar8,0x477fff00);
          uVar17 = __fixunssfsi();
          uVar17 = uVar17 & 0xffff;
          uVar19 = uVar15;
          if (uVar16 < uVar15) {
            uVar19 = uVar16;
          }
          if (uVar17 < uVar19) {
            uVar19 = uVar17;
          }
          uVar18 = uVar15;
          if (uVar15 < uVar16) {
            uVar18 = uVar16;
          }
          if (uVar18 < uVar17) {
            uVar18 = uVar17;
          }
          uVar19 = uVar18 - uVar19 & 0xffff;
          if (uVar18 == 0) {
            bStack_36 = 0;
          }
          else if (uVar19 == 0) {
            bStack_36 = 0;
          }
          else if (uVar15 == uVar18) {
            bStack_36 = (byte)((((uVar16 - uVar17) * 0xfe) / uVar19) / 6);
          }
          else if (uVar16 == uVar18) {
            bStack_36 = (byte)((uint)(((int)(uVar17 - uVar15) / (int)uVar19 + 2) * 0xfe) / 6);
          }
          else {
            bStack_36 = (byte)((uint)(((int)(uVar15 - uVar16) / (int)uVar19 + 4) * 0xfe) / 6);
          }
          (new_color->field_1).field_1.x = (ushort)bStack_36 << 8;
          (new_color->field_1).field_0.saturation = (uint8_t)uVar5;
          eVar2 = '\0';
        }
        else {
          (new_color->field_1).field_1.x = uVar4;
          (new_color->field_1).field_1.y = uVar5;
          eVar2 = '\0';
        }
      }
      else {
        eVar2 = 0x87;
      }
    }
    else if (uVar19 == 3) {
      pzVar7 = color_control_srv_get_attr_desc(uVar1,0x4000);
      pzVar6 = color_control_srv_get_attr_desc(uVar1,1);
      if (pzVar7 == (zcl_attr_desc_t *)0x0) {
        uVar19 = 0;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        uVar19 = (uint)*pzVar7->data_p;
      }
      if (pzVar6 == (zcl_attr_desc_t *)0x0) {
        uVar15 = 0;
      }
      else {
                    /* WARNING: Load size is inaccurate */
        uVar15 = (uint)*pzVar6->data_p;
      }
      uVar1 = new_color->mode;
      if (uVar1 == '\0') {
        *(char *)&new_color->field_1 = (char)(uVar19 >> 8);
        (new_color->field_1).field_0.saturation = (uint8_t)uVar15;
        eVar2 = '\0';
      }
      else if (uVar1 == '\x01') {
        uVar17 = (uVar15 * 0xffff) / 0xfe;
        uVar15 = ((0xffff - uVar17) * 0xfffe) / 0xffff & 0xffff;
        uVar18 = (((uVar19 >> 8) + (uVar19 / 0x2a00) * -0x2a & 0xff) * 0xffff) / 0x2a & 0xffff;
        uVar16 = ((0xffff - (uVar18 * uVar17) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar17 = ((0xffff - ((0xffff - uVar18) * uVar17) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar19 = (uVar19 / 0x2a00) % 6;
        if (uVar19 == 2) {
          uVar3 = 0xfffe;
          uVar18 = uVar17;
        }
        else {
          uVar3 = uVar15;
          if (uVar19 < 3) {
            uVar18 = uVar15;
            if (uVar19 == 0) {
              uVar3 = uVar17;
              uVar15 = 0xfffe;
            }
            else if (uVar19 == 1) {
              uVar3 = 0xfffe;
              uVar15 = uVar16;
            }
            else {
              uVar18 = uVar16;
              uVar15 = 0xfffe;
            }
          }
          else if (uVar19 == 3) {
            uVar18 = 0xfffe;
            uVar3 = uVar16;
          }
          else if (uVar19 == 4) {
            uVar18 = 0xfffe;
            uVar15 = uVar17;
          }
          else {
            uVar18 = uVar16;
            uVar15 = 0xfffe;
          }
        }
        __floatunsisf(uVar15);
        uVar8 = __divsf3(0x477fff00);
        __floatunsisf(uVar3);
        uVar9 = __divsf3(0x477fff00);
        __floatunsisf(uVar18);
        uVar11 = __divsf3(0x477fff00);
        uVar12 = __mulsf3(uVar8,0x3ed32d0a);
        uVar13 = __mulsf3(uVar9,0x3eb714ba);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar11,0x3e38c0cf);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar8,0x3e59c66d);
        uVar14 = __mulsf3(uVar9,0x3f3714ba);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar14 = __mulsf3(uVar11,0x3d93cd57);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar8 = __mulsf3(uVar8,0x3c9e6256);
        uVar9 = __mulsf3(uVar9,0x3df41b76);
        uVar8 = __addsf3(uVar8,uVar9);
        uVar9 = __mulsf3(uVar11,0x3f734214);
        uVar8 = __addsf3(uVar8,uVar9);
        __addsf3(uVar12,uVar13);
        uVar8 = __addsf3(uVar8);
        iVar10 = __eqsf2(0);
        if (iVar10 == 0) {
          (new_color->field_1).field_1.y = 0;
          (new_color->field_1).field_1.x = 0;
          eVar2 = '\0';
        }
        else {
          __divsf3(uVar12,uVar8);
          __mulsf3(0x477eff00);
          uVar4 = __fixunssfsi();
          (new_color->field_1).field_1.x = uVar4;
          __divsf3(uVar13,uVar8);
          __mulsf3(0x477eff00);
          uVar4 = __fixunssfsi();
          (new_color->field_1).field_1.y = uVar4;
          eVar2 = '\0';
        }
      }
      else if (uVar1 == '\x02') {
        uVar17 = (uVar15 * 0xffff) / 0xfe;
        uVar15 = ((0xffff - uVar17) * 0xfffe) / 0xffff & 0xffff;
        uVar18 = (((uVar19 >> 8) + (uVar19 / 0x2a00) * -0x2a & 0xff) * 0xffff) / 0x2a & 0xffff;
        uVar16 = ((0xffff - (uVar18 * uVar17) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar17 = ((0xffff - ((0xffff - uVar18) * uVar17) / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar19 = (uVar19 / 0x2a00) % 6;
        if (uVar19 == 2) {
          uVar3 = 0xfffe;
          uVar18 = uVar17;
        }
        else {
          uVar3 = uVar15;
          if (uVar19 < 3) {
            uVar18 = uVar15;
            if (uVar19 == 0) {
              uVar3 = uVar17;
              uVar15 = 0xfffe;
            }
            else if (uVar19 == 1) {
              uVar3 = 0xfffe;
              uVar15 = uVar16;
            }
            else {
              uVar18 = uVar16;
              uVar15 = 0xfffe;
            }
          }
          else if (uVar19 == 3) {
            uVar18 = 0xfffe;
            uVar3 = uVar16;
          }
          else if (uVar19 == 4) {
            uVar18 = 0xfffe;
            uVar15 = uVar17;
          }
          else {
            uVar18 = uVar16;
            uVar15 = 0xfffe;
          }
        }
        __floatunsisf(uVar15);
        uVar8 = __divsf3(0x477fff00);
        __floatunsisf(uVar3);
        uVar9 = __divsf3(0x477fff00);
        __floatunsisf(uVar18);
        uVar11 = __divsf3(0x477fff00);
        uVar12 = __mulsf3(uVar8,0x3ed32d0a);
        uVar13 = __mulsf3(uVar9,0x3eb714ba);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar11,0x3e38c0cf);
        uVar12 = __addsf3(uVar12,uVar13);
        uVar13 = __mulsf3(uVar8,0x3e59c66d);
        uVar14 = __mulsf3(uVar9,0x3f3714ba);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar14 = __mulsf3(uVar11,0x3d93cd57);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar8 = __mulsf3(uVar8,0x3c9e6256);
        uVar9 = __mulsf3(uVar9,0x3df41b76);
        uVar8 = __addsf3(uVar8,uVar9);
        uVar9 = __mulsf3(uVar11,0x3f734214);
        uVar8 = __addsf3(uVar8,uVar9);
        __addsf3(uVar12,uVar13);
        uVar8 = __addsf3(uVar8);
        iVar10 = __eqsf2(0);
        if (iVar10 == 0) {
          (new_color->field_1).field_1.y = 0;
          (new_color->field_1).field_1.x = 0;
        }
        else {
          __divsf3(uVar12,uVar8);
          __mulsf3(0x477eff00);
          uVar4 = __fixunssfsi();
          (new_color->field_1).field_1.x = uVar4;
          __divsf3(uVar13,uVar8);
          __mulsf3(0x477eff00);
          uVar4 = __fixunssfsi();
          (new_color->field_1).field_1.y = uVar4;
        }
        __floatunsisf((new_color->field_1).field_1.x);
        uVar8 = __divsf3(0x477eff00);
        __floatunsisf((new_color->field_1).field_1.y);
        uVar9 = __divsf3(0x477eff00);
        uVar8 = __subsf3(uVar8,0x3ea9fbe7);
        uVar9 = __subsf3(uVar9,0x3e3e425b);
        uVar8 = __divsf3(uVar8,uVar9);
        __mulsf3(0xc3e08000);
        __addsf3(0x455c5000);
        __mulsf3(uVar8);
        uVar9 = __mulsf3(uVar8);
        uVar8 = __mulsf3(uVar8,0x45d53a66);
        __subsf3(uVar9,uVar8);
        uVar8 = __addsf3(0x45ac82a4);
        iVar10 = __gtsf2(0x461c4000);
        if (iVar10 < 1) {
          iVar10 = __ltsf2(uVar8,0x447a0000);
          if (iVar10 < 0) {
            uVar8 = 0x447a0000;
          }
        }
        else {
          uVar8 = 0x461c4000;
        }
        uVar4 = __fixunssfsi(uVar8);
        (new_color->field_1).field_1.x = uVar4;
        eVar2 = '\0';
      }
      else {
        (new_color->field_1).field_1.x = (uint16_t)uVar19;
        (new_color->field_1).field_0.saturation = (uint8_t)uVar15;
        eVar2 = '\0';
      }
    }
    else {
      eVar2 = 0x87;
    }
  }
  return eVar2;
}

