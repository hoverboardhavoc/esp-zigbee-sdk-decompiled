/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_pib_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_pib_reset(void)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  
  iVar3 = core_globals_get();
  memset((void *)(iVar3 + 0x9d4),0,0xec);
  *(undefined2 *)(iVar3 + 0x9e2) = 0xffff;
  *(undefined2 *)(iVar3 + 0x9e4) = 0xffff;
  *(undefined2 *)(iVar3 + 0x9e0) = 0x1e00;
  nwk_set_rx_on_when_idle(true);
  nwk_mm_get_pib_attr(0,0x40,iVar3 + 0x9e6,8);
  *(undefined1 *)(iVar3 + 0x9ef) = 0;
  *(undefined1 *)(iVar3 + 0x9f0) = 0;
  *(undefined1 *)(iVar3 + 0x9f1) = 0;
  *(undefined1 *)(iVar3 + 0x9f2) = 0;
  *(undefined1 *)(iVar3 + 0x9f3) = 0;
  *(undefined1 *)(iVar3 + 0x9f4) = 0;
  *(undefined1 *)(iVar3 + 0x9f5) = 0;
  *(undefined1 *)(iVar3 + 0x9f6) = 0;
  *(undefined2 *)(iVar3 + 0xa34) = 0xffff;
  *(undefined4 *)(iVar3 + 0xa30) = 0;
  uVar2 = random_noncrypto_get_u32();
  *(undefined1 *)(iVar3 + 0x9da) = uVar2;
  uVar2 = random_noncrypto_get_u32();
  *(undefined1 *)(iVar3 + 0x9d9) = uVar2;
  *(undefined1 *)(iVar3 + 0xa24) = 0xf;
  *(undefined1 *)(iVar3 + 0xa25) = 3;
  *(undefined2 *)(iVar3 + 0x9d6) = 500;
  *(undefined1 *)(iVar3 + 0x9d8) = 2;
  *(undefined1 *)(iVar3 + 0x9de) = 0xc;
  bVar1 = *(byte *)(iVar3 + 0xa2a);
  *(byte *)(iVar3 + 0xa2a) = bVar1 | 2;
  *(byte *)(iVar3 + 0xa2a) = bVar1 | 6;
  *(undefined1 *)(iVar3 + 0xa29) = 8;
  *(undefined1 *)(iVar3 + 0xa37) = 0x4b;
  *(undefined1 *)(iVar3 + 0xa3a) = 1;
  *(undefined1 *)(iVar3 + 0xa3b) = 3;
  *(undefined1 *)(iVar3 + 0x9db) = 0xff;
  nwk_set_keepalive_mode('\x03');
  return;
}

