/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_metering_get_snapshot_cb_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_metering_get_snapshot_cb_handler(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
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
  
  iVar6 = zb_buf_get_tail_func(0x38);
  iVar7 = zb_buf_get_tail_func(param_1,0x38);
  puVar3 = *(undefined4 **)(iVar7 + 0x10);
  iVar7 = zb_buf_get_tail_func(param_1,0x38);
  iVar7 = *(int *)(iVar7 + 0xc);
  memset(auStack_8c,0,0x4c);
  uStack_88 = *(undefined1 *)(iVar6 + 4);
  uStack_86 = 0x702;
  iVar6 = 0;
  uStack_84 = *puVar3;
  uStack_80 = puVar3[1];
  uStack_7c = *(undefined1 *)(puVar3 + 2);
  uStack_78 = *(undefined4 *)((int)puVar3 + 9);
  memset(&uStack_74,0,0x32);
  if (zb_core_action_cb != (code *)0x0) {
    (*zb_core_action_cb)(0xc,auStack_8c);
    iVar6 = esp_err_to_zb_ret();
  }
  uStack_c0 = uStack_74;
  uStack_bc = uStack_70;
  uStack_b5 = (undefined1)((uint)_cStack_6c >> 8);
  uStack_b4 = (undefined1)((uint)_cStack_6c >> 0x10);
  uVar4 = uStack_68 >> 8 & 0xff;
  cStack_b8 = cStack_6c;
  uStack_b3 = (undefined1)((uint)_cStack_6c >> 0x18);
  uStack_b2 = (undefined1)uStack_68;
  uStack_b1 = (undefined1)(uStack_68 >> 8);
  memcpy(auStack_b0,auStack_63,0x21);
  iVar2 = iStack_98;
  iVar1 = iStack_a4;
  if (cStack_6c == '\0') {
    uVar8 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC10,uVar8,"ESP_ZIGBEE_CORE");
  }
  else {
    if (iVar6 != 0) {
      return iVar6;
    }
    if (uVar4 < 6) {
      if (3 < uVar4) {
        uVar14 = (uint)bStack_a9;
        uVar5 = uStack_a8 << 8;
        uVar4 = bStack_aa / 6;
        uVar15 = (uint)bStack_aa % 6;
        if (uVar15 != 0) {
          uVar4 = uVar4 + 1;
        }
        uStack_b6 = (undefined1)uVar4;
        for (uVar12 = 0; (uVar12 & 0xff) < uVar4; uVar12 = uVar12 + 1) {
          uStack_b7 = (undefined1)uVar12;
          bStack_aa = 6;
          if (uVar4 - 1 == uVar12) {
            bStack_aa = (byte)uVar15;
          }
          iVar6 = uVar12 * 0x24 + (uVar5 | uVar14);
          bStack_a9 = (byte)iVar6;
          uStack_a8._0_3_ = (undefined3)((uint)iVar6 >> 8);
          zb_buf_get_out_func();
          zb_zcl_metering_send_cmd_publish_snapshot
                    (iVar7 + 1,2,*(undefined1 *)(iVar7 + 0xb),*(undefined1 *)(iVar7 + 0xc),
                     &uStack_c0,0);
        }
        return 0;
      }
      if (1 < uVar4) {
        uVar14 = (uint)bStack_99;
        uVar4 = uStack_94 & 0xff;
        uVar15 = (uVar14 + uVar4) / 3;
        if ((uVar14 + uVar4) % 3 != 0) {
          uVar15 = uVar15 + 1 & 0xff;
        }
        uVar17 = (uint)bStack_90;
        uVar12 = uStack_94 >> 8;
        uStack_b6 = (undefined1)uVar15;
        uVar13 = 0;
        uVar5 = 0;
        for (uVar16 = 0; uVar16 != uVar15; uVar16 = uVar16 + 1 & 0xff) {
          uStack_b7 = (undefined1)uVar16;
          if (uVar14 < 3) {
            iVar6 = uVar13 * 6 + (uVar17 << 0x18 | uVar12);
            uVar9 = (undefined1)iVar6;
            uVar10 = (undefined1)((uint)iVar6 >> 8);
            uVar11 = (undefined1)((uint)iVar6 >> 0x10);
            bStack_90 = (byte)((uint)iVar6 >> 0x18);
            if (uVar4 < 3) {
              iStack_98 = uVar5 * 6 + iVar2;
              if (uVar14 + uVar4 == 4) {
                bStack_99 = 2;
                uVar5 = uVar5 + 2 & 0xff;
                uStack_94._0_2_ = CONCAT11(uVar9,1);
                uStack_94._0_3_ = CONCAT12(uVar10,(undefined2)uStack_94);
                uStack_94 = CONCAT13(uVar11,(undefined3)uStack_94);
                uVar13 = uVar13 + 1 & 0xff;
                uVar4 = 1;
                uVar14 = 0;
              }
              else {
                bStack_99 = (byte)uVar14;
                uStack_94._0_2_ = CONCAT11(uVar9,(char)uVar4);
                uStack_94._0_3_ = CONCAT12(uVar10,(undefined2)uStack_94);
                uStack_94 = CONCAT13(uVar11,(undefined3)uStack_94);
              }
            }
            else {
              uVar4 = uVar4 - 3 & 0xff;
              uStack_94._0_2_ = CONCAT11(uVar9,3);
              uStack_94._0_3_ = CONCAT12(uVar10,(undefined2)uStack_94);
              uStack_94 = CONCAT13(uVar11,(undefined3)uStack_94);
              uVar13 = uVar13 + 3 & 0xff;
              bStack_99 = 0;
            }
          }
          else {
            iStack_98 = uVar5 * 6;
            bStack_99 = 3;
            uVar14 = uVar14 - 3 & 0xff;
            uVar5 = uVar5 + 3 & 0xff;
            uStack_94 = uStack_94 & 0xffffff00;
            iStack_98 = iStack_98 + iVar2;
          }
          zb_buf_get_out_func();
          zb_zcl_metering_send_cmd_publish_snapshot
                    (iVar7 + 1,2,*(undefined1 *)(iVar7 + 0xb),*(undefined1 *)(iVar7 + 0xc),
                     &uStack_c0,0);
        }
        return 0;
      }
      uVar4 = bStack_99 / 3;
      uVar14 = (uint)bStack_99 % 3;
      if (uVar14 != 0) {
        uVar4 = uVar4 + 1;
      }
      uStack_b6 = (undefined1)uVar4;
      for (uVar15 = 0; (uVar15 & 0xff) < uVar4; uVar15 = uVar15 + 1) {
        uStack_b7 = (undefined1)uVar15;
        bStack_99 = 3;
        if (uVar4 - 1 == uVar15) {
          bStack_99 = (byte)uVar14;
        }
        iStack_98 = uVar15 * 0x12 + iVar2;
        zb_buf_get_out_func();
        zb_zcl_metering_send_cmd_publish_snapshot
                  (iVar7 + 1,2,*(undefined1 *)(iVar7 + 0xb),*(undefined1 *)(iVar7 + 0xc),&uStack_c0,
                   0);
      }
      return 0;
    }
    if ((uVar4 - 6 & 0xff) < 2) {
      uVar4 = (uint)bStack_aa;
      uVar14 = uStack_a8 >> 0x18;
      uVar5 = uStack_a8 << 8 | (uint)bStack_a9;
      uVar15 = (uVar4 + uVar14) / 6;
      if ((uVar4 + uVar14) % 6 != 0) {
        uVar15 = uVar15 + 1;
      }
      uStack_b6 = (undefined1)uVar15;
      uVar13 = 0;
      uVar12 = 0;
      for (uVar16 = 0; uVar16 != uVar15; uVar16 = uVar16 + 1 & 0xff) {
        uStack_b7 = (undefined1)uVar16;
        if (uVar4 < 6) {
          iStack_a4 = uVar13 * 6 + iVar1;
          if (uVar14 < 6) {
            bStack_aa = (byte)uVar4;
            iVar6 = uVar12 * 6 + uVar5;
            bStack_a9 = (byte)iVar6;
            uStack_a8._0_3_ = (undefined3)((uint)iVar6 >> 8);
            if (uVar4 + uVar14 < 7) {
              uStack_a8 = CONCAT13((char)uVar14,(undefined3)uStack_a8);
            }
            else {
              uStack_a8 = CONCAT13((char)(6 - uVar4),(undefined3)uStack_a8);
              uVar13 = (6 - uVar4 & 0xff) + uVar13 & 0xff;
              uVar12 = uVar12 + uVar4 & 0xff;
              uVar14 = (uVar4 + uVar14) - 6 & 0xff;
              uVar4 = 0;
            }
          }
          else {
            uStack_a8 = CONCAT13(6,(undefined3)uStack_a8);
            uVar14 = uVar14 - 6 & 0xff;
            uVar13 = uVar13 + 6 & 0xff;
            bStack_aa = 0;
          }
        }
        else {
          iVar6 = uVar12 * 6;
          bStack_aa = 6;
          uVar4 = uVar4 - 6 & 0xff;
          uVar12 = uVar12 + 6 & 0xff;
          uStack_a8 = iVar6 + uVar5;
          bStack_a9 = (byte)uStack_a8;
          uStack_a8 = uStack_a8 >> 8;
        }
        zb_buf_get_out_func();
        zb_zcl_metering_send_cmd_publish_snapshot
                  (iVar7 + 1,2,*(undefined1 *)(iVar7 + 0xb),*(undefined1 *)(iVar7 + 0xc),&uStack_c0,
                   0);
      }
      return 0;
    }
    uVar8 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC11,uVar8,"ESP_ZIGBEE_CORE",uStack_b1);
  }
  return -0x1c;
}

