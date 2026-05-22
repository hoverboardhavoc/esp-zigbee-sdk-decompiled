/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_init(uint16_t capacity)

{
  undefined2 in_register_0000202a;
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
  *(uint16_t *)(iVar1 + 0xc54) = capacity;
  uVar2 = mm_calloc(CONCAT22(in_register_0000202a,capacity),0x12);
  *(undefined4 *)(iVar1 + 0xc50) = uVar2;
  uVar2 = mm_calloc(*(ushort *)(iVar1 + 0xc54) + 7 >> 3,1);
  *(undefined4 *)(iVar1 + 0xc4c) = uVar2;
  *(undefined2 *)(iVar1 + 0xc56) = 0xffff;
  return;
}

