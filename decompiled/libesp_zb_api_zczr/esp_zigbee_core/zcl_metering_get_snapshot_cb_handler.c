/*
 * Last changed at upstream commit 8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * https://github.com/espressif/esp-zigbee-sdk/commit/8ab0979f6a6f2e31f8d566b96a951f1d6ea3f7f3
 * Upstream date: 2023-11-03 16:33:23 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.2(a51c2f72)
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
  char cVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 local_b0;
  undefined4 uStack_ac;
  char cStack_a8;
  undefined1 uStack_a7;
  undefined1 uStack_a6;
  undefined1 uStack_a5;
  undefined1 uStack_a4;
  undefined1 uStack_a3;
  undefined1 uStack_a2;
  undefined1 uStack_a1;
  undefined1 auStack_a0 [6];
  byte bStack_9a;
  byte bStack_99;
  undefined4 uStack_98;
  int iStack_94;
  byte bStack_89;
  int iStack_88;
  undefined4 uStack_84;
  byte bStack_80;
  undefined1 auStack_7c [4];
  undefined1 uStack_78;
  undefined2 uStack_76;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined1 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  
  iVar7 = zb_buf_get_tail_func(0x38);
  iVar8 = zb_buf_get_tail_func(param_1,0x38);
  puVar4 = *(undefined4 **)(iVar8 + 0x10);
  iVar8 = zb_buf_get_tail_func(param_1,0x38);
  iVar8 = *(int *)(iVar8 + 0xc);
  memset(auStack_7c,0,0x4c);
  uStack_78 = *(undefined1 *)(iVar7 + 4);
  uStack_76 = 0x702;
  uStack_74 = *puVar4;
  uStack_70 = puVar4[1];
  uStack_6c = *(undefined1 *)(puVar4 + 2);
  uStack_68 = *(undefined4 *)((int)puVar4 + 9);
  uStack_64 = 0;
  uStack_60 = 0;
  uStack_5c = 0;
  uStack_58 = 0;
  uStack_54 = 0;
  uStack_50 = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  if (zb_core_action_cb == (code *)0x0) {
    iVar7 = 0;
  }
  else {
    (*zb_core_action_cb)(0x12,auStack_7c);
    iVar7 = error_to_zb_ret();
  }
  local_b0 = uStack_64;
  uStack_ac = uStack_60;
  cVar3 = (char)uStack_5c;
  cStack_a8 = (char)uStack_5c;
  uStack_a5 = (undefined1)((uint)uStack_5c >> 8);
  uStack_a4 = (undefined1)((uint)uStack_5c >> 0x10);
  uStack_a3 = (undefined1)((uint)uStack_5c >> 0x18);
  uStack_a2 = (undefined1)uStack_58;
  uVar5 = uStack_58 >> 8 & 0xff;
  uStack_a1 = (undefined1)(uStack_58 >> 8);
  memcpy(auStack_a0,(void *)((int)&uStack_54 + 1),0x21);
  iVar2 = iStack_88;
  iVar1 = iStack_94;
  if (cVar3 == '\0') {
    uVar9 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC34,uVar9,"ESP_ZIGBEE_CORE");
    iVar7 = -0x1c;
  }
  else if (iVar7 == 0) {
    if (uVar5 < 6) {
      if (3 < uVar5) {
        uVar5 = (uint)bStack_99;
        uVar13 = uStack_98 << 8;
        uVar12 = bStack_9a / 6;
        uVar14 = (uint)bStack_9a % 6;
        if (uVar14 != 0) {
          uVar12 = uVar12 + 1;
        }
        uStack_a6 = (undefined1)uVar12;
        for (uVar6 = 0; uVar6 < uVar12; uVar6 = uVar6 + 1 & 0xff) {
          uStack_a7 = (undefined1)uVar6;
          if (uVar6 == uVar12 - 1) {
            bStack_9a = (byte)uVar14;
          }
          else {
            bStack_9a = 6;
          }
          iVar7 = uVar6 * 0x24 + (uVar13 | uVar5);
          bStack_99 = (byte)iVar7;
          uStack_98._0_3_ = (undefined3)((uint)iVar7 >> 8);
          zb_buf_get_out_func();
          zb_zcl_metering_send_cmd_publish_snapshot
                    (iVar8 + 1,2,*(undefined1 *)(iVar8 + 0xb),*(undefined1 *)(iVar8 + 0xc),&local_b0
                     ,0);
        }
        return 0;
      }
      if (uVar5 < 2) {
        uVar5 = bStack_89 / 3;
        uVar12 = (uint)bStack_89 % 3;
        if (uVar12 != 0) {
          uVar5 = uVar5 + 1;
        }
        uStack_a6 = (undefined1)uVar5;
        for (uVar13 = 0; uVar13 < uVar5; uVar13 = uVar13 + 1 & 0xff) {
          uStack_a7 = (undefined1)uVar13;
          if (uVar13 == uVar5 - 1) {
            bStack_89 = (byte)uVar12;
          }
          else {
            bStack_89 = 3;
          }
          iStack_88 = uVar13 * 0x12 + iVar2;
          zb_buf_get_out_func();
          zb_zcl_metering_send_cmd_publish_snapshot
                    (iVar8 + 1,2,*(undefined1 *)(iVar8 + 0xb),*(undefined1 *)(iVar8 + 0xc),&local_b0
                     ,0);
        }
        return 0;
      }
      if ((uVar5 - 2 & 0xff) < 2) {
        uVar5 = (uint)bStack_89;
        uVar12 = uStack_84 & 0xff;
        uVar14 = (uint)bStack_80 << 0x18 | uStack_84 >> 8;
        uVar13 = (uVar5 + uVar12) / 3;
        if ((uVar5 + uVar12) % 3 != 0) {
          uVar13 = uVar13 + 1 & 0xff;
        }
        uStack_a6 = (undefined1)uVar13;
        uVar11 = 0;
        uVar10 = 0;
        for (uVar6 = 0; uVar6 < uVar13; uVar6 = uVar6 + 1 & 0xff) {
          uStack_a7 = (undefined1)uVar6;
          if (uVar5 < 3) {
            if (uVar12 < 3) {
              bStack_89 = (byte)uVar5;
              if (uVar5 + uVar12 < 4) {
                iStack_88 = uVar10 * 6 + iVar2;
                iVar7 = uVar11 * 6 + uVar14;
                uStack_84._0_2_ = CONCAT11((char)iVar7,(char)uVar12);
                uStack_84._0_3_ = CONCAT12((char)((uint)iVar7 >> 8),(undefined2)uStack_84);
                uStack_84 = CONCAT13((char)((uint)iVar7 >> 0x10),(undefined3)uStack_84);
                bStack_80 = (byte)((uint)iVar7 >> 0x18);
              }
              else {
                iStack_88 = uVar10 * 6 + iVar2;
                uVar10 = uVar10 + uVar5 & 0xff;
                uVar12 = (uVar5 - 3) + uVar12 & 0xff;
                iVar7 = uVar11 * 6 + uVar14;
                uStack_84 = CONCAT13((char)((uint)iVar7 >> 0x10),
                                     CONCAT12((char)((uint)iVar7 >> 8),
                                              CONCAT11((char)iVar7,(char)(3 - uVar5))));
                bStack_80 = (byte)((uint)iVar7 >> 0x18);
                uVar11 = (3 - uVar5 & 0xff) + uVar11 & 0xff;
                uVar5 = 0;
              }
            }
            else {
              uVar12 = uVar12 - 3 & 0xff;
              iVar7 = uVar11 * 6 + uVar14;
              uStack_84._0_2_ = CONCAT11((char)iVar7,3);
              uStack_84._0_3_ = CONCAT12((char)((uint)iVar7 >> 8),(undefined2)uStack_84);
              uStack_84 = CONCAT13((char)((uint)iVar7 >> 0x10),(undefined3)uStack_84);
              bStack_80 = (byte)((uint)iVar7 >> 0x18);
              uVar11 = uVar11 + 3 & 0xff;
              bStack_89 = 0;
            }
          }
          else {
            bStack_89 = 3;
            uVar5 = uVar5 - 3 & 0xff;
            iStack_88 = uVar10 * 6 + iVar2;
            uVar10 = uVar10 + 3 & 0xff;
            uStack_84 = uStack_84 & 0xffffff00;
          }
          zb_buf_get_out_func();
          zb_zcl_metering_send_cmd_publish_snapshot
                    (iVar8 + 1,2,*(undefined1 *)(iVar8 + 0xb),*(undefined1 *)(iVar8 + 0xc),&local_b0
                     ,0);
        }
        return 0;
      }
    }
    else if ((uVar5 - 6 & 0xff) < 2) {
      uVar5 = (uint)bStack_9a;
      uVar14 = uStack_98 << 8 | (uint)bStack_99;
      uVar12 = uStack_98 >> 0x18;
      uVar13 = (uVar5 + uVar12) / 6;
      if ((uVar5 + uVar12) % 6 != 0) {
        uVar13 = uVar13 + 1;
      }
      uStack_a6 = (undefined1)uVar13;
      uVar11 = 0;
      uVar10 = 0;
      for (uVar6 = 0; uVar6 < uVar13; uVar6 = uVar6 + 1 & 0xff) {
        uStack_a7 = (undefined1)uVar6;
        if (uVar5 < 6) {
          if (uVar12 < 6) {
            bStack_9a = (byte)uVar5;
            if (uVar5 + uVar12 < 7) {
              iVar7 = uVar10 * 6 + uVar14;
              bStack_99 = (byte)iVar7;
              uStack_98._0_3_ = (undefined3)((uint)iVar7 >> 8);
              uStack_98 = CONCAT13((char)uVar12,(undefined3)uStack_98);
              iStack_94 = uVar11 * 6 + iVar1;
            }
            else {
              iVar7 = uVar10 * 6 + uVar14;
              bStack_99 = (byte)iVar7;
              uStack_98._0_3_ = (undefined3)((uint)iVar7 >> 8);
              uVar10 = uVar10 + uVar5 & 0xff;
              uStack_98 = CONCAT13((char)(6 - uVar5),(undefined3)uStack_98);
              uVar12 = (uVar5 - 6) + uVar12 & 0xff;
              iStack_94 = uVar11 * 6 + iVar1;
              uVar11 = (6 - uVar5 & 0xff) + uVar11 & 0xff;
              uVar5 = 0;
            }
          }
          else {
            uStack_98 = CONCAT13(6,(undefined3)uStack_98);
            uVar12 = uVar12 - 6 & 0xff;
            iStack_94 = uVar11 * 6 + iVar1;
            uVar11 = uVar11 + 6 & 0xff;
            bStack_9a = 0;
          }
        }
        else {
          bStack_9a = 6;
          uVar5 = uVar5 - 6 & 0xff;
          uStack_98 = uVar10 * 6 + uVar14;
          bStack_99 = (byte)uStack_98;
          uStack_98 = uStack_98 >> 8;
          uVar10 = uVar10 + 6 & 0xff;
        }
        zb_buf_get_out_func();
        zb_zcl_metering_send_cmd_publish_snapshot
                  (iVar8 + 1,2,*(undefined1 *)(iVar8 + 0xb),*(undefined1 *)(iVar8 + 0xc),&local_b0,0
                  );
      }
      return 0;
    }
    uVar9 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC35,uVar9,"ESP_ZIGBEE_CORE",uStack_a1);
    iVar7 = -0x1c;
  }
  return iVar7;
}

