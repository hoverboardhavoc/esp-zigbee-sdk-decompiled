/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_init(undefined4 param_1)

{
  int iVar1;
  void *__s;
  undefined4 uVar2;
  
  iVar1 = core_globals_get();
  __s = (void *)(iVar1 + 0xc4c);
  if (((*(short *)(iVar1 + 0xc54) != 0) && (*(int *)(iVar1 + 0xc50) != 0)) &&
     (*(int *)(iVar1 + 0xc4c) != 0)) {
    __s = (void *)__assert_func(0,0,0,0);
  }
  memset(__s,0,0xc);
  *(short *)(iVar1 + 0xc54) = (short)param_1;
  uVar2 = mm_calloc(param_1,0x12);
  *(undefined4 *)(iVar1 + 0xc50) = uVar2;
  uVar2 = mm_calloc(*(ushort *)(iVar1 + 0xc54) + 7 >> 3,1);
  *(undefined4 *)(iVar1 + 0xc4c) = uVar2;
  *(undefined2 *)(iVar1 + 0xc56) = 0xffff;
  return;
}

