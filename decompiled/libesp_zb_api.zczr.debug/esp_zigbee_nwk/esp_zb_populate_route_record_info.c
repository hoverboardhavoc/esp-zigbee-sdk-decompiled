/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_nwk.o -> esp_zb_populate_route_record_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_populate_route_record_info(undefined2 *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  
  *param_1 = *(undefined2 *)(param_2 + 2);
  *(byte *)(param_1 + 1) = *param_2 >> 1;
  *(byte *)((int)param_1 + 3) = param_2[1];
  bVar1 = param_2[5];
  bVar2 = param_2[6];
  bVar3 = param_2[7];
  bVar4 = param_2[8];
  bVar5 = param_2[9];
  bVar6 = param_2[10];
  bVar7 = param_2[0xb];
  bVar8 = param_2[0xc];
  bVar9 = param_2[0xd];
  *(byte *)(param_1 + 2) = param_2[4];
  *(byte *)((int)param_1 + 5) = bVar1;
  *(byte *)(param_1 + 3) = bVar2;
  *(byte *)((int)param_1 + 7) = bVar3;
  *(byte *)(param_1 + 4) = bVar4;
  *(byte *)((int)param_1 + 9) = bVar5;
  *(byte *)(param_1 + 5) = bVar6;
  *(byte *)((int)param_1 + 0xb) = bVar7;
  *(byte *)(param_1 + 6) = bVar8;
  *(byte *)((int)param_1 + 0xd) = bVar9;
  return;
}

