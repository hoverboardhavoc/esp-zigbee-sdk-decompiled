/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_api.o -> ezb_nwk_get_next_route_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_nwk_get_next_route_record(undefined4 *param_1,undefined2 *param_2)

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
    puVar1 = (undefined2 *)nwk_route_record_table_next(*param_1);
    *param_1 = puVar1;
    if (puVar1 == (undefined2 *)0x0) {
      uVar2 = 5;
    }
    else {
      *param_2 = *puVar1;
      *(undefined1 *)(param_2 + 1) = 0;
      *(undefined1 *)((int)param_2 + 3) = *(undefined1 *)(puVar1 + 1);
      memcpy(param_2 + 2,puVar1 + 2,0x18);
      uVar2 = 0;
    }
  }
  return uVar2;
}

