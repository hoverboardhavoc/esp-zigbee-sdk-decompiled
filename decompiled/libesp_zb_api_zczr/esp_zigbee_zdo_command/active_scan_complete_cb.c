/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> active_scan_complete_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_scan_complete_cb(int param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  uint uVar5;
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [12];
  
  piVar2 = (int *)zb_buf_begin_func();
  if (*piVar2 == 0) {
    puVar3 = (undefined1 *)malloc((uint)*(byte *)(piVar2 + 1) * 0xb);
    puVar1 = puVar3;
    pbVar4 = (byte *)((int)piVar2 + 5);
    for (uVar5 = 0; uVar5 < *(byte *)(piVar2 + 1); uVar5 = uVar5 + 1) {
      zb_address_get_pan_id(*pbVar4 & 0x7f,auStack_28);
      zb_address_get_short_pan_id(*pbVar4 & 0x7f,auStack_2a);
      *puVar1 = auStack_2a[0];
      puVar1[1] = auStack_2a[1];
      puVar1[2] = pbVar4[2] >> 4 & 1;
      memcpy(puVar1 + 3,auStack_28,8);
      puVar1 = puVar1 + 0xb;
      pbVar4 = pbVar4 + 4;
    }
    if (zdo_active_scan_user_cb != (code *)0x0) {
      (*zdo_active_scan_user_cb)(*piVar2,puVar3);
    }
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
    return;
  }
  return;
}

