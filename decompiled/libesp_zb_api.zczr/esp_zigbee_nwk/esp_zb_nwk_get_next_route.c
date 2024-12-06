/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_route(ushort *param_1,undefined2 *param_2)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 == (undefined2 *)0x0) {
    return 0x102;
  }
  uVar3 = (uint)*param_1;
  if (uVar3 != 0xffff) {
    do {
      if (_gc_routing_table_size <= uVar3) {
        *param_1 = 0xffff;
        return 0x105;
      }
      iVar1 = uVar3 * 5;
      uVar4 = uVar3 + 1;
      uVar3 = uVar4 & 0xffff;
      pbVar2 = (byte *)(iVar1 + _g_zb);
    } while ((*pbVar2 & 1) == 0);
    *param_1 = (ushort)(uVar4 * 0x10000 >> 0x10);
    *param_2 = *(undefined2 *)(pbVar2 + 3);
    zb_address_short_by_ref(param_2 + 1,pbVar2[2]);
    *(byte *)(param_2 + 3) = (byte)((pbVar2[1] & 0xf) << 2) | *pbVar2 >> 6;
    *(byte *)(param_2 + 2) = *pbVar2 & 0x38 | *pbVar2 >> 1 & 3 | *(byte *)(param_2 + 2) & 0xc0;
    return 0;
  }
  return 0x105;
}

