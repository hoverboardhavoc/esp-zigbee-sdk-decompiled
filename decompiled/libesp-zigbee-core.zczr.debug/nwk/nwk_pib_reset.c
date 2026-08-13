/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_pib_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
  nwk_set_rx_on_when_idle(1);
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
  *(undefined4 *)(iVar3 + 0xa2c) = 3;
  nwk_set_keepalive_mode();
  return;
}

