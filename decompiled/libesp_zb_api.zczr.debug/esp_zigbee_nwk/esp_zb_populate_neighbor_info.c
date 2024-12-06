/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_nwk.o -> esp_zb_populate_neighbor_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_populate_neighbor_info(int param_1,byte *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int extraout_a1;
  int iVar6;
  int extraout_a1_00;
  int extraout_a1_01;
  
  zb_address_ieee_by_ref(param_2[7]);
  uVar1 = zb_address_short_by_ieee(param_1);
  *(undefined2 *)(param_1 + 8) = uVar1;
  *(byte *)(param_1 + 10) = *param_2 >> 2 & 3;
  *(byte *)(param_1 + 0xb) = *param_2 >> 4;
  *(byte *)(param_1 + 0xc) = param_2[1] >> 1 & 1;
  *(byte *)(param_1 + 0xd) = param_2[1] >> 2 & 7;
  *(byte *)(param_1 + 0xe) = param_2[4];
  *(byte *)(param_1 + 0xf) = param_2[5];
  *(byte *)(param_1 + 0x10) = param_2[8] >> 4 & 7;
  *(byte *)(param_1 + 0x11) = (byte)((param_2[9] & 0xf) << 1) | param_2[8] >> 7;
  uVar2 = zb_convert_timeout_value(param_2[8] & 0xf);
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  uVar5 = *(uint *)(param_2 + 0xe);
  iVar6 = *(int *)(param_2 + 0x12);
  iVar3 = zb_timer_get();
  uVar4 = uVar5 - iVar3;
  iVar6 = (iVar6 - extraout_a1) - (uint)(uVar5 < uVar4);
  if ((iVar6 < 0) || ((iVar6 == 0x7fffffff && (0xfffffffe < uVar4)))) {
    uVar5 = zb_timer_get();
    uVar2 = __udivdi3((extraout_a1_01 - *(int *)(param_2 + 0x12)) -
                      (uint)(uVar5 < uVar5 - *(int *)(param_2 + 0xe)),1000,0);
  }
  else {
    uVar5 = *(uint *)(param_2 + 0xe);
    iVar6 = *(int *)(param_2 + 0x12);
    iVar3 = zb_timer_get();
    uVar2 = __udivdi3((iVar6 - extraout_a1_00) - (uint)(uVar5 < uVar5 - iVar3),1000,0);
  }
  *(undefined4 *)(param_1 + 0x18) = uVar2;
  return;
}

