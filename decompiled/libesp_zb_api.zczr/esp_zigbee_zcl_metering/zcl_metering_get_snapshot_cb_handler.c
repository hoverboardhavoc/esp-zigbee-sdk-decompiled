/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_metering.o -> zcl_metering_get_snapshot_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_metering_get_snapshot_cb_handler(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  char cStack_b8;
  undefined1 uStack_b7;
  undefined1 uStack_b6;
  undefined1 uStack_b5;
  undefined1 uStack_b4;
  undefined1 uStack_b3;
  undefined1 uStack_b2;
  undefined1 uStack_b1;
  undefined1 auStack_b0 [6];
  byte bStack_aa;
  byte bStack_a9;
  undefined4 uStack_a8;
  int iStack_a4;
  byte bStack_99;
  int iStack_98;
  undefined4 uStack_94;
  byte bStack_90;
  undefined1 auStack_8c [4];
  undefined1 uStack_88;
  undefined2 uStack_86;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined1 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  char cStack_6c;
  uint uStack_68;
  undefined1 auStack_63 [47];
  
  iVar4 = zb_buf_get_tail_func(0x38);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  puVar1 = *(undefined4 **)(iVar5 + 0x10);
  iVar5 = zb_buf_get_tail_func(param_1,0x38);
  iVar3 = *(int *)(iVar5 + 0xc);
  memset(auStack_8c,0,0x4c);
  uStack_88 = *(undefined1 *)(iVar4 + 4);
  uStack_86 = 0x702;
  uStack_84 = *puVar1;
  uStack_80 = puVar1[1];
  uStack_7c = *(undefined1 *)(puVar1 + 2);
  uStack_78 = *(undefined4 *)((int)puVar1 + 9);
  memset(&uStack_74,0,0x32);
  esp_zb_core_action_handler_schedule(0xc,auStack_8c);
  iVar6 = esp_err_to_zb_ret();
  uStack_c0 = uStack_74;
  uStack_bc = uStack_70;
  uStack_b5 = (undefined1)((uint)_cStack_6c >> 8);
  uStack_b4 = (undefined1)((uint)_cStack_6c >> 0x10);
  uVar2 = uStack_68 >> 8 & 0xff;
  cStack_b8 = cStack_6c;
  uStack_b3 = (undefined1)((uint)_cStack_6c >> 0x18);
  uStack_b2 = (undefined1)uStack_68;
  uStack_b1 = (undefined1)(uStack_68 >> 8);
  memcpy(auStack_b0,auStack_63,0x21);
  iVar5 = iStack_98;
  iVar4 = iStack_a4;
  if (cStack_6c == '\0') {
    uVar7 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_METERING","E (%lu) %s: No appropriate snapshot!\n",uVar7,
            "ESP_ZIGBEE_ZCL_METERING");
  }
  else {
    if (iVar6 != 0) {
      return iVar6;
    }
    if (uVar2 < 6) {
      if (3 < uVar2) {
        uVar14 = (uint)bStack_a9;
        uVar11 = uStack_a8 << 8;
        uVar2 = bStack_aa / 6;
        uVar15 = (uint)bStack_aa % 6;
        if (uVar15 != 0) {
          uVar2 = uVar2 + 1;
        }
        uStack_b6 = (undefined1)uVar2;
        for (uVar12 = 0; (uVar12 & 0xff) < uVar2; uVar12 = uVar12 + 1) {
          uStack_b7 = (undefined1)uVar12;
          bStack_aa = (byte)uVar15;
          if (uVar12 != uVar2 - 1) {
            bStack_aa = 6;
          }
          iVar4 = uVar12 * 0x24 + (uVar11 | uVar14);
          bStack_a9 = (byte)iVar4;
          uStack_a8._0_3_ = (undefined3)((uint)iVar4 >> 8);
          zb_buf_get_out_func();
          zb_zcl_metering_send_cmd_publish_snapshot
                    (iVar3 + 1,2,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0xc),
                     &uStack_c0,0);
        }
        return 0;
      }
      if (1 < uVar2) {
        uVar14 = (uint)bStack_99;
        uVar2 = uStack_94 & 0xff;
        uVar15 = (uVar14 + uVar2) / 3;
        if ((uVar14 + uVar2) % 3 != 0) {
          uVar15 = uVar15 + 1 & 0xff;
        }
        uVar17 = (uint)bStack_90;
        uVar11 = uStack_94 >> 8;
        uStack_b6 = (undefined1)uVar15;
        uVar13 = 0;
        uVar12 = 0;
        for (uVar16 = 0; uVar16 != uVar15; uVar16 = uVar16 + 1 & 0xff) {
          uStack_b7 = (undefined1)uVar16;
          if (uVar14 < 3) {
            iVar4 = uVar13 * 6 + (uVar17 << 0x18 | uVar11);
            uVar8 = (undefined1)iVar4;
            uVar9 = (undefined1)((uint)iVar4 >> 8);
            uVar10 = (undefined1)((uint)iVar4 >> 0x10);
            bStack_90 = (byte)((uint)iVar4 >> 0x18);
            if (uVar2 < 3) {
              iStack_98 = uVar12 * 6 + iVar5;
              if (uVar14 + uVar2 == 4) {
                uVar2 = 1;
                bStack_99 = 2;
                uVar12 = uVar12 + 2 & 0xff;
                uStack_94._0_2_ = CONCAT11(uVar8,1);
                uStack_94._0_3_ = CONCAT12(uVar9,(undefined2)uStack_94);
                uStack_94 = CONCAT13(uVar10,(undefined3)uStack_94);
                uVar13 = uVar13 + 1 & 0xff;
                uVar14 = 0;
              }
              else {
                bStack_99 = (byte)uVar14;
                uStack_94._0_2_ = CONCAT11(uVar8,(char)uVar2);
                uStack_94._0_3_ = CONCAT12(uVar9,(undefined2)uStack_94);
                uStack_94 = CONCAT13(uVar10,(undefined3)uStack_94);
              }
            }
            else {
              uVar2 = uVar2 - 3 & 0xff;
              uStack_94._0_2_ = CONCAT11(uVar8,3);
              uStack_94._0_3_ = CONCAT12(uVar9,(undefined2)uStack_94);
              uStack_94 = CONCAT13(uVar10,(undefined3)uStack_94);
              uVar13 = uVar13 + 3 & 0xff;
              bStack_99 = 0;
            }
          }
          else {
            iStack_98 = uVar12 * 6;
            bStack_99 = 3;
            uVar14 = uVar14 - 3 & 0xff;
            uVar12 = uVar12 + 3 & 0xff;
            uStack_94 = uStack_94 & 0xffffff00;
            iStack_98 = iStack_98 + iVar5;
          }
          zb_buf_get_out_func();
          zb_zcl_metering_send_cmd_publish_snapshot
                    (iVar3 + 1,2,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0xc),
                     &uStack_c0,0);
        }
        return 0;
      }
      uVar2 = bStack_99 / 3;
      uVar14 = (uint)bStack_99 % 3;
      if (uVar14 != 0) {
        uVar2 = uVar2 + 1;
      }
      uStack_b6 = (undefined1)uVar2;
      for (uVar15 = 0; (uVar15 & 0xff) < uVar2; uVar15 = uVar15 + 1) {
        uStack_b7 = (undefined1)uVar15;
        bStack_99 = (byte)uVar14;
        if (uVar2 - 1 != uVar15) {
          bStack_99 = 3;
        }
        iStack_98 = uVar15 * 0x12 + iVar5;
        zb_buf_get_out_func();
        zb_zcl_metering_send_cmd_publish_snapshot
                  (iVar3 + 1,2,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0xc),&uStack_c0,
                   0);
      }
      return 0;
    }
    if ((uVar2 - 6 & 0xff) < 2) {
      uVar2 = (uint)bStack_aa;
      uVar14 = uStack_a8 >> 0x18;
      uVar11 = uStack_a8 << 8 | (uint)bStack_a9;
      uVar15 = (uVar2 + uVar14) / 6;
      if ((uVar2 + uVar14) % 6 != 0) {
        uVar15 = uVar15 + 1;
      }
      uStack_b6 = (undefined1)uVar15;
      uVar12 = 0;
      uVar13 = 0;
      for (uVar16 = 0; uVar16 != uVar15; uVar16 = uVar16 + 1 & 0xff) {
        uStack_b7 = (undefined1)uVar16;
        if (uVar2 < 6) {
          iStack_a4 = uVar12 * 6 + iVar4;
          if (uVar14 < 6) {
            bStack_aa = (byte)uVar2;
            iVar5 = uVar13 * 6 + uVar11;
            bStack_a9 = (byte)iVar5;
            uStack_a8._0_3_ = (undefined3)((uint)iVar5 >> 8);
            if (uVar2 + uVar14 < 7) {
              uStack_a8 = CONCAT13((char)uVar14,(undefined3)uStack_a8);
            }
            else {
              uStack_a8 = CONCAT13((char)(6 - uVar2),(undefined3)uStack_a8);
              uVar12 = (6 - uVar2 & 0xff) + uVar12 & 0xff;
              uVar13 = uVar13 + uVar2 & 0xff;
              uVar14 = (uVar2 + uVar14) - 6 & 0xff;
              uVar2 = 0;
            }
          }
          else {
            uStack_a8 = CONCAT13(6,(undefined3)uStack_a8);
            uVar14 = uVar14 - 6 & 0xff;
            uVar12 = uVar12 + 6 & 0xff;
            bStack_aa = 0;
          }
        }
        else {
          iVar5 = uVar13 * 6;
          bStack_aa = 6;
          uVar2 = uVar2 - 6 & 0xff;
          uVar13 = uVar13 + 6 & 0xff;
          uStack_a8 = iVar5 + uVar11;
          bStack_a9 = (byte)uStack_a8;
          uStack_a8 = uStack_a8 >> 8;
        }
        zb_buf_get_out_func();
        zb_zcl_metering_send_cmd_publish_snapshot
                  (iVar3 + 1,2,*(undefined1 *)(iVar3 + 0xb),*(undefined1 *)(iVar3 + 0xc),&uStack_c0,
                   0);
      }
      return 0;
    }
    uVar7 = esp_log_timestamp();
    esp_log(1,"ESP_ZIGBEE_ZCL_METERING","E (%lu) %s: Unsupported sub-payload type(0x%x)!\n",uVar7,
            "ESP_ZIGBEE_ZCL_METERING",uStack_b1);
  }
  return -0x1c;
}

