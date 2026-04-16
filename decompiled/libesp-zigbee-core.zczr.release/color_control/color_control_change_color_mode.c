/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_change_color_mode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x0001023c) */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t color_control_change_color_mode(zcl_packet_t *packet,uint8_t new_mode)

{
  uint8_t ep_id;
  uint8_t uVar1;
  uint uVar2;
  uint uVar3;
  ezb_zcl_status_t eVar4;
  byte bVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  ushort uVar8;
  zcl_attr_desc_t *pzVar9;
  uint uVar10;
  zcl_attr_desc_t *pzVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint16_t attr_id;
  undefined3 in_register_0000202d;
  int iVar20;
  int extraout_a1;
  ezb_zcl_color_control_color_t *value;
  uint8_t *value_00;
  uint uVar21;
  uint uVar22;
  uint16_t _delta;
  uint uVar23;
  uint16_t _max;
  float tk;
  uint uVar24;
  uint uVar25;
  byte local_50 [2];
  ushort uStack_4e;
  ezb_zcl_color_control_color_t new_color;
  uint8_t mode;
  
  iVar20 = CONCAT31(in_register_0000202d,new_mode);
  value_00 = local_50;
  local_50[1] = 0;
  uStack_4e = 0;
  new_color.mode = '\0';
  new_color._1_1_ = 0;
  local_50[0] = new_mode;
  if (packet == (zcl_packet_t *)0x0) {
    packet = (zcl_packet_t *)__assert_func(0,0,0);
    iVar20 = extraout_a1;
  }
  ep_id = (packet->header).dst_ep;
  pzVar9 = color_control_srv_get_attr_desc(ep_id,0x4001);
                    /* WARNING: Load size is inaccurate */
  bVar5 = *pzVar9->data_p;
  memset((void *)((int)&new_color.field_1 + 2),0,0x18);
  uVar10 = zcl_packet_to_message((undefined1 *)((int)&new_color.field_1 + 2),packet);
  if (uVar10 == 0) {
    zcl_core_action_schedule(0x1b,(undefined1 *)((int)&new_color.field_1 + 2));
    uVar10 = 0xfe;
  }
  if (uVar10 != 0xfe) goto _L0;
  if (bVar5 == 2) {
    pzVar9 = color_control_srv_get_attr_desc(ep_id,7);
    uVar8 = 0;
    if (pzVar9 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      uVar8 = *pzVar9->data_p;
    }
    if (local_50[0] != 0) {
      if (local_50[0] != 1) {
        uVar7 = new_color._0_2_;
        if (local_50[0] != 3) goto _L0;
        __floatunsisf(uVar8);
        uVar13 = __divsf3(0x447a0000);
        if (uVar8 < 0xfb) {
          __mulsf3(0xc041a77a);
          __addsf3(0x4006d9b5);
          __mulsf3(uVar13);
          __addsf3(0x3e63fa5a);
          __mulsf3(uVar13);
          uVar13 = __addsf3(0x3e7628cc);
          __mulsf3(0x40453b86);
          __subsf3(0x40bbf2c9);
          __mulsf3(uVar13);
          __addsf3(0x40701283);
          __mulsf3(uVar13);
          uVar14 = 0x3ebd7294;
        }
        else {
          __mulsf3(0xbe884164);
          __subsf3(0x3e6ffb8b);
          __mulsf3(uVar13);
          __addsf3(0x3f60b0a9);
          __mulsf3(uVar13);
          uVar13 = __addsf3(0x3e383a54);
          if (uVar8 < 0x1c3) {
            __mulsf3(0xbf747772);
            __subsf3(0x3fafe553);
            __mulsf3(uVar13);
            __addsf3(0x4005d902);
            __mulsf3(uVar13);
            uVar14 = 0x3e2b8228;
          }
          else {
            __mulsf3(0xbf8d9de8);
            __subsf3(0x3fac8ee0);
            __mulsf3(uVar13);
            __addsf3(0x400be030);
            __mulsf3(uVar13);
            uVar14 = 0x3e4f0cae;
          }
        }
        uVar15 = __subsf3(uVar14);
        iVar19 = __gtsf2(uVar13,0x3f800000);
        uVar14 = 0x3f800000;
        if (iVar19 < 1) {
          uVar14 = uVar13;
        }
        iVar19 = __gtsf2(uVar15,0x3f800000);
        uVar13 = 0x3f800000;
        if (iVar19 < 1) {
          uVar13 = uVar15;
        }
        iVar19 = __ltsf2(uVar13,0);
        uVar15 = 0;
        if (-1 < iVar19) {
          uVar15 = uVar13;
        }
        __mulsf3(uVar15,0x477eff00);
        uVar7 = __fixunssfsi();
        new_color._0_2_ = uVar7;
        iVar19 = __ltsf2(uVar14,0);
        uVar13 = 0;
        if (-1 < iVar19) {
          uVar13 = uVar14;
        }
        __mulsf3(uVar13,0x477eff00);
        uVar6 = __fixunssfsi();
        __floatunsisf(uVar6);
        uVar13 = __divsf3(0x477eff00);
        __floatunsisf(uVar7);
        uVar14 = __divsf3(0x477eff00);
        __subsf3(0x3f800000,uVar13);
        uVar15 = __subsf3(uVar14);
        uVar16 = __mulsf3(uVar13,0x404f6402);
        uVar17 = __mulsf3(uVar14,0x3fc4c155);
        uVar16 = __subsf3(uVar16,uVar17);
        uVar17 = __mulsf3(uVar15,0x3eff3ffb);
        uVar16 = __subsf3(uVar16,uVar17);
        uVar17 = __mulsf3(uVar13,0xbf782129);
        uVar18 = __mulsf3(uVar14,0x3ff02081);
        uVar17 = __addsf3(uVar17,uVar18);
        uVar18 = __mulsf3(uVar15,0x3d2a36a0);
        uVar17 = __addsf3(uVar17,uVar18);
        uVar13 = __mulsf3(uVar13,0x3d63ef28);
        uVar14 = __mulsf3(uVar14,0x3e50f0a6);
        uVar13 = __subsf3(uVar13,uVar14);
        uVar14 = __mulsf3(uVar15,0x3f8755f8);
        uVar14 = __addsf3(uVar13,uVar14);
        iVar19 = __gtsf2(uVar16,0x3f800000);
        uVar13 = 0x3f800000;
        if (iVar19 < 1) {
          uVar13 = uVar16;
        }
        iVar19 = __gtsf2(uVar17,0x3f800000);
        uVar15 = 0x3f800000;
        if (iVar19 < 1) {
          uVar15 = uVar17;
        }
        iVar19 = __gtsf2(uVar14,0x3f800000);
        uVar16 = 0x3f800000;
        if (iVar19 < 1) {
          uVar16 = uVar14;
        }
        iVar19 = __ltsf2(uVar13,0);
        uVar14 = 0;
        if (-1 < iVar19) {
          uVar14 = uVar13;
        }
        __mulsf3(uVar14,0x477fff00);
        uVar10 = __fixunssfsi();
        iVar19 = __ltsf2(uVar15,0);
        uVar10 = uVar10 & 0xffff;
        uVar13 = 0;
        if (-1 < iVar19) {
          uVar13 = uVar15;
        }
        __mulsf3(uVar13,0x477fff00);
        uVar21 = __fixunssfsi();
        iVar19 = __ltsf2(uVar16,0);
        uVar21 = uVar21 & 0xffff;
        uVar13 = 0;
        if (-1 < iVar19) {
          uVar13 = uVar16;
        }
        __mulsf3(uVar13,0x477fff00);
        uVar24 = __fixunssfsi();
        uVar24 = uVar24 & 0xffff;
        uVar12 = uVar10;
        if (uVar10 < uVar21) {
          uVar12 = uVar21;
        }
        if (uVar12 < uVar24) {
          uVar12 = uVar24;
        }
        if (uVar12 == 0) {
          uVar2 = 0;
          uVar23 = 0;
        }
        else {
          uVar23 = uVar10;
          if (uVar21 < uVar10) {
            uVar23 = uVar21;
          }
          if (uVar24 < uVar23) {
            uVar23 = uVar24;
          }
          uVar22 = uVar12 - uVar23 & 0xffff;
          uVar23 = 0;
          uVar2 = (uVar22 * 0xfe) / uVar12 & 0xff;
          if (uVar22 != 0) {
            if (uVar10 == uVar12) {
              uVar23 = (((uVar21 - uVar24) * 0xfe) / uVar22) / 6 & 0xff;
            }
            else {
              if (uVar21 == uVar12) {
                iVar19 = (int)(uVar24 - uVar10) / (int)uVar22 + 2;
              }
              else {
                iVar19 = (int)(uVar10 - uVar21) / (int)uVar22 + 4;
              }
              uVar23 = (uint)(iVar19 * 0xfe) / 6 & 0xff;
            }
          }
        }
_L0:
        uVar1 = (uint8_t)uVar2;
        uStack_4e = (ushort)(uVar23 << 8);
_L0:
        new_color.mode = uVar1;
_L0:
        value = (ezb_zcl_color_control_color_t *)&stack0xffffffb2;
        attr_id = 0x4000;
        goto _L0;
      }
      __floatunsisf(uVar8);
      uVar13 = __divsf3(0x447a0000);
      if (uVar8 < 0xfb) {
        __mulsf3(0xc041a77a);
        __addsf3(0x4006d9b5);
        __mulsf3(uVar13);
        __addsf3(0x3e63fa5a);
        __mulsf3(uVar13);
        uVar13 = __addsf3(0x3e7628cc);
        __mulsf3(0x40453b86);
        __subsf3(0x40bbf2c9);
        __mulsf3(uVar13);
        __addsf3(0x40701283);
        __mulsf3(uVar13);
        uVar14 = 0x3ebd7294;
      }
      else {
        __mulsf3(0xbe884164);
        __subsf3(0x3e6ffb8b);
        __mulsf3(uVar13);
        __addsf3(0x3f60b0a9);
        __mulsf3(uVar13);
        uVar13 = __addsf3(0x3e383a54);
        if (uVar8 < 0x1c3) {
          __mulsf3(0xbf747772);
          __subsf3(0x3fafe553);
          __mulsf3(uVar13);
          __addsf3(0x4005d902);
          __mulsf3(uVar13);
          uVar14 = 0x3e2b8228;
        }
        else {
          __mulsf3(0xbf8d9de8);
          __subsf3(0x3fac8ee0);
          __mulsf3(uVar13);
          __addsf3(0x400be030);
          __mulsf3(uVar13);
          uVar14 = 0x3e4f0cae;
        }
      }
      uVar15 = __subsf3(uVar14);
      iVar19 = __gtsf2(uVar13,0x3f800000);
      uVar14 = 0x3f800000;
      if (iVar19 < 1) {
        uVar14 = uVar13;
      }
      iVar19 = __ltsf2(uVar14,0);
      uVar13 = 0;
      if (-1 < iVar19) {
        uVar13 = uVar14;
      }
      __mulsf3(uVar13,0x477eff00);
      uStack_4e = __fixunssfsi();
      iVar19 = __gtsf2(uVar15,0x3f800000);
      uVar13 = 0x3f800000;
      if (iVar19 < 1) {
        uVar13 = uVar15;
      }
      iVar19 = __ltsf2(uVar13,0);
      uVar14 = 0;
      if (-1 < iVar19) {
        uVar14 = uVar13;
      }
_L0:
      __mulsf3(uVar14,0x477eff00);
      new_color._0_2_ = __fixunssfsi();
      goto _L0;
    }
    __floatunsisf(uVar8);
    uVar13 = __divsf3(0x447a0000);
    if (uVar8 < 0xfb) {
      __mulsf3(0xc041a77a);
      __addsf3(0x4006d9b5);
      __mulsf3(uVar13);
      __addsf3(0x3e63fa5a);
      __mulsf3(uVar13);
      uVar13 = __addsf3(0x3e7628cc);
      __mulsf3(0x40453b86);
      __subsf3(0x40bbf2c9);
      __mulsf3(uVar13);
      __addsf3(0x40701283);
      __mulsf3(uVar13);
      uVar14 = 0x3ebd7294;
    }
    else {
      __mulsf3(0xbe884164);
      __subsf3(0x3e6ffb8b);
      __mulsf3(uVar13);
      __addsf3(0x3f60b0a9);
      __mulsf3(uVar13);
      uVar13 = __addsf3(0x3e383a54);
      if (uVar8 < 0x1c3) {
        __mulsf3(0xbf747772);
        __subsf3(0x3fafe553);
        __mulsf3(uVar13);
        __addsf3(0x4005d902);
        __mulsf3(uVar13);
        uVar14 = 0x3e2b8228;
      }
      else {
        __mulsf3(0xbf8d9de8);
        __subsf3(0x3fac8ee0);
        __mulsf3(uVar13);
        __addsf3(0x400be030);
        __mulsf3(uVar13);
        uVar14 = 0x3e4f0cae;
      }
    }
    uVar15 = __subsf3(uVar14);
    iVar19 = __gtsf2(uVar13,0x3f800000);
    uVar14 = 0x3f800000;
    if (iVar19 < 1) {
      uVar14 = uVar13;
    }
    iVar19 = __ltsf2(uVar14,0);
    uVar13 = 0;
    if (-1 < iVar19) {
      uVar13 = uVar14;
    }
    __mulsf3(uVar13,0x477eff00);
    uVar8 = __fixunssfsi();
    uStack_4e = uVar8;
    iVar19 = __gtsf2(uVar15,0x3f800000);
    uVar13 = 0x3f800000;
    if (iVar19 < 1) {
      uVar13 = uVar15;
    }
    iVar19 = __ltsf2(uVar13,0);
    uVar14 = 0;
    if (-1 < iVar19) {
      uVar14 = uVar13;
    }
    __mulsf3(uVar14,0x477eff00);
    uVar7 = __fixunssfsi();
    new_color._0_2_ = uVar7;
    __floatunsisf(uVar8);
    uVar13 = __divsf3(0x477eff00);
    __floatunsisf(uVar7);
    uVar14 = __divsf3(0x477eff00);
    __subsf3(0x3f800000,uVar13);
    uVar15 = __subsf3(uVar14);
    uVar16 = __mulsf3(uVar13,0x404f6402);
    uVar17 = __mulsf3(uVar14,0x3fc4c155);
    uVar16 = __subsf3(uVar16,uVar17);
    uVar17 = __mulsf3(uVar15,0x3eff3ffb);
    uVar16 = __subsf3(uVar16,uVar17);
    uVar17 = __mulsf3(uVar13,0xbf782129);
    uVar18 = __mulsf3(uVar14,0x3ff02081);
    uVar17 = __addsf3(uVar17,uVar18);
    uVar18 = __mulsf3(uVar15,0x3d2a36a0);
    uVar17 = __addsf3(uVar17,uVar18);
    uVar13 = __mulsf3(uVar13,0x3d63ef28);
    uVar14 = __mulsf3(uVar14,0x3e50f0a6);
    uVar13 = __subsf3(uVar13,uVar14);
    uVar14 = __mulsf3(uVar15,0x3f8755f8);
    uVar14 = __addsf3(uVar13,uVar14);
    iVar19 = __gtsf2(uVar16,0x3f800000);
    uVar13 = 0x3f800000;
    if (iVar19 < 1) {
      uVar13 = uVar16;
    }
    iVar19 = __gtsf2(uVar17,0x3f800000);
    uVar15 = 0x3f800000;
    if (iVar19 < 1) {
      uVar15 = uVar17;
    }
    iVar19 = __gtsf2(uVar14,0x3f800000);
    uVar16 = 0x3f800000;
    if (iVar19 < 1) {
      uVar16 = uVar14;
    }
    iVar19 = __ltsf2(uVar13,0);
    uVar14 = 0;
    if (-1 < iVar19) {
      uVar14 = uVar13;
    }
    __mulsf3(uVar14,0x477fff00);
    uVar10 = __fixunssfsi();
    iVar19 = __ltsf2(uVar15,0);
    uVar10 = uVar10 & 0xffff;
    uVar13 = 0;
    if (-1 < iVar19) {
      uVar13 = uVar15;
    }
_L0:
    __mulsf3(uVar13,0x477fff00);
    uVar21 = __fixunssfsi();
    iVar19 = __ltsf2(uVar16,0);
    uVar21 = uVar21 & 0xffff;
    uVar13 = 0;
    if (-1 < iVar19) {
      uVar13 = uVar16;
    }
    __mulsf3(uVar13,0x477fff00);
    uVar24 = __fixunssfsi();
    uVar24 = uVar24 & 0xffff;
    uVar12 = uVar10;
    if (uVar10 < uVar21) {
      uVar12 = uVar21;
    }
    if (uVar12 < uVar24) {
      uVar12 = uVar24;
    }
    if (uVar12 == 0) {
      new_color._0_2_ = (ushort)(byte)new_color._1_1_ << 8;
_L0:
      uStack_4e = uStack_4e & 0xff00;
    }
    else {
      uVar23 = uVar10;
      if (uVar21 < uVar10) {
        uVar23 = uVar21;
      }
      if (uVar24 < uVar23) {
        uVar23 = uVar24;
      }
      uVar23 = uVar12 - uVar23 & 0xffff;
      new_color.mode = (uint8_t)((uVar23 * 0xfe) / uVar12);
      if (uVar23 == 0) goto _L0;
      if (uVar10 == uVar12) {
        uStack_4e = CONCAT11(uStack_4e._1_1_,(char)((((uVar21 - uVar24) * 0xfe) / uVar23) / 6));
      }
      else {
        if (uVar21 == uVar12) {
          iVar19 = (int)(uVar24 - uVar10) / (int)uVar23 + 2;
        }
        else {
          iVar19 = (int)(uVar10 - uVar21) / (int)uVar23 + 4;
        }
        uStack_4e = CONCAT11(uStack_4e._1_1_,(char)((uint)(iVar19 * 0xfe) / 6));
      }
    }
_L0:
    color_control_srv_set_attr_value(ep_id,0,(uint8_t *)&stack0xffffffb2);
    value = &new_color;
    attr_id = 1;
  }
  else {
    if (bVar5 < 3) {
      if (bVar5 != 0) {
        pzVar9 = color_control_srv_get_attr_desc(ep_id,3);
        pzVar11 = color_control_srv_get_attr_desc(ep_id,4);
        uVar8 = 0;
        if (pzVar9 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
          uVar8 = *pzVar9->data_p;
        }
        uVar7._0_1_ = '\0';
        uVar7._1_1_ = 0;
        if (pzVar11 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
          uVar7 = *pzVar11->data_p;
        }
        if (local_50[0] == 0) {
          __floatunsisf();
          uVar13 = __divsf3(0x477eff00);
          __floatunsisf(uVar7);
          uVar14 = __divsf3(0x477eff00);
          __subsf3(0x3f800000,uVar13);
          uVar15 = __subsf3(uVar14);
          uVar16 = __mulsf3(uVar13,0x404f6402);
          uVar17 = __mulsf3(uVar14,0x3fc4c155);
          uVar16 = __subsf3(uVar16,uVar17);
          uVar17 = __mulsf3(uVar15,0x3eff3ffb);
          uVar16 = __subsf3(uVar16,uVar17);
          uVar17 = __mulsf3(uVar13,0xbf782129);
          uVar18 = __mulsf3(uVar14,0x3ff02081);
          uVar17 = __addsf3(uVar17,uVar18);
          uVar18 = __mulsf3(uVar15,0x3d2a36a0);
          uVar17 = __addsf3(uVar17,uVar18);
          uVar13 = __mulsf3(uVar13,0x3d63ef28);
          uVar14 = __mulsf3(uVar14,0x3e50f0a6);
          uVar13 = __subsf3(uVar13,uVar14);
          uVar14 = __mulsf3(uVar15,0x3f8755f8);
          uVar14 = __addsf3(uVar13,uVar14);
          iVar19 = __gtsf2(uVar16,0x3f800000);
          uVar13 = 0x3f800000;
          if (iVar19 < 1) {
            uVar13 = uVar16;
          }
          iVar19 = __gtsf2(uVar17,0x3f800000);
          uVar15 = 0x3f800000;
          if (iVar19 < 1) {
            uVar15 = uVar17;
          }
          iVar19 = __gtsf2(uVar14,0x3f800000);
          uVar16 = 0x3f800000;
          if (iVar19 < 1) {
            uVar16 = uVar14;
          }
          iVar19 = __ltsf2(uVar13,0);
          uVar14 = 0;
          if (-1 < iVar19) {
            uVar14 = uVar13;
          }
          __mulsf3(uVar14,0x477fff00);
          uVar10 = __fixunssfsi();
          iVar19 = __ltsf2(uVar15,0);
          uVar10 = uVar10 & 0xffff;
          uVar13 = 0;
          if (-1 < iVar19) {
            uVar13 = uVar15;
          }
          goto _L0;
        }
        if (local_50[0] != 2) {
          if (local_50[0] == 3) {
            __floatunsisf();
            uVar13 = __divsf3(0x477eff00);
            __floatunsisf(uVar7);
            uVar14 = __divsf3(0x477eff00);
            __subsf3(0x3f800000,uVar13);
            uVar15 = __subsf3(uVar14);
            uVar16 = __mulsf3(uVar13,0x404f6402);
            uVar17 = __mulsf3(uVar14,0x3fc4c155);
            uVar16 = __subsf3(uVar16,uVar17);
            uVar17 = __mulsf3(uVar15,0x3eff3ffb);
            uVar16 = __subsf3(uVar16,uVar17);
            uVar17 = __mulsf3(uVar13,0xbf782129);
            uVar18 = __mulsf3(uVar14,0x3ff02081);
            uVar17 = __addsf3(uVar17,uVar18);
            uVar18 = __mulsf3(uVar15,0x3d2a36a0);
            uVar17 = __addsf3(uVar17,uVar18);
            uVar13 = __mulsf3(uVar13,0x3d63ef28);
            uVar14 = __mulsf3(uVar14,0x3e50f0a6);
            uVar13 = __subsf3(uVar13,uVar14);
            uVar14 = __mulsf3(uVar15,0x3f8755f8);
            uVar14 = __addsf3(uVar13,uVar14);
            iVar19 = __gtsf2(uVar16,0x3f800000);
            uVar13 = 0x3f800000;
            if (iVar19 < 1) {
              uVar13 = uVar16;
            }
            iVar19 = __gtsf2(uVar17,0x3f800000);
            uVar15 = 0x3f800000;
            if (iVar19 < 1) {
              uVar15 = uVar17;
            }
            iVar19 = __gtsf2(uVar14,0x3f800000);
            uVar16 = 0x3f800000;
            if (iVar19 < 1) {
              uVar16 = uVar14;
            }
            iVar19 = __ltsf2(uVar13,0);
            uVar14 = 0;
            if (-1 < iVar19) {
              uVar14 = uVar13;
            }
            __mulsf3(uVar14,0x477fff00);
            uVar10 = __fixunssfsi();
            iVar19 = __ltsf2(uVar15,0);
            uVar10 = uVar10 & 0xffff;
            uVar13 = 0;
            if (-1 < iVar19) {
              uVar13 = uVar15;
            }
            __mulsf3(uVar13,0x477fff00);
            uVar21 = __fixunssfsi();
            iVar19 = __ltsf2(uVar16,0);
            uVar21 = uVar21 & 0xffff;
            uVar13 = 0;
            if (-1 < iVar19) {
              uVar13 = uVar16;
            }
            __mulsf3(uVar13,0x477fff00);
            uVar24 = __fixunssfsi();
            uVar24 = uVar24 & 0xffff;
            uVar12 = uVar10;
            if (uVar10 < uVar21) {
              uVar12 = uVar21;
            }
            if (uVar12 < uVar24) {
              uVar12 = uVar24;
            }
            uVar23 = 0;
            if (uVar12 != 0) {
              uVar23 = uVar10;
              if (uVar21 < uVar10) {
                uVar23 = uVar21;
              }
              if (uVar24 < uVar23) {
                uVar23 = uVar24;
              }
              uVar2 = uVar12 - uVar23 & 0xffff;
              uVar23 = 0;
              if (uVar2 != 0) {
                if (uVar10 == uVar12) {
                  uVar23 = (((uVar21 - uVar24) * 0xfe) / uVar2) / 6 & 0xff;
                }
                else {
                  if (uVar21 == uVar12) {
                    iVar19 = (int)(uVar24 - uVar10) / (int)uVar2 + 2;
                  }
                  else {
                    iVar19 = (int)(uVar10 - uVar21) / (int)uVar2 + 4;
                  }
                  uVar23 = (uint)(iVar19 * 0xfe) / 6 & 0xff;
                }
              }
            }
            uStack_4e = (ushort)(uVar23 << 8);
            uVar1 = (uint8_t)uVar7;
            goto _L0;
          }
          goto _L0;
        }
        __floatunsisf();
_L0:
        __divsf3(0x477eff00);
        uVar13 = __subsf3(0x3ea9fbe7);
        __floatunsisf(uVar7);
        __divsf3(0x477eff00);
        uVar14 = __subsf3(0x3e3e425b);
        uVar13 = __divsf3(uVar13,uVar14);
        __mulsf3(0xc3e08000);
        __addsf3(0x455c5000);
        __mulsf3(uVar13);
        uVar14 = __mulsf3(uVar13);
        uVar13 = __mulsf3(uVar13,0x45d53a66);
        __subsf3(uVar14,uVar13);
        uVar14 = __addsf3(0x45ac82a4);
        iVar19 = __gtsf2(0x461c4000);
        uVar13 = 0x461c4000;
        if (iVar19 < 1) {
          uVar13 = uVar14;
        }
        iVar19 = __ltsf2(uVar13,0x447a0000);
        uVar14 = 0x447a0000;
        if (-1 < iVar19) {
          uVar14 = uVar13;
        }
        uStack_4e = __fixunssfsi(uVar14);
_L0:
        value = (ezb_zcl_color_control_color_t *)&stack0xffffffb2;
        attr_id = 7;
        goto _L0;
      }
      pzVar9 = color_control_srv_get_attr_desc(ep_id,0);
      pzVar11 = color_control_srv_get_attr_desc(ep_id,1);
      uVar23 = 0;
      if (pzVar9 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
        uVar23 = (uint)*pzVar9->data_p;
      }
      uVar2 = 0;
      if (pzVar11 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
        uVar2 = (uint)*pzVar11->data_p;
      }
      if (local_50[0] == 1) {
        uVar10 = ((uVar23 % 0x2a) * 0xffff) / 0x2a;
        uVar21 = (uVar2 * 0xffff) / 0xfe;
        uVar24 = uVar10 * uVar21;
        uVar10 = (0xffff - uVar10) * uVar21;
        goto _L0;
      }
      if (local_50[0] == 2) {
        uVar10 = ((uVar23 % 0x2a) * 0xffff) / 0x2a;
        uVar21 = (uVar2 * 0xffff) / 0xfe;
        uVar24 = uVar10 * uVar21;
        uVar10 = (0xffff - uVar10) * uVar21;
_L0:
        uVar22 = 0xfffe;
        uVar25 = ((0xffff - uVar24 / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar24 = ((0xffff - uVar21) * 0xfffe) / 0xffff & 0xffff;
        uVar2 = ((0xffff - uVar10 / 0xffff) * 0xfffe) / 0xffff & 0xffff;
        uVar23 = (uVar23 / 0x2a) % 6;
        uVar10 = uVar22;
        uVar21 = uVar24;
        uVar12 = uVar2;
        if (uVar23 != 2) {
          if (uVar23 < 3) {
            uVar3 = uVar2;
            uVar21 = uVar25;
            uVar12 = uVar24;
            if (uVar23 == 0) {
_L0:
              uVar10 = uVar3;
              uVar21 = uVar22;
              uVar12 = uVar24;
            }
          }
          else {
            uVar10 = uVar25;
            uVar12 = uVar22;
            if ((uVar23 != 3) &&
               (uVar3 = uVar24, uVar10 = uVar24, uVar21 = uVar2, uVar24 = uVar25, uVar23 != 4))
            goto _L0;
          }
        }
        __floatunsisf(uVar21);
        uVar13 = __divsf3(0x477fff00);
        __floatunsisf(uVar10);
        uVar14 = __divsf3(0x477fff00);
        __floatunsisf(uVar12);
        uVar15 = __divsf3(0x477fff00);
        uVar16 = __mulsf3(uVar13,0x3ed32d0a);
        uVar17 = __mulsf3(uVar14,0x3eb714ba);
        uVar16 = __addsf3(uVar16,uVar17);
        uVar17 = __mulsf3(uVar15,0x3e38c0cf);
        uVar16 = __addsf3(uVar16,uVar17);
        uVar17 = __mulsf3(uVar13,0x3e59c66d);
        uVar18 = __mulsf3(uVar14,0x3f3714ba);
        uVar17 = __addsf3(uVar17,uVar18);
        uVar18 = __mulsf3(uVar15,0x3d93cd57);
        uVar17 = __addsf3(uVar17,uVar18);
        uVar13 = __mulsf3(uVar13,0x3c9e6256);
        uVar14 = __mulsf3(uVar14,0x3df41b76);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar14 = __mulsf3(uVar15,0x3f734214);
        uVar13 = __addsf3(uVar13,uVar14);
        uVar14 = __addsf3(uVar16,uVar17);
        uVar13 = __addsf3(uVar13,uVar14);
        iVar19 = __eqsf2(0);
        if (iVar19 == 0) {
          uVar7._0_1_ = '\0';
          uVar7._1_1_ = 0;
          uVar6 = 0;
        }
        else {
          __divsf3(uVar16,uVar13);
          __mulsf3(0x477eff00);
          uVar6 = __fixunssfsi();
          __divsf3(uVar17,uVar13);
          __mulsf3(0x477eff00);
          uVar7 = __fixunssfsi();
        }
        new_color._0_2_ = uVar7;
        __floatunsisf(uVar6);
        goto _L0;
      }
      if (local_50[0] == 3) goto _L0;
      uStack_4e = CONCAT11(uStack_4e._1_1_,(char)uVar23);
      new_color.mode = (uint8_t)uVar2;
      uVar8 = uStack_4e;
      uVar7 = new_color._0_2_;
_L0:
      new_color._0_2_ = uVar7;
      uStack_4e = uVar8;
      if (local_50[0] == 2) goto _L0;
      if (2 < local_50[0]) {
        if (local_50[0] == 3) goto _L0;
        goto _L0;
      }
      if (local_50[0] == 0) goto _L0;
    }
    else {
      if (bVar5 != 3) {
_L0:
        uVar10 = 0x87;
        goto _L0;
      }
      pzVar9 = color_control_srv_get_attr_desc(ep_id,0x4000);
      pzVar11 = color_control_srv_get_attr_desc(ep_id,1);
      uVar23 = 0;
      if (pzVar9 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
        uVar23 = (uint)*pzVar9->data_p;
      }
      uVar10 = 0;
      if (pzVar11 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
        uVar10 = (uint)*pzVar11->data_p;
      }
      if (local_50[0] == 0) {
        uStack_4e = CONCAT11(uStack_4e._1_1_,(char)(uVar23 >> 8));
        new_color.mode = (uint8_t)uVar10;
        goto _L0;
      }
      if (local_50[0] != 1) {
        if (local_50[0] == 2) {
          uVar23 = uVar23 >> 8;
          uVar12 = ((uVar23 % 0x2a) * 0xffff) / 0x2a;
          uVar21 = (uVar10 * 0xffff) / 0xfe;
          uVar24 = uVar12 * uVar21;
          uVar10 = (0xffff - uVar12) * uVar21;
          goto _L0;
        }
        new_color.mode = (uint8_t)uVar10;
        uVar8 = (ushort)uVar23;
        uVar7 = new_color._0_2_;
        goto _L0;
      }
      uVar23 = uVar23 >> 8;
      uVar12 = ((uVar23 % 0x2a) * 0xffff) / 0x2a;
      uVar21 = (uVar10 * 0xffff) / 0xfe;
      uVar24 = uVar12 * uVar21;
      uVar10 = (0xffff - uVar12) * uVar21;
_L0:
      uVar22 = 0xfffe;
      uVar25 = ((0xffff - uVar24 / 0xffff) * 0xfffe) / 0xffff & 0xffff;
      uVar12 = ((0xffff - uVar21) * 0xfffe) / 0xffff & 0xffff;
      uVar2 = ((0xffff - uVar10 / 0xffff) * 0xfffe) / 0xffff & 0xffff;
      uVar23 = (uVar23 / 0x2a) % 6;
      uVar10 = uVar22;
      uVar21 = uVar12;
      uVar24 = uVar2;
      if (uVar23 != 2) {
        if (uVar23 < 3) {
          uVar3 = uVar2;
          uVar21 = uVar25;
          uVar24 = uVar12;
          if (uVar23 == 0) {
_L0:
            uVar10 = uVar3;
            uVar21 = uVar22;
            uVar24 = uVar12;
          }
        }
        else {
          uVar10 = uVar25;
          uVar24 = uVar22;
          if ((uVar23 != 3) &&
             (uVar3 = uVar12, uVar10 = uVar12, uVar21 = uVar2, uVar12 = uVar25, uVar23 != 4))
          goto _L0;
        }
      }
      __floatunsisf(uVar21);
      uVar13 = __divsf3(0x477fff00);
      __floatunsisf(uVar10);
      uVar14 = __divsf3(0x477fff00);
      __floatunsisf(uVar24);
      uVar15 = __divsf3(0x477fff00);
      uVar16 = __mulsf3(uVar13,0x3ed32d0a);
      uVar17 = __mulsf3(uVar14,0x3eb714ba);
      uVar16 = __addsf3(uVar16,uVar17);
      uVar17 = __mulsf3(uVar15,0x3e38c0cf);
      uVar16 = __addsf3(uVar16,uVar17);
      uVar17 = __mulsf3(uVar13,0x3e59c66d);
      uVar18 = __mulsf3(uVar14,0x3f3714ba);
      uVar17 = __addsf3(uVar17,uVar18);
      uVar18 = __mulsf3(uVar15,0x3d93cd57);
      uVar17 = __addsf3(uVar17,uVar18);
      uVar13 = __mulsf3(uVar13,0x3c9e6256);
      uVar14 = __mulsf3(uVar14,0x3df41b76);
      uVar13 = __addsf3(uVar13,uVar14);
      uVar14 = __mulsf3(uVar15,0x3f734214);
      uVar13 = __addsf3(uVar13,uVar14);
      uVar14 = __addsf3(uVar16,uVar17);
      uVar13 = __addsf3(uVar13,uVar14);
      iVar19 = __eqsf2(0);
      if (iVar19 != 0) {
        __divsf3(uVar16,uVar13);
        __mulsf3(0x477eff00);
        uStack_4e = __fixunssfsi();
        uVar14 = __divsf3(uVar17,uVar13);
        goto _L0;
      }
      new_color.mode = '\0';
      new_color._1_1_ = 0;
      uStack_4e = 0;
    }
_L0:
    color_control_srv_set_attr_value(ep_id,3,(uint8_t *)&stack0xffffffb2);
    value = &new_color;
    attr_id = 4;
  }
_L0:
  eVar4 = color_control_srv_set_attr_value(ep_id,attr_id,&value->mode);
  uVar10 = CONCAT31(extraout_var,eVar4);
  if (uVar10 == 0) {
    if (iVar20 == 3) {
      new_color.field_1.field_0.saturation = '\0';
      value_00 = &new_color.field_1.field_0.saturation;
    }
    eVar4 = color_control_srv_set_attr_value(ep_id,8,value_00);
    uVar10 = CONCAT31(extraout_var_00,eVar4);
    if (uVar10 == 0) {
      bVar5 = color_control_srv_set_attr_value(ep_id,0x4001,local_50);
      uVar10 = (uint)bVar5;
    }
  }
_L0:
  return (ezb_zcl_status_t)uVar10;
}

