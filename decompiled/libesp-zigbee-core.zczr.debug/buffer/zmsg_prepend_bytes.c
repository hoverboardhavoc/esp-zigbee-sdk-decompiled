/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_prepend_bytes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zmsg_prepend_bytes(int param_1,uint param_2,int param_3)

{
  short sVar1;
  undefined4 *puVar2;
  
  while( true ) {
    if (param_2 <= *(ushort *)(param_1 + 0xc)) {
      sVar1 = (short)param_2;
      *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) - sVar1;
      *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + sVar1;
      *(short *)(param_1 + 0x12) = *(short *)(param_1 + 0x12) + sVar1;
      if (param_3 != 0) {
        zmsg_write_bytes(param_1,0,param_2,param_3);
      }
      return 0;
    }
    puVar2 = (undefined4 *)mempool_malloc(0);
    if (puVar2 == (undefined4 *)0x0) break;
    *puVar2 = *(undefined4 *)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = puVar2;
    *(short *)(param_1 + 0xc) = *(short *)(param_1 + 0xc) + 0xac;
  }
  return 1;
}

