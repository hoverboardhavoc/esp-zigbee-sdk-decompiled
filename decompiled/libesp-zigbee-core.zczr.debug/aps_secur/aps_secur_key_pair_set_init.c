/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_secur_key_pair_set_init(uint16_t capacity)

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
  *(uint16_t *)(iVar3 + 0x9a8) = capacity;
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

