/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  __s = (void *)(iVar1 + 0xcb0);
  if (((*(short *)(iVar1 + 0xcb8) != 0) && (*(int *)(iVar1 + 0xcb4) != 0)) &&
     (*(int *)(iVar1 + 0xcb0) != 0)) {
    __s = (void *)__assert_func(0,0,0,0);
  }
  memset(__s,0,0xc);
  *(uint16_t *)(iVar1 + 0xcb8) = capacity;
  uVar2 = mm_calloc(CONCAT22(in_register_0000202a,capacity),0x10);
  *(undefined4 *)(iVar1 + 0xcb4) = uVar2;
  uVar2 = mm_calloc(*(ushort *)(iVar1 + 0xcb8) + 7 >> 3,1);
  *(undefined4 *)(iVar1 + 0xcb0) = uVar2;
  *(undefined2 *)(iVar1 + 0xcba) = 0xffff;
  return;
}

