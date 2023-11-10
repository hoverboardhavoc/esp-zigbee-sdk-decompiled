/*
 * Last changed at upstream commit 9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * https://github.com/espressif/esp-zigbee-sdk/commit/9c5b13dc736bb98a07bff27683b0a2fc347e4448
 * Upstream date: 2023-11-10 18:10:39 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.3(ba5a889a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_cmd_read_attr_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_cmd_read_attr_resp_handler(undefined4 param_1)

{
  uint *puVar1;
  undefined2 *puVar2;
  undefined1 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  undefined2 *puVar10;
  undefined1 auStack_44 [32];
  uint *puStack_24;
  
  puStack_24 = (uint *)0x0;
  iVar4 = zb_zcl_basic_message_create(auStack_44);
  if (iVar4 == 0) {
    puVar9 = (uint *)0x0;
    do {
      uVar7 = zb_buf_len_func(param_1);
      puVar8 = puVar9;
      if (uVar7 < 3) {
        puVar2 = (undefined2 *)0x0;
_L0:
        puVar1 = puStack_24;
        if (puVar2 != (undefined2 *)0x0) {
          puVar8 = (uint *)malloc(0x14);
          *puVar8 = (uint)*(byte *)(puVar2 + 1);
          *(undefined2 *)(puVar8 + 1) = *puVar2;
          *(ushort *)((int)puVar8 + 6) = (ushort)*(byte *)((int)puVar2 + 3);
          *(undefined2 *)(puVar8 + 2) = 0;
          puVar10 = puVar2 + 2;
          uVar3 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar2 + 3),puVar10);
          *(undefined1 *)((int)puVar8 + 10) = uVar3;
          *(char *)((int)puVar8 + 0xb) = (char)puVar10;
          *(char *)(puVar8 + 3) = (char)((uint)puVar10 >> 8);
          *(char *)((int)puVar8 + 0xd) = (char)((uint)puVar10 >> 0x10);
          *(char *)((int)puVar8 + 0xe) = (char)((uint)puVar10 >> 0x18);
          puVar8[4] = 0;
          puVar1 = puVar8;
          if (puVar9 != (uint *)0x0) {
            puVar9[4] = (uint)puVar8;
            puVar1 = puStack_24;
          }
        }
      }
      else {
        puVar2 = (undefined2 *)zb_buf_begin_func(param_1);
        puVar1 = puStack_24;
        if (puVar2 != (undefined2 *)0x0) {
          iVar4 = zb_zcl_zcl8_statuses_conversion(*(undefined1 *)(puVar2 + 1));
          *(char *)(puVar2 + 1) = (char)iVar4;
          if (iVar4 == 0) {
            iVar4 = zb_zcl_get_attribute_size(*(undefined1 *)((int)puVar2 + 3),puVar2 + 2);
            uVar7 = iVar4 + 4U & 0xff;
            zb_buf_len_func(param_1);
          }
          else {
            uVar7 = 3;
          }
          uVar6 = zb_buf_len_func(param_1);
          if (uVar7 <= uVar6) {
            zb_buf_cut_left_func(param_1,uVar7);
            goto _L0;
          }
          puVar2 = (undefined2 *)0x0;
          puVar1 = puStack_24;
        }
      }
      puStack_24 = puVar1;
      puVar9 = puVar8;
    } while (puVar2 != (undefined2 *)0x0);
    iVar4 = (*zb_core_action_cb)(0x1000,auStack_44,zb_core_action_cb);
    puVar9 = puStack_24;
    while (puVar9 != (uint *)0x0) {
      puVar8 = (uint *)puVar9[4];
      free(puVar9);
      puVar9 = puVar8;
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC24,uVar5,"ESP_ZIGBEE_CORE",
                  "zcl_cmd_read_attr_resp_handler",0x6b4);
  }
  return iVar4;
}

