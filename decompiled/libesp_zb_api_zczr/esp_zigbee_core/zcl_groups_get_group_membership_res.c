/*
 * Last changed at upstream commit d50acd5408f73d4459b46a949332bb6e32f97543
 * https://github.com/espressif/esp-zigbee-sdk/commit/d50acd5408f73d4459b46a949332bb6e32f97543
 * Upstream date: 2023-09-08 17:20:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.4(89250ad3)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_groups_get_group_membership_res
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_groups_get_group_membership_res(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  byte bVar5;
  uint auStack_44 [7];
  undefined1 uStack_28;
  undefined1 uStack_27;
  void *pvStack_24;
  
  zb_buf_begin_func();
  iVar1 = zb_zcl_basic_message_create(param_1,auStack_44);
  if (iVar1 == 0) {
    uVar2 = zb_buf_len_func(param_1);
    if (uVar2 < 2) {
      puVar3 = (undefined1 *)0x0;
    }
    else {
      puVar3 = (undefined1 *)zb_buf_begin_func(param_1);
      if (puVar3 != (undefined1 *)0x0) {
        bVar5 = puVar3[1];
        uVar2 = zb_buf_len_func(param_1);
        if (uVar2 < ((bVar5 + 1) * 2 & 0xff)) {
          puVar3 = (undefined1 *)0x0;
        }
        else {
          for (bVar5 = 0; bVar5 < (byte)puVar3[1]; bVar5 = bVar5 + 1) {
          }
        }
      }
    }
    auStack_44[0] = (uint)(puVar3 == (undefined1 *)0x0);
    if (puVar3 == (undefined1 *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (uint)(byte)puVar3[1];
    }
    uStack_27 = (undefined1)uVar2;
    if (puVar3 == (undefined1 *)0x0) {
      uStack_28 = 0;
    }
    else {
      uStack_28 = *puVar3;
    }
    pvStack_24 = malloc(uVar2 << 1);
    for (iVar1 = 0; (puVar3 != (undefined1 *)0x0 && (iVar1 < (int)(uint)(byte)puVar3[1]));
        iVar1 = iVar1 + 1) {
      *(undefined2 *)((int)pvStack_24 + iVar1 * 2) = *(undefined2 *)(puVar3 + iVar1 * 2 + 2);
    }
    iVar1 = (*zb_core_action_cb)(0x1012,auStack_44,zb_core_action_cb);
    free(pvStack_24);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar4,"ESP_ZIGBEE_CORE",
                  "zcl_groups_get_group_membership_res",0x542);
  }
  return iVar1;
}

