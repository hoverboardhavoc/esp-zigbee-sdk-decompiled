/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_route_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_route_record(ushort *param_1,undefined2 *param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 == (undefined2 *)0x0) {
    return 0x102;
  }
  uVar3 = (uint)*param_1;
  if (uVar3 != 0xffff) {
    pbVar1 = (byte *)(_g_zb + uVar3 * 0xe);
    while (pbVar2 = pbVar1, uVar3 < gc_nwk_max_source_routes) {
      uVar4 = uVar3 + 1;
      uVar3 = uVar4 & 0xffff;
      pbVar1 = pbVar2 + 0xe;
      if ((*pbVar2 & 1) != 0) {
        *param_1 = (ushort)(uVar4 * 0x10000 >> 0x10);
        *param_2 = *(undefined2 *)(pbVar2 + 2);
        *(byte *)(param_2 + 1) = *pbVar2 >> 1;
        *(byte *)((int)param_2 + 3) = pbVar2[1];
        memcpy(param_2 + 2,pbVar2 + 4,10);
        return 0;
      }
    }
    *param_1 = 0xffff;
  }
  return 0x105;
}

