/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> buffer.o -> zmsg_clone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zmsg_clone(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = zmsg_alloc(*(undefined2 *)(param_1 + 0xc));
  if ((iVar1 == 0) ||
     (iVar2 = zmsg_append_bytes_from_msg(param_1,0,*(undefined2 *)(param_1 + 0xe)), iVar2 != 0)) {
    if (iVar1 != 0) {
      zmsg_free(iVar1);
      iVar1 = 0;
    }
  }
  else {
    *(undefined2 *)(iVar1 + 0x16) = *(undefined2 *)(param_1 + 0x16);
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 0x18);
    *(undefined2 *)(iVar1 + 0x12) = *(undefined2 *)(param_1 + 0x12);
  }
  return iVar1;
}

