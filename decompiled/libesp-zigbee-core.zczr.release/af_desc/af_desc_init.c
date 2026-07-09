/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_desc_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool af_desc_init(void)

{
  uint __nmemb;
  void *pvVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  *(undefined4 *)(iVar2 + 0xca0) = 0;
  s_ep_num_on_dev = 0x40;
  iVar2 = core_globals_get();
  *(ushort *)(iVar2 + 0xc98) = *(ushort *)(iVar2 + 0xc98) & 0xfff0;
  iVar2 = core_globals_get();
  *(ushort *)(iVar2 + 0xc98) = *(ushort *)(iVar2 + 0xc98) & 0xff0f | 0x10;
  iVar2 = core_globals_get();
  *(ushort *)(iVar2 + 0xc98) = *(ushort *)(iVar2 + 0xc98) & 0xf0ff | 0x100;
  iVar2 = core_globals_get();
  *(ushort *)(iVar2 + 0xc98) = *(ushort *)(iVar2 + 0xc98) & 0xfff | 0xc000;
  __nmemb = (uint)s_ep_num_on_dev;
  iVar2 = core_globals_get();
  pvVar1 = calloc(__nmemb,4);
  *(void **)(iVar2 + 0xc9c) = pvVar1;
  iVar2 = core_globals_get();
  return *(int *)(iVar2 + 0xc9c) == 0;
}

