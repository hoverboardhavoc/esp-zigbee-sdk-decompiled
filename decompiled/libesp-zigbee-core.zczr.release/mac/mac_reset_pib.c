/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_reset_pib
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_reset_pib(void *param_1)

{
  undefined1 uVar1;
  
  memset(param_1,0,0x2c);
  mac_set_panid(param_1,0xffff);
  *(undefined2 *)((int)param_1 + 8) = 0xffff;
  mac_pal_set_shortaddr(0xffff);
  mac_pal_get_macaddr(param_1);
  mac_pal_set_extaddr(param_1);
  uVar1 = random_noncrypto_get_u32();
  *(undefined1 *)((int)param_1 + 0xd) = uVar1;
  uVar1 = random_noncrypto_get_u32();
  *(undefined4 *)((int)param_1 + 0x18) = 0x7fff800;
  *(undefined4 *)((int)param_1 + 0x1c) = 0x2003256c;
  *(undefined2 *)((int)param_1 + 0x20) = 0x805;
  *(undefined1 *)((int)param_1 + 0x22) = 4;
  *(undefined2 *)((int)param_1 + 0x28) = 500;
  *(undefined1 *)((int)param_1 + 0xc) = uVar1;
  *(undefined2 *)((int)param_1 + 0xe) = 0xffff;
  *(undefined4 *)((int)param_1 + 0x10) = 0;
  *(undefined4 *)((int)param_1 + 0x14) = 0;
  *(byte *)((int)param_1 + 0x2a) = *(byte *)((int)param_1 + 0x2a) & 0xfe;
  return;
}

