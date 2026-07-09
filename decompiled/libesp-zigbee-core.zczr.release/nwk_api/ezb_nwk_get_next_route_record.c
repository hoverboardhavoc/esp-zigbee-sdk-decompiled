/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_api.o -> ezb_nwk_get_next_route_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_nwk_get_next_route_record(undefined4 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar2 = 2;
    if (param_2 != (undefined2 *)0x0) {
      puVar3 = (undefined2 *)nwk_route_record_table_next(*param_1);
      *param_1 = puVar3;
      uVar2 = 5;
      if (puVar3 != (undefined2 *)0x0) {
        uVar1 = *puVar3;
        *(undefined1 *)(param_2 + 1) = 0;
        *param_2 = uVar1;
        *(undefined1 *)((int)param_2 + 3) = *(undefined1 *)(puVar3 + 1);
        memcpy(param_2 + 2,puVar3 + 2,0x18);
        uVar2 = 0;
      }
    }
    return uVar2;
  }
  return 2;
}

