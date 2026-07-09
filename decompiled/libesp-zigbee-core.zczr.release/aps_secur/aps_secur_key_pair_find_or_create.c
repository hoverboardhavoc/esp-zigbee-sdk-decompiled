/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * aps_secur_key_pair_find_or_create(undefined4 *param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined1 *__s;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  __s = (undefined1 *)aps_secur_get_key_pair_by_addr();
  if (__s == (undefined1 *)0x0) {
    iVar4 = core_globals_get();
    iVar6 = *(int *)(iVar4 + 0x9a0);
    iVar4 = core_globals_get();
    uVar7 = *(undefined4 *)(iVar4 + 0x9a4);
    iVar4 = core_globals_get();
    uVar1 = *(ushort *)(iVar4 + 0x9a8);
    uVar5 = mempool_alloc_idx(uVar7,(uint)uVar1);
    if ((uVar5 < uVar1) && (__s = (undefined1 *)(iVar6 + uVar5 * 0x38), __s != (undefined1 *)0x0)) {
      memset(__s,0,0x38);
      uVar2 = *(undefined2 *)(param_1 + 1);
      uVar7 = *param_1;
      uVar3 = param_1[1];
      *__s = (char)*(undefined2 *)param_1;
      __s[1] = (char)((uint)uVar7 >> 8);
      __s[3] = (char)((uint)uVar7 >> 0x18);
      __s[5] = (char)((uint)uVar3 >> 8);
      __s[2] = (char)((uint)uVar7 >> 0x10);
      __s[4] = (char)uVar2;
      __s[6] = (char)((uint)uVar3 >> 0x10);
      __s[7] = (char)((uint)uVar3 >> 0x18);
    }
  }
  return __s;
}

