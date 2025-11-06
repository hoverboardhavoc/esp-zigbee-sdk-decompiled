/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_groups.o -> zcl_groups_get_group_membership_res
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
  uint auStack_48 [8];
  undefined1 uStack_28;
  byte bStack_27;
  void *pvStack_24;
  
  zb_buf_begin_func();
  iVar1 = zb_zcl_basic_message_create(param_1,auStack_48);
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
    auStack_48[0] = (uint)(puVar3 == (undefined1 *)0x0);
    if (puVar3 == (undefined1 *)0x0) {
      bStack_27 = 0;
      uStack_28 = 0;
    }
    else {
      bStack_27 = puVar3[1];
      uStack_28 = *puVar3;
    }
    pvStack_24 = malloc((uint)bStack_27 << 1);
    for (iVar1 = 0; (puVar3 != (undefined1 *)0x0 && (iVar1 < (int)(uint)(byte)puVar3[1]));
        iVar1 = iVar1 + 1) {
      *(undefined2 *)((int)pvStack_24 + iVar1 * 2) = *(undefined2 *)(puVar3 + iVar1 * 2 + 2);
    }
    iVar1 = esp_zb_core_action_handler_schedule(0x1012,auStack_48);
    free(pvStack_24);
  }
  else {
    uVar4 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Failed to create get_group_membership_response message\n"
            ,uVar4,0x10000,"zcl_groups_get_group_membership_res",0x60);
  }
  return iVar1;
}

