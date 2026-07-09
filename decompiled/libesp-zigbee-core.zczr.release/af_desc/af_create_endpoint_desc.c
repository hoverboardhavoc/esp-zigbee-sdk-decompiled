/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_create_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * af_create_endpoint_desc(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined1 *puVar4;
  
  puVar4 = (undefined1 *)calloc(1,0x20);
  if (puVar4 != (undefined1 *)0x0) {
    uVar1 = *param_1;
    uVar2 = *(undefined2 *)(param_1 + 2);
    *puVar4 = uVar1;
    *(undefined2 *)(puVar4 + 2) = uVar2;
    memset(puVar4 + 0xd,0,0xf);
    uVar3 = *(undefined2 *)(param_1 + 4);
    puVar4[0xc] = uVar1;
    *(undefined2 *)(puVar4 + 0xe) = uVar2;
    *(undefined2 *)(puVar4 + 0x10) = uVar3;
    uVar2 = *(undefined2 *)(param_1 + 6);
    *(undefined4 *)(puVar4 + 0x1c) = 0;
    puVar4[0x12] = (byte)uVar2 & 0xf;
  }
  return puVar4;
}

