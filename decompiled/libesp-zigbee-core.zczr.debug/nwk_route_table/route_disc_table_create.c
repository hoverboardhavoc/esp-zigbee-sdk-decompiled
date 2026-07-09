/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> route_disc_table_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * route_disc_table_create(int *param_1,undefined2 param_2,undefined1 param_3)

{
  ushort uVar1;
  int iVar2;
  undefined2 *__s;
  uint uVar3;
  
  iVar2 = *param_1;
  uVar1 = *(ushort *)(param_1 + 2);
  uVar3 = mempool_alloc_idx(param_1[1],(uint)uVar1);
  if (uVar3 < uVar1) {
    __s = (undefined2 *)(iVar2 + uVar3 * 0x10);
    if (__s != (undefined2 *)0x0) {
      memset(__s,0,0x10);
      *(undefined1 *)(__s + 5) = param_3;
      *__s = param_2;
      __s[1] = 0xffff;
      *(undefined1 *)((int)__s + 0xb) = 0xff;
      *(undefined1 *)(__s + 6) = 0xff;
      __s[4] = 10;
    }
  }
  else {
    __s = (undefined2 *)0x0;
  }
  return __s;
}

