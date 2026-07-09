/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_init(undefined2 param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = core_globals_get();
  iVar3 = *(int *)(iVar3 + 0x9a0);
  iVar4 = core_globals_get();
  iVar6 = *(int *)(iVar4 + 0x9a4);
  iVar4 = core_globals_get();
  if (((*(short *)(iVar4 + 0x9a8) != 0) && (iVar3 != 0)) && (iVar6 != 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0xb8,
                  "aps_secur_key_pair_set_init",&_L0);
  }
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0x9a0) = 0;
  *(undefined1 *)(iVar3 + 0x9a1) = 0;
  *(undefined1 *)(iVar3 + 0x9a2) = 0;
  *(undefined1 *)(iVar3 + 0x9a3) = 0;
  *(undefined1 *)(iVar3 + 0x9a4) = 0;
  *(undefined1 *)(iVar3 + 0x9a5) = 0;
  *(undefined1 *)(iVar3 + 0x9a6) = 0;
  *(undefined1 *)(iVar3 + 0x9a7) = 0;
  *(undefined1 *)(iVar3 + 0x9a8) = 0;
  *(undefined1 *)(iVar3 + 0x9a9) = 0;
  *(undefined1 *)(iVar3 + 0x9aa) = 0;
  *(undefined1 *)(iVar3 + 0x9ab) = 0;
  iVar3 = core_globals_get();
  *(undefined2 *)(iVar3 + 0x9a8) = param_1;
  iVar3 = core_globals_get();
  uVar1 = *(undefined2 *)(iVar3 + 0x9a8);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar1,0x38);
  *(undefined4 *)(iVar3 + 0x9a0) = uVar5;
  iVar3 = core_globals_get();
  uVar2 = *(ushort *)(iVar3 + 0x9a8);
  iVar3 = core_globals_get();
  uVar5 = mm_calloc(uVar2 + 7 >> 3,1);
  *(undefined4 *)(iVar3 + 0x9a4) = uVar5;
  return;
}

