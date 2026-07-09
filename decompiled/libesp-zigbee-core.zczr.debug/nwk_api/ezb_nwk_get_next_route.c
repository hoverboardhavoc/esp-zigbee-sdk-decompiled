/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_api.o -> ezb_nwk_get_next_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_nwk_get_next_route(undefined4 *param_1,undefined2 *param_2)

{
  undefined2 *puVar1;
  undefined4 uVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 2;
  }
  else if (param_2 == (undefined2 *)0x0) {
    uVar2 = 2;
  }
  else {
    puVar1 = (undefined2 *)nwk_route_table_next(*param_1);
    *param_1 = puVar1;
    if (puVar1 == (undefined2 *)0x0) {
      uVar2 = 5;
    }
    else {
      *param_2 = *puVar1;
      param_2[1] = puVar1[1];
      *(undefined1 *)(param_2 + 2) = *(undefined1 *)((int)puVar1 + 0xb);
      *(byte *)((int)param_2 + 5) = *(byte *)((int)param_2 + 5) & 0xf8 | (byte)puVar1[7] & 7;
      *(byte *)((int)param_2 + 5) =
           (byte)((*(uint *)(puVar1 + 6) >> 0x13 & 1) << 3) | *(byte *)((int)param_2 + 5) & 0xf7;
      *(byte *)((int)param_2 + 5) =
           (byte)((*(uint *)(puVar1 + 6) >> 0x14 & 1) << 4) | *(byte *)((int)param_2 + 5) & 0xef;
      *(byte *)((int)param_2 + 5) =
           (byte)((*(uint *)(puVar1 + 6) >> 0x15 & 1) << 5) | *(byte *)((int)param_2 + 5) & 0xdf;
      uVar2 = 0;
    }
  }
  return uVar2;
}

