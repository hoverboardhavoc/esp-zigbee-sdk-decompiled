/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_create_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * af_create_endpoint_desc(undefined1 *param_1)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x20);
  if (puVar1 != (undefined1 *)0x0) {
    *puVar1 = *param_1;
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 2);
    memset(puVar1 + 0xc,0,0x10);
    puVar1[0xc] = *param_1;
    *(undefined2 *)(puVar1 + 0xe) = *(undefined2 *)(param_1 + 2);
    *(undefined2 *)(puVar1 + 0x10) = *(undefined2 *)(param_1 + 4);
    puVar1[0x12] = puVar1[0x12] & 0xf0 | (byte)*(undefined2 *)(param_1 + 6) & 0xf;
    *(undefined4 *)(puVar1 + 0x1c) = 0;
  }
  return puVar1;
}

