/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_ias_zone_cluster_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_ias_zone_cluster_handler(undefined4 param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *__ptr;
  uint uVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 uVar7;
  uint auStack_48 [8];
  undefined4 uStack_28;
  undefined2 uStack_24;
  
  iVar3 = zb_buf_get_tail_func(0x1b);
  if (iVar3 == 0) {
    return 0;
  }
  if (*(char *)(iVar3 + 0x14) != '\x01') {
    return 0;
  }
  if (zb_core_action_cb == (code *)0x0) {
    return 0;
  }
  bVar2 = true;
  if (*(char *)(iVar3 + 0x13) == '\0') {
    __ptr = (undefined4 *)malloc(6);
    uVar4 = zb_buf_len_func(param_1);
    bVar1 = uVar4 < 6;
    if (!bVar1) {
      puVar5 = (undefined1 *)zb_buf_begin_func(param_1);
      *(undefined1 *)__ptr = *puVar5;
      *(undefined1 *)((int)__ptr + 1) = puVar5[1];
      *(undefined1 *)((int)__ptr + 2) = puVar5[2];
      *(undefined1 *)((int)__ptr + 3) = puVar5[3];
      *(undefined1 *)(__ptr + 1) = puVar5[4];
      *(undefined1 *)((int)__ptr + 5) = puVar5[5];
    }
    iVar6 = zb_zcl_basic_message_create(param_1,auStack_48);
    if (iVar6 != 0) goto _L0;
    uStack_24 = *(undefined2 *)(__ptr + 1);
    uStack_28 = *__ptr;
    uVar7 = 0x1031;
  }
  else {
    if (*(char *)(iVar3 + 0x13) != '\x01') {
      return 0;
    }
    __ptr = (undefined4 *)malloc(4);
    uVar4 = zb_buf_len_func(param_1);
    bVar1 = uVar4 < 4;
    if (!bVar1) {
      puVar5 = (undefined1 *)zb_buf_begin_func(param_1);
      *(undefined1 *)__ptr = *puVar5;
      *(undefined1 *)((int)__ptr + 1) = puVar5[1];
      *(undefined1 *)((int)__ptr + 2) = puVar5[2];
      *(undefined1 *)((int)__ptr + 3) = puVar5[3];
    }
    iVar6 = zb_zcl_basic_message_create(param_1,auStack_48);
    if (iVar6 != 0) goto _L0;
    uStack_28 = *__ptr;
    uVar7 = 0x1030;
  }
  auStack_48[0] = (uint)bVar1;
  iVar6 = (*zb_core_action_cb)(uVar7,auStack_48,zb_core_action_cb);
  free(__ptr);
  bVar2 = iVar6 != 0;
_L0:
  zb_zcl_send_default_handler(param_1,iVar3,bVar2);
  return 1;
}

