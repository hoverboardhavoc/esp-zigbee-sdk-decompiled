/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> active_scan_complete_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void active_scan_complete_cb(int param_1)

{
  undefined1 *puVar1;
  byte *pbVar2;
  int *piVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 auStack_2a [2];
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined1 uStack_26;
  undefined1 uStack_25;
  undefined1 uStack_24;
  undefined1 uStack_23;
  undefined1 uStack_22;
  undefined1 uStack_21;
  
  piVar3 = (int *)zb_buf_begin_func();
  if (*piVar3 == 0) {
    pbVar2 = (byte *)((int)piVar3 + 5);
    puVar4 = (undefined1 *)malloc((uint)*(byte *)(piVar3 + 1) * 0xb);
    puVar1 = puVar4;
    for (uVar6 = 0; uVar6 < *(byte *)(piVar3 + 1); uVar6 = uVar6 + 1) {
      zb_address_get_pan_id(*pbVar2 & 0x7f,&uStack_28);
      zb_address_get_short_pan_id(*pbVar2 & 0x7f,auStack_2a);
      *puVar1 = auStack_2a[0];
      puVar1[1] = auStack_2a[1];
      puVar1[2] = pbVar2[2] >> 4 & 1;
      puVar1[3] = uStack_28;
      puVar1[4] = uStack_27;
      puVar1[5] = uStack_26;
      puVar1[6] = uStack_25;
      puVar1[7] = uStack_24;
      puVar1[8] = uStack_23;
      puVar1[9] = uStack_22;
      puVar1[10] = uStack_21;
      puVar1 = puVar1 + 0xb;
      pbVar2 = pbVar2 + 4;
    }
    if (zdo_active_scan_user_cb != (code *)0x0) {
      (*zdo_active_scan_user_cb)(*piVar3,puVar4);
    }
  }
  else {
    uVar5 = esp_log_timestamp();
    esp_log_write(2,0x10000,&_LC2,uVar5,0x10000);
  }
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

