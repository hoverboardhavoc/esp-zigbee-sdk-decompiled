/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_api.o -> ezb_nwk_get_next_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_nwk_get_next_route(undefined4 *param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = 2;
    if (param_2 != (undefined2 *)0x0) {
      puVar2 = (undefined2 *)nwk_route_table_next(*param_1);
      *param_1 = puVar2;
      uVar1 = 5;
      if (puVar2 != (undefined2 *)0x0) {
        uVar1 = 0;
        *param_2 = *puVar2;
        param_2[1] = puVar2[1];
        *(undefined1 *)(param_2 + 2) = *(undefined1 *)((int)puVar2 + 0xb);
        *(byte *)((int)param_2 + 5) =
             *(byte *)((int)param_2 + 5) & 0xc0 | (byte)puVar2[7] & 7 | (byte)puVar2[7] & 8 |
             (byte)puVar2[7] & 0x10 | (byte)puVar2[7] & 0x20;
      }
    }
    return uVar1;
  }
  return 2;
}

