/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_groups.o -> zb_zcl_group_cluster_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zb_zcl_group_cluster_resp_handler(undefined4 param_1)

{
  byte bVar1;
  bool bVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  uint auStack_48 [8];
  undefined2 uStack_28;
  byte *pbStack_24;
  
  iVar4 = zb_buf_get_tail_func(0x1b);
  if (((iVar4 == 0) || (*(char *)(iVar4 + 0x14) != '\x01')) ||
     (iVar5 = esp_zb_has_core_action_handler(), iVar5 == 0)) {
    return 0;
  }
  bVar1 = *(byte *)(iVar4 + 0x13);
  bVar2 = true;
  if (bVar1 == 2) {
    zb_buf_begin_func(param_1);
    iVar6 = zb_zcl_basic_message_create(param_1,auStack_48);
    if (iVar6 != 0) goto _L0;
    uVar7 = zb_buf_len_func(param_1);
    if (((uVar7 < 2) ||
        (puVar3 = (undefined1 *)zb_buf_begin_func(param_1), puVar3 == (undefined1 *)0x0)) ||
       (bVar1 = puVar3[1], uVar7 = zb_buf_len_func(param_1), uVar7 < ((bVar1 + 1) * 2 & 0xff))) {
      puVar3 = (undefined1 *)0x0;
    }
    auStack_48[0] = (uint)(puVar3 == (undefined1 *)0x0);
    uVar7 = 0;
    if (puVar3 != (undefined1 *)0x0) {
      uVar7 = (uint)(byte)puVar3[1];
    }
    uVar10 = 0;
    if (puVar3 != (undefined1 *)0x0) {
      uVar10 = *puVar3;
    }
    uStack_28 = CONCAT11((char)uVar7,uVar10);
    pbStack_24 = (byte *)malloc(uVar7 << 1);
    iVar6 = 0;
    if (puVar3 != (undefined1 *)0x0) {
      for (; iVar6 < (int)(uint)(byte)puVar3[1]; iVar6 = iVar6 + 1) {
        *(undefined2 *)(pbStack_24 + iVar6 * 2) = *(undefined2 *)(puVar3 + iVar6 * 2 + 2);
      }
    }
    iVar6 = esp_zb_core_action_handler_schedule(0x1012,auStack_48);
    free(pbStack_24);
  }
  else {
    if (bVar1 < 3) {
      if (bVar1 == 0) goto _L0;
      iVar6 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar6 != 0) goto _L0;
      uVar7 = zb_buf_len_func(param_1);
      if (uVar7 < 4) {
        pbStack_24 = (byte *)0x0;
        auStack_48[0] = 1;
      }
      else {
        pbStack_24 = (byte *)zb_buf_begin_func(param_1);
        auStack_48[0] = 1;
        if (pbStack_24 != (byte *)0x0) {
          auStack_48[0] = (uint)*pbStack_24;
        }
      }
      if (pbStack_24 == (byte *)0x0) {
        uStack_28 = 0xffff;
        pbStack_24 = (byte *)0x0;
      }
      else {
        uStack_28 = *(undefined2 *)(pbStack_24 + 1);
        pbStack_24 = pbStack_24 + 3;
      }
      uVar9 = 0x1011;
    }
    else {
      if (bVar1 != 3) {
        return 0;
      }
_L0:
      iVar6 = zb_zcl_basic_message_create(param_1,auStack_48);
      if (iVar6 != 0) goto _L0;
      uVar7 = zb_buf_len_func(param_1);
      if (uVar7 < 3) {
        pbVar8 = (byte *)0x0;
        auStack_48[0] = 1;
      }
      else {
        pbVar8 = (byte *)zb_buf_begin_func(param_1);
        auStack_48[0] = 1;
        if (pbVar8 != (byte *)0x0) {
          auStack_48[0] = (uint)*pbVar8;
        }
      }
      if (pbVar8 == (byte *)0x0) {
        uStack_28 = 0xffff;
      }
      else {
        uStack_28 = *(undefined2 *)(pbVar8 + 1);
      }
      uVar9 = 0x1010;
    }
    iVar6 = esp_zb_core_action_handler_schedule(uVar9,auStack_48);
  }
  bVar2 = iVar6 != 0;
_L0:
  zb_zcl_send_default_handler(param_1,iVar4,bVar2);
  return iVar5;
}

